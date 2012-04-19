#ifndef LIGHT_H
#define LIGHT_H

#include <QtOpenGL>
#include <QVector3D>

class Light
{
public:
    Light();
    ~Light();
    void init();
    void update();
    void render();
    void setPosition(float x, float y, float z);
    void toggle();
    void turnOn();
    void turnOff();

    GLuint id;
    QVector3D * position;
    bool state;
    bool draw;
};

#endif // LIGHT_H
