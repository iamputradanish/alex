#include <Arduino.h>
#include <avr/io.h>
#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>
#include <timers.h>
#include <semphr.h>
#include <robotlib.h>

#define N 200
#define STACK_SIZE 200

SemaphoreHandle_t interrupt =  xSemaphoreCreateMutex();
QueueHandle_t xQueue;
SemaphoreHandle_t xSemaphoreMotor = xSemaphoreCreateMutex();
//Parse the bluetooth signal to which function
void moveByInstructionTask(void *p) {
	while (1) {
		char signal;
		xQueueReceive(xQueue, &signal, portMAX_DELAY);
		switch (signal) {
		case 12: // FORWARD
			forward();
			break;
		case 32: // BACKWARD
			backward();
			break;
		case 13: // RIGHT FORWARD
			rightForward();
			break;
		case 11: // LEFT FORWARD
			leftForward();
			break;
		case 33: // RIGHT BACKWARD
			rightBackward();
			break;
		case 31: // LEFT BACKWARD
			leftBackward();
			break;
		case 21: // LEFT
			left();
			break;
		case 23: //RIGHT
			right();
			break;
		default:
			stop();
			break;
		}

	}

}

void bluetoothEnqueueData(void *p) {
	while (1) {
		if (xSemaphoreTake(interrupt, 5) == pdTRUE) {
			// read potentiometer's value
			char signal = UDR0;
			xQueueSendToBack(xQueue, &signal, 10);
			vTaskDelay(1);
		}
	}
}

ISR(USART_RX_vect) {
	BaseType_t xHigherPriorityTaskWoken = pdFALSE;
	xSemaphoreGiveFromISR(interrupt, &xHigherPriorityTaskWoken);
	taskYIELD();
}


//Set up bluetooth device
void setup() {
	UBRR0 = 103; // for configuring baud rate of 9600bps
	UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00);
// Use 8-bit character sizes
	UCSR0B |= (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0);
// Turn on the transmission, reception, and Receive interrupt
	sei();
	// enable global interrupt



	xQueue = xQueueCreate(N, sizeof(int));

}

void loop () {
	xTaskCreate(moveByInstructionTask, "moveByInstructionTask", STACK_SIZE, NULL, 2, NULL);
	xTaskCreate(bluetoothEnqueueData, "bluetoothEnqueueData", STACK_SIZE, NULL, 1, NULL);
	vTaskStartScheduler();
}
