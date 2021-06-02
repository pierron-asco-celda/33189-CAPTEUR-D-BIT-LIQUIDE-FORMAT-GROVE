# 33189 CAPTEUR DÉBIT LIQUIDE AU FORMAT GROVE


CAPTEUR DE PRESSION DIFFÉRENTIEL AU FORMAT GROVE [33189](https://www.pierron.fr/capteur-de-debit-de-liquide-grove.html)

Ce module, compatible Grove, mesure le débit d'un liquide. Il est basé sur un capteur de débit constitué d'un rotor et d'un capteur à effet hall. Lorsque l'eau passe dans le capteur, la rotation du rotor génère des impulsions en fonction du débit. La fréquence de sortie varie en fonction de la vitesse du rotor.

- Alimentation : 5 à 24 V
- Consommation : 15 mA
- Plage de mesure : 0,3 à 6 l/min
- Diamètre du filet : 1/8''

![L-33189](/img/L-33189.jpg)

# RESSOURCES À TÉLÉCHARGER :

Ressource utilisation : [NOTICE](https://github.com/pierron-asco-celda/33189-CAPTEUR-DEBIT-LIQUIDE-FORMAT-GROVE/blob/main/src/Pierron-33189-Datasheet.pdf)

# Schémas :

![SCH-33189](/img/SCH-33189.jpg)
![BRD-33189](/img/BRD-33189.jpg)

# Exemple :
### Arduino / C++
```cpp
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

```
## À propos :

PIERRON ASCO-CELDA (https://www.pierron.fr).