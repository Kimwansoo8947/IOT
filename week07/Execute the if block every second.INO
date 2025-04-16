
// 1초 동안의 loop의 실행 횟수를 세어서 출력함
void setup() {
  Serial.begin(115200);
  Serial.println();

}

void loop() {

  static unsigned long loopCnt = 0; // 지역변수는 다음 실행때 값을 잃어버리므로 값 유지를 위해 static을 사용한다.
  static unsigned long nextMil = millis() + 1000; // 지역변수는 다음 실행때 값을 잃어버리므로 값 유지를 위해 static을 사용한다.
  // mills()는 가동시간을 밀리초 단위로 알려주는 아두이노 내장 함수이다. nextMil은 1 초 후를 나타내는 변수이므로 mills + 1000으로 초기화한다.
  loopCnt++;

  if(millis() > nextMil){ // 현재 시간이 실행 예정 시간보다 커졌는지 확인하는 조건
    nextMil = millis() + 1000; // 다음 실행 예정 시간을 지금시간에서 1초 후로 갱신
    Serial.print(loopCnt);
    loopCnt = 0; // 카운트 초기화
  }
  
}
// 변수 nextMIil에 붙은 static에 유의한다.
