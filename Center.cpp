#include "Center.h"
#include <iostream>

Center::Center(){
  delete (*this).name;
  delete (*this).head;
  delete (*this).tail;
}

void Center::heal(){
  
}
