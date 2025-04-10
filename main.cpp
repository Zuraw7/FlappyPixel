#include <iostream>
#include "raylib.h"
#include "player.h"
#include "Scene.h"
#include "Pipe.h"
#include <cstdlib>
#include <ctime>
#include <deque>

void gameLoop(Scene const *scene);
void renderPipes(std::deque<Pipe>& pipes, double& pipeTime);
int collisionDetection(Player const *player, std::deque<Pipe> const &pipes);

int main() {
    auto const scene = new Scene();

    scene->startWindow();

    gameLoop(scene);

    delete scene;

    return 0;
}

void gameLoop(Scene const *scene) {
    while (!WindowShouldClose()) {
        auto *player = new Player(80, 280);
        std::srand(std::time(nullptr));
        std::deque<Pipe> pipes;

        double startTime = GetTime();
        double scoreTime = GetTime();
        double pipeTime = GetTime();

        // Game itself
        while (true) {
            BeginDrawing();
            ClearBackground(SKYBLUE);

            renderPipes(pipes, pipeTime);
            scene->drawPlayer(player);
            scene->renderScore(player);

            player->moving(startTime);
            player->scoreMechanism(scoreTime);

            if (collisionDetection(player, pipes) == 1) {
                EndDrawing();
                break;
            }
            EndDrawing();
        }

        // Death menu
        std::string scoreText = "Score: " + std::to_string(player->getScore());
        delete player;
        while (!IsKeyPressed(KEY_P) && !WindowShouldClose()) {
            BeginDrawing();
            ClearBackground(SKYBLUE);

            DrawText("You died!", GetScreenWidth() / 2 - 80, 200, 20, RED);
            DrawText("Press P to play again!", GetScreenWidth() / 2 - 140, 280, 20, RED);
            DrawText(scoreText.c_str(), GetScreenWidth() / 2 - 80, 320, 20, RED);

            EndDrawing();
        }
    }
    CloseWindow();
}

void renderPipes(std::deque<Pipe>& pipes, double& pipeTime) {
    if (GetTime() - pipeTime > 1.5) {
        pipes.emplace_back();
        pipeTime = GetTime();
    }
    if (!pipes.empty() && pipes[0].getX() < 0 - pipes[0].getWidth()) {
        pipes.pop_front();
    }
    for (auto& pipe : pipes) {
        pipe.drawPipe();
    }
}


int collisionDetection(Player const *player, std::deque<Pipe> const &pipes) {

    for (auto pipe : pipes) {
        // check if player is in pipe's X coordinates
        if (player->getPosX() + (player->getWidth()) > pipe.getX() &&
            player->getPosX() < (pipe.getX() + pipe.getWidth())) {
            // check if players is not in pipes hole
            if (player->getPosY() - (player->getHeight() / 2) <= pipe.getHoleY() ||
                player->getPosY() + (player->getHeight() / 2) >= pipe.getHoleY() + pipe.getHoleHeight()) {
                return 1;
                }
            // break loop to prevent from checking next pipes (we need just one pipe)
            break;
            }
    }
    return 0;
}