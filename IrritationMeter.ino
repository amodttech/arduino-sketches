
const int soundPin = 0;

const int green1 = 3;
const int green2 = 4;
const int green3 = 5;
const int yellow1 = 6;
const int yellow2 = 7;
const int red1 = 8;


//variables for storing raw sound and scaled value
int sound;
int scale;


void setup() {

 Serial.begin(9600);

 pinMode(green1, OUTPUT);
 pinMode(green2, OUTPUT);
 pinMode(green3, OUTPUT);
 pinMode(yellow1, OUTPUT);
 pinMode(yellow2, OUTPUT);
 pinMode(red1, OUTPUT);
}


void loop() {
 //read and store the audio from Envelope pin
 sound = analogRead(soundPin);
 
 //map sound which in a quiet room a clap is 300
 //from 0 to 6 to be used with switch case
 // map(sound, minsoundlevel, maxsoundlevel, case0, case6)
 scale = map(sound, 25, 175, 0, 6);


 Serial.print(sound);
 Serial.print("   ");
 Serial.println(scale);


  //switch case on scaled value
switch (scale) {
  //if 0 RGB = Blue
  case 0:
    digitalWrite(green1, LOW);
    digitalWrite(green2, HIGH);
    digitalWrite(green3, HIGH);
    digitalWrite(yellow1, HIGH);
    digitalWrite(yellow2, HIGH);
    digitalWrite(red1, HIGH);
    break;
  //if 1 RGB = Green  
  case 1:
    digitalWrite(green1, LOW);
    digitalWrite(green2, LOW);
    digitalWrite(green3, HIGH);
    digitalWrite(yellow1, HIGH);
    digitalWrite(yellow2, HIGH);
    digitalWrite(red1, HIGH);
    break;
  //if 2 RGB = Yellow  
  case 2:
    digitalWrite(green1, LOW);
    digitalWrite(green2, LOW);
    digitalWrite(green3, LOW);
    digitalWrite(yellow1, HIGH);
    digitalWrite(yellow2, HIGH);
    digitalWrite(red1, HIGH);
    break;
  //if 3 RGB = Red
  case 3:
    digitalWrite(green1, LOW);
    digitalWrite(green2, LOW);
    digitalWrite(green3, LOW);
    digitalWrite(yellow1, LOW);
    digitalWrite(yellow2, HIGH);
    digitalWrite(red1, HIGH);
    break;
  case 4:
    digitalWrite(green1, LOW);
    digitalWrite(green2, LOW);
    digitalWrite(green3, LOW);
    digitalWrite(yellow1, LOW);
    digitalWrite(yellow2, LOW);
    digitalWrite(red1, HIGH);
    break;
  case 5:
    digitalWrite(green1, LOW);
    digitalWrite(green2, LOW);
    digitalWrite(green3, LOW);
    digitalWrite(yellow1, LOW);
    digitalWrite(yellow2, LOW);
    digitalWrite(red1, LOW);
    break;
  //default off
  default:
    digitalWrite(green1, HIGH);
    digitalWrite(green2, HIGH);
    digitalWrite(green3, HIGH);
    digitalWrite(yellow1, HIGH);
    digitalWrite(yellow2, HIGH);
    digitalWrite(red1, HIGH);
    break;
   }
   delay(1000);
}