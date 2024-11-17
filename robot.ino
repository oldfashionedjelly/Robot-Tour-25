// Define pins
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
  // Initialize the start button pin as an input
  pinMode(PIN_PB_START, INPUT);

  // Initialize motor control pins
  pinMode(PIN_MTR1_DIR_FWD, OUTPUT);
  pinMode(PIN_MTR1_DIR_REV, OUTPUT);
  pinMode(PIN_MTR2_DIR_FWD, OUTPUT);
  pinMode(PIN_MTR2_DIR_REV, OUTPUT);
  pinMode(PIN_MTR1_PWM, OUTPUT);
  pinMode(PIN_MTR2_PWM, OUTPUT);

  // Start serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Check if the start button is pressed
  if (digitalRead(PIN_PB_START) == HIGH) {
    // If the button is pressed, move both motors forward
    Serial.println("Start button pressed. Moving forward...");

    // Set motor 1 to move forward
    digitalWrite(PIN_MTR1_DIR_FWD, HIGH);
    digitalWrite(PIN_MTR1_DIR_REV, LOW);

    // Set motor 2 to move forward
    digitalWrite(PIN_MTR2_DIR_FWD, HIGH);
    digitalWrite(PIN_MTR2_DIR_REV, LOW);

    // Enable PWM for both motors to control speed (set to full speed here, 255)
    analogWrite(PIN_MTR1_PWM, 255); // Full speed for motor 1
    analogWrite(PIN_MTR2_PWM, 255); // Full speed for motor 2
  } else {
    // If the button is not pressed, stop the motors
    Serial.println("Start button not pressed. Motors stopped.");

    // Set motors to stop (no forward or reverse direction)
    digitalWrite(PIN_MTR1_DIR_FWD, LOW);
    digitalWrite(PIN_MTR1_DIR_REV, LOW);
    digitalWrite(PIN_MTR2_DIR_FWD, LOW);
    digitalWrite(PIN_MTR2_DIR_REV, LOW);

    // Stop PWM (set to 0 to stop motors)
    analogWrite(PIN_MTR1_PWM, 0);
    analogWrite(PIN_MTR2_PWM, 0);
  }

  // Small delay to avoid bouncing effects from the button
  delay(50);
}
