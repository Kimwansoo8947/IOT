## InfluxDB 설치 
  - InfluxDB download key using wget
```
wget -q https://repos.influxdata.com/influxdata-archive_compat.key
echo '393e8779c89ac8d958f81f942f9ad7fb82a25e133faddaf92e15b16e6ac9ce4c influxdata-archive_compat.key' | sha256sum -c && cat influxdata-archive_compat.key | gpg --dearmor | sudo tee /etc/apt/trusted.gpg.d/influxdata-archive_compat.gpg > /dev/null
echo 'deb [signed-by=/etc/apt/trusted.gpg.d/influxdata-archive_compat.gpg] https://repos.influxdata.com/debian stable main' | sudo tee /etc/apt/sources.list.d/influxdata.list
```
  - Packages are up to date && install Influxdb
```
 sudo apt-get update && sudo apt-get install influxdb -y

```
  - InfluxDB as a background service on startup
```
sudo service influxdb start
```
  - InfluxDB is status (service)
```
sudo service influxdb status
```
  
## InfluxDB 데이터베이스 만들기

```
$ influx

>create database <데이터베이스이름>
확인 : show databases 
```

# Grafana Installation

## 1. Install the prerequisite packages
```
sudo apt-get install -y apt-transport-https software-properties-common wget
```

## 2. Import the GPG key:
```
sudo mkdir -p /etc/apt/keyrings/
wget -q -O - https://apt.grafana.com/gpg.key | gpg --dearmor | sudo tee /etc/apt/keyrings/grafana.gpg > /dev/null
```

## 3. To add a repository for stable releases, run the following command:
```
echo "deb [signed-by=/etc/apt/keyrings/grafana.gpg] https://apt.grafana.com stable main" | sudo tee -a /etc/apt/sources.list.d/grafana.list
```

## 4. Run the following command to update the list of available packages:
```
sudo apt-get update && sudo apt-get install grafana -y

```
## 5. Run the following command to server start
```
sudo systemctl start grafana-server
```
## influxdb import with python
```
pip install influxdb
```
  - hint: See PEP 668 for the detailed specification.
```
  sudo rm /usr/lib/python3.11/EXTERNALLY-MANAGED
```
## influxDB Database 생성
```
$ Influx
$ create database dust
$ show databases
$ exit
```
## 문자열 처리와 형변환
```
a = "300.0"
print(float(a)) # 문자열 "300.0"을 float형으로 변환 -> 300.0

b = "dust = 300.0"
print(b.split("=")[1]) # "문자열을 "=" 기준으로 나눈 뒤, 오른 쪽 값 출력 -> " 300.0"

ex)
b = "dust = 300.0"
print(b.split("=")[0]) # "문자열을 "=" 기준으로 나눈 뒤, 왼쪽 값 출력 -> "dust "

```
## Grafana 접속
```
localhost:3000
username : admin , password : admin
Connections -> Data sources
InfluxDB
InfluxDB 연결 설정
http://localhost:8086
Database : dust
User : root, password : root
select measurement -> dust
tag -> inhaUni = 2222
field(value) -> dust
```

