#define PIN_PB_START  4
#define ENA 10  
#define ENB 5   
#define IN1 6  
#define IN2 7   
#define IN3 8  
#define IN4 9  

void setup() {
  pinMode(PIN_PB_START, INPUT_PULLUP);
  pinMode(ENA, OUTPUT);
  pinMode(ENB, OUTPUT);
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  if (digitalRead(PIN_PB_START) == LOW) {  
    
    //add commands here

    while (digitalRead(PIN_PB_START) == LOW) {
      delay(10);
    }
  }
}

void forward() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 200);
  analogWrite(ENB, 255);

  delay(850); 

  analogWrite(ENA, 0);  
  delay(300);           
  analogWrite(ENB, 0);  

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void forwardHalf() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 200);
  analogWrite(ENB, 255);

  delay(400); 

  analogWrite(ENA, 0);  
  delay(150);           
  analogWrite(ENB, 0);  

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void backward() {
  digitalWrite(IN1, LOW);   
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);  
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 200);    
  analogWrite(ENB, 255);    

  delay(850);  

  analogWrite(ENA, 0);  
  delay(300);           
  analogWrite(ENB, 0);  

  digitalWrite(IN1, LOW);  
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void backwardHalf() {
  digitalWrite(IN1, LOW);   
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);  
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 200);    
  analogWrite(ENB, 255);    

  delay(400);  

  analogWrite(ENA, 0);  
  delay(150);           
  analogWrite(ENB, 0);  

  digitalWrite(IN1, LOW);  
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void turnLeft() {
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);

  delay(335); 

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}

void turnRight() {
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  analogWrite(ENA, 255);
  analogWrite(ENB, 255);

  delay(350); 

  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, LOW);
}
