#include <Arduino.h>
#include <avr/io.h>
#include <FreeRTOS.h>
#include <task.h>

#define STACK_SIZE 200

#define TEMPO 400
#define CNOTE 2093
#define DNOTE 2349
#define ENOTE 2637



const TickType_t xTempo = (TEMPO/portTICK_PERIOD_MS);
const TickType_t xHalf  = ((TEMPO/2)/portTICK_PERIOD_MS);

TickType_t = xLastWakeTime;

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

void vTask1(void *p)
{
	for (;;) {
		bluetoothconnected;
	}
}

void setup() 
{
  pinMode(12,OUTPUT);
}

void loop() {
	xTaskCreate(vTask1, 			// Pointer to the task entry function
				"BTBuzzer", // Task name
				STACK_SIZE, 	// Stack size
				NULL, 			// Pointer that will be used as parameter
				1, 				// Task priority
				NULL); 			// Used to pass back a handle by which the created task can be referenced.
	vTaskStartScheduler();
}
