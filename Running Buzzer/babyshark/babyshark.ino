#define TEMPO 400
#define DNOTE 2349
#define ENOTE 2637
#define GNOTE 3136
#define FSNOTE 2960

int HALF = (TEMPO/2)
int QUARTER = (HALF/2)
int THIRD = (TEMPO/3)
int EIGTH = (QUARTER/2)

void setup() {
  pinMode(12,OUTPUT);
}

void babysharkdoo(){
  //D-E G GG  GG  GG
  tone(12,DNOTE); //D
  delay(HALF);
  
  tone(12,ENOTE); //E
  delay(HALF);
  noTone(12);
  delay(QUARTER);

  tone(12,GNOTE); //G
  delay(EIGTH);
  noTone(12);
  delay(HALF);


  tone(12,GNOTE); //G
  delay(EIGTH);
  noTone(12);
  delay(HALF);
  
  tone(12,GNOTE); //G
  delay(EIGTH);
  noTone(12);
  delay(THIRD);


  
  
  tone(12,GNOTE); //G
  delay(EIGTH);
  noTone(12);
  delay(QUARTER);
  
  tone(12,GNOTE); //G
  delay(QUARTER);
  noTone(12);
  delay(QUARTER);


  
  
  tone(12,GNOTE); //G
  delay(EIGTH);
  noTone(12);
  delay(THIRD);

  tone(12,GNOTE); //G
  delay(EIGTH);
  noTone(12);
  delay(THIRD);

}

void babyshark(){
  tone(12,GNOTE); //G
  delay(EIGTH);
  noTone(12);
  delay(HALF);
  
  tone(12,GNOTE); //G
  delay(EIGTH);
  noTone(12);
  delay(HALF);

  

  tone(12,FSNOTE); //F#
  delay(EIGTH);
  noTone(12);
  delay(tempo);
  delay(tempo);
}

void loop() {
  babysharkdoo();
  delay(QUARTER);
  babysharkdoo();
  delay(QUARTER);
  babysharkdoo();
  babyshark();

}
