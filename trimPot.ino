/*
  SparkFun Inventor’s Kit
  Circuit 1B-Potentiometer

  Changes how fast an LED connected to pin 13 blinks, based on a potentiometer connected to pin A0

  This sketch was written by SparkFun Electronics, with lots of help from the Arduino community.
  This code is completely free for any use.

  View circuit diagram and instructions at: https://learn.sparkfun.com/tutorials/sparkfun-inventors-kit-experiment-guide---v41
  Download code at: https://github.com/sparkfun/SIK-Guide-Code
*/

int potPosition;       //this variable will hold a value based on the position of the potentiometer
int brightness = 0;
int fadeAmount = 5;
int led = 11;

void setup()
{
  Serial.begin(9600);       //start a serial connection with the computer

  pinMode(led, OUTPUT);      //set pin 13 as an output that can be set to HIGH or LOW
}

void loop()
{
  //read the position of the pot
  potPosition = analogRead(A0);    //set potPosition to a number between 0 and 1023 based on how far the knob is turned
  Serial.println(potPosition);     //print the value of potPosition in the serial monitor on the computer

    analogWrite(led, brightness);

    brightness = brightness + fadeAmount;

    if (brightness <= 0 || brightness >= 255) {
        fadeAmount = -fadeAmount;
    }

    delay(potPosition);

    Serial.print(brightness);
    Serial.print(fadeAmount);
    }

