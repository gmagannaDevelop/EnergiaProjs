#include <LedControl.h>

/**
* Led Matrix test
*/


#include <LedControl.h>

#define DATA_PIN    P1_3        // data for AS1106
#define CLOCK_PIN   P1_5        // clock for AS1106
#define LOAD_PIN    P1_4        // load CS for AS1106

// Proto: LedControl(int dataPin, int clkPin, int csPin, int numDevices=1);
LedControl lc=LedControl(DATA_PIN, CLOCK_PIN, LOAD_PIN, 1);

unsigned long delaytime=100;


void setup() {

  pinMode(RED_LED,OUTPUT);
  pinMode(DATA_PIN,OUTPUT);
  pinMode(CLOCK_PIN,OUTPUT);
  pinMode(LOAD_PIN,OUTPUT);
  digitalWrite(LOAD_PIN,HIGH);
  // BLink to test...
  digitalWrite(RED_LED, HIGH);
  delay(1000);
  digitalWrite(RED_LED, LOW);



  lc.init();
  lc.shutdown(0,false);
  lc.setIntensity(0,10);
  lc.clearDisplay(0);

}

void loop() {

  // BLink to test
  digitalWrite(RED_LED, HIGH);
  lc.clearDisplay(0);

  int i;
  for (i=0; i<4; i++)
  { 
    lc.setColumn(0, i, B00111000);
    delay(1000);
    lc.clearDisplay(0);
    delay(1000);
  }  

}
