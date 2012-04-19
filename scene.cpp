#include "scene.h"

Scene::Scene() {
    init();
}


Scene::~Scene() {
    delete player;
    delete cube;
    delete light;
}


void Scene::init() {
    player = new Player();
    cube = new Cube();

    light = new Light();
    light->setPosition(2.0f, 2.0f, 2.0f);
    light->draw = true;
}


void Scene::update() {
    cube->update();
    player->update();
    light->update();
}


void Scene::render() {

    light->render();

    glEnable(GL_LIGHTING);
    glPushMatrix();
        //GLfloat mat_emission[] = {1.0, 1.0, 0.0, 1.0};
        //GLfloat mat_specular[] = { 1.0, 1.0, 1.0, 1.0 };
        //GLfloat mat_shininess[] = { 50.0 };
        //glMaterialfv(GL_FRONT, GL_SPECULAR, mat_specular);
        //glMaterialfv(GL_FRONT, GL_SHININESS, mat_shininess);
        //glMaterialfv(GL_FRONT, GL_EMISSION, mat_emission);
        glColor4f(1, 1, 0, 1);

        glTranslatef(-2.0f, 0.0f, 0.0f);
        GLUquadric * qobj = gluNewQuadric();
        gluSphere(qobj, 1, 50, 50);
        gluDeleteQuadric(qobj);
    glPopMatrix();
    glDisable(GL_LIGHTING);

    cube->render();
    player->render();
}
