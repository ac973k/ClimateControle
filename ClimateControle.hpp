#ifndef CLIMATECONTROLE_HPP
#define CLIMATECONTROLE_HPP

#include "src/Thermo/Thermo.hpp"
#include "src/Display/Display.hpp"
#include "src/Date/Date.hpp"
#include "src/LG_AIR/LG_AIR.hpp"

class ClimateControle
{
	private:
	Thermo *thermo;
	Display *lcd;
	DateTime *dt;
	LG_AIR *air;
	
	float MaxSummerTemp;
	float MinSummerTemp;
	float MaxWinterTemp;
	float MinWinterTemp;
	
	uint8_t power;
	
	uint8_t count;
	
	public:
	ClimateControle();
	~ClimateControle();
	
	void printTempAndHum();
	void printDateAndTime();
	void printInform();
	
	void setupDateAndTime(uint8_t date, uint8_t mon, uint16_t year, uint8_t hour, uint8_t min, uint8_t sec);
	void setupTempLimits(float aMaxSummerTemp, float aMinSummerTemp, float aMaxWinterTemp, float aMinWinterTemp);
	
	void switchMode();
	
	void onUpdate();
	
	void test();
};

#endif