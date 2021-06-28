#ifndef DISPLAY_HPP
#define DISPLAY_HPP

#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

class Display
{
	private:
	LiquidCrystal_I2C *lcd;
	
	public:
	Display(uint8_t address, uint8_t col, uint8_t row);
	~Display();
	
	void printOnLCD(char text[100]);
	void printOnLCD(char text[100], int num);
	void printOnLCD(char text[100], float num);
	void setStr(uint8_t colomn, uint8_t row);
	
	void lcdClear();
};

#endif