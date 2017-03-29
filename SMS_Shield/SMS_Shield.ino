/*

SMS Shield Example

This example shows an application on 1Sheeld's SMS shield.

By using this example, you can send a SMS when the value
of the smartphone's temperature sensor exceeds a certain
limit.

OPTIONAL:
To reduce the library compiled size and limit its memory usage, you
can specify which shields you want to include in your sketch by
defining CUSTOM_SETTINGS and the shields respective INCLUDE_ define. 

*/

#define CUSTOM_SETTINGS
#define INCLUDE_SMS_SHIELD
#define INCLUDE_TERMINAL_SHIELD

/* Include 1Sheeld library. */
#include <OneSheeld.h>

/* Define a boolean flag. */
boolean isMessageSent = false;

void setup() 
{
 /* Start communication. */
 OneSheeld.begin(); 
}

void loop() {

  delay(5000); // wait 5 seconds
  
  if(!isMessageSent) {  

    // log the event to the 1sheeld terminal
    Terminal.println("SENT SMS");

    // add your number here
    // don't forget to add the country code
    SMS.send("+11234567890","Message from 1Sheeld");
    /* Set the flag. */
    isMessageSent = true;  
  }
}
