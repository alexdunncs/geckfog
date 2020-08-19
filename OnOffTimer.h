#ifndef ONOFFTIMER
#define ONOFFTIMER

class OnOffTimer {
  unsigned long int activeDuration;
  unsigned long int inactiveDuration;
  unsigned long int lastToggle = 0;
  unsigned long int nextToggle = 0;
  bool active = false;

  void toggle();

  public:

  bool isActive();
  void printSchedule();

  OnOffTimer(unsigned long int activeDuration, unsigned long int inactiveDuration);
  OnOffTimer(unsigned long int activeDuration, unsigned long int inactiveDuration, bool initiallyActive);
  
};

#endif
