/*
     Naam: Thijs van Kessel
     Klas: ic19ao.e
     Datum: 28-12-2020
*/

int Led1 = 7;
int Led2 = 6;
int Button1 = 2;
int Button2 = 3;
int Button3 = 4;
int Button1val;
int Button1val2;
int Button2val;
int Button2val2;
int Button3val;
int Button3val2;
int buttonState1;
int buttonState2;
int buttonState3;
int code1;
int code2;
int code3;

void setup() {
  pinMode(Button1, INPUT);
  pinMode(Button2, INPUT);
  pinMode(Button3, INPUT);
  pinMode(Led1, OUTPUT);
  pinMode(Led2, OUTPUT);
  digitalWrite(Led1, HIGH);
  buttonState3 = digitalRead(Button3);
  buttonState2 = digitalRead(Button2);
  buttonState1 = digitalRead(Button1);
  Serial.begin(9600);
}

void loop() {
  Button1val = (digitalRead(Button1)); //
  delay(10);
  Button1val2 = (digitalRead(Button1));

  if (Button1val == Button1val2)
  {
    if (Button1val != buttonState1)
    {
      if (Button1val == HIGH)                           /* sends messages to the monitor */
      {
        Serial.println("button 1 is just pressed");
      }
      else
      {
        Serial.println("button 1 is released");       /* checks if code is filled in, not than fills the code, if it has code it skips and goes to next */
        if (code1 == NULL)
        {
          code1 = 1;
          Serial.println("codeOne is set to 1");
        }
        else
        {
          if (code2 == NULL)
          {
            code2 = 1;
            Serial.println("codeTwo is set to 1");
          }
          else
          {
            if (code3 == NULL)
            {
              code3 = 1;
              Serial.println("codethree is set to 1");

              checkCode();
            }
          }
        }
      }
    }
    buttonState1 = Button1val;
  }

  Button2val = (digitalRead(Button2));
  delay(10);
  Button2val2 = (digitalRead(Button2));

  if (Button2val == Button2val2)
  {
    if (Button2val != buttonState2)
    {
      if (Button2val == HIGH)
      {
        Serial.println("button 2 is just pressed");         /* sends messages to the monitor */
      }
      else
      {
        Serial.println("button 2 is released");             /* checks if code is filled in, not than fills the code, if it has code it skips and goes to next */
        if (code1 == NULL)
        {
          code1 = 2;
          Serial.println("codeOne is set to 2");
        }
        else
        {
          if (code2 == NULL)
          {
            code2 = 2;
            Serial.println("codeTwo is set to 2");
          }
          else
          {
            if (code3 == NULL)
            {
              code3 = 2;
              Serial.println("codethree is set to 2");

              checkCode();
            }
          }
        }
      }
    }
    buttonState2 = Button2val;
  }

  Button3val = (digitalRead(Button3));
  delay(10);
  Button3val2 = (digitalRead(Button3));

  if (Button3val == Button3val2)
  {
    if (Button3val != buttonState3)
    {
      if (Button3val == HIGH)
      {
        Serial.println("button 3 is just pressed");         /* sends messages to the monitor */
      }
      else
      {
        Serial.println("button 3 is released");     /* checks if code is filled in, not than fills the code, if it has code it skips and goes to next */
        if (code1 == NULL)
        {
          code1 = 3;
          Serial.println("codeOne is set to 3");
        }
        else
        {
          if (code2 == NULL)
          {
            code2 = 3;
            Serial.println("codeTwo is set to 3");
          }
          else
          {
            if (code3 == NULL)
            {
              code3 = 3;
              Serial.println("codethree is set to 3");

              checkCode();
            }
          }
        }
      }
    }
    buttonState3 = Button3val;
  }
}

void reset()
{
  code1 = NULL;
  code2 = NULL;
  code3 = NULL;
}

// Method check code
void checkCode()
{
  if (code1 == 1 && code2 == 3 && code3 == 2)
  {
    digitalWrite(Led1, LOW);
    digitalWrite(Led2, HIGH);
    delay(3000);
    digitalWrite(Led2, LOW);
    digitalWrite(Led1, HIGH);

    reset();
  }
  else
  {
    digitalWrite(Led1, LOW);
    delay(500);
    digitalWrite(Led1, HIGH);
    delay(500);
    digitalWrite(Led1, LOW);
    delay(500);
    digitalWrite(Led1, HIGH);
    delay(500);
    digitalWrite(Led1, LOW);
    delay(500);
    digitalWrite(Led1, HIGH);

    reset();
  }
}
