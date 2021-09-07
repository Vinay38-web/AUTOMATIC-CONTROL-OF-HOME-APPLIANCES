#include <SoftwareSerial.h>
const int rxPin = 11;
const int txPin = 12;               
SoftwareSerial mySerial(rxPin, txPin);
int light=8;
int fan=9;
String data;
void setup() 
{
   Serial.begin(9600);
   mySerial.begin(9600); 
   pinMode(fan, OUTPUT);
   pinMode(light, OUTPUT); 
   digitalWrite(fan, LOW);
   digitalWrite(light, LOW);
}
void loop() 
{
    int i=0;
    data="";
   /* while(1)
    { 
      while(mySerial.available()<=0);
      ch = mySerial.read();
      if(ch=='#')
      break;
      data+=ch;
    }*/
   while(mySerial.available()<=0);
   data=mySerial.readString();
   Serial.println(data);
    
    if(data=="turn on light")
    { 
      digitalWrite(light,HIGH);
      Serial.println("light on");
    }
    else if(data=="turn off light")
    {
      digitalWrite(light,LOW);
      Serial.println("light off");
    }
    else if(data=="turn on fan")
    {
      digitalWrite(fan,HIGH);
      Serial.println("fan on");
    }
    else if(data=="turn off fan")
    {
      digitalWrite(fan,LOW);
      Serial.println("fan off");
    }
    else if(data=="turn on all")
    {
      digitalWrite(fan,HIGH);
      digitalWrite(light,HIGH);
      Serial.println("all on");
    }
    else if(data=="turn off all")
    {
      digitalWrite(fan,LOW);
      digitalWrite(light,LOW);
      Serial.println("all off"); 
    }
}
