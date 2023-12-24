#include <SPI.h>
#include <SSD1306Wire.h>

#define DISP_ADR 0x3c // I2C address of the display
#define DISP_SDA 21 // SDA pin for the display
#define DISP_SCL 22 // SCL pin for the display

void displayTaskInit();

void displayRender();

void displayTest();