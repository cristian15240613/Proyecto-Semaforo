int c_r = 13;
int c_a = 12;
int c_v = 11;

int p_v = 10;
int p_r = 9;

void setup() {
  pinMode(c_r, OUTPUT);
  pinMode(c_a, OUTPUT);
  pinMode(c_v, OUTPUT);

  pinMode(p_v, OUTPUT);
  pinMode(p_r, OUTPUT);
}

void loop() {
  digitalWrite(p_v, LOW);
  digitalWrite(p_r, HIGH);
  
  digitalWrite(c_v, HIGH);
  delay(5000);
  digitalWrite(c_v, LOW);
  delay(500);

  for(int i=0; i < 2; i++){
    digitalWrite(c_v, HIGH);
    delay(500);
    digitalWrite(c_v, LOW);
    delay(500);  
    
  }
  
  digitalWrite(c_a, HIGH);
  delay(2200);
  digitalWrite(c_a, LOW);
  delay(500);

  digitalWrite(p_r, LOW);
  digitalWrite(p_v, HIGH);
  
  digitalWrite(c_r, HIGH);
  delay(4500);
  digitalWrite(c_r, LOW);
  delay(500);

  for(int i=0; i < 2; i++){
    digitalWrite(c_r, HIGH);
    delay(500);
    digitalWrite(c_r, LOW);
    delay(500);  
    
  }

}
