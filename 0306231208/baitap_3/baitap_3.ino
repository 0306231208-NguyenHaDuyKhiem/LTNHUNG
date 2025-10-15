int btn_up=9;
int btn_down=8;
int led=3;
;
int delay_step=100;

int delay_start=500;
int pre_up=LOW;
int pre_down=LOW;
void setup() {
  // put your setup code here, to run once:
  pinMode(led,OUTPUT);
  pinMode(btn_up,INPUT);
  pinMode(btn_down,INPUT);
}

void loop() {
  if(pre_up==LOW && digitalRead(btn_up)==HIGH)
    {
      delay_start+=delay_step;
      pre_up=digitalRead(btn_up);
    }
    pre_up=digitalRead(btn_up);
    
    if(pre_down==LOW && digitalRead(btn_down)==HIGH){
      delay_start-=delay_step;
      pre_down=digitalRead(btn_down);
    }
    pre_down=digitalRead(btn_down);
    digitalWrite(led,HIGH);
    delay(delay_start);
    digitalWrite(led,LOW);
    delay(delay_start);


}
