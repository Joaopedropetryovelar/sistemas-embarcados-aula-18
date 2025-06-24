//aqui definimos as entradas dos pinos
#define pin_led1 8
#define pin_led2 9
#define pin_botao1 2
#define pin_botao2 3

int cont = 0;
int tic1 = 0;
int tic2 = 0;

void setup() {
  pinMode(pin_led1, OUTPUT);
  pinMode(pin_led2, OUTPUT);
  pinMode(pin_botao1, INPUT);
  pinMode(pin_botao2, INPUT);
  Serial.begin(9600);
}

void loop(){
  bool botaoA = digitalRead(pin_botao1);
  bool botaoB = digitalRead(pin_botao2);

  Serial.println(cont);
 if (botaoA == 1 && tic1 == 0 && cont<1) {
    cont += 1;
    tic1 += 1;
  }
  if (botaoA == 0) {
    tic1 = 0;
  }
    
  if (botaoB == 1 && tic2 == 0 && cont>0) {
    cont -= 1;
    tic2 += 1;
  }
  if (botaoB == 0) {
    tic2 = 0;
  }
if (cont == 1){
  digitalWrite(pin_led1, 1);
  digitalWrite(pin_led2, 0);
}else{
  digitalWrite(pin_led1, 0);
  digitalWrite(pin_led2, 1);
}
}