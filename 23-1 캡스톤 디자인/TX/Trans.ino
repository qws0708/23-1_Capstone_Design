int IN1 = 2;
int IN2 = 3;
int IN3 = 4;
int IN4 = 5;

int IN5 = 8;
int IN6 = 9;
int IN7 = 10;
int IN8 = 11;

void setup() {
  
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(IN5, OUTPUT);
  pinMode(IN6, OUTPUT);
  pinMode(IN7, OUTPUT);
  pinMode(IN8, OUTPUT);

  Serial.begin(9600);
  
}


void X_Forward_Turn1() {  // X축 시계방향 1.8도 한바퀴
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
  delay(3);
}

void X_Forward_Turn2() {  // X축 시계방향 1.8도 한바퀴
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
  delay(3);
}

void X_Forward_Turn3() {  // X축 시계방향 1.8도 한바퀴
  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
  delay(3);
}

void X_Forward_Turn4() {  // X축 시계방향 1.8도 한바퀴
  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
  delay(3);
}

void X_Backward_Turn1() {  // X축 반시계방향 1.8도 한바퀴
  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
  delay(3);
}

void X_Backward_Turn2() {  // X축 반시계방향 1.8도 한바퀴
  digitalWrite(IN5, HIGH);
  digitalWrite(IN6, LOW);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
  delay(3);
}

void X_Backward_Turn3() {  // X축 반시계방향 1.8도 한바퀴
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  digitalWrite(IN7, LOW);
  digitalWrite(IN8, HIGH);
  delay(3);
}

void X_Backward_Turn4() {  // X축 반시계방향 1.8도 한바퀴
  digitalWrite(IN5, LOW);
  digitalWrite(IN6, HIGH);
  digitalWrite(IN7, HIGH);
  digitalWrite(IN8, LOW);
  delay(3);
}

void Y_Forward_Turn1() {  // Y축 시계방향 1.8도 한바퀴
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(3);
}

void Y_Forward_Turn2() {  // Y축 시계방향 1.8도 한바퀴
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(3);
}

void Y_Forward_Turn3() {  // Y축 시계방향 1.8도 한바퀴
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(3);
}

void Y_Forward_Turn4() {  // Y축 시계방향 1.8도 한바퀴
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(3);
}

void Y_Backward_Turn1() {  // Y축 반시계방향 1.8도 한바퀴
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(3);
}

void Y_Backward_Turn2() {  // Y축 반시계방향 1.8도 한바퀴
  digitalWrite(IN1, HIGH);
  digitalWrite(IN2, LOW);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(3);
}

void Y_Backward_Turn3() {  // Y축 반시계방향 1.8도 한바퀴
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, LOW);
  digitalWrite(IN4, HIGH);
  delay(3);
}

void Y_Backward_Turn4() {  // Y축 반시계방향 1.8도 한바퀴
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, HIGH);
  digitalWrite(IN3, HIGH);
  digitalWrite(IN4, LOW);
  delay(3);
}
//서빙 완료

bool Serving_x = false;
bool Serving_y = false;
bool Table_Serving_x = false;
bool Table_Serving_y = false;

//테이블 1번 영역

int table_1[4][2] ={{70, 19}, {85, 19}, {70, 38}, {85, 38}};
//테이블 2번 영역

int table_2[4][2] ={{70, 62}, {85, 62}, {70, 81}, {85, 81}};
// 고정 값 ( 단위 : cm)

int start_X = 35;
int start_Y = 46;

int X_Rotation = 0;
int Y_Rotation = 0;

// X,Y 나누기 4 몫(share),나머지(remainder) => for문에 필요

int X_share = 0;
int X_remainder = 0;

int Y_share = 0;
int Y_remainder = 0;

int Table_X_Rotation = 0;
int Table_X_share = 0;
int Table_X_remainder = 0;

int Table_Y_Rotation = 0;
int Table_Y_share = 0;
int Table_Y_remainder = 0;

int Reset_X_Rotation = 0;
int Reset_Y_Rotation = 0;
int Reset_X_share = 0;
int Reset_X_remainder = 0;
int Reset_Y_share = 0;
int Reset_Y_remainder = 0;

void loop() {
  // 회전 수 입력 1바퀴 = 200 = 4cm , 1바퀴 = 1 = 0.02cm

  

  while (Serial.available() == 0) {}  // Wait until data is available
  int X = Serial.parseInt();          // Read the input as an integer                  // Print the value of x
  
  // Clear the input buffer
  


  while (Serial.available() == 0) {}  // Wait until data is available
  int Y = Serial.parseInt();
            // Read the input as an integer
                                      // Print the value of y
  
  // Clear the input buffer
  while (Serial.available() == 0) {}  // Wait until data is available
  int Table_num = Serial.parseInt();
  
  

  while (Serial.available() == 0) {}  // Wait until data is available
  int count = Serial.parseInt();
  
  //int X = 60;
  //int Y = 60;
  //int Table_num = 1;
  //int count = 0;
  
  

  //while (Serial.available() == 0) {}  // Wait until data is available
  //int Control_ver = Serial.parseInt();

  // 회전 수 입력 끝

  int X_distance = start_X - X;  // X축 좌표 차이(거리)
  int Y_distance = start_Y - Y;  // Y축 좌표 차이(거리)
  int to_table_1_1_x = X - table_1[count][0];
  int to_table_1_1_y = Y - table_1[count][1];
  

  int to_table_2_1_x = X - table_2[count][0];
  int to_table_2_1_y = Y - table_2[count][1];

  int to_reset_1_x = table_1[count][0] - start_X;
  int to_reset_1_y = table_1[count][1] - start_Y;

  int to_reset_2_x = table_2[count][0] - start_X;
  int to_reset_2_y = table_2[count][1] - start_Y;


// @@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@서빙할 음식 위치로 이동@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
  if (X_distance < 0) {                   // X1 - X2 < 0 : 시계 방향 회전 필요
    X_Rotation = abs(X_distance) / 0.02;  // X축 이동 시 필요 회전 수
    Serial.println(X_Rotation);

    X_share = X_Rotation / 4;
    X_remainder = X_Rotation % 4;

    for (int i = 0; i < X_share; i++) {
      X_Forward_Turn1();
      X_Forward_Turn2();
      X_Forward_Turn3();
      X_Forward_Turn4();
    }

    if (X_remainder == 3) {
      X_Forward_Turn1();
      X_Forward_Turn2();
      X_Forward_Turn3();
    }

    if (X_remainder == 2) {
      X_Forward_Turn1();
      X_Forward_Turn2();
    }

    if (X_remainder == 1) {
      X_Forward_Turn1();
    }

    Serving_x = true;
  }

  if (X_distance > 0) {              // X1 - X2 > 0 : 반시계 방향 회전 필요
    X_Rotation = X_distance / 0.02;  // X축 이동 시 필요 회전 수
    Serial.println(X_Rotation);

    X_share = X_Rotation / 4;
    X_remainder = X_Rotation % 4;

    for (int i = 0; i < X_share; i++) {
      X_Backward_Turn1();
      X_Backward_Turn2();
      X_Backward_Turn3();
      X_Backward_Turn4();
    }

    if (X_remainder == 3) {
      X_Backward_Turn1();
      X_Backward_Turn2();
      X_Backward_Turn3();
    }

    if (X_remainder == 2) {
      X_Backward_Turn1();
      X_Backward_Turn2();
    }

    if (X_remainder == 1) {
      X_Backward_Turn1();
    }
    Serving_x = true;
  }

  if (X_distance == 0) {  // X축 이동 없음
    Serial.println("X축 이동 없음");
    Serving_x = true;
  }

  delay(1000);

  if (Y_distance > 0) {              // Y1 - Y2 > 0 :시계 방향 회전 필요
    Y_Rotation = Y_distance / 0.02;  // Y축 이동 시 필요 회전 수
    Serial.println(Y_Rotation);

    Y_share = Y_Rotation / 4;
    Y_remainder = Y_Rotation % 4;

    for (int i = 0; i < Y_share; i++) {
      Y_Forward_Turn1();
      Y_Forward_Turn2();
      Y_Forward_Turn3();
      Y_Forward_Turn4();
    }

    if (Y_remainder == 3) {
      Y_Forward_Turn1();
      Y_Forward_Turn2();
      Y_Forward_Turn3();
    }

    if (Y_remainder == 2) {
      Y_Forward_Turn1();
      Y_Forward_Turn2();
    }

    if (Y_remainder == 1) {
      Y_Forward_Turn1();
    }
    Serving_y = true;
  }


  if (Y_distance < 0) {                   // Y1 - Y2 < 0 : 반시계 방향 회전 필요
    Y_Rotation = abs(Y_distance) / 0.02;  // X축 이동 시 필요 회전 수
    Serial.println(Y_Rotation);

    Y_share = Y_Rotation / 4;
    Y_remainder = Y_Rotation % 4;

    for (int i = 0; i < Y_share; i++) {
      Y_Backward_Turn1();
      Y_Backward_Turn2();
      Y_Backward_Turn3();
      Y_Backward_Turn4();
    }

    if (Y_remainder == 3) {
      Y_Backward_Turn1();
      Y_Backward_Turn2();
      Y_Backward_Turn3();
    }

    if (Y_remainder == 2) {
      Y_Backward_Turn1();
      Y_Backward_Turn2();
    }

    if (Y_remainder == 1) {
      Y_Backward_Turn1();
    }
    Serving_y = true;
  }

  if (Y_distance == 0) {  //Y축 이동 없음
    Serial.println("Y축 이동 없음");
    Serving_y = true;
  }
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@서빙할 음식 좌표로 이동 완료@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

// ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~그리퍼 통신 코드(음식 들어올리기 = A)~~~~~~~~~~~
//~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  Serial.println("A");

  delay(20000);//음식 집을 시간  


// ####################################################주문한 테이블로 이동#####################################################################################################
  if (Serving_x == true && Serving_y == true) {
    if(Table_num == 1){
      if (to_table_1_1_x < 0) {                         // X1 - X2 < 0 : 시계 방향 회전 필요
        Table_X_Rotation = abs(to_table_1_1_x) / 0.02;  // X축 이동 시 필요 회전 수
        Serial.println(Table_X_Rotation);

        Table_X_share = Table_X_Rotation / 4;
        Table_X_remainder = Table_X_Rotation % 4;

        for (int i = 0; i < Table_X_share; i++) {
          X_Forward_Turn1();
          X_Forward_Turn2();
          X_Forward_Turn3();
          X_Forward_Turn4();
        }

        if (Table_X_remainder == 3) {
          X_Forward_Turn1();
          X_Forward_Turn2();
          X_Forward_Turn3();
        }

        if (Table_X_remainder == 2) {
          X_Forward_Turn1();
          X_Forward_Turn2();
        }

        if (Table_X_remainder == 1) {
          X_Forward_Turn1();
        }

        Table_Serving_x = true;
      }

      if (to_table_1_1_x > 0) {                    // X1 - X2 > 0 : 반시계 방향 회전 필요
        Table_X_Rotation = to_table_1_1_x / 0.02;  // X축 이동 시 필요 회전 수
        Serial.println(Table_X_Rotation);

        Table_X_share = Table_X_Rotation / 4;
        Table_X_remainder = Table_X_Rotation % 4;

        for (int i = 0; i < Table_X_share; i++) {
          X_Backward_Turn1();
          X_Backward_Turn2();
          X_Backward_Turn3();
          X_Backward_Turn4();
        }

        if (Table_X_remainder == 3) {
          X_Backward_Turn1();
          X_Backward_Turn2();
          X_Backward_Turn3();
        }

        if (Table_X_remainder == 2) {
          X_Backward_Turn1();
          X_Backward_Turn2();
        }

        if (Table_X_remainder == 1) {
          X_Backward_Turn1();
        }
        Table_Serving_x = true;
      }

      if (to_table_1_1_x == 0) {  // X축 이동 없음
        Serial.println("X축 이동 없음");
        Table_Serving_x = true;
      }

      delay(3000);
    
      if (to_table_1_1_y > 0) {                    // Y1 - Y2 > 0 :시계 방향 회전 필요
        Table_Y_Rotation = to_table_1_1_y / 0.02;  // Y축 이동 시 필요 회전 수
        Serial.println(Table_Y_Rotation);

        Table_Y_share = Table_Y_Rotation / 4;
        Table_Y_remainder = Table_Y_Rotation % 4;

        for (int i = 0; i < Table_Y_share; i++) {
          Y_Forward_Turn1();
          Y_Forward_Turn2();
          Y_Forward_Turn3();
          Y_Forward_Turn4();
        }

        if (Table_Y_remainder == 3) {
          Y_Forward_Turn1();
          Y_Forward_Turn2();
          Y_Forward_Turn3();
        }

        if (Table_Y_remainder == 2) {
          Y_Forward_Turn1();
          Y_Forward_Turn2();
        }

        if (Table_Y_remainder == 1) {
          Y_Forward_Turn1();
        }
        Table_Serving_y = true;
      }


      if (to_table_1_1_y < 0) {                         // Y1 - Y2 < 0 : 반시계 방향 회전 필요
        Table_Y_Rotation = abs(to_table_1_1_y) / 0.02;  // X축 이동 시 필요 회전 수
        Serial.println(Table_Y_Rotation);

        Table_Y_share = Table_Y_Rotation / 4;
        Table_Y_remainder = Table_Y_Rotation % 4;

        for (int i = 0; i < Table_Y_share; i++) {
          Y_Backward_Turn1();
          Y_Backward_Turn2();
          Y_Backward_Turn3();
          Y_Backward_Turn4();
        }

        if (Table_Y_remainder == 3) {
          Y_Backward_Turn1();
          Y_Backward_Turn2();
          Y_Backward_Turn3();
        }

        if (Table_Y_remainder == 2) {
          Y_Backward_Turn1();
          Y_Backward_Turn2();
        }

        if (Table_Y_remainder == 1) {
          Y_Backward_Turn1();
        }
        Table_Serving_y = true;
      }

      if (to_table_1_1_y == 0) {  //Y축 이동 없음
        Serial.println("Y축 이동 없음");
        Table_Serving_y = true;
      }
    }
    delay(5000);
    if(Table_num == 2){
      if (to_table_2_1_x < 0) {                         // X1 - X2 < 0 : 시계 방향 회전 필요
        Table_X_Rotation = abs(to_table_2_1_x) / 0.02;  // X축 이동 시 필요 회전 수
        Serial.println(Table_X_Rotation);

        Table_X_share = Table_X_Rotation / 4;
        Table_X_remainder = Table_X_Rotation % 4;

        for (int i = 0; i < Table_X_share; i++) {
          X_Forward_Turn1();
          X_Forward_Turn2();
          X_Forward_Turn3();
          X_Forward_Turn4();
        }

        if (Table_X_remainder == 3) {
          X_Forward_Turn1();
          X_Forward_Turn2();
          X_Forward_Turn3();
        }

        if (Table_X_remainder == 2) {
          X_Forward_Turn1();
          X_Forward_Turn2();
        }

        if (Table_X_remainder == 1) {
          X_Forward_Turn1();
        }

        Table_Serving_x = true;
      }

      if (to_table_2_1_x > 0) {                    // X1 - X2 > 0 : 반시계 방향 회전 필요
        Table_X_Rotation = to_table_2_1_x / 0.02;  // X축 이동 시 필요 회전 수
        Serial.println(Table_X_Rotation);

        Table_X_share = Table_X_Rotation / 4;
        Table_X_remainder = Table_X_Rotation % 4;

        for (int i = 0; i < Table_X_share; i++) {
          X_Backward_Turn1();
          X_Backward_Turn2();
          X_Backward_Turn3();
          X_Backward_Turn4();
        }

        if (Table_X_remainder == 3) {
          X_Backward_Turn1();
          X_Backward_Turn2();
          X_Backward_Turn3();
        }

        if (Table_X_remainder == 2) {
          X_Backward_Turn1();
          X_Backward_Turn2();
        }

        if (Table_X_remainder == 1) {
          X_Backward_Turn1();
        }
        Table_Serving_x = true;
      }

      if (to_table_2_1_x == 0) {  // X축 이동 없음
        Serial.println("X축 이동 없음");
        Table_Serving_x = true;
      }

      delay(3000);
    
      if (to_table_2_1_y > 0) {                    // Y1 - Y2 > 0 :시계 방향 회전 필요
        Table_Y_Rotation = to_table_2_1_y / 0.02;  // Y축 이동 시 필요 회전 수
        Serial.println(Table_Y_Rotation);

        Table_Y_share = Table_Y_Rotation / 4;
        Table_Y_remainder = Table_Y_Rotation % 4;

        for (int i = 0; i < Table_Y_share; i++) {
          Y_Forward_Turn1();
          Y_Forward_Turn2();
          Y_Forward_Turn3();
          Y_Forward_Turn4();
        }

        if (Table_Y_remainder == 3) {
          Y_Forward_Turn1();
          Y_Forward_Turn2();
          Y_Forward_Turn3();
        }

        if (Table_Y_remainder == 2) {
          Y_Forward_Turn1();
          Y_Forward_Turn2();
        }

        if (Table_Y_remainder == 1) {
          Y_Forward_Turn1();
        }
        Table_Serving_y = true;
      }


      if (to_table_2_1_y < 0) {                         // Y1 - Y2 < 0 : 반시계 방향 회전 필요
        Table_Y_Rotation = abs(to_table_2_1_y) / 0.02;  // X축 이동 시 필요 회전 수
        Serial.println(Table_Y_Rotation);

        Table_Y_share = Table_Y_Rotation / 4;
        Table_Y_remainder = Table_Y_Rotation % 4;

        for (int i = 0; i < Table_Y_share; i++) {
          Y_Backward_Turn1();
          Y_Backward_Turn2();
          Y_Backward_Turn3();
          Y_Backward_Turn4();
        }

        if (Table_Y_remainder == 3) {
          Y_Backward_Turn1();
          Y_Backward_Turn2();
          Y_Backward_Turn3();
        }

        if (Table_Y_remainder == 2) {
          Y_Backward_Turn1();
          Y_Backward_Turn2();
        }

        if (Table_Y_remainder == 1) {
          Y_Backward_Turn1();
        }
        Table_Serving_y = true;
      }

      if (to_table_2_1_y == 0) {  //Y축 이동 없음
        Serial.println("Y축 이동 없음");
        Table_Serving_y = true;
      }
    }
  }
  // ###############################################주문한 테이블로 이동완료############################################################################################


  // ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
  //~~~~~~~~~~~~~~~~~~~~그리퍼 통신 코드(내려둘때 = B )~~~~~~~~~~~
  //~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

  Serial.println("B");


  delay(20000);//음식 내려두기
  



  //++++++++++++++++++++++++++++++++++++++++++++++++++++++초기 위치로 이동+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
  if (Table_Serving_x == true && Table_Serving_y == true) {
    if(Table_num == 1){
      if (to_reset_1_x < 0) {                         // X1 - X2 < 0 : 시계 방향 회전 필요
        Reset_X_Rotation = abs(to_reset_1_x) / 0.02;  // X축 이동 시 필요 회전 수
        Serial.println(Reset_X_Rotation);

        Reset_X_share = Reset_X_Rotation / 4;
        Reset_X_remainder = Reset_X_Rotation % 4;

        for (int i = 0; i < Reset_X_share; i++) {
          X_Forward_Turn1();
          X_Forward_Turn2();
          X_Forward_Turn3();
          X_Forward_Turn4();
        }

        if (Reset_X_remainder == 3) {
          X_Forward_Turn1();
          X_Forward_Turn2();
          X_Forward_Turn3();
        }

        if (Reset_X_remainder == 2) {
          X_Forward_Turn1();
          X_Forward_Turn2();
        }

        if (Reset_X_remainder == 1) {
          X_Forward_Turn1();
        }
      }

      if (to_reset_1_x > 0) {                    // X1 - X2 > 0 : 반시계 방향 회전 필요
        Reset_X_Rotation = to_reset_1_x / 0.02;  // X축 이동 시 필요 회전 수
        Serial.println(Reset_X_Rotation);

        Reset_X_share = Reset_X_Rotation / 4;
        Reset_X_remainder = Reset_X_Rotation % 4;

        for (int i = 0; i < Reset_X_share; i++) {
          X_Backward_Turn1();
          X_Backward_Turn2();
          X_Backward_Turn3();
          X_Backward_Turn4();
        }

        if (Reset_X_remainder == 3) {
          X_Backward_Turn1();
          X_Backward_Turn2();
          X_Backward_Turn3();
        }

        if (Reset_X_remainder == 2) {
          X_Backward_Turn1();
          X_Backward_Turn2();
        }

        if (Reset_X_remainder == 1) {
          X_Backward_Turn1();
        }
      }

      if (to_reset_1_x == 0) {  // X축 이동 없음
        Serial.println("X축 이동 없음");
      }

      delay(3000);

      if (to_reset_1_y > 0) {                    // Y1 - Y2 > 0 :시계 방향 회전 필요
        Reset_Y_Rotation = to_reset_1_y / 0.02;  // Y축 이동 시 필요 회전 수
        Serial.println(Reset_Y_Rotation);

        Reset_Y_share = Reset_Y_Rotation / 4;
        Reset_Y_remainder = Reset_Y_Rotation % 4;

        for (int i = 0; i < Reset_Y_share; i++) {
          Y_Forward_Turn1();
          Y_Forward_Turn2();
          Y_Forward_Turn3();
          Y_Forward_Turn4();
        }

        if (Reset_Y_remainder == 3) {
          Y_Forward_Turn1();
          Y_Forward_Turn2();
          Y_Forward_Turn3();
        }

        if (Reset_Y_remainder == 2) {
          Y_Forward_Turn1();
          Y_Forward_Turn2();
        }

        if (Reset_Y_remainder == 1) {
          Y_Forward_Turn1();
        }
      }

      if (to_reset_1_y < 0) {                         // Y1 - Y2 < 0 : 반시계 방향 회전 필요
        Reset_Y_Rotation = abs(to_reset_1_y) / 0.02;  // X축 이동 시 필요 회전 수
        Serial.println(Reset_Y_Rotation);

        Reset_Y_share = Reset_Y_Rotation / 4;
        Reset_Y_remainder = Reset_Y_Rotation % 4;

        for (int i = 0; i < Reset_Y_share; i++) {
          Y_Backward_Turn1();
          Y_Backward_Turn2();
          Y_Backward_Turn3();
          Y_Backward_Turn4();
        }

        if (Reset_Y_remainder == 3) {
          Y_Backward_Turn1();
          Y_Backward_Turn2();
          Y_Backward_Turn3();
        }

        if (Reset_Y_remainder == 2) {
          Y_Backward_Turn1();
          Y_Backward_Turn2();
        }

        if (Reset_Y_remainder == 1) {
          Y_Backward_Turn1();
        }
      }

      if (to_reset_1_y == 0) {  //Y축 이동 없음
        Serial.println("Y축 이동 없음");
      }
    }
    delay(5000);
    if(Table_num == 2){
      if (to_reset_2_x < 0) {                         // X1 - X2 < 0 : 시계 방향 회전 필요
        Reset_X_Rotation = abs(to_reset_2_x) / 0.02;  // X축 이동 시 필요 회전 수
        Serial.println(Reset_X_Rotation);

        Reset_X_share = Reset_X_Rotation / 4;
        Reset_X_remainder = Reset_X_Rotation % 4;

        for (int i = 0; i < Reset_X_share; i++) {
          X_Forward_Turn1();
          X_Forward_Turn2();
          X_Forward_Turn3();
          X_Forward_Turn4();
        }

        if (Reset_X_remainder == 3) {
          X_Forward_Turn1();
          X_Forward_Turn2();
          X_Forward_Turn3();
        }

        if (Reset_X_remainder == 2) {
          X_Forward_Turn1();
          X_Forward_Turn2();
        }

        if (Reset_X_remainder == 1) {
          X_Forward_Turn1();
        }
      }

      if (to_reset_2_x > 0) {                    // X1 - X2 > 0 : 반시계 방향 회전 필요
        Reset_X_Rotation = to_reset_2_x / 0.02;  // X축 이동 시 필요 회전 수
        Serial.println(Reset_X_Rotation);

        Reset_X_share = Reset_X_Rotation / 4;
        Reset_X_remainder = Reset_X_Rotation % 4;

        for (int i = 0; i < Reset_X_share; i++) {
          X_Backward_Turn1();
          X_Backward_Turn2();
          X_Backward_Turn3();
          X_Backward_Turn4();
        }

        if (Reset_X_remainder == 3) {
          X_Backward_Turn1();
          X_Backward_Turn2();
          X_Backward_Turn3();
        }

        if (Reset_X_remainder == 2) {
          X_Backward_Turn1();
          X_Backward_Turn2();
        }

        if (Reset_X_remainder == 1) {
          X_Backward_Turn1();
        }
      }

      if (to_reset_1_x == 0) {  // X축 이동 없음
        Serial.println("X축 이동 없음");
      }

      delay(3000);

      if (to_reset_2_y > 0) {                    // Y1 - Y2 > 0 :시계 방향 회전 필요
        Reset_Y_Rotation = to_reset_2_y / 0.02;  // Y축 이동 시 필요 회전 수
        Serial.println(Reset_Y_Rotation);

        Reset_Y_share = Reset_Y_Rotation / 4;
        Reset_Y_remainder = Reset_Y_Rotation % 4;

        for (int i = 0; i < Reset_Y_share; i++) {
          Y_Forward_Turn1();
          Y_Forward_Turn2();
          Y_Forward_Turn3();
          Y_Forward_Turn4();
        }

        if (Reset_Y_remainder == 3) {
          Y_Forward_Turn1();
          Y_Forward_Turn2();
          Y_Forward_Turn3();
        }

        if (Reset_Y_remainder == 2) {
          Y_Forward_Turn1();
          Y_Forward_Turn2();
        }

        if (Reset_Y_remainder == 1) {
          Y_Forward_Turn1();
        }
      }


      if (to_reset_2_y < 0) {                         // Y1 - Y2 < 0 : 반시계 방향 회전 필요
        Reset_Y_Rotation = abs(to_reset_2_y / 0.02);  // X축 이동 시 필요 회전 수
        Serial.println(Reset_Y_Rotation);

        Reset_Y_share = Reset_Y_Rotation / 4;
        Reset_Y_remainder = Reset_Y_Rotation % 4;

        for (int i = 0; i < Reset_Y_share; i++) {
          Y_Backward_Turn1();
          Y_Backward_Turn2();
          Y_Backward_Turn3();
          Y_Backward_Turn4();
        }

        if (Reset_Y_remainder == 3) {
          Y_Backward_Turn1();
          Y_Backward_Turn2();
          Y_Backward_Turn3();
        }

        if (Reset_Y_remainder == 2) {
          Y_Backward_Turn1();
          Y_Backward_Turn2();
        }

        if (Reset_Y_remainder == 1) {
          Y_Backward_Turn1();
        }
      }

      if (to_reset_2_y == 0) {  //Y축 이동 없음
        Serial.println("Y축 이동 없음");
      }
    }
  }
  //@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@초기 위치로 이동@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
}