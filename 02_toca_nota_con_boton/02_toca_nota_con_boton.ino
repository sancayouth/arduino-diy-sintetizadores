/*

  circuito:
  - Salida de audio conectada al pin digital 9
  - Boton conectado en el pin digial 2

*/

byte pinAudio = 9;
byte boton = 2;
byte estadoBoton = 0;
byte estadoPrevioBoton = 0;
int tocaNota = 0;

// 262 es la frecuencia en HZ en la que se encuentra la nota DO
#define DO_NOTA 262

void setup()
{
  Serial.begin(9600);
  // Seteamos el boton en modo de Entrada
  pinMode(boton, INPUT);
}

void loop()
{
  estadoBoton = digitalRead(boton);
  if (estadoBoton == HIGH && estadoPrevioBoton == LOW)
  {
    tocaNota = 1 - tocaNota;
    delay(20);
  }
  estadoPrevioBoton = estadoBoton;
  if (tocaNota)
    tone(pinAudio, DO_NOTA, 10);
}
