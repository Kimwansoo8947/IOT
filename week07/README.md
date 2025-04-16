- 7주차 수업 내용 정리
- 특정 기능 수행에 로직을 묶어 놓아서 다른 일을 못하게 되면 프로그램이 블로킹되었다고 합니다.
- 반대로 여러 기능을 수행하는 것은 논블로킹 방식이라고 합니다.
- 인터럽트는 외부의 자극이나 시간에 의해 마이크로컨트롤러에 긴급히 전달되는 신호입니다.

  
- 아두이노 파일 구조
- ifndef는 # if not defined를 줄인말이다. 처음 #include항 후부터는 #ifndef가 거짓이 되므로 #include는 동작하지 않는다.
- 클래스 생성하기
- class 명령어는 클래스를 정의한다.
- 클래스는 함수가 아니라 명령어이므로 끝에 세미콜론을 붙인다.
- {}안은 public과 private를 붙여서 두 영역으로 나눈다.
- public은 클래스 외부에 알려져야 할 메소드의 프로토타입을 정의 private은 메소드 안에서 사용할 함수나 변수를 생성한다. 이 값은 외부에 알려지지 않는다.
- 클래스 이름과 같은 이름을 가지 특별한 함수를 생성자라고 한다.
- 생성자 앞에는 void나 변수형이 붙지 않으므로 다른 메소드와 구분된다.
- 생성자는 주로 클래스 사용을 위해 오브젝트를 생성할떄 호출한다.
#ifndef LedToggle_h
#define LedToggle_h

#include "Arduino.h"

class LedToggle {
public:
    LedToggle(int pin); // 생성자 선언
    LedToggle(int pin, unsigned long delayTime); // 생성자 
    void toggle();

private:
    int _pin;
    bool _state;
    unsigned long _delayTime; 
};

#endif

#include "LedToggle.h"

LedToggle::LedToggle(int pin) {
    _pin = pin;
    _state = false;
    _delayTime =0; //  추가 
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, LOW);

} 

LedToggle::LedToggle(int pin, unsigned long delayTime) { // 추 가 
	_pin = pin;
    _state = false;
    _delayTime = delayTime;
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, LOW);
	
	
	
}
void LedToggle::toggle() {
	
	if(_delayTime >0){
		delay(_delayTime);
	   
	}
    _state = !_state;
    digitalWrite(_pin, _state ? HIGH : LOW);

- 인터넷의 구조
- 패킷 네트워크: 전송하고자 하는 메시지를 작은 조각으로 나누고 조각마다 송신자와 수신자의 주소를 기입한 후 조각들이 독립적으로 네트워크를 이동하도록 구현
- 피어-투-피어: 연결된 모든 컴퓨터가 서버이자 클라이언트 역할을 동시에 수행 ex) 비트토렌트, 블록체인
- 허브: 여러 대의 컴퓨터를 간단하게 연결하는 장비 (지능이 없다.)
- 스위치 (두뇌가 포함됨)
- 라우터 (네트워크 최적의 경로를 찾아줌) : 라우터가 갖고 있는 경로 정보를 서로 교환하며 최적의 패킷 경로를 결정
- 이더넷 통신 방식 - CSMA/CD : 동시에 통신을 할때 발생하는 충돌을 막기 위헤 CSMA/CD 사용
- 도메인 네임 서버 (DNS): 문자로 구성된 도메인 네임과 숫자로 구성된 IP 주소를 연결해주는 소프트웨어
- TCP: 신뢰성 높은 통신을성
