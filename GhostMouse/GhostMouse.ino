/**
 * This example turns the ESP32 into a Bluetooth LE mouse that continuously moves the mouse.
 */
#include <BleMouse.h>

BleMouse bleMouse("Logitech M3 Mouse", "Logitech", random(80, 100));

int hdisp = 0;
int vdisp = 0;

void setup() {

  randomSeed(analogRead(0));

  Serial.begin(115200);
  Serial.println("Starting BLE work!");

 // bleMouse.setBatteryLevel(random(80, 100));

  bleMouse.begin();
}

void loop() {

  if(bleMouse.isConnected()) {

  //   unsigned long startTime;

  //   delay(random(8000, 60000));

  //   Serial.println("Scroll up");
  //   startTime = millis();
  //   while(millis()<startTime+200) {
  //     bleMouse.move(0,0,1);
  //     delay(random(63, 340));
  //   }

  //   delay(random(2000, 20000));

  //   Serial.println("Scroll down");
  //   startTime = millis();
  //   while(millis()<startTime+2000) {
  //     bleMouse.move(0,0,-1);
  //     delay(random(63, 340));
  //   }

  //   delay(random(8000, 60000));

    Serial.println("Jiggle");
    //for (int i = 0; i < random(3, 8); i++) {

      //signed char hmove = hdisp < 0 ? random(12, 65) : random(-8, -87);
      //signed char vmove = vdisp < 0 ? random(15, 62) : random(-18, -93);

      bleMouse.move(40, 17, 0, 0);
      delay(100);

      //hdisp += hmove;
      //vdisp += vmove;
    //}

    Serial.println("H: " + hdisp);
    Serial.println("V: " + vdisp);
  }
}