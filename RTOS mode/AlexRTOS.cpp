#include <Arduino.h>
#include <avr/io.h>
#include <FreeRTOS.h>
#include <task.h>

// FreeRTOS constant
#define STACK_SIZE 200

// IO pins constant
#define BUZZER_PIN 12 

// Music note duration constant
#define TEMPO 3200

// Music note frequency constant
#define B6NOTE 1976
#define B7NOTE 3951
#define CNOTE 2093
#define DNOTE 2349
#define ENOTE 2637
#define FSNOTE 2960
#define GNOTE 3136
#define ANOTE 3520

// Note delay time
const TickType_t xTempo = (TEMPO/portTICK_PERIOD_MS);
const TickType_t xHalf  = ((TEMPO/2)/portTICK_PERIOD_MS);
const TickType_t xQuarter = ((TEMPO/4)/portTICK_PERIOD_MS);
const TickType_t xThird = ((TEMPO/3)/portTICK_PERIOD_MS);
const TickType_t xEigth = ((TEMPO/8)/portTICK_PERIOD_MS);

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
void bluetoothconnected(){
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
void theboywholived(){
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

/***** FreeRTOS Tasks *****/
void babySharkMusicTask(void *p) {
	for (;;) {
		TickType_t xLastWakeTime = xTaskGetTickCount();
		babysharkdoo();
		vTaskDelayUntil(&xLastWakeTime, xQuarter);
		babysharkdoo();
		vTaskDelayUntil(&xLastWakeTime, xQuarter);
		babysharkdoo();
		babyshark();
	}
}

void endChallengeMusicTask(void *p) {
	for (;;) {
		theboywholived();
	}
}

void blueToothConnectionMusicTask(void *p) {
	bluetoothconnected();
	vTaskSuspend(NULL);
}

/***** Setup *****/
void setup() {
	pinMode(BUZZER_PIN,OUTPUT);
}

/***** Loop *****/
void loop() {
	xTaskCreate(babySharkMusicTask, "RunningBuzzer", STACK_SIZE, NULL, 1, NULL);
	xTaskCreate(endChallengeMusicTask, "EndBuzzer", STACK_SIZE, NULL, 2, NULL);
	xTaskCreate(blueToothConnectionMusicTask, "BTTone", STACK_SIZE, NULL, 3, NULL);
	vTaskStartScheduler();
}
