// C++ code
//
int celsius = 0;
int sensor = 0;

void setup()
{
  pinMode(A0, INPUT);
  Serial.begin(9600);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop()
{
  //medição da temperatura em Celsius
  sensor = analogRead (A0);
  celsius = map(((analogRead(A0) - 20) * 3.04), 0, 1023, -40, 125);
    
  Serial.print("Medida do sensor = ");
  Serial.println(sensor);
  Serial.print("Temperatura = ");
  Serial.print(celsius);
  Serial.println("C, ");
  Serial.println("   ");
  
  if (celsius <= 0) {
     digitalWrite(5, LOW);
     digitalWrite(6, LOW);
     digitalWrite(7, LOW);
     digitalWrite(8, LOW);
     digitalWrite(9, LOW);
     digitalWrite(10, LOW);
     digitalWrite(11, LOW);
     digitalWrite(12, LOW);
     digitalWrite(13, HIGH);
  }
  if (celsius > 0 && celsius <= 10) {
     digitalWrite(5, LOW);
     digitalWrite(6, LOW);
     digitalWrite(7, LOW);
     digitalWrite(8, LOW);
     digitalWrite(9, LOW);
     digitalWrite(10, LOW);
     digitalWrite(11, LOW);
     digitalWrite(12, HIGH);
     digitalWrite(13, LOW);
  }
  if (celsius > 10 && celsius <= 20) {
     digitalWrite(5, LOW);
     digitalWrite(6, LOW);
     digitalWrite(7, LOW);
     digitalWrite(8, LOW);
     digitalWrite(9, LOW);
     digitalWrite(10, LOW);
     digitalWrite(11, HIGH);
     digitalWrite(12, LOW);
     digitalWrite(13, LOW);
  }
  if (celsius > 20 && celsius <= 30) {
     digitalWrite(5, LOW);
     digitalWrite(6, LOW);
     digitalWrite(7, LOW);
     digitalWrite(8, LOW);
     digitalWrite(9, LOW);
     digitalWrite(10, HIGH);
     digitalWrite(11, LOW);
     digitalWrite(12, LOW);
     digitalWrite(13, LOW);
  }
  if (celsius > 30 && celsius <= 40) {
     digitalWrite(5, LOW);
     digitalWrite(6, LOW);
     digitalWrite(7, LOW);
     digitalWrite(8, LOW);
     digitalWrite(9, HIGH);
     digitalWrite(10, LOW );
     digitalWrite(11, LOW);
     digitalWrite(12, LOW);
     digitalWrite(13, LOW);
  }
  if (celsius > 40 && celsius <= 50) {
     digitalWrite(5, LOW);
     digitalWrite(6, LOW);
     digitalWrite(7, LOW);
     digitalWrite(8, HIGH);
     digitalWrite(9, LOW);
     digitalWrite(10, LOW );
     digitalWrite(11, LOW);
     digitalWrite(12, LOW);
     digitalWrite(13, LOW);
  }
  if (celsius > 50 && celsius <= 60) {
     digitalWrite(5, LOW);
     digitalWrite(6, LOW);
     digitalWrite(7, HIGH);
     digitalWrite(8, LOW);
     digitalWrite(9, LOW);
     digitalWrite(10, LOW );
     digitalWrite(11, LOW);
     digitalWrite(12, LOW);
     digitalWrite(13, LOW);
  }
  if (celsius > 60 && celsius <= 70) {
     digitalWrite(5, LOW);
     digitalWrite(6, HIGH);
     digitalWrite(7, LOW);
     digitalWrite(8, LOW);
     digitalWrite(9, LOW);
     digitalWrite(10, LOW );
     digitalWrite(11, LOW);
     digitalWrite(12, LOW);
     digitalWrite(13, LOW);
  }
  if (celsius > 70) {
     digitalWrite(5, HIGH);
     digitalWrite(6, LOW);
     digitalWrite(7, LOW);
     digitalWrite(8, LOW);
     digitalWrite(9, LOW);
     digitalWrite(10, LOW );
     digitalWrite(11, LOW);
     digitalWrite(12, LOW);
     digitalWrite(13, LOW);
  }
  delay(5000); // Delay de 5000 millisegundos(s = 0,5 segundos
}