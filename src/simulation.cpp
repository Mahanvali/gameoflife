#include "simulation.hpp"
#include <vector>
#include <utility>

void Simulation::Draw()
{
    //Draw the simulation
    grid.Draw();
}

void Simulation::Update()
{
    for(int row = 0; grid.getRows() > row; row++){
        for(int column = 0; grid.getColumns() > column; column++){
            // for every cell count its live neighbors
            int liveNeighbors = CountLiveNeighbors(row, column);
            //Value the cell contains, either dead(0) or alive(1)
            int cellValue = grid.GetValueOfCells(row, column);
            //Rule #1, if the cell is alive, it dies when it has fewer than 2 or more than 3 neighbors, else it stays alive
            if(cellValue == 1){
                if(liveNeighbors > 3 || liveNeighbors < 2){
                    //Set the value of the cells to the temporary grid first
                    //Kill the cell
                    temp_grid.SetValueOfCells(row, column, 0);
                } else {
                    //else the cell stays alive
                    temp_grid.SetValueOfCells(row, column, 1);
                }
                //Rule #2, if the cell is dead, it becomes alive if the number of neighboring cells is exactly 3, else it stays dead
            } else if(cellValue == 0){
                if(liveNeighbors == 3){
                    temp_grid.SetValueOfCells(row, column, 1);
                } else {
                    temp_grid.SetValueOfCells(row, column, 0);
                }
            }
        }
    }
    //After we've done all the changes to temp_grid, we can set the temp_grid to grid to apply the changes.
    grid = temp_grid;
}

void Simulation::SetCellValue(int row, int column, int value)
{
    grid.SetValueOfCells(row, column, value);
}

int Simulation::CountLiveNeighbors(int row, int column)
{
    int liveNeighbors = 0;
    std::vector<std::pair<int, int>> neighborOffsets = {
        {-1, 0}, //Above
        {1 , 0}, //Below
        {0, -1}, //Left
        {0, 1}, //Right
        {-1, -1}, //Diagonal Upper Left
        {-1, 1}, //Diagonal Upper Right
        {1, -1}, //Diagonal Lower Left
        {1, 1} //Diagonal Lower Right
    };

    for(const auto& offset : neighborOffsets){
        //Calculate the neighbor rows in a way that even if the neighbor is off the grid, it warps around the screen so right goes to left, left to right, bottom to top, top to bottom
        int neighborRow = (row + offset.first + grid.getRows()) % grid.getRows();
        // Do the same to the columns
        int neighborColumn = (column + offset.second + grid.getColumns()) % grid.getColumns();
        liveNeighbors += grid.GetValueOfCells(neighborRow, neighborColumn);
    }
    return liveNeighbors;
}
