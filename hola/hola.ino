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
#define TOP         B00000111
#define BOTTOM      B11100000

// Proto: LedControl(int dataPin, int clkPin, int csPin, int numDevices=1);
LedControl lc=LedControl(DATA_PIN, CLOCK_PIN, LOAD_PIN, -4);

unsigned long delaytime=100;
byte pos_y1 = B00111000;
byte pos_y2 = B00011100;





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

  do {
    delay(250);
    pos_y1 = pos_y1 >> 1;
    pos_y2 = pos_y2 << 1;
    lc.setColumn(0, 0, pos_y1);
    lc.setColumn(0, 7, pos_y2);
    delay(250);
  } while ( (pos_y1 != TOP) && (pos_y2 != BOTTOM) );
   
  do {
    delay(250);
    pos_y1 = pos_y1 << 1;
    pos_y2 = pos_y2 >> 1;
    lc.setColumn(0, 0, pos_y1);
    lc.setColumn(0, 7, pos_y2);
    delay(250);
  } while ( (pos_y1 != BOTTOM) && (pos_y2 != TOP) );
  

  /*
  while (pos_y2 != B00000111){
    delay(500);
    pos_y2 = pos_y2 >> 1;
    lc.setColumn(0, 7, pos_y2);
  } 
  while (pos_y2 != B11100000){
    delay(500);
    pos_y2 = pos_y2 << 1;
    lc.setColumn(0, 7, pos_y2);
  }
  */

}
