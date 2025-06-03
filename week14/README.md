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
## ZigBee 스택
```
- 물리계층
3개의 밴드에 27개의 채널 사용
2.4GHz 대역에서 무선 랜돠 겹치는 채널이 있다.
DSSS => 양쪽 모두가 알고 있는 슈도 랜덤 값인 +1 이나 -1을 데이터에 곱해서 보낸다.

- MAC 계층 특징
Network Cordinator(NC): 네트워크 코디네이터 (관리자)
# FFD : 전기능기기 (프로토콜 모두 구현)
# RFD : 축소기능기기 (최소한의 무선 기능을 가직 있다.)
지그비의 CSMA-CA  : RTS, CTS 사용하지 않는다.
슈퍼 프레임 구조
- CFP -> 확실히 받아야되는 데이터에 사용
- CAP ->  조금 덜 중요한 데이터에 사용
- inactive -> sleep 모드라고 생각 (배터리)
비콘 => 비콘에 따라 시간 동기화를 하여 슬롯 단위 송수신 가능
     => GTS가 어는 기기에 할당되었는지 알려줌

MAC 주소
PAN ID : 네트워크 주소, 코디네이터가 할당한 ID
- ADDRESS : 2 Byte 또는 8 Byte
  - 2 Byte : 코디네이터가 할당해준 주소
  - 8 Byte : 처음 제작될 때 제작사가 할당해준 주소
  - 같은 네트워크에서 통신할떄는 사용 안 될 수도 있다.

- 분산 주소 할당 기법
ZigBee 라우터는 모두 자신의 자식 노드에게 주소 할당을 할 수 있다. => 분산 방식

- 분산 할당의 예
Cm : 최대 자식의 개수
Rm : 라우터가 될 수 있는 최대 개수
Lm : 네트워크 Tree의 최대 길이
```


