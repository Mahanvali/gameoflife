#pragma once
#include "grid.hpp"

class Simulation{
    public:
        Simulation(int width, int height, int cellsize):
            grid(width, height, cellsize), temp_grid(width, height, cellsize) {grid.FillRandomCells();};
        void Draw();
        void Update();
        void SetCellValue(int row, int column, int value);
        int CountLiveNeighbors(int row, int column);
    private:
        Grid grid;
        //Temporary grid in which we use to appy to the real grid, this is just an easier implementation to achieve the simulation
        Grid temp_grid;
};