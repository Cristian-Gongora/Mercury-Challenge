int t = 500;

#define Pecho 11
#define Ptrig 12

long duracion;
int distancia; 

int U;

//Motor derecho
int IN1 = 4;    //Input3 conectada al pin 4
int IN2 = 5;    //Input4 conectada al pin 3
int ENA = 3;    // ENB conectada al pin 2 de arduino

int IN3 = 6;
int IN4 = 7;
int ENB = 9;
int IN13 = 13;
int INTD = 2;
String inString = "";    // string to hold input
long PWM;
int k;
int Dista,Dista_1;
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

 pinMode(Pecho, INPUT);     // define el pin 6 como entrada (echo)
 pinMode(Ptrig, OUTPUT);    // define el pin 7 como salida  (triger)
 pinMode(13, 1);            // Define el pin 13 como salida
 pinMode(8, 1);
 Serial.begin (9600);
 Serial.setTimeout(1);
}
void loop()
{
//  char  entrada ="Y";
//  //if (Serial.available()) {
// String inChar = Serial.readString();
//  if (inChar>"0"){
// 
////    if (isDigit(inChar)) {
//      // convert the incoming byte to a char and add it to the string:
//      inString = (String)inChar;
//  //  }
//    // if you get a newline, print the string, then the string's value:
//    //inString = (String)inChar;
//   PWM= inString.toInt()  -255;
////Serial.println(PWM);           // envia el valor de la distancia por el puerto serial
// //} 


// ============================= SENSOR DISTANCIA

  digitalWrite(Ptrig, LOW);
  delayMicroseconds(2);
  digitalWrite(Ptrig, HIGH);   // genera el pulso de triger por 10ms
  delayMicroseconds(10);
  digitalWrite(Ptrig, LOW);

  
  duracion = pulseIn(Pecho, HIGH);
  distancia = (duracion/2) / 29;            // calcula la distancia en centimetros
  
    Serial.print("\nDistancia:");
    Serial.println(distancia);           // envia el valor de la distancia por el puerto serial
delay(50);


// ============================= MOTORES

U = Serial.parseInt();

if (U > 0 )
{
digitalWrite(13,HIGH);  
    analogWrite(ENA, U);
      digitalWrite(IN1, 0);
      digitalWrite(IN2, 1);

      analogWrite(ENB, U);
      digitalWrite(IN3, 1);
      digitalWrite(IN4, 0);
    
  
}
if(U - 255 < 0){
digitalWrite(13,LOW);
      analogWrite(ENA, U);
      digitalWrite(IN1, 1);
      digitalWrite(IN2, 0);

      analogWrite(ENB, U);
      digitalWrite(IN4, 1);
      digitalWrite(IN3, 0);

}

}
