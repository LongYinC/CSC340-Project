#ifndef NURSERY_H
#define NURSERY_H

#include "Buildings.h"

class Nursery : public Building {
public:
  Nursery();
  ~Nursery();
  void napTime();
};

#endif
