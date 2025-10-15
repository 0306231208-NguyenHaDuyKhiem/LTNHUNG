void setup() {
  // put your setup code here, to run once:
  for(int i=1;i<11;i++){
    pinMode(i,OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  int a[10];
  for(int i=0;i<10;i++){
    a[i]=random(-100,100);
  }
  for(int i=1;i<11;i++)
  {
    if(a[i-1]%2==1)
    {
      digitalWrite(i,HIGH);
    }
    else{
      digitalWrite(i,LOW);
    }
  }
  delay(500);
}
