const int sensorA = 2;
const int sensorB = 3;
const int sensorC = 4;
const int sensorD = 5;

// Saídas
const int valvulaP = 6;
const int bombaM1 = 7;
const int bombaM2 = 8;
const int alarmeAL = 9;

void setup() {
  // Define os pinos dos sensores como entrada
  pinMode(sensorA, INPUT);
  pinMode(sensorB, INPUT);
  pinMode(sensorC, INPUT);
  pinMode(sensorD, INPUT);

  // Define os leds como saída
  pinMode(valvulaP, OUTPUT);
  pinMode(bombaM1, OUTPUT);
  pinMode(bombaM2, OUTPUT);
  pinMode(alarmeAL, OUTPUT);

  // Inicializa todos desligados
  digitalWrite(valvulaP, LOW);
  digitalWrite(bombaM1, LOW);
  digitalWrite(bombaM2, LOW);
  digitalWrite(alarmeAL, LOW);
}

void loop() {
  // verifica os sensores
  bool nivelA = digitalRead(sensorA);
  bool nivelB = digitalRead(sensorB);
  bool nivelC = digitalRead(sensorC);
  bool nivelD = digitalRead(sensorD);

  // Controle da válvula P
  if (nivelA) {
    digitalWrite(valvulaP, LOW);  
  } else if (!nivelB) {
    digitalWrite(valvulaP, HIGH); 
  }

 
  if (!nivelC) {
    digitalWrite(alarmeAL, HIGH);
  } else {
    digitalWrite(alarmeAL, LOW);
  }

 
  if (!nivelD) {
  
    digitalWrite(bombaM1, LOW);
    digitalWrite(bombaM2, LOW);
  } else if (!nivelB) {
    
    digitalWrite(bombaM1, HIGH);
    digitalWrite(bombaM2, LOW);
  } else {
   
    digitalWrite(bombaM1, HIGH);
    digitalWrite(bombaM2, HIGH);
  }

  delay(500); 
}
