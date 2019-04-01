#include <Arduino.h>
#include <avr/io.h>
#include <FreeRTOS.h>
#include <task.h>

#define STACK_SIZE 200
#define BUZZER_PIN 12 

#define TEMPO 3200
#define B6NOTE 1976
#define B7NOTE 3951
#define CNOTE 2093
#define DNOTE 2349
#define ENOTE 2637
#define FSNOTE 2960
#define GNOTE 3136
#define ANOTE 3520

const TickType_t xTempo = (TEMPO/portTICK_PERIOD_MS);
const TickType_t xHalf  = ((TEMPO/2)/portTICK_PERIOD_MS);
const TickType_t xQuarter = ((HALF/2)/portTICK_PERIOD_MS);
const TickType_t xThird = ((TEMPO/3)/portTICK_PERIOD_MS);
const TickType_t xEigth = ((QUARTER/2)/portTICK_PERIOD_MS);

TickType_t = xLastWakeTime;

void babysharkdoo(){
  xLastWakeTime = xTaskGetTickCount();
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
  xLastWakeTime = xTaskGetTickCount();
  
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

void bluetoothconnected(){
  xLastWakeTime = xTaskGetTickCount();
  //C D E
  tone(BUZZER_PIN,CNOTE); //C
  vTaskDelayUntil(&xLastWakeTime, xHalf);
  tone(BUZZER_PIN,DNOTE); //D
  vTaskDelayUntil(&xLastWakeTime, xHalf);
  tone(BUZZER_PIN,ENOTE); //E
  vTaskDelayUntil(&xLastWakeTime, xHalf);
  noTone(BUZZER_PIN);

}

void theboywholived(){
	xLastWakeTime = xTaskGetTickCount();
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
  vTaskDelayUntil(&xLastWakeTime, XHalf);
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

}

void vTask1(void *p)
{
	
	for (;;) {
		xLastWakeTime = xTaskGetTickCount();
		babysharkdoo();
		vTaskDelayUntil(&xLastWakeTime, xQUARTER);
		babysharkdoo();
		vTaskDelayUntil(&xLastWakeTime, xQUARTER);
		babysharkdoo();
		babyshark();
	}
}

void vTask2(void *p)
{
	for (;;) {
		xLastWakeTime = xTaskGetTickCount();
		theboywholived();
	}
}

void vTask3(void *p)
{
	for (;;) {
		bluetoothconnected();
		vTaskSuspend(NULL);
	}
}

void setup() 
{
  pinMode(BUZZER_PIN,OUTPUT);
}

void loop() {
	xTaskCreate(vTask1, 			// Pointer to the task entry function
				"RunningBuzzer", // Task name
				STACK_SIZE, 	// Stack size
				NULL, 			// Pointer that will be used as parameter
				1, 				// Task priority
				NULL); 			// Used to pass back a handle by which the created task can be referenced.
	xTaskCreate(vTask2, 			// Pointer to the task entry function
				"EndBuzzer", // Task name
				STACK_SIZE, 	// Stack size
				NULL, 			// Pointer that will be used as parameter
				2, 				// Task priority
				NULL); 			// Used to pass back a handle by which the created task can be referenced.
	xTaskCreate(vTask3, 			// Pointer to the task entry function
				"BTTone", // Task name
				STACK_SIZE, 	// Stack size
				NULL, 			// Pointer that will be used as parameter
				3, 				// Task priority
				NULL); 			// Used to pass back a handle by which the created task can be referenced.
	vTaskStartScheduler();
}
