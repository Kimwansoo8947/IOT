import time
import requests, json
from influxdb import InfluxDBClient
import serial

seri = serial.Serial('/dev/ttyACM0', baudrate=9600, timeout=None)


# 1초 간격으로 센서 값을 읽고 InfluxDB에 저장
while True:
    time.sleep(1) # 1초 대기
    if seri.in_waiting != 0: # 시리얼 버퍼에 읽을 데이터가 있는 경우
        content = seri.readline() # 한줄 읽는다.
        a = float(content.decode())  #  중요) 바이트 데이터를 문자열로 변환 후 float으로 변환 (먼지 농도)

     
        data = [{
            'measurement': 'dust',
            'tags': {
                'InhaUni': '2222',
            },
            'fields': {
                'dust': a, # 실제 측정 데이터 (float)
            }
        }]

        client = None
        try:
            client = influxdb('localhost',8086,'root','root','root','dust')
        except Exception as e:
            print("Exception", str(e))

        if client is not None:
            try:
                client.write_points(data)
            except Exception as e:
                print("Exception write:", str(e))
            finally:
                client.close()

        print(a)  # 센서값 출력
        print("running influxdb OK")
