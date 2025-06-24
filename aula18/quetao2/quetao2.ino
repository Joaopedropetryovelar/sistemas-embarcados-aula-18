#define led1 = 2
#define led2 = 3
#define led3 = 4
#define led4 = 5

unsigned long tempoAnterior = 0;
int estado = 0;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
}

void loop() {
  unsigned long tempoAtual = millis();

  switch (estado) {
    case 0: 
      digitalWrite(led1, HIGH);
      if (tempoAtual - tempoAnterior >= 125) {
        digitalWrite(led1, LOW);
        tempoAnterior = tempoAtual;
        estado = 1;
      }
      break;

    case 1: 
      digitalWrite(led2, HIGH);
      if (tempoAtual - tempoAnterior >= 250) {
        digitalWrite(led2, LOW);
        tempoAnterior = tempoAtual;
        estado = 2;
      }
      break;

    case 2: 
      digitalWrite(led3, HIGH);
      if (tempoAtual - tempoAnterior >= 500) {
        digitalWrite(led3, LOW);
        tempoAnterior = tempoAtual;
        estado = 3;
      }
      break;

    case 3: 
      digitalWrite(led4, HIGH);
      if (tempoAtual - tempoAnterior >= 1000) {
        digitalWrite(led4, LOW);
        tempoAnterior = tempoAtual;
        estado = 4;
      }
      break;

    case 4:
      if (tempoAtual - tempoAnterior >= 1000) {
        tempoAnterior = tempoAtual;
        estado = 0; 
      }
      break;
  }
}
