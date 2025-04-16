- 특정 기능 수행에 로직을 묶어 놓아서 다른 일을 못하게 되면 프로그램이 블로킹되었다고 합니다.
- 반대로 여러 기능을 수행하는 것은 논블로킹 방식이라고 합니다.
- 인터럽트는 외부의 자극이나 시간에 의해 마이크로컨트롤러에 긴급히 전달되는 신호입니다.

  

#ifndef LedToggle_h
#define LedToggle_h

#include "Arduino.h"

class LedToggle {
public:
    LedToggle(int pin); // 생성자 선언
    LedToggle(int pin, unsigned long delayTime); // 생성 
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


    
