#pragma once
#include <vector>

class Grid{
    public:
        Grid(int width, int height, int cellsize): 
            rows(height/cellsize), 
            columns(width/cellsize), 
            cellsize(cellsize), 
            cells(rows, std::vector<int>(columns, 0)) {};
        void Draw();
        void SetValueOfCells(int row, int column, int value);
        int GetValueOfCells(int row, int column);
        bool isWithinBounds(int row, int column);
        //total rows
        int getRows() {return rows;}
        //total columns
        int getColumns() {return columns;}
        //Set random cells to be alive, so that we can run the simulation because otherwise our simulation would be empty.
        void FillRandomCells();
    private:
        int rows;
        int columns;
        int cellsize;
        std::vector<std::vector<int>> cells;
};