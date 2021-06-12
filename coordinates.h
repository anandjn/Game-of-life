#ifndef COORDINATES_H
#define COORDINATES_H

class Coordinates {
private:
  
  int x;
  int y;

public: 
  Coordinates();
  Coordinates(int x, int y);
  void setX(int x);
  void setY(int y);
  int getX();
  int getY();
  void show();

};


#endif
