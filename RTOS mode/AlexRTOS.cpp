#include <Arduino.h>
#include <avr/io.h>
#include <FreeRTOS.h>
#include <task.h>

#define STACK_SIZE 200

#define TEMPO 400
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
  tone(12,DNOTE); //D
  vTaskDelayUntil(&xLastWakeTime, xHalf);
  tone(12,ENOTE); //E
  vTaskDelayUntil(&xLastWakeTime, xHalf);
  noTone(12);
  vTaskDelayUntil(&xLastWakeTime, xQuarter);
  
  tone(12,GNOTE); //G
  vTaskDelayUntil(&xLastWakeTime, xEigth);
  noTone(12);
  vTaskDelayUntil(&xLastWakeTime, xHalf);

  tone(12,GNOTE); //G
  vTaskDelayUntil(&xLastWakeTime, xEigth);
  noTone(12);
  vTaskDelayUntil(&xLastWakeTime, xHalf);
  tone(12,GNOTE); //G
  vTaskDelayUntil(&xLastWakeTime, xEigth);
  noTone(12);
  vTaskDelayUntil(&xLastWakeTime, xThird);
  
  tone(12,GNOTE); //G
  vTaskDelayUntil(&xLastWakeTime, xEigth);
  noTone(12);
  vTaskDelayUntil(&xLastWakeTime, xQuarter);
  tone(12,GNOTE); //G
  vTaskDelayUntil(&xLastWakeTime, xQuarter);
  noTone(12);
  vTaskDelayUntil(&xLastWakeTime, xQuarter);

  tone(12,GNOTE); //G
  vTaskDelayUntil(&xLastWakeTime, xEigth);
  noTone(12);
  vTaskDelayUntil(&xLastWakeTime, xThird);
  tone(12,GNOTE); //G
  vTaskDelayUntil(&xLastWakeTime, xEigth);
  noTone(12);
  vTaskDelayUntil(&xLastWakeTime, xThird);

}

void babyshark(){
  xLastWakeTime = xTaskGetTickCount();
  
  tone(12,GNOTE); //G
  vTaskDelayUntil(&xLastWakeTime, xEigth);
  noTone(12);
  vTaskDelayUntil(&xLastWakeTime, xHalf); 
  tone(12,GNOTE); //G
  vTaskDelayUntil(&xLastWakeTime, xEigth);
  noTone(12);
  vTaskDelayUntil(&xLastWakeTime, xHalf);
  
  tone(12,FSNOTE); //F#
  vTaskDelayUntil(&xLastWakeTime, xEigth);
  noTone(12);
  vTaskDelayUntil(&xLastWakeTime, xTempo);
  vTaskDelayUntil(&xLastWakeTime, xTempo);
}

void bluetoothconnected(){
  xLastWakeTime = xTaskGetTickCount();
  //C D E
  tone(12,CNOTE); //C
  vTaskDelayUntil(&xLastWakeTime, xHalf);
  tone(12,DNOTE); //D
  vTaskDelayUntil(&xLastWakeTime, xHalf);
  tone(12,ENOTE); //E
  vTaskDelayUntil(&xLastWakeTime, xHalf);
  noTone(12);

}

void theboywholived(){
	xLastWakeTime = xTaskGetTickCount();
//  B E G F# E B A F#
  noTone(12);
  vTaskDelayUntil(&xLastWakeTime, xTempo);
  vTaskDelayUntil(&xLastWakeTime, xTempo);
  tone(12,B6NOTE); //B
  vTaskDelayUntil(&xLastWakeTime, xTempo);
  
  
  tone(12,ENOTE); //E
  vTaskDelayUntil(&xLastWakeTime, xTempo);
  vTaskDelayUntil(&xLastWakeTime, xHalf);
  tone(12,GNOTE); //G
  vTaskDelayUntil(&xLastWakeTime, xHalf);
  tone(12,FSNOTE); //F#
  vTaskDelayUntil(&xLastWakeTime, xTempo);
  
  tone(12,ENOTE); //E
  vTaskDelayUntil(&xLastWakeTime, xTempo);
  vTaskDelayUntil(&xLastWakeTime, xTempo);
  
  tone(12,B7NOTE); //B
  vTaskDelayUntil(&xLastWakeTime, xTempo);
  
  tone(12,ANOTE); //A
  vTaskDelayUntil(&xLastWakeTime, xTempo);
  vTaskDelayUntil(&xLastWakeTime, xTempo);
  vTaskDelayUntil(&xLastWakeTime, xTempo);

  tone(12,FSNOTE); //F#
  vTaskDelayUntil(&xLastWakeTime, xTempo);
  vTaskDelayUntil(&xLastWakeTime, xTempo);
  noTone(12);
  vTaskDelayUntil(&xLastWakeTime, xTempo);
  
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
	}
}

void setup() 
{
  pinMode(12,OUTPUT);
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
