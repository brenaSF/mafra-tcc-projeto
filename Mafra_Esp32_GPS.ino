#include <TinyGPSPlus.h>
#include <WiFi.h>
#include <FirebaseESP32.h>
#define RX 16 
#define TX 17
#define FIREBASE_HOST "https://registromafra-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "1qWpfhZT1Jm49pCc3b6n7NpgTjIENALwv8DtoPye"
#define led 18
#define botao 33
#define bot 19
int ativa = 2;
const char* ssid = "Hi";
const char* password = "brena123";
boolean novadata = false;
String  PAI = "/Ficha do usuario";
static const int RXPin = 16, TXPin = 17;
float lat,lon;
String longitude,latitude,datadoalerta;
int mes,dia,ano,minuto,segundo,hora;
FirebaseData firebaseData;

// The TinyGPSPlus object
TinyGPSPlus gps;

// The serial connection to the GPS device
HardwareSerial GPS(1);

void setup(){
  pinMode(botao, INPUT_PULLUP);
  pinMode(bot, INPUT_PULLUP);
  Serial.begin(115200);
  GPS.begin(9600,SERIAL_8N1,RX,TX);
  WiFi.begin(ssid,password);
  Firebase.begin(FIREBASE_HOST,FIREBASE_AUTH);
  pinMode(led,OUTPUT);
  conectaWifi(); }

void loop(){ 
  // This sketch displays information every time a new sentence is correctly encoded.
 conf();}

void conectaWifi(){
if(WiFi.status()==WL_CONNECTED)
return;
while(WiFi.status()!= WL_CONNECTED){
  delay(500);
Serial.println("Conectando ao WiFi..."); }
digitalWrite(led, LOW);
delay(500);  }

void conf(){
 for(unsigned long start = millis(); millis() - start < 1000;){
  while (GPS.available()){
    if (gps.encode(GPS.read())){      
    novadata = true;  }}
  
  if (novadata == true)
  {
    novadata = false;
    Serial.print("satelites:");
    Serial.println(gps.satellites.value());
    delay(1000);
    if(digitalRead(botao)==LOW){
    ativa = 1;
    }
    if(digitalRead(bot)==LOW){
    digitalWrite(led, LOW);
    ativa = 0;
    }
         if(ativa == 1){

      digitalWrite(led, LOW);
      displayInfo();
      Serial.println("Enviado ao Firebase!!");
      digitalWrite(led, HIGH);
      
      } }}}
// função pra transformar o horário em string
String strHora(int horario){
    //declarar a string do horário 
    String strHorario = "";

    if(horario < 10){
        //se for menor q 10, adiciona o 0 na frente
        strHorario += "0";
    }
    // aí adiciona o horário aqui e retorna ele
    strHorario += String(horario);
    return strHorario;
}
void displayInfo()
{ 
  
  lon = gps.location.lng();
  lat = gps.location.lat();
  longitude = String(lon,6);
  latitude = String(lat,6);
  mes = gps.date.month();
  dia = gps.date.day();
  ano = gps.date.year();
  hora = gps.time.hour() - 4;
  minuto = gps.time.minute();
  segundo = gps.time.second();
  String stringHora = strHora(hora);
  String stringMin = strHora(minuto);
  String stringSeg = strHora(segundo);
  String horario = stringHora + ":" + stringMin + ":" + stringSeg;
  String datadoalerta = String(dia) + "/" + String(mes) + "/" + String(ano);
 // String Horario = String(hora) + ":" + String(minuto) + ":" + String(segundo);
  
  //Serial.print(F("Location: ")); 
  if (gps.location.isValid())
  {
    Firebase.setString(firebaseData, PAI + "/-Mo9rVTXzWmKRK5aAuQF"+"/latitude",latitude);
    Firebase.setString(firebaseData, PAI + "/-Mo9rVTXzWmKRK5aAuQF"+"/longitude",longitude);
  }
  else
  {
    Serial.print(F("INVALID"));
  }

 // Serial.print(F("Date/Time: "));
  if (gps.date.isValid())
  { 
    Firebase.setString(firebaseData, PAI + "/-Mo9rVTXzWmKRK5aAuQF"+"/datadoalerta",datadoalerta);
  
   // Serial.print(gps.date.month());
   // Serial.print(F("/"));
  //  Serial.print(gps.date.day());
   // Serial.print(F("/"));
  //  Serial.print(gps.date.year());
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.print(F(" "));
  if (gps.time.isValid())
  {
    Firebase.setString(firebaseData, PAI + "/-Mo9rVTXzWmKRK5aAuQF"+"/horario",horario);
  
  }
  else
  {
    Serial.print(F("INVALID"));
  }

  Serial.println();
}
