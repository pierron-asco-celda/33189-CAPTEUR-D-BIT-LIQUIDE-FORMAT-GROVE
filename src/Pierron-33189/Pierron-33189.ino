// baud rate 9600;

int interruption = 0;
int capteur      = 2;

unsigned int SetPoint = 400;
float calibration = 90;

volatile byte compteur = 0;
float debit = 0.0;

unsigned int debitinstantane = 0;
unsigned long quantitetotal = 0; 
unsigned long oldTime = 0;

void setup() {
  Serial.begin(9600);
  pinMode(capteur, INPUT);
  digitalWrite(capteur, HIGH);

  attachInterrupt(interruption, comptage, FALLING);
}

void loop() {
  if ((millis() - oldTime) > 1000)
  {
    detachInterrupt(interruption);
    debit = ((1000.0 / (millis() - oldTime)) * compteur) / calibration;
    oldTime = millis();
    debitinstantane = (debit / 60) * 1000;
    quantitetotal += debitinstantane;
    unsigned int frac;

    Serial.print("Débit instantané: ");
    Serial.print(debitinstantane, DEC);
    Serial.print("mL/Sec");
    Serial.print("\t");

    Serial.print("Débit total: ");
    Serial.print(quantitetotal, DEC);
    Serial.println("mL");
    Serial.print("\t");

    if (quantitetotal > 40) {
    }
    compteur = 0;
    attachInterrupt(interruption, comptage, FALLING);
  }
}

void comptage()
{
  compteur++;
}
