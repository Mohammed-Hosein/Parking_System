'
int xPin=A0;
int yPin=A1;

int out1=8;     //output1 for HT12E IC
int out2=9;     //output1 for HT12E IC
int out3=10;    //output1 for HT12E IC
int out4=11;    //output1 for HT12E IC

void setup(){
  Serial.begin(9600);
  pinMode(xPin,INPUT);
  pinMode(yPin,INPUT);

  pinMode(out1,OUTPUT);
  pinMode(out2,OUTPUT);
  pinMode(out3,OUTPUT);
  pinMode(out4,OUTPUT);
}


void loop() 
{
  int xval=analogRead(xPin);
  int yval=analogRead(yPin);

  if ((xval>320 && xval<350) && (yval>320 && yval<350)) //stop
  {
    digitalWrite(out1,LOW);  
    digitalWrite(out2,LOW);   
    digitalWrite(out3,LOW);   
    digitalWrite(out4,LOW);
    Serial.println("stop");
  } 

  else 
  { 
    if ((xval>320 && xval<350) && (yval>250 && yval<300)) //forward
   {
     digitalWrite(out1,HIGH);  
     digitalWrite(out2,LOW);   
     digitalWrite(out3,HIGH);  
     digitalWrite(out4,LOW);
     Serial.println("forward");
      
    }
    if ((xval>320 && xval<350) && (yval>355 && yval<400)) //backward
  {
   digitalWrite(out1,LOW);   
   digitalWrite(out2,HIGH);  
   digitalWrite(out3,LOW);   
   digitalWrite(out4,HIGH);
   Serial.println("back");
      
    }   

    if ((xval>355 && xval<400) && (yval>320 && yval<350)) //left
    {
      digitalWrite(out1,HIGH);  
      digitalWrite(out2,LOW);   
      digitalWrite(out3,LOW);   
      digitalWrite(out4,HIGH);
      Serial.println("left");
     }


    if ((xval>250 && xval<300) && (yval>320 && yval<350))//right
    {
      digitalWrite(out1,LOW);  
      digitalWrite(out2,HIGH);   
      digitalWrite(out3,HIGH);   
      digitalWrite(out4,LOW);
      Serial.println("right");
    }
  }
}
