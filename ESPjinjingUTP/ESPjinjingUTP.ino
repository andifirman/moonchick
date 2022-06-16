
//========LIBRARY========
#include <ESP8266WiFi.h>
#include <WiFiUdp.h>

//========WIFI AND FIREBASE SETTING========

#define WIFI_SSID "TP-Link AP"
#define WIFI_PASSWORD "4l4yb3td4h"

#define redPin    D0
#define greenPin  D1
#define bluePin   D2

//coba dulu pakai fix sensor
//#define redPin    D7
//#define greenPin  D6
//#define bluePin   D5

WiFiUDP Udp;
unsigned int localUdpPort = 8888;  // local port to listen on

// -----------------------Variable-----------------------
String bacaSerial;
String idTemp, id, berat, amonia, hum, temp;

int idGrid;

bool terima = false;

String dataKirim;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  // connect to wifi.
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  IPAddress ip(192, 168, 43, 26);
  IPAddress gateway(192, 168, 43, 1);
  IPAddress subnet(255, 255, 255, 0);
  WiFi.config(ip, gateway, subnet);
  
  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }

  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());


  pinMode(redPin,   OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin,  OUTPUT);

  Serial.println("بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم");
}

void loop() {
  ledStanby();
  getData();
}
