/*
// Pines de conexión // 7 segmentos 3 digitos SH5361BS
const int digit1 = 2; // Pin del primer dígito(pin 7 del 7 segmentos)
const int digit2 = 3; // Pin del segundo dígito (pin 10 del 7 segmentos)
const int digit3 = 4; // Pin del tercer dígito (pin 11 del 7 segmentos)
const int segmentA = 5; // Pin del LED superior (pin 8 del 7 segmentos)
const int segmentB = 6; // Pin del LED arriba derecha (pin 12 del 7 segmentos)
const int segmentC = 7; // Pin del LED abajo derecha (pin 4 del 7 segmentos)
const int segmentD = 8; // Pin del LED inferior (pin 2 del 7 segmentos)
const int segmentE = 9; // Pin del LED abajo izquierda (pin 1 del 7 segmentos)
const int segmentF = 10; // Pin del LED arriba izquierda (pin 9 del 7 segmentos)
const int segmentG = 11; // Pin del LED central (pin 5 del 7 segmentos)
const int segmentDP = 12; // Pin del LED del punto (pin 3 del 7 segmento)
*/
#include <SevSeg.h>

int clampPin = A0; // Pin de la pinza
int pinA = 5;int pinB = 6;int pinC = 7;int pinD = 8;
int pinE = 9;int pinF = 10;int pinG = 11;
int pinDP = 12;int D1 = 2;int D2 = 3;int D3 = 4; //int D4 = 1;
float R1 = 983000;
float R2 = 99600;

void setup() {//set all segments & digits as outputs
  Serial.begin(9600); //initialize serial communication at 9600 bits per second
  pinMode(clampPin, INPUT);
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);
  pinMode(pinC, OUTPUT);
  pinMode(pinD, OUTPUT);
  pinMode(pinE, OUTPUT);
  pinMode(pinF, OUTPUT);
  pinMode(pinG, OUTPUT);
  pinMode(pinDP, OUTPUT);
  pinMode(D1, OUTPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
//  pinMode(D4, OUTPUT);
}

void loop() {
  // Recta de caracterización de la pinza
  //  Y = 1.2417 x + 1.2721 (Y corriente x voltaje)
  // Leer el valor de la pinza
  //float clampValue = analogRead(clampPin)*5/1023;
  float clampValue=analogRead(0)*5/1023.0;
  float voltaje = (clampValue*(R1+R2)/R2);
  float corriente = 1.2417 * voltaje + 1.2721;
  
  Serial.println(clampValue);
  Serial.print(voltaje);
  Serial.print(" voltios\n");
  Serial.print(corriente);
  Serial.print(" amperios\n");
  delay(1);
  
  // Mapear el valor del potenciómetro al rango de 0 a 999
  //int numero = map(corriente, 0, 1023, 0, 999);
  
  int amp = corriente*100;

  //Serial.println(amp);
  int digito1 = amp / 100; // Dígito más significativo
  //Serial.println(digito1);
  int digito2 = (amp / 10) % 10; // Dígito del medio
  //Serial.println(digito2);
  int digito3 = amp % 10; // Dígito menos significativo
  //Serial.println(digito3);
  // Dígito 3
  digitalWrite(D1, LOW);
  digitalWrite(D2, LOW);
  digitalWrite(D3, HIGH);
  digitalWrite(pinDP, HIGH);
  displayDigit(digito3);
  delay(10);
  // Dígito 2
  digitalWrite(D1, LOW);
  digitalWrite(D2, HIGH);
  digitalWrite(D3, LOW);
  digitalWrite(pinDP, HIGH);
  displayDigit(digito2);
  delay(10);
  // Dígito 1
  digitalWrite(D1, HIGH);
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(pinDP, LOW);
  displayDigit(digito1);
  delay(10);

}

//functions representing numbers 0-9
void zero(){
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, HIGH);
}

void one(){
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}

void two(){
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, HIGH);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, LOW);
}
  
void three(){
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, LOW);
}
    
void four(){
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}
    
void five(){
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}
    
void six(){
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}
    
void seven(){
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, HIGH);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, HIGH);
  digitalWrite(pinG, HIGH);
}
    
void eight(){
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, LOW);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}
    
void nine(){
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  digitalWrite(pinC, LOW);
  digitalWrite(pinD, LOW);
  digitalWrite(pinE, HIGH);
  digitalWrite(pinF, LOW);
  digitalWrite(pinG, LOW);
}

void displayDigit(int digit){
  switch (digit) {
    case 0:
      zero();
      break;
    case 1:
      one();
      break;
    case 2:
      two();
      break;
    case 3:
      three();
      break;
    case 4:
      four();
      break;
    case 5:
      five();
      break;
    case 6:
      six();
      break;
    case 7:
      seven();
      break;
    case 8:
      eight();
      break;
    case 9:
      nine();
      break;
  }
}
