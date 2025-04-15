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


    
