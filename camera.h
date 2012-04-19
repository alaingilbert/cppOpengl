#ifndef CAMERA_H
#define CAMERA_H

#include <QtOpenGL>
#include <QVector3D>

class Camera
{

public:
    Camera();
    Camera(QVector3D *position);
    ~Camera();
    void init();
    void update();
    void perspectiveProjection();
    void viewport(float width, float height);

    float clipNear;
    float clipFar;
    float fieldOfView;
    float aspectRatio;
    QVector3D * position;
    QVector3D * focus;
    float viewportWidth;
    float viewportHeight;
    float pitch;
    float yaw;
    float roll;
};

#endif // CAMERA_H
