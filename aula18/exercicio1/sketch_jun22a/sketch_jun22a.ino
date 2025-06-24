#define led 8 //define os apelidos dos pinos
#define botao 2 //define os apelidos dos pinos
int conta=0;//contador para saber quantas vezes clicaram no botão

bool estado_anterior = HIGH;//como é um pullup o estado anterior do clique vai ser 1(HIGH)

bool piscar= false;//ira alternar de true para false

bool estadoled = LOW;//essa parte que ira inverter o estado do led, fazendo ele pipscar

unsigned long tempo_anterior = 0;//inicialme o tempo anterior começa em zero

unsigned long intervalo = 500;//possui um intervalo de 500 milissegundo

void setup() {
  //configuração dos pinos(sendo OUTPUT para saída e INPUT_PULLUP para entrada)
  pinMode(led, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
  digitalWrite(led , LOW);

}

void loop() {
  bool atual = digitalRead(botao);//verifica os estado do botão

  if (atual == LOW && estado_anterior == HIGH){//essa parte identifica o clique no botão
    piscar = !piscar;//ira alternar (true e false)
    conta ++;//soma mais um, a cada clique no botão
  }

  estado_anterior=atual;//para não repetir op código

  if(piscar){
    unsigned long tempo_atual = millis();//quantos milissegundos tem após ligar o arduino

    if (tempo_atual - tempo_anterior >= intervalo){//a cada 500 millisegundo ira trocar o estado do botão
      tempo_anterior = tempo_atual;//chegando em 500 milissegundo o estado anterior ira assumir o 500 milissegundo e ira somar mais 500 trocando o estado do led
      estadoled= !estadoled;//troca os estado do botão
      digitalWrite(led, estadoled);//a cada troca de estado ira ligar ou desligar o led
    }
  }

  if (conta >= 2){//se a conta chegar a 2
  digitalWrite(led , LOW);//o led desligara
  }
}
