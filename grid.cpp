#include <iostream>
#include <sstream>
#include "grid.h"
#include "cell.h"

Grid::Grid(int size){
  this->size = size;
  this->graph = new Cell *[this->size];
  for(int i = 0; i < this->size; i++){
    this->graph[i] = new Cell[this->size];
    for(int j=0; j< this->size; j++){
      this->graph[i][j].setX(i);
      this->graph[i][j].setY(j);
    } 
  }
}

Grid::~Grid(){
  for(int i = 0; i < this->size; i++){
    delete[] this->graph[i];
    // std::cout<<"Desctruction"<<std::endl;
  }
  delete[] this->graph;
  // std::cout<<"Complete Desctruction"<<std::endl;
}

void Grid::addCell(int x, int y){
  this->graph[x][y].birth();
}

void Grid::updateNeighbours(){
  //calculate neighbours count for each cell and update them
  for (int i = 0; i < this->size; i++){
    for (int j = 0; j< this->size; j++){
      Cell *current_cell = &this->graph[i][j];
      int neighbourCount = countNeighbours(*current_cell);
      current_cell->setNeighbourCount(neighbourCount);
    }
  }
}

void Grid::nextGen(){
  //Creates next generation based on current generation
  for (int i = 0; i < this->size; i++){
    for (int j = 0; j< this->size; j++){
      Cell *current_cell = &this->graph[i][j];
      
      //#1. Any live cell with fewer than two live neighbours dies, as if by loneliness.
      if (current_cell->isAlive() && current_cell->getNeighbourCount() < 2){
        current_cell->death();
        continue;
      }
      //#2. Any live cell with more than three live neighbours dies, as if by overcrowding.
      if (current_cell->isAlive() && current_cell->getNeighbourCount() > 3){
        current_cell->death();
        continue;
      }
      //#3. Any live cell with two or three live neighbours lives, unchanged, to the next generation.
      if (current_cell->isAlive() && (current_cell->getNeighbourCount() == 2 || current_cell->getNeighbourCount() == 3)){
        continue;
      }
      //#4. Any dead cell with exactly three live neighbours comes to life.
      if (!current_cell->isAlive() && current_cell->getNeighbourCount() == 3){
        current_cell->birth();
        continue;
      }
    }
  }
  //update new cells with new neighbour count
  updateNeighbours();
}
void Grid::input(int number_of_coordinates){
  //get (number_of_coordinates) coodinates from console in x,y form and those cell to grid
  for(int i=0; i< number_of_coordinates; i++){
    int x,y;
    std::string coordinates;
    std::cin>>coordinates;
    std::stringstream s_stream(coordinates);
    int j = 0;
    while(s_stream.good()){
      std::string substr;
      getline(s_stream, substr, ',');
      if (j==0){
        //first coordinate : x, break if out of bound
        x = std::stoi(substr);
        if(x >= this->size){
          std::cout<<"skipping this coordinate"<<std::endl;
          break;
        }
      }else if (j == 1){
        //second coordinate : y, break if out of bound
        y = std::stoi(substr);
        if(y >= this->size){
          std::cout<<"skipping this coordinate"<<std::endl;
          break;
        }
      }
      j++;
      
    }
  //add cell to grid
  addCell(x,y);
  // std::cout<<"x = "<<x<<" y = "<<y<<std::endl;
  }
  //update new cells with new neighbour count
  updateNeighbours();
} 

void Grid::printCoordinates(){
  //print out all alive cells coordinates
  for (int i = 0; i<this->size; i++){
    for (int j =0; j<this->size; j++){
      Cell *current_cell = &this->graph[i][j];
      if(current_cell->isAlive()){
        std::cout<<i<<", "<<j<<std::endl;
      }
    }
  }
}

void Grid::show(){
  //prints grid with 0th row at bootom
  for (int i =this->size-1; i> -1; i--){
    for (int j = 0; j< this->size; j++){
    std::string Health = this->graph[i][j].isAlive() ? "[@]" : " - ";
    std::cout<<Health;
    }
    std::cout<<std::endl;
  }  
}


//private
int Grid::countNeighbours(Cell current_cell){
  //for current cell count all its alive neighbours, starting from top left.
  int neighbour_count = 0;
  int current_cell_row = current_cell.getX();
  int current_cell_col = current_cell.getY();
  int top_left_cell_row = current_cell_row - 1;
  int top_left_cell_col = current_cell_col - 1;

  for (int i = 0; i< 3; i++){
    for (int j = 0; j<3; j++){
      int current_neighbour_row = top_left_cell_row + i;
      int current_neighbour_col = top_left_cell_col +j;

      //skip if neighbour is out of grid
      if (current_neighbour_row < 0 || current_neighbour_col < 0 || current_neighbour_row > this->size - 1 || current_neighbour_col > this->size - 1) {
        continue;
      }
      //skip if neighbour and curent cell is same
      if (current_neighbour_row == current_cell_row && current_neighbour_col == current_cell_col){
        continue;
      }
      //count alive neighbours
      if (this->graph[current_neighbour_row][current_neighbour_col].isAlive()){
        neighbour_count++;
      }
    }
  }
  return neighbour_count;
}

//testing only
int Grid::testingNeighbourCount(int x, int y){
  Cell *current_cell = &this->graph[x][y];
  return countNeighbours(*current_cell);
}
