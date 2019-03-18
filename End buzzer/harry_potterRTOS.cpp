#include <Arduino.h>
#include <avr/io.h>
#include <FreeRTOS.h>
#include <task.h>

#define STACK_SIZE 200

#define TEMPO 535
#define B6NOTE 1976
#define B7NOTE 3951
#define ENOTE 2637
#define GNOTE 3136
#define FSNOTE 2960
#define ANOTE 3520


const TickType_t xTempo = (TEMPO/portTICK_PERIOD_MS);
const TickType_t xHalf  = ((TEMPO/2)/portTICK_PERIOD_MS);
const TickType_t xQuarter = ((HALF/2)/portTICK_PERIOD_MS);
const TickType_t xEigth = ((QUARTER/2)/portTICK_PERIOD_MS);


void theboywholived(){
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
  noTone(12);
  vTaskDelay(xTempo);
  vTaskDelay(xTempo);
  tone(12,B6NOTE); //B
  vTaskDelay(xTempo);
  
  
  tone(12,ENOTE); //E
  vTaskDelay(xTempo);
  vTaskDelay(xHalf);
  tone(12,GNOTE); //G
  vTaskDelay(xHalf);
  tone(12,FSNOTE); //F#
  vTaskDelay(xTempo);
  
  tone(12,ENOTE); //E
  vTaskDelay(xTempo);
  vTaskDelay(xTempo);
  
  tone(12,B7NOTE); //B
  vTaskDelay(xTempo);
  
  tone(12,ANOTE); //A
  vTaskDelay(xTempo);
  vTaskDelay(xTempo);
  vTaskDelay(xTempo);

  tone(12,FSNOTE); //F#
  vTaskDelay(xTempo);
  vTaskDelay(xTempo);
  noTone(12);
  vTaskDelay(xTempo);
  
//  //E G F# Eb E B
//
//  tone(12,ENOTE); //E
//  vTaskDelay(xTempo);
//  vTaskDelay(XHalf);
//  tone(12,GNOTE); //G
//  vTaskDelay(xHalf);
//  tone(12,FSNOTE); //F#
//  vTaskDelay(xTempo);
//
//  tone(12,2489); //D#
//  vTaskDelay(xTempo);
//  vTaskDelay(xTempo);
//  tone(12,2489); //Eb/D#
//  vTaskDelay(xTempo);
//  tone(12,B7NOTE); //B
//  vTaskDelay(xTempo);
//  vTaskDelay(xTempo);
//  vTaskDelay(xTempo);
//  noTone(12);
  
}

void vTask2(void *p)
{
	for (;;) {
		theboywholived();
		vTaskDelay(100000);
	}
}

void setup() 
{
  pinMode(12,OUTPUT);
}

void loop() {
	xTaskCreate(vTask2, 			// Pointer to the task entry function
				"EndBuzzer", // Task name
				STACK_SIZE, 	// Stack size
				NULL, 			// Pointer that will be used as parameter
				1, 				// Task priority
				NULL); 			// Used to pass back a handle by which the created task can be referenced.
	vTaskStartScheduler();
}
