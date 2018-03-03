#include <Settings.h>
#include <AsyncTimerInterval.h>

#define DEBUG_SERIAL_BAUDRATE 115200

/*---------------------------------------------------------------------------
Timer intervals
Example:
--------
static unsigned long ulStartTimer = millis();   // start time measurement
... instead of ...
if (millis() - ulStartTimer > x) {
<do something || exit loop by break>
}
---------------------------------------------------------------------------*/
#define BLINK_INTERVAL  10000L		// Interval in ms
#define BLINK_EVENT_DEVIDER 3		// Interval SubEvent

AsyncTimerInterval BlinkInterval("BlinkTimer", BLINK_INTERVAL);
/*---------------------------------------------------------------------------*/

void setup()
{
	// Configure serial interfaces
	Serial.begin(DEBUG_SERIAL_BAUDRATE);
	// give the serial interface a second to initialize:
	while (!Serial) {}
}

void loop()
{
	if (BlinkInterval.FirstTime()) {
		Serial.println("Event FirstTime, perform firt measurement");
	}

	if (BlinkInterval.Event()) {
		Serial.print("Event, perform next measurement ");
		Serial.println(BlinkInterval.EventCounter());

		if (BlinkInterval.EventByDevider(BLINK_EVENT_DEVIDER)) {
			Serial.print("Event ");
			Serial.print(BlinkInterval.EventCounter());
			Serial.print(" from Event devider for every ");
			Serial.print(BLINK_EVENT_DEVIDER);
			Serial.println(". Event, put results to webservice");
		}
	}
}
