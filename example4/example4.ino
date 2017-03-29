/**
 * CIID Experimental Imaging
 * 
 * Example 3 : 1Sheeld Remote Trigger
 *  Controlling DSLR from Arduino via 1Sheeld & Phone
 *  Uses the 1Sheeld PushButton Virtual Shield
 *  
 */

/* INCLUDES
 --------------------------------- */
 
/* Note:
To reduce library compile-size, and limit memory usage, 
we specify the shields (virtual) we want to include by
defining CUSTOM_SETTINGS and shields INCLUDE_ definition 
*/

#define CUSTOM_SETTINGS
#define INCLUDE_MIC_SHIELD

//include 1sheeld lib
#include <OneSheeld.h>

/* VARS
 --------------------------------- */
/* A name for the LED on pin 13. */
int ledPin = 13;
int sigPin = 7;

int threshold = 80;

/* SETUP
 --------------------------------- */
void setup() {
  
  // start comms with shield
  OneSheeld.begin();
  
  // set the trigger & led pin to ouput
  pinMode(ledPin, OUTPUT);
  pinMode(sigPin, OUTPUT);
}

/* LOOP
 --------------------------------- */
void loop() {
  
  // check if the "push button" is pressed
  if( Mic.getValue() > threshold ) {
    
    // set pins to HIGH
    digitalWrite(sigPin, HIGH); // trip the relay
    digitalWrite(ledPin, HIGH); // led visual indicator
    
    delay(1000); //pause briefly
    
    // set pins to LOW
    digitalWrite(sigPin, LOW); // trip the relay
    digitalWrite(ledPin, LOW); // led visual indicator
  }
}
