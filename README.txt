Данная библиотека обеспечивает взаимодействие датчика с концентратором.

После ее подключения в проект, для использования необходимо внести изменения:
1. В основном файле программы (main.c) добавить строки:
1.1
#include "SPI_connection.h"
#include "protocol_parser.h"

1.2 Вызвать функцию sensorInit() для инициализации датчика (при необходимости ее можно доработать под каждый датчик)

1.3 В основном цикле добавить:
	  if (spi_rx_complete) {
		  spi_rx_complete = false;
		  parserFSM();
	  }

2. В файле main.h объявить:
extern SPI_HandleTypeDef hspi2;
extern TIM_HandleTypeDef htim2;
extern uint8_t data_buf[256];
extern uint8_t page_pos_ptr ;
extern volatile uint16_t page_ptr;

3. Сконфигурировать соответствующий схеме вывод CS для SPI связи с концентратором в режим 
External Interrupt Mode with Falling Edge

4. Cконфигурировать вывод сигнала CTRL.
Использовать TIM2 для настройки параметров:
- Clock Source = Internal Clock
- Channel 1 = PWM Generation CH1
- One Pulse Mode = Enabled
- Prescaler = 72
- Counter Period = 501
- Mode = PWM mode 1
- Pulse = 1
- CH Polarity = High
Остальные настройки оставить по умолчанию

Для датчика необходимо переопределить функции (при необходимости):
1. sensorChipInit()
2. resetSensorChip
3. stopSensorChip()
4. enableSensorChip()
5. startMeasurement()
6. stopMeasurement()
7. sensorSelfchek()
8. startMeasurement()
9. stopMeasurement()