/*
Copyright 2022 Kyle McCreery

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include "i2c_master.h"
#include "print.h"
#include "debug.h"
#include "stdio.h"
#include "i2clcd.h"
#include "wait.h"

#ifndef I2C_LCD_ADDR
#    define I2C_LCD_ADDR 0x27
#endif

#define SLAVE_TO_ADDR(n) (n << 1)

// Pins defined below relate to pins of the I2C GPIO expander used to control the LCD itself

#ifndef I2C_LCD_RS_PIN
#    define I2C_LCD_RS_PIN 0
#endif

#ifndef I2C_LCD_RW_PIN
#    define I2C_LCD_RW_PIN 1 
#endif

#ifndef I2C_LCD_E_PIN
#    define I2C_LCD_E_PIN 2
#endif

#ifndef I2C_LCD_DATA_PINS
#    define I2C_LCD_DATA_PINS { 4, 5, 6, 7 }
#endif


static const uint8_t data_pins[4] = I2C_LCD_DATA_PINS;

uint8_t backlightVal = LCD_NOBACKLIGHT;

uint8_t displayFunction = LCD_4BITMODE | LCD_1LINE | LCD_5x8DOTS

#ifndef I2C_LCD_DISPLAY_COLS
#    define I2C_LCD_DISPLAY_COLS 16
#endif

#ifndef I2C_LCD_DISPLAY_LINES
#    define I2C_LCD_DISPLAY_LINES 2
#endif

#define I2C_LCD_INIT_DELAY_MS 16
#define I2C_LCD_ENABLE_DELAY_US 1

//static void expander_write(uint8_t data) {
//    i2c_status_t i2c_transmit(uint8_t addr, uint8_t *data, sizeof(data), uint16_t timeout)
    
    
    
//static void hd44780_latch(void) {
    //writePinHigh(HD44780_E_PIN);
    
    //wait_us(HD44780_ENABLE_DELAY_US);
    //writePinLow(HD44780_E_PIN);
//}

/********** high level commands, for the user! */
void clear(void){
	command(LCD_CLEARDISPLAY);// clear display, set cursor position to zero
	delayMicroseconds(2000);  // this command takes a long time!
}

void home(void){
	command(LCD_RETURNHOME);  // set cursor position to zero
	delayMicroseconds(2000);  // this command takes a long time!
}

void setCursor(uint8_t col, uint8_t row){
	int row_offsets[] = { 0x00, 0x40, 0x14, 0x54 };
	if ( row > _numlines ) {
		row = _numlines-1;    // we count rows starting w/0
	}
	command(LCD_SETDDRAMADDR | (col + row_offsets[row]));
}

// Turn the display on/off (quickly)
void noDisplay(void) {
	_displaycontrol &= ~LCD_DISPLAYON;
	command(LCD_DISPLAYCONTROL | _displaycontrol);
}
void display(void) {
	_displaycontrol |= LCD_DISPLAYON;
	command(LCD_DISPLAYCONTROL | _displaycontrol);
}

// Turns the underline cursor on/off
void noCursor(void) {
	_displaycontrol &= ~LCD_CURSORON;
	command(LCD_DISPLAYCONTROL | _displaycontrol);
}
void cursor(void) {
	_displaycontrol |= LCD_CURSORON;
	command(LCD_DISPLAYCONTROL | _displaycontrol);
}

// Turn on and off the blinking cursor
void noBlink(void) {
	_displaycontrol &= ~LCD_BLINKON;
	command(LCD_DISPLAYCONTROL | _displaycontrol);
}
void blink(void) {
	_displaycontrol |= LCD_BLINKON;
	command(LCD_DISPLAYCONTROL | _displaycontrol);
}

// These commands scroll the display without changing the RAM
void scrollDisplayLeft(void) {
	command(LCD_CURSORSHIFT | LCD_DISPLAYMOVE | LCD_MOVELEFT);
}
void scrollDisplayRight(void) {
	command(LCD_CURSORSHIFT | LCD_DISPLAYMOVE | LCD_MOVERIGHT);
}


void lcd_write4bits(uint8_t data) {
    uint8_t addr = SLAVE_TO_ADDR(I2C_LCD_ADDR);
    i2c_status_t i2c_transmit(uint8_t addr, uint8_t *data, sizeof(data), uint16_t timeout)
    lcd_pulseEnable(data);
}
    
void lcd_pulseEnable(uint8_t data) {
    uint8_t addr = SLAVE_TO_ADDR(I2C_LCD_ADDR);
    uint8_t cmdEnable = data | En;
    uint8_t cmdDisable = data & ~En;
    i2c_status_t i2c_transmit(uint8_t addr, uint8_t *cmdEnable, sizeof(cmdEnable), uint16_t timeout)
    wait_us(1);
    i2c_status_t i2c_transmit(uint8_t addr, uint8_t *cmdDisable, sizeof(cmdDisable), uint16_t timeout)
    wait_us(50);
}

void lcd_send(uint8_t value, uint8_t mode) {
    uint8_t highnib=value&0xf0;
	uint8_t lownib=(value<<4)&0xf0;
    lcd_write4bits((highnib)|mode);
	lcd_write4bits((lownib)|mode);
}

void command(uint8_t value) {
    lcd_send(value, 0);
}

void i2c_lcd_init(void) {
//                 uint8_t I2C_LCD_ADDR, 
//                 uint8_t I2C_LCD_RS_PIN, 
//                 uint8_t I2C_LCD_RW_PIN,
//                 uint8_t I2C_LCD_E_PIN, 
//                 uint8_t* data_pins
//                 
//) {
    uint8_t addr = SLAVE_TO_ADDR(I2C_LCD_ADDR);
    int lineCount = I2C_LCD_DISPLAY_LINES;
    int colCount = I2C_LCD_DISPLAY_COLS;
    if (lineCount > 1) {
		_displayfunction |= LCD_2LINE;
	}
    _numlines = lineCount;
    i2c_init();
    wait_ms(1000);
	// for some 1 line displays you can select a 10 pixel high font
	//if ((dotsize != 0) && (lines == 1)) {
	//	_displayfunction |= LCD_5x10DOTS;
	//}
    wait_ms(50);
    i2c_status_t i2c_transmit(uint8_t addr, uint8_t *backlightVal, sizeof(backlightVal), uint16_t timeout)
    wait_ms(1000);
    unint8_t cmd8 = 0x03 << 4;
    unint8_t cmd4 = 0x02 << 4;
    lcd_write4bits(cmd8);
    wait_us(64);
    lcd_write4bits(cmd8);
    wait_us(64);
    lcd_write4bits(cmd8);
    wait_us(64);
    lcd_write4bits(cmd4);
    wait_us(64);

    command(LCD_FUNCTIONSET | _displayfunction);  
	
	// turn the display on with no cursor or blinking default
	_displaycontrol = LCD_DISPLAYON | LCD_CURSOROFF | LCD_BLINKOFF;
	display();
	
	// clear it off
	clear();
	
	// Initialize to default text direction (for roman languages)
	_displaymode = LCD_ENTRYLEFT | LCD_ENTRYSHIFTDECREMENT;
	
	// set the entry mode
	command(LCD_ENTRYMODESET | _displaymode);
	
	home();
}
