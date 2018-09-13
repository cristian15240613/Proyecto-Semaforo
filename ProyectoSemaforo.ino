int c_r = 13;   // Led de coches rojo
int c_a = 12;   // Led de coches amarillo
int c_v = 11;   // Led de coches verde

int p_v = 10;   // Led de peatones verde
int p_r = 9;    // Led de peatones rojo

int pinEntrada = 8; // Pin de lectura de botón

int potenciometro = A1;   // Lectura de entrada digital potenciometro
int valPot = 0;           // Valor del potenciometro

void setup() {
  pinMode(c_r, OUTPUT);
  pinMode(c_a, OUTPUT);
  pinMode(c_v, OUTPUT);

  pinMode(p_v, OUTPUT);
  pinMode(p_r, OUTPUT);

  pinMode(pinEntrada, INPUT_PULLUP);

  Serial.begin(9600);
}

void loop() {
  
  valPot = analogRead(potenciometro);   // Lectura del potenciometro
  int valVerde = valPot * 40;           // Valor del potenciometro * 40
  int segundos = valVerde / 1000;       // Segundos dependiendo el valor del potenciometro

//-------    Leyenda de los segundos que durará el semaforo de coches en verde    --------
  Serial.print("El semaforo en verde durará: ");  
  Serial.print(segundos);
  Serial.print(" segundos más dos parpadeos");
  Serial.println(" ");
// ---------------------------------------------------------------------------------------

  // Encender led rojo de peaton y apagar led verde de peaton
  digitalWrite(p_v, LOW);
  digitalWrite(p_r, HIGH);
  
  
  digitalWrite(c_v, HIGH);
  delay(valVerde);  // Duracion del led verde dependiendo el valor del potenciometro

// Parpadeos para el termino de tiempo del led verde
  for(int i=0; i < 3; i++){
    digitalWrite(c_v, HIGH);
    delay(500);
    digitalWrite(c_v, LOW);
    delay(500);  
  }

// En caso de que estén pulsando el botón cuando este por acabarse el ciclo del led verde
  if(digitalRead(pinEntrada) == LOW){
    botonPrecionado();
  }else{
    digitalWrite(c_a, HIGH);
    delay(2200);
    digitalWrite(c_a, LOW);
    delay(500);

  // Encender led verde de peaton y apagar led rojo de peaton
  // En caso de que estén pulsando el botón cuando este por acabarse el ciclo del led amarillo
    if(digitalRead(pinEntrada) == LOW){
      botonPrecionado();
    }else{
      digitalWrite(p_r, LOW);
      digitalWrite(p_v, HIGH);
  
      digitalWrite(c_r, HIGH);
      delay(4500);

      parpadeosCRojo();
    }
  }
}

// ------------- Método para hacer los cambios de colores en semaforos cuando el peaton presiona el botón
void botonPrecionado(){
    digitalWrite(p_r, HIGH);
    
    digitalWrite(c_v, LOW);
    digitalWrite(c_r, LOW);
    
  for(int i = 0; i < 8; i++){
    digitalWrite(c_a, HIGH);
    delay(500);
    digitalWrite(c_a, LOW);
    delay(500);
  }
  
  digitalWrite(c_r, HIGH);
  digitalWrite(p_v, HIGH);
  digitalWrite(p_r, LOW);
  delay(12000);
  parpadeosCRojo();
  digitalWrite(c_r, LOW);
  digitalWrite(p_v, HIGH);
}

// Solo parpadeos en el led de coches rojo y el de peatones en verde
void parpadeosCRojo(){
  
  for(int i=0; i < 3; i++){
      digitalWrite(c_r, HIGH);
      digitalWrite(p_v, HIGH);
        
      delay(500);

      digitalWrite(p_v, LOW);
      digitalWrite(c_r, LOW);
      delay(500);
  }
  
}
