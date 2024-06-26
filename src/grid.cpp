#include "grid.hpp"
#include "raylib.h"

void Grid::Draw()
{
    for(int row = 0; row < rows; row++){
        for(int column = 0; column < columns; column++){
            //If cell is alive set the color to green, else set the color to a light gray.
            Color colorsOfCells = cells[row][column] ? Color{0, 255, 0, 255} : Color{55, 55, 55, 255};
            //Draw the squares/cells, make the cells a bit smaller than cellSize so it doesn't cover up the entire screen giving us "lines" 
            //because we calulated the cellsize in away that it covers the entire screen, so instead of just drawing lines we use this method instead.
            //made it smaller by subtracting by 1
            DrawRectangle(column * cellsize, row * cellsize, cellsize - 1, cellsize - 1, colorsOfCells);
        }
    }
}

void Grid::SetValueOfCells(int row, int column, int value)
{
    //Check if the values are within the grid
    if (isWithinBounds(row, column)){
        cells[row][column] = value;
    }
}

int Grid::GetValueOfCells(int row, int column)
{
    if(isWithinBounds(row, column)){
        return cells[row][column];
    }
    return 0;
}

bool Grid::isWithinBounds(int row, int column)
{
    //Check if the values are within the grid
    if (row >= 0 && row < rows && column >= 0 && column < columns){
        return true;
    }

    return false;
}

void Grid::FillRandomCells()
{
    //Loop through all cells of the grid
    for(int row = 0; rows > row; row++){
        for(int column = 0; columns > column; column++){
            //Using the GetRandomValue of raylib to assign values to random cells
            int randomCellValue = GetRandomValue(0, 4);

            //Apply random values, 
            //only make the cell alive if the random value is 4 giving us approximately 20% alive cells, 80% dead cells
            cells[row][column] = (randomCellValue == 4) ? 1 : 0;
        }
    }
}
