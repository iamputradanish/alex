#include <Arduino.h>
#include <avr/io.h>
#include <FreeRTOS.h>
#include <task.h>
#include <semphr.h>

#define STACK_SIZE 200

#define GREEN_LED_DATA_PIN 2
#define GREEN_LED_LATCH_PIN 3
#define GREEN_LED_CLOCK_PIN 4
#define RED_LED_PIN 7

#define GREEN_LED_ALL_HIGH 0xFF

//SemaphoreHandle_t xSemaphoreTask1And3 = NULL;
bool isMoving = true;
bool isBTConnected = true;

void digitalWriteGreenLeds(unsigned char greenLedOutput) {
	digitalWrite(GREEN_LED_LATCH_PIN, LOW);
	shiftOut(GREEN_LED_DATA_PIN, GREEN_LED_CLOCK_PIN, MSBFIRST, greenLedOutput);
	digitalWrite(GREEN_LED_LATCH_PIN, HIGH);
	return;
}

void taskGreenLed(void *p) {
	// Wait till is BT Connected;
	// Flash 2 times:
	TickType_t lastTick = xTaskGetTickCount();
	for (int i = 0; i < 3; i++) {
		digitalWriteGreenLeds(~GREEN_LED_ALL_HIGH);
		vTaskDelayUntil(&lastTick, 250);
		digitalWriteGreenLeds(GREEN_LED_ALL_HIGH);
		if (i != 2) {
			vTaskDelayUntil(&lastTick, 250);
		}
	}
	// Start loop
	int j = 0;	// run from 0 to 13
	while (1) {
		lastTick = xTaskGetTickCount();
		if (!isMoving) {
			digitalWriteGreenLeds(GREEN_LED_ALL_HIGH);
			vTaskDelayUntil(&lastTick, 125); // Wait till new data
		} else {
			int led_to_light;	// run from 0 to 7 to 0
			if (j < 7) {
				// forward running led
				led_to_light = j;
			} else {
				// backward running led
				led_to_light = 14 - j;
			}
			digitalWriteGreenLeds(1 << led_to_light);
			j++;
			if (j >= 14) {
				j = 0;
			}
			vTaskDelayUntil(&lastTick, 125);
		}
	}
}

void taskRedLed(void *p) {
	TickType_t lastTick = 0;
	unsigned char redLedOutput = LOW;
	unsigned char redClkDiv2 = 0;
	while (1) {
		redClkDiv2 = !redClkDiv2;
		if (!isMoving) {
			redLedOutput = !redLedOutput;
		} else {
			if (redClkDiv2 == 0) {
				redLedOutput = !redLedOutput;
			}
		}
		digitalWrite(RED_LED_PIN, redLedOutput);
		vTaskDelayUntil(&lastTick, 250);
	}
}

void setup() {
	pinMode(GREEN_LED_DATA_PIN, OUTPUT);
	pinMode(GREEN_LED_LATCH_PIN, OUTPUT);
	pinMode(GREEN_LED_CLOCK_PIN, OUTPUT);
	pinMode(RED_LED_PIN, OUTPUT);

	digitalWriteGreenLeds(GREEN_LED_ALL_HIGH);

//    xSemaphoreTask1And3 = xSemaphoreCreateMutex();
//    xSemaphoreGive(xSemaphoreTask1And3);

    xTaskCreate(taskGreenLed, "Green LED Task", STACK_SIZE, NULL, 3, NULL);
    xTaskCreate(taskRedLed, "Red Led Task", STACK_SIZE, NULL, 2, NULL);
//    xTaskCreate(task3, "task 3", STACK_SIZE, NULL, 1, NULL);

    vTaskStartScheduler();
}

void loop() {

}
