#define TEMPO 400
#define DNOTE 2349
#define ENOTE 2637
#define GNOTE 3136
#define FSNOTE 2960

int HALF = (TEMPO/2)
int QUARTER = (HALF/2)
int THIRD = (TEMPO/3)
int EIGTH = (QUARTER/2)

int notes[13]={1976, 2093, 2217, 2349, 2489, 2637, 2793, 2960, 3136, 3322, 3520, 3729, 3951};
  //           B   , C   , C#  , D   , D#  , E   , F   , F#  , G   , G#  , A   , A#  , B
  //           0     1     2     3     4     5     6     7     8     9     10    11    12

void setup() {
  pinMode(12,OUTPUT);
}

void theboywholived(){
//
//  B E G F# E B A F#
//  E G F# Eb E B
//  B E G F# E B D Db C
//  Ab C B Bb F# G E
//  G B G B G C B Bb
//  F# G B Bb Bb B B
//  G B G B G D Db C
//  Ab C B Bb F# G E

  //B E G F E B A F
  noTone(12);
  delay(tempo);
  delay(tempo);
  tone(12,notes[0]); //B
  delay(tempo);
  
  
  tone(12,notes[5]); //E
  delay(tempo);
  delay(halfnote);
  tone(12,notes[8]); //G
  delay(halfnote);
  tone(12,notes[7]); //F#
  delay(tempo);
  
  tone(12,notes[5]); //E
  delay(tempo);
  delay(tempo);
  
  tone(12,notes[12]); //B
  delay(tempo);
  
  tone(12,notes[10]); //A
  delay(tempo);
  delay(tempo);
  delay(tempo);

  tone(12,notes[7]); //F#
  delay(tempo);
  delay(tempo);
  noTone(12);
  delay(tempo);
  
//  //E G F# Eb E B
//
//  tone(12,notes[4]); //E
//  delay(tempo);
//  delay(halfnote);
//  tone(12,notes[8]); //G
//  delay(halfnote);
//  tone(12,notes[7]); //F#
//  delay(tempo);
//
//  tone(12,notes[5]); //D#
//  delay(tempo);
//  delay(tempo);
//  tone(12,notes[5]); //Eb/D#
//  delay(tempo);
//  tone(12,notes[12]); //B
//  delay(tempo);
//  delay(tempo);
//  delay(tempo);
//  noTone(12);
  
}

void loop() {
  theboywholived();
  delay(100000);
}
