#ifndef PLAYER_H
#define PLAYER_H

#include <QVector3D>
#include "camera.h"

class Player
{
public:
    Player();
    ~Player();
    void init();
    void update();
    void render();
    void moveLeft(int dt);
    void moveRight(int dt);
    void moveForward(int dt);
    void moveBackward(int dt);
    void moveUp(int dt);
    void moveDown(int dt);
    void rotateLeft(int dt);
    void rotateRight(int dt);

    Camera * camera;
    QVector3D * position;
    QVector3D * rotation;
    float velocity;
};

#endif // PLAYER_H
