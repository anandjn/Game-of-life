/*----Problem 2: Game of Life------
Author : Anand Jain
Email: anandjn505@gmail.com
Date: 10 June 2021
----------------------------------*/

/*----------testing--------
#include <iostream>
#include "cell.h"
#include "test.h"
--------------------------*/

#include "grid.h"


int main() {
  /*----------testing--------
  testCell();
  testgridView();
  testNeighbourCount();
  testNextGen();
  testPrintAliveCoordinates();
  testInputOutput(10, 5);
  --------------------------*/

  //Create a grid of size X
  Grid game_of_life(10);
  //Get N inputs
  game_of_life.input(6);
  //manipulate to next generation
  game_of_life.nextGen();
  //print output
  game_of_life.show();
  game_of_life.printCoordinates();
  
}