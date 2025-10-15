
int cot1_do = 2;
int cot1_vang = 3;
int cot1_xanh = 4;

int cot2_do = 5;
int cot2_vang = 6;
int cot2_xanh = 7;


int time_xanh = 5000; 
int time_vang = 2000; 
int time_delay = 500; 

void setup() {
  pinMode(cot1_do, OUTPUT);
  pinMode(cot1_vang, OUTPUT);
  pinMode(cot1_xanh, OUTPUT);
  pinMode(cot2_do, OUTPUT);
  pinMode(cot2_vang, OUTPUT);
  pinMode(cot2_xanh, OUTPUT);


  digitalWrite(cot1_xanh, HIGH);
  digitalWrite(cot2_do, HIGH);
}

void loop() {
 
  digitalWrite(cot1_xanh, HIGH);
  digitalWrite(cot1_vang, LOW);
  digitalWrite(cot1_do, LOW);

  digitalWrite(cot2_do, HIGH);
  digitalWrite(cot2_vang, LOW);
  digitalWrite(cot2_xanh, LOW);

  delay(time_xanh);


  digitalWrite(cot1_xanh, LOW);
  digitalWrite(cot1_vang, HIGH);
  delay(time_vang);

  
  digitalWrite(cot1_vang, LOW);
  digitalWrite(cot1_do, HIGH);

  digitalWrite(cot2_do, LOW);
  digitalWrite(cot2_xanh, HIGH);
  delay(time_xanh);

 
  digitalWrite(cot2_xanh, LOW);
  digitalWrite(cot2_vang, HIGH);
  delay(time_vang);


  digitalWrite(cot2_vang, LOW);
  digitalWrite(cot2_do, HIGH);
  digitalWrite(cot1_do, LOW);

  delay(time_delay);
}
