//Code written by yatuoximeng on Github / yatuobomb on Tiktok
//Feel free to modify as you like! I added a lot of comments if someone wants to learn from this btw.

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// define your oled's display dimensions
#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for SSD1306 display connected using I2C connection
#define OLED_RESET     -1 // Reset pin # (or -1 if sharing Arduino reset pin)
#define SCREEN_ADDRESS 0x3C // Typically 0x3C for 128x64, if you are having issues, you might need to change this to 0x3D

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup() {
  Serial.begin(115200); //Serial monitor baud rate setting
  
  // Initialize OLED
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_ADDRESS)) {
    Serial.println(F("SSD1306 allocation failed"));
    for(;;); // Don't proceed, loop forever
  }
  
  // Clear the buffer
  display.clearDisplay();
  
  // Display simple text
  display.setTextSize(1);             // Normal 1:1 pixel scale
  display.setTextColor(SSD1306_WHITE); // Draw white text (this only matters if you have a multicolor OLED!!)
  display.setCursor(0,0);             // Start at top-left corner
  display.println(F("Hello, ESP32!")); 
  
  // Display larger text
  display.setTextSize(2); // LARGER text size
  display.setCursor(0,20); //down 20 pixels
  display.println(F("OLED Test"));
  
  // Display some graphics
  display.drawRect(0, 40, 30, 20, SSD1306_WHITE); // Rectangle
  display.fillCircle(70, 50, 10, SSD1306_WHITE);   // Filled circle
  
  // Show all the above
  display.display();
  
  Serial.println("OLED initialized"); // Serial feedback
}

void loop() {
  // Scroll part of the screen
  display.startscrollright(0x00, 0x0F);
  delay(2000);
  display.stopscroll();
  delay(1000);
  display.startscrollleft(0x00, 0x0F);
  delay(2000);
  display.stopscroll();
  delay(1000);
  
  // Invert display
  display.invertDisplay(true);
  delay(1000);
  display.invertDisplay(false);
  delay(1000);
}
