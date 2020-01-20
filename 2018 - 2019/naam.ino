//Made by Thijs van Kessel, Ic.18.ao.E
//date of finish: 15-4-2019

//defined alle output
#define ROW_1Tkes 2           
#define ROW_2Tkes 3
#define ROW_3Tkes 4
#define ROW_4Tkes 5
#define ROW_5Tkes 6
#define ROW_6Tkes 7
#define ROW_7Tkes 8
#define ROW_8Tkes 9

#define COL_1Tkes 10
#define COL_2Tkes 11
#define COL_3Tkes 12
#define COL_4Tkes 13
#define COL_5Tkes A0
#define COL_6Tkes A1
#define COL_7Tkes A2
#define COL_8Tkes A3

// Alle bytes declared
const byte rijTkes[8] = {ROW_1Tkes, ROW_2Tkes, ROW_3Tkes, ROW_4Tkes, ROW_5Tkes, ROW_6Tkes, ROW_7Tkes, ROW_8Tkes};  // array van kolom pinnen
const byte kolomTkes[8]   = {COL_1Tkes, COL_2Tkes, COL_3Tkes, COL_4Tkes, COL_5Tkes, COL_6Tkes, COL_7Tkes, COL_8Tkes}; // array van rij pinnens
byte letter_tTkes[8] = {B00000000, B01111110, B01111110, B00011000, B00011000, B00011000, B00011000, B00000000}; // array voor de letter
byte letter_hTkes[8] = {B00000000, B00100000, B00100000, B00111000, B00100100, B00100100, B00100100, B00000000}; // array voor de letter
byte letter_iTkes[8] = {B00000000, B00010000, B00000000, B00111000, B00010000, B00010000, B00111000, B00000000}; // array voor de letter
byte letter_jTkes[8] = {B00000000, B00010000, B00000000, B00111000, B00001000, B00001000, B00110000, B00000000}; // array voor de letter
byte letter_sTkes[8] = {B00000000, B00000000, B00011100, B00100000, B00011000, B00000100, B00111000, B00000000}; // array voor de letter

void setup() {
  Serial.begin(9600);
  // zet de pins als outputs
  for (byte i = 2; i <= 13; i++)
  pinMode(i, OUTPUT);
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
  pinMode(A2, OUTPUT);
  pinMode(A3, OUTPUT);
}

void loop() {
  //vraagt naar methode eerst de byte daarna de tijd daarna de letter voor debugging
  DisplayThijsTkes(letter_tTkes, 2000, "T");
  DisplayThijsTkes(letter_hTkes, 2000, "H");
  DisplayThijsTkes(letter_iTkes, 2000, "I");
  DisplayThijsTkes(letter_jTkes, 2000, "J");
  DisplayThijsTkes(letter_sTkes, 2000, "S");
}

void DisplayThijsTkes(byte buffer[], int timerTkes, String letterTkes) {
  //printing leter voor debug monitor
  Serial.println(letterTkes);
  for (int i = 0; i < timerTkes; i++) {
    for (byte r = 0; r < 8; r++) {
      digitalWrite(rijTkes[r], HIGH); // zet alle rijen naar high
      for (byte k = 0; k < 8; k++) {
        if (bitRead(buffer[r], k) == 1) {     // gaat door de byte heen met de byte reader als 1 zet het high en als de 1 0 is worden de lampjes ge-invert, dan zijn de letters uit en de rest aan
          digitalWrite(kolomTkes[k], LOW);
        } else {
          digitalWrite(kolomTkes[k], HIGH);
        }
        delayMicroseconds(1);
        digitalWrite(kolomTkes[k], HIGH);
      }
      digitalWrite(rijTkes[r], LOW); // zet alles weer naar low zoals orgineel
    }
  }
}
