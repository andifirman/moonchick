#include <DHT.h>
#include <WiFiUdp.h>
#include <ESP8266WiFi.h>

#define WIFI_SSID "TP-Link AP"
#define WIFI_PASSWORD "4l4yb3td4h"

#define DHTTYPE   DHT22
#define DHT1PIN   D1
#define DHT2PIN   D2

#define ledBlue   D5
#define ledGreen  D6
#define ledRed    D7

#define onFan     D0

#define l_on      HIGH
#define l_off     LOW

WiFiUDP Udp;
unsigned int localUdpPort = 8888;  // local port to listen on

DHT dht1(DHT1PIN, DHTTYPE, 11); // 11 works fine for ESP8266
DHT dht2(DHT2PIN, DHTTYPE, 11); // 11 works fine for ESP8266

//===================================================================VARIABLES==
//===DHT===
float TempA = 0, HumA = 0;
float TempB = 0, HumB = 0;
float Temp  = 0, Hum  = 0;

//===Anemometer===
float WindSpeed = 0;
float angin;
float value;

long intervalOn     = 60000;
long previousMillis = 0;

String dataKirim;

void setup() {

  Serial.begin(9600
  );
  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  IPAddress ip(192, 168, 43, 25);
  IPAddress gateway(192, 168, 43, 1);
  IPAddress subnet(255, 255, 255, 0);
  WiFi.config(ip, gateway, subnet);

  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
    //    Sensor_reconect();
  }

  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  pinMode(ledBlue, OUTPUT);
  pinMode(ledGreen, OUTPUT);
  pinMode(ledRed, OUTPUT);
  pinMode(onFan, OUTPUT);

  //  digitalWrite(ledBlue, l_on);
  //  digitalWrite(ledGreen, l_on);
  //  digitalWrite(ledRed, l_on);

  //===power on anemometer===
  digitalWrite(onFan, HIGH);
  delay(5000);
  digitalWrite(onFan, LOW);

  dht1.begin();
  dht2.begin();



  digitalWrite(ledBlue, l_off);
  digitalWrite(ledGreen, l_off);
  digitalWrite(ledRed, l_off);

  Serial.println("بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم");
}

void loop() {
  //  if (WiFi.status() != WL_CONNECTED) {
  //    reconnectWifi();
  //  }

  Wait_Process();

  dht22();
  wind();

  sendUDP();

  delay(1000);
}
