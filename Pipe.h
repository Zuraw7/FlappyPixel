//
// Created by zuraw on 4/9/25.
//

#ifndef PIPE_H
#define PIPE_H

#include "raylib.h"
#include <stdlib.h>

class Pipe {
private:
    int _width, _x, _holeHeight, _holeY;
    Color _color;

public:
    Pipe();
    ~Pipe() = default;
    Pipe(const Pipe& other) = default;
    Pipe& operator=(const Pipe& other) = default;

    int getX() const { return _x; }
    int getWidth() const { return _width; }
    int getHoleY() const { return _holeY; }
    int getHoleHeight() const { return _holeHeight; }

    void drawPipe();
};

#endif //PIPE_H
