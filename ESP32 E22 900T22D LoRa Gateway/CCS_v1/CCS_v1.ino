#include <ArduinoJson.h>
#include <WiFi.h>
#include <PubSubClient.h>
#include "LoRa_E22.h"
#include <HardwareSerial.h>

// Replace the next variables with your SSID/Password combination
const char* ssid = "Teknofest";
const char* password = "16megabit";

// Add your MQTT Broker IP address, example:
//const char* mqtt_server = "192.168.1.144";
const char* mqtt_server = "192.168.1.85";

WiFiClient espClient;
PubSubClient client(espClient);

#define M0 32 //3in1 PCB mizde pin 7
#define M1 33 //3in1 PCB mizde pin 6
#define RX 27 //3in1 PCB mizde pin RX
#define TX 35  //3in1 PCB mizde pin TX
 
HardwareSerial fixajSerial(1);                            //Serial biri seçiyoruz.
LoRa_E22 e22(TX, RX, &fixajSerial, UART_BPS_RATE_9600);

typedef struct{
  byte command;
}CCS_MANUEL_COMMAND;

CCS_MANUEL_COMMAND manuel_command = {0};


void setup() {
  Serial.begin(9600);
  WiFi_Connect();
  client.setServer(mqtt_server, 1883);
  client.setCallback(callback);
  MQTT_Connect();
  
  pinMode(M0, OUTPUT);
  pinMode(M1, OUTPUT);
  digitalWrite(M0, LOW);
  digitalWrite(M1, 0);
 
  delay(500);
  e22.begin();
  delay(500);
}

void loop() {
  if (!client.connected()) {
    MQTT_Connect();
  }
  client.loop();
}

void WiFi_Connect(){
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
}

void MQTT_Connect(){
   while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("ESP32Client")) {
      Serial.println("connected");
      // Subscribe
      client.subscribe("yon");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void callback(char* topic, byte* message, unsigned int length) {
  Serial.print("Message arrived on topic: ");
  Serial.print(topic);
  Serial.print(". Message: ");
  String messageTemp;
  boolean transmit = false;
  
  for (int i = 0; i < length; i++) {
    Serial.print((char)message[i]);
    messageTemp += (char)message[i];
  }
  Serial.println();

  StaticJsonDocument <256> doc;
  deserializeJson(doc,message);

  byte command = doc["message"];
  Serial.println("Komut: " + String(command));
  
  if (String(topic) == "yon") {
    if(command == 0){
      manuel_command.command = 0;
      transmit = true;
    }
    else if(command == 1){
      manuel_command.command = 1;
      transmit = true;
    }
    else if(command == 2){
      manuel_command.command = 2;
      transmit = true;
    }
    else if(command == 3){
      manuel_command.command = 3;
      transmit = true;
    }
    else if(command == 4){
      manuel_command.command = 4;
      transmit = true;
    }
    if(transmit == true){
      ResponseStatus rs = e22.sendFixedMessage(0, 2, 18, &manuel_command, sizeof(CCS_MANUEL_COMMAND));
      Serial.println(rs.getResponseDescription());
    }
  }
  
//  if (String(topic) == "command") {
//    if(messageTemp == "0"){
//      manuel_command.command = 0;
//      transmit = true;
//    }
//    else if(messageTemp == "1"){
//      manuel_command.command = 1;
//      transmit = true;
//    }
//    else if(messageTemp == "2"){
//      manuel_command.command = 2;
//      transmit = true;
//    }
//    else if(messageTemp == "3"){
//      manuel_command.command = 3;
//      transmit = true;
//    }
//    else if(messageTemp == "4"){
//      manuel_command.command = 4;
//      transmit = true;
//    }
//
//    if(transmit == true){
//      ResponseStatus rs = e22.sendFixedMessage(0, 2, 18, &manuel_command, sizeof(CCS_MANUEL_COMMAND));
//      Serial.println(rs.getResponseDescription());
//    }
//  }
}
