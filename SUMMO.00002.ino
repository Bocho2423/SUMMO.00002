// Incluye la librería para el sensor ultrasónico
#include <NewPing.h>

// Configuración del motor
const int motorPin1 = 5; // Conecta al pin IN1 del motor

// Configuración del sensor ultrasónico
const int trigPin = 9;
const int echoPin = 12;

// Configuración de distancia umbral para detección
const int distanciaUmbral = 20; // En centímetros

// Crea un objeto NewPing para el sensor ultrasónico
NewPing sonar(trigPin, echoPin);

void setup() {
    pinMode(motorPin1, OUTPUT);
    Serial.begin(9600); // Inicializa la comunicación serial
}

void loop() {
    // Mide la distancia con el sensor ultrasónico
    int distancia = sonar.ping_cm();

    // Control del motor según la distancia
    if (distancia > distanciaUmbral) {
        // Avanza
        digitalWrite(motorPin1, HIGH);
    } else {
        // Detiene el motor
        digitalWrite(motorPin1, LOW);
    }

    // Muestra la distancia en el monitor serial
    Serial.print("Distancia: ");
    Serial.print(distancia);
    Serial.println(" cm");
    delay(600); // Pequeña pausa para evitar lecturas rápidas
}
