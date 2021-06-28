#ifndef DATE_HPP
#define DATE_HPP

#include <DS3231.h>                    // Подключаем библиотеку Wire  

class DateTime
{
	private:
	DS3231 *rtc;
	
	public:
	DateTime(uint8_t data_pin, uint8_t sclk_pin);
	~DateTime();
	
	String getDate();
	String getMonthStr();
	
	String getTime();
	
	void setDate(uint8_t date, uint8_t mon, uint16_t year);
	void setTime(uint8_t hour, uint8_t min, uint8_t sec);
};

#endif