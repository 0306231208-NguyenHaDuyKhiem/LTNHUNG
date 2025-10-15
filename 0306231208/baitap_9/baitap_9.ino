#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
bool state=true;
int btn=10;
int lm35=A0;
int pre_btn=LOW;
float pre_temp=0;
void setup() {
  // put your setup code here, to run once:
  lcd.begin(12,6);
  pinMode(btn,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
   float temp = (5.0 * analogRead(lm35) * 100.0 / 1024.0);
  float tempF = (temp * 1.8) + 32;
  int cur_btn=digitalRead(btn);
  if(pre_btn==LOW && cur_btn==HIGH)
  {
    if(state==true)
    {
      state=false;
      
    }
    else{
      state=true;
      
    }
  }
  pre_btn=cur_btn;
 
  if(state==true)
    {
      if(temp!=pre_temp){
         
      lcd.setCursor(0, 0);
     
      lcd.print(temp);
       pre_temp=temp;
       
      }
     
    }
  else{
    if(temp!=pre_temp){
     
      lcd.setCursor(0, 0);
      
      lcd.print(tempF);
       pre_temp=temp;
      }
  }


}
