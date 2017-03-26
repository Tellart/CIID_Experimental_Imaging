/**
 * CIID Experimental Imaging
 * 
 * Example 1 : Intervelometer
 *  Controlling DSLR from Arduino using a relay
 *  
 **/

/* VARS
 --------------------------------- */
//pin definitions
int ledPin = 13; // led indicator pin
int sigPin = 7;  // signal pin

long lastTrigger  = 0;     // time of last shot (ms)
int  triggerDelay = 1000;  // time between shots (ms)
int  shotsTaken   = 0;     // number shots taken
bool doneShooting = false; // stops when true
int  maxShots     = 10;    // max num of shots

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
}

/* LOOP
 --------------------------------- */
void loop() {

  // millis = time (in ms) since program started running
  // if last trigger great than delay, take another shot
  if(millis() - lastTrigger > triggerDelay && !doneShooting) {

    // print out the number of shots taken
    shotsTaken++;
    Serial.print("taking shot ");
    Serial.println(shotsTaken, DEC); 

    // set pins to HIGH
    digitalWrite(sigPin, HIGH); // trip the relay
    digitalWrite(ledPin, HIGH); // led visual indicator
    
    delay(100); //pause briefly
    
    // set pins to LOW
    digitalWrite(sigPin, LOW); // trip the relay
    digitalWrite(ledPin, LOW); // led visual indicator
  }

  // if we've reach the max number of shots, stop shooting
  if(shotsTaken >= maxShots) {
    doneShooting = true;
  }
}




