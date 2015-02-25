// Pin 13 has an LED connected on most Arduino boards.
// give it a name:
const int ledPin = 13;
const int baudRate = 9600;

// the setup routine runs once when you press reset:
void setup() {
	// initialize the digital pin as an output.
	pinMode(ledPin, OUTPUT);
	Serial.begin(baudRate);
}

// the loop routine runs over and over again forever:
void loop() {
	if (Serial.available()) {
                char chr = Serial.read() - '0';
		light(chr);
	}
	delay(500);
}

void light (int n) {
	for (int i = 0; i < n; i++) {
		digitalWrite(ledPin, HIGH);   // turn the LED on (HIGH is the voltage level)
		delay(100);               // wait for a second
		digitalWrite(ledPin, LOW);    // turn the LED off by making the voltage LOW
		delay(100);               // wait for a second
	}
}
