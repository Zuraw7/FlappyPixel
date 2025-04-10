//
// Created by zuraw on 4/9/25.
//

#include "Pipe.h"

void Pipe::drawPipe() {
    DrawRectangle(_x, 0, _width, _holeY, _color);
    DrawRectangle(_x, (_holeY + _holeHeight), _width, GetScreenHeight() - (_holeY + _holeHeight), _color);
    _x -= 1;
}

Pipe::Pipe() : _color(GREEN) {
    _width = std::rand() % 30 + 50; // Randomize pipes width
    _holeHeight = std::rand() % 50 + 130; // Randomize pipes hole height
    _holeY = std::rand() % (GetScreenHeight() - _holeHeight); // Randomize pipes hole
    _x = GetScreenWidth() + _width; // Spawn pipes outside of view
}