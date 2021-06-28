#include "Thermo.hpp"

Thermo::Thermo(uint8_t dhtPIN, uint8_t dhtType)
{
	dht = new DHT(dhtPIN, dhtType);
	dht->begin();
}

Thermo::~Thermo()
{
	delete dht;
}

float Thermo::getTemp()
{
	return dht->readTemperature();
}

float Thermo::getHum()
{
	return dht->readHumidity();
}