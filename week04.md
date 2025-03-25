통신 프로토콜
- 하드웨어끼리 통신
- ex) 컴퓨터나 원거리 통신 장비 사이에서 메시지를 주고 받는 양식과 규칙의 체계

- I2C (Inter-Intergrated-Circuit)
- I 스퀘어 C라고도 부른다.
- 집적회로
- SDA: 클록 신호에 밎추어 데이터를 주고 받기 위한 선
- SCL: 타이밍(클록)을 동기화 하기 위한 선

- 하나의 관리자가 여러게의 센서를 가질 수 있다.
- 실제로 사용은 112개 입니다. 그 이유는 15개가 예약되어 있습니다.
- 데이터 상태(SDA)가 LOW 이면 ACK , HIGH이면 NACK이다.

- I2C, UART, SPI 통신 비교

I2C: 1:N
UART: 1:1 통신
SPI: 1:N 센서를 더 추가하는 경우 slave 갯수 만큼  ss라인이 더 필요하다.


A4 -> SDA (데이터 선신 프로토콜
- 하드웨어끼리 통신
- ex) 컴퓨터나 원거리 통신 장비 사이에서 메시지를 주고 받는 양식과 규칙의 체계

- I2C (Inter-Intergrated-Circuit)
- I 스퀘어 C라고도 부른다.
- 집적회로
- SDA: 클록 신호에 밎추어 데이터를 주고 받기 위한 선
- SCL: 타이밍(클록)을 동기화 하기 위한 선

- 하나의 관리자가 여러게의 센서를 가질 수 있다.
- 실제로 사용은 112개 입니다. 그 이유는 15개가 예약되어 있습니다.
- 데이터 상태(SDA)가 LOW 이면 ACK , HIGH이면 NACK이다.

- I2C, UART, SPI 통신 비교

I2C: 1:N, N:N
UART: 1:1 통신
SPI: 1:N 센서를 더 추가하는 경우 slave 갯수 만큼  ss라인이 더 필요하다.

A4 -> SDA (데이터 선)
A5 -> SCL (클럭 선)

1602(16x2) LCD 의미
LCD에 COLUMNS 16
ROW가 2개

#include <Wire.h> // I2C 통신을 위한 기본 라이브러리
#include <LiquidCrystal_I2C.h> // I2C LCD 라이브러리

LiquidCrystal_I2C lcd(0x27, 16,2);
  
void setup()
{
  lcd.init(); // I2C LCD 초기화
  lcd.backlight(); // 백라이트 켜기
  lcd.print("LCD init");
  delay(2000);
  lcd.clear();
}

void loop()
{
 	lcd.setCursor(16,0);
  	lcd.print("Hello, World!");
    
  	for(int position = 0; position<16; position++){
      lcd.scrollDisplayLeft();
      delay(150);
    }
                
              
}

아두이노 1602 LCD I2C 주소 찾기

#include<Wire.h> // I2C 통신을 위한 라이브러리

void setup(){
  Serial.begin(9600); // 시리얼 모니터 시작 (속도: 9600 baud)
  Wire.begin();
  Serial.println("I2C Scanner Running..."); // 시작 메시지 출력

}

void loop(){
  Serial.println("Scanning..."); // 검색 시작 메시지 출력

  for(byte address = 1; address <127; address++){ // I2C 주소 범위: 0x01 ~ 0x7F (1~127)
    Wire.beginTransmission(address); // 특정 주소로 통신 시작
    if(Wire.endTransmission()==0){ // 응답이 0이면 I2C 장치가 존재함
      Serial.print("I2C 장치 발견 0x"); // 발견된 장치 주소 출력
      Serial.println(address,HEX); // 16진수(HEX) 형식으로 출력
      delay(500); // 0.5초 대기 (너무 빠르게 반복되지 않도록)
    }
  }
  Serial.println("Scan Complete! Retrying in 5 seconds...\n");
  delay(5000); // 5초 후 다시 검색
}
