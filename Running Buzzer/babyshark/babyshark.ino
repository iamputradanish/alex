#define tempo 535
#define halfnote (tempo/2)
#define quarternote (halfnote/2)
#define thirdnote (535/3)
#define eigthnote (quarternote/2)

void setup() {
  pinMode(12,OUTPUT);
}

void babyshark(){
  tone(12,294); //D
  delay(eigthnote);
  noTone(12);
  delay(tempo);
  
  tone(12,330); //E
  delay(eigthnote);
  noTone(12);
  delay(tempo);

  tone(12,392); //G
  delay(eigthnote);
  noTone(12);
  delay(halfnote);
  
  tone(12,392); //G
  delay(eigthnote);
  noTone(12);
  delay(halfnote);
  
  tone(12,392); //G
  delay(eigthnote);
  noTone(12);
  delay(thirdnote);
  
  tone(12,392); //G
  delay(eigthnote);
  noTone(12);
  delay(quarternote);
  
  tone(12,392); //G
  delay(quarternote);
  noTone(12);
  delay(quarternote);
  
  tone(12,392); //G
  delay(eigthnote);
  noTone(12);
  delay(thirdnote);

  

}

void babyshark1(){
  tone(12,392); //G
  delay(eigthnote);
  noTone(12);
  delay(halfnote);
  
  tone(12,392); //G
  delay(eigthnote);
  noTone(12);
  delay(halfnote);

  tone(12,392); //F#
  delay(eigthnote);
  noTone(12);
  delay(tempo);
}

void loop() {
  babyshark();
  babyshark();
  babyshark();
  babyshark1();

  //int notes[10]={261, 277, 294, 311, 330, 349, 370, 392, 415, 440};
  //            mid C  C#   D    D#   E    F    F#   G    G#   A

  //for(int i = 0; i < 10; i++){
  //  tone(12, notes[i]); //accesses spots on the array.
  //  delay(1000);
}
