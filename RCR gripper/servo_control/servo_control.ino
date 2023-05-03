#include <Servo.h>

Servo servo1;
Servo servo2;

int step = 2;

int servo1Home = 60;
int servo2Home = 126;

int servo1Active = 120;
int servo2Active = 66;

int LED1 = 8;
int LED2 = 9;

int downBotton = 10;
int upBotton = 11;
int cfgBotton = 12;

int servo1Val = servo1Home;
int servo2Val = servo2Home;

int mode = 1;

void  setup()
{
  Serial.begin(9600);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);

  servo1.attach(5);
  servo2.attach(6);

  servo1.write(servo1Home);
  servo2.write(servo2Home);

  pinMode(downBotton, INPUT_PULLUP);
  pinMode(upBotton, INPUT_PULLUP);
  pinMode(cfgBotton, INPUT_PULLUP);

  Serial.println("-----------");
  Serial.println("-- Start --");
  Serial.println("-----------");
  delay(100);
}

void  loop(){
  int downVal = digitalRead(downBotton);
  int upVal = digitalRead(upBotton);
  int cfgVal = digitalRead(cfgBotton);

  digitalWrite(LED1, LOW);
  digitalWrite(LED2, LOW);
  if(cfgVal==0){
    mode += 1;
    delay(100);
  }

  switch (mode) {
  
  case 1:
    if(upVal==0){
      servo1Val = servo1Active;
      servo2Val = servo2Active;
    }
    else if(downVal==0){
      servo1Val = servo1Home;
      servo2Val = servo2Home;
    }
    break;
  
  case 2:
    digitalWrite(LED1, HIGH);
    servo1Val = servo1Home;
    if(upVal==0){
      servo1Home += step;
    }
    else if(downVal==0){
      servo1Home -= step;
    }
    // delay(50);
    break;
  
  case 3:
    digitalWrite(LED2, HIGH);
    servo1Val = servo1Active;
    if(upVal==0){
      servo1Active += step;
    }
    else if(downVal==0){
      servo1Active -= step;
    }
    // delay(50);
    break;
  
  case 4:
    if(upVal==0){
      servo1Val = servo1Active;
      servo2Val = servo2Active;
    }
    else if(downVal==0){
      servo1Val = servo1Home;
      servo2Val = servo2Home;
    }
    break;
    break;
  
  case 5:
    digitalWrite(LED1, HIGH);
    servo2Val = servo2Home;
    if(upVal==0){
      servo2Home -= step;
    }
    else if(downVal==0){
      servo2Home += step;
    }
    // delay(50);
    break;
  
  case 6:
    digitalWrite(LED2, HIGH);
    servo2Val = servo2Active;
    if(upVal==0){
      servo2Active -= step;
    }
    else if(downVal==0){
      servo2Active += step;
    }
    // delay(50);
    break;
  }

  if(mode>6){
    mode=1;
  }
  if(servo1Home<0){
    servo1Home=0;
  }
  if(servo2Home>180){
    servo2Home=180;
  }
  if(servo1Active>180){
    servo1Active=180;
  }
  if(servo2Active<0){
    servo2Active=0;
  }

  Serial.print("mode : ");
  Serial.println(mode);
  servo1.write(servo1Val);
  Serial.print("servo1Val : ");
  Serial.println(servo1Val);
  servo2.write(servo2Val);
  Serial.print("servo2Val : ");
  Serial.println(servo2Val);

  delay(50);
}



  