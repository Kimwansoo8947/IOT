 includes Test:
 configuration TestAppC
 {
 }
 implementation
  {
          components TestC, MainC;
          components LedsC, new TimerMilliC();

          components ActiveMessageC as AMC;
          components new AMSenderC(AM_TEST_DATA_MSG) as AMSC; // 무선으로 데이터를 전송하기 위한 컴포넌트

          TestC.Boot -> MainC;
          TestC.Leds -> LedsC;
          TestC.MilliTimer -> TimerMilliC;
 
          TestC.RadioControl -> AMC;
          TestC.RadioSend -> AMSC;

          components new SensirionSht11C() as Sht11Ch0C; // 온 습도
          TestC.Temp -> Sht11Ch0C.Temperature;
          TestC.Humi -> Sht11Ch0C.Humidity;
  
          components new IlluAdcC() as Illu; // 조도 센서
          TestC.Illu -> Illu;

          components BatteryC; // 배터리
          TestC.Battery -> BatteryC;
}
 
