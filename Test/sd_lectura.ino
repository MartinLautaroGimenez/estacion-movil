#include <SPI.h>
#include <SD.h>

const int chipSelect = 9;

void setup() {
  Serial.begin(9600);
  
  if (!SD.begin(chipSelect)) {
    Serial.println("Error al inicializar la tarjeta SD.");
    return;
  }
  
  Serial.println("Leyendo el archivo datalog.txt:");
  File dataFile = SD.open("datalog.txt");
  
  if (dataFile) {
    while (dataFile.available()) {
      Serial.write(dataFile.read());
    }
    dataFile.close();
  } else {
    Serial.println("Error al abrir el archivo datalog.txt.");
  }
}

void loop() {
  //nada si no se repiteria la lectura infinitamente
}
