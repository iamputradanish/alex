#include <Arduino.h>
#include <avr/io.h>
#include <FreeRTOS.h>
#include <task.h>

#define STACK_SIZE 200

#define TEMPO 400
#define DNOTE 2349
#define ENOTE 2637
#define GNOTE 3136
#define FSNOTE 2960

const TickType_t xTempo = TEMPO portTICK_PERIOD_MS;
const TickType_t xHalf  = TEMPO/2;
const TickType_t xQuarter = HALF/2;
const TickType_t xThird = TEMPO/3;
const TickType_t xEigth = QUARTER/2;


void babysharkdoo(){
  //D-E G GG  GG  GG
  tone(12,DNOTE); //D
  vTaskDelay(xHALF);
  tone(12,ENOTE); //E
  vTaskDelay(xHALF);
  noTone(12);
  vTaskDelay(xQUARTER);

  tone(12,GNOTE); //G
  vTaskDelay(xEIGTH);
  noTone(12);
  vTaskDelay(xHALF);


  tone(12,GNOTE); //G
  vTaskDelay(xEIGTH);
  noTone(12);
  vTaskDelay(xHALF);
  tone(12,GNOTE); //G
  vTaskDelay(xEIGTH);
  noTone(12);
  vTaskDelay(xTHIRD);
  
  
  tone(12,GNOTE); //G
  vTaskDelay(xEIGTH);
  noTone(12);
  vTaskDelay(xQUARTER);
  tone(12,GNOTE); //G
  vTaskDelay(xQUARTER);
  noTone(12);
  vTaskDelay(xQUARTER);

  
  tone(12,GNOTE); //G
  vTaskDelay(xEIGTH);
  noTone(12);
  vTaskDelay(xTHIRD);
  tone(12,GNOTE); //G
  vTaskDelay(xEIGTH);
  noTone(12);
  vTaskDelay(xTHIRD);

}

void babyshark(){
  tone(12,GNOTE); //G
  vTaskDelay(xEIGTH);
  noTone(12);
  vTaskDelay(xHALF); 
  tone(12,GNOTE); //G
  vTaskDelay(xEIGTH);
  noTone(12);
  vTaskDelay(xHALF);


  tone(12,FSNOTE); //F#
  vTaskDelay(xEIGTH);
  noTone(12);
  vTaskDelay(xTEMPO);
  vTaskDelay(xTEMPO);
}

void vTask1(void *p)
{
	for (;;) {
		babysharkdoo();
		vTaskDelay(xQUARTER);
		babysharkdoo();
		vTaskDelay(xQUARTER);
		babysharkdoo();
		babyshark();
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
	vTaskStartScheduler();
}
