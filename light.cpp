#include "light.h"

Light::Light() {
    init();
}

Light::~Light() {
    delete position;
}

void Light::init() {
    id = GL_LIGHT0;
    position = new QVector3D(0.0f, 0.0f, 0.0f);
    state = draw = false;
}

void Light::update() {
}

void Light::render() {
    GLfloat lightPosition[] = { position->x(), position->y(), position->z(), 0.0 };
    glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);

    //glEnable(GL_LIGHTING);
    glPushMatrix();
        //GLfloat mat_emission[] = {1.0, 1.0, 0.0, 1.0};
        //GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
        //GLfloat mat_shininess[] = { 50.0 };
        //glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
        //glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
        //glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
        glColor4f(1, 1, 0, 1);

        glTranslatef(position->x(), position->y(), position->z());
        GLUquadric * qobj = gluNewQuadric();
        gluSphere(qobj, 0.1f, 50, 50);
        gluDeleteQuadric(qobj);
    glPopMatrix();
    glDisable(GL_LIGHTING);
}

void Light::setPosition(float x, float y, float z) {
    position->setX(x);
    position->setY(y);
    position->setZ(z);
}

void Light::toggle() {
    state = !state;
    if (state) { glEnable(GL_LIGHT0);  }
    else       { glDisable(GL_LIGHT0); }
}

void Light::turnOn() {
    state = true;
    glEnable(GL_LIGHT0);
}

void Light::turnOff() {
    state = false;
    glDisable(GL_LIGHT0);
}
