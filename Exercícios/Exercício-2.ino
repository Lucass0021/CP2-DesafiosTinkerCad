// https://www.tinkercad.com/things/65K3kiegYJG/editel

// CODIGO USADO: 

#define RELE1 7
#define RELE2 8
#define PINO_FONTE1 A0
#define PINO_FONTE2 A1

void setup() {
  Serial.begin(9600);
  pinMode(RELE1, OUTPUT);
  pinMode(RELE2, OUTPUT);
}

void loop() {
  int tensaoFonte1 = analogRead(PINO_FONTE1);
  int tensaoFonte2 = analogRead(PINO_FONTE2);

  Serial.print("Tensão Fonte 1: ");
  Serial.println(tensaoFonte1);
  Serial.print("Tensão Fonte 2: ");
  Serial.println(tensaoFonte2);

  
  if (tensaoFonte1 > tensaoFonte2) {
    digitalWrite(RELE1, HIGH);  
    digitalWrite(RELE2, LOW);   
    Serial.println("Fonte 1 ativada");
  } else {
    digitalWrite(RELE1, LOW);  
    digitalWrite(RELE2, HIGH);  
    Serial.println("Fonte 2 ativada");
  }

  Serial.println("------------------------");
  delay(5000); 
}
