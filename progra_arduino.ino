// C++ code


#include <Servo.h> 

int pos = 0;
int potenciometro = A4;
int bM = A0;
int bA = A1;
int A = 4;
int B = 5;
int C = 6;
int D = 7;
int E = 8;
int F = 9;
int G = 10;
int rojo = 11;
int azul = 12;
int verde = A5;
int Buzzer = A3;
int Estado = 0, BAS, BMS, fc, pot, temp,VER;
int ultimoEstadoBoton = LOW;
Servo servo_9;

void setup(){
  servo_9.attach(A2);
  Serial.begin(9600);

//PinMode para entradas y salidas. 
  pinMode(bM, INPUT);
  pinMode(bA, INPUT);
  pinMode(potenciometro, INPUT);
  pinMode(A, OUTPUT); 
  pinMode(B, OUTPUT); 
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT); 
  pinMode(E, OUTPUT); 
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(rojo, OUTPUT);
  pinMode(azul, OUTPUT);
  pinMode(verde, OUTPUT);
  pinMode(Buzzer, OUTPUT);
 
}

void loop()
{
  pot = analogRead(potenciometro);
  int angulo = map(pot, 0, 1023, 0, 180);
  int BM = digitalRead(bM);
  delay(15);
  if(BM == HIGH){
    BMS = 1;
  }
  if(BMS == 1 && BM == LOW){
    if(Estado == 2){
    	Estado = 0;
    }else{
    	Estado ++;
    }
    BMS = 0;
  }
  
  int BA = digitalRead(bA);
  delay(15);
  if(BA == HIGH){
    BAS = 1;
    
  }
  if(BAS == 1 && BA == LOW){
    if(Estado == 2){
    	digitalWrite(Buzzer, LOW);
    }
    BAS = 0;
  }
  VER = map(pot, 0, 1023, 0, 255);
  analogWrite(verde, VER);
  Serial.println(VER);
  switch(Estado){
  	case 0:
    	
    	mostrarCero();
    	servo_9.write(0);
    	digitalWrite(rojo, LOW);
    	digitalWrite(azul, LOW);
    	digitalWrite(verde, LOW);
    	break;
  	case 1:
    	mostrarUno();
    	servo_9.write(angulo);
    	fc = map(pot, 0, 1023, 0, 200);
    	frecuenciaC(fc);
    	break;
  	case 2:
    	mostrarDos();
    	servo_9.write(180);
    	temp = map(pot, 0, 1023, 15, 40);
        if(temp < 35){
        	digitalWrite(rojo, HIGH);
            digitalWrite(azul, HIGH);
            digitalWrite(verde, LOW);
        }else if(35 <= temp && temp < 37){
        	digitalWrite(rojo, LOW);
            digitalWrite(azul, HIGH);
            digitalWrite(verde, HIGH);
        }else if(37 <= temp && temp < 38){
        	digitalWrite(rojo, HIGH);
            digitalWrite(azul, LOW);
            digitalWrite(verde, HIGH);
        }else if(38 <= temp && temp <= 39){
        	digitalWrite(rojo, LOW);
            digitalWrite(azul, LOW);
            
          	Serial.println(VER);
        }else{
        	digitalWrite(rojo, HIGH);
            digitalWrite(azul, HIGH);
            digitalWrite(verde, HIGH);
        }  
    	break;
  }
}
  
//Configuración Display
void mostrarCero() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH); 
  digitalWrite(C, HIGH);
  digitalWrite(D, HIGH); 
  digitalWrite(E, HIGH); 
  digitalWrite(F, HIGH);
  digitalWrite(G, LOW);
}

void mostrarUno() {
  digitalWrite(A, LOW); 
  digitalWrite(B, HIGH); 
  digitalWrite(C, HIGH);
  digitalWrite(D, LOW); 
  digitalWrite(E, LOW);
  digitalWrite(F, LOW);
  digitalWrite(G, LOW);
}

void mostrarDos() {
  digitalWrite(A, HIGH);
  digitalWrite(B, HIGH); 
  digitalWrite(C, LOW);
  digitalWrite(D, HIGH); 
  digitalWrite(E, HIGH); 
  digitalWrite(F, LOW);
  digitalWrite(G, HIGH);
}


//Modo 1: Monitor de frecuencia cardíaca.
void frecuenciaC(int fC){
  if(fC < 60){
    digitalWrite(rojo, HIGH);
    digitalWrite(azul, LOW);
    digitalWrite(verde, HIGH);
  }else if(fC < 100 && fC >= 60){
    digitalWrite(verde, HIGH);
    digitalWrite(azul, LOW);
    digitalWrite(rojo, LOW);
  }else if(fC < 150 && fC >= 100){
    digitalWrite(rojo, HIGH);
    digitalWrite(azul, LOW);
    digitalWrite(verde, LOW);
  }else{
    delay(100);
    digitalWrite(rojo, LOW);
    delay(100);
    digitalWrite(rojo, HIGH);
    digitalWrite(azul, LOW);
    digitalWrite(verde, LOW);
  }
}

//Modo 2: Monitor de temperatura corporal 

