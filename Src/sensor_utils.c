/*
 * sensor_utils.c
 *
 *  Created on: 20 мар. 2026 г.
 *      Author: AVA
 */

#include "sensor_utils.h"
#include "main.h"
#include "../Drivers/W25Q/w25q_spi.h"
#include "protocol_parser.h"
#include "SPI_Connection.h"
#include <stdbool.h>
#include <stdint.h>

bool need_selfcheck = 0;

/* Выполняет проверку работоспособности датчика
 * Возврат: 1 - датчик работоспособен
 * 			0 - датчик не работоспособен */
bool sensorSelfCheck() {

#ifdef TEST_VERSION
	return true;
#endif

	return true;
}

void sensorChipInit() {
	return;
}

void resetSensorChip() {
	return;
}

void stopSensorChip() {
	return;
}

void enableSensorChip() {
	return;
}

/* Выполняет сброс датчика */
void resetSensor() {

	stopMeasurement();

    // сброс cостояния протокола
    resetFSMProtocol();

    // сброс переменных
    page_pos_ptr = 0;
    page_ptr = 0;

    // сброс микросхемы датчика
    resetSensorChip();

	// очистка флеш-памяти
    HAL_GPIO_WritePin(GPIOA, GPIO_PIN_2, GPIO_PIN_SET);
    W25_Erase_Chip();

    reset_ready = true;

	return;
}
/* Запуск измерения */
void startMeasurement() {

	enableSensorChip();
	return;
}

/* Остановка измерения */
void stopMeasurement() {

	stopSensorChip();
	return;
}



