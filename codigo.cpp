const int led_vermelho = 17;
const int led_amarelo = 4;
const int led_verde = 2;
const int botao = 14;

unsigned long tempoAnterior = 0; // Armazena o tempo anterior
int estadoSequencia = 0; // Controla a sequência de LEDs
bool sequenciaAtiva = true; // Controla se a sequência de LEDs está ativa

void setup() {
  pinMode(led_vermelho, OUTPUT); 
  pinMode(led_amarelo, OUTPUT);
  pinMode(led_verde, OUTPUT);
  pinMode(botao, INPUT_PULLUP);
}

void loop() {
  // Verifica o estado do botão
  int estadoBotao = digitalRead(botao);

  // Se o botão for pressionado, altera o estado da sequência
  if (estadoBotao == LOW) { 
    sequenciaAtiva = !sequenciaAtiva; // Alterna entre ativar e desativar a sequência

    // Aguarda o botão ser solto para evitar múltiplas ativações
    while (digitalRead(botao) == LOW) {
      delay(10); 
    }
  }

  // Se a sequência estiver ativa, executa a lógica dos LEDs
  if (sequenciaAtiva) {
    unsigned long tempoAtual = millis();

    // LED vermelho - permanece aceso por 6 segundos
    if (estadoSequencia == 0 && tempoAtual - tempoAnterior >= 6000) {
      digitalWrite(led_vermelho, LOW);  
      digitalWrite(led_amarelo, HIGH);  
      tempoAnterior = tempoAtual;
      estadoSequencia = 1;
    }
    // LED amarelo - permanece aceso por 2 segundos
    else if (estadoSequencia == 1 && tempoAtual - tempoAnterior >= 2000) {
      digitalWrite(led_amarelo, LOW);   
      digitalWrite(led_verde, HIGH);    
      tempoAnterior = tempoAtual;
      estadoSequencia = 2;
    }
    // LED verde - permanece aceso por 2 segundos (primeira vez)
    else if (estadoSequencia == 2 && tempoAtual - tempoAnterior >= 2000) {
      digitalWrite(led_verde, LOW);     
      digitalWrite(led_verde, HIGH);    // LED verde acende novamente
      tempoAnterior = tempoAtual;
      estadoSequencia = 3;
    }
    // LED verde - permanece aceso por mais 2 segundos (para tempo extra de travessia)
    else if (estadoSequencia == 3 && tempoAtual - tempoAnterior >= 2000) {
      digitalWrite(led_verde, LOW);     
      digitalWrite(led_amarelo, HIGH);  // Transição para o amarelo novamente
      tempoAnterior = tempoAtual;
      estadoSequencia = 4;
    }
    // LED amarelo - permanece aceso por 2 segundos (segundo amarelo)
    else if (estadoSequencia == 4 && tempoAtual - tempoAnterior >= 2000) {
      digitalWrite(led_amarelo, LOW);   
      digitalWrite(led_vermelho, HIGH); // Volta para o LED vermelho
      tempoAnterior = tempoAtual;
      estadoSequencia = 0;              // Reinicia a sequência
    }
  } else {
    // Se a sequência está inativa, apaga todos os LEDs
    digitalWrite(led_vermelho, LOW);
    digitalWrite(led_amarelo, LOW);
    digitalWrite(led_verde, LOW);
  }
}
