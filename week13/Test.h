   #ifndef TEST_H // if not define : 중복 방지
   #define TEST_H
   #include "message.h"
   enum{ // enum -> 컴파일러 체크 가능  # define : 컴파일러 체크 불가능
           TEST_PERIOD = 10240LU, // 1024 -> 1초, 10240 -> 10초
   };
   enum{
           DFLT_VAL = 0x11,
   };
  enum{
          TEST_DATA_LENGTH = TOSH_DATA_LENGTH - 6, // TOSH_DATA_LENGTH => 사용자가 넣을 데이터 길이 값
  };
  enum{
          AM_TEST_DATA_MSG = 0xA4, // 0xA4 => 메시지 타입
  };
  typedef nx_struct test_data_msg{
          nx_am_addr_t srcID;
          nx_uint32_t seqNo; // 32비트
          nx_uint16_t type; // 16비트 => 2바이트
          nx_uint16_t Temp;
          nx_uint16_t Humi;
          nx_uint16_t Illu;
          nx_uint16_t battery;
          // nx_uint8_t testData[TEST_DATA_LENGTH];
  } test_data_msg_t;
 
  #endif // TEST_H
