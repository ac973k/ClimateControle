#ifndef LG_AIR_HPP
#define LG_AIR_HPP

#include <IRremoteInt.h>

class LG_AIR
{
	private:
	IRsend *sender;
	
	public:
	LG_AIR(uint8_t aPin, bool aEnableLED, uint8_t aLEDPin);
	~LG_AIR();
	
	void airPowerON();
	void airPowerOFF();
	
	void sendCode(uint8_t uAddress, uint16_t uCommand, uint_fast8_t numberOfRepeats, bool isRepeat);
	
	void aSwitchMode(char aCurrentMonth);
};

#endif