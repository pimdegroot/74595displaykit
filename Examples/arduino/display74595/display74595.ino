byte a, b, c, d;

void setup() {
  // put your setup code here, to run once:
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(9,OUTPUT);

  digitalWrite(2,HIGH);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,HIGH);

  digitalWrite(6,LOW);

  digitalWrite(7,LOW);
  digitalWrite(8,LOW);

  digitalWrite(9,HIGH);
  
  for(int i=0;i<8;i++){
    digitalWrite(8,HIGH);
    digitalWrite(8,LOW);
  }

  digitalWrite(7,HIGH);
  digitalWrite(7,LOW);

  a=0;
  b=0;
  c=0;
  d=0;

}

void loop() {
  // put your main code here, to run repeatedly:
  a++;
  if(bitRead(a,4)==1){
    b++;
  }
  if(bitRead(b,2)==1){
    c++;
  }
  if(bitRead(c,3)==1){
    d++;
  }



  shiftOut(9,8,MSBFIRST,a);
  digitalWrite(7,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(2,HIGH);
  delay(5);
  digitalWrite(2,LOW);

  shiftOut(9,8,MSBFIRST,b);
  digitalWrite(7,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(3,HIGH);
  delay(5);
  digitalWrite(3,LOW);

  shiftOut(9,8,MSBFIRST,c);
  digitalWrite(7,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(4,HIGH);
  delay(5);
  digitalWrite(4,LOW);
  
  shiftOut(9,8,MSBFIRST,d);
  digitalWrite(7,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(5,HIGH);
  delay(5);
  digitalWrite(5,LOW);

  

}
