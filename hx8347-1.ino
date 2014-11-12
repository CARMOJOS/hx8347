#define LCD_RD   A0
#define LCD_WR   A1     
#define LCD_RS   A2        
#define LCD_CS   A3       
#define LCD_REST A4

#define	BLACK           0x0000
#define	BLUE            0x001F
#define	RED             0xF800
#define	GREEN           0x07E0
#define CYAN            0x07FF
#define MAGENTA         0xF81F
#define YELLOW          0xFFE0 
#define WHITE           0xFFFF

#include "hx8347lib.h"

HX8347 tft(LCD_CS, LCD_RS, LCD_WR, LCD_RD, LCD_REST);


int RGB(int r,int g,int b)
{return r << 16 | g << 8 | b;
}


void setup()
{
  for(int p=2;p<10;p++)
  {
    pinMode(p,OUTPUT);
  }

  tft.Lcd_Init();
  tft.LCD_Clear(0xf800);
  Serial.begin(115200);
}

void loop()
{  

  //for(int i=0;i<1000;i++)
  //{
    //tft.Rectf(0,0,173,158,BLUE);
    tft.fillScreen(RED);
    tft.drawString(0,0,"Hello",GREEN,7);
    tft.drawTriangle(0,150,0,95,75,15,YELLOW);
    //tft.fillTriangle(0,150,0,95,75,15,BLUE);
    //tft.drawLine(0, 0, 130, 150, BLUE);
    delay(1000);
    //tft.H_line(0,150,1,BLUE);
    //tft.drawString(10,0,"Hottie!",RED,7);
//for (uint16_t x=0; x < tft.width(); x+=6) {
//tft.drawRoundRect(tft.width()/2 -x/2, tft.height()/2 -x/2 , x, x, x/8, tft.Color565(x, 0, 0));  

//}
//}
  
  //tft.LCD_Clear(0xf800);
  //tft.H_line(10,10,150,RED);
}
