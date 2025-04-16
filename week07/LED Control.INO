// 특정 기능 수행에 로직을 묶어 놓아서 다른 일을 못하게 되면 프로그램이 블로킹되었다고 합니다.
// 반대로 여러 기능을 수행하는 것은 논블로킹 방식이라고 합니다.
// 인터럽트는 외부의 자극이나 시간에 의해 마이크로컨트롤러에 긴급히 전달되는 신호입니다.

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
