#define sensorPin 12 // which pin has what
#define LED 13

unsigned long lastMillis; // how much time has passed since LED has turned on
unsigned long Time = 2000; // the time the LED will be on after sound detection
int sensorVal; // val from sound sensor (0 or 1)

void setup() {
  // put your setup code here, to run once:
  pinMode(sensorPin, INPUT); // input
  pinMode(LED, OUTPUT); // output
}

void loop() {
  // put your main code here, to run repeatedly:
  sensorVal = digitalRead(sensorPin);

  if (sensorVal) { // if sensorval is true (1); this happens if sensor sent a val
    digitalWrite(LED, HIGH);
    lastMillis = millis(); // lastMillis = time when we turn on the LED
  }

  if (millis() - lastMillis >= 2000) {  // turns off the light
     digitalWrite(LED, LOW);
     lastMillis = millis();
  }
}
