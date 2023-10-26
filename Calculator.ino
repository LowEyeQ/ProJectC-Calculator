
#include <LiquidCrystal.h>

#include <Keypad.h> 


const byte ROWS = 4; 

const byte COLS = 4; 


char keys[ROWS][COLS] = {


  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}


};


byte rowPins[ROWS] = { 7, 6, 5, 4 };

byte colPins[COLS] = { 3, 2, 1, 0 };


Keypad kpd = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS ); 


const int rs = 13, en = 12, d4 = 11, d5 = 10, d6 = 9, d7 = 8;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);


int count = 0,mod=0;
 double Num1,Num2,Number,Num3;

 char key,action;

 boolean result = false;

 

void setup() {

  lcd.begin(16, 2);

  lcd.setCursor(0, 1);

  lcd.print("Calculator");


   delay(2000);

    lcd.clear();

}


void loop() {

  

key = kpd.getKey();


if (key!=NO_KEY)

DetectButtons();


if (result==true){
  CalculateResult();

  if(mod != 0){
    DisplayError();
    delay(50);
    mod=0;
  }else{
    DisplayResult(); 
  }  
}else{
  DisplayResult(); 
}


}


void DetectButtons()

{ 

     lcd.clear();

    if (key=='*') 

    {Number=Num1=Num2=Num3=0; result=false;count=0;}

     if (key == '1'){
      if (Number==0){
        Number=1;
      }else{
        Number = (Number*10) + 1;
      }}

    if (key == '2'){
      if (Number==0){
        Number=2;
      }else{
        Number = (Number*10) + 2;
    }}

    if (key == '3'){
      if (Number==0){
        Number=3;
      }else{
        Number = (Number*10) + 3;
      }}

     if (key == '4'){
      if (Number==0){
        Number=4;
      }else{
        Number = (Number*10) + 4;
      }}

      if (key == '5'){
      if (Number==0){
        Number=5;
      }else{
        Number = (Number*10) + 5;
      }}

      if (key == '6'){
      if (Number==0){
        Number=6;
      }else{
        Number = (Number*10) + 6;
      }}

    if (key == '7'){
      if (Number==0){
        Number=7;
      }else{
        Number = (Number*10) + 7;
      }}

    if (key == '8'){
      if (Number==0){
        Number=8;
      }else{
        Number = (Number*10) + 8;
      }}

    if (key == '9'){
      if (Number==0){
        Number=9;
      }else{
        Number = (Number*10) + 9;
      }}

    if (key == '0'){
      if (Number==0){
        Number=0;
      }else{
        Number = (Number*10);
      }}

    if (key == '#'){
      Num2=Number;
      result = true;
}

      if (key == 'A' || key == 'B' || key == 'C' || key == 'D')
  {
    // Num1 = Num3;
    Num1 = Number;    
    Number =0;

    if (key == 'A')
    {action = '+';
    if(count != 0){
      Num1 = Num3;
      Num2 = 0;
      Num3 = 0;
      Number = 0;
      }
    }

     if (key == 'B'){
      action = '-'; 
      if(count != 0){
      Num1 = Num3;
      Num2 = 0;
      Num3 = 0;
      Number = 0;
      }
      }

     if (key == 'C'){
      action = '*';
      if(count != 0){
      Num1 = Num3;
      Num2 = 0;
      Num3 = 0;
      Number = 0;
      }
      }

     if (key == 'D'){
      action = '/';
      if(count != 0){
        if(mod == 0){
          Num1 = Num3;
          Num2 = 0;
          Num3 = 0;
          Number = 0;
        }else{
          Num1 = Num3;
          Num2 = 0;
          Num3 = 0;
          Number = 0;
          mod = 0;
        }
      
      }
      }  
    delay(100);

  }

  

}


void CalculateResult()

{

  if (action=='+'){
      Num3 = Num1 + Num2;
      ++count;
  }

  if (action=='-')

    Num3 = Num1-Num2;
    ++count;

  if (action=='*')

    Num3 = Num1*Num2;
    ++count;

  if (action=='/')
    if((long)Number == 0){
      mod++;
      ++count;
    }else{
      Num3 = Num1/Num2; 
      ++count;
    }
}


void DisplayResult()

{
    lcd.setCursor(0, 0); 
    lcd.print((long)Num1); lcd.print(action); lcd.print((long)Num2);
     if (result==true)

    {lcd.print(" ="); lcd.print(Num3);}

    

    lcd.setCursor(0, 1);

    lcd.print((long)Number);
    // lcd.print((long)Num1);lcd.print('-');lcd.print((long)Num2);lcd.print('-');lcd.print((long)Num3);lcd.print('-');lcd.print(Number);lcd.print('-');lcd.print(mod);lcd.print('-');lcd.print(count);
}

void DisplayError()
{
    lcd.setCursor(0, 0); 

    lcd.print("Error");

    lcd.setCursor(0, 1); 

    lcd.print((long)Number); 
    // lcd.print((long)Num1);lcd.print('-');lcd.print((long)Num2);lcd.print('-');lcd.print((long)Num3);lcd.print('-');lcd.print((long)Number);lcd.print('-');lcd.print(count);lcd.print('-');lcd.print(mod);
    mod=0;
}