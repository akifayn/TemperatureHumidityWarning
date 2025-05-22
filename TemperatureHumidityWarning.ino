#define BLYNK_TEMPLATE_ID "TMPL6K8JefXnv"
#define BLYNK_TEMPLATE_NAME "proje "

#include <DHT.h>
#include <Wire.h>  // I2C kütüphanesi
#include <LiquidCrystal_I2C.h>
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// DHT sensörünü bağladığınız pini tanımlayın
#define DHTPIN 4  // D2 pinine bağladığını varsayıyoruz (GPIO4)

// DHT sensör tipini tanımlayın
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

// LCD ekran için gerekli parametreler
LiquidCrystal_I2C lcd(0x27, 16, 2);  // I2C adresi 0x27 olan 16x2 LCD ekran

// Blynk için gerekli değişkenler
char auth[] = "7mpvlzSAZ5aLiRVuub1dZFLO9enyxlfc";  // Blynk Auth Token
char ssid[] = "SUPERONLINE_WiFi_4636";       // WiFi SSID
char pass[] = "FPUAJTXU7YTT";   // WiFi Password

// Buzzer ve LED pinlerini tanımlayın
#define BUZZER_PIN 5  // D1 pinine bağladığını varsayıyoruz (GPIO5)
#define LED_PIN 12    // D6 pinine bağladığını varsayıyoruz (GPIO12)

// Super Mario melodisi için notalar ve süreleri
int melody[] = {
  262, 262, 0, 262, 0, 209, 262, 0, 330, 0, 392, 0, 0, 0, 
  523, 0, 392, 0, 330, 0, 262, 0, 196, 0, 0, 0, 
  392, 0, 370, 0, 349, 0, 311, 0, 330, 0, 0, 0, 
  262, 0, 0, 0, 196, 0, 0, 0, 262, 0, 0, 0, 311, 0, 349, 0, 
  330, 0, 262, 0, 330, 0, 392, 0, 523, 0, 0, 0
};
int noteDurations[] = {
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4
};

void setup() {
  Serial.begin(9600);  // Seri iletişimi başlat ve baud hızını 9600 olarak ayarla

  // I2C pinlerini ayarla
  Wire.begin(0, 2);  // SDA -> D3 (GPIO0), SCL -> D4 (GPIO2)

  dht.begin();  // DHT sensörünü başlat

  // LCD ekranı başlat
  lcd.init();
  lcd.backlight();
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("DHT11 sensor test");

  // Buzzer ve LED pinlerini çıkış olarak ayarla
  pinMode(BUZZER_PIN, OUTPUT);
  digitalWrite(BUZZER_PIN, LOW);  // Başlangıçta buzzer kapalı

  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW);  // Başlangıçta LED kapalı

  // Blynk'i başlat
  Blynk.begin(auth, ssid, pass);
}

void playMelody() {
  // Super Mario melodisini çal
  int melodyLength = sizeof(melody) / sizeof(melody[0]);
  for (int thisNote = 0; thisNote < melodyLength; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(BUZZER_PIN, melody[thisNote], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(BUZZER_PIN);
  }
}

void loop() {
  Blynk.run();  // Blynk işlevini çalıştır
  delay(2000);  // Okumalar arasında 2 saniye bekle

  // Nem ve sıcaklık değerlerini oku
  float humi = dht.readHumidity();
  float temperature_C = dht.readTemperature();

  // Okumanın başarılı olup olmadığını kontrol et
  if (isnan(temperature_C) || isnan(humi)) {
    Serial.println("Failed to read from DHT sensor!");
    lcd.setCursor(0, 1);
    lcd.print("Failed to read");
  } else {
    Serial.print("Sicaklik: ");
    Serial.print(temperature_C);
    Serial.print(" °C, Nem: ");
    Serial.print(humi);
    Serial.println(" %");

    // LCD ekranına sıcaklık ve nem değerlerini yazdır
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Sicaklik:");
    lcd.print(temperature_C);
    lcd.print(" C");
    
    lcd.setCursor(0, 1);
    lcd.print("Nem:     ");
    lcd.print(humi);
    lcd.print(" %");

    // Blynk uygulamasına sıcaklık ve nem değerlerini gönder
    Blynk.virtualWrite(V0, temperature_C);  // Sıcaklık için Virtual Pin V0
    Blynk.virtualWrite(V1, humi);           // Nem için Virtual Pin V1
    Blynk.virtualWrite(V2,LED_PIN);

    // Sıcaklık 32 dereceyi geçtiğinde buzzer'ı çalıştır ve LED'i yak
    if (temperature_C > 34) {
      digitalWrite(LED_PIN, HIGH);  // LED'i yak
      playMelody();  // Tehlike alarmı melodisini çal
    } else {
      noTone(BUZZER_PIN);  // Sesi kapat
      digitalWrite(LED_PIN, LOW);  // LED'i kapat
    }
  }
}
