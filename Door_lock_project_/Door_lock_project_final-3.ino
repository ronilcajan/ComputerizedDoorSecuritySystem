/*	PINCode Door Unlock with GizDuino
	Dev: Ronil M. Cajan & Jersel M. Alabata // Date:10/1/2018 //	*/
//Libraries
#include <Keypad.h>
#include <LiquidCrystal.h>
#include <Servo.h>

Servo myservo;//servo

LiquidCrystal lcd(A0, A1, A2, A3, A4, A5);//LCD

#define PIN_Lenght 7 // Give enough room for six chars + NULL char

int pos = 0;    // variable to store the servo position

char Data[PIN_Lenght]; // 6 is the number of chars it can hold + the null char = 7
char Master[PIN_Lenght] = "123456";
char Temp[PIN_Lenght] = "";
byte data_count = 0, master_count = 0;
bool Pass_is_good;
char customKey;
const int buzzer = 11;//small speaker/buzzer

/*-------------------------------KEYPAD---------------------------------------*/
const byte ROWS = 4;//number of rows on the keypad
const byte COLS = 4;//number of columns on the keypad
char keys[ROWS][COLS] = {
  {'1','4','7','*'},
  {'2','5','8','0'},
  {'3','6','9','#'},
  {'A','B','C','D'}
};
bool door = true;

//Code that shows the the keypad connections to the arduino terminals
byte rowPins[ROWS] = {5, 4, 3, 2}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {9, 8, 7, 6}; //connect to the column pinouts of the keypad

Keypad customKeypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS); //initialize an instance of class NewKeypad

void setup(){
  myservo.attach(10);
  ServoClose();
  lcd.begin(16, 2);//Setup the LCD's number of columns and rows 
  //Print welcome message...
  lcd.print("    Welcome!");
  lcd.setCursor(0, 1);
  lcd.print("GizDuino Project");
  delay(3000);
  lcd.clear();
}

void loop(){//Main Loop
  if (door == 0){
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("[A]-Close?");
    lcd.setCursor(0, 1);
    lcd.print("[C]-Change PIN?");
    customKey = customKeypad.getKey();
    if (customKey == 'A'){
      lcd.clear();
      ServoClose();
      tone(buzzer,500,200);
      lcd.print("  Door is close!");
      delay(2000);
      door = 1;
    }
    else if (customKey == 'C'){
      lcd.clear();
      tone(buzzer,300,100);
      lcd.setCursor(0, 0);
      lcd.print("Are you sure?");
      lcd.setCursor(0, 1);
      lcd.print("[1]YES   [2]NO");
      if (customKey == '1'){
        lcd.clear();
        PINchange();
      }
      else if (customKey == '2'){
       lcd.clear();
       door=0;
      }else{
       door=0;
      }
    }else{
      door=0;
    }
  }
  else Open(); 
}
/********************************FUNCTIONS*************************************/
void clearData(){
  while (data_count != 0){ // This can be used for any array size,
    Data[data_count--] = 0; //clear array for new data
    Temp[data_count--] = 0;
  }
  return;
}

void ServoOpen(){
  for (pos = 180; pos >= 0; pos -= 5){ // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}

void ServoClose(){
  for (pos = 0; pos <= 180; pos += 5) { // goes from 180 degrees to 0 degrees
    myservo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
void PINchange(){
  lcd.setCursor(0, 0);
  lcd.print(" Enter New PIN:");
  customKey = customKeypad.getKey();
  noTone(buzzer);
  if (customKey){ // makes sure a key is actually pressed, equal to (customKey != NO_KEY)
    Temp[data_count] = customKey; // store char into data array
    lcd.setCursor(data_count, 1); // move cursor to show each new char
    lcd.print(Data[data_count]); // print char at said cursor
    data_count++; // increment data array by 1 to store new char, also keep track of the number of chars entered
    tone(buzzer,1000,300);
  }
  if (data_count == PIN_Lenght -1){
    if (!strcmp(Temp, Master)){
      lcd.clear();
      lcd.print(" Checking...");
      delay(2000);
      lcd.setCursor(0, 0);
      lcd.print(" Same PIN...");
      lcd.setCursor(0, 1);
      lcd.print(" Nothing Change!");
      tone(buzzer,500,200);
      delay(300);
      tone(buzzer,500,200);
      delay(1000);
      lcd.clear();
      door=0;
    }
    if (strcmp(Temp, Master)){
     Master[data_count] = Temp[data_count];
     lcd.clear();
     lcd.print(" Checking...");
     delay(2000);
     lcd.begin(16, 2);
     lcd.print(" Done...");
     delay(1000);
     lcd.clear();
     lcd.print(" PIN Code Changed!");
     tone(buzzer,500,200);
     delay(2000);
     door=0;
    }
    clearData();
  }

}
void Open(){
  lcd.setCursor(0, 0);
  lcd.print(" Enter PIN Code:");
  customKey = customKeypad.getKey();
  noTone(buzzer);
  if (customKey){ // makes sure a key is actually pressed, equal to (customKey != NO_KEY)
    Data[data_count] = customKey; // store char into data array
    lcd.setCursor(data_count, 1); // move cursor to show each new char
    lcd.print(Data[data_count]); // print char at said cursor
    data_count++; // increment data array by 1 to store new char, also keep track of the number of chars entered
    tone(buzzer,1000,300);
  }
  if (data_count == PIN_Lenght - 1){ // if the array index is equal to the number of expected chars, compare data to master
    if (!strcmp(Data, Master)){ // equal to (strcmp(Data, Master) == 0)
      lcd.clear();
      ServoOpen();
      lcd.print(" Door is Open!");
      delay(1000);
      door = 0;
    }
    else
    {
      lcd.clear();
      lcd.print(" Access Denied!");
      tone(buzzer,500,200);
      delay(300);
      tone(buzzer,500,200);
      delay(1000);
      door = 1;
    }
    clearData();
  }
}
