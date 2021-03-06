/**********************************************************************************
************************************BIBLIOTECAS************************************
**********************************************************************************/
#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include <ESP8266WiFi.h>
#include <ESP8266WiFiMulti.h>
#include <WiFiUdp.h>
#include <NTPClient.h>
#include "SSD1306Wire.h"

// Configuração do Display OLED
SSD1306Wire  display(0x3c, 5, 4);

#define pinLED 16

// Definição da conexão Wi-Fi
char ssid []  = ")o,0(";
char password [] = "riko1234";


// Definição do Servidor NTP
WiFiUDP udp;
NTPClient ntp(udp, "a.st1.ntp.br", -3 * 3600, 60000);
char days[7][12] = {"DOMINGO", "SEGUNDA", "TERÇA", "QUARTA", "QUINTA", "SEXTA", "SÁBADO"};


String combo, data, tempo;
int b = 0;
int networks;

/* struct Date {
  int dayOfWeek;
  int day;
  int month;
  int year;
  int hours;
  int minutes;
  int seconds;
*/

void setup() {
  // Inicializaçaõ do monitor serial e definição da velocidade de transmissão
  Serial.begin(115200);
  delay(100);

  //pinMode(pinLED, OUTPUT);
  //digitalWrite(pinLED, HIGH);

  // Inicialização do display OLED e definição do modo de exibição
  telaInicial();
  conectarWiFi();

  //Inicializa o cliente NTP
  ntp.begin();
  delay(250);
  ntp.update();
}

void telaInicial()
{
  display.init();
  display.flipScreenVertically();
  display.setFont(ArialMT_Plain_16);
  display.display();
  display.clear();
}

void conectarWiFi()
{
  //Inicializaçaõ da conexão com a rede WLAN
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  delay(500);

  Serial.println();
  Serial.println();
  Serial.print("CONECTANDO...");
  Serial.println(ssid);
  delay(1500);

  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.drawString(0, 15, "CONECTANDO...");
  display.display();
  delay(1500);
  display.clear();

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");

    display.drawString(b, 10, ".");
    b += 5;
    display.display();
    delay(500);
    display.clear();
  }
  progress();

  Serial.println();
  Serial.println("Done!");
  Serial.println("Wi-Fi connected");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());
  delay(1500);

  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.drawString(0, 0, "Wi-Fi: ");
  display.drawString(0, 15, ssid);
  display.drawString(0, 30, "conectado.");
  display.display();
  delay(1500);
  display.clear();
}

void progress()
{
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  for (int contador = 0; contador <= 100; contador++)
  {
    //Desenha a barra de progresso
    display.drawProgressBar(0, 32, 120, 10, contador);
    display.drawString(64, 15, String(contador) + "%");
    display.display();
    delay(17);
    display.clear();
  }
}

void graficos()
{
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  //Desenha um quadrado
  display.drawRect(12, 12, 30, 30);
  //Desenha um quadrado cheio
  display.fillRect(20, 20, 35, 35);
  //Desenha circulos
  for (int i = 1; i < 8; i++)
  {
    display.drawCircle(92, 32, i * 3);
  }
  display.display();
  delay(1000);
  display.clear();
}

void newTime()
{
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  if (WiFi.status() != WL_CONNECTED)
  {
    display.drawString(0, 0, "Falha ao obter a hora!");
    delay(2000);
    display.drawString(0, 20, "Erro de conexão...");
    delay (2000);
    return;
  }
  else
  {
    int y = 0;
    while (!ntp.update())
    {

      Serial.print(".");

      display.drawString(y, 10, ".");
      y += 5;
      display.display();
      ntp.forceUpdate();
      delay(500);
      display.clear();

    }
    // Variável que armazena hora atualizada no formato gregoriano
    tempo = ntp.getFormattedTime();

    combo = ntp.getFormattedDate();    // notação 2018-04-30T16:00:13Z

    int splitT = data.indexOf("T");
    data = combo.substring(0, splitT);

    for (int c = 0; c < 100; c++)
    {
      Serial.print(days[ntp.getDay()]);
      Serial.print(", ");
      Serial.println(data);
      Serial.print(ntp.getHours());
      Serial.print(":");
      Serial.print(ntp.getMinutes());
      Serial.print(":");
      Serial.println(ntp.getSeconds());

      display.setFont(ArialMT_Plain_16);
      display.drawString(10, 0, days[ntp.getDay()]);
      display.drawLine(15, 50, 120, 50); // Adiciona uma linha à lista de escrita do display
      display.setFont(ArialMT_Plain_24);
      display.drawString(22, 20, ntp.getFormattedTime());
      display.display(); // Escreve as informações da lista de escrita no display
      delay(500);
      display.clear();
    }
  }
}

void medirNet()
{
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_16);
  for (int m = 0; m < 15; m++)
  {
    display.drawString(20, 0, ssid);
    display.drawString(0, 20, "Sinal: ");
    display.drawString(0, 35, String (WiFi.RSSI()) + "dBm");
    display.display();
    delay(250);
    display.clear();
  }
}

void messages()
{
  display.setTextAlignment(TEXT_ALIGN_CENTER);
  display.setFont(ArialMT_Plain_16);  //Define fonte e tamanho da letra
  display.drawString (0, 5, "MENSAGEM");
  display.drawString (0, 22, "URGENTE!");
  display.display();
  delay(3000);
  display.clear();

  for (uint8_t d = 0; d < 10; d++) {
    display.setTextAlignment(TEXT_ALIGN_LEFT);
    display.drawString (0, 5, "QUERIDA ");
    display.drawString (25, 23, "REBECA, ");
    display.display();
    delay(500);
    display.clear();
  }

  for (uint8_t f = 0; f < 3; f++)
  {
    for (int16_t g = -127; g < 192; g++)
    {
      if (g == 164)
      {
        display.setFont(ArialMT_Plain_16);
        display.drawString(g - 164, 12 * f, "SAUDADES!!!");
        display.display();
        delay(3000);
        display.clear();
      }
      if (g == 10)
      {
        display.setFont(ArialMT_Plain_10);
        display.drawString(g, 11, "DESDE QUE NASCEU,");
        delay(2000);
        display.drawString(g + 17, 22, "MEU CORAÇÃO");
        delay(2000);
        display.drawString(g + 35, 33, "É SEU!");
        display.display();
        delay(4000);
        display.clear();
      }
      else
      {
        display.setFont(ArialMT_Plain_16);
        display.drawString(g, 31, "EU TE AMO!");
        display.display();
        delay(17);
        display.clear();
      }
    }
  }
}

void buscarNets()
{
  display.setTextAlignment(TEXT_ALIGN_LEFT);
  display.setFont(ArialMT_Plain_16);
  display. drawString(0, 10, "LOCALIZANDO...");
  networks = WiFi.scanNetworks();
  display.display();
  delay(1000);
  display.clear();

  for (int z = 0; z < networks; z++)
  {
     display.drawString(0, 5, "Wi-Fi: ");
      display.drawString(0, 20, WiFi.SSID(z));
      display.drawString(0, 35, "Sinal: ");
      display.drawString(0, 50, String( WiFi.RSSI(z)) + "dBm");
      //display.drawString(30, 45, "dBm");
      display.display();
      delay(1000);
      display.clear();
  }
}


/* Date getDate()
  {
  //Recupera os dados de data e horário usando o client NTP
  char* strDate = (char*)ntpClient.getFormattedDate().c_str();

  //Passa os dados da string para a struct
  Date date;
  sscanf(strDate, "%d-%d-%dT%d:%d:%dZ",
         &date.year,
         &date.month,
         &date.day,
         &date.hours,
         &date.minutes,
         &date.seconds);

  //Dia da semana de 0 a 6, sendo 0 o domingo
  date.dayOfWeek = ntpClient.getDay();
  return date;
  }
*/

void loop()
{
  /*
      Date date = get.Date();
      display.printf(" %s             \n\n %s  \n\n %02d/%02d/%d\n\n %02d:%02d:%02d",
      WiFi.SSID().c_str(),
      dayOfWeekNames[date.dayOfWeek],
      date.day,
      date.month,
      date.year,
      date.hours,
      date.minutes,
      date.seconds);
    }
  */
  display.clear();
  medirNet();
  newTime();
  messages();
  buscarNets();
  graficos();

}
