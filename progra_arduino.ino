// C++ code


#include <Servo.h> 


int potenciometro = A4;
int bM = 3;
int bA = 2;
int A = 4;
int B = 5;
int C = 6;
int D = 7;
int E = 8;
int F = 9;
int G = 10;
int rojo = 13;
int azul = 12;
int verde = 11;
int Buzzer = A3;
int Estado = 0,EstadoA, BAS, BMS, fc, pot, temp,VER;

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
 
  EstadoA = 0;
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
    	EstadoA = 1;
    }
    BAS = 0;
  }
  switch(Estado){
  	case 0:
    	
    	mostrarCero();
    	servo_9.write(0);
    	digitalWrite(rojo, 0);
    	digitalWrite(azul, 0);
    	digitalWrite(verde, 0);
    	break;
  	case 1:
    	mostrarUno();
    	servo_9.write(angulo);
    	fc = map(pot, 0, 1023, 0, 200);
    	frecuenciaC(fc);
    	break;
  	case 2:
    	mostrarDos();
    	
    	temp = map(pot, 0, 1023, 15, 40);
    	Serial.println(EstadoA);
        if(temp < 35){
          	servo_9.write(0);
        	  analogWrite(rojo, 255);
            analogWrite(azul, 255);
            analogWrite(verde, 0);
            if(EstadoA == 1){
              digitalWrite(Buzzer, LOW);
            }else{
              digitalWrite(Buzzer, HIGH);
            }
        }else if(35 <= temp && temp < 37){
          	servo_9.write(45);
        	  analogWrite(rojo, 0);
            analogWrite(azul, 255);
            analogWrite(verde, 255);
    	      digitalWrite(Buzzer, LOW);   
            EstadoA = 0;
        }else if(37 <= temp && temp < 38){
          	servo_9.write(90);
        	  analogWrite(rojo, 255);
            analogWrite(azul, 0);
            analogWrite(verde, 255);
    	      digitalWrite(Buzzer, LOW);   
            EstadoA = 0;
        }else if(38 <= temp && temp <= 39){
          	servo_9.write(135);
            analogWrite(rojo, 255);
            analogWrite(azul, 0);
            analogWrite(verde, 165);
    	      digitalWrite(Buzzer, LOW); 
            EstadoA = 0; 
        }else{
            servo_9.write(180);
        	  analogWrite(rojo, 255);
            analogWrite(azul, 255);
            analogWrite(verde, 255);
            if(EstadoA == 1){
              digitalWrite(Buzzer, LOW);
            }else{
              digitalWrite(Buzzer, HIGH);
            }
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
    analogWrite(rojo, 255);
    analogWrite(azul, 0);
    analogWrite(verde, 255);
  }else if(fC < 100 && fC >= 60){
    analogWrite(verde, 255);
    analogWrite(azul, 0);
    analogWrite(rojo, 0);
  }else if(fC < 150 && fC >= 100){
    analogWrite(rojo, 255);
    analogWrite(azul, 0);
    analogWrite(verde, 0);
  }else{
    delay(100);
    analogWrite(rojo, 0);
    delay(100);
    analogWrite(rojo, 255);
    analogWrite(azul, 0);
    analogWrite(verde, 0);
  }
}

//Modo 2: Monitor de temperatura corporal 

  
  
  
  
