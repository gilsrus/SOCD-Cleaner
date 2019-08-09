const uint8_t upIN = 2;
const uint8_t downIN = 3;
const uint8_t leftIN = 4;
const uint8_t rightIN = 5;

const uint8_t leftOUT = 6;
const uint8_t rightOUT = 7;
const uint8_t upOUT = 8;
const uint8_t downOUT = 9;

const uint8_t jumpper1Pin = 10;
const uint8_t jumpper2Pin = 14;


uint8_t leftRead;
uint8_t downRead;
uint8_t upRead;
uint8_t rightRead;

uint8_t jumpper1Read;
uint8_t jumpper2Read;

unsigned long currentMillis;
unsigned long upPreviousMillis = 0;
unsigned long downPreviousMillis = 0;
unsigned long leftPreviousMillis = 0;
unsigned long rightPreviousMillis = 0;

uint8_t upPreviousState = 0; 
uint8_t downPreviousState = 0;
uint8_t leftPreviousState = 0; 
uint8_t rightPreviousState = 0; 

uint8_t mode;

void setup() {

// Serial.begin(9600);
 pinMode(leftIN, INPUT_PULLUP);
 pinMode(rightIN, INPUT_PULLUP);
 pinMode(upIN, INPUT_PULLUP);
 pinMode(downIN, INPUT_PULLUP);
 
 pinMode(leftOUT, OUTPUT);
 pinMode(rightOUT, OUTPUT);
 pinMode(downOUT, OUTPUT);
 pinMode(upOUT, OUTPUT);

 pinMode(jumpper1Pin,INPUT_PULLUP);
 pinMode(jumpper2Pin,INPUT_PULLUP);

 
  jumpper1Read = digitalRead(jumpper1Pin);
  jumpper2Read = digitalRead(jumpper2Pin);
  
  if(jumpper1Read && jumpper2Read)  mode = 3;
  if(!jumpper1Read && jumpper2Read) mode = 1;
  if(jumpper1Read && !jumpper2Read) mode = 2;
  if(!jumpper1Read && !jumpper2Read) mode = 0;



}

void loop() {


  currentMillis = millis();

  upRead = digitalRead(upIN);
  downRead = digitalRead(downIN);
  leftRead = digitalRead(leftIN);
  rightRead = digitalRead(rightIN);
  
  switch (mode)
  {
  case 0:
    outputRAW();
    break;
  
  case 1:
    outputSODC();
    break;

  case 2:
    outputLASTCOMMAND();
    break;

  case 3:
    outputLASTCOMMANDnSODC();
    break;

  default:
    mode = 0;
    break;
  }


}

void outputRAW(){
if(!upRead)    digitalWrite(upOUT,LOW);
if(upRead)     digitalWrite(upOUT,HIGH);

if(!downRead)  digitalWrite(downOUT,LOW);
if(downRead)   digitalWrite(downOUT,HIGH);

if(!leftRead)  digitalWrite(leftOUT,LOW);
if(leftRead)   digitalWrite(leftOUT,HIGH);

if(!rightRead) digitalWrite(rightOUT,LOW);
if(rightRead)  digitalWrite(rightOUT,HIGH);

}

void outputSODC(){
   if (!leftRead)
  {
    if (rightRead)
    {
      digitalWrite(rightOUT, HIGH);
      digitalWrite(leftOUT, LOW);
    }
    else
    {
      digitalWrite(rightOUT, HIGH);
      digitalWrite(leftOUT, HIGH);
    }
  }
  else if (!rightRead)
  {
    digitalWrite(leftOUT, HIGH);
    digitalWrite(rightOUT, LOW);
  }
  else
  {
    digitalWrite(rightOUT, HIGH);
    digitalWrite(leftOUT, HIGH);
  }

  
  if (!upRead)
  {
    digitalWrite(downOUT, HIGH);
    digitalWrite(upOUT, LOW);
  }
  else if (!downRead)
  {
    {
      digitalWrite(downOUT, LOW);
      digitalWrite(upOUT, HIGH);
    }
  }
  else
  {
    digitalWrite(upOUT, HIGH);
    digitalWrite(downOUT, HIGH);
  }

}

void outputLASTCOMMAND(){

if(!upRead){
  if(!upPreviousState){
    upPreviousMillis = currentMillis;
    upPreviousState = HIGH;
  }
  if(!downRead){
    if(upPreviousMillis > downPreviousMillis){
      digitalWrite(upOUT,LOW);
    }
    else
    {
      digitalWrite(upOUT,HIGH);
    }
    
  }
 else
 {
   digitalWrite(upOUT,LOW);
 }
}


if(upRead) {
  upPreviousState = LOW;
  digitalWrite(upOUT,HIGH);

}    

if(!downRead){
  if(!downPreviousState){
    downPreviousMillis = currentMillis;
    downPreviousState = HIGH;
  }
  if(!upRead){
    if(downPreviousMillis > upPreviousMillis){
      digitalWrite(downOUT,LOW);
    }
    else
    {
      digitalWrite(downOUT,HIGH);
    }
    
  }
 else
 {
   digitalWrite(downOUT,LOW);
 }
}


if(downRead) {
  downPreviousState = LOW;
  digitalWrite(downOUT,HIGH);

}  

if(!leftRead){
  if(!leftPreviousState){
    leftPreviousMillis = currentMillis;
    leftPreviousState = HIGH;
  }
  if(!rightRead){
    if(leftPreviousMillis > rightPreviousMillis){
      digitalWrite(leftOUT,LOW);
    }
    else
    {
      digitalWrite(leftOUT,HIGH);
    }
    
  }
 else
 {
   digitalWrite(leftOUT,LOW);
 }
}


if(leftRead) {
  leftPreviousState = LOW;
  digitalWrite(leftOUT,HIGH);

}  
if(!rightRead){
  if(!rightPreviousState){
    rightPreviousMillis = currentMillis;
    rightPreviousState = HIGH;
  }
  if(!leftRead){
    if(rightPreviousMillis > leftPreviousMillis){
      digitalWrite(rightOUT,LOW);
    }
    else
    {
      digitalWrite(rightOUT,HIGH);
    }
    
  }
 else
 {
   digitalWrite(rightOUT,LOW);
 }
}


if(rightRead) {
  rightPreviousState = LOW;
  digitalWrite(rightOUT,HIGH);

}  

}

void outputLASTCOMMANDnSODC(){

 if (!upRead)
  {
    digitalWrite(downOUT, HIGH);
    digitalWrite(upOUT, LOW);
  }
  else if (!downRead)
  {
    {
      digitalWrite(downOUT, LOW);
      digitalWrite(upOUT, HIGH);
    }
  }
  else
  {
    digitalWrite(upOUT, HIGH);
    digitalWrite(downOUT, HIGH);
  }

  
if(!leftRead){
  if(!leftPreviousState){
    leftPreviousMillis = currentMillis;
    leftPreviousState = HIGH;
  }
  if(!rightRead){
    if(leftPreviousMillis > rightPreviousMillis){
      digitalWrite(leftOUT,LOW);
    }
    else
    {
      digitalWrite(leftOUT,HIGH);
    }
    
  }
 else
 {
   digitalWrite(leftOUT,LOW);
 }
}


if(leftRead) {
  leftPreviousState = LOW;
  digitalWrite(leftOUT,HIGH);

}  
if(!rightRead){
  if(!rightPreviousState){
    rightPreviousMillis = currentMillis;
    rightPreviousState = HIGH;
  }
  if(!leftRead){
    if(rightPreviousMillis > leftPreviousMillis){
      digitalWrite(rightOUT,LOW);
    }
    else
    {
      digitalWrite(rightOUT,HIGH);
    }
    
  }
 else
 {
   digitalWrite(rightOUT,LOW);
 }
}


if(rightRead) {
  rightPreviousState = LOW;
  digitalWrite(rightOUT,HIGH);

}  

}
