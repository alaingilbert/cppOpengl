#include "player.h"

Player::Player() {
    init();
}


Player::~Player() {
    delete camera;
    delete position;
    delete rotation;
}


void Player::init() {
    position = new QVector3D(3.0f, 3.0f, 7.0f);
    rotation = new QVector3D(0.0f, 0.0f, 0.0f);
    velocity = 2.0f;
    camera = new Camera(position);
}


void Player::update() {
    camera->update();
}


void Player::render() {
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(rotation->x(), 1.0f, 0.0f, 0.0f);
    glRotatef(rotation->y(), 0.0f, 1.0f, 0.0f);
    glRotatef(rotation->z(), 0.0f, 0.0f, 1.0f);
    glPopMatrix();
}


void Player::moveLeft(int dt) {
    camera->position->setX(camera->position->x() - dt/1000.0f * velocity);
    camera->focus->setX(camera->focus->x() - dt/1000.0f * velocity);
}

void Player::moveRight(int dt) {
    camera->position->setX(camera->position->x() + dt/1000.0f * velocity);
    camera->focus->setX(camera->focus->x() + dt/1000.0f * velocity);
}

void Player::moveForward(int dt) {
    camera->position->setZ(camera->position->z() - dt/1000.0f * velocity);
    camera->focus->setZ(camera->focus->z() - dt/1000.0f * velocity);
}

void Player::moveBackward(int dt) {
    camera->position->setZ(camera->position->z() + dt/1000.0f * velocity);
    camera->focus->setZ(camera->focus->z() + dt/1000.0f * velocity);
}

void Player::moveUp(int dt) {
    camera->position->setY(camera->position->y() + dt/1000.0f * velocity);
    camera->focus->setY(camera->focus->y() + dt/1000.0f * velocity);
}

void Player::moveDown(int dt) {
    camera->position->setY(camera->position->y() - dt/1000.0f * velocity);
    camera->focus->setY(camera->focus->y() - dt/1000.0f * velocity);
}

void Player::rotateLeft(int dt) {
    rotation->setY(rotation->y() + dt/1000.0f * velocity * 20);
    camera->yaw = rotation->y();
}

void Player::rotateRight(int dt) {
    rotation->setY(rotation->y() - dt/1000.0f * velocity * 20);
    camera->yaw = rotation->y();
}
