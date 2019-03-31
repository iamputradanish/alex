#include <Arduino.h>
#include <avr/io.h>
#include <FreeRTOS.h>
#include <task.h>
#include <queue.h>
#include <semphr.h>

#define STACK_SIZE 200
#define QUEUE_SIZE 10
#define TICK_TO_WAIT 10

typedef enum dir {
	STOP,
	FORWARD,
	BACKWARD,
	LEFT,
	RIGHT,
	LEFT_FORWARD,
	RIGHT_FORWARD,
	LEFT_BACKWARD,
	RIGHT_BACKWARD,
} dir;

// Motor control pins
#define PA1   11
#define PA2   10
#define P2B   6
#define P1B   5

// Ensure that percent is between 0 and 100
double checkPercent(double percent) {
	if (percent < 0.0)
		return 0.0;
	else if (percent > 100.0)
		return 100.0;
	else
		return percent;
}

// Get PWM value based on percentage
int getPWMValue(double percent) {
	return (int) (percent / 100.0 * 255.0);
}

// Move Alex motors
// A is right motor, B is left motor
// 1 is forward, 2 is backward
void move(double percentA, double percentB, int direction) {
	int valA = getPWMValue(checkPercent(percentA));
	int valB = getPWMValue(checkPercent(percentB));

	// Forward and reverse values for motors 1 and 2
	int A1Val, A2Val, B1Val, B2Val;

	switch (direction) {
	case FORWARD:
		A1Val = valA;
		A2Val = 0;

		B2Val = 0;
		B1Val = valB;

		break;

	case BACKWARD:
		A1Val = 0;
		A2Val = valA;

		B2Val = valB;
		B1Val = 0;

		break;

	case LEFT:
		A1Val = valA;
		A2Val = 0;

		B2Val = 0;
		B1Val = valB;

		break;

	case RIGHT:
		A1Val = valA;
		A2Val = 0;

		B2Val = 0;
		B1Val = valB;

		break;

	case LEFT_FORWARD:
		A1Val = valA;
		A2Val = 0;

		B2Val = 0;
		B1Val = valB;

		break;

	case RIGHT_FORWARD:
		A1Val = valA;
		A2Val = 0;

		B2Val = 0;
		B1Val = valB;

		break;

	case LEFT_BACKWARD:
		A1Val = 0;
		A2Val = valA;

		B2Val = valB;
		B1Val = 0;

		break;

	case RIGHT_BACKWARD:
		A1Val = 0;
		A2Val = valA;

		B2Val = valB;
		B1Val = 0;

		break;

	case STOP:
	default:
		A1Val = 0;
		A2Val = 0;

		B2Val = 0;
		B1Val = 0;

		break;

	}

	analogWrite(PA1, A1Val);
	analogWrite(PA2, A2Val);
	analogWrite(P1B, B1Val);
	analogWrite(P2B, B2Val);
}

void forward() {
	move(50.0, 50.0, FORWARD);
}

void backward() {
	move(50.0, 50.0, BACKWARD);
}

void left() {
	move(75.0, 0, LEFT);
}

void right() {
	move(25.0, 75.0, RIGHT);
}

void leftForward() {
	move(75.0, 25.0, LEFT_FORWARD);
}

void rightForward() {
	move(25.0, 75.0, RIGHT_FORWARD);
}

void leftBackward() {
	move(75.0, 25.0, LEFT_BACKWARD);
}

void rightBackward() {
	move(25.0, 75.0, RIGHT_BACKWARD);
}

void stop() {
	move(0.0, 0.0, STOP);
}

#define N 200
#define STACK_SIZE 200

SemaphoreHandle_t interrupt = xSemaphoreCreateMutex();
QueueHandle_t xQueue;
SemaphoreHandle_t xSemaphoreMotor = xSemaphoreCreateMutex();
//Parse the bluetooth signal to which function
void moveByInstructionTask(void *p) {
	while (1) {
		char signal;
		if (xQueueReceive(xQueue, &signal, portMAX_DELAY) == pdTRUE) {
			switch (signal) {
			case 50: //Connected
				Serial.println("connected");
				break;
			case 12: // FORWARD
				Serial.println("forwar");
				forward();
				break;
			case 32: // BACKWARD
				Serial.println("backwar");
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
				Serial.println("stop");
				stop();
				break;
			}
		}
		vTaskDelay(100);
	}

}

void bluetoothEnqueueData(void *p) {
	while (1) {
		if (Serial.available()) {
			// read potentiometer's value
			char signal = Serial.read();
			xQueueSendToBack(xQueue, &signal, portMAX_DELAY);
			vTaskDelay(1);
		}
	}
}
/*
 void setBaud(unsigned long baudRate) {
 unsigned int b;
 b = (unsigned int) round(F_CPU / (16.0 * baudRate)) - 1;
 UBRR0H = (unsigned char) (b >> 8);
 UBRR0L = (unsigned char) b;
 }

 void setupUART() {
 UBRR0L = 103;
 UBRR0H = 0;
 UCSR0C = 0b00000110;
 UCSR0A = 0;
 }

 void startUART() {
 UCSR0B = 0b00011000;
 }

 ISR(USART_RX_vect) {
 BaseType_t xHigherPriorityTaskWoken = pdFALSE;
 char val = UDR0;
 xQueueSendToBackFromISR(xQueue, &val, &xHigherPriorityTaskWoken);
 //taskYIELD();
 }*/

//Set up bluetooth device
void SerialEvent() {
}

void setup() {

	Serial.begin(9600);
	//Serial.println("Compile and upload");

	xQueue = xQueueCreate(N, sizeof(char));

}

void loop() {
	xTaskCreate(moveByInstructionTask, "moveByInstructionTask", STACK_SIZE,
			NULL, 2, NULL);
	xTaskCreate(bluetoothEnqueueData, "bluetoothTask", STACK_SIZE, NULL, 1,
			NULL);
	vTaskStartScheduler();
}

