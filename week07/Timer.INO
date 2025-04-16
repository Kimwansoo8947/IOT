
#include <SimpleTimer.h>
SimpleTimer timerCnt; // 클래스를 가지고 인스턴스 생성 (재사용 가능), 인수가 없는 형태

unsigned long loopCnt;

void timerCntFunc(){
  Serial.println(loopCnt);
  loopCnt = 0;

}
void setup() {
  Serial.begin(115200);
  Serial.println();

  timerCnt.setInterval(1000,timerCntFunc); // 1초마다 timercntFunc() 함수를 실행하라고 타이머 설정
  
 

}

void loop() {

  timerCnt.run();  // 함수 실행
  loopCnt++;
}
