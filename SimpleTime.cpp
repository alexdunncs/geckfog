#include "SimpleTime.h"
#include <Arduino.h>

void SimpleTime::print() {
  String str = "";
  str += this->hour;
  str += ":";
  str += this->minute;
  str += ":";
  str += this->second;

  Serial.print(str);
}


bool SimpleTime::isOverflowed(){
  return this->overflowed;
}

void SimpleTime::resetOverflow(){
  this->overflowed = false;
}

SimpleTime::SimpleTime(int hour, int minute, int second) {
  if (second >= 60) {
    minute += second / 60;
    second = second % 60;
  }
  
  if (minute >= 60) {
    hour += minute / 60;
    minute = minute % 60;
  }

  if (hour >= 24) {
    hour = hour % 24;
    this->overflowed = true;
  }

  this->second = second;
  this->minute = minute;
  this->hour = hour;
}

bool SimpleTime::operator==(const SimpleTime& other){
  return this->hour == other.hour
  && this->minute == other.minute
  && this->second == other.second;
};

bool SimpleTime::operator<(const SimpleTime& other){
  return this->hour < other.hour
  || this->hour == other.hour && this->minute < other.minute
  || this->hour == other.hour && this->minute == other.minute && this->second < other.second;  
};

bool SimpleTime::operator>(const SimpleTime& other){
  return !(*this == other || *this < other);
};

bool SimpleTime::operator<=(const SimpleTime& other){
  return *this < other || *this == other;  
};

bool SimpleTime::operator>=(const SimpleTime& other){
  return *this > other || *this == other;  
};

SimpleTime SimpleTime::operator+(const SimpleTime& other){
  return SimpleTime(this->hour + other.hour, this->minute + other.minute, this->second + other.second);   
};
