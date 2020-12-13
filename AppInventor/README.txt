1. 블루투스에 관하여
	- 기본적으로 앱인벤터에서 지원하는 BluetoothClient, BluetoothServer는 HC-10모듈과 호환 X
	- BluetoothLE를 다운받아 앱인벤터에 적용해서 사용해야 연결 가능

2. BluetoothLE
	- service_UUID와 characteristic_UUID를 initialize해야 함
	- 인터넷에 돌아다니는 UUID를 복사하여 사용했음. 역할에 대해서는 무지
3. 기능
	- BluetoothLE의 블럭에서 골라 사용할 수 있음
	- Bluetooth.StartScanning : 블루투스 스캔
	- Bluetooth.StopScanning : 블루투스 스캔 중단
	- Bluetooth.Connect(index) : 리스트의 index에 있는 기기와의 블루투스 연결
	- Bluetooth.RegisterForStrings(service_uuid, characteristic_uuid, utf16) : ?????
	- Bluetooth.Disconnect : 블루투스 연결 중단
	- When Bluetooth.StringsReceived : 블루투스가 문자열을 입력받았을 경우
	- Bluetooth.WriteStrings(service_uuid, characteristic_uuid, utf16, values) : value의 문자열을 블루투스로 전송