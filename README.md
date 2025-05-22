# 🌡️ TemperatureHumidityWarning - IoT Tabanlı Sıcaklık ve Nem Uyarı Sistemi

Bu proje, DHT11 sensörü kullanarak ortam sıcaklığı ve nemini ölçer. Ölçülen değerler LCD ekran üzerinden görüntülenir ve Blynk uygulaması aracılığıyla uzaktan takip edilebilir. Sıcaklık belirli bir değerin üzerine çıktığında buzzer ve LED ile uyarı verilir. Uyarı sırasında Super Mario melodisi çalınır.

## [📹 Proje Videosu](https://www.youtube.com/watch?v=UFVGz6wSowM)

## 🎯 Amaç
- Sıcaklık ve nem değerlerini ölçmek
- LCD ekran üzerinden görüntülemek
- Belirlenen sıcaklık üzerine çıktığında uyarı vermek
- Blynk ile mobil cihaz üzerinden uzaktan izlemek

## 🧰 Kullanılan Malzemeler
- ESP8266 (NodeMCU)
- DHT11 Sensörü
- I2C LCD 16x2 Ekran
- Aktif Buzzer
- LED
- Wi-Fi bağlantısı
- Blynk Uygulaması

## 🔌 Donanım Bağlantıları

| Bileşen     | ESP8266 GPIO | Açıklama           |
|-------------|---------------|--------------------|
| DHT11       | GPIO4 (D2)    | Sıcaklık ve nem    |
| LCD (I2C)   | SDA: D3 / SCL: D4 | LCD ekran        |
| Buzzer      | GPIO5 (D1)    | Sesli uyarı        |
| LED         | GPIO12 (D6)   | Görsel uyarı       |

## 📱 Blynk Ayarları
- Template ID: `TMPL6K8JefXnv`
- Auth Token: Blynk uygulamasından alınmalı
- Virtual Pin V0: Sıcaklık
- Virtual Pin V1: Nem
- Virtual Pin V2: LED durumu

## 🛠️ Kurulum
1. Arduino IDE üzerinden şu kütüphaneleri yükle:
   - `DHT.h`
   - `LiquidCrystal_I2C.h`
   - `BlynkSimpleEsp8266.h`
   - `ESP8266WiFi.h`
2. Kodda yer alan `auth`, `ssid` ve `pass` değişkenlerini kendi bilgilerinizle değiştirin.
3. ESP8266'yı bağlayın ve `.ino` dosyasını karta yükleyin.

## 🎵 Alarm Sistemi
Sıcaklık sınır üzerine çıktığında buzzer üzerinden Super Mario melodisi çalar ve LED yanar.

## 👨‍💻 Geliştirici
- Muhammet Akif Ayan
