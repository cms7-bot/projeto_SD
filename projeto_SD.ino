#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,20,4);

// =======================
// BOTÕES
// =======================

const int botao1 = 2;
const int botao2 = 3;
const int botaoReset = 4;

// =======================
// LEDS
// =======================

const int ledInicio = 7;
const int led1 = 8;
const int led2 = 9;

// =======================
// CONTROLE
// =======================

bool jogoLiberado = false;
bool vencedor = false;
bool aguardandoInicio = false;
bool queimada_jogador1 = false;
bool queimada_jogador2 = false;

// =======================
// PLACAR
// =======================

int pontos1 = 0;
int pontos2 = 0;

// =======================
// TEMPO
// =======================

unsigned long tempoInicio;
unsigned long tempoAleatorio;

// =======================
// SETUP
// =======================

void setup() {

  Serial.begin(9600);

  pinMode(botao1, INPUT_PULLUP);
  pinMode(botao2, INPUT_PULLUP);
  pinMode(botaoReset, INPUT_PULLUP);

  pinMode(ledInicio, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.print("JOGO DO PASSA OU REPASSA");

  delay(3000);

  lcd.clear();

  lcd.print("PREPARAR!");

  randomSeed(analogRead(A0));

  iniciarRodada();
}

// =======================
// LOOP
// =======================

void loop() {
  // =======================
  // RESET
  // =======================

  if (digitalRead(botaoReset) == LOW) {

    lcd.clear();
    
    Serial.println("");
    Serial.println("====================");
    Serial.println("Nova rodada");
    Serial.println("AGUARDE...");
    Serial.println("====================");

    lcd.print("Reiniciando rodada");
   

    delay(300);

    iniciarRodada();
  }

  // =======================
  // TEMPO ALEATÓRIO
  // =======================

  if (aguardandoInicio) {

    // QUEIMADA ANTES DO LED
    verificarQueimada();

    // VERIFICA SE O TEMPO PASSOU
    if (millis() - tempoInicio >= tempoAleatorio) {

      digitalWrite(ledInicio, HIGH);

      jogoLiberado = true;

      aguardandoInicio = false;

    

      lcd.clear();

      Serial.println("\nVALENDO!");
      lcd.print("VALENDO!");
    }
  }

  // =======================
  // JOGO LIBERADO
  // =======================

  if (jogoLiberado && !vencedor) {

    // Jogador 1 venceu
    if (digitalRead(botao1) == LOW) {

      digitalWrite(led1, HIGH);

      pontos1++;

      vencedor = true;

      jogoLiberado = false;

      lcd.clear();

      Serial.println("Jogador 1 venceu!");
      lcd.print("Jogador 1 venceu");

      mostrarPlacar();
    }

    // Jogador 2 venceu
    if (digitalRead(botao2) == LOW) {

      digitalWrite(led2, HIGH);

      pontos2++;

      vencedor = true;

      jogoLiberado = false;

      lcd.clear();

      Serial.println("Jogador 2 venceu!");
      lcd.print("Jogador 2 venceu");

      mostrarPlacar();
    }
  }
}

// =======================
// NOVA RODADA
// =======================

void iniciarRodada() {

  digitalWrite(ledInicio, LOW);
  digitalWrite(led1, LOW);
  digitalWrite(led2, LOW);

  vencedor = false;
  jogoLiberado = false;

  aguardandoInicio = true;

  tempoAleatorio = random(2000, 6000);

  tempoInicio = millis();

}

// =======================
// VERIFICAR QUEIMADA
// =======================

void verificarQueimada() {

  // Jogador 1 queimou
  if (digitalRead(botao1) == LOW && !vencedor) {

    digitalWrite(led2, HIGH);

    pontos2++;

    vencedor = true;

    aguardandoInicio = false;

    lcd.clear();

    Serial.println("Jogador 1 QUEIMOU!");
    lcd.print("Jogador 1 QUEIMOU!");
    
    mostrarPlacar();

    Serial.println("Soltar o botão");

    while (digitalRead(botao1) == LOW) {}
  }

  // Jogador 2 queimou
  if (digitalRead(botao2) == LOW && !vencedor) {

    digitalWrite(led1, HIGH);

    pontos1++;

    vencedor = true;

    aguardandoInicio = false;

    lcd.clear();

    Serial.println("Jogador 2 QUEIMOU!");
    lcd.print("Jogador 2 QUEIMOU!");

    mostrarPlacar();

    Serial.println("Soltar o botão");

    while (digitalRead(botao2) == LOW) {}
  }
}

// =======================
// PLACAR
// =======================

void mostrarPlacar() {

  Serial.println("");
  Serial.println("===== PLACAR =====");

  Serial.print("Jogador 1: ");
  Serial.println(pontos1);

  Serial.print("Jogador 2: ");
  Serial.println(pontos2);

  Serial.println("==================");
}
