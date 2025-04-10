//
// Created by zuraw on 4/7/25.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "raylib.h"

class Player {
private:
    int _posX;
    int _posY;
    int _height;
    int _width;
    int _score;

public:
    Player(const int posX, const int posY) : _posX(posX), _posY(posY) {
        _height = 15;
        _width = 15;
        _score = 0;
    }
    Player(const Player &other) = delete;
    Player &operator=(const Player &other) = delete;
    ~Player() = default;

    // Getters
    int getPosX() const { return _posX; }
    int getPosY() const { return _posY; }
    int getHeight() const { return _height; }
    int getWidth() const { return _width; }
    int getScore() const { return _score; }

    // Setters
    void setPosY(int const posY) { _posY = posY; }
    void setScore(int const score) { _score = score; }

    // Methods
    void moving(double &startTime);
    void drawPlayer () const;
    void scoreMechanism (double &scoreTime);
};



#endif //PLAYER_H
