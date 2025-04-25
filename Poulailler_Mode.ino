const int FDC_O = 3;
const int FDC_F = 4;
const int ledpin = 6;
const int boutonDebloque = A1;
const int pontEnHPin1 = 9;
const int pontEnHPin2 = 10;
const int switchPin = 7;
int LuminositePin = A0;

bool fdc_o = false;
bool fdc_f = false;
bool porte_fermee = false;
bool porte_ouverte = true;
bool porte_bloque = false;
bool mode_auto = true;

unsigned long previousMillis = 0;
bool ledState = false;

void setup() {
  pinMode(FDC_O, INPUT_PULLUP);
  pinMode(FDC_F, INPUT_PULLUP);
  pinMode(ledpin, OUTPUT);
  pinMode(pontEnHPin1, OUTPUT);
  pinMode(pontEnHPin2, OUTPUT);
  pinMode(boutonDebloque, INPUT_PULLUP);
  pinMode(switchPin, INPUT_PULLUP);

  digitalWrite(ledpin, LOW);
}

void loop() {
  int Luminosite = analogRead(LuminositePin);
  fdc_o = !digitalRead(FDC_O);
  fdc_f = !digitalRead(FDC_F);
  mode_auto = digitalRead(switchPin); // HIGH = auto, LOW = manuel

  // Gestion du bouton
  if (digitalRead(boutonDebloque) == LOW) {
    delay(50);
    if (digitalRead(boutonDebloque) == LOW) {
      while (digitalRead(boutonDebloque) == LOW);
      if (porte_bloque) {
        porte_bloque = false;
      } else if (!mode_auto) {
        if (porte_fermee) ouverture();
        else if (porte_ouverte) fermeture();
      }
    }
  }

  // Gestion de la LED
  if (porte_bloque) {
    unsigned long currentMillis = millis();
    if (currentMillis - previousMillis >= 500) {
      previousMillis = currentMillis;
      ledState = !ledState;
      digitalWrite(ledpin, ledState);
    }
  } else if (!mode_auto) {
    digitalWrite(ledpin, HIGH);
  } else {
    digitalWrite(ledpin, LOW);
  }

  // Mode auto : contrôle selon la luminosité
  if (!porte_bloque && mode_auto) {
    if (Luminosite >= 50 && (fdc_f || !fdc_o)) {
      ouverture();
    }
    if (Luminosite <= 20 && (fdc_o || !fdc_f)) {
      fermeture();
    }
  }
}

void ouverture() {
  unsigned long startTime = millis();
  while (!fdc_o) {
    digitalWrite(pontEnHPin1, HIGH);
    digitalWrite(pontEnHPin2, LOW);
    fdc_o = !digitalRead(FDC_O);
    if (millis() - startTime > 4000) {
      stop();
      porte_bloque = true;
      return;
    }
  }
  porte_fermee = false;
  porte_ouverte = true;
  stop();
}

void fermeture() {
  unsigned long startTime = millis();
  while (!fdc_f) {
    digitalWrite(pontEnHPin1, LOW);
    digitalWrite(pontEnHPin2, HIGH);
    fdc_f = !digitalRead(FDC_F);
    if (millis() - startTime > 4000) {
      stop();
      porte_bloque = true;
      return;
    }
  }
  porte_fermee = true;
  porte_ouverte = false;
  stop();
}

void stop() {
  digitalWrite(pontEnHPin1, LOW);
  digitalWrite(pontEnHPin2, LOW);
}
