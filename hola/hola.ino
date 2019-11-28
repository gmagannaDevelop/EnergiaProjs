#include <LedControl.h>

/**
* Led Matrix test
*/


#include <LedControl.h>

#define DATA_PIN    P1_3        // data for AS1106
#define CLOCK_PIN   P1_5        // clock for AS1106
#define LOAD_PIN    P1_4        // load CS for AS1106
#define P1_UP       P1_6        // pin to signal up
#define P1_DOWN     P1_7        // pin to signal down.

// Proto: LedControl(int dataPin, int clkPin, int csPin, int numDevices=1);
LedControl lc=LedControl(DATA_PIN, CLOCK_PIN, LOAD_PIN, 4);

unsigned long delaytime=100;


void setup() {

  pinMode(RED_LED,OUTPUT);
  pinMode(DATA_PIN,OUTPUT);
  pinMode(CLOCK_PIN,OUTPUT);
  pinMode(LOAD_PIN,OUTPUT);
  pinMode(P1_UP, INPUT);
  pinMode(P1_DOWN, INPUT);
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
  byte pos_y = B00111000;
   
  if (P1_UP == 0)
  {
    if (pos_y != B11100000){
      pos_y = pos_y << 1;
    }
  }
  if (P1_DOWN == 0)
  {
    if (pos_y != B00000111){
      pos_y = pos_y >> 1;
    }
  }
    
  lc.setColumn(0, 0, pos_y);

}
