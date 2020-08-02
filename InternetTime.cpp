#include <ArduinoJson.h>

#include "InternetTime.h"

String InternetTime::getUtcString() {
    const char* TIME_SERVER_URL = "http://worldtimeapi.org/api/ip";
    
    HTTPClient http;
    
    http.begin(TIME_SERVER_URL);
    int responseCode = http.GET();

    StaticJsonDocument<256> response;
    deserializeJson(response, http.getString());
    String payload = http.getString();
    return response["datetime"];
}
