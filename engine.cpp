#include "engine.h"

Engine::Engine(QWidget * parent) : QGLWidget(parent) {
}


Engine::~Engine() {
    delete timer;
    delete scene;
}

void Engine::initializeGL() {
    init();
}

void Engine::init() {
    setFocusPolicy(Qt::ClickFocus);
    glClearColor(0.0618, 0.0618, 0.0618, 1.0);
    glClearDepth(1.0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glPolygonMode(GL_FRONT, GL_FILL);
    glPolygonMode(GL_BACK, GL_FILL);
    glShadeModel(GL_SMOOTH);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_CULL_FACE);
    glEnable(GL_AUTO_NORMAL);
    glEnable(GL_NORMALIZE);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(cycle()));
    timer->start(1000/60);
    timeLast = QTime::currentTime();

    scene = new Scene();

    keyA = keyW = keyS = keyD = keyQ = keyE = keySpace = keyShift = key1 = false;

    float global_ambient[] = { 1.0f, 1.0f, 1.0f, 1.0f };
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT, global_ambient);
}


void Engine::cycle() {
    int dt = timeLast.elapsed();
    update(dt);
    render();
}


void Engine::update(int dt) {
    updateKeyboard(dt);
    scene->update();
}


void Engine::render() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    scene->render();

    swapBuffers();
    timeLast = QTime::currentTime();
}

void Engine::resizeGL(int width, int height) {
    //qDebug() << "resize" << width << height;
    scene->player->camera->viewport(width, height);
    scene->player->camera->update();
}

void Engine::updateKeyboard(int dt) {
    if      (keyA)     { scene->player->moveLeft(dt);     }
    else if (keyD)     { scene->player->moveRight(dt);    }
    else if (keyW)     { scene->player->moveForward(dt);  }
    else if (keyS)     { scene->player->moveBackward(dt); }
    else if (keyQ)     { scene->player->rotateLeft(dt);   }
    else if (keyE)     { scene->player->rotateRight(dt);  }
    else if (keySpace) { scene->player->moveUp(dt);       }
    else if (keyShift) { scene->player->moveDown(dt);     }
}

void Engine::keyPressEvent(QKeyEvent *event) {
    switch(event->key()) {
    case Qt::Key_A:         keyA = true; break;
    case Qt::Key_D:         keyD = true; break;
    case Qt::Key_S:         keyS = true; break;
    case Qt::Key_W:         keyW = true; break;
    case Qt::Key_Q:         keyQ = true; break;
    case Qt::Key_E:         keyE = true; break;
    case Qt::Key_Space: keySpace = true; break;
    case Qt::Key_Shift: keyShift = true; break;
    case Qt::Key_1:         key1 = true; break;
    }
}
void Engine::keyReleaseEvent(QKeyEvent *event) {
    switch(event->key()) {
    case Qt::Key_A:         keyA = false; break;
    case Qt::Key_D:         keyD = false; break;
    case Qt::Key_S:         keyS = false; break;
    case Qt::Key_W:         keyW = false; break;
    case Qt::Key_Q:         keyQ = false; break;
    case Qt::Key_E:         keyE = false; break;
    case Qt::Key_Space: keySpace = false; break;
    case Qt::Key_Shift: keyShift = false; break;
    case Qt::Key_1: key1 = false; scene->light->toggle(); break;
    }
}
