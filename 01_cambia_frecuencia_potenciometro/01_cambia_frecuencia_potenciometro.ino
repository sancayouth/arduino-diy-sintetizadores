/*

  circuito:
  - Potenciometro de 10k con el pin central conectado en el pin analogo 0,
    los pin de los lados van conectados a +5V y tierra
  - Salida de audio conectada al pin digital 9

*/

void setup()
{
  // Inicializamos el serial para debuggear
  Serial.begin(9600);
}

void loop()
{
  // Leemos el potenciometro
  int pot_frequencia = analogRead(A0);
  int pitch = map(pot_frequencia, 0, 1023, 220, 880);
  Serial.println(pitch);

  // Hacemos sonar el pitch
  tone(9, pitch, 10);
  delay(1);
}
