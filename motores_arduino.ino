#define Pecho 11
#define Ptrig 12
long duracion, distancia; 

int t = 50;


//Motor derecho
int IN1 = 4;    //Input3 conectada al pin 4
int IN2 = 5;    //Input4 conectada al pin 3
int ENA = 3;    // ENB conectada al pin 2 de arduino

int IN3 = 6;
int IN4 = 7;
int ENB = 9;
int IN13 = 13;
int INTD = 2;

int k;

void setup()
{
 pinMode(IN1,OUTPUT);
 pinMode(IN2,OUTPUT);
  pinMode(IN3,OUTPUT);
 pinMode(IN4,OUTPUT);
 pinMode(ENB,OUTPUT);
 pinMode(ENA, OUTPUT);
 pinMode(IN13, OUTPUT);
 pinMode(INTD, OUTPUT);
 Serial.begin (9600);
}
void loop()
{
  char entrada = Serial.read();

    if (entrada=='w' || entrada=='s' || entrada =='f' || entrada == 'o' || entrada == 'i' || entrada == 'r' || entrada == 'p'){Serial.println(entrada);}

      if(entrada == 'p')
      {
        
    digitalWrite(Ptrig, LOW);
    delayMicroseconds(2);
    digitalWrite(Ptrig, HIGH);   // genera el pulso de triger por 10ms
    delayMicroseconds(10);
    digitalWrite(Ptrig, LOW);

    duracion = pulseIn(Pecho, HIGH);
    distancia = (duracion / 2) / 29;          // calcula la distancia en centimetros

    if (distancia >= 500 || distancia <= 0) { // si la distancia es mayor a 500cm o menor a 0cm
      Serial.println("---");                  // no mide nada
    }
     else {
      // for (int i=0; i <= 255; i++){
      Serial.print("Distancia:");
      Serial.print(distancia);           // envia el valor de la distancia por el puerto serial
      Serial.println(" ");              // le coloca a la distancia los centimetros "cm"
      digitalWrite(13, 0);               // en bajo el pin 13
      digitalWrite(8, 0);                // el pin 8 en bajo
    }


      if (distancia <= 1 && distancia >= 1) {
      digitalWrite(13, 1);     // en alto el pin 13 si la distancia es menor a 10cm
      digitalWrite(8, 1);
      Serial.println("Alarma.......");         // envia la palabra Alarma por el puerto serial
    }
      delay(150);  
      }
      if(entrada == 'r')
      {
      analogWrite(ENA, 200);
      digitalWrite(IN1, 0);
      digitalWrite(IN2, 1);

      analogWrite(ENB, 200);
      digitalWrite(IN3, 1);
      digitalWrite(IN4, 0);

      delay(800);
      digitalWrite(IN2, 0);
      digitalWrite(IN1, 0);
      digitalWrite(IN4, 0);
      digitalWrite(IN3, 0);
      
      }
//==================== ADELANTE
      if(entrada == 'w')
      {
      analogWrite(ENA, 200);
      digitalWrite(IN1, 0);
      digitalWrite(IN2, 1);

      analogWrite(ENB, 200);
      digitalWrite(IN3, 1);
      digitalWrite(IN4, 0);

      delay(50);
      digitalWrite(IN2, 0);
      digitalWrite(IN1, 0);
      digitalWrite(IN4, 0);
      digitalWrite(IN3, 0);
      
      }

//===================== ATRAS
      if(entrada == 's')
      {
      analogWrite(ENA, 200);
      digitalWrite(IN1, 1);
      digitalWrite(IN2, 0);

      analogWrite(ENB, 200);
      digitalWrite(IN3, 0);
      digitalWrite(IN4, 1);

      delay(50);
      digitalWrite(IN2, 0);
      digitalWrite(IN1, 0);
      digitalWrite(IN4, 0);
      digitalWrite(IN3, 0);
      }

// ====================== IZQUIERDA

      if(entrada == 'a')
      {
      analogWrite(ENA, 200);
      digitalWrite(IN1, 1);
      digitalWrite(IN2, 0);

      analogWrite(ENB, 200);
      digitalWrite(IN3, 1);
      digitalWrite(IN4, 0);

      delay(50);;
      digitalWrite(IN2, 0);
      digitalWrite(IN1, 0);
      digitalWrite(IN4, 0);
      digitalWrite(IN3, 0);
      }

// =================== DERECHA

      if(entrada == 'd')
      {
      analogWrite(ENA, 200);
      digitalWrite(IN1, 0);
      digitalWrite(IN2, 1);

      analogWrite(ENB, 200);
      digitalWrite(IN3, 0);
      digitalWrite(IN4, 1);

      delay(50);
      digitalWrite(IN2, 0);
      digitalWrite(IN1, 0);
      digitalWrite(IN4, 0);
      digitalWrite(IN3, 0);
      }

// ================= APAGAR

      if(entrada == 'f')
      {
        analogWrite(ENB,0);
        analogWrite(ENA, 0);
      }

// =================== LED ON

      if(entrada == 'i')
      {
        digitalWrite(INTD, HIGH);
      }

      if(entrada == 'o')
      {
        digitalWrite(INTD, LOW);
      }



}
