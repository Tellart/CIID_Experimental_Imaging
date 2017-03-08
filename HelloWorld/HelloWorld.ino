/*
 * OPTIONAL:
 * To reduce the library compiled size and limit its memory usage, you
 * can specify which shields you want to include in your sketch by
 * defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define.
 */
#define INCLUDE_MIC_SHIELD
#define INCLUDE_TERMINAL_SHIELD
#define CUSTOM_SETTINGS


/* Include 1Sheeld library. */
#include <OneSheeld.h>


/* A name for the LED on pin 13. */
int ledPin = 13;

void setup() {
  // put your setup code here, to run once:
   /* Start communication. */
  OneSheeld.begin();

  pinMode(ledPin, OUTPUT);
}

void loop() {
  
  Terminal.println(Mic.getValue());

  if(Mic.getValue() > 50)
  {
    /* Turn on the LED. */
    digitalWrite(ledPin, HIGH);
    delay(1000);
  }
  else
  {
    /* Turn off the LED. */
    digitalWrite(ledPin, LOW);
  }
  // put your main code here, to run repeatedly:

}
