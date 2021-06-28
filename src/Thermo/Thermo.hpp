#ifndef THERMO_HPP
#define THERMO_HPP

#include <DHT.h>

class Thermo
{
	private:
	DHT *dht;
	
	public:
	Thermo(uint8_t dhtPIN, uint8_t dhtType);
	~Thermo();
	
	float getTemp();
	float getHum();
};

#endif