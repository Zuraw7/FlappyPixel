//
// Created by zuraw on 4/7/25.
//

#include "player.h"

void Player::drawPlayer () const {
    DrawRectangle(_posX, _posY, _width, _height, YELLOW);
}

void Player::moving (double &startTime) {
    double const currentTime = GetTime();
    if (IsKeyDown(KEY_SPACE) && getPosY() > 0 && currentTime - startTime >= 0.01) {
        setPosY(getPosY() - 5);
        startTime = currentTime;
    } else if (currentTime - startTime >= 0.025 && (getPosY() + getHeight()) <= GetScreenHeight()) {
        setPosY(getPosY() + 5);
        startTime = currentTime;
    }
    if (IsKeyPressed(KEY_DOWN) && getPosY() + (getHeight() * 3) < GetScreenHeight()) {
        setPosY(getPosY() + (getHeight() * 3));
        startTime = currentTime;
    }
}

void Player::scoreMechanism (double &scoreTime) {
    if (GetTime() - scoreTime > 0.5) {
        setScore(getScore() + 1);
        scoreTime = GetTime();
    }
}