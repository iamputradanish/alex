//#include <Arduino.h>
//#include <math.h>
//#include <avr/io.h>
//#include <FreeRTOS.h>
//#include <task.h>
//#include <semphr.h>
//
///*----------CONSTANTS----------*/
//// FreeRTOS constants
//#define STACK_SIZE 100
//#define QUEUE_SIZE 10
//
//// Task constants
//#define BLUETOOTHTASK_PERIOD 40
//#define RECEIVE_DATA_DEADLINE 20
//#define GREENLEDBLUETOOTH_DELAY 250
//#define GREENLEDMOVING_DELAY 100
//#define REDLEDSTATIONARY_DELAY 250
//#define REDLEDMOVING_DELAY 500
//
//// IO pins constants
//#define GREEN_LED_DATA_PIN 2
//#define GREEN_LED_LATCH_PIN 3
//#define GREEN_LED_CLOCK_PIN 4
//#define RED_LED_PIN 7
//#define MOTOR_A1_PIN 10
//#define MOTOR_A2_PIN 9
//#define MOTOR_B1_PIN 5
//#define MOTOR_B2_PIN 6
//#define BUZZER_PIN 12
//
//// Led constants
//#define NUMBER_OF_FLASH 2
//#define GREEN_LED_ALL_HIGH 0xFF
//#define GREEN_LED_ALL_LOW 0x00
//
//// Music note duration constant
//#define TEMPO 3200
//
//// Music note frequency constants
//#define B6NOTE 1976
//#define B7NOTE 3951
//#define CNOTE 2093
//#define DNOTE 2349
//#define ENOTE 2637
//#define FSNOTE 2960
//#define GNOTE 3136
//#define ANOTE 3520
//
//typedef enum data_t {
//	BLUETOOTH_CONNECTED = 111,
//	BEGIN_CHALLENGE = 112,
//	END_CHALLENGE = 113,
//	STOP = 114,
//	MOVING = 115
//} data_t;
//
//// Note delay time
//const TickType_t xTempo = (TEMPO/portTICK_PERIOD_MS);
//const TickType_t xHalf  = ((TEMPO/2)/portTICK_PERIOD_MS);
//const TickType_t xQuarter = ((TEMPO/4)/portTICK_PERIOD_MS);
//const TickType_t xThird = ((TEMPO/3)/portTICK_PERIOD_MS);
//const TickType_t xEigth = ((TEMPO/8)/portTICK_PERIOD_MS);
//
///*----------FreeRTOS Handlers-----------*/
//// Task handler
//TaskHandle_t th_babyshark;
//TaskHandle_t th_endmusic;
//
//// Queue handler
//QueueHandle_t q_buzzerdata;
//QueueHandle_t q_greenleddata;
//QueueHandle_t q_redleddata;
//QueueHandle_t q_motordata;
//
///*----------FUNCTIONS----------*/
///***** Set up Serial for BlueTooth *****/
//// Declared only to make Serial.available() usable
//void SerialEvent() {
//	// Empty
//}
//
///***** Combine two 8-bit into a 16-bit data *****/
//int convert_8_bit_into_16_bit(signed char x, signed char y) {
//	int data = 0x00;
//	data |= x;
//	data = data << 8;
//	data |= y;
//	return data;
//}
//
///***** Split a 16-bit into two 8-bit data *****/
//void convert_16_bit_into_8_bit(signed char* x, signed char* y, int data) {
//	*x = 0x0;
//	*y = 0x0;
//	*x |= (data >> 8);
//	*y |= data;
//	return;
//}
//
///***** Cap the percentage value *****/
//double checkPercent(double percent) {
//	if (percent < 0.0)
//		return 0.0;
//	else if (percent > 100.0)
//		return 100.0;
//	else
//		return percent;
//}
//
///***** Convert duty cycle to analogWrite value *****/
//int getPWMValue(double percent) {
//	return (int) (percent / 100.0 * 255.0);
//}
//
///***** Move motor based on duty cycle *****/
//void move(double percentL, double percentR) {
//	int valA = getPWMValue(checkPercent(fabs(percentR)));
//	int valB = getPWMValue(checkPercent(fabs(percentL)));
//	if (percentR >= 0) {
//		analogWrite(MOTOR_A1_PIN, valA);
//		analogWrite(MOTOR_A2_PIN, 0);
//	} else {
//		analogWrite(MOTOR_A1_PIN, 0);
//		analogWrite(MOTOR_A2_PIN, valA);
//	}
//	if (percentL >= 0) {
//		analogWrite(MOTOR_B1_PIN, valB);
//		analogWrite(MOTOR_B2_PIN, 0);
//	} else {
//		analogWrite(MOTOR_B1_PIN, 0);
//		analogWrite(MOTOR_B2_PIN, valB);
//	}
//}
//
///***** Move motor based on analog value *****/
//void moveAnalog (int l, int r) {
//	int valA = abs(r);
//	int valB = abs(l);
//	if (r >= 0) {
//		analogWrite(MOTOR_A1_PIN, valA);
//		analogWrite(MOTOR_A2_PIN, 0);
//	} else {
//		analogWrite(MOTOR_A1_PIN, 0);
//		analogWrite(MOTOR_A2_PIN, valA);
//	}
//	if (l >= 0) {
//		analogWrite(MOTOR_B1_PIN, valB);
//		analogWrite(MOTOR_B2_PIN, 0);
//	} else {
//		analogWrite(MOTOR_B1_PIN, 0);
//		analogWrite(MOTOR_B2_PIN, valB);
//	}
//}
//
///***** Green LED control *****/
//void digitalWriteGreenLeds(char greenLedOutput) {
//	digitalWrite(GREEN_LED_LATCH_PIN, LOW);
//	shiftOut(GREEN_LED_DATA_PIN, GREEN_LED_CLOCK_PIN, MSBFIRST, greenLedOutput);
//	digitalWrite(GREEN_LED_LATCH_PIN, HIGH);
//	return;
//}
//
//void greenLedBlueToothFlash() {
//	TickType_t xLastWakeTime = xTaskGetTickCount();
//	for (int i = 0; i <= NUMBER_OF_FLASH; i++) {
//		digitalWriteGreenLeds(GREEN_LED_ALL_LOW);
//		vTaskDelayUntil(&xLastWakeTime, GREENLEDBLUETOOTH_DELAY);
//		digitalWriteGreenLeds(GREEN_LED_ALL_HIGH);
//		if (i != NUMBER_OF_FLASH) {
//			vTaskDelayUntil(&xLastWakeTime, GREENLEDBLUETOOTH_DELAY);
//		}
//	}
//}
//
///***** BabyShark song *****/
//void babysharkdoo(){
//	TickType_t xLastWakeTime = xTaskGetTickCount();
//	//D-E G GG  GG  GG
//	tone(BUZZER_PIN,DNOTE); //D
//	vTaskDelayUntil(&xLastWakeTime, xHalf);
//	tone(BUZZER_PIN,ENOTE); //E
//	vTaskDelayUntil(&xLastWakeTime, xHalf);
//	noTone(BUZZER_PIN);
//	vTaskDelayUntil(&xLastWakeTime, xQuarter);
//
//	tone(BUZZER_PIN,GNOTE); //G
//	vTaskDelayUntil(&xLastWakeTime, xEigth);
//	noTone(BUZZER_PIN);
//	vTaskDelayUntil(&xLastWakeTime, xHalf);
//
//	tone(BUZZER_PIN,GNOTE); //G
//	vTaskDelayUntil(&xLastWakeTime, xEigth);
//	noTone(BUZZER_PIN);
//	vTaskDelayUntil(&xLastWakeTime, xHalf);
//	tone(BUZZER_PIN,GNOTE); //G
//	vTaskDelayUntil(&xLastWakeTime, xEigth);
//	noTone(BUZZER_PIN);
//	vTaskDelayUntil(&xLastWakeTime, xThird);
//
//	tone(BUZZER_PIN,GNOTE); //G
//	vTaskDelayUntil(&xLastWakeTime, xEigth);
//	noTone(BUZZER_PIN);
//	vTaskDelayUntil(&xLastWakeTime, xQuarter);
//	tone(BUZZER_PIN,GNOTE); //G
//	vTaskDelayUntil(&xLastWakeTime, xQuarter);
//	noTone(BUZZER_PIN);
//	vTaskDelayUntil(&xLastWakeTime, xQuarter);
//
//	tone(BUZZER_PIN,GNOTE); //G
//	vTaskDelayUntil(&xLastWakeTime, xEigth);
//	noTone(BUZZER_PIN);
//	vTaskDelayUntil(&xLastWakeTime, xThird);
//	tone(BUZZER_PIN,GNOTE); //G
//	vTaskDelayUntil(&xLastWakeTime, xEigth);
//	noTone(BUZZER_PIN);
//	vTaskDelayUntil(&xLastWakeTime, xThird);
//}
//
//void babyshark(){
//	TickType_t xLastWakeTime = xTaskGetTickCount();
//
//	tone(BUZZER_PIN,GNOTE); //G
//	vTaskDelayUntil(&xLastWakeTime, xEigth);
//	noTone(BUZZER_PIN);
//	vTaskDelayUntil(&xLastWakeTime, xHalf);
//	tone(BUZZER_PIN,GNOTE); //G
//	vTaskDelayUntil(&xLastWakeTime, xEigth);
//	noTone(BUZZER_PIN);
//	vTaskDelayUntil(&xLastWakeTime, xHalf);
//
//	tone(BUZZER_PIN,FSNOTE); //F#
//	vTaskDelayUntil(&xLastWakeTime, xEigth);
//	noTone(BUZZER_PIN);
//	vTaskDelayUntil(&xLastWakeTime, xTempo);
//	vTaskDelayUntil(&xLastWakeTime, xTempo);
//}
//
///***** BlueTooth connection song *****/
//void bluetoothconnectedtone() {
//	TickType_t xLastWakeTime = xTaskGetTickCount();
//	//C D E
//	tone(BUZZER_PIN,CNOTE); //C
//	vTaskDelayUntil(&xLastWakeTime, xHalf);
//	tone(BUZZER_PIN,DNOTE); //D
//	vTaskDelayUntil(&xLastWakeTime, xHalf);
//	tone(BUZZER_PIN,ENOTE); //E
//	vTaskDelayUntil(&xLastWakeTime, xHalf);
//	noTone(BUZZER_PIN);
//}
//
///***** End challenge song *****/
//void theboywholived() {
//	TickType_t xLastWakeTime = xTaskGetTickCount();
//	//  B E G F# E B A F#
//	noTone(BUZZER_PIN);
//	vTaskDelayUntil(&xLastWakeTime, xTempo);
//	vTaskDelayUntil(&xLastWakeTime, xTempo);
//	tone(BUZZER_PIN,B6NOTE); //B
//	vTaskDelayUntil(&xLastWakeTime, xTempo);
//
//	tone(BUZZER_PIN,ENOTE); //E
//	vTaskDelayUntil(&xLastWakeTime, xTempo);
//	vTaskDelayUntil(&xLastWakeTime, xHalf);
//	tone(BUZZER_PIN,GNOTE); //G
//	vTaskDelayUntil(&xLastWakeTime, xHalf);
//	tone(BUZZER_PIN,FSNOTE); //F#
//	vTaskDelayUntil(&xLastWakeTime, xTempo);
//
//	tone(BUZZER_PIN,ENOTE); //E
//	vTaskDelayUntil(&xLastWakeTime, xTempo);
//	vTaskDelayUntil(&xLastWakeTime, xTempo);
//
//	tone(BUZZER_PIN,B7NOTE); //B
//	vTaskDelayUntil(&xLastWakeTime, xTempo);
//
//	tone(BUZZER_PIN,ANOTE); //A
//	vTaskDelayUntil(&xLastWakeTime, xTempo);
//	vTaskDelayUntil(&xLastWakeTime, xTempo);
//	vTaskDelayUntil(&xLastWakeTime, xTempo);
//
//	tone(BUZZER_PIN,FSNOTE); //F#
//	vTaskDelayUntil(&xLastWakeTime, xTempo);
//	vTaskDelayUntil(&xLastWakeTime, xTempo);
//	noTone(BUZZER_PIN);
//	vTaskDelayUntil(&xLastWakeTime, xTempo);
//
//	//E G F# Eb E B
//	tone(BUZZER_PIN,ENOTE); //E
//	vTaskDelayUntil(&xLastWakeTime, xTempo);
//	vTaskDelayUntil(&xLastWakeTime, xHalf);
//	tone(BUZZER_PIN,GNOTE); //G
//	vTaskDelayUntil(&xLastWakeTime, xHalf);
//	tone(BUZZER_PIN,FSNOTE); //F#
//	vTaskDelayUntil(&xLastWakeTime, xTempo);
//
//	tone(BUZZER_PIN,2489); //D#
//	vTaskDelayUntil(&xLastWakeTime, xTempo);
//	vTaskDelayUntil(&xLastWakeTime, xTempo);
//	tone(BUZZER_PIN,2489); //Eb/D#
//	vTaskDelayUntil(&xLastWakeTime, xTempo);
//	tone(BUZZER_PIN,B7NOTE); //B
//	vTaskDelayUntil(&xLastWakeTime, xTempo);
//	vTaskDelayUntil(&xLastWakeTime, xTempo);
//	vTaskDelayUntil(&xLastWakeTime, xTempo);
//
//	noTone(BUZZER_PIN);
//	vTaskDelayUntil(&xLastWakeTime, xTempo);
//	vTaskDelayUntil(&xLastWakeTime, xTempo);
//}
//
///*----------TASKS----------*/
///***** BlueTooth Task *****/
//void blueToothTask(void *p) {
//	TickType_t xLastWakeTime = 0;
//	signed char signal;
//	signed char temp;
//	int motor_data;
//	while (1) {
//		if (Serial.available()) {
//			// read potentiometer's value
//			signal = Serial.read();
//			// Serial.println(signal);
//			switch (signal) {
//			case BLUETOOTH_CONNECTED:
//				xQueueReceive(q_greenleddata, &temp, 0);
//				xQueueSendToBack(q_greenleddata, &signal, 0);
//				xQueueReceive(q_buzzerdata, &temp, 0);
//				xQueueSendToBack(q_buzzerdata, &signal, 0);
//				break;
//			case BEGIN_CHALLENGE:
//			case END_CHALLENGE:
//				xQueueReceive(q_buzzerdata, &temp, 0);
//				xQueueSendToBack(q_buzzerdata, &signal, 0);
//				break;
//			case STOP:
//				motor_data = 0x00;
//				xQueueReceive(q_motordata, &temp, 0);
//				xQueueSendToBack(q_motordata, &motor_data, 0);
//				xQueueReceive(q_greenleddata, &temp, 0);
//				xQueueSendToBack(q_greenleddata, &signal, 0);
//				xQueueReceive(q_redleddata, &temp, 0);
//				xQueueSendToBack(q_redleddata, &signal, 0);
//				break;
//			case MOVING:
//				// Receive 2 more byte for motor data
//				TickType_t timer = xTaskGetTickCount();
//				TickType_t deadline = xTaskGetTickCount() + RECEIVE_DATA_DEADLINE;
//				while ((!Serial.available()) && (timer < deadline)) {
//					timer = xTaskGetTickCount();
//				}
//				if (Serial.available()) {
//					signed char x = Serial.read();
//					while ((!Serial.available()) && (timer < deadline)) {
//						timer = xTaskGetTickCount();
//					}
//					if (Serial.available()) {
//						signed char y = Serial.read();
//						motor_data = convert_8_bit_into_16_bit(x, y);
//						if (motor_data == 0x00) {
//							signal = STOP;
//						}
//						xQueueReceive(q_motordata, &temp, 0);
//						xQueueSendToBack(q_motordata, &motor_data, 0);
//						xQueueReceive(q_greenleddata, &temp, 0);
//						xQueueSendToBack(q_greenleddata, &signal, 0);
//						xQueueReceive(q_redleddata, &temp, 0);
//						xQueueSendToBack(q_redleddata, &signal, 0);
//					}
//				}
//				break;
//			}
//		}
//		vTaskDelayUntil(&xLastWakeTime, BLUETOOTHTASK_PERIOD);
//	}
//}
//
///***** Motor Task *****/
//void motorTask(void *p) {
//	int data = 0x00;
//	signed char x, y;
//	double l = 0;
//	double r = 0;
//	move(0.0, 0.0);
//	while (1) {
//		// Wait for data from blueTooth task
//		xQueueReceive(q_motordata, &data, portMAX_DELAY);
//		convert_16_bit_into_8_bit(&x, &y, data);
//		if (y == 0) {
//			l = x;
//			r = (-1) * x;
//		} else if (x >= 0) {
//			l = y;
//			if (y > 0) {
//				r = (((double) (y - x)) / (y + x)) * y;
//			} else if (y < 0) {
//				r = (((double) (y + x)) / (y - x)) * y;
//			}
//		} else if (x < 0) {
//			r = y;
//			if (y > 0) {
//				l = (((double) (y + x)) / (y - x)) * y;
//			} else if (y < 0) {
//				l = (((double) (y - x)) / (y + x)) * y;
//			}
//		}
//		move(l, r);
//	}
//}
//
///***** Led Tasks *****/
//void greenLedTask(void *p) {
//	signed char data = STOP;
//	bool isMoving = false;
//	char output = GREEN_LED_ALL_HIGH;
//	int i = 0; // loop from 0 to 13 and repeat
//	int ledToLight;
//	TickType_t xLastWakeTime;
//	digitalWriteGreenLeds(GREEN_LED_ALL_HIGH);
//	// BlueTooth Flash
//	while (data != BLUETOOTH_CONNECTED) {
//		// Wait for data from blueTooth task
//		xQueueReceive(q_greenleddata, &data, portMAX_DELAY);
//		if (data == BLUETOOTH_CONNECTED) {
//			greenLedBlueToothFlash();
//		}
//	}
//	// Green Led Control
//	xLastWakeTime = xTaskGetTickCount();
//	while (1) {
//		if (xQueueReceive(q_greenleddata, &data, 0) == pdTRUE) {
//			switch (data) {
//			case MOVING:
//				isMoving = true;
//				break;
//			case STOP:
//				isMoving = false;
//				break;
//			}
//		}
//		if (isMoving) {
//			if (i < 7) {
//				ledToLight = i;			// forward running led
//			} else {
//				ledToLight = 14 - i;	// backward running led
//			}
//			output = 1 << ledToLight;
//		} else {
//			output = GREEN_LED_ALL_HIGH;
//		}
//		i++;
//		if (i >= 14) {
//			i = 0;
//		}
//		digitalWriteGreenLeds(output);
//		vTaskDelayUntil(&xLastWakeTime, GREENLEDMOVING_DELAY);
//	}
//}
//
//void redLedTask(void *p) {
//	TickType_t xLastWakeTime = 0;
//	signed char data = STOP;
//	bool isMoving = false;
//	int prevOutput = LOW;
//	int output = LOW;
//	while (1) {
//		if (xQueueReceive(q_redleddata, &data, 0) == pdTRUE) {
//			switch (data) {
//			case MOVING:
//				isMoving = true;
//				break;
//			case STOP:
//				isMoving = false;
//				break;
//			}
//		}
//		if (isMoving) {
//			if (prevOutput == output) {
//				// last 500ms has the same output => toggle
//				output = !output;
//			} else {
//				prevOutput = output;
//			}
//		} else {
//			// toggle every 250ms
//			prevOutput = output;
//			output = !output;
//		}
//		digitalWrite(RED_LED_PIN, output);
//		vTaskDelayUntil(&xLastWakeTime, REDLEDSTATIONARY_DELAY);
//	}
//}
//
///***** Audio Tasks *****/
//// Buzzer tasks controller
//void buzzerTask(void *p) {
//	signed char data = STOP;
//	noTone(BUZZER_PIN);
//	// BlueTooth Tone
//	while (data != BLUETOOTH_CONNECTED) {
//		// Wait for data from blueTooth task
//		xQueueReceive(q_buzzerdata, &data, portMAX_DELAY);
//		if (data == BLUETOOTH_CONNECTED) {
//			bluetoothconnectedtone();
//		}
//	}
//	// Control challenge music tasks
//	while (1) {
//		// Wait for data from blueTooth task
//		xQueueReceive(q_buzzerdata, &data, portMAX_DELAY);
//		switch (data) {
//		case BEGIN_CHALLENGE:
//			noTone(BUZZER_PIN);
//			vTaskSuspend(th_endmusic);
//			vTaskResume(th_babyshark);
//			break;
//		case END_CHALLENGE:
//			noTone(BUZZER_PIN);
//			vTaskSuspend(th_babyshark);
//			vTaskResume(th_endmusic);
//			break;
//		}
//	}
//}
//
//// Run during challenge
//void babySharkMusicTask(void *p) {
//	// Suspend until buzzerTask give control
//	vTaskSuspend(NULL);
//	while (1) {
//		TickType_t xLastWakeTime = xTaskGetTickCount();
//		babysharkdoo();
//		vTaskDelayUntil(&xLastWakeTime, xQuarter);
//		babysharkdoo();
//		vTaskDelayUntil(&xLastWakeTime, xQuarter);
//		babysharkdoo();
//		babyshark();
//	}
//}
//
//// Run when challenge ends
//void endChallengeMusicTask(void *p) {
//	// Suspend until buzzerTask give control
//	vTaskSuspend(NULL);
//	while (1) {
//		theboywholived();
//	}
//}
//
///*----------MAIN----------*/
///***** Setup *****/
//void setup() {
//	pinMode(GREEN_LED_DATA_PIN, OUTPUT);
//	pinMode(GREEN_LED_LATCH_PIN, OUTPUT);
//	pinMode(GREEN_LED_CLOCK_PIN, OUTPUT);
//	pinMode(RED_LED_PIN, OUTPUT);
//	pinMode(MOTOR_A1_PIN, OUTPUT);
//	pinMode(MOTOR_A2_PIN, OUTPUT);
//	pinMode(MOTOR_B1_PIN, OUTPUT);
//	pinMode(MOTOR_B2_PIN, OUTPUT);
//	pinMode(BUZZER_PIN,OUTPUT);
//
//	Serial.begin(9600);
//
//	q_buzzerdata = xQueueCreate(QUEUE_SIZE, sizeof(signed char));
//	q_greenleddata = xQueueCreate(QUEUE_SIZE, sizeof(signed char));
//	q_redleddata = xQueueCreate(QUEUE_SIZE, sizeof(signed char));
//	q_motordata = xQueueCreate(QUEUE_SIZE, sizeof(int));
//}
//
///***** Loop *****/
//void loop() {
//	xTaskCreate(blueToothTask, "BlueToothTask", STACK_SIZE, NULL, 6, NULL);
//	xTaskCreate(motorTask, "Motor", STACK_SIZE, NULL, 5, NULL);
//	xTaskCreate(greenLedTask, "GreenLed", STACK_SIZE, NULL, 4, NULL);
//	xTaskCreate(redLedTask, "RedLed", STACK_SIZE, NULL, 2, NULL);
//	xTaskCreate(buzzerTask, "Buzzer", STACK_SIZE, NULL, 3, NULL);
//	xTaskCreate(babySharkMusicTask, "RunningBuzzer", STACK_SIZE, NULL, 1, &th_babyshark);
//	xTaskCreate(endChallengeMusicTask, "EndBuzzer", STACK_SIZE, NULL, 1, &th_endmusic);
//
//	vTaskStartScheduler();
//}
