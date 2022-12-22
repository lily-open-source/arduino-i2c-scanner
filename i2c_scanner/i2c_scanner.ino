#include <Wire.h>

void setup() {
  Serial.begin(115200);
  Wire.begin();
}

void loop() {
  // Mengulangi proses pemindaian setiap 1 detik
  delay(1000);

  Serial.println("Scanning...");

  // Memindai alamat I2C
  for (int i = 0; i < 128; i++) {
    Wire.beginTransmission(i);
    int error = Wire.endTransmission();
    if (error == 0) {
      Serial.print("Device found at address 0x");
      if (i < 16) Serial.print("0");
      Serial.println(i, HEX);
    }
  }
}
