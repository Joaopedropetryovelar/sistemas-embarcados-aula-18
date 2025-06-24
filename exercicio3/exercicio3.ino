#define led1  2
#define led2  3
#define led3 4
#define led4 5
#define botao 6 


unsigned long tempoAnterior = 0;
int estadoAtual = 0;
bool sequenciaDireta = true;
bool sequenciaAtiva = false;
bool botaoPressionado = false;

void setup() {
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
  
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);
  digitalWrite(led3, LOW);
  digitalWrite(led4, LOW);
}

void loop() {
  unsigned long tempoAtual = millis();
  

  if (digitalRead(botao) == LOW && !botaoPressionado) {
    botaoPressionado = true;
    sequenciaDireta = !sequenciaDireta;
    sequenciaAtiva = true;
    estadoAtual = 0;
    tempoAnterior = tempoAtual;
    
   
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
  }
  
  if (digitalRead(botao) == HIGH) {
    botaoPressionado = false;
  }

  
  if (sequenciaAtiva) {
    if (sequenciaDireta) {
      if (estadoAtual == 0) {
        digitalWrite(led1, HIGH);
        tempoAnterior = tempoAtual;
        estadoAtual = 1;
      }
      
      if (estadoAtual == 1 && tempoAtual - tempoAnterior >= 125) {
        digitalWrite(led2, HIGH);
        tempoAnterior = tempoAtual;
        estadoAtual = 2;
      }
      
      if (estadoAtual == 2 && tempoAtual - tempoAnterior >= 250) {
        digitalWrite(led3, HIGH);
        tempoAnterior = tempoAtual;
        estadoAtual = 3;
      }
      
      if (estadoAtual == 3 && tempoAtual - tempoAnterior >= 500) {
        digitalWrite(led4, HIGH);
        tempoAnterior = tempoAtual;
        estadoAtual = 4;
      }
      
      if (estadoAtual == 4 && tempoAtual - tempoAnterior >= 500) {
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        sequenciaAtiva = false;
      }
      
    } else {
      if (estadoAtual == 0) {
        digitalWrite(led4, HIGH);
        tempoAnterior = tempoAtual;
        estadoAtual = 1;
      }
      
      if (estadoAtual == 1 && tempoAtual - tempoAnterior >= 125) {
        digitalWrite(led3, HIGH);
        tempoAnterior = tempoAtual;
        estadoAtual = 2;
      }
      
      if (estadoAtual == 2 && tempoAtual - tempoAnterior >= 250) {
        digitalWrite(led2, HIGH);
        tempoAnterior = tempoAtual;
        estadoAtual = 3;
      }
      
      if (estadoAtual == 3 && tempoAtual - tempoAnterior >= 500) {
        digitalWrite(led1, HIGH);
        tempoAnterior = tempoAtual;
        estadoAtual = 4;
      }
      
      if (estadoAtual == 4 && tempoAtual - tempoAnterior >= 500) {
        digitalWrite(led1, LOW);
        digitalWrite(led2, LOW);
        digitalWrite(led3, LOW);
        digitalWrite(led4, LOW);
        sequenciaAtiva = false;
      }
    }
  }
}
