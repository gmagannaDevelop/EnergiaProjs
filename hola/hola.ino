


#include <LedControl.h>

/**
* Led Matrix test
*/

/////////////////////// STRUCTURES ///////////////////////////////////
struct POS {
  byte y;
  int  x;
};

struct BALL {
  /* vx should be {-1, 1} for both possible directions
     vy should be {0,  1} because it will be used as a boolean flag.
  */
  byte y;
  int x;
  int vx;
  int vy;  
};
////////////////////////////////////////////////////////////////////

///////////////////////// MACROS ///////////////////////////////////
#define DATA_PIN    12         //       data for AS1106
#define CLOCK_PIN   10         //       clock for AS1106
#define LOAD_PIN    11         //       load CS for AS1106

#define P1_UP       3          // P1_1  pin to signal up
#define P1_DOWN     4          // P1_2  pin to signal down.
#define P2_UP       5          // P1_3  pin to signal up
#define P2_DOWN     6          // P1_4  pin to signal down.

#define TOP         B00000111
#define BOTTOM      B11100000    
#define BTOP        B00000001
#define BBOTTOM     B10000000  

// This was defined for a 8x8 matrix
#define P_RIGHT     1       
#define P_LEFT      6
#define B_RIGHT     0
#define B_LEFT      7
////////////////////////////////////////////////////////////////////


///////////////////////// GLOBAL VARIABLES ///////////////////////////////
// Proto: LedControl(int dataPin, int clkPin, int csPin, int numDevices=1);
LedControl lc=LedControl(DATA_PIN, CLOCK_PIN, LOAD_PIN, 4);

byte move_player(byte pos, int UP, int DOWN);
struct BALL move_ball(struct BALL ball, struct POS p1, struct POS p2);

unsigned long delaytime=100;

struct POS p1, p2;
struct BALL ball;
////////////////////////////////////////////////////////////////////



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

  p1.y    = B00111000;
  p1.x    = 0;
  p2.y    = B00011100;
  p2.x    = 7;
  ball.y  = B00100000;
  ball.x  = 4;
  ball.vx = 1;
  ball.vy = 0;

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
  
  /*
  move_player_one();
  move_player_two();
  */

  p1.y = move_player(p1.y, P1_UP, P1_DOWN);
  p2.y = move_player(p2.y, P2_UP, P2_DOWN);
  ball = move_ball(ball, p1, p2);

  lc.setColumn(0, ball.x, ball.y);
  lc.setColumn(0, p1.x, p1.y);
  lc.setColumn(0, p2.x, p2.y);
  

  delay(100);


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


byte move_player(byte pos, int UP, int DOWN)
{
  int _up   = 1 - digitalRead(UP);
  int _down = 1 - digitalRead(DOWN);

  if (_up) {
    if (pos == TOP) {
      pos = BOTTOM;
    } 
    else {
      pos = pos >> 1;  
    }  
  }

  if (_down) {
    if (pos == BOTTOM) {
      pos = TOP;
    } 
    else {
      pos = pos << 1;  
    }
  }

  return pos;
}


struct BALL move_ball(struct BALL ball, struct POS p1, struct POS p2)
{
  // Check bouncing with a bat/player :
  if ((ball.x == 1)){
    if (ball.y | p1.y == p1.y){
      ball.vx *= -1;
    }
  }
  if ((ball.x == 6)){
    if (ball.y | p2.y == p2.y){
      ball.vx *= -1;
    }
  }

  // Check top-bottom boundaries :
  if ((ball.y == BTOP)){
    ball.vy = 1;
  }
  if ((ball.y == BBOTTOM)){
    ball.vy = 0;
  }

  if (ball.vy){
    ball.y = ball.y << 1;  
  }
  else {
    ball.y = ball.y >> 1;  
  } 

  ball.x += ball.vx;

  return ball;
}
