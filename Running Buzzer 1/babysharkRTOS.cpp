#include <Arduino.h>
#include <avr/io.h>
#include <FreeRTOS.h>
#include <task.h>

#define STACK_SIZE 200

#define BUZZER_PIN 13

#define TEMPO 400
#define DNOTE 2349
#define ENOTE 2637
#define GNOTE 3136
#define FSNOTE 2960

const TickType_t xTempo = (TEMPO/portTICK_PERIOD_MS);
const TickType_t xHalf  = xTempo/2;
const TickType_t xQuarter = xHalf/2;
const TickType_t xThird = xTempo/3;
const TickType_t xEigth = xQuarter/2;

TickType_t xLastWakeTime;

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

void vTask1(void *p)
{

	for (;;) {
		xLastWakeTime = xTaskGetTickCount();
		babysharkdoo();
		vTaskDelayUntil(&xLastWakeTime, xQuarter);
		babysharkdoo();
		vTaskDelayUntil(&xLastWakeTime, xQuarter);
		babysharkdoo();
		babyshark();
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
	vTaskStartScheduler();
}
