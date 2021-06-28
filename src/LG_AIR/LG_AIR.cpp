#include "LG_AIR.hpp"

#include <IRremote.h>

LG_AIR::LG_AIR(uint8_t aPin, bool aEnableLED, uint8_t aLEDPin)
{
	sender = new IRsend(aPin);
	sender->begin(aPin, aEnableLED, aLEDPin);
}

LG_AIR::~LG_AIR()
{
	
}

void LG_AIR::airPowerON()
{
	sender->sendLG(0x88, 0x30, 28);
}


void LG_AIR::airPowerOFF()
{
	sender->sendLG(0x88, 0xC005, 28);
}

	
void LG_AIR::sendCode(uint8_t uAddress, uint16_t uCommand, uint_fast8_t numberOfRepeats, bool isRepeat)
{
	sender->sendLG(uAddress, uCommand, numberOfRepeats, isRepeat);
}

void LG_AIR::aSwitchMode(char aCurrentMonth)
{
	if (aCurrentMonth == "December" || aCurrentMonth == "January" || aCurrentMonth ==  "February") {
		
		sender->sendLG(0x88, 0x0CF4, 28);
		
	}
	else if (aCurrentMonth == "June" || aCurrentMonth == "July" || aCurrentMonth ==  "August") {
		sender->sendLG(0x88, 0x0834, 28);
	}
}