#include "ClimateControle.hpp"

ClimateControle::ClimateControle()
{
	thermo = new Thermo(11, DHT11); //pin, DHT Version [DHT11, DHT22]
	lcd = new Display(0x3F, 16, 2); //Address, colomn, row
	dt = new DateTime(A4, A5); //SDA, SCL pins
	air = new LG_AIR(3, false, 0); //pin, enable LED True/False, Led Pin
	
	power = 0; //AIR LG. Power ON = 1, Power OFF = 0
	
	Serial.begin(115200);
}

ClimateControle::~ClimateControle()
{
	delete air;
	delete dt;
	delete lcd;
	delete thermo;
}

void ClimateControle::printTempAndHum()
{
	count = 5;
	
	while (count) {
		lcd->setStr(0, 0);
		lcd->printOnLCD("T = ", thermo->getTemp());
		Serial.print("T = ");
		Serial.print(thermo->getTemp());
		Serial.print("\n");

		lcd->setStr(0, 1);
		lcd->printOnLCD("H = ", thermo->getHum());
		lcd->printOnLCD(" %");
		Serial.print("H = ");
		Serial.print(thermo->getHum());
		Serial.print("\n");

		count--;

		delay(1000);
    
		lcd->lcdClear();
	}
}

void ClimateControle::printDateAndTime()
{
	count = 5;
	
	while (count) {

		lcd->setStr(0, 0);
		lcd->printOnLCD(dt->getDate().c_str());
		Serial.print(dt->getDate().c_str());
		Serial.print("\n");

		lcd->setStr(0, 1);
		lcd->printOnLCD(dt->getTime().c_str());
		Serial.print(dt->getTime().c_str());
		Serial.print("\n");

		count--;

		delay(1000);

		lcd->lcdClear();
	}
}

void ClimateControle::printInform()
{
	if (power == 0) {
		lcd->setStr(0, 0);
		lcd->printOnLCD("AIR Off");
		lcd->setStr(0, 1);
		lcd->printOnLCD("by Danilka =)");
	}
	else if (power == 1) {
		lcd->setStr(0, 0);
		lcd->printOnLCD("AIR On");
		lcd->setStr(0, 1);
		lcd->printOnLCD("by Danilka =)");
	}

	delay(5000);
	lcd->lcdClear();
}

void ClimateControle::setupDateAndTime(uint8_t date, uint8_t mon, uint16_t year, uint8_t hour, uint8_t min, uint8_t sec)
{
	dt->setDate(date, mon, year);
	dt->setTime(hour, min, sec);              //  Установить время 16:29:00 (формат 24 часа)
}

void ClimateControle::setupTempLimits(float aMaxSummerTemp, float aMinSummerTemp, float aMaxWinterTemp, float aMinWinterTemp)
{
	MaxSummerTemp = aMaxSummerTemp;
	MinSummerTemp = aMinSummerTemp;
	MaxWinterTemp = aMaxWinterTemp;
	MinWinterTemp = aMinWinterTemp;
}

void ClimateControle::switchMode()
{
	air->aSwitchMode(dt->getMonthStr().c_str()); //FORMAT_SHORT = Jan, Feb etc... default: January, February, etc...
}

void ClimateControle::onUpdate()
{	
	if (dt->getMonthStr() == "December" || dt->getMonthStr() == "January" || dt->getMonthStr() == "February")
	{
		if (thermo->getTemp() <= MinWinterTemp && power == 0)
		{
			air->airPowerON();
			power = 1;
			Serial.print("Power ON\n");
			lcd->lcdClear();
			lcd->setStr(0, 0);
			lcd->printOnLCD("Power ON");
			delay(2000);
			lcd->lcdClear();
		}
		else if (thermo->getTemp() >= MaxWinterTemp && power == 1)
		{
			air->airPowerOFF();
			power = 0;
			Serial.print("Power OFF\n");
			lcd->lcdClear();
			lcd->setStr(0, 0);
			lcd->printOnLCD("Power OFF");
			delay(2000);
			lcd->lcdClear();
		}
	}
		
	if (dt->getMonthStr() == "June" or dt->getMonthStr() == "July" or dt->getMonthStr() == "August")
	{
		if (thermo->getTemp() >= MaxSummerTemp && power == 0)
		{
			air->airPowerON();
			power = 1;
			Serial.print("Power ON\n");
			lcd->lcdClear();
			lcd->setStr(0, 0);
			lcd->printOnLCD("Power ON");
			delay(2000);
			lcd->lcdClear();
		}
		else if (thermo->getTemp() <= MinSummerTemp && power == 1)
		{
			air->airPowerOFF();
			power = 0;
			Serial.print("Power OFF\n");
			lcd->lcdClear();
			lcd->setStr(0, 0);
			lcd->printOnLCD("Power OFF");
			delay(2000);
			lcd->lcdClear();
		}
	}
}

void ClimateControle::test()
{
	lcd->setStr(0, 0);
	lcd->printOnLCD("Max Summer:", MaxSummerTemp);
	lcd->setStr(0, 1);
	lcd->printOnLCD("Min Summer:", MinSummerTemp);
	
	delay(2000);
	lcd->lcdClear();
	
	lcd->setStr(0, 0);
	lcd->printOnLCD("Max Winter:", MaxWinterTemp);
	lcd->setStr(0, 1);
	lcd->printOnLCD("Min Winter:", MinWinterTemp);
	delay(2000);
	lcd->lcdClear();
	
	lcd->setStr(0, 0);
	lcd->printOnLCD("Month: ");
	lcd->printOnLCD(dt->getMonthStr().c_str());
	delay(2000);
	lcd->lcdClear();
}