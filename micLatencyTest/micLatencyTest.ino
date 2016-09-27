/*
 Name:		micLatencyTest.ino
 Created:	9/15/2016 10:28:24 AM
 Author:	yangtang
*/
#define led 13  // built-in LED
//#define debug;

unsigned long time1;
unsigned long time2;
int beginSignal;
int sensorVal;
const int analogPin = A3;	// Analog input pin 0
String lastSong;

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);
	DDRD = 0xFC;		// Port D data direction register sets pins 2-7 as output
	//Serial.println("counter started");
	//Serial.println("press 1 then enter to start");
	
#ifdef debug
		Serial.println("press 2 for next song");
#endif

}

// the loop function runs over and over again until power down or reset
void loop() {
	while (Serial.available() > 0) {	// Send data only when data received
		beginSignal = Serial.read();	// Read incoming bit

		if (beginSignal == 49 || beginSignal == 50) {	// Wait for input from serial
			time1 = micros() / 1000;	// Init time
			sensorVal = analogRead(analogPin);	// Read ADC value on channel 0
			
			#ifdef debug	// Print sensorVal
				Serial.print("sensor value: ");
				Serial.print(sensorVal);
				Serial.println();
			#endif	

			if (beginSignal == 49) { Serial.println("pause|"); }
			else { Serial.println("next|"); }

			//while (sensorVal <= 10) {}
			
			recordTime();

#ifdef debug
	else {
		digitalWrite(led, LOW);
		Serial.print(" LED OFF");
		Serial.println();    // End the line
	}
#endif

		}
	}
}

void recordTime() {
	time2 = micros() / 1000;	// Saves time when music was heard
	digitalWrite(led, HIGH);

	//prints time(ms) = time2 - time1
	Serial.println(time2 - time1);
}
