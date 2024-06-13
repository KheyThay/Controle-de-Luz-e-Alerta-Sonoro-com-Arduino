// Programa de luminosidade usando o fotoresistor e buzzer

int ledverde = 13;//Pino verde
int ledamarelo = 12;//Pino amarelo
int ledvermelho = 11;//Pino vermelho
int buzzer = 8; // Pino do buzzer
float LDR = A1;
int valorLDR = 0; // Esta é a leitura inicial do fotoresistor(LDR)
bool buzzerAtivado = false; // Variável para controlar se o buzzer está ativado ou não
unsigned long tempoAnterior = 0; // Variável para armazenar o tempo anterior
const int tempoBuzzer = 200; // Aumentando o tempo de duração do som para 200 ms
const int tempoPausa = 100; // Mantendo o tempo de pausa como 100 ms

void setup() {
  Serial.begin(9600);//habilitando o serial para ele receber os valores
  pinMode(ledverde, OUTPUT);//essas são variaveis de saida dos leds
  pinMode(ledamarelo, OUTPUT);
  pinMode(ledvermelho, OUTPUT);
  pinMode(buzzer, OUTPUT); // Define o pino do buzzer como saída
  pinMode(LDR, INPUT);//Ele irá enviar informações
}

void loop() {
  valorLDR = analogRead(LDR);
  Serial.println(valorLDR);
  // Luminosidade baixa
  if (valorLDR < 100) {
    apagaLeds();
    digitalWrite(ledverde, HIGH);
    desligaBuzzer(); // Desliga o buzzer se estiver ativado
  }
  // Luminosidade média
  if (valorLDR >= 100 && valorLDR < 150) {
    apagaLeds();
    digitalWrite(ledamarelo, HIGH);
    desligaBuzzer(); // Desliga o buzzer se estiver ativado
  }
  // Luminosidade alta
  if (valorLDR >= 150) {
    apagaLeds();
    digitalWrite(ledvermelho, HIGH);
    if (!buzzerAtivado) { // Se o buzzer não estiver ativado
      if (millis() - tempoAnterior >= tempoPausa) { // Verifica se passaram 2 segundos desde a última pausa
        ligaBuzzer(); // Liga o buzzer
        tempoAnterior = millis(); // Atualiza o tempo anterior para o momento atual
        buzzerAtivado = true; // Define o buzzer como ativado
      }
    } else { // Se o buzzer estiver ativado
      if (millis() - tempoAnterior >= tempoBuzzer) { // Verifica se passaram 3 segundos desde o último toque do buzzer
        desligaBuzzer(); // Desliga o buzzer
        tempoAnterior = millis(); // Atualiza o tempo anterior para o momento atual
        buzzerAtivado = false; // Define o buzzer como desativado
      }
    }
  }
  Serial.print("Valor LDR: ");
  Serial.println(valorLDR); // Imprime o valor do fotoresistor no monitor serial
  delay(100); // Adiciona um pequeno atraso para estabilizar a leitura
}

void apagaLeds() {
  digitalWrite(ledverde, LOW);
  digitalWrite(ledamarelo, LOW);
  digitalWrite(ledvermelho, LOW);
}

void ligaBuzzer() {
  tone(buzzer, 4000); // Liga o buzzer com uma frequência de 3000 Hz (exemplo)
}


void desligaBuzzer() {
  noTone(buzzer); // Desliga o buzzer
}
