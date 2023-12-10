#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
 
#define SCREEN_WIDTH 128 // 设置OLED宽度,单位:像素
#define SCREEN_HEIGHT 64 // 设置OLED高度,单位:像素

  
int S[5] = {13, 12, 11, 10, 9}; //重置ADG732的A0, A1, A2, A3, A4 
int CS = 8 ;
int WR = 7 ;
int EN = 6 ;
int switchPin = 5;
int OLED_RESET = 4;
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
int redLedPin = 3;
int OUTPIN = 2 ; //公共GND输出
int D = A0 ; //公共D口输入
#define adcpin1  A1 
#define adcpin2  A2 
#define adcpin3  A3 
    int V1 = analogRead(A1); //ADC读取电压
    int V2 = analogRead(A2);    //D输入电压
    int V3 = analogRead(A3);    //D输入电压
int KeyNum = 0 ;  


void setup() {
    // 初始化OLED并设置其IIC地址为 0x3C
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C);

    Draw_Init_Interface();
    KANA();
 
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
    pinMode(D, OUTPUT);
    digitalWrite(D, LOW);
    
    pinMode(OUTPIN, OUTPUT);
    digitalWrite(OUTPIN, LOW);
    Serial.begin(115200);
}

void loop() {
    int switchValue = digitalRead(switchPin); //定义变量并赋初值为0     
    if (switchValue == LOW) { // 如果检测到按键按下
        delay(1000);
        KeyNum ++; 
        delay(200); // 执行模式 +1
        words_display();  
          if (KeyNum >= 7) { // 如果超过设定执行状态数量，那么就回到 1 号模式
              KeyNum = 0;
              }
      }

    switch(KeyNum){
    case 0:
            Serial.println("Waitting for the KEY");
            key();
            Serial.println();
            break;  
    case 1:Serial.println("Mission 1 Start"); //正向SPX
            digitalWrite(redLedPin, HIGH);  //点亮红色LED
            digitalWrite(OUTPIN, LOW);
            for(int i = 0; i<32;i++){
                pinSelect(i);
                int a = i + 1;
                digitalWrite(D, HIGH);
                    float  VoltageValue1 = (analogRead(A1) - analogRead(A2)) * (5.0 / 1024.0); // 正向电压计算  
                    float  CurrentValue1 = (analogRead(A3) - analogRead(A1)) * (5.0 / 1024.0) / 10 ;  //正向电流
                    float  ResValue1 = VoltageValue1 / CurrentValue1 * 1000;   //正向电阻
                delay(100);
                digitalWrite(D, LOW);
                delay(100);
                
                Serial.print("The Pin number is:");
                Serial.println(a,DEC);
                Serial.print("The Voltage Value is(v):");
                Serial.println( VoltageValue1 ,DEC); //5v-adpin为1k电阻电压，I=V/R
                Serial.print("The Current Value is(mA):");
                Serial.println( CurrentValue1 ,DEC);//5v-adpin为1k电阻电压，I=V/R
                Serial.print("The Res Value is(kΩ):");
                Serial.println( ResValue1 ,DEC); //5v-adpin为1k电阻电压，I=V/R
                }
                delay(500);
                Serial.print("Mission 1 Complete");
                Serial.println();
                digitalWrite(redLedPin, LOW);
                Misson_display();    
            break;
    case 2:Serial.println("Mission 2 Start");//反向SPX
            digitalWrite(redLedPin, HIGH);  //点亮红色LED
            digitalWrite(D, LOW);
            for(int i = 0; i<32;i++){
                pinSelect(i);
                int a = i + 1;
                digitalWrite(OUTPIN, HIGH);
                delay(100);
                    float  VoltageValue2 = (analogRead(A2) - analogRead(A1)) * (5.0 / 1024.0); // 反向电压计算       
                    float  CurrentValue2 = (analogRead(A1) - analogRead(A3)) * (5.0 / 1024.0) / 10 ;  //反向电流 
                    float  ResValue2 = VoltageValue2 / CurrentValue2 * 1000 ;   //反向电阻 
                digitalWrite(OUTPIN, LOW);
                delay(100);
                
                Serial.print("The Pin number is:");
                Serial.println(a,DEC);
                Serial.print("The Voltage Value is(v):");
                Serial.println( VoltageValue2 ,DEC); //5v-adpin为1k电阻电压，I=V/R
                Serial.print("The Current Value is(mA):");
                Serial.println( CurrentValue2 ,DEC);//5v-adpin为1k电阻电压，I=V/R
                Serial.print("The Res Value is(kΩ):");
                Serial.println( ResValue2 ,DEC); //5v-adpin为1k电阻电压，I=V/R
                }
                delay(500);
                Serial.print("Mission 2 Complete");
                Serial.println();
                digitalWrite(redLedPin, LOW);
                Misson_display();
            break;  
    case 3:Serial.println("Mission 3 Start");//正向PDT
                     digitalWrite(redLedPin, HIGH);  //点亮红色LED
            digitalWrite(OUTPIN, LOW);
            for(int i = 0; i<26;i++){
                pinSelect(i);
                int a = i + 1;
                digitalWrite(D, HIGH);
                    float  VoltageValue1 = (analogRead(A1) - analogRead(A2)) * (5.0 / 1024.0); // 正向电压计算  
                    float  CurrentValue1 = (analogRead(A3) - analogRead(A1)) * (5.0 / 1024.0) / 10 ;  //正向电流
                    float  ResValue1 = VoltageValue1 / CurrentValue1 * 1000;   //正向电阻

                delay(100);
                digitalWrite(D, LOW);
                delay(100);
                
                Serial.print("The Pin number is:");
                Serial.println(a,DEC);
                Serial.print("The Voltage Value is(v):");
                Serial.println( VoltageValue1 ,DEC); //5v-adpin为1k电阻电压，I=V/R
                Serial.print("The Current Value is(mA):");
                Serial.println( CurrentValue1 ,DEC);//5v-adpin为1k电阻电压，I=V/R
                Serial.print("The Res Value is(kΩ):");
                Serial.println( ResValue1 ,DEC); //5v-adpin为1k电阻电压，I=V/R
                }
                delay(500);
                Serial.print("Mission 3 Complete");
                Serial.println();
                digitalWrite(redLedPin, LOW);
                Misson_display();
            break;
    case 4:Serial.println("Mission 4 Start");//反向PDT
            digitalWrite(redLedPin, HIGH);  //点亮红色LED
            digitalWrite(D, LOW);
            for(int i = 0; i<26;i++){
                pinSelect(i);
                int a = i + 1;
                digitalWrite(OUTPIN, HIGH);
                delay(100);
                    float  VoltageValue2 = (analogRead(A2) - analogRead(A1)) * (5.0 / 1024.0); // 反向电压计算       
                    float  CurrentValue2 = (analogRead(A1) - analogRead(A3)) * (5.0 / 1024.0) / 10 ;  //反向电流 
                    float  ResValue2 = VoltageValue2 / CurrentValue2 * 1000;   //反向电阻 
                digitalWrite(OUTPIN, LOW);
                delay(100);
                
                Serial.print("The Pin number is:");
                Serial.println(a,DEC);
                Serial.print("The Voltage Value is(v):");
                Serial.println( VoltageValue2 ,DEC); //5v-adpin为1k电阻电压，I=V/R
                Serial.print("The Current Value is(mA):");
                Serial.println( CurrentValue2 ,DEC);//5v-adpin为1k电阻电压，I=V/R
                Serial.print("The Res Value is(kΩ):");
                Serial.println( ResValue2 ,DEC); //5v-adpin为1k电阻电压，I=V/R
                }
                delay(500);
                Serial.print("Mission 4 Complete");
                Serial.println();
                digitalWrite(redLedPin, LOW);
                Misson_display();
            break;
      /*  case 5:Serial.println("Mission 5 Start");//正向PDT
            digitalWrite(redLedPin, HIGH);  //点亮红色LED
            digitalWrite(OUTPIN, LOW);
            for(int i = 0; i<16;i++){
                pinSelect(i);
                int a = i + 1;
                digitalWrite(D, HIGH);
                    float  VoltageValue1 = (analogRead(A1) - analogRead(A2)) * (5.0 / 1024.0); // 正向电压计算  
                                    Serial.println(VoltageValue1);   
                    float  CurrentValue1 = (analogRead(A3) - analogRead(A1)) * (5.0 / 1024.0) / 10 ;  //正向电流
                                    Serial.print(CurrentValue1);
                    float  ResValue1 = VoltageValue1 / CurrentValue1 / 1000;   //正向电阻
                                    Serial.println(ResValue1);
                delay(100);
                digitalWrite(D, LOW);
                delay(100);
                
                Serial.print("The Pin number is:");
                Serial.println(a,DEC);
                Serial.print("The Voltage Value is(v):");
                Serial.println( VoltageValue1 ,DEC); //5v-adpin为1k电阻电压，I=V/R
                Serial.print("The Current Value is(mA):");
                Serial.println( CurrentValue1 ,DEC);//5v-adpin为1k电阻电压，I=V/R
                Serial.print("The Res Value is(kΩ):");
                Serial.println( ResValue1 ,DEC); //5v-adpin为1k电阻电压，I=V/R
                }
                Serial.print("Mission 5 Complete");
                Serial.println();
                digitalWrite(redLedPin, LOW);
                Misson_display();KeyNum = 0;
            break;
    case 6:Serial.println("Mission 6 Start");//反向PDT
            digitalWrite(redLedPin, HIGH);  //点亮红色LED
            digitalWrite(D, LOW);
            for(int i = 0; i<16;i++){
                pinSelect(i);
                int a = i + 1;
                digitalWrite(OUTPIN, HIGH);
                delay(100);
                    float  VoltageValue2 = (analogRead(A2) - analogRead(A1)) * (5.0 / 1024.0); // 反向电压计算       
                    float  CurrentValue2 = (analogRead(A1) - analogRead(A3)) * (5.0 / 1024.0) / 10 ;  //反向电流 
                    float  ResValue2 = VoltageValue2 / CurrentValue2 ;   //反向电阻 
                digitalWrite(OUTPIN, LOW);
                delay(100);
                
                Serial.print("The Pin number is:");
                Serial.println(a,DEC);
                Serial.print("The Voltage Value is(v):");
                Serial.println( VoltageValue2 ,DEC); //5v-adpin为1k电阻电压，I=V/R
                Serial.print("The Current Value is(mA):");
                Serial.println( CurrentValue2 ,DEC);//5v-adpin为1k电阻电压，I=V/R
                Serial.print("The Res Value is(kΩ):");
                Serial.println( ResValue2 ,DEC); //5v-adpin为1k电阻电压，I=V/R
      

                }
                Serial.print("Mission 6 Complete");
                Serial.println();
                digitalWrite(redLedPin, LOW);
                Misson_display();KeyNum = 0;
            break;   */
    default: 
            Serial.println("Waitting for the KEY");
            key();
            Serial.println();KeyNum = 0;
            break;
    }
}

void pinSelect(int pinnum)
{
  digitalWrite(WR, LOW);
    for (int x = 0; x<5; x++){
      byte state = bitRead(pinnum, x);
      digitalWrite(S[x], state);
      //Serial.print(state);
    }
    //Serial.println();
  digitalWrite(WR, HIGH);
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


void Draw_Init_Interface(void) 
{
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

void words_display()
{
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1.5);
  display.setCursor(0, 0);
  display.print("Mission ");
 
  display.setCursor(0, 20);
  display.print("Mission   ");
  display.print(KeyNum);
 
  display.setCursor(0, 40);
  display.print("Start    ");
  display.print("<( ^_^ )>");
  display.display();
}

void Misson_display()
{
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1.5);
  display.setCursor(0, 0);
  display.print("Mission ");
 
  display.setCursor(0, 20);
  display.print("Mission   ");
  display.print(KeyNum);
 
  display.setCursor(0, 40);
  display.print("Complete");
  display.print("<( ^_^ )>");
  display.display();
}
void displayValues(int row, const char* label, int value) {
    display.setCursor(0, row);
    display.print(label);
    display.setCursor(0, row + 10);
    display.print(value);
}
