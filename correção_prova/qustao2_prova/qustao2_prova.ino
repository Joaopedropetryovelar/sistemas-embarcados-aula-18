//definimos os pinos
#define pin_led1 8
#define pin_botao1 2

int cont = 0;
int tic1 = 0;
int tic2 = 0;

void setup(){
  pinMode(pin_led1, OUTPUT);
  pinMode(pin_botao1, INPUT);
  Serial.begin(9600);
}

void loop() {
  bool botaoA = digitalRead(pin_botao1);
  
  Serial.println(cont);

 if (botaoA == 1 && tic1 == 0 && cont<100) {
    cont += 1;
    tic1 += 1;
  }
  if (botaoA == 0) {
    tic1 = 0;
  }
if (cont % 2 == 1){
  digitalWrite(pin_led1, 1);
}else{
  digitalWrite(pin_led1, 0);
}
}
