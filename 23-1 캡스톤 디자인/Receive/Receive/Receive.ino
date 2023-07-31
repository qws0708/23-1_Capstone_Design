// 모터1
int IN1 = 2;
int IN2 = 3;
int IN3 = 4;
int IN4 = 5;

// 모터2
int IN5 = 8;
int IN6 = 9;
int IN7 = 10;
int IN8 = 11;

// 그리퍼 모터
int IN9 = 12;
int IN10 = 13;


void setup() {

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);
  pinMode(IN9, OUTPUT);
  pinMode(IN10, OUTPUT);

  Serial.begin(9600);
}


void M1_Forward_Turn1() {  // X축 시계방향 1.8도 한바퀴
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
  delay(3);
}

void M1_Forward_Turn2() {  // X축 시계방향 1.8도 한바퀴
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
  delay(3);
}

void M1_Forward_Turn3() {  // X축 시계방향 1.8도 한바퀴
  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
  delay(3);
}

void M1_Forward_Turn4() {  // X축 시계방향 1.8도 한바퀴
  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
  delay(3);
}

void M1_Backward_Turn1() {  // X축 반시계방향 1.8도 한바퀴
  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
  delay(3);
}

void M1_Backward_Turn2() {  // X축 반시계방향 1.8도 한바퀴
  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
  delay(3);
}

void M1_Backward_Turn3() {  // X축 반시계방향 1.8도 한바퀴
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
  delay(3);
}

void M1_Backward_Turn4() {  // X축 반시계방향 1.8도 한바퀴
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
  delay(3);
}



void M2_Forward_Turn1() {  // Y축 시계방향 1.8도 한바퀴
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(3);
}

void M2_Forward_Turn2() {  // Y축 시계방향 1.8도 한바퀴
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(3);
}

void M2_Forward_Turn3() {  // Y축 시계방향 1.8도 한바퀴
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(3);
}

void M2_Forward_Turn4() {  // Y축 시계방향 1.8도 한바퀴
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(3);
}

void M2_Backward_Turn1() {  // Y축 반시계방향 1.8도 한바퀴
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(3);
}

void M2_Backward_Turn2() {  // Y축 반시계방향 1.8도 한바퀴
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(3);
}

void M2_Backward_Turn3() {  // Y축 반시계방향 1.8도 한바퀴
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(3);
}

void M2_Backward_Turn4() {  // Y축 반시계방향 1.8도 한바퀴
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(3);
}

void Pick_up_a_bowl() {  // 그릇 잡기
  delay(500);
  digitalWrite(IN9, 255);
  digitalWrite(IN10, 0);
  delay(500);
  digitalWrite(IN9, 0);
  digitalWrite(IN10, 0);
}

void Put_a_bowl() {  // 그릇 놓기
  delay(500);
  digitalWrite(IN9, 0);
  digitalWrite(IN10, 255);
  delay(500);
  digitalWrite(IN9, 0);
  digitalWrite(IN10, 0);
}

void Stop_Griiper() {  // 그리퍼 정지
  delay(500);
  digitalWrite(IN9, 0);
  digitalWrite(IN10, 0);
}

void loop() {

  while (Serial.available()) {
    char data = Serial.read();
    if (data == 'A') {
      Serial.println("Pick_up_a_bowl Start");
      int X = 0;

      if (X == 0) {

        delay(2000);

        for (int i = 0; i < 200; i++) {  // 그리퍼 내리기
          M1_Backward_Turn1();
          M2_Forward_Turn1();
          M1_Backward_Turn2();
          M2_Forward_Turn2();
          M1_Backward_Turn3();
          M2_Forward_Turn3();
          M1_Backward_Turn4();
          M2_Forward_Turn4();
        }

        delay(2000);

        // 그릇 잡기
        for (int i = 0; i < 3; i++) {
          Pick_up_a_bowl();
        }

        delay(2000);

        for (int i = 0; i < 200; i++) {  // 그리퍼 올리기
          M1_Forward_Turn1();
          M2_Backward_Turn1();
          M1_Forward_Turn2();
          M2_Backward_Turn2();
          M1_Forward_Turn3();
          M2_Backward_Turn3();
          M1_Forward_Turn4();
          M2_Backward_Turn4();
        }

        delay(2000);

        Serial.println("Pick_up_a_bowl Finish");
      }
    }

    if (data == 'B') {
      Serial.println("Put_a_bowl Start");
      int X = 1;

      if (X == 1) {

        delay(2000);

        for (int i = 0; i < 200; i++) {  // 그리퍼 내리기
          M1_Backward_Turn1();
          M2_Forward_Turn1();
          M1_Backward_Turn2();
          M2_Forward_Turn2();
          M1_Backward_Turn3();
          M2_Forward_Turn3();
          M1_Backward_Turn4();
          M2_Forward_Turn4();
        }

        delay(2000);

        // 그릇 놓기
        for (int i = 0; i < 1; i++) {
          Put_a_bowl();
        }

        delay(2000);

        for (int i = 0; i < 200; i++) {  // 그리퍼 올리기
          M1_Forward_Turn1();
          M2_Backward_Turn1();
          M1_Forward_Turn2();
          M2_Backward_Turn2();
          M1_Forward_Turn3();
          M2_Backward_Turn3();
          M1_Forward_Turn4();
          M2_Backward_Turn4();
        }

        delay(2000);

        Serial.println("Put_a_bowl Finish");
      }
    }
  }
}