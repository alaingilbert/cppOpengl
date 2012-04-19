#ifndef CUBE_H
#define CUBE_H

#include <QVector3D>
#include <QtOpenGL>

class Cube
{
public:
    Cube();
    ~Cube();
    void init();
    void update();
    void render();

    QVector3D * position;
    GLuint texture;
};

#endif // CUBE_H
