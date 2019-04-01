#include <Arduino.h>
#include <avr/io.h>
#include <FreeRTOS.h>
#include <task.h>

#define STACK_SIZE 200

#define BUZZER_PIN 12

//#define TEMPO 400
#define TEMPO 3200

#define CNOTE 2093
#define DNOTE 2349
#define ENOTE 2637



const TickType_t xTempo = (TEMPO/portTICK_PERIOD_MS);
const TickType_t xHalf  = ((TEMPO/2)/portTICK_PERIOD_MS);

TickType_t xLastWakeTime;

void bluetoothconnected(){
  xLastWakeTime = xTaskGetTickCount();
  //C D E
  tone(BUZZER_PIN, CNOTE); //C
  vTaskDelayUntil(&xLastWakeTime, xHalf);
  tone(BUZZER_PIN, DNOTE); //D
  vTaskDelayUntil(&xLastWakeTime, xHalf);
  tone(BUZZER_PIN, ENOTE); //E
  vTaskDelayUntil(&xLastWakeTime, xHalf);
  noTone(BUZZER_PIN);

}

void vTask3(void *p)
{
	bluetoothconnected();
	vTaskSuspend(NULL);
}

void setup() 
{
  pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
	xTaskCreate(vTask3, 			// Pointer to the task entry function
				"BTTone", // Task name
				STACK_SIZE, 	// Stack size
				NULL, 			// Pointer that will be used as parameter
				3, 				// Task priority
				NULL); 			// Used to pass back a handle by which the created task can be referenced.
	vTaskStartScheduler();
}
