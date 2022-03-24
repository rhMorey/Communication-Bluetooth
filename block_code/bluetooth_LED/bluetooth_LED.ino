#include <SoftwareSerial.h> //Bibliothèque permettant la gestion du module BLE
 #define RxD 2
 #define TxD 3
 SoftwareSerial BLE(RxD,TxD); // Déclare le module BLE branché en 2 et 3
 void setup()
 {
 Serial.begin(9600);
 pinMode(RxD, INPUT);
 pinMode(TxD, OUTPUT);
 setupBleConnection();
 pinMode(6, OUTPUT);
 pinMode(7, OUTPUT);
 }
void loop()
 {
int LED;
 if(BLE.available()){//vérifie si des données ont été envoyées depuis le moduleBLE
 LED = BLE.read(); //Permet de lire les données reçues
 }
if (LED == 1) {
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  } 
if (LED == 0) {
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  } 
}
 void setupBleConnection() // Fonction paramétrant le module BLE
 {
 BLE.begin(9600); //
 BLE.print("AT+CLEAR");
 BLE.print("AT+ROLE1"); //Configure le module BLE en tant que maître
 BLE.print("AT+SAVE1");
 }
