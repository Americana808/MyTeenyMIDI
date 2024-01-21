int const numPins = 18; // number of pins
int currentVal[numPins];
int newVal[numPins];
int analogPins[] = {
  0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17
};
//0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17
int const channel = 1; // The MIDI channel

void setup() {
  // put your setup code here, to run once:
  Serial.begin(38400);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < numPins; i++) {

    newVal[i] = analogRead(analogPins[i]); //Read analog value

    if (abs(newVal[i] - currentVal[i]) > 3) {
      usbMIDI.sendControlChange(i + 1, newVal[i] >> 3, channel); //(control, value, channel)
      currentVal[i] = newVal[i];
    }
  }

  while (usbMIDI.read());
  delay(25);

}
