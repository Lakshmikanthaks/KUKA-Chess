 
#include <Wire.h>
#include <MCP23017.h>

// http://arduiniana.org/libraries/streaming/
template<class T> inline Print &operator <<(Print &obj, T arg)
{  
  obj.print(arg); 
  return obj; 
}

MCP23017 GPIOchipArray[] = {MCP23017(), MCP23017(), MCP23017(), MCP23017(), MCP23017(), MCP23017(), MCP23017(), MCP23017()}; 

void setup()
{
  Serial.begin(9600); // set up serial
  Serial << F("\n- - - - - - - -\nSerial Started\n");

  Wire.begin();           // Wire must be started!

  // Set up each board:
  for(uint8_t i=0;i<=7;i++)  {  
    GPIOchipArray[i].begin(i);
    GPIOchipArray[i].init();
    GPIOchipArray[i].internalPullupMask(65535);
    GPIOchipArray[i].inputOutputMask(65535);  // All inputs
  }
}

void loop()
{
    Serial << "----\n";
  for(uint8_t i=0;i<=7;i++)  {  
    word buttonStatus = GPIOchipArray[i].digitalWordRead();
    Serial << "Board " << i << ": ";
    Serial.println(buttonStatus, BIN);
    delay(1000);
  }
    word buttonStatus = GPIOchipArray[7].digitalWordRead();
    Serial << "Board " << 7 << ": ";
    Serial.println(buttonStatus, BIN);
    delay(1000);
} 




