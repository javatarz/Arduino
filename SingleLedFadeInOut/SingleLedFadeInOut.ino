const int ledPin = 12;
const int waitTime = 10;
const int stateChangedWaitTime = 500;

long lastTimer;
int lastVal;
int lastState;

void setup() {
  pinMode(ledPin, OUTPUT);
  
  lastTimer = millis();
  lastState = 1;
  lastVal = 0;
}

void loop() {
  long currentTimer = millis();
  const long diff = currentTimer - lastTimer;
  
  if (!((lastVal == 0 || lastVal == 255) && diff <= stateChangedWaitTime) && diff >= waitTime) {
    lastVal += lastState;
    
    if (lastVal == 0 || lastVal == 255) {
      lastState = lastState == 1 ? -1 : 1;
    }
    
    analogWrite(ledPin, lastVal);
    lastTimer = currentTimer;
  }
}
