  #define s0 3       //Module pins wiring
  #define s1 2
  #define s2 4
  #define s3 7
  #define out 8

  #define pistPull 9
  #define pistPush 10
  
  #include<Servo.h>
  
  Servo Myservo;
  
  int data=0;
  int red=0;
  int blue=0;
  int green=0;
  
  void setup() 
  {
     Myservo.attach(6);
  
     pinMode(pistPull, OUTPUT);
     pinMode(pistPush, OUTPUT);
    
     pinMode(s0,OUTPUT);    
     pinMode(s1,OUTPUT);
     pinMode(s2,OUTPUT);
     pinMode(s3,OUTPUT);
     pinMode(out,INPUT);
  
     Serial.begin(115200);   
     
     digitalWrite(s0,HIGH); 
     digitalWrite(s1,HIGH); 
     
  }
  
  void loop()                  
  {
  
     digitalWrite(s2,LOW);       
     digitalWrite(s3,LOW); 
     red=GetData();             
  
     digitalWrite(s2,LOW);
     digitalWrite(s3,HIGH);
     blue=GetData();
  
     digitalWrite(s2,HIGH);
     digitalWrite(s3,HIGH);
     green=GetData();
  
     Serial.println();
  
     if (red<blue && red<=green && red<23) { 
        Serial.println("Red");
        Myservo.write(0);
        push();
     }
  
    else if (blue<green && blue<red && blue<21) {   
        Serial.println("Blue");
        Myservo.write(45);
        push();
    }
  
    else if (green<red && (green-blue)<= 8) { 
        Serial.println("Green"); 
        Myservo.write(90);
        push();            
    }
  
    else {
       Serial.println();
    }
    
     delay(200);
  }
  
  int GetData(){
     data=pulseIn(out,LOW);            
     delay(20);
     return data;
  }
  
  void push(){
     digitalWrite(pistPush, HIGH);
     digitalWrite(pistPull, LOW);
     delay(1000);
     digitalWrite(pistPull, LOW);
     digitalWrite(pistPush, HIGH);
  }
