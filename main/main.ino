#include <SoftwareSerial.h>

SoftwareSerial tb2Serial(6, 7); // RX, TX

void setup() {
// Open serial communications and wait for port to open:
    Serial.begin(115200);
    while (!Serial) {
        ; // wait for serial port to connect. Needed for native USB port only
    }
    Serial.println("M252 demo");
    tb2Serial.begin(19200);
    delay(1000);
}

void loop(void) {
    if (tb2Serial.available()) {
       Serial.write(tb2Serial.read()); 
    }
    if (Serial.available()) {
        tb2Serial.write(Serial.read());
    }
}
