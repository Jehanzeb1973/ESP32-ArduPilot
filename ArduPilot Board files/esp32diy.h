/*
 * This file is free software: you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This file is distributed in the hope that it will be useful, but
 * WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 * See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

/*
 * This board that does not contain any sensors (but pins are active), it is a great help for a novice user,
 * by flashing an empty board, you can connect via Mavlink (Mission Planner - MP) and gradually add sensors.
 * If you had some sensor configured and it doesn't work then the MP connection does not work and then you may not know what to do next.
*/

#pragma once

#define HAL_ESP32_BOARD_NAME "esp32-diy"

#define TRUE  1
#define FALSE 0

//Inertial sensors
#define PROBE_IMU_I2C(driver, bus, addr, args ...) ADD_BACKEND(AP_InertialSensor_ ## driver::probe(*this,GET_I2C_DEVICE(bus, addr),##args))
#define PROBE_BARO_I2C(driver, bus, addr, args ...) ADD_BACKEND(AP_Baro_ ## driver::probe(*this,std::move(GET_I2C_DEVICE(bus, addr)),##args))

//I2C Buses
#define HAL_ESP32_I2C_BUSES {.port=I2C_NUM_0, .sda=GPIO_NUM_21, .scl=GPIO_NUM_22, .speed=400*KHZ, .internal=true}

//SPI Buses
#define HAL_ESP32_SPI_BUSES {}

//SPI Devices
#define HAL_ESP32_SPI_DEVICES {}

//RCIN
#define HAL_ESP32_RCIN GPIO_NUM_36

//RCOUT
#define HAL_ESP32_RCOUT {GPIO_NUM_25, GPIO_NUM_27, GPIO_NUM_33, GPIO_NUM_32}


//BAROMETER
#define HAL_BARO_ALLOW_INIT_NO_BARO 1
#define HAL_BARO_DEFAULT 					HAL_BARO_BMP280_I2C
#define HAL_BARO_BMP280_NAME 				"bmp280"
#define HAL_BARO_PROBE_LIST 				PROBE_BARO_I2C(BMP280, 0, 0x76)



//IMU
// #define AP_INERTIALSENSOR_ENABLED 1
// #define AP_INERTIALSENSOR_KILL_IMU_ENABLED 0
#define HAL_INS_DEFAULT 					HAL_INS_MPU6050_I2C
#define HAL_INS_MPU6050_I2C_BUS 				0
#define HAL_INS_MPU6050_I2C_ADDR 			(0x68)
#define HAL_INS_PROBE_LIST PROBE_IMU_I2C(Invensense, 0, 0x68, ROTATION_NONE)



//COMPASS
#define AP_COMPASS_ENABLE_DEFAULT 0
#define ALLOW_ARM_NO_COMPASS

//See boards.py
#ifndef ENABLE_HEAP
#define ENABLE_HEAP 1
#endif

//WIFI
#define HAL_ESP32_WIFI 1  //1-TCP, 2-UDP, comment this line = without wifi
#define WIFI_SSID "ardupilot-esp32"
#define WIFI_PWD "ardupilot-esp32"

//UARTs
// UART_NUM_0 is Serial 0 and default for mavlink
// UART_NUM_1 is Serial 3 in mission planner
// UART-Num_2 is Serial 2 in mission planner
//Serial 1 settings are used when connected to mission planner using wifi

	#define HAL_ESP32_UART_DEVICES \
    {.port=UART_NUM_0, .rx=GPIO_NUM_3 , .tx=GPIO_NUM_1 },\
    {.port=UART_NUM_1, .rx=GPIO_NUM_39, .tx=GPIO_NUM_18},\
    {.port=UART_NUM_2, .rx=GPIO_NUM_16, .tx=GPIO_NUM_17}




//#define AP_OPTICALFLOW_ENABLED 1
//#define AP_OPTICALFLOW_CXOF_ENABLED 1
//#define AP_OPTICALFLOW_MAV_ENABLED 1

//#define AP_RANGEFINDER_TOFSENSEF_I2C_ENABLED 1

//ADC
#define HAL_DISABLE_ADC_DRIVER 1
#define HAL_USE_ADC 0

//LED
#define DEFAULT_NTF_LED_TYPES Notify_LED_None

//RMT pin number
#define HAL_ESP32_RMT_RX_PIN_NUMBER 4

//SD CARD
// Do u want to use mmc or spi mode for the sd card, this is board specific,
// as mmc uses specific pins but is quicker,
// and spi is more flexible pinouts....
// dont forget vspi/hspi should be selected to NOT conflict with HAL_ESP32_SPI_BUSES

//#define HAL_ESP32_SDCARD //after enabled, uncomment one of below
//#define HAL_ESP32_SDMMC
//#define HAL_ESP32_SDSPI {.host=VSPI_HOST, .dma_ch=2, .mosi=GPIO_NUM_2, .miso=GPIO_NUM_15, .sclk=GPIO_NUM_26, .cs=GPIO_NUM_21}

#define HAL_LOGGING_FILESYSTEM_ENABLED 0
#define HAL_LOGGING_DATAFLASH_ENABLED 0
#define HAL_LOGGING_MAVLINK_ENABLED 0

#define HAL_BOARD_LOG_DIRECTORY "/SDCARD/APM/LOGS"
#define HAL_BOARD_STORAGE_DIRECTORY "/SDCARD/APM/STORAGE"
#define HAL_BOARD_LOG_DIRECTORY "/SDCARD/APM/LOGS"
#define HAL_BOARD_TERRAIN_DIRECTORY "/SDCARD/APM/TERRAIN"

#define HAL_LOGGING_BACKENDS_DEFAULT 1

//#define AP_RCPROTOCOL_ENABLED 0
