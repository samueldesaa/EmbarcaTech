#include <FastLED.h>

// Defina o número de LEDs
#define NUM_LEDS 25  // Alterar para o número de LEDs que você está utilizando

// Defina o pino onde os LEDs estão conectados
#define LED_PIN 7

// Defina o tipo de LEDs
#define LED_TYPE WS2812B  // Alterar para o tipo de LED que você está utilizando

// Defina o modelo de cor dos LEDs
#define COLOR_ORDER GRB

// Criação do objeto FastLED
CRGB leds[NUM_LEDS];

void setup() {
  // Inicializa o controle dos LEDs
  FastLED.addLeds<LED_TYPE, LED_PIN, COLOR_ORDER>(leds, NUM_LEDS);
  FastLED.setBrightness(100);  // Ajuste o brilho (0-255)
  pinMode(26, INPUT);
  pinMode(27, INPUT);
  pinMode(22, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  // Exemplo de animação simples - Alternando as cores do LED
  int x = analogRead(26);
  int y = analogRead(27);
  int botao = analogRead(22);
  Serial.print(x);
  Serial.print(",");
  Serial.print(y);
  Serial.print(",");
  Serial.println(botao);
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Red;  // Definir LED como vermelho
    FastLED.show();  // Atualiza os LEDs
    delay(100);  // Espera 100 ms
    leds[i] = CRGB::Black;  // Apaga o LED
  }
  
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Green;  // Definir LED como verde
    FastLED.show();  // Atualiza os LEDs
    delay(100);  // Espera 100 ms
    leds[i] = CRGB::Black;  // Apaga o LED
  }
  
  for (int i = 0; i < NUM_LEDS; i++) {
    leds[i] = CRGB::Blue;  // Definir LED como azul
    FastLED.show();  // Atualiza os LEDs
    delay(100);  // Espera 100 ms
    leds[i] = CRGB::Black;  // Apaga o LED
  }
}
