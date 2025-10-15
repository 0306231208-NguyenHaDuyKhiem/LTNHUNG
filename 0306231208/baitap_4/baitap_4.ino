int btn=8;
int led_y=3;
int led_r=4;
int count=1;
int pre_btn=LOW;
void setup() {
  // put your setup code here, to run once:
  pinMode(btn,INPUT);
  pinMode(led_y,OUTPUT);
  pinMode(led_r,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int cur_btn= digitalRead(btn);
  if(pre_btn==LOW && cur_btn==HIGH)
    {
      switch (count){
        case 1:
            digitalWrite(led_y,HIGH);
            digitalWrite(led_r,HIGH);
          break;
        case 2:
            digitalWrite(led_y,LOW);
            digitalWrite(led_r,LOW);
          break;
        case 3:
            digitalWrite(led_y,HIGH);
            digitalWrite(led_r,LOW);
          break;
        case 4:
            digitalWrite(led_y,LOW);
            digitalWrite(led_r,HIGH);
          break;
        default:
            digitalWrite(led_y,LOW);
            digitalWrite(led_r,LOW);
            count=0;
          break;
      }
      count++;
      pre_btn=cur_btn;
    }
    pre_btn=cur_btn;
   
    
  
}
