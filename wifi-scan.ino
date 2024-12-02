#define timeSeconds 10

// Set GPIOs for LED and PIR Motion Sensor
Const int led = 26;
Const int motionSensor = 27;

// Timer: Auxiliary variables
Unsigned long now = millis();
Unsigned long lastTrigger = 0;
Boolean startTimer = false;
Boolean motion = false;

// Checks if motion was detected, sets LED HIGH and starts a timer
Void IRAM_ATTR detectsMovement() {
  digitalWrite(led, HIGH);
  startTimer = true;
  lastTrigger = millis();
}

Void setup() {
  // Serial port for debugging purposes
  Serial.begin(115200);
  
  // PIR Motion Sensor mode INPUT_PULLUP
  pinMode(motionSensor, INPUT_PULLUP);
  // Set motionSensor pin as interrupt, assign interrupt function and set RISING mode
  attachInterrupt(digitalPinToInterrupt(motionSensor), detectsMovement, RISING);

  // Set LED to LOW
  pinMode(led, OUTPUT);
  digitalWrite(led, LOW);
}

Void loop() {
  // Current time
  Now = millis();
  If((digitalRead(led) == HIGH) && (motion == false)) {
    Serial.println(“MOTION DETECTED!!!”);
    Motion = true;
  }
  // Turn off the LED after the number of seconds defined in the timeSeconds variable
  If(startTimer && (now – lastTrigger > (timeSeconds*1000))) {
    Serial.println(“Motion stopped…”);
    digitalWrite(led, LOW);
    startTimer = false;
    motion = false;
  }
}
