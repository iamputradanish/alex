#define tempo 400
#define halfnote (tempo/2)
#define quarternote (halfnote/2)
#define thirdnote (535/3)
#define eigthnote (quarternote/2)

int notes[12]={2093, 2217, 2349, 2489, 2637, 2793, 2960, 3136, 3322, 3520, 3729, 3951};
  //             C7  , C#7 , D7  , D#7 , E7  , F7  , F#7 , G7  , G#7 , A7  , A#7 , B7

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
