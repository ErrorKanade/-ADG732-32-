#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
 
#define SCREEN_WIDTH 128 // 设置OLED宽度,单位:像素
#define SCREEN_HEIGHT 64 // 设置OLED高度,单位:像素
#define adPin A0

boolean change = false;  
int S[5] = {13, 12, 11, 10, 9}; //重置A0, A1, A2, A3, A4 
int CS = 8 ;
int WR = 7 ;
int EN = 6 ;
int switchPin = 5;
int OLED_RESET = 4;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
int redLedPin = 3;
int INPIN = A0 ; //公共D口输入


void pinSelect(int pinnum){
  digitalWrite(WR, LOW);
    for (int x = 0; x<5; x++){
      byte state = bitRead(pinnum, x);
      digitalWrite(S[x], state);
      Serial.print(state);
    }
    Serial.println();
  digitalWrite(WR, HIGH);
}


void words_display()
{
  // 清除屏幕
  display.clearDisplay();
 
  // 设置字体颜色,白色可见
  display.setTextColor(WHITE);
 
  //设置字体大小
  display.setTextSize(1.5);
 
}

void kkkkk(void)
{
  
static const unsigned char PROGMEM ce[] = {

0x00,0x20,0xE4,0x23,0x28,0x22,0x28,0x2A,0xA1,0x2A,0xA2,0x2A,0xA2,0x2A,0xA8,0x2A,
0xA8,0x2A,0xA4,0x2A,0xA7,0x2A,0x84,0x20,0x44,0x21,0x44,0x22,0x24,0x28,0x10,0x10};/*"测",0*/
/* (16 X 16 , 宋体 )*/
static const unsigned char PROGMEM liang [] = {

0x00,0x00,0xF8,0x0F,0x08,0x08,0xF8,0x0F,0x08,0x08,0xFF,0x7F,0x00,0x00,0xF8,0x0F,
0x88,0x08,0xF8,0x0F,0x88,0x08,0xF8,0x0F,0x80,0x00,0xF8,0x0F,0x80,0x00,0xFE,0x3F};/*"量",1*/
/* (16 X 16 , 宋体 )*/
static const unsigned char PROGMEM jie [] = {

0x08,0x04,0x08,0x04,0x04,0x04,0xE4,0x7F,0x22,0x04,0x1F,0x04,0x88,0x3F,0x04,0x00,
0x02,0x00,0xBF,0x3F,0x82,0x20,0x80,0x20,0xB8,0x20,0x87,0x20,0x82,0x3F,0x80,0x20};/*"结",2*/
/* (16 X 16 , 宋体 )*/
static const unsigned char PROGMEM shu[] = {

0x80,0x00,0x80,0x00,0xFF,0x7F,0x80,0x00,0x80,0x00,0xFC,0x1F,0x84,0x10,0x84,0x10,
0x84,0x10,0xFC,0x1F,0xC4,0x11,0xA0,0x02,0x90,0x04,0x8C,0x18,0x83,0x60,0x80,0x00};/*"束",3*/
/* (16 X 16 , 宋体 )*/
    // 显示之前清屏
    display.clearDisplay();
 
    // 显示文字 (左上角x坐标,右上角y坐标, 图形数组, 图形宽度像素点, 图形高度像素点, 设置颜色)
    display.drawBitmap(20 * 1, 16, ce, 16, 32, 1);
    display.drawBitmap(20 * 2, 16, liang, 16, 32, 1);
    display.drawBitmap(20 * 3, 16, jie, 16, 32, 1);
    display.drawBitmap(20 * 4, 16, shu, 16, 32, 1);
}


void KANA(void)
{

static const unsigned char PROGMEM hans_K[] = {
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0xFC,0xF8,0x30,0x20,0x30,0x40,
    0x30,0xC0,0x30,0x80,0x31,0x00,0x31,0x00,0x30,0x00,0x36,0x00,0x37,0x00,0x3B,0x00,
    0x39,0x80,0x31,0x80,0x30,0xC0,0x30,0xC0,0x30,0x60,0x30,0x60,0x30,0x20,0x30,0x30,
    0x30,0x38,0xFC,0x7C,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};/*"K",0*/
 
static const unsigned char PROGMEM hans_A1[] = {
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xC0,0x18,0x60,0x30,0x30,0x30,0x30,
    0x00,0x30,0x01,0xF0,0x0E,0x30,0x38,0x30,0x70,0x30,0x60,0x30,0x60,0x30,0x60,0x34,
    0x30,0xF4,0x1F,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};/*"a",1*/
 
static const unsigned char PROGMEM hans_N[] = {
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x09,0xE0,0x7A,0x60,0x1C,0x30,0x18,0x30,
    0x18,0x30,0x18,0x30,0x18,0x30,0x18,0x30,0x18,0x30,0x18,0x30,0x18,0x30,0x18,0x30,
    0x18,0x30,0x7E,0xFC,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};/*"n",2*/
 
static const unsigned char PROGMEM hans_A2[] = {
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,
    0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x0F,0xC0,0x18,0x60,0x30,0x30,0x30,0x30,
    0x00,0x30,0x01,0xF0,0x0E,0x30,0x38,0x30,0x70,0x30,0x60,0x30,0x60,0x30,0x60,0x34,
    0x30,0xF4,0x1F,0x18,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00};/*"a",3*/

    // 显示之前清屏
    display.clearDisplay();
 
    // 显示文字 (左上角x坐标,右上角y坐标, 图形数组, 图形宽度像素点, 图形高度像素点, 设置颜色)
    display.drawBitmap(20 * 1, 16, hans_K, 16, 32, 1);
    display.drawBitmap(20 * 2, 16, hans_A1, 16, 32, 1);
    display.drawBitmap(20 * 3, 16, hans_N, 16, 32, 1);
    display.drawBitmap(20 * 4, 16, hans_A2, 16, 32, 1);
 
    //显示图形
    display.display();
    delay(2000);
}

void key(void)
{

    // 显示之前清屏
    display.clearDisplay();
 
    display.setCursor(15, 30);
    display.print("Waiting for start "); 
    display.display();
    delay(2000);
}


void Draw_Init_Interface(void) {
    for (size_t a = 0; a < 46; a = a + 5)
    {
        display.clearDisplay();
        display.setTextSize(1);
        display.setTextColor(WHITE);
        display.setCursor(25, 20);
        display.println("Initialize...");
        display.drawRect(38, 38, 51, 6, WHITE);//以（38，38）为起点绘制一个长度51宽度为6的矩形
        display.drawLine(40, 40, 40 + a, 40, WHITE);//循环绘制线条达到显示进度的效果
        display.drawLine(40, 41, 40 + a, 41, WHITE);
        display.display();
        delay(100);
        display.clearDisplay();
    }
    display.display();
}

void setup() {
    // 初始化OLED并设置其IIC地址为 0x3C
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

  Draw_Init_Interface();
  KANA();
  key();
 
  pinMode(redLedPin, OUTPUT);  //设置引脚3为输出模式
  pinMode(switchPin, INPUT_PULLUP);  // 设置引脚2为输入模式
  
  for (int x = 0; x < 5; x++) {
    pinMode(S[x], OUTPUT);
      digitalWrite(S[x], LOW);
  }

  pinMode(CS, OUTPUT);
    digitalWrite(CS, LOW);
  pinMode(WR, OUTPUT);
    digitalWrite(WR, LOW);
  pinMode(EN, OUTPUT);
    digitalWrite(EN, LOW);
  pinMode(INPIN, OUTPUT);
    digitalWrite(INPIN, LOW);
  Serial.begin(115200);

}

void loop() {
  int ad_value_raw = analogRead(adPin);

  int switchValue = digitalRead(switchPin); //定义变量并赋初值为0

  if (switchValue == LOW) {   //判断键值等于0，执行下面的程序
    digitalWrite(redLedPin, HIGH);  //点亮红色LED
    for(int i = 1; i<33;i++){
  pinSelect(i);
  digitalWrite(INPIN, HIGH);
  Serial.print("The Pin number is:");
  Serial.println(i,DEC);
  Serial.print("The Voltage Value is(v):");
  Serial.println(analogRead(adPin)* (5.0 / 1024.0),DEC);
  words_display();
    display.setCursor(0, 0);
    display.print("The Pin number is: "); 
    display.setCursor(0, 10);
    display.print( i);
    display.setCursor(0, 30);
    display.print("The Voltage Value is:"); 
    display.setCursor(0, 40);
    display.print( analogRead(adPin)* (5.0 / 1024.0));
    display.print( " V");
    delay(200);
    display.display();
    display.clearDisplay();
    kkkkk();}
}
  else {  //判断键值不为0,将执行下面的语句
    digitalWrite(redLedPin, LOW);  //熄灭红色LED
      words_display();
      kkkkk();
      delay(200);
  }


}
