#define GREEN_LED_DATA_PIN 2
#define GREEN_LED_LATCH_PIN 3
#define GREEN_LED_CLOCK_PIN 4
#define RED_LED_PIN 7

void red_led_stationary() {
  digitalWrite(RED_LED_PIN, HIGH);
  delay(250);
  digitalWrite(RED_LED_PIN, LOW);
  delay(250);
}

void red_led_moving() {
  digitalWrite(RED_LED_PIN, HIGH);
  delay(500);
  digitalWrite(RED_LED_PIN, LOW);
  delay(500);
}

void setup() {
  pinMode(RED_LED_PIN, OUTPUT);
}

void loop() {
  for (int i = 0; i < 2; i++) {
    red_led_stationary();
  }
  red_led_moving();
}

