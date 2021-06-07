#include "glidepoint.h"
#include "i2c_master.h"
#include "pointing_device.h"

#ifdef CONSOLE_ENABLE
#    include "print.h"
#endif

relData_t relData;

/*
 * To-Do:
 *  - I think I would like the DR implemented as an interupt pin to allow for normal interaction without constant polling
 *
 *
 *
 *
 *
 */

__attribute__((weak)) void pointing_device_init(void) {
  Pinnacle_Init();

  // These functions are required for use with thick overlays (curved)
  setAdcAttenuation(ADC_ATTENUATE_2X);
  //tuneEdgeSensitivity();
  // The following two lines take the place of tuning edge sensitivity
  ERA_WriteByte(0x49,  0x04); //tuning
  ERA_WriteByte(0x68,  0x03); //tuning

  Pinnacle_EnableFeed(true);
}


void Pinnacle_Init()
{
  RAP_Init();
  //pinMode(DR_PIN, INPUT);

  // Host clears SW_CC flag
  Pinnacle_ClearFlags();

  // Configuration bits written to relavent registers
  RAP_Write(0x03, SYSCONFIG_1);    // 0x00, nothing set
  RAP_Write(0x04, FEEDCONFIG_1);   // 0x01, enables feed (data output)
  RAP_Write(0x05, FEEDCONFIG_2);   // 0x1F, disable GlideExtend, disables all taps and scrolling, enables Intellimouse
  RAP_Write(0x0A, Z_IDLE_COUNT);
  
    #ifdef CONSOLE_ENABLE
        print("Pinnacle initialized")
    #endif
  
}

void RAP_Init()
{
  // Set up I2C peripheral
    i2c_init();
}

void Pinnacle_ClearFlags()
{
  RAP_Write(0x02, 0x00);
  delay(1);
}

void RAP_ReadBytes(uint8_t* data, uint8_t reg_read, uint16_t size_of_data) {
    uint8_t cmdByte = READ_MASK | reg_read;   // Form the READ command byte
    i2c_readReg(CIRQUE_WRITE, cmdByte, data, size_of_data, CIRQUE_I2C_TIMEOUT);
}

// Writes single-byte <data> to <address>
void RAP_Write(uint8_t reg_write, uint8_t data)
{
    uint8_t cmdByte = WRITE_MASK | reg_write;  // Form the WRITE command byte
    i2c_writeReg(CIRQUE_WRITE, cmdByte, data, 1, CIRQUE_I2C_TIMEOUT);
}

/*  ERA (Extended Register Access) Functions  */
// Reads <count> bytes from an extended register at <address> (16-bit address),
// stores values in <*data>
void ERA_ReadBytes(uint16_t address, uint8_t * data)
{
  uint8_t ERAControlValue = 0xFF;

  Pinnacle_EnableFeed(false); // Disable feed

  RAP_Write(0x1C, 0x01);     // Send upper byte of ERA address
  RAP_Write(0x1D, address); // Send lower byte of ERA address

  RAP_Write(0x1E, 0x05);  // Signal ERA-read (auto-increment) to Pinnacle

  // Wait for status register 0x1E to clear
  do
  {
    RAP_ReadBytes(&ERAControlValue, 0x1E, 1);
  } while(ERAControlValue != 0x00);

  RAP_ReadBytes(data, 0x1B, 1);

  Pinnacle_ClearFlags();
  }
}

// Writes a byte, <data>, to an extended register at <address> (16-bit address, starts with hardcoded 0x01)
void ERA_WriteByte(uint16_t address, uint8_t data)
{
  uint8_t ERAControlValue = 0xFF;

  Pinnacle_EnableFeed(false); // Disable feed

  RAP_Write(0x1B, data);      // Send data byte to be written

  RAP_Write(0x1C, 0x01);     // Upper byte of ERA address
  RAP_Write(0x1D, address); // Lower byte of ERA address
  RAP_Write(0x1E, 0x02);  // Signal an ERA-write to Pinnacle
  // Wait for status register 0x1E to clear
  do
  {
    RAP_ReadBytes(&ERAControlValue, 0x1E, 1);
  } while(ERAControlValue != 0x00);
  Pinnacle_ClearFlags();
}

   
/*  Curved Overlay Functions  */
// Adjusts the feedback in the ADC, effectively attenuating the finger signal
// By default, the the signal is maximally attenuated (ADC_ATTENUATE_4X for use with thin, flat overlays
void setAdcAttenuation(uint8_t adcGain)
{
  uint8_t temp = 0x00;

  //Serial.println();
  //Serial.println("Setting ADC gain...");
  ERA_ReadBytes(0x87, &temp);
  temp &= 0x3F; // clear top two bits
  temp |= adcGain;
  ERA_WriteByte(0x87, temp);
  ERA_ReadBytes(0x87, &temp);
  #ifdef CONSOLE_ENABLE
    print("ADC gain set to:\t");
    print(temp &= 0xC0, HEX);
  switch(temp)
  {
    case ADC_ATTENUATE_1X:
      print(" (X/1)");
      break;
    case ADC_ATTENUATE_2X:
      print(" (X/2)");
      break;
    case ADC_ATTENUATE_3X:
      print(" (X/3)");
      break;
    case ADC_ATTENUATE_4X:
      print(" (X/4)");
      break;
    default:
      break;
  }
    #endif
}

void Pinnacle_GetRelative(relData_t * result)
{
  uint8_t data[4] = { 0,0,0,0 };
  RAP_ReadBytes(data, 0x12, 4);
  
  Pinnacle_ClearFlags();

  result->pbyte0 = data[0];
  result->xDelta = data[1];
  result->yDelta = data[2];
  result->wheel = data[3];
}

__attribute__((weak)) void update_member(int8_t* member, int16_t* offset) {
    if (*offset > 127) {
        *member = 127;
        *offset -= 127;
    } else if (*offset < -127) {
        *member = -127;
        *offset += 127;
    } else {
        *member = *offset;
        *offset = 0;
    }
}


__attribute__((weak)) void process_mouse(report_mouse_t* mouse) {
    static int8_t new_x_offset = 0;
    static int8_t new_y_offset = 0;

    Pinnacle_GetRelative(&relData);

    mouse->x = (int8_t) relData.xDelta;
    mouse->y = (int8_t) relData.yDelta;
    
}

__attribute__((weak)) void pointing_device_task(void) {
    report_mouse_t mouse_report = pointing_device_get_report();

    process_mouse(&mouse_report);

    pointing_device_set_report(mouse_report);
    pointing_device_send();
}


__attribute__((weak)) void pointing_device_send(void) {
    static report_mouse_t old_report = {};
    report_mouse_t mouseReport = pointing_device_get_report();
   
    int8_t x = mouseReport.x, y = mouseReport.y;
    mouseReport.x = 0;
    mouseReport.y = 0;
    process_mouse_user(&mouseReport, x, y);
    if (has_report_changed(mouseReport, old_report)) {
        trackball_idle = false;
        host_mouse_send(&mouseReport);
    } else {
        trackball_idle = true;
    }
    mouseReport.x = 0;
    mouseReport.y = 0;
    old_report = mouseReport;
    pointing_device_set_report(mouseReport);
}

__attribute__((weak)) void process_mouse_user(report_mouse_t* mouse_report, int16_t x, int16_t y) {
    mouse_report->x = x;
    mouse_report->y = y;
}

__attribute__((weak)) bool has_report_changed(report_mouse_t new, report_mouse_t old) {
    return (new.x && new.x != old.x) ||
           (new.y && new.y != old.y)
}


