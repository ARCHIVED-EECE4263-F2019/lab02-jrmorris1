// This is a test to makw sure the NodeMCU can cause the DC motor
// to move, and that my circuit works
/*
 * Still needs:
 * Button press commands
 * Button debouncing
 * 
 */


void setup() {
  // put your setup code here, to run once:
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  clockwise(400);
  delay(1000);
  counterclockwise(400);
  delay(1000);
}

void clockwise(int Speed){
  analogWrite(D5, Speed); // sets speed of motor
  analogWrite(D6, 0);     // stops second motor pin
}

void counterclockwise(int Speed){
  analogWrite(D5, 0);     // stops first motor pin
  analogWrite(D6, Speed); // sets speed of motor
}
