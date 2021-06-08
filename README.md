# 33189 Capteur de debit liquide GROVE


CAPTEUR DE PRESSION DIFFÉRENTIEL AU FORMAT GROVE [33189](https://www.pierron.fr/capteur-de-debit-de-liquide-grove.html)

Ce module, compatible Grove, mesure le débit d'un liquide. Il est basé sur un capteur de débit constitué d'un rotor et d'un capteur à effet hall. Lorsque l'eau passe dans le capteur, la rotation du rotor génère des impulsions en fonction du débit. La fréquence de sortie varie en fonction de la vitesse du rotor.

- Tension d’alimentation maximale : 5-12V DC
- Plage d’écoulement de l’eau : 0,3-6 L/min
- Diamètre intérieur : 4 mm
- Diamètre extérieur : 7 mm
- Taille de la buse Standard: Type 18 (1/8 " / 3.175mm) 
- Pression d’eau d’épreuve : <0,8 MPa
- Courant de fonctionnement : 15 mA (DC 5V)
- Résistance d’isolation: >100 MΩ
- Précision : ±5 % 
- L’impulsion de sortie de haut niveau : >4.5 VCC (tension d’entrée CC 5 V)
- L’impulsion de sortie bas niveau : <0.5 VCC (tension d’entrée CC 5 V)
- Formule d’écoulement de l’eau : 1L = 5880 ondes carrées
- Plage d’humidité de travail : 35% ~ 90% HR (pas de gel)

![L-33189](/img/L-33189.jpg)

# RESSOURCES À TÉLÉCHARGER :

Ressource utilisation : [NOTICE](https://github.com/pierron-asco-celda/33189-CAPTEUR-DEBIT-LIQUIDE-FORMAT-GROVE/blob/main/src/Pierron-33189-Datasheet.pdf)

# Schémas :

![SCH-33189](/img/SCH-33189.jpg)
![BRD-33189](/img/BRD-33189.jpg)

# Exemple :

### mBlock
![P1-33189](/img/P1-33189.jpg)

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
