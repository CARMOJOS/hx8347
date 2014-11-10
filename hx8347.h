#include <Arduino.h>

#define swap(a, b) { int16_t t = a; a = b; b = t; }

class HX8347 : public Print {
 public:
  HX8347(uint8_t cs, uint8_t cd, uint8_t wr, uint8_t rd, uint8_t reset);

  uint16_t Color565(uint8_t r, uint8_t g, uint8_t b);

  // drawing primitives!
  void clearScreen(unsigned int j);
  void drawPixel(uint16_t x, uint16_t y, uint16_t color);
  void fillScreen(uint16_t color);
  void drawLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color);
  void drawFastLine(uint16_t x0, uint16_t y0, uint16_t l, uint16_t color, uint8_t flag);
  void V_line(uint16_t x0, uint16_t y0, uint16_t length, uint16_t color);
  void H_line(uint16_t x0, uint16_t y0, uint16_t length, uint16_t color);
  void drawTriangle(uint16_t x0, uint16_t y0,
			  uint16_t x1, uint16_t y1,
			  uint16_t x2, uint16_t y2, uint16_t color);
  void fillTriangle(int32_t x0, int32_t y0,
			  int32_t x1, int32_t y1,
		    int32_t x2, int32_t y2, 
		    uint16_t color);
  void Rect(uint16_t x0, uint16_t y0, uint16_t w, uint16_t h, uint16_t color);
  void Rectf(uint16_t x0, uint16_t y0, uint16_t w, uint16_t h, uint16_t color);
  void drawRoundRect(uint16_t x0, uint16_t y0, uint16_t w, uint16_t h, uint16_t radius, uint16_t color);
  void fillRoundRect(uint16_t x0, uint16_t y0, uint16_t w, uint16_t h, uint16_t radius, uint16_t color);
  void drawCircle(uint16_t x0, uint16_t y0, uint16_t r,	uint16_t color);
  void fillCircle(uint16_t x0, uint16_t y0, uint16_t r,	uint16_t color);

  void setCursor(uint16_t x, uint16_t y);
  void setTextColor(uint16_t c);
  void setTextSize(uint8_t s);
  virtual size_t write(uint8_t);

  void drawChar(uint16_t x, uint16_t y, char c, uint16_t color, uint8_t s = 1);
  void drawString(uint16_t x, uint16_t y, char *c, uint16_t color, uint8_t s = 1);

  // commands
  void Lcd_Init(void);
  void goHome(void);
  void goTo(int x, int y);
  void LCD_Clear(unsigned int j);
  int RGB(int r,int g,int b);
  void reset(void);
  void setRotation(uint8_t x);
  uint8_t getRotation();

  /* low level */

  void Lcd_Writ_Bus(unsigned char VH);
  void Lcd_Write_Com(unsigned char VH);
  void Lcd_Write_Data(unsigned char VH);
  void Lcd_Write_Com_Data(unsigned char com,unsigned char dat);
  uint16_t readData(void);
  uint16_t readRegister(uint16_t addr);
  void Address_set(unsigned int x1,unsigned int y1,unsigned int x2,unsigned int y2);


  uint16_t width();
  uint16_t height();

  static const uint16_t TFTHEIGHT = 240;
  static const uint16_t TFTWIDTH = 320;

  void writeData_unsafe(uint16_t d);

  void setWriteDir(void);
  void setReadDir(void);


  void write8(uint8_t d);

 private:
  void drawCircleHelper(uint16_t x0, uint16_t y0, uint16_t r, uint8_t corner, uint16_t color);
  void fillCircleHelper(uint16_t x0, uint16_t y0, uint16_t r, uint8_t corner, uint16_t delta, uint16_t color);

  uint8_t read8(void);

  uint8_t _cs, _cd, _reset, _wr, _rd;

  uint8_t csport, cdport, wrport, rdport;
  uint8_t cspin, cdpin, wrpin, rdpin;

  uint16_t _width, _height;
  uint8_t textsize;
  uint16_t cursor_x, cursor_y;
  uint16_t textcolor;
  uint8_t rotation;
};
