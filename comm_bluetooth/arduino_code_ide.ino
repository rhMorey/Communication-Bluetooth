#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h> //Bibliothèque permettant la gestion du module BLE
 #define RxD 2
 #define TxD 3
 SoftwareSerial BLE(RxD,TxD); // Déclare le module BLE branché en 2 et 3
double angle_rad = PI/180.0;
double angle_deg = 180.0/PI;
double status;

 void setup()
 {
 Serial.begin(9600);
 pinMode(RxD, INPUT);
 pinMode(TxD, OUTPUT);
 setupBleConnection();
 pinMode(8, OUTPUT);
 pinMode(4,OUTPUT);
 pinMode(5,OUTPUT);
 pinMode(7,OUTPUT);
 pinMode(6,OUTPUT);
 }
void loop()
 {
int status;
 if(BLE.available()){//vérifie si des données ont été envoyées depuis le moduleBLE
 status = BLE.read(); //Permet de lire les données reçues
 }
if (status == 1) {if(((status)==(1))){
        digitalWrite(4,1);
        analogWrite(5,150);
        digitalWrite(7,1);
        analogWrite(6,0);
    }}
if (status == 2) {if(((status)==(2))){
        digitalWrite(4,1);
        analogWrite(5,0);
        digitalWrite(7,1);
        analogWrite(6,0);
    }}
if (status == 4) {if(((status)==(4))){
        digitalWrite(4,0);
        analogWrite(5,200);
        digitalWrite(7,1);
        analogWrite(6,25);
    }}
if (status == 3) {if(((status)==(3))){
        digitalWrite(4,0);
        analogWrite(5,25);
        digitalWrite(7,1);
        analogWrite(6,200);
    }}

}
 void setupBleConnection() // Fonction paramétrant le module BLE
 {
 BLE.begin(9600); //
 BLE.print("AT+CLEAR");
 BLE.print("AT+ROLE1"); //Configure le module BLE en tant que maître
 BLE.print("AT+SAVE1");
 }
