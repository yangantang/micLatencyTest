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
const int analogPin = A0;	// Analog input pin 0
const int sampleWindow = 50; // Sample window width in mS (50 mS = 20Hz)
unsigned int sample;

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);
	//DDRD = 0xFF;		// Port D data direction register sets pins 2-7 as output
	//Serial.println("counter started");
	//Serial.println("press 1 then enter to start");
}

// the loop function runs over and over again until power down or reset
void loop() {
	while (Serial.available() > 0) {	// Send data only when data received
		beginSignal = Serial.read();	// Read incoming bit

		if (beginSignal == 49 || beginSignal == 50) {	// Wait for input from serial
			if (beginSignal == 49) { Serial.print("pause|"); }
			else { Serial.print("next|"); }

			time1 = micros() / 1000;	// Init time
			
			#ifdef debug	// Print sensorVal
				Serial.print("sensor value: ");
				Serial.print(sensorVal);
				Serial.println();
			#endif	
			
			double output = 0;
			
			while (output <= 0.9) {
				output = peakToPeak();
			}
			
			recordTime();
		}
	}
}

double peakToPeak() {
	unsigned long startMillis = millis();  // Start of sample window
	unsigned int peakToPeak = 0;   // peak-to-peak level

	unsigned int signalMax = 0;
	unsigned int signalMin = 1024;

	// collect data for 50 mS
	while (millis() - startMillis < sampleWindow)
	{
		sample = analogRead(0);
		if (sample < 1024)  // toss out spurious readings
		{
			if (sample > signalMax)
			{
				signalMax = sample;  // save just the max levels
			}
			else if (sample < signalMin)
			{
				signalMin = sample;  // save just the min levels
			}
		}
	}
	peakToPeak = signalMax - signalMin;  // max - min = peak-peak amplitude
	double volts = (peakToPeak * 3.3) / 1024;  // convert to volts

	return volts;
}

void recordTime() {
	time2 = micros() / 1000;	// Saves time when music was heard
	digitalWrite(led, HIGH);

	//prints time(ms) = time2 - time1
	Serial.print(time2 - time1);
	Serial.print("|");
}
