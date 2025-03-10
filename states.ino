#define PIN_MTR1_DIR_FWD  5
#define PIN_MTR1_DIR_REV  6
#define PIN_MTR2_DIR_FWD  7
#define PIN_MTR2_DIR_REV  8
#define PIN_MTR1_PWM      9
#define PIN_MTR2_PWM     10

void setup() {
  pinMode(PIN_MTR1_DIR_FWD, OUTPUT);
  pinMode(PIN_MTR1_DIR_REV, OUTPUT);
  pinMode(PIN_MTR2_DIR_FWD, OUTPUT);
  pinMode(PIN_MTR2_DIR_REV, OUTPUT);
  pinMode(PIN_MTR1_PWM, OUTPUT);
  pinMode(PIN_MTR2_PWM, OUTPUT);

  // Move motors forward
  digitalWrite(PIN_MTR1_DIR_FWD, HIGH);
  digitalWrite(PIN_MTR1_DIR_REV, LOW);
  digitalWrite(PIN_MTR2_DIR_FWD, HIGH);
  digitalWrite(PIN_MTR2_DIR_REV, LOW);

  analogWrite(PIN_MTR1_PWM, 255);
  analogWrite(PIN_MTR2_PWM, 255);
}

void loop() {
  // Nothing needed in loop, motors will run indefinitely
}
