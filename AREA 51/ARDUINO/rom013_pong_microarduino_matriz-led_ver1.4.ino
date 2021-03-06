#include "LedControl.h"

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

//Mario Theme
int melody[] = {
  NOTE_E7, NOTE_E7, 0, NOTE_E7,
  0, NOTE_C7, NOTE_E7, 0,
  NOTE_G7, 0, 0,  0,
  NOTE_G6, 0, 0, 0,

  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,

  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0,

  NOTE_C7, 0, 0, NOTE_G6,
  0, 0, NOTE_E6, 0,
  0, NOTE_A6, 0, NOTE_B6,
  0, NOTE_AS6, NOTE_A6, 0,

  NOTE_G6, NOTE_E7, NOTE_G7,
  NOTE_A7, 0, NOTE_F7, NOTE_G7,
  0, NOTE_E7, 0, NOTE_C7,
  NOTE_D7, NOTE_B6, 0, 0
};
//Theme Mario tempo
int tempo[] = {
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,

  9, 9, 9,
  12, 12, 12, 12,
  12, 12, 12, 12,
  12, 12, 12, 12,
};

//Underworld melody
int underworld_melody[] = {
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_C4, NOTE_C5, NOTE_A3, NOTE_A4,
  NOTE_AS3, NOTE_AS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0,
  NOTE_F3, NOTE_F4, NOTE_D3, NOTE_D4,
  NOTE_DS3, NOTE_DS4, 0,
  0, NOTE_DS4, NOTE_CS4, NOTE_D4,
  NOTE_CS4, NOTE_DS4,
  NOTE_DS4, NOTE_GS3,
  NOTE_G3, NOTE_CS4,
  NOTE_C4, NOTE_FS4, NOTE_F4, NOTE_E3, NOTE_AS4, NOTE_A4,
  NOTE_GS4, NOTE_DS4, NOTE_B3,
  NOTE_AS3, NOTE_A3, NOTE_GS3,
  0, 0, 0
};
//Underworld time
int underworld_tempo[] = {
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  3,
  12, 12, 12, 12,
  12, 12, 6,
  6, 18, 18, 18,
  6, 6,
  6, 6,
  6, 6,
  18, 18, 18, 18, 18, 18,
  10, 10, 10,
  10, 10, 10,
  3, 3, 3
};

#define pinMelodia 7

const byte DIN      = 10;   // Conectado ao DataIn - DIn
const byte CS       = 9;   // Conectado ao LOAD - CS
const byte CLK      = 8;   // Conectado ao CLOCK - CLK
const byte DEVICES =  1;   // Somenta para MAX72XX -- DEVICES sao a quantidade de dispositivos que estao interligados


LedControl myMatrix = LedControl(DIN, CLK, CS, DEVICES ); // Controle da Matriz de led (myMatrix -> matriz de led)

int column = 1, row = random(8) + 1; // Decide em que ponto a bola deve iniciar
int directionX = 1, directionY = 1; // Certifica-se de que ela vai primeiro da esquerda para a direita
int paddle1 = 1, paddle1Val;        // Pino e valor do potenciometro
int speed = 300;                    // Velocidade da bola declarada em milisegundos
int counter = 0, mult = 10;         // Declaracao de contador e multiplicador


byte invader1a[] =
{
  B00011000,
  B00111100,
  B01111110,
  B11011011,
  B11111111,
  B00100100,
  B01011010,
  B10100101
};


byte invader1b[] =
{
  B00011000,
  B00111100,
  B01111110,
  B11011011,
  B11111111,
  B00100100,
  B01011010,
  B01000010
};

byte um [] =
{
  B00001000,
  B00011000,
  B00101000,
  B00001000,
  B00001000,
  B00001000,
  B00001000,
  B00111110
};

byte dois [] =
{
  B00111100,
  B00000100,
  B00000100,
  B00111100,
  B00100000,
  B00100000,
  B00100000,
  B00111100
};

byte tres [] =
{
  B00111100,
  B00000100,
  B00000100,
  B00111100,
  B00000100,
  B00000100,
  B00000100,
  B00111100
};

byte quatro [] =
{
  B00100100,
  B00100100,
  B00100100,
  B00100100,
  B00111100,
  B00000100,
  B00000100,
  B00000100
};

byte cinco [] =
{
  B00111100,
  B00100000,
  B00100000,
  B00100000,
  B00111100,
  B00000100,
  B00000100,
  B00111100
};
void setup()
{
  Serial.begin(9600);
  pinMode(7, OUTPUT);
  myMatrix.shutdown(0, false); // O MAX72XX esta em power-saving quando ligamos - fazer uma chamada para "acordar"
  myMatrix.setIntensity(0, 3); // Ajuste de brilho alterando o valor de dois (menos brilho) para 5 (mais brilho) - 0 a 15
  myMatrix.clearDisplay(0);    // Limpa a matriz
  randomSeed(analogRead(0));
}


void loop()
{

  paddle1Val = analogRead(paddle1);              // Le valor inicial do potenciometro
  paddle1Val = map(paddle1Val, 200, 1024, 1, 6); // Os valores sao mapeados entre 1 e 6

  column += directionX;     // Coordenadas de coluna
  row += directionY;        // Coordenadas de linha

  // Verificar se a bola atingiu a parede ou a raquete
  if (column == 6 && directionX == 1 && (paddle1Val == row || paddle1Val + 1 == row || paddle1Val + 2 == row))
  {
    directionX = -1; // Inverte a direcao da bola
  }

  // Se a bola atingiu as paredes topo, base ou lateral esquerda - inverte a direcao da bola
  if (column == 0 && directionX == -1 ) {
    directionX = 1;
  }
  if (row == 7 && directionY == 1 ) {
    directionY = -1;
  }
  if (row == 0 && directionY == -1 ) {
    directionY = 1;
  }

  // Se a bola estiver na coluna 7, nao atingiu a raquete e finaliza o jogo com a funcao GAME OVER
  if (column == 7) {
    sing(2);
    game_over();
  }

  myMatrix.clearDisplay(0); // Limpa a tela para o próximo quadro de animação

  myMatrix.setLed(0, column, row, HIGH);  // Desenha bola

  // Desenha a raquete na coluna 7
  myMatrix.setLed(0, 7, paddle1Val, HIGH);
  myMatrix.setLed(0, 7, paddle1Val + 1, HIGH);
  myMatrix.setLed(0, 7, paddle1Val + 2, HIGH);

  if (!(counter % mult)) {
    speed -= 5;
    mult * mult;
  } // Reinicia bola com menos velocidade
  delay(speed);
  counter++;
}

void game_over() // Acende todos os leds
{
 
 
  for (int i = 0; i < 8; i++)
  {
    myMatrix.setRow(0, i, cinco[i]);
  }
  delay (1000);
  for (int i = 0; i < 8; i++)
  {
    myMatrix.setRow(0, i, quatro[i]);
  }
  delay (1000);
  for (int i = 0; i < 8; i++)
  {
    myMatrix.setRow(0, i, tres[i]);
  }
  delay (1000);
  for (int i = 0; i < 8; i++)
  {
    myMatrix.setRow(0, i, dois[i]);
  }
  delay (1000);
  for (int i = 0; i < 8; i++)
  {
    myMatrix.setRow(0, i, um[i]);
  }
  delay (1000);
   for (int x = 0; x < 7; x++)
  {
    for (int i = 0; i < 8; i++)
    {
      myMatrix.setRow(0, i, invader1a[i]);
     
    }
     delay(200);
    for (int y = 0; y < 8; y++)
    {
      for (int i = 0; i < 8; i++)
      {
        myMatrix.setRow(0, i, invader1b[i]);
       
      }
       delay(200);
       }
      
     }
  counter = 0; // Reinicia todos os valores
  speed = 300;
  column = 1;
  row = random(8) + 1; // Escolhe uma nova posição inicial
}
int song = 0;

void sing(int s)
{
  // iterate over the notes of the melody:
  song = s;
  if (song == 2) {
    Serial.println(" 'Underworld Theme'");
    int size = sizeof(underworld_melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {

      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / underworld_tempo[thisNote];

      buzz(pinMelodia, underworld_melody[thisNote], noteDuration);

      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      buzz(pinMelodia, 0, noteDuration);

    }
  }
  else
  {
    Serial.println(" 'Mario Theme'");
    int size = sizeof(melody) / sizeof(int);
    for (int thisNote = 0; thisNote < size; thisNote++) {

      // to calculate the note duration, take one second
      // divided by the note type.
      //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
      int noteDuration = 1000 / tempo[thisNote];
      buzz(pinMelodia, melody[thisNote], noteDuration);
      // to distinguish the notes, set a minimum time between them.
      // the note's duration + 30% seems to work well:
      int pauseBetweenNotes = noteDuration * 1.30;
      delay(pauseBetweenNotes);
      // stop the tone playing:
      buzz(pinMelodia, 0, noteDuration);

    }
  }
}

void buzz(int targetPin, long frequency, long length)
{
  digitalWrite(7, HIGH);
  long delayValue = 1000000 / frequency / 2; // calculate the delay value between transitions
  //// 1 second's worth of microseconds, divided by the frequency, then split in half since
  //// there are two phases to each cycle
  long numCycles = frequency * length / 1000; // calculate the number of cycles for proper timing
  //// multiply frequency, which is really cycles per second, by the number of seconds to
  //// get the total number of cycles to produce
  for (long i = 0; i < numCycles; i++) { // for the calculated length of time...
    digitalWrite(targetPin, HIGH); // write the buzzer pin high to push out the diaphram
    delayMicroseconds(delayValue); // wait for the calculated delay value
    digitalWrite(targetPin, LOW); // write the buzzer pin low to pull back the diaphram
    delayMicroseconds(delayValue); // wait again or the calculated delay value
  }
}
