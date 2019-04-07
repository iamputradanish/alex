#include <Arduino.h>
#include <math.h>
#include <avr/io.h>
#include <FreeRTOS.h>
#include <task.h>
#include <semphr.h>

/*----------CONSTANTS----------*/
// FreeRTOS constants
#define STACK_SIZE 100
#define QUEUE_SIZE 10

// Task constants
#define BLUETOOTHTASK_PERIOD 40
#define GREENLEDBLUETOOTH_DELAY 250
#define GREENLEDMOVING_DELAY 100
#define REDLEDSTATIONARY_DELAY 250
#define REDLEDMOVING_DELAY 500

// IO pins constants
#define GREEN_LED_DATA_PIN 2
#define GREEN_LED_LATCH_PIN 3
#define GREEN_LED_CLOCK_PIN 4
#define RED_LED_PIN 7
#define MOTOR_A1_PIN 10
#define MOTOR_A2_PIN 9
#define MOTOR_B1_PIN 5
#define MOTOR_B2_PIN 6
#define BUZZER_PIN 12

/*
// Data constants
#define BLUETOOTH_CONNECTED 50
#define BEGIN_CHALLENGE 1
#define END_CHALLENGE 2
#define STOP 0
#define FORWARD 12
#define BACKWARD 32
#define RIGHT_FORWARD 13
#define LEFT_FORWARD 11
#define RIGHT_BACKWARD 33
#define LEFT_BACKWARD 31
#define LEFT 21
#define RIGHT 23
*/

// Led constants
#define NUMBER_OF_FLASH 2
#define GREEN_LED_ALL_HIGH 0xFF
#define GREEN_LED_ALL_LOW 0x00

// Music note duration constant
#define TEMPO 3200

// Music note frequency constants
#define B6NOTE 1976
#define B7NOTE 3951
#define CNOTE 2093
#define DNOTE 2349
#define ENOTE 2637
#define FSNOTE 2960
#define GNOTE 3136
#define ANOTE 3520

typedef enum data_t {
	BLUETOOTH_CONNECTED = 50,
	BEGIN_CHALLENGE = 1,
	END_CHALLENGE = 2,
	STOP = 0,
	FORWARD = 12,
	BACKWARD = 32,
	LEFT = 21,
	RIGHT = 23,
	LEFT_FORWARD = 11,
	RIGHT_FORWARD = 13,
	LEFT_BACKWARD = 31,
	RIGHT_BACKWARD = 33,
} data_t;

// Note delay time
const TickType_t xTempo = (TEMPO/portTICK_PERIOD_MS);
const TickType_t xHalf  = ((TEMPO/2)/portTICK_PERIOD_MS);
const TickType_t xQuarter = ((TEMPO/4)/portTICK_PERIOD_MS);
const TickType_t xThird = ((TEMPO/3)/portTICK_PERIOD_MS);
const TickType_t xEigth = ((TEMPO/8)/portTICK_PERIOD_MS);

/*----------FreeRTOS Handlers-----------*/
// Task handler
TaskHandle_t th_bluetooth;
TaskHandle_t th_motor;
TaskHandle_t th_led;
TaskHandle_t th_greenledbluetooth;
TaskHandle_t th_greenledmoving;
TaskHandle_t th_redledstationary;
TaskHandle_t th_redledmoving;
TaskHandle_t th_buzzer;
TaskHandle_t th_bluetmusic;
TaskHandle_t th_babyshark;
TaskHandle_t th_endmusic;

// Queue handler
QueueHandle_t q_buzzerdata;
QueueHandle_t q_leddata;
QueueHandle_t q_motordata;

// Semaphore handler
SemaphoreHandle_t semaphore_buzzer;
SemaphoreHandle_t semaphore_greenled;

/*----------FUNCTIONS----------*/
/***** Set up Serial for BlueTooth *****/
// Declared only to make Serial.available() usable
void SerialEvent() {
	// Empty
}

/***** Cap the percentage value *****/
double checkPercent(double percent) {
	if (percent < 0.0)
		return 0.0;
	else if (percent > 100.0)
		return 100.0;
	else
		return percent;
}

/***** Convert duty cycle to analogWrite value *****/
int getPWMValue(double percent) {
	return (int) (percent / 100.0 * 255.0);
}

/***** Move motor based on duty cycle *****/
void move(double percentL, double percentR) {
	int valA = getPWMValue(checkPercent(fabs(percentR)));
	int valB = getPWMValue(checkPercent(fabs(percentL)));
	if (percentR >= 0) {
		analogWrite(MOTOR_A1_PIN, valA);
		analogWrite(MOTOR_A2_PIN, 0);
	} else {
		analogWrite(MOTOR_A1_PIN, 0);
		analogWrite(MOTOR_A2_PIN, valA);
	}
	if (percentL >= 0) {
		analogWrite(MOTOR_B1_PIN, valB);
		analogWrite(MOTOR_B2_PIN, 0);
	} else {
		analogWrite(MOTOR_B1_PIN, 0);
		analogWrite(MOTOR_B2_PIN, valB);
	}
}

/***** Move motor based on analog value *****/
void moveAnalog (int l, int r) {
	int valA = abs(r);
	int valB = abs(l);
	if (r >= 0) {
		analogWrite(MOTOR_A1_PIN, valA);
		analogWrite(MOTOR_A2_PIN, 0);
	} else {
		analogWrite(MOTOR_A1_PIN, 0);
		analogWrite(MOTOR_A2_PIN, valA);
	}
	if (l >= 0) {
		analogWrite(MOTOR_B1_PIN, valB);
		analogWrite(MOTOR_B2_PIN, 0);
	} else {
		analogWrite(MOTOR_B1_PIN, 0);
		analogWrite(MOTOR_B2_PIN, valB);
	}
}

/***** Green LED control *****/
void digitalWriteGreenLeds(char greenLedOutput) {
	digitalWrite(GREEN_LED_LATCH_PIN, LOW);
	shiftOut(GREEN_LED_DATA_PIN, GREEN_LED_CLOCK_PIN, MSBFIRST, greenLedOutput);
	digitalWrite(GREEN_LED_LATCH_PIN, HIGH);
	return;
}

/***** BabyShark song *****/
void babysharkdoo(){
	TickType_t xLastWakeTime = xTaskGetTickCount();
	//D-E G GG  GG  GG
	tone(BUZZER_PIN,DNOTE); //D
	vTaskDelayUntil(&xLastWakeTime, xHalf);
	tone(BUZZER_PIN,ENOTE); //E
	vTaskDelayUntil(&xLastWakeTime, xHalf);
	noTone(BUZZER_PIN);
	vTaskDelayUntil(&xLastWakeTime, xQuarter);

	tone(BUZZER_PIN,GNOTE); //G
	vTaskDelayUntil(&xLastWakeTime, xEigth);
	noTone(BUZZER_PIN);
	vTaskDelayUntil(&xLastWakeTime, xHalf);

	tone(BUZZER_PIN,GNOTE); //G
	vTaskDelayUntil(&xLastWakeTime, xEigth);
	noTone(BUZZER_PIN);
	vTaskDelayUntil(&xLastWakeTime, xHalf);
	tone(BUZZER_PIN,GNOTE); //G
	vTaskDelayUntil(&xLastWakeTime, xEigth);
	noTone(BUZZER_PIN);
	vTaskDelayUntil(&xLastWakeTime, xThird);

	tone(BUZZER_PIN,GNOTE); //G
	vTaskDelayUntil(&xLastWakeTime, xEigth);
	noTone(BUZZER_PIN);
	vTaskDelayUntil(&xLastWakeTime, xQuarter);
	tone(BUZZER_PIN,GNOTE); //G
	vTaskDelayUntil(&xLastWakeTime, xQuarter);
	noTone(BUZZER_PIN);
	vTaskDelayUntil(&xLastWakeTime, xQuarter);

	tone(BUZZER_PIN,GNOTE); //G
	vTaskDelayUntil(&xLastWakeTime, xEigth);
	noTone(BUZZER_PIN);
	vTaskDelayUntil(&xLastWakeTime, xThird);
	tone(BUZZER_PIN,GNOTE); //G
	vTaskDelayUntil(&xLastWakeTime, xEigth);
	noTone(BUZZER_PIN);
	vTaskDelayUntil(&xLastWakeTime, xThird);
}

void babyshark(){
	TickType_t xLastWakeTime = xTaskGetTickCount();

	tone(BUZZER_PIN,GNOTE); //G
	vTaskDelayUntil(&xLastWakeTime, xEigth);
	noTone(BUZZER_PIN);
	vTaskDelayUntil(&xLastWakeTime, xHalf);
	tone(BUZZER_PIN,GNOTE); //G
	vTaskDelayUntil(&xLastWakeTime, xEigth);
	noTone(BUZZER_PIN);
	vTaskDelayUntil(&xLastWakeTime, xHalf);

	tone(BUZZER_PIN,FSNOTE); //F#
	vTaskDelayUntil(&xLastWakeTime, xEigth);
	noTone(BUZZER_PIN);
	vTaskDelayUntil(&xLastWakeTime, xTempo);
	vTaskDelayUntil(&xLastWakeTime, xTempo);
}

/***** BlueTooth connection song *****/
void bluetoothconnectedtone() {
	TickType_t xLastWakeTime = xTaskGetTickCount();
	//C D E
	tone(BUZZER_PIN,CNOTE); //C
	vTaskDelayUntil(&xLastWakeTime, xHalf);
	tone(BUZZER_PIN,DNOTE); //D
	vTaskDelayUntil(&xLastWakeTime, xHalf);
	tone(BUZZER_PIN,ENOTE); //E
	vTaskDelayUntil(&xLastWakeTime, xHalf);
	noTone(BUZZER_PIN);
}

/***** End challenge song *****/
void theboywholived() {
	TickType_t xLastWakeTime = xTaskGetTickCount();
	//  B E G F# E B A F#
	noTone(BUZZER_PIN);
	vTaskDelayUntil(&xLastWakeTime, xTempo);
	vTaskDelayUntil(&xLastWakeTime, xTempo);
	tone(BUZZER_PIN,B6NOTE); //B
	vTaskDelayUntil(&xLastWakeTime, xTempo);

	tone(BUZZER_PIN,ENOTE); //E
	vTaskDelayUntil(&xLastWakeTime, xTempo);
	vTaskDelayUntil(&xLastWakeTime, xHalf);
	tone(BUZZER_PIN,GNOTE); //G
	vTaskDelayUntil(&xLastWakeTime, xHalf);
	tone(BUZZER_PIN,FSNOTE); //F#
	vTaskDelayUntil(&xLastWakeTime, xTempo);

	tone(BUZZER_PIN,ENOTE); //E
	vTaskDelayUntil(&xLastWakeTime, xTempo);
	vTaskDelayUntil(&xLastWakeTime, xTempo);

	tone(BUZZER_PIN,B7NOTE); //B
	vTaskDelayUntil(&xLastWakeTime, xTempo);

	tone(BUZZER_PIN,ANOTE); //A
	vTaskDelayUntil(&xLastWakeTime, xTempo);
	vTaskDelayUntil(&xLastWakeTime, xTempo);
	vTaskDelayUntil(&xLastWakeTime, xTempo);

	tone(BUZZER_PIN,FSNOTE); //F#
	vTaskDelayUntil(&xLastWakeTime, xTempo);
	vTaskDelayUntil(&xLastWakeTime, xTempo);
	noTone(BUZZER_PIN);
	vTaskDelayUntil(&xLastWakeTime, xTempo);

	//E G F# Eb E B
	tone(BUZZER_PIN,ENOTE); //E
	vTaskDelayUntil(&xLastWakeTime, xTempo);
	vTaskDelayUntil(&xLastWakeTime, xHalf);
	tone(BUZZER_PIN,GNOTE); //G
	vTaskDelayUntil(&xLastWakeTime, xHalf);
	tone(BUZZER_PIN,FSNOTE); //F#
	vTaskDelayUntil(&xLastWakeTime, xTempo);

	tone(BUZZER_PIN,2489); //D#
	vTaskDelayUntil(&xLastWakeTime, xTempo);
	vTaskDelayUntil(&xLastWakeTime, xTempo);
	tone(BUZZER_PIN,2489); //Eb/D#
	vTaskDelayUntil(&xLastWakeTime, xTempo);
	tone(BUZZER_PIN,B7NOTE); //B
	vTaskDelayUntil(&xLastWakeTime, xTempo);
	vTaskDelayUntil(&xLastWakeTime, xTempo);
	vTaskDelayUntil(&xLastWakeTime, xTempo);

	noTone(BUZZER_PIN);
	vTaskDelayUntil(&xLastWakeTime, xTempo);
	vTaskDelayUntil(&xLastWakeTime, xTempo);
}

/*----------TASKS----------*/
/***** BlueTooth Task *****/
void blueToothTask(void *p) {
	TickType_t xLastWakeTime = 0;
	while (1) {
		if (Serial.available()) {
			// read potentiometer's value
			char signal = Serial.read();
			// Serial.println(signal);
			switch (signal) {
			case BLUETOOTH_CONNECTED:
				xQueueSendToBack(q_buzzerdata, &signal, 0);
				xQueueSendToBack(q_leddata, &signal, 0);
				break;
			case BEGIN_CHALLENGE:
			case END_CHALLENGE:
				xQueueSendToBack(q_buzzerdata, &signal, 0);
				break;
			case STOP:
			case FORWARD:
			case LEFT:
			case RIGHT:
			case BACKWARD:
			case LEFT_FORWARD:
			case RIGHT_FORWARD:
			case LEFT_BACKWARD:
			case RIGHT_BACKWARD:
				xQueueSendToBack(q_leddata, &signal, 0);
				xQueueSendToBack(q_motordata, &signal, 0);
				break;
			}
		}
		vTaskDelayUntil(&xLastWakeTime, BLUETOOTHTASK_PERIOD);
	}
}

/***** Motor Task *****/
void motorTask(void *p) {
	char data = STOP;
	move(0.0, 0.0);
	while (1) {
		// Wait for data from blueTooth task
		xQueueReceive(q_motordata, &data, portMAX_DELAY);
		switch (data) {
		case FORWARD:
			move(100.0, 100.0);
			break;
		case BACKWARD:
			move(-100.0, -100.0);
			break;
		case LEFT:
			move(-100.0, 100.0);
			break;
		case RIGHT:
			move(100.0, -100.0);
			break;
		case LEFT_FORWARD:
			move(12.5, 100.0);
			break;
		case RIGHT_FORWARD:
			move(100.0, 12.5);
			break;
		case LEFT_BACKWARD:
			move(-12.5, -100.0);
			break;
		case RIGHT_BACKWARD:
			move(-100.0, -12.5);
			break;
		case STOP:
		default:
			move(0.0, 0.0);
			break;
		}
	}
}

/***** Led Tasks *****/
void ledTask(void *p) {
	char data = STOP;
	digitalWriteGreenLeds(GREEN_LED_ALL_HIGH);
	while (1) {
		// Wait for data from blueTooth task
		xQueueReceive(q_leddata, &data, portMAX_DELAY);
		switch (data) {
		case BLUETOOTH_CONNECTED:
			vTaskResume(th_greenledbluetooth);
			break;
		case STOP:
			vTaskSuspend(th_greenledmoving);
			digitalWriteGreenLeds(GREEN_LED_ALL_HIGH);
			vTaskSuspend(th_redledmoving);
			vTaskResume(th_redledstationary);
			break;
		case FORWARD:
		case LEFT:
		case RIGHT:
		case BACKWARD:
		case LEFT_FORWARD:
		case RIGHT_FORWARD:
		case LEFT_BACKWARD:
		case RIGHT_BACKWARD:
			vTaskResume(th_greenledmoving);
			vTaskSuspend(th_redledstationary);
			vTaskResume(th_redledmoving);
			break;
		}
	}
}

void greenLedBlueToothTask(void *p) {
	vTaskSuspend(NULL);
	// Prevent other green led task from starting until this task is done
	xSemaphoreTake(semaphore_greenled, portMAX_DELAY);
	TickType_t xLastWakeTime = xTaskGetTickCount();
	for (int i = 0; i <= NUMBER_OF_FLASH; i++) {
		digitalWriteGreenLeds(GREEN_LED_ALL_LOW);
		vTaskDelayUntil(&xLastWakeTime, GREENLEDBLUETOOTH_DELAY);
		digitalWriteGreenLeds(GREEN_LED_ALL_HIGH);
		if (i != NUMBER_OF_FLASH) {
			vTaskDelayUntil(&xLastWakeTime, GREENLEDBLUETOOTH_DELAY);
		}
	}
	xSemaphoreGive(semaphore_greenled);
	vTaskSuspend(NULL);
}

void greenLedMovingTask(void *p) {
	vTaskSuspend(NULL);
	TickType_t xLastWakeTime;
	int j = 0;	// run from 0 to 13 and repeat
	// Wait until green led blueTooth flash is done
	xSemaphoreTake(semaphore_greenled, portMAX_DELAY);
	xSemaphoreGive(semaphore_greenled);
	while (1) {
		xLastWakeTime = xTaskGetTickCount();
		int led_to_light;	// run from 0 to 7 to 0
		if (j < 7) {
			led_to_light = j;		// forward running led
		} else {
			led_to_light = 14 - j;	// backward running led
		}
		digitalWriteGreenLeds(1 << led_to_light);
		j++;
		if (j >= 14) {
			j = 0;
		}
		vTaskDelayUntil(&xLastWakeTime, GREENLEDMOVING_DELAY);
	}
}

void redLedStationaryTask(void *p) {
	TickType_t xLastWakeTime;
	while (1) {
		xLastWakeTime = xTaskGetTickCount();
		digitalWrite(RED_LED_PIN, HIGH);
		vTaskDelayUntil(&xLastWakeTime, REDLEDSTATIONARY_DELAY);
		digitalWrite(RED_LED_PIN, LOW);
		vTaskDelayUntil(&xLastWakeTime, REDLEDSTATIONARY_DELAY);
	}
}

void redLedMovingTask(void *p) {
	vTaskSuspend(NULL);
	TickType_t xLastWakeTime;
	while (1) {
		xLastWakeTime = xTaskGetTickCount();
		digitalWrite(RED_LED_PIN, HIGH);
		vTaskDelayUntil(&xLastWakeTime, REDLEDMOVING_DELAY);
		digitalWrite(RED_LED_PIN, LOW);
		vTaskDelayUntil(&xLastWakeTime, REDLEDMOVING_DELAY);
	}
}

/***** Audio Tasks *****/
// Buzzer tasks controller
void buzzerTask(void *p) {
	char data = STOP;
	noTone(BUZZER_PIN);
	while (1) {
		// Wait for data from blueTooth task
		xQueueReceive(q_buzzerdata, &data, portMAX_DELAY);
		switch (data) {
		case BLUETOOTH_CONNECTED:
			noTone(BUZZER_PIN);
			vTaskResume(th_bluetmusic);
			break;
		case BEGIN_CHALLENGE:
			noTone(BUZZER_PIN);
			vTaskSuspend(th_endmusic);
			vTaskResume(th_babyshark);
			break;
		case END_CHALLENGE:
			noTone(BUZZER_PIN);
			vTaskSuspend(th_babyshark);
			vTaskResume(th_endmusic);
			break;
		}
	}
}

// Run during challenge
void babySharkMusicTask(void *p) {
	vTaskSuspend(NULL);
	// Wait until blueTooth tone is done
	xSemaphoreTake(semaphore_buzzer, portMAX_DELAY);
	xSemaphoreGive(semaphore_buzzer);
	while (1) {
		TickType_t xLastWakeTime = xTaskGetTickCount();
		babysharkdoo();
		vTaskDelayUntil(&xLastWakeTime, xQuarter);
		babysharkdoo();
		vTaskDelayUntil(&xLastWakeTime, xQuarter);
		babysharkdoo();
		babyshark();
	}
}

// Run when challenge ends
void endChallengeMusicTask(void *p) {
	vTaskSuspend(NULL);
	// Wait until blueTooth tone is done
	xSemaphoreTake(semaphore_buzzer, portMAX_DELAY);
	xSemaphoreGive(semaphore_buzzer);
	while (1) {
		theboywholived();
	}
}

// Run when connected to blueTooth
void blueToothConnectionMusicTask(void *p) {
	vTaskSuspend(NULL);
	// Prevent other music from starting until this task is done
	xSemaphoreTake(semaphore_buzzer, portMAX_DELAY);
	bluetoothconnectedtone();
	xSemaphoreGive(semaphore_buzzer);
	vTaskSuspend(NULL);
}

/*----------MAIN----------*/
/***** Setup *****/
void setup() {
	pinMode(GREEN_LED_DATA_PIN, OUTPUT);
	pinMode(GREEN_LED_LATCH_PIN, OUTPUT);
	pinMode(GREEN_LED_CLOCK_PIN, OUTPUT);
	pinMode(RED_LED_PIN, OUTPUT);
	pinMode(MOTOR_A1_PIN, OUTPUT);
	pinMode(MOTOR_A2_PIN, OUTPUT);
	pinMode(MOTOR_B1_PIN, OUTPUT);
	pinMode(MOTOR_B2_PIN, OUTPUT);
	pinMode(BUZZER_PIN,OUTPUT);

	Serial.begin(9600);

	q_buzzerdata = xQueueCreate(QUEUE_SIZE, sizeof(char));
	q_leddata = xQueueCreate(QUEUE_SIZE, sizeof(char));
	q_motordata = xQueueCreate(QUEUE_SIZE, sizeof(char));

	semaphore_buzzer = xSemaphoreCreateMutex();
	semaphore_greenled = xSemaphoreCreateMutex();
}

/***** Loop *****/
void loop() {
	xTaskCreate(blueToothTask, "BlueToothTask", STACK_SIZE, NULL, 6, &th_bluetooth);
	xTaskCreate(motorTask, "Motor", STACK_SIZE, NULL, 5, &th_motor);
	xTaskCreate(ledTask, "Led", STACK_SIZE, NULL, 4, &th_led);
	xTaskCreate(greenLedBlueToothTask, "GreenLedBT", STACK_SIZE, NULL, 2, &th_greenledbluetooth);
	xTaskCreate(greenLedMovingTask, "GreenLedMoving", STACK_SIZE, NULL, 2, &th_greenledmoving);
	xTaskCreate(redLedStationaryTask, "RedLedStationary", STACK_SIZE, NULL, 2, &th_redledstationary);
	xTaskCreate(redLedMovingTask, "RedLedMoving", STACK_SIZE, NULL, 2, &th_redledmoving);
	xTaskCreate(buzzerTask, "Buzzer", STACK_SIZE, NULL, 3, &th_buzzer);
	xTaskCreate(babySharkMusicTask, "RunningBuzzer", STACK_SIZE, NULL, 1, &th_babyshark);
	xTaskCreate(endChallengeMusicTask, "EndBuzzer", STACK_SIZE, NULL, 1, &th_endmusic);
	xTaskCreate(blueToothConnectionMusicTask, "BTTone", STACK_SIZE, NULL, 1, &th_bluetmusic);

	xSemaphoreGive(semaphore_buzzer);
	xSemaphoreGive(semaphore_greenled);

	vTaskStartScheduler();
}
