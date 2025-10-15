#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
int btnE = 10;
int btnO = 9;
int btnF = 8;
int btnS = 7;

byte EE[8] = {
  B01110,
  B10001,
  B01110,
  B10001,
  B11111,
  B10000,
  B01110,
  B00000
};

byte OO[8] = {
  B01110,
  B10001,
  B01110,
  B10001,
  B10001,
  B10001,
  B01110,
  B00000
};

byte EF[8] = {
  B01100,
  B00010,
  B01110,
  B10001,
  B11111,
  B10000,
  B01110,
  B00000
};

byte ES[8] = {
  B00110,
  B01000,
  B01110,
  B10001,
  B11111,
  B10000,
  B01110,
  B00000
};

byte OF[8] = {
  B01100,
  B00010,
  B01110,
  B10001,
  B10001,
  B10001,
  B01110,
  B00000
};

byte OS[8] = {
  B00110,
  B01000,
  B01110,
  B10001,
  B10001,
  B10001,
  B01110,
  B00000
};

int pre_Char = 0;
int cur_Char; 
int cursorX = 0;
int cursorY = 0;

int preBtnE = LOW;
int preBtnO = LOW;
int preBtnF = LOW;
int preBtnS = LOW;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  pinMode(btnE, INPUT);
  pinMode(btnO, INPUT);
  pinMode(btnF, INPUT);
  pinMode(btnS, INPUT);
  lcd.createChar(0, EE);
  lcd.createChar(1, OO);
  lcd.createChar(2, EF);
  lcd.createChar(3, ES);
  lcd.createChar(4, OF);
  lcd.createChar(5, OS);
  lcd.setCursor(cursorX, cursorY);
}

void loop() {
  // put your main code here, to run repeatedly:
  int curBtnE = digitalRead(btnE);
  int curBtnO = digitalRead(btnO);
  int curBtnF = digitalRead(btnF);
  int curBtnS = digitalRead(btnS);

  cur_Char = 0;
  
  if (curBtnE == HIGH && preBtnE == LOW) {
    if (pre_Char == 1) cur_Char = 5;
    else cur_Char = 1;
  }
  if (curBtnO == HIGH && preBtnO == LOW) {
    if (pre_Char == 2) cur_Char = 6;
    else cur_Char = 2;
  }
  if (curBtnF == HIGH && preBtnF == LOW) {
    if (pre_Char == 1) cur_Char = 7;
    else if (pre_Char == 2) cur_Char = 9;
    else cur_Char = 3;
  }
  if (curBtnS == HIGH && preBtnS == LOW) {
    if (pre_Char == 1) cur_Char = 8;
    else if (pre_Char == 2) cur_Char = 10;
    else cur_Char = 4;
  }

  switch (cur_Char) {
    case 1: {
      lcd.setCursor(cursorX, cursorY);
      lcd.print("E");
      cursorX++;
      if (cursorX > 15) {
        cursorX = 0;
        cursorY++;
        if (cursorY > 1) cursorY = 0;
      }
      pre_Char = cur_Char;
      break;
    }
    case 2: {
      lcd.setCursor(cursorX, cursorY);
      lcd.print("O");
      cursorX++;
      if (cursorX > 15) {
        cursorX = 0;
        cursorY++;
        if (cursorY > 1) cursorY = 0;
      }
      pre_Char = cur_Char;
      break;
    }
    case 3: {
      lcd.setCursor(cursorX, cursorY);
      lcd.print("F");
      cursorX++;
      if (cursorX > 15) {
        cursorX = 0;
        cursorY++;
        if (cursorY > 1) cursorY = 0;
      }
      pre_Char = cur_Char;
      break;
    }
    case 4: {
      lcd.setCursor(cursorX, cursorY);
      lcd.print("S");
      cursorX++;
      if (cursorX > 15) {
        cursorX = 0;
        cursorY++;
        if (cursorY > 1) cursorY = 0;
      }
      pre_Char = cur_Char;
      break;
    }
    case 5: {
      if (cursorX == 0) {
        if (cursorY == 0) {
          lcd.setCursor(15, 1);
        }
        else lcd.setCursor(15, 0);
      }
      else {
        lcd.setCursor(cursorX - 1, cursorY);
      }
      lcd.print(char(0));
      pre_Char = cur_Char;
      break;
    }
    case 6: {
      if (cursorX == 0) {
        if (cursorY == 0) {
          lcd.setCursor(15, 1);
        }
        else lcd.setCursor(15, 0);
      }
      else {
        lcd.setCursor(cursorX - 1, cursorY);
      }
      lcd.print(char(1));
      pre_Char = cur_Char;
      break;
    }
    case 7: {
      if (cursorX == 0) {
        if (cursorY == 0) {
          lcd.setCursor(15, 1);
        }
        else lcd.setCursor(15, 0);
      }
      else {
        lcd.setCursor(cursorX - 1, cursorY);
      }
      lcd.print(char(2));
      pre_Char = cur_Char;
      break;
    }
    case 8: {
      if (cursorX == 0) {
        if (cursorY == 0) {
          lcd.setCursor(15, 1);
        }
        else lcd.setCursor(15, 0);
      }
      else {
        lcd.setCursor(cursorX - 1, cursorY);
      }
      lcd.print(char(3));
      pre_Char = cur_Char;
      break;
    }
    case 9: {
      if (cursorX == 0) {
        if (cursorY == 0) {
          lcd.setCursor(15, 1);
        }
        else lcd.setCursor(15, 0);
      }
      else {
        lcd.setCursor(cursorX - 1, cursorY);
      }
      lcd.print(char(4));
      pre_Char = cur_Char;
      break;
    }
    case 10: {
      if (cursorX == 0) {
        if (cursorY == 0) {
          lcd.setCursor(15, 1);
        }
        else lcd.setCursor(15, 0);
      }
      else {
        lcd.setCursor(cursorX - 1, cursorY);
      }
      lcd.print(char(5));
      pre_Char = cur_Char;
      break;
    }
    default: {
      
    }
  }
  
  preBtnE = curBtnE;
  preBtnO = curBtnO;
  preBtnF = curBtnF;
  preBtnS = curBtnS;
}