#include <Arduino.h>
#include <avr/io.h>
#include <FreeRTOS.h>
#include <task.h>

#define TEMPO 400
#define HALF (TEMPO/2)
#define QUARTER (HALF/2)
#define THIRD (TEMPO/3)
#define EIGTH (QUARTER/2)
#define DNOTE 2349
#define ENOTE 2637
#define GNOTE 3136
#define FSNOTE 2960

void setup() {
  pinMode(12,OUTPUT);
}

void babysharkdoo(){
  //D-E G GG  GG  GG
  tone(12,notes[2]); //D
  delay(halfnote);
  
  tone(12,notes[4]); //E
  delay(halfnote);
  noTone(12);
  delay(quarternote);

  tone(12,notes[7]); //G
  delay(eigthnote);
  noTone(12);
  delay(halfnote);


  tone(12,notes[7]); //G
  delay(eigthnote);
  noTone(12);
  delay(halfnote);
  
  tone(12,notes[7]); //G
  delay(eigthnote);
  noTone(12);
  delay(thirdnote);


  
  
  tone(12,notes[7]); //G
  delay(eigthnote);
  noTone(12);
  delay(quarternote);
  
  tone(12,notes[7]); //G
  delay(quarternote);
  noTone(12);
  delay(quarternote);


  
  
  tone(12,notes[7]); //G
  delay(eigthnote);
  noTone(12);
  delay(thirdnote);

  tone(12,notes[7]); //G
  delay(eigthnote);
  noTone(12);
  delay(thirdnote);

}

void babyshark(){
  tone(12,notes[7]); //G
  delay(eigthnote);
  noTone(12);
  delay(halfnote);
  
  tone(12,notes[7]); //G
  delay(eigthnote);
  noTone(12);
  delay(halfnote);

  

  tone(12,notes[6]); //F#
  delay(eigthnote);
  noTone(12);
  delay(tempo);
  delay(tempo);
}

void loop() {
  babysharkdoo();
  delay(quarternote);
  babysharkdoo();
  delay(quarternote);
  babysharkdoo();
  babyshark();

}

void task1(void *p)
{
	for (TickType_t xFrequency = 0; xFrequency <= PERIOD_50; xFrequency++) {
		TickType_t xLastWakeTime;

		xLastWakeTime = xTaskGetTickCount();
		digitalWrite(LED_PIN, HIGH);
		vTaskDelayUntil(&xLastWakeTime, xFrequency);

		xLastWakeTime = xTaskGetTickCount();
		digitalWrite(LED_PIN, LOW);
		vTaskDelayUntil(&xLastWakeTime, PERIOD_50 - xFrequency);
	}
}

void setup()
{
	pinMode(LED_PIN, OUTPUT);
}

void loop() {
	xTaskCreate(task1, 			// Pointer to the task entry function
				"Task1", 		// Task name
				STACK_SIZE, 	// Stack size
				NULL, 			// Pointer that will be used as parameter
				1, 				// Task priority
				NULL); 			// Used to pass back a handle by which the created task can be referenced.
	vTaskStartScheduler();
}
