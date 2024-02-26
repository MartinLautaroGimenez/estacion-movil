#include <SD.h>

File logFile;
bool holaMundoImpreso = false; // Variable para controlar si se ha impreso "Hola mundo" o no

void setup()
{
  Serial.begin(9600);
  Serial.print(F("Iniciando SD ..."));
  if (!SD.begin(9))
  {
    Serial.println(F("Error al iniciar"));
    return;
  }
  Serial.println(F("Iniciado correctamente"));
}

void loop()
{
  // Si "Hola mundo" aún no se ha impreso, lo imprime y establece la bandera a verdadero
  if (!holaMundoImpreso) {
    logFile = SD.open("datalog.txt", FILE_WRITE);
    if (logFile) { 
      logFile.print("HOLA MUNDO\n"); // Imprime "Hola mundo" con un salto de línea
      logFile.close();
      holaMundoImpreso = true; // Establece la bandera a verdadero
      Serial.println("Archivo escrito correctamente");
    } else {
      Serial.println("Error al abrir el archivo");
    }
  }
  delay(500);
}
