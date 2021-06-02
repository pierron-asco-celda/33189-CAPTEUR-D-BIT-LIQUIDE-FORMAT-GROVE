// Baud rate 9600;

int sensorPin       = 2;
unsigned int SetPoint = 400;
float calibrationFactor = 90;
volatile byte pulseCount = 0;
float flowRate = 0.0;
unsigned int flowMilliLitres = 0;
unsigned long totalMilliLitres = 0;

unsigned long oldTime = 0;

void setup(){
  Serial.begin(9600);
  pinMode(sensorPin, INPUT);
  digitalWrite(sensorPin, HIGH);
}

void loop(){
  if ((millis() - oldTime) > 1000)
  {
    flowRate = ((1000.0 / (millis() - oldTime)) * pulseCount) / calibrationFactor;
    oldTime = millis();
    flowMilliLitres = (flowRate / 60) * 1000;
    totalMilliLitres += flowMilliLitres;
    
    Serial.print("Debit instantane: ");
    Serial.print(flowMilliLitres, DEC);
    Serial.print("mL/Second");
    Serial.print("\t");

    Serial.print("Debit Total: ");
    Serial.print(totalMilliLitres, DEC);
    Serial.println("mL");
    Serial.print("\t");
    
    pulseCount = 0;
  }
}

void pulseCounter()
{
  pulseCount++;
}
