//
// Created by zuraw on 4/8/25.
//

#ifndef SCENE_H
#define SCENE_H

#include "player.h"

class Scene {
public:
    Scene() = default;
    ~Scene() = default;
    Scene(const Scene& other) = default;
    Scene& operator= (const Scene& other) = default;

    void startWindow() const;
    void renderScore (Player *player) const;
    void drawPlayer (Player *player) const;

};



#endif //SCENE_H
