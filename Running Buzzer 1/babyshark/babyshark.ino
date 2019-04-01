#define TEMPO 400
#define DNOTE 2349
#define ENOTE 2637
#define GNOTE 3136
#define FSNOTE 2960

#define HALF (TEMPO/2)
#define QUARTER (HALF/2)
#define THIRD (TEMPO/3)
#define EIGTH (QUARTER/2)

#define BUZZER_PIN 13

void setup() {
  pinMode(13,OUTPUT);
}

void No_Tone(beat){
  for(int i=0;i<beat;i++){
    digitalWrite(BUZZER_PIN, LOW);
  }
}

void D_Note(beat){
  for(int i=0;i<beat;i++){
    digitalWrite(BUZZER_PIN, HIGH);
    delayMicroseconds(213);
    digitalWrite(BUZZER_PIN, LOW);
    delayMicroseconds(213);
  } 
}

void E_Note(beat){
  for(int i=0;i<beat;i++){
    digitalWrite(BUZZER_PIN, HIGH);
    delayMicroseconds(190);
    digitalWrite(BUZZER_PIN, LOW);
    delayMicroseconds(190);
  } 
}

void G_Note(){
  for(int i=0;i<beat;i++){
    digitalWrite(BUZZER_PIN, HIGH);
    delayMicroseconds(160);
    digitalWrite(BUZZER_PIN, LOW);
    delayMicroseconds(160);
  } 
}

void FS_Note(beat){
  for(int i=0;i<beat;i++){
    digitalWrite(BUZZER_PIN, HIGH);
    delayMicroseconds(169);
    digitalWrite(BUZZER_PIN, LOW);
    delayMicroseconds(169);
  } 
}

void babysharkdoo(){
  //D-E G GG  GG  GG

  D_Note(HALF);

  E_Note(HALF);
  No_Tone(QUARTER);

  G_Note(EIGTH);
  No_Note(HALF);


  G_Note(EIGTH);
  No_Note(HALF);
  
  G_Note(EIGTH);
  No_Note(THIRD);

  
  
  G_Note(EIGTH);
  No_Note(QUARTER);
  
  G_Note(QUARTER);
  No_Note(QUARTER);


  
  
  G_Note(EIGTH);
  No_Note(THIRD);

  G_Note(EIGTH);
  No_Note(THIRD);

}

void babyshark(){
  G_Note(EIGTH);
  No_Note(HALF);
  
  G_Note(EIGTH);
  No_Note(HALF);

  
  FS_Note(EIGTH);
  No_Note(TEMPO);
  No_Note(TEMPO);
}

void loop() {
  babysharkdoo();
  for(int i=0;i<QUARTER;i++){}
  babysharkdoo();
  for(int i=0;i<QUARTER;i++){}
  babysharkdoo();
  babyshark();

}
