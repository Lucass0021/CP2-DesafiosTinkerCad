// Link do Tinkercad

// https://www.tinkercad.com/things/jJioUXsUmn2-copy-of-exercicio-03-cp2-sers/editel?returnTo=%2Fthings%2FjJioUXsUmn2-copy-of-exercicio-03-cp2-sers&sharecode=tDhot8OSGdBBLiKJwY3UmMEnxfMcHZmIO1FTyI_g03s

const int pinSensor = A0;
const int ledVerde = 8;
const int ledAmarelo = 9;
const int ledVermelho = 10;

void setup() {
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int leitura = analogRead(pinSensor);

  float tensao = leitura * (5.0 / 1023.0) * 6.0; 

  if (tensao < 24.0) {
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
    Serial.println("Estado: NORMAL");
  } else if (tensao >= 24.0 && tensao < 27.0) {
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, LOW);
    Serial.println("Estado: ALERTA");
  } else {
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, HIGH);
    Serial.println("Estado: SOBRECARGA MÁXIMA");
  }

  Serial.print("Tensão medida: ");
  Serial.print(tensao);
  Serial.println(" V");

  delay(2000);
}
