// Link do código
const int pinoSerie = A0;  // Pino analógico A0 (Conjunto Série)
const int pinoParalelo = A1;  // Pino analógico A1 (Conjunto Paralelo)

const int ledSerie = 7;      // LED indicador
const int ledParalelo = 8;      // LED indicador

int leituraSerie = 0;           // Variável para armazenar a leitura
float tensaoSerie = 0.0;        // Tensão convertida

int leituraParalelo = 0;           // Variável para armazenar a leitura
float tensaoParalelo = 0.0;        // Tensão convertida

// Limite de tensão para acionamento do LED
// const float limiteTensao = 2.5;  

void setup() {
  pinMode(ledSerie, OUTPUT);
  pinMode(ledParalelo, OUTPUT);

  Serial.begin(9600);     
}

void loop() {
  leituraSerie = analogRead(pinoSerie);   // 0 a 1023            
  tensaoSerie = leituraSerie * (5.0 / 1023.0);    // 0.00 a 5.00V
  
  leituraParalelo = analogRead(pinoParalelo);               
  tensaoParalelo = leituraParalelo * (5.0 / 1023.0);  

  // Exibe os valores no Monitor Serial
  Serial.print("Tensao - Conjunto Serie (V): ");
  Serial.println(tensaoSerie);

  Serial.print("Tensao - Conjunto Paralelo (V): ");
  Serial.println(tensaoParalelo);
  
  Serial.println("---------------------------------------------");

  // Verifica o limite de tensão e aciona o LED
  if (tensaoParalelo > tensaoSerie) {
    Serial.println("Paralelo gerando mais energia");
    digitalWrite(ledParalelo, HIGH);  // Acende o LED
    digitalWrite(ledSerie, LOW); 
  } else {
    Serial.println("Serie gerando mais energia");
    digitalWrite(ledParalelo, LOW);  // Acende o LED
    digitalWrite(ledSerie, HIGH); 
  }

  Serial.println("---------------------------------------------");
  delay(3000);  // Aguarda 1 segundo antes da próxima leitura
//-------------------------------------------------------------------------------------------------------------------------------
// Link do Tinkercad: https://www.tinkercad.com/things/6XBsR35TnGS/editel?sharecode=3e6lhBzGrtKpF4xpgzN-MGvRL61MA1lbPbnqJv-rEss
