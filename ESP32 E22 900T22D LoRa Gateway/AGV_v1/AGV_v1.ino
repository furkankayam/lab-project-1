#include "LoRa_E22.h"
#include <HardwareSerial.h>

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

boolean receive = false;

void LoRa_Listen(void);

void setup() {
  Serial.begin(115200);
  
  pinMode(M0, OUTPUT);
  pinMode(M1, OUTPUT);
  digitalWrite(M0, LOW);
  digitalWrite(M1, 0);
 
  delay(500);
  e22.begin();
  delay(500);
}

void loop() {
  LoRa_Listen();

  if(receive == true){
    if(manuel_command.command == 0)
      Serial.println("dur");
    else if(manuel_command.command == 1)
      Serial.println("ileri");
    else if(manuel_command.command == 2)
      Serial.println("sag");
    else if(manuel_command.command == 3)
      Serial.println("geri");
    else if(manuel_command.command == 4)
      Serial.println("sol");
      
    receive = false;
  }
}

void LoRa_Listen(){
  while (e22.available()  > 0) {
    // Gelen mesaj okunuyor
    ResponseStructContainer rsc = e22.receiveMessage(sizeof(CCS_MANUEL_COMMAND));
    manuel_command = *(CCS_MANUEL_COMMAND*) rsc.data;

    rsc.close();
    receive = true;
  }
}
