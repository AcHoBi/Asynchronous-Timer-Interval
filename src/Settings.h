// Include guard
#pragma once

/*---------------------------------------------------------------------------
  Includes
  ---------------------------------------------------------------------------*/
#include <Arduino.h>

/*---------------------------------------------------------------------------
  Defines
  ---------------------------------------------------------------------------*/


/*---------------------------------------------------------------------------
  Templates
  ---------------------------------------------------------------------------*/



/*---------------------------------------------------------------------------
  Option switches: Enable serial debugger
  #define LEVEL_TRACE     "TRACE   "
  #define LEVEL_INFO      "INFO    "
  #define LEVEL_WARNING   "WARNING "
  #define LEVEL_CRITICAL  "CRITICAL"
  #define LEVEL_ERROR     "ERROR   "

  // #define DBG(...) Serial.println(__DATE__ ", " __TIME__ ", " __VERSION__ ", " __FILE__ ", " + String(__PRETTY_FUNCTION__) + ", " __VA_ARGS__)
  #define DBG(errLevel, ...) Serial.println(String(errLevel) + ": " + String(__PRETTY_FUNCTION__) + " " __VA_ARGS__)
  #else
  #define DBG(...)
  #endif
  ---------------------------------------------------------------------------*/
#define DEBUG
// #define DBG_LEVEL_ALL
// #define DBG_LEVEL_TRACE
#define DBG_LEVEL_INFO
#define DBG_LEVEL_WARNING
#define DBG_LEVEL_CRITICAL
#define DBG_LEVEL_ERROR

#ifdef DEBUG
#define DEBUG_SERIAL_BAUDRATE 115200

#ifdef DBG_LEVEL_ALL
#define DBG_ALL(...) Serial.print("ALL      " + String(__PRETTY_FUNCTION__) + " "); Serial.println(__VA_ARGS__);
#else
#define DBG_ALL(...)
#endif

#ifdef DBG_LEVEL_TRACE
#define DBG_TRACE(...) Serial.print("TRACE    " + String(__PRETTY_FUNCTION__) + " "); Serial.println(__VA_ARGS__);
#else
#define DBG_TRACE(...)
#endif

#ifdef DBG_LEVEL_INFO
#define DBG_INFO(...) Serial.print("INFO     " + String(__PRETTY_FUNCTION__) + " "); Serial.println(__VA_ARGS__);
#else
#define DBG_INFO(...)
#endif

#ifdef DBG_LEVEL_WARNING
#define DBG_WARNING(...) Serial.print("WARNING  " + String(__PRETTY_FUNCTION__) + " "); Serial.println(__VA_ARGS__);
#else
#define DBG_WARNING(...)
#endif

#ifdef DBG_LEVEL_CRITICAL
#define DBG_CRITICAL(...) Serial.print("CRITICAL " + String(__PRETTY_FUNCTION__) + " "); Serial.println(__VA_ARGS__);
#else
#define DBG_CRITICAL(...)
#endif

#ifdef DBG_LEVEL_ERROR
#define DBG_ERROR(...) Serial.print("ERROR    " + String(__PRETTY_FUNCTION__) + " "); Serial.println(__VA_ARGS__);
#else
#define DBG_ERROR(...)
#endif

#endif // DEBUG



//int GetFreeRam ()
//{
// extern int __heap_start, *__brkval;
// int v;
// return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
//}
