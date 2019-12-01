


#include <LedControl.h>

/**
* Led Matrix test
*/


/* LEGACY DEFINITIONS :
#define DATA_PIN    5         //       data for AS1106
#define CLOCK_PIN   7         //       clock for AS1106
#define LOAD_PIN    6         //       load CS for AS1106

#define P1_UP       12        // P2_4  pin to signal up
#define P1_DOWN     13        // P2_5  pin to signal down.
#define P2_UP       15        // P1_6  pin to signal up
#define P2_DOWN     14        // P1_7  pin to signal down.

#define TOP         B00000111
#define BOTTOM      B11100000
*/


#define DATA_PIN    12        //       data for AS1106
#define CLOCK_PIN   10        //       clock for AS1106
#define LOAD_PIN    11        //       load CS for AS1106

#define P1_UP       3        // P1_1  pin to signal up
#define P1_DOWN     4        // P1_2  pin to signal down.
#define P2_UP       5        // P1_3  pin to signal up
#define P2_DOWN     6        // P1_4  pin to signal down.

#define TOP         B00000111
#define BOTTOM      B11100000    

// Proto: LedControl(int dataPin, int clkPin, int csPin, int numDevices=1);
LedControl lc=LedControl(DATA_PIN, CLOCK_PIN, LOAD_PIN, 4);


void move_player_one(void);
void move_player_two(void);

unsigned long delaytime=100;
byte pos_y1 = B00111000;
byte pos_y2 = B00011100;
byte bally = B00100000;

void setup() {

  pinMode(RED_LED,OUTPUT);
  pinMode(DATA_PIN,OUTPUT);
  pinMode(CLOCK_PIN,OUTPUT);
  pinMode(LOAD_PIN,OUTPUT);
  pinMode(P1_UP, INPUT);
  pinMode(P1_DOWN, INPUT);
  pinMode(P2_UP, INPUT);
  pinMode(P2_DOWN, INPUT);
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

//BATS AUTOMATICOS/
/*
  while(pos_y1 != BOTTOM || pos_y1 != TOP) 
  {
    delay(100);
  pos_y1 = pos_y1 << 1;
  lc.setColumn(0,0,pos_y1);
    if (pos_y1 = TOP)
    {
      delay(100);
      pos_y1 = pos_y1 >> 1;
       lc.setColumn(0,0,pos_y1);
    }

    if (pos_y1 = BOTTOM)
    {
      delay(100);
      pos_y1 = pos_y1 << 1;
       lc.setColumn(0,0,pos_y1);
    }
  }
*/

  /*
  int button1 =  digitalRead(P1_UP);
  int button2 =  digitalRead(P1_DOWN);

  if (!button1) {
    pos_y1 = pos_y1 >> 1;
    pos_y2 = pos_y2 << 1;
  } 

  if (!button2) {
    pos_y1 = pos_y1 << 1;
    pos_y2 = pos_y2 >> 1;
  }
  */

  move_player_one();
  move_player_two();

  lc.setColumn(0, 0, pos_y1);
  lc.setColumn(0, 7, pos_y2);

  delay(100);
/*
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
*/

// PELOTA/
 /*
  while(i <= 7 && i >= 0)
    {
      
    
    delay(250);
    bally = bally >> 1;
      
lc.clearDisplay(0);
  

  
  if(bally == B00000001)
  {
      bally = bally << 1;
      lc.setColumn(0,i,bally);
  }

 
    lc.setColumn(0,i,bally);
    i++;
  
  }
  */
  
}



void move_player_one(void)
{
  int _up   = 1 - digitalRead(P1_UP);
  int _down = 1 - digitalRead(P1_DOWN);

  if (_up) {
    pos_y1 = pos_y1 >> 1;
  }
  if (_down) {
    pos_y1 = pos_y1 << 1;
  }
  
}


void move_player_two(void)
{
  int _up   = 1 - digitalRead(P2_UP);
  int _down = 1 - digitalRead(P2_DOWN);

  if (_up) {
    pos_y2 = pos_y2 >> 1;
  }
  if (_down) {
    pos_y2 = pos_y2 << 1;
  }
  
}
