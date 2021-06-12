#include <iostream>
#include "test.h"

void testCell(){
  std::cout<<"Cell A"<<std::endl;
  Cell cellA(5,6);
  cellA.summary();

  std::cout<<"Cell B"<<std::endl;
  Cell cellB(0,0);
  cellB.birth();
  cellB.summary();
}

void testgridView(){
  std::cout<<"Grid of size 10X10"<<std::endl;
  Grid test_grid1(10);
  test_grid1.show();

  std::cout<<"Grid of size 5X5"<<std::endl;
  Grid test_grid2(5);
  test_grid2.show();

  std::cout<<"Grid of size 3X3"<<std::endl;
  Grid test_grid3(3);
  test_grid3.show();

}

void testNeighbourCount(){
  std::cout<<"Creating grid of 10X10"<<std::endl;
  Grid test_grid1(10);
  std::cout<<"Adding Cells at (2,3), (3,3), (4,3), (3,5), (5,3)"<<std::endl;
  test_grid1.addCell(2, 3);
  test_grid1.addCell(3, 3);
  test_grid1.addCell(4, 3);
  test_grid1.addCell(3, 5);
  test_grid1.addCell(5, 3);
  std::cout<<"No. of neighbours (2,3) has : "<<test_grid1.testingNeighbourCount(2,3)<<std::endl;
  std::cout<<"No. of neighbours (3,3) has : "<<test_grid1.testingNeighbourCount(3,3)<<std::endl;
  std::cout<<"No. of neighbours (4,3) has : "<<test_grid1.testingNeighbourCount(4,3)<<std::endl;
  std::cout<<"No. of neighbours (3,5) has : "<<test_grid1.testingNeighbourCount(3,5)<<std::endl;
  std::cout<<"No. of neighbours (5,3) has : "<<test_grid1.testingNeighbourCount(5,3)<<std::endl;

  //testing corner cases
  std::cout<<"Testing corner cases (0,0), (9,9), (0,5) (9,1)"<<std::endl;
  test_grid1.addCell(0, 0);
  test_grid1.addCell(9, 9);
  test_grid1.addCell(0, 5);
  test_grid1.addCell(9, 1);
  std::cout<<"No. of neighbours (0,0) has : "<<test_grid1.testingNeighbourCount(0,0)<<std::endl;
  std::cout<<"No. of neighbours (9,9) has : "<<test_grid1.testingNeighbourCount(9,9)<<std::endl;
  std::cout<<"No. of neighbours (0,5) has : "<<test_grid1.testingNeighbourCount(0,5)<<std::endl;
  std::cout<<"No. of neighbours (9,1) has : "<<test_grid1.testingNeighbourCount(9,1)<<std::endl;

  std::cout<<"Printing Grid"<<std::endl;
  test_grid1.show();
}

void testNextGen(){
  //Input A: (Block pattern - Still life)
  std::cout<<"Input A: (Block pattern - Still life)"<<std::endl;
  Grid block(6);
  block.addCell(1,1);
  block.addCell(1,2);
  block.addCell(2,1);
  block.addCell(2,2);
  block.updateNeighbours();
  std::cout<<"Before"<<std::endl;  
  block.show();
  std::cout<<"After"<<std::endl;
  block.nextGen();
  block.show();

  //Input B : (Boat pattern - Still life)
  std::cout<<"Input A: (Block pattern - Still life)"<<std::endl;
  Grid boat(6);
  boat.addCell(0,1);
  boat.addCell(1,0);
  boat.addCell(2,1);
  boat.addCell(0,2);
  boat.addCell(1,2);
  boat.updateNeighbours();
  std::cout<<"Before"<<std::endl;  
  boat.show();
  std::cout<<"After"<<std::endl;
  boat.nextGen();
  boat.show();

  //Input C (Blinker pattern - oscillator)
  std::cout<<"Input C (Blinker pattern - oscillator)"<<std::endl;
  Grid blink(6);
  blink.addCell(1,1);
  blink.addCell(1,0);
  blink.addCell(1,2);
  blink.updateNeighbours();
  std::cout<<"Before"<<std::endl; 
  blink.show();
  std::cout<<"After"<<std::endl;
  blink.nextGen();
  blink.show();
 
  //Input D : (Toad pattern - two phase oscillator)
  std::cout<<"Input D : (Toad pattern - two phase oscillator"<<std::endl;
  Grid toad(6);
  toad.addCell(1,1);
  toad.addCell(1,2);
  toad.addCell(1,3);
  toad.addCell(2,2);
  toad.addCell(2,3);
  toad.addCell(2,4);
  toad.updateNeighbours();
  std::cout<<"Before"<<std::endl; 
  toad.show();
  std::cout<<"After"<<std::endl;
  toad.nextGen();
  toad.show();

}

void testPrintAliveCoordinates(){
  //Input D : (Toad pattern - two phase oscillator)
  std::cout<<"Input D : (Toad pattern - two phase oscillator"<<std::endl;
  Grid toad(6);
  toad.addCell(1,1);
  toad.addCell(1,2);
  toad.addCell(1,3);
  toad.addCell(2,2);
  toad.addCell(2,3);
  toad.addCell(2,4);
  toad.updateNeighbours();
  std::cout<<"Before"<<std::endl; 
  toad.show();
  std::cout<<"After"<<std::endl;
  toad.nextGen();
  toad.show();
  toad.printCoordinates();
}

void testInputOutput(int gridSize, int num_of_inputs){
  Grid testGrid(gridSize);
  testGrid.input(num_of_inputs);
  testGrid.show();
  testGrid.printCoordinates();
}