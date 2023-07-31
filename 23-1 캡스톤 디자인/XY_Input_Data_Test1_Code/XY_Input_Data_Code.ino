int IN1=2;
int IN2=3;
int IN3=4;
int IN4=5;

int IN5=8;
int IN6=9;
int IN7=10;
int IN8=11;

void setup()
{
 
 pinMode(IN1,OUTPUT);
 pinMode(IN2,OUTPUT);
 pinMode(IN3,OUTPUT);
 pinMode(IN4,OUTPUT);
 pinMode(IN5,OUTPUT);
 pinMode(IN6,OUTPUT);
 pinMode(IN7,OUTPUT);
 pinMode(IN8,OUTPUT);
 Serial.begin(9600);

}


void Forward_Y_Turn(){ // Y축 정방향으로 1바퀴 돌아가는 코드

 for(int i=0; i<50; i= i+1){
 digitalWrite(IN1,LOW);
 digitalWrite(IN2,HIGH);
 digitalWrite(IN3,HIGH);
 digitalWrite(IN4,LOW);
 delay(3);


 digitalWrite(IN1,LOW);
 digitalWrite(IN2,HIGH);
 digitalWrite(IN3,LOW);
 digitalWrite(IN4,HIGH);
 delay(3);
 

 digitalWrite(IN1,HIGH);
 digitalWrite(IN2,LOW);
 digitalWrite(IN3,LOW);
 digitalWrite(IN4,HIGH);
 delay(3);
 

 digitalWrite(IN1,HIGH);
 digitalWrite(IN2,LOW);
 digitalWrite(IN3,HIGH);
 digitalWrite(IN4,LOW);
 delay(3);

 }
 

}

void Forward_X_Turn(){ // X축 정방향으로 1바퀴 돌아가는 코드

 for(int i=0; i<50; i= i+1){
 digitalWrite(IN5,LOW);
 digitalWrite(IN6,HIGH);
 digitalWrite(IN7,HIGH);
 digitalWrite(IN8,LOW);
 delay(3);


 digitalWrite(IN5,LOW);
 digitalWrite(IN6,HIGH);
 digitalWrite(IN7,LOW);
 digitalWrite(IN8,HIGH);
 delay(3);
 

 digitalWrite(IN5,HIGH);
 digitalWrite(IN6,LOW);
 digitalWrite(IN7,LOW);
 digitalWrite(IN8,HIGH);
 delay(3);
 

 digitalWrite(IN5,HIGH);
 digitalWrite(IN6,LOW);
 digitalWrite(IN7,HIGH);
 digitalWrite(IN8,LOW);
 delay(3);

 }
 

}


void Stop(){ // 정지 코드
 digitalWrite(IN1,LOW);
 digitalWrite(IN2,LOW);
 digitalWrite(IN3,LOW);
 digitalWrite(IN4,LOW);
}

void loop()
{
  Serial.println("Enter X and Y");
  Serial.print("X = ");

  while (Serial.available() == 0) {} // Wait until data is available
  int x = Serial.parseInt(); // Read the input as an integer
  Serial.println(x); // Print the value of x

  // Clear the input buffer
  while (Serial.available() > 0) {
    char _ = Serial.read();
  }

  Serial.print("Y = ");

  while (Serial.available() == 0) {} // Wait until data is available
  int y = Serial.parseInt(); // Read the input as an integer
  Serial.println(y); // Print the value of y

  // Clear the input buffer
  while (Serial.available() > 0) {
    char _ = Serial.read();
  }

  int Rotation_X = x/4;  // x축 회전 바퀴 수
  int Rotation_Y = y/4;  // y축 회전 바퀴 수

  for(int i=0; i<Rotation_Y; i= i+1){
    Forward_Y_Turn();
  }
  
  for(int i=0; i<Rotation_X; i= i+1){
    Forward_X_Turn();
  }

  
}

