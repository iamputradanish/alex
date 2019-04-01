#include <Arduino.h>
#include <avr/io.h>
#include <FreeRTOS.h>
#include <task.h>

#define STACK_SIZE 200

#define BUZZER_PIN 12

// #define TEMPO 535
#define TEMPO 2140
#define B6NOTE 1976
#define B7NOTE 3951
#define ENOTE 2637
#define GNOTE 3136
#define FSNOTE 2960
#define ANOTE 3520


const TickType_t xTempo = (TEMPO/portTICK_PERIOD_MS);
const TickType_t xHalf  = xTempo/2;
const TickType_t xQuarter = xHalf/2;
const TickType_t xEigth = xQuarter/2;

TickType_t xLastWakeTime;

void theboywholived(){
	xLastWakeTime = xTaskGetTickCount();
//
//  B E G F# E B A F#
//  E G F# Eb E B
//  B E G F# E B D Db C
//  Ab C B Bb F# G E
//  G B G B G C B Bb
//  F# G B Bb Bb B B
//  G B G B G D Db C
//  Ab C B Bb F# G E

  //B E G F E B A F
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

//  //E G F# Eb E B
//
//  tone(BUZZER_PIN,ENOTE); //E
//  vTaskDelayUntil(&xLastWakeTime, xTempo);
//  vTaskDelayUntil(&xLastWakeTime, XHalf);
//  tone(BUZZER_PIN,GNOTE); //G
//  vTaskDelayUntil(&xLastWakeTime, xHalf);
//  tone(BUZZER_PIN,FSNOTE); //F#
//  vTaskDelayUntil(&xLastWakeTime, xTempo);
//
//  tone(BUZZER_PIN,2489); //D#
//  vTaskDelayUntil(&xLastWakeTime, xTempo);
//  vTaskDelayUntil(&xLastWakeTime, xTempo);
//  tone(BUZZER_PIN,2489); //Eb/D#
//  vTaskDelayUntil(&xLastWakeTime, xTempo);
//  tone(BUZZER_PIN,B7NOTE); //B
//  vTaskDelayUntil(&xLastWakeTime, xTempo);
//  vTaskDelayUntil(&xLastWakeTime, xTempo);
//  vTaskDelayUntil(&xLastWakeTime, xTempo);
//  noTone(BUZZER_PIN);

}

void vTask2(void *p)
{
	for (;;) {
		xLastWakeTime = xTaskGetTickCount();
		theboywholived();
		vTaskDelayUntil(&xLastWakeTime, 1000);
	}
}

void setup()
{
  pinMode(BUZZER_PIN,OUTPUT);
}

void loop() {
	xTaskCreate(vTask2, 		// Pointer to the task entry function
				"EndBuzzer", 	// Task name
				STACK_SIZE, 	// Stack size
				NULL, 			// Pointer that will be used as parameter
				2, 				// Task priority
				NULL); 			// Used to pass back a handle by which the created task can be referenced.
	vTaskStartScheduler();
}
