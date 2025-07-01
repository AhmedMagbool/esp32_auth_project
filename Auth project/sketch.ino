/* ESP32 + ILI9341 + Serial Login UI + 64×64 Tuwaiq Logo (0/1)
   أحمد 2025
*/
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <SPI.h>
#include "tuwaiq_logo_64x64_clean.h"   // شعار طويق 64×64

//----------------------------------------------------
// أطراف الشاشة (خريطة Wokwi الافتراضية: CS على D15)
#define TFT_CS   5   // انقل السلك إلى D15 أو غيّر الرقم حسب توصيلك
#define TFT_DC    2
#define TFT_RST   4
Adafruit_ILI9341 tft(TFT_CS, TFT_DC, TFT_RST);

//----------------------------------------------------
// دالة رسم الشعار
void drawTuwaiqLogo(int x0, int y0, uint16_t color = ILI9341_WHITE) {
  for (uint8_t y = 0; y < 64; y++) {
    for (uint8_t x = 0; x < 64; x++) {
      if (tuwaiqLogo[y][x]) {            // 1 = يرسم، 0 = يترك
        tft.drawPixel(x0 + x, y0 + y, color);
      }
    }
  }
}

//----------------------------------------------------
// منطق الحساب والتسجيل
String storedUser = "", storedPass = "";
String tmpUser = "", tmpPass = "";

enum State {UI_HOME, CREATE_USER, CREATE_PASS, LOGIN_USER, LOGIN_PASS, LOGGED_IN};
State state = UI_HOME;

//----------------------------------------------------
// شاشة البداية
void drawHome() {
   tft.fillScreen(ILI9341_BLACK);
  drawTuwaiqLogo(240 - 64 - 4, 4);



  tft.setTextSize(2);
  tft.setTextColor(ILI9341_WHITE);
  tft.setCursor(10, 60);
  tft.println("Welcome to System");

  tft.setTextColor(ILI9341_WHITE);
  tft.setCursor(10, 100);
  tft.println("Type: create or login");

}

//----------------------------------------------------
void setup() {
  Serial.begin(115200);
  tft.begin();
  drawHome();
}

//----------------------------------------------------
void loop() {
  if (!Serial.available()) return;

  String in = Serial.readStringUntil('\n');
  in.trim();

  switch (state) {
    case UI_HOME:
      if (in.equalsIgnoreCase("create")) {
        state = CREATE_USER;
        tft.fillScreen(ILI9341_BLACK);
        tft.setTextSize(2); tft.setCursor(10,20);
        tft.setTextColor(ILI9341_WHITE);
        tft.println("Create Username:");
      } else if (in.equalsIgnoreCase("login")) {
        state = LOGIN_USER;
        tft.fillScreen(ILI9341_BLACK);
        tft.setTextSize(2); tft.setCursor(10,20);
        tft.println("Enter Username:");
      } else {
        tft.setCursor(10,180); tft.setTextColor(ILI9341_RED);
        tft.println("Invalid command");          // أمر غير مفهوم
      }
      break;

    case CREATE_USER:
      tmpUser = in;
      state   = CREATE_PASS;
      tft.setCursor(10,60); tft.println("Enter Password:");
      break;

    case CREATE_PASS:
      tmpPass = in;
      storedUser = tmpUser; storedPass = tmpPass;
      tft.setCursor(10,100); tft.setTextColor(ILI9341_GREEN);
      tft.println("Account Created!");
      delay(1500);
      state = UI_HOME; drawHome();
      break;

    case LOGIN_USER:
      tmpUser = in;
      state   = LOGIN_PASS;
      tft.setCursor(10,60); tft.setTextColor(ILI9341_WHITE);
      tft.println("Enter Password:");
      break;

    case LOGIN_PASS:
      tmpPass = in;
      if (tmpUser == storedUser && tmpPass == storedPass) {
        state = LOGGED_IN;
        tft.fillScreen(ILI9341_BLACK);
        tft.setCursor(10,20); tft.setTextColor(ILI9341_GREEN);
        tft.println("Login Successful!");
      } else {
        tft.setCursor(10,100); tft.setTextColor(ILI9341_RED);
        tft.println("Wrong Credentials!");
        delay(1500);
        state = UI_HOME; drawHome();
      }
      break;

    default: break;
  }
}
