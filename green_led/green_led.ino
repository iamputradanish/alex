#define GREEN_LED_DATA_PIN 2
#define GREEN_LED_LATCH_PIN 3
#define GREEN_LED_CLOCK_PIN 4
#define RED_LED_PIN 7

#define GREEN_LED_ALL_HIGH 0xFF

void green_led_stationary() {
  digitalWrite(GREEN_LED_LATCH_PIN, LOW);
  shiftOut(GREEN_LED_DATA_PIN, GREEN_LED_CLOCK_PIN, MSBFIRST, GREEN_LED_ALL_HIGH);
  digitalWrite(GREEN_LED_LATCH_PIN, HIGH);
}

void green_led_blink() {
  digitalWrite(GREEN_LED_LATCH_PIN, LOW);
  shiftOut(GREEN_LED_DATA_PIN, GREEN_LED_CLOCK_PIN, MSBFIRST, GREEN_LED_ALL_HIGH);
  digitalWrite(GREEN_LED_LATCH_PIN, HIGH);
  delay(1000);
  digitalWrite(GREEN_LED_LATCH_PIN, LOW);
  shiftOut(GREEN_LED_DATA_PIN, GREEN_LED_CLOCK_PIN, MSBFIRST, ~GREEN_LED_ALL_HIGH);
  digitalWrite(GREEN_LED_LATCH_PIN, HIGH);
  delay(1000);
}

void green_led_moving() {
  for (int i = 0; i < 7; i++) {
    digitalWrite(GREEN_LED_LATCH_PIN, LOW);
    shiftOut(GREEN_LED_DATA_PIN, GREEN_LED_CLOCK_PIN, MSBFIRST, 1 << i);
    digitalWrite(GREEN_LED_LATCH_PIN, HIGH);
    delay(125);
  }
  for (int i = 0; i < 7; i++) {
    digitalWrite(GREEN_LED_LATCH_PIN, LOW);
    shiftOut(GREEN_LED_DATA_PIN, GREEN_LED_CLOCK_PIN, LSBFIRST, 1 << i);
    digitalWrite(GREEN_LED_LATCH_PIN, HIGH);
    delay(125);
  }
}

void setup() {
  pinMode(GREEN_LED_DATA_PIN, OUTPUT);
  pinMode(GREEN_LED_LATCH_PIN, OUTPUT);
  pinMode(GREEN_LED_CLOCK_PIN, OUTPUT);
  // green_led_stationary();
}

void loop() {
  // green_led_blink();
  green_led_moving();
}

