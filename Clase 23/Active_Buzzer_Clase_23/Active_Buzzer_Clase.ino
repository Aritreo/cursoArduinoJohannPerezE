// los buzzers pueden ser de dos tipos el activo y el pasivo. 
// El activo viene con un sticker, el activo viene tapado y el pasivo destapado.
// El zumbador viene con un sonido predeterminado (con un cicuito interno)
// no le podemos sacar un tono especifico
// es un poco mas costoso que el zumbador pasivo. 
// con solo pasar 5v ya funciona y empieza a sonar

//int buzzPin = 8;
//int number;
//String msg1 = "Por favor introduce tu número";
//int dt = 500;
//void setup() {
//  // put your setup code here, to run once:
//  Serial.begin(9600);
//  pinMode(buzzPin, OUTPUT);
//}
//
//void loop() {
//  // put your main code here, to run repeatedly:
//  Serial.println();
//  Serial.println(msg1);
//  while (Serial.available() == 0) {
//
//  }
//  number = Serial.parseInt();
//
//  if (number > 10){
//    digitalWrite(buzzPin, HIGH);
//    delay(dt);
//    digitalWrite(buzzPin, LOW);
//  }
//
//}

int buzzPin = 8;
int potVal;
int potPin = A5;

void setup() { #
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzPin, OUTPUT);
  pinMode(potPin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:

  potVal = analogRead(potPin);
  Serial.println(potVal);

  while (potVal>1000){
    digitalWrite(buzzPin, HIGH);
    potVal = analogRead(potPin); // dentro del ciclo while tenemos que volver a leer
    // cuanto vale el potVal sino siempre va a estar valiendo 
    // lo mismo y no cambiaria.
    Serial.println(potVal); // Hasta que no salga del ciclo no vaa escribir nada por eso
    // se escribe el serial.print, asi no se queda congelado cuando entramos en el ciclo 
  }
  digitalWrite(buzzPin, LOW);

}
