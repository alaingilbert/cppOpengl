#include "cube.h"

Cube::Cube() {
    init();
}


Cube::~Cube() {
    delete position;
}


void Cube::init() {
    position = new QVector3D(0.0f, 0.0f, 0.0f);

    QImage image(":/ressources/textures.png");
    image = image.convertToFormat(QImage::Format_ARGB32);
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glPixelStorei(GL_UNPACK_ALIGNMENT, 1);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, image.width(), image.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image.bits());
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
    //glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_DECAL);
}


void Cube::update() {
}


void Cube::render() {
    glMatrixMode(GL_MODELVIEW);
    glEnable(GL_TEXTURE_2D);
    glEnable(GL_LIGHTING);
    glPushMatrix();

    //GLfloat whiteSpecularMaterial[] = {1.0, 1.0, 1.0};
    //glMaterialfv(GL_FRONT, GL_SPECULAR, whiteSpecularMaterial);
    //glMaterialfv( GL_FRONT, GL_EMISSION,

    glBindTexture(GL_TEXTURE_2D, texture);
    glColor3f(1.0f, 1.0f, 1.0f);
    glBegin(GL_QUADS);
        // Face
        glTexCoord2f(0.0f,       0.0f);       glNormal3f(-1.0f, -1.0f,  1.0f); glVertex3f( 0.0f,  0.0f,  1.0f);
        glTexCoord2f(1.0f/16.0f, 0.0f);       glNormal3f( 1.0f, -1.0f,  1.0f); glVertex3f( 1.0f,  0.0f,  1.0f);
        glTexCoord2f(1.0f/16.0f, 1.0f/16.0f); glNormal3f( 1.0f,  1.0f,  1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
        glTexCoord2f(0.0f,       1.0f/16.0f); glNormal3f(-1.0f,  1.0f,  1.0f); glVertex3f( 0.0f,  1.0f,  1.0f);
        // Left
        glTexCoord2f(0.0f,       0.0f);       glNormal3f(-1.0f,  1.0f,  1.0f); glVertex3f( 0.0f,  1.0f,  1.0f);
        glTexCoord2f(1.0f/16.0f, 0.0f);       glNormal3f(-1.0f,  1.0f, -1.0f); glVertex3f( 0.0f,  1.0f,  0.0f);
        glTexCoord2f(1.0f/16.0f, 1.0f/16.0f); glNormal3f(-1.0f, -1.0f, -1.0f); glVertex3f( 0.0f,  0.0f,  0.0f);
        glTexCoord2f(0.0f,       1.0f/16.0f); glNormal3f(-1.0f, -1.0f,  1.0f); glVertex3f( 0.0f,  0.0f,  1.0f);
        // Back
        glTexCoord2f(0.0f,       0.0f);       glNormal3f(-1.0f, -1.0f, -1.0f); glVertex3f( 0.0f,  0.0f,  0.0f);
        glTexCoord2f(1.0f/16.0f, 0.0f);       glNormal3f(-1.0f,  1.0f, -1.0f); glVertex3f( 0.0f,  1.0f,  0.0f);
        glTexCoord2f(1.0f/16.0f, 1.0f/16.0f); glNormal3f( 1.0f,  1.0f, -1.0f); glVertex3f( 1.0f,  1.0f,  0.0f);
        glTexCoord2f(0.0f,       1.0f/16.0f); glNormal3f( 1.0f, -1.0f, -1.0f); glVertex3f( 1.0f,  0.0f,  0.0f);
        // Right
        glTexCoord2f(0.0f,       0.0f);       glNormal3f( 1.0f,  1.0f,  1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
        glTexCoord2f(1.0f/16.0f, 0.0f);       glNormal3f( 1.0f, -1.0f,  1.0f); glVertex3f( 1.0f,  0.0f,  1.0f);
        glTexCoord2f(1.0f/16.0f, 1.0f/16.0f); glNormal3f( 1.0f, -1.0f, -1.0f); glVertex3f( 1.0f,  0.0f,  0.0f);
        glTexCoord2f(0.0f,       1.0f/16.0f); glNormal3f( 1.0f,  1.0f, -1.0f); glVertex3f( 1.0f,  1.0f,  0.0f);
        // Top
        glTexCoord2f(0.0f,       0.0f);       glNormal3f(-1.0f,  1.0f, -1.0f); glVertex3f( 0.0f,  1.0f,  0.0f);
        glTexCoord2f(1.0f/16.0f, 0.0f);       glNormal3f(-1.0f,  1.0f,  1.0f); glVertex3f( 0.0f,  1.0f,  1.0f);
        glTexCoord2f(1.0f/16.0f, 1.0f/16.0f); glNormal3f( 1.0f,  1.0f,  1.0f); glVertex3f( 1.0f,  1.0f,  1.0f);
        glTexCoord2f(0.0f,       1.0f/16.0f); glNormal3f( 1.0f,  1.0f, -1.0f); glVertex3f( 1.0f,  1.0f,  0.0f);
        // Floor
        glTexCoord2f(0.0f,       0.0f);       glNormal3f(-1.0f, -1.0f, -1.0f); glVertex3f( 0.0f,  0.0f,  0.0f);
        glTexCoord2f(1.0f/16.0f, 0.0f);       glNormal3f( 1.0f, -1.0f, -1.0f); glVertex3f( 1.0f,  0.0f,  0.0f);
        glTexCoord2f(1.0f/16.0f, 1.0f/16.0f); glNormal3f( 1.0f, -1.0f,  1.0f); glVertex3f( 1.0f,  0.0f,  1.0f);
        glTexCoord2f(0.0f,       1.0f/16.0f); glNormal3f(-1.0f, -1.0f,  1.0f); glVertex3f( 0.0f,  0.0f,  1.0f);
    glEnd();

    glPopMatrix();
    glDisable(GL_TEXTURE_2D);
    glDisable(GL_LIGHTING);
}
