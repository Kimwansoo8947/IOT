#include <Wire.h> // I2C 통신을 위한 기본 라이브러리
#include <LiquidCrystal_I2C.h> // I2C LCD 라이브러리

LiquidCrystal_I2C lcd(0x27, 16,2); // I2C 주소: 0x27
  
void setup()
{
  lcd.init(); // I2C LCD 초기화
  lcd.backlight(); // 백라이트 켜기
  lcd.print("LCD init");
  delay(2000); // 2초 동안 대기
  lcd.clear(); // LCD 화면 지우기
}

void loop()
{
 	lcd.setCursor(0,0); // 첫 번째 줄 첫 번째 칸(0,0)부터 출력
    lcd.print("Hello World!");
      
  	for(int position = 0; position <16; position++){ 
    
      lcd.scrollDisplayLeft(); // 한 칸씩 왼쪽으로 보냄
      delay(150);                
              
}
