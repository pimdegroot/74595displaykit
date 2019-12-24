#define row0 PA0
#define row1 PA1
#define row2 PA2
#define row3 PA3

#define OE PA4
#define LAT PA5
#define CLK PA6
#define SER PA7

byte a, b, c, d;
unsigned long endtime;

void setup() {
  // put your setup code here, to run once:
  pinMode(row0,OUTPUT);
  pinMode(row1,OUTPUT);
  pinMode(row2,OUTPUT);
  pinMode(row3,OUTPUT);
  pinMode(OE,OUTPUT);
  pinMode(LAT,OUTPUT);
  pinMode(CLK,OUTPUT);
  pinMode(SER,OUTPUT);

  digitalWrite(row0,HIGH);
  digitalWrite(row1,HIGH);
  digitalWrite(row2,HIGH);
  digitalWrite(row3,HIGH);

  digitalWrite(OE,LOW);

  digitalWrite(LAT,LOW);
  digitalWrite(CLK,LOW);

  digitalWrite(SER,HIGH);
  
  for(int i=0;i<8;i++){
    digitalWrite(CLK,HIGH);
    delay(1);
    digitalWrite(CLK,LOW);
  }

  digitalWrite(LAT,HIGH);
  digitalWrite(LAT,LOW);

  a=0;
  b=0;
  c=0;
  d=0;

  endtime = millis() + 100;

}

void loop() {
  // put your main code here, to run repeatedly:

  if (millis() == endtime) {
    endtime = millis() + 100;
    d=c;
    c=b;
    b=a;
    a++;
  }

  for(int i=0;i<8;i++){
    digitalWrite(SER,bitRead(a,i));
    delayMicroseconds(50);
    digitalWrite(CLK,HIGH);
    delayMicroseconds(50);
    digitalWrite(CLK,LOW);
  }
  digitalWrite(row3,LOW);
  digitalWrite(LAT,HIGH);
  delayMicroseconds(50);
  digitalWrite(LAT,LOW);
  digitalWrite(row0,HIGH);
  delay(1);
  

  for(int i=0;i<8;i++){
    digitalWrite(SER,bitRead(b,i));
    delayMicroseconds(50);
    digitalWrite(CLK,HIGH);
    delayMicroseconds(50);
    digitalWrite(CLK,LOW);
  }
  digitalWrite(row0,LOW);
  digitalWrite(LAT,HIGH);
  delayMicroseconds(50);
  digitalWrite(LAT,LOW);
  digitalWrite(row1,HIGH);
  delay(1);
  

  for(int i=0;i<8;i++){
    digitalWrite(SER,bitRead(c,i));
    delayMicroseconds(50);
    digitalWrite(CLK,HIGH);
    delayMicroseconds(50);
    digitalWrite(CLK,LOW);
  }
  digitalWrite(row1,LOW);
  digitalWrite(LAT,HIGH);
  delayMicroseconds(50);
  digitalWrite(LAT,LOW);
  digitalWrite(row2,HIGH);
  delay(1);
  
  
  for(int i=0;i<8;i++){
    digitalWrite(SER,bitRead(d,i));
    delayMicroseconds(50);
    digitalWrite(CLK,HIGH);
    delayMicroseconds(50);
    digitalWrite(CLK,LOW);
  }
  digitalWrite(row2,LOW);
  digitalWrite(LAT,HIGH);
  delayMicroseconds(50);
  digitalWrite(LAT,LOW);
  digitalWrite(row3,HIGH);
  delay(1);
  

  

}
