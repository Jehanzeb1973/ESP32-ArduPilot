# ESP32-ArduPilot  

Precompiled Ardupilot Code for ESP32  

This Repository allows you to quickly start with ArduPilot on ESP32  

ArduPilot compilation is not difficult but is done under Linux and lot of people dont want that level of detailed effort  

With precompiled code you can start quickly in ESP32 Ardupilot, the downside being you are stuck with firmware choices that have been made at compile time  

## Settings:  

### RC in pin GPIO36  

### RC Out Signals for controlling speed controllers and other outputs on following GPIO's  

GPIO0, GPIO5, GPIO16, GPIO17, GPIO18, GPIO19, GPIO23, GPIO25, GPIO26, GPIO27, GPIO32, GPIO33  


### Except GPS all sensors are connected through I2C Pins SDA=GPIO21, SCL=GPIO22  

1-BMP280 Barometric sensor reading on I2C pins  

2-MPU6050 IMU reading on I2C pins  

3-MPU9250 IMU readings on I2C pins  

4-5883 Magnetic sensor reading on I2C Pins  


   

### UART for GPS connection  

UART_NUM_0, .rx=GPIO_NUM_3 , .tx=GPIO_NUM_1  

UART_NUM_1, .rx=GPIO_NUM_35, .tx=GPIO_NUM_17



Mission Planner accessible over WiFi as well as Serial port;
WiFi Credentials;

WIFI_SSID						"ardupilot123"
WIFI_PWD						"ardupilot123"

### Software required to upload files  
ESP32 Flash Download tool  
https://www.espressif.com/en/support/download/other-tools  
#### Flash Download address  

0x1000 bootloader.bin  

0x10000 ardupilot.bin  

0x8000 partition-table.bin




