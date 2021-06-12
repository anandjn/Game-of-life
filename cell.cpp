#include <iostream>
#include "cell.h"

Cell::Cell():
Coordinates(){
  neighbour_count = 0;
  life_state = false;
}

Cell::Cell(int x, int y):
Coordinates(x, y){
  neighbour_count = 0;
  life_state = false;
}

int Cell::getNeighbourCount(){
  return neighbour_count;
}

void Cell::setNeighbourCount(int count){
  this->neighbour_count = count;
}
void Cell::birth(){
  life_state = true;
}

void Cell::death(){
  life_state = false;
}

bool Cell::isAlive(){
  return life_state;
}

void Cell::summary(){
  std::string Health = isAlive() ? "Alive" : "Dead";
  std::cout<<"Cell is "<<Health<<" at ("<<getX()<<", "<<getY()<<")"<<std::endl;
}
