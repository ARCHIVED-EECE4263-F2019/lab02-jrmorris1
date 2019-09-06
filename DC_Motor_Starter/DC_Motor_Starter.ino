int count = 0;              // variable used to track speed stage
int Speed = 0;              // Motor speed variable
int dir = 0;                // Clockwise/Counterclockwise direction tracker
byte Motor = D5;            // Initial Motor direction pin



void setup() {
  Serial.begin(115200);
  pinMode(D5, OUTPUT);       // Clockwise direction motor pin
  pinMode(D6, OUTPUT);       // Counterclockwise direction motor pin
  pinMode(D2, INPUT);        // Speed push button
  pinMode(D1, INPUT);        // Direction push button
   
}

void loop() {
  Serial.print(Speed);       // Print speed for debugging
  Serial.println(dir);       // Print direction for debugging
  
  // Set Speed to 0 and direction to clockwise when both buttons are
  // pressed
  if(digitalRead(D1) && digitalRead(D2)){
    Speed = 0;
    count = 0;
    dir = 0;
    Motor = D5;
    Serial.println("Reset"); // Reset confirmation
    delay(500);              // delay for switch debouncing because the provided library gave me issues
  }

  // Change direction from clockwise to counterclockwise or vice versa when button 1 is pressed
   if(digitalRead(D1) && !digitalRead(D2)){
    if(dir == 0){
      dir += 1;
      Motor = D6;
      delay(200);            // delay for switch debouncing
      }
    else if(dir == 1){
      dir = 0;
      Motor = D5;
      delay(200);            // delay for switch debouncing
    }
   }

  // Change speed from Off to Fast to Slow in that order 
  else if(digitalRead(D2) && !digitalRead(D1)){
    if(count == 0){
      count += 1;
      Speed = 1000;          // fast speed setting
      delay(200);            // delay for switch debouncing
    }
    else if(count == 1){
      count += 1;
      Speed = 500;           // slow speed setting
      delay(200);            // delay for switch debouncing 
    }
    else if(count == 2){
      count = 0;
      Speed = 0;             // Off speed setting
      delay(200);            // delay for switch debouncing
    }
  }
  

  analogWrite(Motor, Speed); // Turns motor in a desired direction and speed
}
