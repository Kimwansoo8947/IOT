// 함수 만들기
// 함수를 호출하는 방법
// 함수를 호출하는 방법
// 함수 이름만으로 호출하는 방법

int a1 = 2;
int a2 = 3;
int a3;

void setup() {
  Serial.begin(115200);
  Serial.println();

  sum(); // sum 함수 호출
  Serial.println(a3); //5

}

void loop() {


}
void sum(){
  a3 = a1 + a2;
}

// 인수의 값을 복사하여 매개 변수로 전달하는 방법
int a1 = 2;
int a2 = 3;
int a3;

void setup() {
  Serial.begin(115200);
  Serial.println();

  sum(a1,a2); // sum 함수 호출 a1,a2는 인수이다.
  Serial.println(a3); //5

}

void loop() {


}
int sum(int a, int b){ // a,b는 매개변수이다.
  int c = a+b;
  return c
}
 // 사용한 인수를 매개 변수에서 참조하여 사용하는 방법
int a1 = 2;
int a2 = 3;
int a3;

void setup() {
  Serial.begin(115200);
  Serial.println();

  sum(a1,a2,a3); // sum 함수 호출 a1,a2,a3는 인수이다.
  Serial.println(a3); //5

}

void loop() {


}
void sum(int a, int b , int &c){ // a,b,c는 매개변수이다.
// 함수 호출 시 인수로 사용한 변수값을 함수 내에서 수정하려면 함수의 매개 변수 다음에 &을 붙인다.
  c = a+b;

}

// 함수 오버로딩
// 같은 이름에 매개 변수 형이나 개수를 다르게 갖는 것을 함수 오버로딩이라고 한다.
int a1 = 2;
int a2 = 3;
int a3;

float f1 = 2.5;
float f2 = 3.6;
float f3;

void setup() {
  Serial.begin(115200);
  Serial.println();

  a3 = sum(a1,a2);
  Serial.println(a3);
  sum(f1,f2,f3); // sum 함수 호출 a1,a2,a3는 인수이다.
  Serial.println(f3); //5

}

void loop() {


}

int sun(int a, int b){ //a,b는 매개 변수이다.
  int c = a+b;
  return c;
}
void sum(float a, float b , float &c){ // a,b,c는 매개변수이다.
  c = a+b;

}
