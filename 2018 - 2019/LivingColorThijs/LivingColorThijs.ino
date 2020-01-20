//Made by Thijs van Kessel 82405 ic18ao.e
//finished on 30-1-2019

//on witch pins the leds is attached
int GreenLight = 9;
int BlueLight = 10;
int RedLight = 11;

//Color range
int Red = 255;
int Green = 0;
int Blue = 0;

//declaring the button
int Button = 2;
int buttonState = 0;
int val1;
int val2;

//Cycles for the stop and start function
bool StopCycle = true;
bool start = false;

void setup()
{
  pinMode(Button, INPUT);
  pinMode(RedLight, OUTPUT);
  pinMode(BlueLight, OUTPUT);
  pinMode(GreenLight, OUTPUT);
  Serial.begin(9600);
  buttonState = digitalRead(Button);
  StartRGB();
}

void ButtonDebounce()
{
  val1 = digitalRead(Button);
  delay(10);
  val2 = digitalRead(Button);
  if (val1 == val2)
  {
    if (val1 != buttonState)
    {
      if (val1 == HIGH)
      {
        if (StopCycle == true)
        {
          StopCycle = false;
          Serial.println("Pressed Start");
        }
        else if (StopCycle == false)
        {
          StopCycle = true;
          Serial.println("Pressed Stop");
        }
      }
    }
    buttonState = val1;
  }
}

void loop()
{
  ButtonDebounce();
  ColorCycle();

  if (StopCycle == false) {
    Serial.println("R =" + (String)Red + " G =" + (String)Green + " B =" + (String)Blue);
  }
}
void StartRGB()
{
  //Starts the LEDS
  Red = 255;
  Update();

  delay(500);
  //Makes green out of red
  Red = 0;
  Green = 255;
  Update();

  delay(500);
  //Makes blue out of green
  Green = 0;
  Blue = 255;
  Update();

  delay(500);
  //Makes red out of blue
  Blue = 0;
  Red = 255;
  Update();
}

void ColorCycle()
{
  if (StopCycle == false)
  {
    //Red to Blue
    if (Red == 255 && Green == 0 && Blue < 255) {
      Blue = Blue + 1;
    }
    //Fade Red
    else if (Red > 0 && Green == 0 && Blue == 255) {
      Red = Red - 1;
    }
    //Blue to Green
    else if (Red == 0 && Green < 255 && Blue == 255) {
      Green = Green + 1;
    }
    //Fade Blue
    else if (Red == 0 && Green == 255 && Blue > 0) {
      Blue = Blue - 1;
    }
    //Green to Red
    else if (Red < 255 && Green == 255 && Blue == 0) {
      Red = Red + 1;
    }
    //Fade Green
    else if (Red == 255 && Green > 0 && Blue == 0) {
      Green = Green - 1;
    }
    Update();
  }
}

void Update()
{
  //update's the color of the led
  analogWrite(RedLight, Red);
  analogWrite(BlueLight, Blue);
  analogWrite(GreenLight, Green);
}
