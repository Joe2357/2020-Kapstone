# 명령어

1. 라이브러리
	- SPI.h
	- Wire.h
	- Adafruit_GFX.h
	- Adafruit_SSD1306.h

2. 기기 initialize
	- Adafruit_SSD1306 'name'(D1, D0, DC, RES, CS);

3. 명령어
	- 'name'.begin() : 로고를 띄움
	- 'name'.display() : 출력한 문구들을 화면에 띄움
	- 'name'.clearDisplay() : 문구를 지움 ( 화면에는 지워지지 않음, 다른 것을 출력하여 덮어써야함 )
	- 'name'.setTextSize(n) : 텍스트 크기 조절
	- 'name'.setTextColor() : 텍스트 색깔 조절
	- 'name'.setCursor(x, y) : 텍스트 시작 위치 설정 ( 픽셀 )
	- 'name'.print() : 텍스트 출력 ( display하기 전에는 보이지 않음 )
