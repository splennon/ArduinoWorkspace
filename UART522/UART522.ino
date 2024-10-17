// example.ino

#include "MFRC522.h"

MFRC522 Conector;

void setup()  {
      Serial.begin(9600);
    Serial1.begin(57600, SERIAL_8O1, 4, 2);
    Serial2.begin(57600, SERIAL_8O1, 16, 17);
	Conector.begin(&Serial2);

  Serial.println("Setup");
}

void loop() {
    if (Conector.available()) {


      Serial.println("detecting card");


        Conector.readCardSerial(); 	// Mandatory

Serial.println("Reading card");

        byte* ba = Conector.getCardSerial();

Serial.println("Reading card");

        for(int i=0; i<sizeof(ba); i++){
          printHex(ba[i]);
        }
        
        // Detected card at the reader!

        Conector.wait();			// Mandatory
    }
}

uint8_t b[]= {0x7E, 0x00, 0x1C, 0x90, 0x00, 0x13, 0XA2, 0x00, 
              0x41, 0x58, 0x1C, 0xCB, 0xFF, 0xFE, 0xC1, 0x7C, 
              0x00, 0x0F, 0x00, 0x01, 0x00, 0x00, 0x37, 0x46, 
              0x46, 0x46, 0x00, 0x00, 0x00, 0xE7};
int i;

void printHex(uint8_t num) {
  char hexCar[2];

  sprintf(hexCar, "%02X", num);
  Serial.print(hexCar);
}
