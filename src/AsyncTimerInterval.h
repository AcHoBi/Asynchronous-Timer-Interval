// Include guard
#pragma once

/*---------------------------------------------------------------------------
  Includes
  ---------------------------------------------------------------------------*/
#include <Arduino.h>

  /*---------------------------------------------------------------------------
	Defines
	---------------------------------------------------------------------------*/

class AsyncTimerInterval
{
public:
	AsyncTimerInterval(char *eventName, unsigned long interval);
	// void Open(unsigned long interval);  
	void SetInterval(unsigned long interval);
	void Start(); // starts or retriggers timer	
	bool Event();
	bool EventByDevider(unsigned int eventDevider);
	bool FirstTime();
	/// <summary>ElapsedTime</summary>
	unsigned long ElapsedTime();
	unsigned long RemainingTime();
	unsigned long EventCounter();

private:
	///<summary>Store for the _eventName property</summary>
	char _eventName[16];
	///<summary>Store for the _interval property</summary>
	unsigned long _interval = 0;
	///<summary>Store for the _startTimer property</summary>
	unsigned long _startTimer = 0;
	///<summary>Store for the _eventCounter property</summary>
	unsigned long _eventCounter = 0;
	///<summary>Store for the _bFirstTime event property</summary>
	bool _bFirstTime = true;
};

