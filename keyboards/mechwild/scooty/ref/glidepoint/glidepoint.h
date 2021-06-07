#pragma once

#include <quantum.h>


// Hardware pin-number labels
//#define SDA_PIN   18
//#define SCL_PIN   19
//#define DR_PIN    9

//#define LED_0     21
//#define LED_1     20

// Cirque's 7-bit I2C Slave Address
#define CIRQUE_ADDR  (0x2A << 1)

#define CIRQUE_WRITE (TRACKBALL_ADDRESS | I2C_WRITE)
#define CIRQUE_READ  (TRACKBALL_ADDRESS | I2C_READ)

#define CIRQUE_I2C_TIMEOUT 100


// Masks for Cirque Register Access Protocol (RAP)
#define WRITE_MASK  0x80
#define READ_MASK   0xA0


// Register Config Values and Reference

 #define Z_IDLE_COUNT  0x05 // Written to 0x0A
 // 0x0A acceptes 0x00 through 0xFF (0-255 decimal)
 // 0x0A default is 0x1E 

 #define SYSCONFIG_1   0x00 // Written to 0x03   
 
/*  REG 0x03      +-----------------+-------------------+------------+-------------+
 * SysConfig1     |  Bit 7 - Bit 3  |      Bit 2        |   Bit 1    |    Bit 0    |
 * +--------------+-----------------+-------------------+------------+-------------+
 * | Description  |                 | Sleep Enable      | Shutdown   | Reset       |
 * +--------------+-----------------+-------------------+------------+-------------+
 * | Read/Write   |                 | R/W               | R/W        | R           |
 * +--------------+-----------------+-------------------+------------+-------------+
 * | Values       |                 | 1=low power mode  | 1=Shutdown | 0=Active    |
 * |              |                 | 0=normal mod      | 0=Active   |             |
 * +--------------+-----------------+-------------------+------------+-------------+
 * | Default      |                 | 0                 | 0          | 0           |
 * +--------------+-----------------+-------------------+------------+-------------+
 */
  
 #define FEEDCONFIG_1  0x01 // Written to 0x04

/*  REG 0x04      +------------------+--------------------+-------+-------------+-------------+-----------------+------------+-------------+
 * Data Output    |     Bit 7        |     Bit 6          | Bit 5 |    Bit 4    |    Bit 3    |      Bit 2      |   Bit 1    |    Bit 0    |
 * +--------------+------------------+--------------------+-------+-------------+-------------+-----------------+------------+-------------+
 * | Description  | Y data Invert[1] | X data Invert[1]   |       | Y Disable   | X Disable   | Filter Disable  | Data mode  | Feed Enable |
 * +--------------+------------------+--------------------+-------+-------------+-------------+-----------------+------------+-------------+
 * | Values       | 1=Y max to 0     | 1=X max to 0       |       | 1=no Y data | 1=no X data | 1=no filter     | 1=absolute | 1=feed      |
 * |              | 0=0 to Y max     | 0=0 to Y max       |       | 0=Y data    | 0=X data    | 0=filter        | 0=relative | 0=no feed   |
 * +--------------+------------------+--------------------+-------+-------------+-------------+-----------------+------------+-------------+
 * | Default      | 0                | 0                  |       | 0           | 0           | 0               | 0          | 0           |
 * +--------------+------------------+--------------------+-------+-------------+-------------+-----------------+------------+-------------+
 *
 *   [1] Y and X data count invert is only available when in absolute mode
 */
 
 #define FEEDCONFIG_2  0x1F // Written to 0x05
 
/*  REG 0x05     
 * Relative Mode  +------------------+-------+-------+--------------+-------------+-----------------+------------+-------------+
 * Features       |     Bit 7        | Bit 6 | Bit 5 |    Bit 4     |    Bit 3    |      Bit 2      |   Bit 1    |    Bit 0    |
 * +--------------+------------------+-------+-------+--------------+-------------+-----------------+------------+-------------+
 * | Description  | Swap X & Y       |       |       | GlideExtend® | Scroll      | Secondary       | All Taps   | Intellimouse|
 * |              |                  |       |       | Disable      | Disable     | Tap Disable     | Disable    | Enable      |
 * +--------------+------------------+-------+-------+--------------+-------------+-----------------+------------+-------------+
 * | Values       | 1=90° rotation   |       |       | 1=disable    | 1=disable   | 1=disable       | 1=disable  | 1=enable    |
 * |              | 0=0° rotation    |       |       | 0=enable     | 0=enable    | 0=enable        | 0=enable   | 0=disable   |
 * +--------------+------------------+-------+-------+--------------+-------------+-----------------+------------+-------------+
 * | Default      | 0                |       |       | 0            | 0           | 0               | 0          | 0           |
 * +--------------+------------------+-------+-------+--------------+-------------+-----------------+------------+-------------+  
 */



// Coordinate scaling values
#define PINNACLE_XMAX     2047    // max value Pinnacle can report for X
#define PINNACLE_YMAX     1535    // max value Pinnacle can report for Y
#define PINNACLE_X_LOWER  127     // min "reachable" X value
#define PINNACLE_X_UPPER  1919    // max "reachable" X value
#define PINNACLE_Y_LOWER  63      // min "reachable" Y value
#define PINNACLE_Y_UPPER  1471    // max "reachable" Y value
#define PINNACLE_X_RANGE  (PINNACLE_X_UPPER-PINNACLE_X_LOWER)
#define PINNACLE_Y_RANGE  (PINNACLE_Y_UPPER-PINNACLE_Y_LOWER)
#define ZONESCALE 256   // divisor for reducing x,y values to an array index for the LUT
#define ROWS_Y ((PINNACLE_YMAX + 1) / ZONESCALE)
#define COLS_X ((PINNACLE_XMAX + 1) / ZONESCALE)

// ADC-attenuation settings (held in BIT_7 and BIT_6)
// 1X = most sensitive, 4X = least sensitive
#define ADC_ATTENUATE_1X   0x00
#define ADC_ATTENUATE_2X   0x40
#define ADC_ATTENUATE_3X   0x80
#define ADC_ATTENUATE_4X   0xC0

typedef struct _relData
{
  uint16_t pbyte0;
  uint16_t xDelta;
  uint16_t yDelta;
  uint16_t wheel;
} relData_t;

//const uint16_t ZONESCALE = 256;
//const uint16_t ROWS_Y = 6;
//const uint16_t COLS_X = 8;

// These values require tuning for optimal touch-response
// Each element represents the Z-value below which is considered "hovering" in that XY region of the sensor.
// The values present are not guaranteed to work for all HW configurations.
const uint8_t ZVALUE_MAP[ROWS_Y][COLS_X] =
{
  {0, 0,  0,  0,  0,  0, 0, 0},
  {0, 2,  3,  5,  5,  3, 2, 0},
  {0, 3,  5, 15, 15,  5, 2, 0},
  {0, 3,  5, 15, 15,  5, 3, 0},
  {0, 2,  3,  5,  5,  3, 2, 0},
  {0, 0,  0,  0,  0,  0, 0, 0},
};

void pointing_device_init(void);
void process_mouse_user(report_mouse_t* mouse_report, int16_t x, int16_t y);
void update_member(int8_t* member, int16_t* offset);
bool has_report_changed(report_mouse_t new, report_mouse_t old);
void process_mouse(report_mouse_t* mouse);
void pointing_device_task(void);
void pointing_device_send(void);
void Pinnacle_GetRelative(relData_t * result);
void setAdcAttenuation(uint8_t adcGain);
void Pinnacle_Init(void);
void RAP_Init(void);
void Pinnacle_ClearFlags(void);
void ERA_WriteByte(uint16_t address, uint8_t data);
void ERA_ReadBytes(uint16_t address, uint8_t * data);
void RAP_Write(uint8_t reg_write, uint8_t data);
void RAP_ReadBytes(uint8_t* data, uint8_t reg_read, uint16_t size_of_data);
   