/**
 * CIID Experimental Imaging
 * 
 * Example 2 : Sensor-Based Trigger
 *  Controlling DSLR from Arduino using a sensor and relay
 *  
 */

/* VARS
 --------------------------------- */
//pin definitions
int ledPin = 13; // led indicator pin
int sigPin = 7;  // signal pin
int snsPin = 5;

// state of the pin when read
int  lastReading   = HIGH; // last reading of sensor pin, default is HIGH
long lastChange    = 0;    // time of last pin state change 
int  debounceDelay = 100;  // time to wait for debouncing

/* SETUP
 --------------------------------- */
void setup() {

  Serial.begin(9600);
  
  //set pins as output
  pinMode(ledPin,OUTPUT);
  pinMode(sigPin, OUTPUT);

  //start with no voltage to output pins
  digitalWrite(ledPin, LOW);
  digitalWrite(sigPin, LOW);

  // set pin 5 as input
  // use the internal pull-up resitor
  digitalWrite(snsPin, HIGH);
}

/* LOOP
 --------------------------------- */
void loop() {

  int reading = digitalRead(snsPin);

  // confirm reading by debouncing the input
  if( confirm(reading) ) {

    Serial.println("Sensor Detected!");

    // set signal & led pins to HIGH
    digitalWrite(sigPin, HIGH); // trip the relay
    digitalWrite(ledPin, HIGH); // led visual indicator
    
    delay(1000); //brief delay
    
    // return signal + led pins to LOW
    digitalWrite(sigPin, LOW); // trip the relay
    digitalWrite(ledPin, LOW); // led visual indicator
  }
}


bool confirm(int reading) {

  bool confirmed = false;

  // in pin has changed
  if(reading != lastReading) { 

    // update the last reading
    lastReading = reading;
    
    // record the time of change
    lastChange  = millis();
  }

  // if time since last state change exceeds delay
  if ( millis() - lastChange > debounceDelay) {

    // confirm the reading, but only when state is LOW
    if(reading == LOW) {
      confirmed = true;
    }
  }
  
  return confirmed;
}




