//
// Copyright 2020 ChickenMy Inc.
//

#include <WiFiUdp.h>
#include <ESP8266WiFi.h>
#include <FirebaseArduino.h>

#define WIFI_SSID "TP-Link AP"
#define WIFI_PASSWORD "4l4yb3td4h"

//#define FIREBASE_HOST "chickenmy-e5f9f.firebaseio.com"
//#define FIREBASE_AUTH "eEYt6J7B6jXFZb3C5coofCK9iZmkwDsjnAqNzsfH"

#define FIREBASE_HOST "dabes-8aa5c-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "QbkTQlVzsVDYWtMjcZMC9D0CyjhWalPq6DfTTSir"

#define redPin    D7
#define greenPin  D6
#define bluePin   D5

//==============Sensor Tetap==============
#define DBRataSuhu    "kandang/fix1/rerata/temp"
#define DBRataHumi    "kandang/fix1/rerata/hum"
#define DBWindSpeed   "kandang/fix1/W1/speed"

#define DBUpdateTgl   "kandang/fix1/update/tanggal"
#define DBUpdateWaktu "kandang/fix1/update/waktu"

#define DBRekapFix    "rekap/interval/"


IPAddress ip(192, 168, 43, 24);
IPAddress dns(192, 168, 43, 1);
IPAddress gateway(192, 168, 43, 1);
IPAddress subnet(255, 255, 255, 0);

//===Config time===
int timezone = 7;
int dst = 0;

char ntp_server1[20] = "ntp.ku.ac.th";
char ntp_server2[20] = "fw.eng.ku.ac.th";
char ntp_server3[20] = "time.uni.net.th";


//============UDP Setting ==================
WiFiUDP Udp;
unsigned int localUdpPort = 8888;
char incomingPacket[255];  // buffer for incoming packets

//=============Firebase Setting==============
String DBLocationSetting  = "kandang/setting/";
String getHariKe          = DBLocationSetting + "harike";

//Sensor Tetap
String getGalatTemp = DBLocationSetting + "rangeTemp";
String getGalatHumi = DBLocationSetting + "rangeHumi";
String getGalatWind = DBLocationSetting + "rangeWind";

String DBFixEdge      = "ujicoba/FixEdge/";

//Portabel
String DBPortabel   = "kandang/portabel/";
String DBGrafik     = "grafik/grid/";

//blower kontrol
String getBlowerLev1 = DBLocationSetting + "level1";
String getBlowerLev2 = DBLocationSetting + "level2";
String getBlowerLev3 = DBLocationSetting + "level3";
String getBlowerLev4 = DBLocationSetting + "level4";


//==============Variabel===============
int harike = 1;
//Sensor Tetap
String sFixTemp;
String sFixHumi;
String sFixWindSpeed;

String sFixTempRef, sFixHumiRef, sFixWindRef;
String tanggalRef, tanggalW1Ref, waktuS1Ref, waktuS2Ref, waktuW1Ref;

String galatSFixTemp;
String galatSFixHuma;
String galatSFixWind;

//Sensor Portabel
String idTemp, id, berat, amonia, hum, temp, idGrid;

//blower kontrol
String blowerLev1, blowerLev2, blowerLev3, blowerLev4;
String levelBlower;
String levelBlowerLama = "";


String jenisData;

void setup() {
  Serial.begin(9600);

  // ----------------- connect to wifi -----------------
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);

  WiFi.config(ip, dns, gateway, subnet);

  Serial.print("connecting");
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(50);
  }

  Serial.println();
  Serial.print("connected: ");
  Serial.println(WiFi.localIP());
  // ----------------------------------------------------

  Udp.begin(localUdpPort);

  configTime(timezone * 3600, dst, ntp_server1, ntp_server2, ntp_server3);
  Serial.println("Waiting for time");
  while (!time(nullptr)) {
    Serial.print(".");
  }

  // connect Firebase
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

  //======get data reference Firebase==========
  sFixTempRef   = Firebase.getString(DBRataSuhu);
  sFixHumiRef   = Firebase.getString(DBRataHumi);
  sFixWindSpeed = Firebase.getString(DBWindSpeed);

  galatSFixTemp = Firebase.getString(getGalatTemp);
  galatSFixHuma = Firebase.getString(getGalatHumi);
  galatSFixWind = Firebase.getString(getGalatWind);

  blowerLev1    = Firebase.getString(getBlowerLev1);
  blowerLev2    = Firebase.getString(getBlowerLev2);
  blowerLev3    = Firebase.getString(getBlowerLev3);
  blowerLev4    = Firebase.getString(getBlowerLev4);

  harike        = Firebase.getInt(getHariKe);
  
  if (Firebase.failed()) {
    Serial.println("gagal");
  }

  pinMode(redPin,   OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin,  OUTPUT);

  Serial.println("بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم");
}

void loop() {
  // put your main code here, to run repeatedly:
  ledStanby();
  terimaData();

}
