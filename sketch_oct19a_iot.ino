#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// กำหนดค่าตัวแปร
float temperature;
float humidity;
DHT dht14(D4, DHT11);

LiquidCrystal_I2C lcd(0x3f, 16, 2);

void setup() {
  temperature = 0;
  humidity = 0;
  Serial.begin(9600);
  dht14.begin();

//เริ่มการทำงานของจอ
  lcd.begin();
// ตั้งค่าตำแหน่ง (วรรค,บรรทัด)
  lcd.setCursor(0,0);
  lcd.print("Temp:        C");
  lcd.setCursor(0,1);
  lcd.print("Humi:        %");
  
}


void loop() {
  humidity = (dht14.readHumidity());
  temperature = (dht14.readTemperature());
  Serial.print("Temperature : C");
  Serial.print(temperature);
  Serial.print("Humidity: ");
  Serial.println(" %");

  lcd.setCursor(7,0);
  lcd.print(temperature);
  lcd.setCursor(7,1);
  lcd.print(humidity);
  
  delay(1000);
}
