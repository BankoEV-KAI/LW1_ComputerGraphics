#include "zadania.h"


void zadanie1(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("LW1_CompuerGraphics_Ex1");

    init();

    glutDisplayFunc(drawGraph);
    glutMainLoop();
   
}

void init() {
    glClearColor(0.45, 0.48, 0.52, 1.0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-Ox, Ox, -Oy, Oy);
}

void drawAxes() {
    float d{ 0.15 };
    float coord = Ox;
    for (float alpha = 0; alpha <= 90; alpha += 90) {
        glPushMatrix();
        glRotatef(alpha, 0, 0, 1);
        glBegin(GL_LINES);
        glVertex2f(-coord, 0);
        glVertex2f(coord, 0);
        glVertex2f(coord, 0);
        glVertex2f(coord - d, 0 + d);
        glVertex2f(coord, 0);
        glVertex2f(coord - d, 0 - d);
        glEnd();
        glPopMatrix();
        coord = Oy;
    }
}

void drawGraph() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(0, 0, 0);

    glBegin(GL_LINE_STRIP);
    for (float x = -M_PI; x <= M_PI; x += M_PI / 180) {
        float y = pow(M_E, (-A * x)) * sin(B * x);
        glVertex2f(x, y);
    }
    glEnd();

    drawAxes();

    glFlush();
}