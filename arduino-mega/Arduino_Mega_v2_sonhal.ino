#include <AFMotor.h>
 
AF_DCMotor leftBack(1); // create motor #1
AF_DCMotor rigthBack(2); // create motor #2
AF_DCMotor rigthFront(3); // create motor #3
AF_DCMotor leftFront(4); // create motor #4

String UART_DATA = "";
byte UART_LENGTH = 0;
boolean UART_COMPLETE = false;

byte BASE_SPEED = 100;
 
void setup() {

  Serial.begin(115200);           // set up Serial library at 9600 bps
  Serial1.begin(115200);
  Serial.println("Motor test!");
   
  leftBack.setSpeed(150);     //Hız 200 - 255
  leftFront.setSpeed(150);     //Hız 200 - 255
  rigthBack.setSpeed(150);     //Hız 200 - 255
  rigthFront.setSpeed(150);     //Hız 200 - 255
}

void loop() {
  UART_Control();



}





///////////////////////////////////////// Metotlar //////////////////////////////////
void forward(){
  BASE_SPEED = 100;
  leftBack.setSpeed(BASE_SPEED);
  leftFront.setSpeed(BASE_SPEED);
  rigthBack.setSpeed(BASE_SPEED);
  rigthFront.setSpeed(BASE_SPEED);
  
  Serial.println("FORWARD");
  leftFront.run(FORWARD);       
  rigthFront.run(FORWARD);      
  leftBack.run(FORWARD);      
  rigthBack.run(FORWARD);

  for(byte i = 0; i < 31; i++){
    BASE_SPEED += 5;
    delay(25);
    leftBack.setSpeed(BASE_SPEED);
    leftFront.setSpeed(BASE_SPEED);
    rigthBack.setSpeed(BASE_SPEED);
    rigthFront.setSpeed(BASE_SPEED);
  }
}

void backward(){
  BASE_SPEED = 100;
  leftBack.setSpeed(BASE_SPEED);
  leftFront.setSpeed(BASE_SPEED);
  rigthBack.setSpeed(BASE_SPEED);
  rigthFront.setSpeed(BASE_SPEED);
  
  Serial.println("BACKWARD");
  leftFront.run(BACKWARD);       
  rigthFront.run(BACKWARD);      
  leftBack.run(BACKWARD);      
  rigthBack.run(BACKWARD);

   for(byte i = 0; i < 31; i++){
    BASE_SPEED += 5;
    delay(25);
    leftBack.setSpeed(BASE_SPEED);
    leftFront.setSpeed(BASE_SPEED);
    rigthBack.setSpeed(BASE_SPEED);
    rigthFront.setSpeed(BASE_SPEED);
  }
}

void left(){
  BASE_SPEED = 200;
  leftBack.setSpeed(BASE_SPEED);
  leftFront.setSpeed(BASE_SPEED);
  rigthBack.setSpeed(BASE_SPEED);
  rigthFront.setSpeed(BASE_SPEED);
  
  Serial.println("LEFT");
  leftFront.run(BACKWARD);
  leftBack.run(BACKWARD);        
  rigthFront.run(FORWARD);
  rigthBack.run(FORWARD);
}

void rigth(){
  BASE_SPEED = 200;
  leftBack.setSpeed(BASE_SPEED);
  leftFront.setSpeed(BASE_SPEED);
  rigthBack.setSpeed(BASE_SPEED);
  rigthFront.setSpeed(BASE_SPEED);
  
  Serial.println("RIGTH");
  leftFront.run(FORWARD);
  leftBack.run(FORWARD);        
  rigthFront.run(BACKWARD);
  rigthBack.run(BACKWARD);
}

void stop(){
  for(byte i = 0; i < 31; i++){
    BASE_SPEED -= 5;
    delay(25);
    leftBack.setSpeed(BASE_SPEED);
    leftFront.setSpeed(BASE_SPEED);
    rigthBack.setSpeed(BASE_SPEED);
    rigthFront.setSpeed(BASE_SPEED);
  }
  
  Serial.println("dur");
  leftFront.run(RELEASE);  
  leftBack.run(RELEASE); 
  rigthFront.run(RELEASE); 
  rigthBack.run(RELEASE);
}

void UART_Control(){
  //Serial Buffer = "ileri", Serial Buffer Size = 5, Serial.available() return -> 5.
  while(Serial1.available() > 0){
    char ch = Serial1.read();  //İlk okumada 'i', 'l', ..., her read() metodu çağrıldıktan sonra ilgili veri buffer'dan silinir ve buffer size 1 azaltılır.
    if(ch != '\n')
      UART_DATA += ch;  //"i", "il", "ile", "iler", "ileri"
    else{
      UART_COMPLETE = true;
      Serial.println("Gelen Veri: " + UART_DATA);
      break;
    }
  }

  if(UART_COMPLETE == true){
    //stop();
    //delay(500);

    if(UART_DATA[0] == 'i'){
      forward();
    }
    else if(UART_DATA[0] == 'g'){
      backward();
    }
    else if(UART_DATA[0] == 's' && UART_DATA[1] == 'a'){
      rigth();
    }
    else if(UART_DATA[0] == 's' && UART_DATA[1] == 'o'){
      left();
    }
    else if(UART_DATA[0] == 'd'){
      stop();
    }
    else{
      Serial.println("Gecersiz Komut");
    }

    UART_COMPLETE = false;
    UART_DATA = "";
  }
}
