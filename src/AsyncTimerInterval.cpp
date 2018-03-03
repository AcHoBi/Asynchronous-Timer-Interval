/*---------------------------------------------------------------------------
COPYRIGHT © 2017 by AcHo. All rights reserved.
UNIT eventName:     AsyncTimerInterval.cpp
VERSION:            2.0
SUBSYSTEM:          Arduino
FIRST CREATED:      20-09-2016
CHANGES:            03-01-2017
SOFTWARE ENGINEER:  AcHo
DEPARTMENT:         ---
PROJECT:
CALLS:
ERROR HANDLING:
CODE SIZE:
-----------------------------------------------------------------------------
DESCRIPTION:
Timer intervals
Example:
--------
static unsigned long ulStartTimer = millis();   // start time measurement
... instead of ...
if (millis() - ulStartTimer > x) {
<do something || exit loop by break>
}
-----------------------------------------------------------------------------
CHANGES:
03-01-2017 Description
---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------
  Includes
  ---------------------------------------------------------------------------*/
#include <Arduino.h>
#include <Settings.h>
#include <AsyncTimerInterval.h>

  /*---------------------------------------------------------------------------
	 Class TimeInterval
   ---------------------------------------------------------------------------*/

   /// <summary>Initialize timer event</summary>
   /// <remarks>Timer is activated after first Start()</remarks>
   /// <param name="eventName">Event name "xyz" for debugger output</param>
   /// <param name="interval">Interval in ms</param>
   /// <returns>The method returns void</returns>
AsyncTimerInterval::AsyncTimerInterval(char *eventName, unsigned long interval) {
	DBG_TRACE();
	strcpy(_eventName, eventName);
	_interval = interval;
}

void AsyncTimerInterval::SetInterval(unsigned long interval) {
	DBG_TRACE();
	_interval = interval;
}

void AsyncTimerInterval::Start() {  // starts or ret
	DBG_TRACE();
	_startTimer = millis();
}

bool AsyncTimerInterval::Event() {
	bool ret = false;

	if (_eventCounter <= 0) {
		_startTimer = millis();
		_eventCounter++;
		/*---------------------------------------------------------------------------*/
		DBG_TRACE(String(_eventName) + " " + String(_interval) + "ms");
		/*---------------------------------------------------------------------------*/
		ret = true;
	}

	if ((millis() - _startTimer) > _interval) {
		_startTimer = millis();
		_eventCounter++;
		/*---------------------------------------------------------------------------*/
		DBG_TRACE(String(_eventName) + " " + String(_interval) + "ms");
		/*---------------------------------------------------------------------------*/
		ret = true;
	}
	return ret;
}

bool AsyncTimerInterval::EventByDevider(unsigned int eventDevider) {
	bool ret = false;

	if (_eventCounter <= 0) {
		_startTimer = millis();
		_eventCounter++;
	}

	if (_eventCounter % eventDevider == 0) {
		ret = true;
		/*---------------------------------------------------------------------------*/
		DBG_TRACE(String(_eventName) + " " + String(_interval) + "ms * " + String(eventDevider));
		/*---------------------------------------------------------------------------*/
	}
	return ret;
}

bool AsyncTimerInterval::FirstTime() {
	bool ret = false;
	if ((_eventCounter == 1) and _bFirstTime) {
		_bFirstTime = false;
		ret = true;
		/*---------------------------------------------------------------------------*/
		DBG_TRACE(String(_eventName) + " " + String(_interval) + "ms");
		/*---------------------------------------------------------------------------*/
	}
	return ret;
}

unsigned long AsyncTimerInterval::ElapsedTime() {
	DBG_TRACE();
	return (_startTimer - millis());
}

unsigned long AsyncTimerInterval::RemainingTime() {
	DBG_TRACE();
	return (millis() - _startTimer);
}

unsigned long AsyncTimerInterval::EventCounter() {
	DBG_TRACE();
	return _eventCounter;
}

/*---------------------------------------------------------------------------
  Class TimerInterval
  ---------------------------------------------------------------------------*/

