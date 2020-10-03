#include <ArduinoJson.h>

#include "InternetTime.h"

String InternetTime::getUtcString() {
    const char* TIME_SERVER_URL = "http://worldtimeapi.org/api/ip";
    
    HTTPClient http;
    
    http.begin(TIME_SERVER_URL);
    int responseCode = http.GET();
    String payload = http.getString();
    
    StaticJsonDocument<256> response;
    deserializeJson(response, payload);
    String dateString = response["datetime"];
    Serial.println(dateString);
    return response["datetime"];
}
