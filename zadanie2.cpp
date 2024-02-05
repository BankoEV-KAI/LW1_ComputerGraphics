#include "zadania.h"

void zadanie2(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("LW1_CompuerGraphics_Ex1");

    init();

    glutDisplayFunc(drawMosaic);
    glutMainLoop();

}

void initZadanie2() {
    glClearColor(0.45, 0.48, 0.52, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-800,800,-600,600);
}

void drawMosaic() {
    GLfloat l = -100, r = 100, b = -100, t = 100;
    GLint x = 0, y = 0, w = 60, h = 60;
    glClear(GL_COLOR_BUFFER_BIT);
    gluOrtho2D(l, r, b, t);
    for (x = 0; x <= 800; x += w)
        for (y = 0; y <= 600; y += h)
        {
            glViewport(x, y, w, h);
            glColor3f(1.0, 0.0, 0.0);
            for (int i = 0; i <= 7; i++) {
                glLoadIdentity();
                glRotatef(45*i,0,0,1);
                glTranslatef(0.5, 0, 0);
                drawTriangle();
            }
        }
    glFlush();
}

void drawTriangle() {
    glBegin(GL_TRIANGLES);
    glColor3f(1,1,1);
    glVertex2f(0,0);
    glVertex2f(5,5);
    glVertex2f(10,0);
    glEnd();
}