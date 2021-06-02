# 33189 CAPTEUR DEBIT LIQUIDE AU FORMAT GROVE


CAPTEUR DE PRESSION DIFFÉRENTIEL AU FORMAT GROVE [33189](https://www.pierron.fr/capteur-de-debit-de-liquide-grove.html)

![L-33189](/img/L-33189.jpg)

# Installation :
Créer un nouveau répertoire nommé "Pierron_33188" dans le dossier "libraries" de votre dossier Arduino.
Y placer tous les fichiers.
Ou
télécharger le dépôt en ZIP et dans l'IDE Arduino : Croquis / inclure bibliothèque / ajouter la bibliothèque ZIP.

# Usage :
Pour utiliser la librairie dans votre propre projet, importez-la avec  *Sketch > Import Library*.

# RESSOURCES À TÉLÉCHARGER :

Ressource utilisation : [NOTICE](https://github.com/pierron-asco-celda/Pierron_33188/blob/master/src/Pierron-33188-Datasheet.pdf)

# Schémas :

![SCH-33188](/img/SCH-33188.png)

![BRD-33188](/img/BRD-33188.png)

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

PIERRON ASCO-CELDA (https://www.pierron.fr/).