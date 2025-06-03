## Wi-Fi
```
Wi-Fi 구성
AP (Access Point)와 station(STA)으로 구성
  - AP: 유무선 공유기
  - STA: 노트북, 스마트 폰 등

Wi-Fi Service Set
 - BSS ex) 가정
    -  AP가 없으면 ad hoc 모드
    -  AP가 있으면 infrastructure 모드 => 일반적으로 사용

- ESS
  - 두 개 이상의 BSS들이 모여서 구성 => BSS를 여러개 묶어서


MAC 방식
  -PCF => 중앙 집중식
  -DCF => CSMA/CA 사용 (Wi-Fi MAC 방식 중에 주로 사용됨)
```


## MAC 계층
```
CSMA-CA
CA : 충돌 회피
CSMA-CD와 다르게 충돌 감지를 하지 못함

Hidden Terminal Problem
숨겨진 노드 문제
=> 전송 감지가 힘들다. => RTS, CTS (충돌 회피) 사용하는 이유


RTS-CTS-DATA-ACK 방식
송신 측에서 RTS 전송 후, 수신 측에서 CTS 전송
송신 측에서 CTS 전송 받지 못하면, 일정 시간 대기 후 RTS를 다시 전송
송신 측에서 CTS 전송 받으면 DATA 전송하고 수신 측에서 송신 측에 ACK 전송

CSMA-CA의 CSMA-CD와 비교한 장단점
- 장점: 저 가격으로 구현
- 단점: 데이터 전송이 많이 지연될 수 있다.

```
### 



