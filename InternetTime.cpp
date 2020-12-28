#include <ArduinoJson.h>

#include "InternetTime.h"

String InternetTime::getUtcString() {
    const char* TIME_SERVER_URL = "http://worldclockapi.com/api/json/pst/now";
    
    HTTPClient http;
    
    http.begin(TIME_SERVER_URL);
    int responseCode = http.GET();
    String payload = http.getString();
    
    StaticJsonDocument<256> response;
    deserializeJson(response, payload);
//    String dateString = response["currentDateTime"];
    return response["currentDateTime"];
}

SimpleTime InternetTime::getSimpleTime() {
  String timeStr = InternetTime::getUtcString();
  uint8_t hour = timeStr.substring(11,13).toInt();
  uint8_t minute = timeStr.substring(14,16).toInt();
  uint8_t second = timeStr.substring(17,19).toInt();
  
  return SimpleTime(hour, minute, second);
}
