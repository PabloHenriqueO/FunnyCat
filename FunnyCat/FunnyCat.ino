#include <Servo.h>
#include "MotorPasso.h"
#include <robo_hardware2.h>

MotorPasso mp(64,64);
#define PIN_FRENTE_DIR 3
#define PIN_FRENTE_ESQ 9
#define PIN_TRASEIRO_DIR 11
#define PIN_TRASEIRO_ESQ 10
#define LED1 4
#define LED2 2

Servo servo_frontal_dir; 
Servo servo_frontal_esq;
Servo servo_traseiro_dir;
Servo servo_traseiro_esq;

int pos = 0;    // variable to store the servo position
float valorSensorFrontal;
float valorSensorLateral;

void setup() {
  robo.configurar(false);
  Serial.begin(9600);
  pinMode(LED1,OUTPUT);
  pinMode(LED2,OUTPUT);
  
  servo_frontal_dir.attach(PIN_FRENTE_DIR);
  servo_frontal_esq.attach(PIN_FRENTE_ESQ);
  servo_traseiro_dir.attach(PIN_TRASEIRO_DIR);
  servo_traseiro_esq.attach(PIN_TRASEIRO_ESQ);// attaches the servo on pin 9 to the servo object
  
}


void loop() {
 
  valorSensorFrontal = robo.lerSensorSonarFrontal(); //FUNCAO PARA LER VALOR DO SENSOR FRONTAL
  Serial.println(valorSensorFrontal);
  if(valorSensorFrontal<=5){
    digitalWrite(LED2,LOW);
    digitalWrite(LED1,HIGH);
   
   
    servo_traseiro_esq.write(80);
    servo_traseiro_dir.write(110); 
    delay(2000);
    servo_traseiro_esq.write(60);
    servo_traseiro_dir.write(130); 
    delay(2000);
    servo_traseiro_esq.write(40);
    servo_traseiro_dir.write(150); 
    delay(2000); 
    //mp.acionarMotoresEmGraus(80, 180);      
    servo_frontal_dir.attach(PIN_FRENTE_DIR);
    servo_frontal_esq.attach(PIN_FRENTE_ESQ);
    servo_traseiro_dir.attach(PIN_TRASEIRO_DIR);
    servo_traseiro_esq.attach(PIN_TRASEIRO_ESQ);// attaches the servo on pin 9 to the servo object
    
    
  }
  else{
    digitalWrite(LED1,LOW);
    digitalWrite(LED2,HIGH);
    
    servo_frontal_dir.write(110); // frontal direito pra frente
    servo_traseiro_esq.write(80); // traseiro esquerdo pra frente
    servo_traseiro_dir.write(80); //traseiro direito pra frente
    servo_frontal_esq.write(110); //frontal esquerdo pra frente
    delay(500);
    servo_frontal_dir.write(80); // frontal direito pra frente
    servo_traseiro_esq.write(110); // traseiro esquerdo pra frente
    servo_traseiro_dir.write(110); //traseiro direito pra frente
    servo_frontal_esq.write(80); //frontal esquerdo pra frente
    delay(500); 
  }
}
