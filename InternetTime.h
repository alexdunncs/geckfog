#ifndef INTERNETTIME
#define INTERNETTIME

#include <ESP8266HTTPClient.h>

#include "SimpleTime.h"

namespace InternetTime {
    String getUtcString();
    SimpleTime getSimpleTime();
}

#endif
