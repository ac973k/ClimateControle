#include "date.hpp"

DateTime::DateTime(uint8_t data_pin, uint8_t sclk_pin)
{
	rtc = new DS3231(data_pin, sclk_pin);
	rtc->begin();
}

DateTime::~DateTime()
{
	delete rtc;
}

String DateTime::getDate()
{
	return rtc->getDateStr();
}

String DateTime::getMonthStr()
{
	return rtc->getMonthStr();
}

String DateTime::getTime()
{
	return rtc->getTimeStr();
}

void DateTime::setDate(uint8_t date, uint8_t mon, uint16_t year)
{
	rtc->setDate(date, mon, year);
}

void DateTime::setTime(uint8_t hour, uint8_t min, uint8_t sec)
{
	rtc->setTime(hour, min, sec);
}