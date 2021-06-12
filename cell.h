#ifndef CELL_H
#define CELL_H

#include "coordinates.h"

class Cell:public Coordinates{
private:
  bool life_state;
  int neighbour_count;
  
public:
  Cell();
  Cell(int x, int y);
  int getNeighbourCount();
  void setNeighbourCount(int count);
  void birth();
  void death();
  bool isAlive();
  void summary();
};
#endif