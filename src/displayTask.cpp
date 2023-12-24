#include "displayTask.hpp"

SSD1306Wire display(DISP_ADR, DISP_SDA, DISP_SCL);

void displayTaskInit() {
  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_10);
}

