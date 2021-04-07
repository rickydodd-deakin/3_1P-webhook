#include <Adafruit_DHT.h>
#define DHTPIN 2
#define POWERPIN 7
#define DHTTYPE DHT22

DHT dht(DHTPIN, DHTTYPE);

void setup() {
    dht.begin();
    pinMode(POWERPIN, OUTPUT);
    digitalWrite(POWERPIN, HIGH);
}

void loop() {
    delay(30000);
    float temp = dht.getTempCelcius();
    
    if (isnan(temp))
    {
        return;
    }
    
    Particle.publish("temperature", String(temp), PRIVATE);
}
