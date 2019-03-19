int k=0;
int rate_count;
int time_start;
int t,m;
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  pinMode(A0,INPUT);
  // Print a message to the LCD.
  lcd.print("your heart rate is:");
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  if(k==0){
    time_start=millis();
    k=1;
  }
  int value = digitalRead(A0);
  t=t+1;
  if(value==0){
    rate_count=rate_count+1;
  }
  
  int time_period=1000;
  if(millis()-time_start>time_period){
    lcd.setCursor(0, 1);
    // print the number of seconds since reset:
    m=rate_count/120;
    lcd.print(m);
    Serial.println(rate_count);
    rate_count=0;
    k=0;
  }
  
}
