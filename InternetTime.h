#ifndef INTERNETTIME
#define INTERNETTIME

#include <ESP8266HTTPClient.h>

namespace InternetTime {
    String getUtcString();
}

#endif
