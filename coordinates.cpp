#include <iostream>
#include "coordinates.h"

Coordinates::Coordinates(){
  this->x = 0;
  this->y = 0;
}

Coordinates::Coordinates(int x, int y){
  this->x = x;
  this->y = y;
}

void Coordinates::setX(int x){
  this->x = x;
}
void Coordinates::setY(int y){
  this->y = y;
}

int Coordinates::getX(){
  return this->x;
}
int Coordinates::getY(){
  return this->y;
}

void Coordinates::show(){
  std::cout<< "(" << this->x << ", " << this->y << ")" << std::endl;
}
