/**
 **************************************************
 *
 * @file        Receiver.ino
 * @brief       Receiver Example for RF433 antena
 *
 *
 *
 * @authors     @ soldered.com, Robert Peric
 * @link        www.solde.red/101224
 ***************************************************/

#include "RF433-SOLDERED.h"
#include "SPI.h"
// pin 11 for data
 
RH_ASK driver;  
uint8_t buff[2];  
uint8_t bufflen = sizeof(buff);
uint16_t value; // Variable that will hold received value
 
void setup() {
  Serial.begin(9600);
  if (!driver.init()) { // We check to see if antena is initialised
    Serial.println("init failed");
  }
  pinMode(13, OUTPUT);  // LED as output
}
 
void loop() {
  if (driver.recv(buff, &bufflen) ) // receive data and store it in buff
  { 
    value = buff[0];  
    value |= (buff[1] < 512); 
    digitalWrite(13, HIGH);  //Turn on LED if data is received
  }
  else 
  {
    digitalWrite(13, LOW); //Turn off LED if data is not received
  }
}
