#ifndef GYMLEADER_H
#define GYMLEADER_H

#include "Trainer.h"

class GymLeader : public Trainer {
public:
  GymLeader();
  ~GymLeader();
  GymLeader(std::string name, Pokemon* pokemon);
  void someAbstractMethod();
};

#endif
