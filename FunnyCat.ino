#include <Servo.h>

#define PIN_FRENTE_DIR 3
#define PIN_FRENTE_ESQ 9
#define PIN_TRASEIRO_DIR 5
#define PIN_TRASEIRO_ESQ 10

Servo servo_frontal_dir; 
Servo servo_frontal_esq;
Servo servo_traseiro_dir;
Servo servo_traseiro_esq;

int pos = 0;    // variable to store the servo position

void setup() {
  servo_frontal_dir.attach(PIN_FRENTE_DIR);
  servo_frontal_esq.attach(PIN_FRENTE_ESQ);
  servo_traseiro_dir.attach(PIN_TRASEIRO_DIR);
  servo_traseiro_esq.attach(PIN_TRASEIRO_ESQ);// attaches the servo on pin 9 to the servo object
  
}


void loop() {
  
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
