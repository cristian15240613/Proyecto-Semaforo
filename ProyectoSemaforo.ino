int c_r = 13;
int c_a = 12;
int c_v = 11;

int p_v = 10;
int p_r = 9;

int potenciometro = A0;
int valPot = 0;

void setup() {
  pinMode(c_r, OUTPUT);
  pinMode(c_a, OUTPUT);
  pinMode(c_v, OUTPUT);

  pinMode(p_v, OUTPUT);
  pinMode(p_r, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  valPot = analogRead(potenciometro);
  int valVerde = valPot * 40;
  int segundos = valVerde / 1000;
  /*  Valor de potenciometro
  Serial.println(valPot);
  delay(1000);
  */
  Serial.print("El semaforo en verde durará: ");
  Serial.print(segundos);
  Serial.print(" segundos más dos parpadeos");
  Serial.println(" ");

  // Encender led rojo de peaton y apagar led verde de peaton
  digitalWrite(p_v, LOW);
  digitalWrite(p_r, HIGH);
  
  digitalWrite(c_v, HIGH);
  delay(valVerde);

  for(int i=0; i < 3; i++){
    digitalWrite(c_v, HIGH);
    delay(500);
    digitalWrite(c_v, LOW);
    delay(500);  
    
  }
  
  digitalWrite(c_a, HIGH);
  delay(2200);
  digitalWrite(c_a, LOW);
  delay(500);

  // Encender led verde de peaton y apagar led rojo de peaton
  digitalWrite(p_r, LOW);
  digitalWrite(p_v, HIGH);
  
  digitalWrite(c_r, HIGH);
  delay(4500);

  for(int i=0; i < 3; i++){
    digitalWrite(c_r, HIGH);
    digitalWrite(p_v, HIGH);
        
    delay(500);

    digitalWrite(p_v, LOW);
    digitalWrite(c_r, LOW);
    delay(500);
  }
}
