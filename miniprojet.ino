#include <AFMotor.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

// Déclaration des 4 moteurs
AF_DCMotor motor1(1);  // M1
AF_DCMotor motor2(2);  // M2
AF_DCMotor motor3(3);  // M3
AF_DCMotor motor4(4);  // M4

LiquidCrystal_I2C lcd(0x20, 20, 4);
Servo servo1;
Servo servo2;
char cmd;

void setup() {
  Serial.begin(9600);       // Pour affichage PC
  Serial3.begin(9600);      // Pour Bluetooth (ex. BTBee Pro sur Mega)
  Serial.println("Pret a recevoir les commandes Bluetooth");

  // Vitesse initiale
  motor1.setSpeed(200);
  motor2.setSpeed(200);
  motor3.setSpeed(200);
  motor4.setSpeed(200);

  lcd.init(); // Initialisation
  lcd.backlight(); // Allumer le rétroéclairage
  lcd.setCursor(0, 0);
  lcd.print("LCD display write something");

   servo1.attach(9);
  servo2.attach(10);
  servo1.write(90);       // Position initiale
  servo2.write(90);
}

void loop() {
  if (Serial3.available()) {
    cmd = Serial3.read();

    // Ne garder que les lettres utiles
    
      Serial.print("Commande recue : ");
      Serial.println(cmd);

      executeCommand(cmd);
    }
  }


// Fonction pour exécuter les commandes moteurs
void executeCommand(char c) {
  switch (c) {
    case 'F': // Avancer
      motor1.run(FORWARD);
      motor2.run(FORWARD);
      motor3.run(FORWARD);
      motor4.run(FORWARD);
      break;
    case 'B': // Reculer
      motor1.run(BACKWARD);
      motor2.run(BACKWARD);
      motor3.run(BACKWARD);
      motor4.run(BACKWARD);
      break;
    case 'L': // Tourner gauche
      motor1.run(BACKWARD);
      motor2.run(FORWARD);
      motor3.run(BACKWARD);
      motor4.run(FORWARD);
      break;
    case 'R': // Tourner droite
      motor1.run(FORWARD);
      motor2.run(BACKWARD);
      motor3.run(FORWARD);
      motor4.run(BACKWARD);
      break;
    case 'S': // Stop
      motor1.run(RELEASE);
      motor2.run(RELEASE);
      motor3.run(RELEASE);
      motor4.run(RELEASE);
      break;
      case '0':
        servo1.write(0);
        break;
      case '1':
        servo1.write(45);
        break;
         case '2':
        servo1.write(90);
        break;
      case '3':
        servo1.write(135);
        break;
         case '4':
        servo1.write(180);
        break;
      case '5':
        servo2.write(0);
        break;
      case '6':
        servo2.write(45);
        break;
         case '7':
        servo2.write(90);
        break;
      case '8':
        servo2.write(135);
        break;
         case '9':
        servo2.write(180);
        break;
  }
}

