//=====================================================================LIblary==
#include <DHT.h>

//========================DEFINE PIN========================
#define DHTPIN1 2
#define DHTPIN2 3
#define MQPIN   8

#define redPin    6
#define greenPin  5
#define bluePin   4

#define RL 47  //The value of resistor RL is 47K
#define m -0.263 //Enter calculated Slope
#define b 0.42 //Enter calculated intercept
#define Ro 30 //Enter found Ro value

#define DHTTYPE DHT22 //memilih tipe DHT11, bisa diubah menjadi DHT22, DHT21

DHT dht1(DHTPIN1, DHTTYPE);  //setting pin yang dipilih dan tipe DHT
DHT dht2(DHTPIN2, DHTTYPE);  //setting pin yang dipilih dan tipe DHT

//=====================================================================Timbangan&RFID==
String valueT;
String valueR;
String kirimdata;
String coba;

char dataT = 0;
char dataR = 0;

float kelembaban;
float suhu;

bool beresT;
bool beresR;
bool siap;

float amonia;
int idGrid;

float VRL; //Voltage drop across the MQ sensor
float Rs; //Sensor resistance at gas concentration
float ratio; //Define variable for ratio

void setup() {

  Serial.begin(9600);
  Serial1.begin(9600);

  dht1.begin();
  dht2.begin();

  pinMode(redPin,   OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin,  OUTPUT);

  siap = true;

  Serial.print("بِسْمِ اللَّهِ الرَّحْمَنِ الرَّحِيم");
}

void loop() {
  ledStanby();
  if (siap) {
    Serial2.begin(9600);
    Serial.println("siap timbangan");
    RFID();
  } else {
    Serial3.begin(9600);
    Serial.println("siap kirim");
    timbangan();
  }

}
