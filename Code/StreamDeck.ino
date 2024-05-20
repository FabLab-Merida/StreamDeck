#include <Adafruit_NeoPixel.h> // https://github.com/adafruit/Adafruit_NeoPixel (1.12.0)
#include "Keypad.h" // https://github.com/Nullkraft/Keypad (3.2.1)
#include <Keyboard.h> // https://github.com/arduino-libraries/Keyboard (1.0.6)
#include "Encoder.h" // https://github.com/PaulStoffregen/Encoder (1.4.4)
#include "Button.h" // https://github.com/madleech/Button (Initial Release)
#include "id_teclas.h" // Dependiente del proyecto

// Distribucion de las entradas digitales; usamos "byte" en vez de "int" por dependecia de la libreria.
#define filas_keypad 3
#define columnas_keypad 3
byte pines_fila[filas_keypad] = { 5,6,7 };
byte pines_columna[columnas_keypad] = { 8,9,10 };
byte pin_neopixel = 16;
byte pinA_encoder = 2;
byte pinB_encoder = 3;
byte pinBoton_encoder = 4;

//Variables internas del programa.

int estado_encoder_0 = 0;
int capa_teclado = 0;

char pulsadores_capa1[filas_keypad][columnas_keypad] = {
    {'a', 'b', 'c'},
    {'d', 'e', 'f'},
    {'g', 'h', 'i'} };

// Creacion de los objetos
Keypad botones = Keypad(makeKeymap(pulsadores_capa1), pines_fila, pines_columna, filas_keypad, columnas_keypad);
Adafruit_NeoPixel neopi(1, pin_neopixel, NEO_GRBW + NEO_KHZ800);
Encoder codificador(pinA_encoder, pinB_encoder);
Button boton_encoder(pinBoton_encoder);

void test_botones();
void eventos_botones(KeypadEvent boton_pulsado);
void seleccion_capa();

void setup() {
  Serial.begin(9600);
  Keyboard.begin();
  botones.addEventListener(eventos_botones);
  boton_encoder.begin();

  neopi.begin();
  neopi.setPixelColor(0, 255, 0, 0);
  neopi.show();
  }

void loop() {
  if (boton_encoder.pressed()) {
    seleccion_capa();
    }
  char boton_pulsado = botones.getKey();
  if (boton_pulsado) {
    Serial.println(boton_pulsado);

    }
  //Serial.print(boton_encoder.read());

  }

void  test_botones() { // Funcion para probar el estado de los botones del keypad 
  char test_tecla = botones.getKey();
  if (test_tecla) {
    Serial.println(test_tecla);
    }
  }

void seleccion_capa() {
  int estado_encoder_1 = estado_encoder_0;
  bool capa_elegida = false;

  while (capa_elegida == false) {
    estado_encoder_1 = codificador.read();

    if (estado_encoder_1 > estado_encoder_0 && capa_teclado < 2) {
      capa_teclado++;
      }
    else if (estado_encoder_1 < estado_encoder_0 && capa_teclado > 0) {
      capa_teclado--;
      }

    estado_encoder_0 = estado_encoder_1;
    /*Serial.print("la capa es ");
    Serial.print(capa_teclado);*/
    delay(250);

    if (capa_teclado == 0) {
      neopi.setPixelColor(0, 255, 0, 0);
      }
    else if (capa_teclado == 1) {
      neopi.setPixelColor(0, 0, 255, 0);
      }
    else if (capa_teclado == 2) {
      neopi.setPixelColor(0, 0, 0, 255);
      }
    neopi.show();

    if (boton_encoder.pressed()) {
      capa_elegida = true;
      }

    }
  }

void eventos_botones(KeypadEvent boton_pulsado) {
  //CAPA ROJA 
  if (boton_pulsado == 'a' && botones.getState() == PRESSED && capa_teclado == 0) {
    Keyboard.press(TECLA_CTRL_IZQUIERDO);
    Keyboard.press(TECLA_ALT_DERECHO);
    Keyboard.press(TECLA_SHIFT_DERECHO);
    Keyboard.press(TECLA_F1);
    Keyboard.releaseAll();
    }
  if (boton_pulsado == 'b' && botones.getState() == PRESSED && capa_teclado == 0) {
    Keyboard.press(TECLA_CTRL_IZQUIERDO);
    Keyboard.press(TECLA_ALT_DERECHO);
    Keyboard.press(TECLA_SHIFT_DERECHO);
    Keyboard.press(TECLA_F2);
    Keyboard.releaseAll();
    }
  if (boton_pulsado == 'c' && botones.getState() == PRESSED && capa_teclado == 0) {
    Keyboard.press(TECLA_CTRL_IZQUIERDO);
    Keyboard.press(TECLA_ALT_DERECHO);
    Keyboard.press(TECLA_SHIFT_DERECHO);
    Keyboard.press(TECLA_F3);
    Keyboard.releaseAll();
    }
  if (boton_pulsado == 'd' && botones.getState() == PRESSED && capa_teclado == 0) {
    Keyboard.press(TECLA_CTRL_IZQUIERDO);
    Keyboard.press(TECLA_ALT_DERECHO);
    Keyboard.press(TECLA_SHIFT_DERECHO);
    Keyboard.press(TECLA_F4);
    Keyboard.releaseAll();
    }
  if (boton_pulsado == 'e' && botones.getState() == PRESSED && capa_teclado == 0) {
    Keyboard.press(TECLA_CTRL_IZQUIERDO);
    Keyboard.press(TECLA_ALT_DERECHO);
    Keyboard.press(TECLA_SHIFT_DERECHO);
    Keyboard.press(TECLA_F5);
    Keyboard.releaseAll();
    }
  if (boton_pulsado == 'f' && botones.getState() == PRESSED && capa_teclado == 0) {
    Keyboard.press(TECLA_CTRL_IZQUIERDO);
    Keyboard.press(TECLA_ALT_DERECHO);
    Keyboard.press(TECLA_SHIFT_DERECHO);
    Keyboard.press(TECLA_F6);
    Keyboard.releaseAll();
    }
  if (boton_pulsado == 'g' && botones.getState() == PRESSED && capa_teclado == 0) {
    Keyboard.press(TECLA_CTRL_IZQUIERDO);
    Keyboard.press(TECLA_ALT_DERECHO);
    Keyboard.press(TECLA_SHIFT_DERECHO);
    Keyboard.press(TECLA_F7);
    Keyboard.releaseAll();
    }
  if (boton_pulsado == 'h' && botones.getState() == PRESSED && capa_teclado == 0) {
    Keyboard.press(TECLA_CTRL_IZQUIERDO);
    Keyboard.press(TECLA_ALT_DERECHO);
    Keyboard.press(TECLA_SHIFT_DERECHO);
    Keyboard.press(TECLA_F8);
    Keyboard.releaseAll();
    }
  if (boton_pulsado == 'i' && botones.getState() == PRESSED && capa_teclado == 0) {
    Keyboard.press(TECLA_CTRL_IZQUIERDO);
    Keyboard.press(TECLA_ALT_DERECHO);
    Keyboard.press(TECLA_SHIFT_DERECHO);
    Keyboard.press(TECLA_F9);
    Keyboard.releaseAll();
    }

  // CAPA VERDE

  if (boton_pulsado == 'a' && botones.getState() == PRESSED && capa_teclado == 1) {
    Keyboard.press(TECLA_CTRL_IZQUIERDO);
    Keyboard.press(TECLA_ALT_DERECHO);
    Keyboard.press(TECLA_SHIFT_DERECHO);
    Keyboard.press('A');
    Keyboard.releaseAll();
    }
  if (boton_pulsado == 'b' && botones.getState() == PRESSED && capa_teclado == 1) {
    Keyboard.press(TECLA_CTRL_IZQUIERDO);
    Keyboard.press(TECLA_ALT_DERECHO);
    Keyboard.press(TECLA_SHIFT_DERECHO);
    Keyboard.press('S');
    Keyboard.releaseAll();
    }
  if (boton_pulsado == 'c' && botones.getState() == PRESSED && capa_teclado == 1) {
    Keyboard.press(TECLA_CTRL_IZQUIERDO);
    Keyboard.press(TECLA_ALT_DERECHO);
    Keyboard.press(TECLA_SHIFT_DERECHO);
    Keyboard.press('D');
    Keyboard.releaseAll();
    }
  if (boton_pulsado == 'd' && botones.getState() == PRESSED && capa_teclado == 1) {
    Keyboard.press(TECLA_CTRL_IZQUIERDO);
    Keyboard.press(TECLA_ALT_DERECHO);
    Keyboard.press(TECLA_SHIFT_DERECHO);
    Keyboard.press('F');
    Keyboard.releaseAll();
    }
  if (boton_pulsado == 'e' && botones.getState() == PRESSED && capa_teclado == 1) {
    Keyboard.press(TECLA_CTRL_IZQUIERDO);
    Keyboard.press(TECLA_ALT_DERECHO);
    Keyboard.press(TECLA_SHIFT_DERECHO);
    Keyboard.press('G');
    Keyboard.releaseAll();
    }
  if (boton_pulsado == 'f' && botones.getState() == PRESSED && capa_teclado == 1) {
    Keyboard.press(TECLA_CTRL_IZQUIERDO);
    Keyboard.press(TECLA_ALT_DERECHO);
    Keyboard.press(TECLA_SHIFT_DERECHO);
    Keyboard.press('H');
    Keyboard.releaseAll();
    }
  if (boton_pulsado == 'g' && botones.getState() == PRESSED && capa_teclado == 1) {
    Keyboard.press(TECLA_CTRL_IZQUIERDO);
    Keyboard.press(TECLA_ALT_DERECHO);
    Keyboard.press(TECLA_SHIFT_DERECHO);
    Keyboard.press('J');
    Keyboard.releaseAll();
    }
  if (boton_pulsado == 'h' && botones.getState() == PRESSED && capa_teclado == 1) {
    Keyboard.press(TECLA_CTRL_IZQUIERDO);
    Keyboard.press(TECLA_ALT_DERECHO);
    Keyboard.press(TECLA_SHIFT_DERECHO);
    Keyboard.press('K');
    Keyboard.releaseAll();
    }
  if (boton_pulsado == 'i' && botones.getState() == PRESSED && capa_teclado == 1) {
    Keyboard.press(TECLA_CTRL_IZQUIERDO);
    Keyboard.press(TECLA_ALT_DERECHO);
    Keyboard.press(TECLA_SHIFT_DERECHO);
    Keyboard.press('L');
    Keyboard.releaseAll();
    }

  // CAPA AZUL

  if (boton_pulsado == 'a' && botones.getState() == PRESSED && capa_teclado == 2) {
    Keyboard.press(TECLA_CTRL_IZQUIERDO);
    Keyboard.press(TECLA_ALT_DERECHO);
    Keyboard.press(TECLA_SHIFT_DERECHO);
    Keyboard.press('Z');
    Keyboard.releaseAll();
    }
  if (boton_pulsado == 'b' && botones.getState() == PRESSED && capa_teclado == 2) {
    Keyboard.press(TECLA_CTRL_IZQUIERDO);
    Keyboard.press(TECLA_ALT_DERECHO);
    Keyboard.press(TECLA_SHIFT_DERECHO);
    Keyboard.press('X');
    Keyboard.releaseAll();
    }
  if (boton_pulsado == 'c' && botones.getState() == PRESSED && capa_teclado == 2) {
    Keyboard.press(TECLA_CTRL_IZQUIERDO);
    Keyboard.press(TECLA_ALT_DERECHO);
    Keyboard.press(TECLA_SHIFT_DERECHO);
    Keyboard.press('C');
    Keyboard.releaseAll();
    }
  if (boton_pulsado == 'd' && botones.getState() == PRESSED && capa_teclado == 2) {
    Keyboard.press(TECLA_CTRL_IZQUIERDO);
    Keyboard.press(TECLA_ALT_DERECHO);
    Keyboard.press(TECLA_SHIFT_DERECHO);
    Keyboard.press('V');
    Keyboard.releaseAll();
    }
  if (boton_pulsado == 'e' && botones.getState() == PRESSED && capa_teclado == 2) {
    Keyboard.press(TECLA_CTRL_IZQUIERDO);
    Keyboard.press(TECLA_ALT_DERECHO);
    Keyboard.press(TECLA_SHIFT_DERECHO);
    Keyboard.press('B');
    Keyboard.releaseAll();
    }
  if (boton_pulsado == 'f' && botones.getState() == PRESSED && capa_teclado == 2) {
    Keyboard.press(TECLA_CTRL_IZQUIERDO);
    Keyboard.press(TECLA_ALT_DERECHO);
    Keyboard.press(TECLA_SHIFT_DERECHO);
    Keyboard.press('N');
    Keyboard.releaseAll();
    }
  if (boton_pulsado == 'g' && botones.getState() == PRESSED && capa_teclado == 2) {
    Keyboard.press(TECLA_CTRL_IZQUIERDO);
    Keyboard.press(TECLA_ALT_DERECHO);
    Keyboard.press(TECLA_SHIFT_DERECHO);
    Keyboard.press('M');
    Keyboard.releaseAll();
    }
  if (boton_pulsado == 'h' && botones.getState() == PRESSED && capa_teclado == 2) {
    Keyboard.press(TECLA_CTRL_IZQUIERDO);
    Keyboard.press(TECLA_ALT_DERECHO);
    Keyboard.press(TECLA_SHIFT_DERECHO);
    Keyboard.press('P');
    Keyboard.releaseAll();
    }
  if (boton_pulsado == 'i' && botones.getState() == PRESSED && capa_teclado == 2) {
    Keyboard.press(TECLA_CTRL_IZQUIERDO);
    Keyboard.press(TECLA_ALT_DERECHO);
    Keyboard.press(TECLA_SHIFT_DERECHO);
    Keyboard.press('-');
    Keyboard.releaseAll();
    }
  }
