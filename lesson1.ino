const int redled = 7;
const int yellowled = 6;
const int greenled = 5;

const int startBtn = 12;
const int stopBtn = 13;

void setup() {
  pinMode(redled, OUTPUT);
  pinMode(yellowled, OUTPUT);
  pinMode(greenled, OUTPUT);

  pinMode(startBtn, INPUT_PULLUP);
  pinMode(stopBtn, INPUT_PULLUP);
}

void allOff() {
  digitalWrite(redled, LOW);
  digitalWrite(yellowled, LOW);
  digitalWrite(greenled, LOW);
}

bool waitOrStop(int duration) {
  for (int i = 0; i < duration; i += 10) {
    if (digitalRead(stopBtn) == LOW) {
      allOff();
      return false;
    }
    delay(10);
  }
  return true;
}

void loop() {
  if (digitalRead(startBtn) == LOW) {

    // RED LED
    allOff();
    digitalWrite(redled, HIGH);
    if (!waitOrStop(3000)) return;

    // YELLOW LED
    allOff();
    digitalWrite(yellowled, HIGH);
    if (!waitOrStop(1000)) return;

    // GREEN LED
    allOff();
    digitalWrite(greenled, HIGH);
    if (!waitOrStop(3000)) return;

    // Turn all LEDs off
    allOff();
  }

  // STOP button
  if (digitalRead(stopBtn) == LOW) {
    allOff();
  }
}