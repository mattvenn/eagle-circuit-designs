#define LED1 0 //pin 5
//#define LED2 2 //pin 7 - problem with v1, wasn't connected
#define TEMP A1 //pin 7
#define CUR A2 //pin 3
#define TRIAC 3 //pin 2
#define TEMP_HIGH 60
#define ON_DELAY 1000

//just looked at the numbers and guessed - not in real units
#define thresh 10000
//turn off after 2 second
#define off_delay 2000


unsigned long time = 0;

void setup()
{
  pinMode(LED1,OUTPUT);
  pinMode(TRIAC,OUTPUT);
  digitalWrite(TRIAC,LOW);
  digitalWrite(LED1,HIGH);
  for( int i = 0; i < 4; i ++)
  {
      digitalWrite(LED1,LOW);
      delay(100);
      digitalWrite(LED1,HIGH);
      delay(100);
  }
  digitalWrite(LED1,LOW);
  //Serial.begin(9600);

}

void loop()
{
  int sample;
  int offset = 512;
  
  double accum = 0;
  for( int i =0; i< 250; i++)
  {
    sample = analogRead(CUR) - offset;
    accum = accum + sample * sample;
  }

  int rawvoltage= analogRead(TEMP);
  float celcius= (rawvoltage/1024.0) * 500 - 273.15;

  //safety temp
  if(celcius > TEMP_HIGH)
  {
     digitalWrite(TRIAC,LOW);
     digitalWrite(LED1,LOW);
  }
  else
  {
      if(accum > thresh)
      {
         digitalWrite(LED1,HIGH);
         //delay to avoid blowing fuses
         delay(ON_DELAY);
         digitalWrite(TRIAC,HIGH);
         time = millis();
        //Serial.println("on");
      }
      else if(millis() > time + off_delay)
      {
        digitalWrite(LED1,LOW);
        digitalWrite(TRIAC,LOW);
        //Serial.println("off");
      }
  }
  delay(100);
}
