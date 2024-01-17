int RMP = 5;
int RMN = 4;
int LMP = 2;
int LMN = 3;

int LDR_R = 9;
int LDR_L = 8;
int LDR_C = 10;

String direction;

void setup() {
  pinMode(RMP, OUTPUT);
  pinMode(RMN, OUTPUT);
  pinMode(LMP, OUTPUT);
  pinMode(LMN, OUTPUT);

  Serial.begin(9600);
}

void loop() {

      if (Serial.available() > 0) {

      do {

      direction = Serial.readString();

      if (direction == "Forward") {
        Serial.println("F");
        forward();
      }

      else if (direction == "Back") {
        Serial.println("B");
        back();
      }
    
      else if (direction == "Right") {
        Serial.println("R");
        right();
      }

      else if (direction == "Left") {
        Serial.println("L");
        left();
      }

      else if (direction == "Stop") {
        Serial.println("S");
        stop();
      }

      } while (direction != "Disable");
      
    }

    else {
      int ldr_right = digitalRead(LDR_R);
      int ldrleft = digitalRead(LDR_L);
      int ldrcentral = digitalRead(LDR_C);

      if (ldr_right == 0 && ldrcentral == 0 && ldrleft == 0) {
          Serial.println("F");
          forward();
      }

      else if (ldr_right == 0 && ldrcentral == 0 && ldrleft == 1) {
          Serial.println("RF");
          right();
          stop();
          forward();
      }

      //intensity
      else if (ldr_right == 0 && ldrcentral == 1 && ldrleft == 0) {
        Serial.println("F");
        forward();
      }   

      else if (ldr_right == 0 && ldrcentral == 1 && ldrleft == 1) {
        Serial.println("R");
        right();
      }

      else if (ldr_right == 1 && ldrcentral == 0 && ldrleft == 0) {
        Serial.println("LF");
        left();
        stop();
        forward();
      }

      else if (ldr_right == 1 && ldrcentral == 0 && ldrleft == 1) {
        Serial.println("F");
        forward();
      }

      else if (ldr_right == 1 && ldrcentral == 1 && ldrleft == 0) {
        Serial.println("L");
        left();
      }

      else if (ldr_right == 1 && ldrcentral == 1 && ldrleft == 1) {
        Serial.println("S");
        stop();
      }
    }

    delay(500);

}

void forward() {
  digitalWrite(RMP, LOW);
  digitalWrite(RMN, HIGH);
  digitalWrite(LMP, LOW);
  digitalWrite(LMN, HIGH);
}

void back() {
  digitalWrite(RMP, HIGH);
  digitalWrite(RMN, LOW);
  digitalWrite(LMP, HIGH);
  digitalWrite(LMN, LOW);
}

void right() {
  digitalWrite(RMP, HIGH);
  digitalWrite(RMN, LOW);
  digitalWrite(LMP, LOW);
  digitalWrite(LMN, HIGH);

}

void left() {
  digitalWrite(RMP, LOW);
  digitalWrite(RMN, HIGH);
  digitalWrite(LMP, HIGH);
  digitalWrite(LMN, LOW);
}

void stop() {
  digitalWrite(RMP, LOW);
  digitalWrite(RMN, LOW);
  digitalWrite(LMP, LOW);
  digitalWrite(LMN, LOW);
}