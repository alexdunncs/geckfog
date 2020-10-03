#ifndef SIMPLETIME
#define SIMPLETIME

#include <stdint.h>

class SimpleTime {
  uint8_t hour;
  uint8_t minute;
  uint8_t second;

  bool overflowed = false;

public:
  void print();
  bool isOverflowed();
  void resetOverflow();

  SimpleTime(int hour, int minute, int second);

  bool operator==(const SimpleTime& other);
  bool operator<(const SimpleTime& other);
  bool operator>(const SimpleTime& other);
  bool operator<=(const SimpleTime& other);
  bool operator>=(const SimpleTime& other);
  
  SimpleTime operator+(const SimpleTime& other);
};

#endif
