#include "ClimateControle.hpp"

ClimateControle *controle;

void setup() {

  controle = new ClimateControle;
  controle->setupTempLimits(31.9, 27.0, 29.0, 20.0); //Max Temp Summer, Min Temp Summer, Max Temp Winner, Min Temp Winner;

  //controle->switchMode(); //Get current Month and switch Hot or Cold Mode

  //controle->setupDateAndTime(date, mon, year, hour, min, sec); //Example: controle->setupDateAndTime(28, 6, 2021, 17, 07, 00);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  controle->printTempAndHum();
  controle->printDateAndTime();
  controle->printInform();
  controle->onUpdate();
  
  //controle->test();
  delay(2000);
}
