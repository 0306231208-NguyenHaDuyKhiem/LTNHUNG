#include<LiquidCrystal.h>
LiquidCrystal lcd(12,11,5,4,3,2);
int btn_d=10;
int btn_r=9;
int btn_l=8;
int pre_d=LOW;
int pre_r=LOW;
int pre_l=LOW;
int step=0;
int row=0;
bool state=true;
String text="hello";
void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  pinMode(btn_d,INPUT);
  pinMode(btn_r,INPUT);
  pinMode(btn_l,INPUT);
  lcd.setCursor(0,0);
  lcd.print(text);
}

void loop() {
  // put your main code here, to run repeatedly:
  int cur_d=digitalRead(btn_d);
  int cur_r=digitalRead(btn_r);
  int cur_l=digitalRead(btn_l);
  if(pre_d==LOW && cur_d==HIGH)
    {
      if(state==true)
      {
        lcd.noDisplay();
        state=false;
      }
      else{
        lcd.display();
        state=true;
      }
      
    }
    pre_d=cur_d;
  if(pre_r==LOW && cur_r==HIGH)
    {
      if(step==16 && row==0)
        {
          row=1;
          step=0;
        }
      else if(step==16 && row==1){
           row=0;
          step=0;
      }
    
      delay(200);
      lcd.clear();
      lcd.setCursor(step,row);
      lcd.print(text);
      step++;

    }  
  if(pre_l==LOW && cur_l==HIGH)
    {
      if(step==0 && row==0)
        {
          row=1;
          step=16;
        }
      else if(step==0 && row==1)
            {
              step=16;
              row=0;
            }
       step--;
      delay(200);
      lcd.clear();
      lcd.setCursor(step,row);
      lcd.print(text);
    }
    pre_l=cur_l;
}
