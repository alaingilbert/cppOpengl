#ifndef ENGINE_H
#define ENGINE_H

#include <QtOpenGL>
#include <QGLWidget>

#include "scene.h"

class Engine : public QGLWidget
{
    Q_OBJECT

public:
    Engine(QWidget * parent = 0);
    ~Engine();
    void init();
    void update(int dt);
    void render();
    void resizeGL(int width, int height);
    void initializeGL();
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);
    //void mousePressEvent(QMouseEvent *event);
    //void mouseReleaseEvent(QMouseEvent *event);
    //void mouseMoveEvent(QMouseEvent *event);
    //void wheelEvent(QWheelEvent *event);
    void updateKeyboard(int dt);

    QTimer * timer;
    Scene * scene;
    QTime timeLast;
    int timeElapsed;
    bool keyA, keyW, keyS, keyD, keyQ, keyE, keySpace, keyShift, key1;

public slots:
    void cycle();
};

#endif // ENGINE_H
