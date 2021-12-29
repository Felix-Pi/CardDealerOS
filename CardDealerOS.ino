#include <SPI.h>
#include <Adafruit_GFX.h>    // Core graphics library
#include <Adafruit_ST7735.h> // Hardware-specific library

#define TFT_CS        10
#define TFT_RST        7 // Or set to -1 and connect to Arduino RESET pin
#define TFT_DC         9

Adafruit_ST7735 tft = Adafruit_ST7735(TFT_CS, TFT_DC, TFT_RST);

void setup(void) {
  tft.initR(INITR_144GREENTAB); // Init ST7735R chip, green tab
  //tft.fillScreen(ST77XX_BLACK);
  tft.setRotation(1); // set display orientation
}

/* POTIES */
int getPlayers() {
  return 1;
}

int getCards() {
  return 1;
}

/* DISPLAY */
void setDisplayText(int players, int cards) {
  tft.fillScreen(ST77XX_BLACK);
  print_text(5, 30, "Spieler", 2, ST77XX_ORANGE);
  print_text(100, 30, "1", 2, ST77XX_WHITE);

  print_text(5, 60, "Karten", 2, ST77XX_ORANGE);
  print_text(100, 60, "1", 2, ST77XX_WHITE);
}

void print_text(byte x_pos, byte y_pos, char *text, byte text_size, uint16_t color) {
  tft.setCursor(x_pos, y_pos);
  tft.setTextSize(text_size);
  tft.setTextColor(color);
  tft.setTextWrap(true);
  tft.print(text);
}

/* STEPPER MOTOR: Base rotation */

/* DC MOTOR: Card output */
void outputCard() {

}

/* DOMAIN LOGIC */


void loop() {

  setDisplayText(getPlayers(), getCards());

  delay(5000);

}
