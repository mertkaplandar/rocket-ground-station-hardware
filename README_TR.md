# Rocket Ground Station Arduino Code

Bu repo, [mertkaplandar/rocket-ground-station-app](https://github.com/mertkaplandar/rocket-ground-station-app) arayüzün çalışabilmesi için örnek bir kod içermektedir. Bu kod, bir LoRa modülü kullanarak veri almak ve bu verileri JSON formatında seri port ekranına yazmak için geliştirilmiştir. 

## Notlar
[mertkaplandar/rocket-ground-station-app](https://github.com/mertkaplandar/rocket-ground-station-app) uygulamasının çalışması için kod içeriğindeki DataPack'in değiştirilmeden aynı yapıdan kullanılması gerekmektedir. Kullanılmayacak veriler boş bırakılıp seri port ekranına yine de json formatında yazdırılmalıdır.

## Özellikler

- LoRa modülü kullanarak veri alımı.
- Alınan verilerin JSON formatında seri port ekranına yazılması.

## Gereksinimler

- Arduino
- LoRa E32 modülü
- ArduinoJson kütüphanesi
- SoftwareSerial kütüphanesi

## Kurulum

1. Arduino IDE'yi indirin ve yükleyin.
2. Arduino kartınızı bilgisayarınıza bağlayın.
3. Arduino IDE'yi açın ve bu projeyi yükleyin.
4. Gerekli kütüphaneleri yükleyin:
   - `LoRa_E32`
   - `SoftwareSerial`
   - `ArduinoJson`

## Kullanım

1. `mySerial` için gerekli pinleri ayarlayın.
2. LoRa modülünüzü ayarlayın ve `LORA_ADDR` ve `LORA_CH` parametrelerini güncelleyin.
3. Kodu Arduino kartınıza yükleyin.
4. Seri monitörü açın ve verilerin JSON formatında yazdırıldığını görün.