const int stepPin = 9;
const int dirPin  = 11;
const int enPin   = 10;

void setup() {
  pinMode(stepPin, OUTPUT);
  pinMode(dirPin, OUTPUT);
  pinMode(enPin, OUTPUT);

  digitalWrite(enPin, LOW); // enable driver
  Serial.begin(9600);
  Serial.println("Stepper ready. Commands: +(CW), -(CCW), s(stop), e(enable)");
}

void loop() {
  if (Serial.available()){
    char cmd = Serial.read();

    switch(cmd){
      case '+':
        digitalWrite(dirPin, HIGH); // clockwise
        Serial.println("Clockwise");
        break;

      case '-':
        digitalWrite(dirPin, LOW);  // counter-clockwise
        Serial.println("Counter-Clockwise");
        break;

      case 's':
        digitalWrite(enPin, HIGH);  // disable
        Serial.println("Stopped");
        break;

      case 'e':
        digitalWrite(enPin, LOW);   // enable
        Serial.println("Enabled");
        break;
    }
  }

  // step pulse
  digitalWrite(stepPin, HIGH);
  delayMicroseconds(500); 
  digitalWrite(stepPin, LOW);
  delayMicroseconds(500);
}
