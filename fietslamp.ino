/*
   Bike light revision 1
*/

int LED1 = 12;
int LED2 = 11;
int LED3 = 10;
int LED4 = 9;
int LED5 = 8;

int switchPin = 2;

int val;
int val2;
int buttonState;
int lightMode = 0;

void setup()
{
  pinMode(switchPin, INPUT);        // Set the switch pin as input

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);

  Serial.begin(9600);               // Set up serial communication at 9600 bps
  buttonState = digitalRead(switchPin);  // read the initial state
}

void loop()
{
  val = digitalRead(switchPin);     // read input value and store it in val
  delay(10);                        // 10 miliseconds is a good ammount of time
  val2 = digitalRead(switchPin);    // read the input again to check for bounces
  if(val == val2)                   // make sure we got 2 consistant readings!

  if (val != buttonState)           // check button state is changed!
  {
    if (val == LOW)                 // check if the button is pressed
    {
      lightMode++;
    }
  }
  buttonState = val;                // save the new state in our variable
  
  if (lightMode == 0)
  {
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
  }
    if (lightMode == 1)
  {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED5, HIGH);
  }
    if (lightMode == 2)
  {
    digitalWrite(LED1, HIGH);
    digitalWrite(LED2, HIGH);
    digitalWrite(LED3, HIGH);
    digitalWrite(LED4, HIGH);
    digitalWrite(LED5, HIGH);
    delay(500);
    digitalWrite(LED1, LOW);
    digitalWrite(LED2, LOW);
    digitalWrite(LED3, LOW);
    digitalWrite(LED4, LOW);
    digitalWrite(LED5, LOW);
    delay(500);
  }
    if (lightMode == 3)
  {
    digitalWrite(LED1, HIGH);
    delay(100);
    digitalWrite(LED2, HIGH);
    delay(100);
    digitalWrite(LED3, HIGH);
    delay(100);
    digitalWrite(LED4, HIGH);
    delay(100);
    digitalWrite(LED5, HIGH);
    delay(100);
    digitalWrite(LED1, LOW);
    delay(100);
    digitalWrite(LED2, LOW);
    delay(100);
    digitalWrite(LED3, LOW);
    delay(100);
    digitalWrite(LED4, LOW);
    delay(100);
    digitalWrite(LED5, LOW);
    delay(100);
  }  
    if (lightMode == 4)
  {
      lightMode = 0;
  }
}
