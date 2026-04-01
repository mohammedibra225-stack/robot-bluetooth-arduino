# 🤖 Bluetooth Controlled Robot Car with Arduino Mega

## 📌 Description

Ce projet consiste à réaliser une voiture robotisée contrôlée via Bluetooth à l’aide d’un smartphone.
Le système utilise une carte Arduino Mega, un module Bluetooth (HC-05 / BTBee Pro), un driver moteur L293D (via AFMotor), deux servomoteurs et un écran LCD I2C.

---

## ⚙️ Fonctionnalités

* 🚗 Contrôle des **4 moteurs DC**
* 📡 Communication **Bluetooth avec smartphone**
* 🎮 Commandes simples via application mobile
* 🦾 Contrôle de **2 servomoteurs**
* 📺 Affichage d'informations sur écran **LCD I2C**

---

## 🧰 Matériel utilisé

* Arduino Mega 2560
* Module Bluetooth HC-05 / BTBee Pro
* Motor Shield L293D (compatible AFMotor)
* 4 moteurs DC
* 2 servomoteurs
* Écran LCD I2C (20x4)
* Batterie externe pour moteurs
* Fils de connexion

---

## 🔌 Connexions principales

### Bluetooth (Serial3 - Arduino Mega)

| Module Bluetooth | Arduino Mega |
| ---------------- | ------------ |
| TX               | RX3 (Pin 15) |
| RX               | TX3 (Pin 14) |
| VCC              | 5V           |
| GND              | GND          |

---

### Servomoteurs

* Servo1 → Pin 9
* Servo2 → Pin 10

---

### LCD I2C

* Adresse : `0x20`
* SDA → SDA (Mega)
* SCL → SCL (Mega)

---

## 📱 Commandes Bluetooth

| Commande | Action  |
| -------- | ------- |
| F        | Avancer |
| B        | Reculer |
| L        | Gauche  |
| R        | Droite  |
| S        | Stop    |

### 🎮 Servos

| Commande | Action                      |
| -------- | --------------------------- |
| 0 - 4    | Position Servo1 (0° → 180°) |
| 5 - 9    | Position Servo2 (0° → 180°) |

---

## 💻 Installation

1. Installer Arduino IDE
2. Installer les bibliothèques :

   * AFMotor
   * LiquidCrystal_I2C
   * Servo
3. Connecter le matériel
4. Téléverser le code sur l'Arduino Mega
5. Connecter le module Bluetooth au téléphone
6. Utiliser une application comme :

   * Serial Bluetooth Terminal
   * Arduino Bluetooth Controller

---

## ⚠️ Remarques importantes

* Utiliser une **alimentation externe** pour les moteurs
* Relier les **GND en commun**
* Débrancher le Bluetooth lors du téléversement si nécessaire
* Vérifier le **baud rate (9600)**

---

## 🚀 Améliorations possibles

* Ajout de capteurs ultrason (évitage d'obstacles)
* Mode autonome
* Application mobile personnalisée
* Contrôle par WiFi


