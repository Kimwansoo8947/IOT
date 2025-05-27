  1 #ifndef TEST_H
  2 #define TEST_H
  3 #include "message.h"
  4 enum{
  5         TEST_PERIOD = 10240LU,
  6 };
  7 enum{
  8         DFLT_VAL = 0x11,
  9 };
 10 enum{
 11         TEST_DATA_LENGTH = TOSH_DATA_LENGTH - 6,
 12 };
 13 enum{
 14         AM_TEST_DATA_MSG = 0xA4,
 15 };
 16 typedef nx_struct test_data_msg{
 17         nx_am_addr_t srcID;
 18         nx_uint32_t seqNo;
 19         nx_uint16_t type;
 20         nx_uint16_t Temp;
 21         nx_uint16_t Humi;
 22         nx_uint16_t lllu;
 23         nx_uint16_t battery;
 24         // nx_uint8_t testData[TEST_DATA_LENGTH];
 25 } test_data_msg_t;
 26
 27 #endif // TEST_H
