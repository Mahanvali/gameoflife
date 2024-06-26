#include "raylib.h"
#include "simulation.hpp"
#include <iostream>

const int screenWidth = 1200;
const int screenHeight = 600;
const int sizeCell = 3;

Color backgroundColor = {30, 30, 30, 255};
Simulation simulation(screenWidth, screenHeight, sizeCell);

int main(){
    InitWindow(screenWidth, screenHeight, "game of life :)");
    SetTargetFPS(12);
    Simulation simulation(screenWidth, screenHeight, sizeCell);
    while(!WindowShouldClose()){
        simulation.Update();
        BeginDrawing();
            ClearBackground(backgroundColor);
            simulation.Draw();
        EndDrawing();
    }
    CloseWindow();
    return 0;
}
