#define PIN_PB_START           0
#define PIN_MTR1_ENCB          1
#define PIN_MTR1_ENCA          2
#define PIN_MTR2_ENCB          3
#define PIN_MTR2_ENCA          4
#define PIN_MTR1_DIR_FWD       5
#define PIN_MTR1_DIR_REV       6
#define PIN_MTR2_DIR_FWD       7
#define PIN_MTR2_DIR_REV       8
#define PIN_MTR1_PWM           9
#define PIN_MTR2_PWM          10
#define PIN_SONIC_PULSE       11
#define PIN_SONIC_TRIGGER     12

// This is def wrong idk what im doing
#define ENCODER_COUNTS_PER_REV  540     
#define MM_PER_REV              235.62     
#define ENCODER_COUNTS_90_DEG   135   

void setup() {
  pinMode(PIN_PB_START, INPUT);

  pinMode(PIN_MTR1_DIR_FWD, OUTPUT);
  pinMode(PIN_MTR1_DIR_REV, OUTPUT);
  pinMode(PIN_MTR2_DIR_FWD, OUTPUT);
  pinMode(PIN_MTR2_DIR_REV, OUTPUT);
  pinMode(PIN_MTR1_PWM, OUTPUT);
  pinMode(PIN_MTR2_PWM, OUTPUT);

  pinMode(PIN_SONIC_TRIGGER, OUTPUT);
  pinMode(PIN_SONIC_PULSE, INPUT);

  Serial.begin(9600);
}

void loop() {
  if (digitalRead(PIN_PB_START) == LOW) {
    Serial.println("Start button pressed. Moving forward...");

    digitalWrite(PIN_MTR1_DIR_FWD, HIGH);
    digitalWrite(PIN_MTR1_DIR_REV, LOW);

    digitalWrite(PIN_MTR2_DIR_FWD, HIGH);
    digitalWrite(PIN_MTR2_DIR_REV, LOW);

    analogWrite(PIN_MTR1_PWM, 255);
    analogWrite(PIN_MTR2_PWM, 255);
  } else {
    Serial.println("Start button not pressed. Motors stopped.");

    digitalWrite(PIN_MTR1_DIR_FWD, LOW);
    digitalWrite(PIN_MTR1_DIR_REV, LOW);
    digitalWrite(PIN_MTR2_DIR_FWD, LOW);
    digitalWrite(PIN_MTR2_DIR_REV, LOW);

    analogWrite(PIN_MTR1_PWM, 0);
    analogWrite(PIN_MTR2_PWM, 0);
  }

  delay(50);
}
