
#define LED1        3        // P1_1
#define LED2        4        // P2_2
#define P1_UP       15        // P1_6  pin to signal up
#define P1_DOWN     14        // P1_7  pin to signal down.


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);  // msp430g2231 must use 4800
  
  // Configure the pins :
  pinMode(LED1, OUTPUT);
  pinMode(LED2,OUTPUT);
  pinMode(P1_UP, INPUT);
  pinMode(P1_DOWN, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly: 
  int button1 =  digitalRead(P1_UP);
  int button2 =  digitalRead(P1_DOWN);

  Serial.print("UP : \t");
  Serial.print(button1);
  Serial.print("\t DOWN : \t");
  Serial.print(button2);

  delay(200);

  if (button1) { digitalWrite(LED1, HIGH); }
  else { digitalWrite(LED1, LOW); }
  
  if (button2) { digitalWrite(LED2, HIGH); }
  else { digitalWrite(LED2, LOW); }
   
}
