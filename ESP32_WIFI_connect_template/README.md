# ESP32 WiFi Connect Template

ESP32をWi-Fiに接続するためのシンプルなテンプレートです。

## 対応ボード

- ESP32 DevKitC
- ESP32-S3

## 使い方

1. このリポジトリをダウンロードまたはClone
2. Arduino IDEで開く
3. `wifi_config_example.h` を `wifi_config.h` にリネーム
4. `wifi_config.h` のSSIDとパスワードを書き換える

```cpp
const char* ssid = "YOUR_WIFI";
const char* password = "YOUR_PASSWORD";
```

5. ESP32へ書き込む
6. シリアルモニタ(115200bps)を開く

接続に成功するとIPアドレスが表示されます。

## 紹介動画
https://youtube.com/shorts/zqNgp7YTBe8?feature=share

## 注意

`wifi_config.h` は `.gitignore` に登録しているため、GitHubにはアップロードされません。
Wi-Fi情報は公開しないようにしてください。