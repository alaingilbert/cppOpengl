#include "camera.h"

Camera::Camera() {
    init();
}

Camera::Camera(QVector3D * position) {
    init();
    this->position = new QVector3D(*position);
}

Camera::~Camera() {
    delete position;
    delete focus;
}

void Camera::init() {
    clipNear = 0.1f;
    clipFar = 1000.0f;
    fieldOfView = 50.0f;
    aspectRatio = 4/3;

    position = new QVector3D(0.0f, 1.0f, 4.0f);
    focus = new QVector3D(0.0f, 1.0f, 0.0f);

    pitch = yaw = roll = 0.0f;
}


void Camera::update() {
    perspectiveProjection();

    glRotatef(pitch, 1.0f, 0.0f, 0.0f);
    glRotatef(yaw,   0.0f, 1.0f, 0.0f);
    glRotatef(roll,  0.0f, 0.0f, 1.0f);

    glMatrixMode(GL_MODELVIEW);
}


void Camera::perspectiveProjection() {

    glMatrixMode(GL_PROJECTION);
    //glPushMatrix();
    glLoadIdentity();

    gluPerspective(
        fieldOfView,
        aspectRatio,
        clipNear,
        clipFar
    );

    gluLookAt(
        position->x(),
        position->y(),
        position->z(),
        focus->x(),
        focus->y(),
        focus->z(),
        0,1,0
    );
    //glPopMatrix();
}


void Camera::viewport(float width, float height) {
    viewportWidth = width;
    viewportHeight = height;
    glViewport(0,0,viewportWidth,viewportHeight);
    aspectRatio = viewportWidth/viewportHeight;
}
