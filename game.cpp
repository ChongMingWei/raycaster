#include "game.h"
#include <cmath>
#include <cstdlib>
#include <iostream>  //debug
#include "raycaster.h"

void Game::Move(int m, int r, float seconds)
{
    playerA += 0.05f * r * seconds * 25.0f;
    playerX += 0.5f * m * sin(playerA) * seconds * 5.0f;
    playerY += 0.5f * m * cos(playerA) * seconds * 5.0f;

    while (playerA < 0) {
        playerA += 2.0f * M_PI;
    }
    while (playerA >= 2.0f * M_PI) {
        playerA -= 2.0f * M_PI;
    }

    if (playerX < 1) {
        playerX = 1.01f;
    } else if (playerX > MAP_X - 2) {
        playerX = MAP_X - 2 - 0.01f;
    }
    if (playerY < 1) {
        playerY = 1.01f;
    } else if (playerY > MAP_Y - 2) {
        playerY = MAP_Y - 2 - 0.01f;
    }
    std::cout << "x: " << playerX << "y: " << playerY << "a: " << playerA
              << std::endl;  // debug
}

Game::Game()
{
    playerX = 0.0f;  // X position 23.03
    playerY = 0.0f;  // Y position 6.8
    playerA = 0.0f;  // Angle(0~2*pi)5.25
}

Game::~Game() {}
