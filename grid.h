#ifndef GRID_H
#define GRID_H
#include "cell.h"

class Grid{
private:
  int size;
  Cell **graph;
  int countNeighbours(Cell current_cell);
  
public:
  Grid(int size);
  ~Grid();
  void addCell(int x, int y);
  void updateNeighbours();
  void nextGen();
  
  void input(int number_of_coordinates);
  void printCoordinates();
  void show();
  


  //testing only
  int testingNeighbourCount(int x, int y);
private:
  
};

#endif