//
// Created by zuraw on 4/8/25.
//

#include "Scene.h"
#include <string>
#include "player.h"

void Scene::startWindow() const {
    InitWindow(800, 600, "Flappy Pixel");
    SetTargetFPS(144);
}

void Scene::renderScore (Player *player) const {
    std::string const score = std::to_string(player->getScore());

    DrawText("Controls", 30, 10, 20, RED);
    DrawText("SPACE", 30, 30, 20, RED);
    DrawText("Arrow DOWN", 30, 50, 20, RED);

    DrawText("Flappy Pixel", GetScreenWidth() / 2 - 60, 25, 20, RED);
    DrawText(score.c_str(), GetScreenWidth() / 2, 55, 20, RED);
}

void Scene::drawPlayer (Player *player) const {
    player->drawPlayer();
}