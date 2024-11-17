#define PIN_SONIC_TRIGGER 12
#define PIN_SONIC_PULSE   11

void setup() {
  Serial.begin(9600);

  pinMode(PIN_SONIC_TRIGGER, OUTPUT);
  pinMode(PIN_SONIC_PULSE, INPUT);

  digitalWrite(PIN_SONIC_TRIGGER, LOW);
}

void loop() {
  long duration, distance;

  digitalWrite(PIN_SONIC_TRIGGER, HIGH);
  delayMicroseconds(10);
  digitalWrite(PIN_SONIC_TRIGGER, LOW);

  duration = pulseIn(PIN_SONIC_PULSE, HIGH);

  distance = duration * 0.034 / 2;

  if (distance > 0 && distance <= 5) {
    Serial.println("Object detected within 5 cm!");
  } else {
    Serial.println("No object detected within 5 cm.");
  }

  delay(100);
}
