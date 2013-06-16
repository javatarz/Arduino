const int led1Pin = 13;
const int led2Pin = 12;

const int led1MaxTime = 1000;
const int led2MaxTime = 1500;

long led1Timer = led1MaxTime;
long led2Timer = led2MaxTime;
long lastLoopTime = 0;
int led1State = HIGH;
int led2State = HIGH;

void setup() {
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);

  // set initial LED state
  digitalWrite(led1Pin, led1State);
  digitalWrite(led2Pin, led2State);

  lastLoopTime = millis();
}

void loop() {
  long currentLoopTime = millis();
  long diff = currentLoopTime - lastLoopTime;
  
  led1Timer -= diff;
  led2Timer -= diff;
  
  if (led1Timer < 0) {
    led1Timer = led1MaxTime;
    led1State = !led1State;
    
    digitalWrite(led1Pin, led1State);
  }
  
  if (led2Timer < 0) {
    led2Timer = led2MaxTime;
    led2State = !led2State;
    
    digitalWrite(led2Pin, led2State);
  }
  
  lastLoopTime = currentLoopTime;
}
  
