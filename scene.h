#ifndef SCENE_H
#define SCENE_H

#include "player.h"
#include "cube.h"
#include "light.h"

class Scene
{
public:
    Scene();
    ~Scene();
    void init();
    void update();
    void render();

    Player * player;
    Cube * cube;
    Light * light;
};

#endif // SCENE_H
