
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>

#include "glut.h"
using namespace std;

// dimensiunea ferestrei in pixeli
#define dim 300
double pi = 4 * atan(1.0);
unsigned char prevKey;

void Display1() {
    
    double ratia = 0.05;
    
    double ymin = 999999999;
    double ymax = -999999999;
    double xmax = 100;
    double xmin = 0;
    for (double t = ratia; t <= 100; t += ratia) {
        double x1, y1;
        int closest_int = int(t + 0.5);
        double dist = fabs(t - closest_int);
        y1 = (dist / t);
        ymax = (ymax < y1) ? y1 : ymax;
        ymin = (ymin > y1) ? y1 : ymin;

    }

    ymax = (fabs(ymax) > fabs(ymin)) ? fabs(ymax) : fabs(ymin);


    // afisarea punctelor propriu-zise precedata de scalare
    glColor3f(1, 0.1, 0.1); // rosu
    glBegin(GL_LINE_STRIP);
    glVertex2f(0.0f, 1.0f);

    for (double t = 0.05; t < 100; t += ratia) {
        double y1;
        int closest_int = int(t + 0.5);
        double dist = fabs(t - closest_int);
        y1 = (dist / t)/ymax;

        glVertex2f(t/xmax, y1);
    }
    glEnd();
}

void Display2() {

    double a = 0.3, b = 0.2;
    double ratia = 0.05;
    double ymin = 999999999;
    double ymax = -999999999;
    double xmax = -9999999999;
    double xmin = 99999999;
    for(double t = -pi + ratia; t < pi; t += ratia) {
        double x1, y1;
        x1 = 2 * (a * cos(t) + b) * cos(t);
        y1 = 2 * (a * cos(t) + b) * sin(t);
        xmax = (xmax < x1) ? x1 : xmax;
        xmin = (xmin > x1) ? x1 : xmin;
        ymax = (ymax < y1) ? y1 : ymax;
        ymin = (ymin > y1) ? y1 : ymin;

    }

    xmax = (fabs(xmax) > fabs(xmin)) ? fabs(xmax) : fabs(xmin);
    ymax = (fabs(ymax) > fabs(ymin)) ? fabs(ymax) : fabs(ymin);

    // afisarea punctelor propriu-zise precedata de scalare
    glColor3f(1, 0.1, 0.1); // rosu
    glBegin(GL_LINE_STRIP);
    for (double t = -pi + ratia; t < pi; t += ratia) {
        double x1, y1;
        x1 = (2 * (a * cos(t) + b) * cos(t))/xmax;
        y1 = (2 * (a * cos(t) + b) * sin(t))/ymax;
        glVertex2f(x1, y1);
    }
    glEnd();
}

void Display4() {

    double a = 0.1, b = 0.2;
    double ratia = 0.05;
    double ymin = 999999999;
    double ymax = -999999999;
    double xmax = -9999999999;
    double xmin = 99999999;
    for (double t = -10000; t < 10000; t += ratia) {
        double x1, y1;
        x1 = a * t - b * sin(t);
        y1 = a-b * cos(t);
        xmax = (xmax < x1) ? x1 : xmax;
        xmin = (xmin > x1) ? x1 : xmin;
        ymax = (ymax < y1) ? y1 : ymax;
        ymin = (ymin > y1) ? y1 : ymin;

    }

    xmax = (fabs(xmax) > fabs(xmin)) ? fabs(xmax) : fabs(xmin);
    ymax = (fabs(ymax) > fabs(ymin)) ? fabs(ymax) : fabs(ymin);

    // afisarea punctelor propriu-zise precedata de scalare
    glColor3f(1, 0.1, 0.1); // rosu
    glBegin(GL_LINE_STRIP);
    for (double t = -10000 + ratia; t < 10000; t += ratia) {
        double x1, y1;
        x1 = a * t - b * sin(t);
        y1 = a - b * cos(t);
        glVertex2f(x1, y1);
    }
    glEnd();
}

void Display3() {
    double a = 0.2;
    double ratia = 0.04;

    double x = 0, y = 0, xmax = -10000, ymax = -10000, xmin = 10000, ymin = 10000;
    for (double t = -pi / 2 + ratia; t < pi / 2; t += ratia)
    {
        x = a / (4 * pow(cos(t), 2) - 3);
        y = (a * tan(t)) / (4 * pow(cos(t), 2) - 3);
        xmax = xmax < x ? x : xmax;
        ymax = ymax < y ? y : ymax;
        xmin = xmin > x ? x : xmin;
        ymin = ymin > y ? y : ymin;
    }
    xmax = xmax > xmin ? abs(xmax - xmin) : abs(xmin - xmax);
    ymax = ymax > ymin ? abs(ymax - ymin) : abs(ymin - ymax);

    glColor3f(0.1, 0.1, 1);
    glBegin(GL_LINE_LOOP);
    glVertex2f(xmin, ymax);
    for (double t = -pi / 2 + ratia; t < pi / 2; t += ratia)
    {
        if (fabs(t) == pi / 6)
            continue;
        x = a / (4 * pow(cos(t), 2) - 3);
        y = (a * tan(t)) / (4 * pow(cos(t), 2) - 3);
        if (x > 0 or y < 0)
            continue;
        glVertex2f(x, y);
    }

    glEnd();
    cout << xmin << "     " << ymax;
    glColor3f(1, 0.1, 0.1); // rosu
    for (double t = -pi / 2 + ratia; t < pi / 2; t += ratia)
    {
        if (fabs(t) == pi / 6)
            continue;
        x = a / (4 * pow(cos(t), 2) - 3);
        y = (a * tan(t)) / (4 * pow(cos(t), 2) - 3);
        if (x > 0 or y < 0)
            continue;
        glBegin(GL_TRIANGLES);
        glVertex2f(-1, 1);
        glVertex2f(x, y);
        t += ratia;
        x = a / (4 * pow(cos(t), 2) - 3);
        y = (a * tan(t)) / (4 * pow(cos(t), 2) - 3);
        glVertex2f(x, y);

        glEnd();
    }
}

void Display5() {

    double R = 0.1, r = 0.3;
    double ratia = 0.05;
    double r_over_R = r/R;
    double ymin = 999999999;
    double ymax = -999999999;
    double xmax = -9999999999;
    double xmin = 99999999;
    for (double t = 0; t < 2* pi; t += ratia) {
        double x1, y1;
        
        x1 = (R + r) * cos(r_over_R *t) - r* cos(t+ r_over_R*t) ;
        y1 = (R + r) * sin(r_over_R * t) - r * sin(t + r_over_R * t);
        xmax = (xmax < x1) ? x1 : xmax;
        xmin = (xmin > x1) ? x1 : xmin;
        ymax = (ymax < y1) ? y1 : ymax;
        ymin = (ymin > y1) ? y1 : ymin;
        
    }

    xmax = (fabs(xmax) > fabs(xmin)) ? fabs(xmax) : fabs(xmin);
    ymax = (fabs(ymax) > fabs(ymin)) ? fabs(ymax) : fabs(ymin);
    glColor3f(1, 0.1, 0.1); // rosu
    glBegin(GL_LINE_STRIP);
    for (double t = 0; t < 2*pi; t += ratia) {
        double x1, y1;
        x1 = ((R + r) * cos(r_over_R * t) - r * cos(t + r_over_R * t))/xmax;
        y1 = ((R + r) * sin(r_over_R * t) - r * sin(t + r_over_R * t))/ymax;
        glVertex2f(x1, y1);
    }
    glEnd();
}

void Display6() {

    double R = 0.1, r = 0.3;
    double ratia = 0.05;
    double r_over_R = r / R;
    double ymin = 999999999;
    double ymax = -999999999;
    double xmax = -9999999999;
    double xmin = 99999999;
    for (double t = 0; t < 2 * pi; t += ratia) {
        double x1, y1;

        x1 = (R - r) * cos(r_over_R * t) - r * cos(t - r_over_R * t);
        y1 = (R - r) * sin(r_over_R * t) - r * sin(t - r_over_R * t);
        xmax = (xmax < x1) ? x1 : xmax;
        xmin = (xmin > x1) ? x1 : xmin;
        ymax = (ymax < y1) ? y1 : ymax;
        ymin = (ymin > y1) ? y1 : ymin;

    }

    xmax = (fabs(xmax) > fabs(xmin)) ? fabs(xmax) : fabs(xmin);
    ymax = (fabs(ymax) > fabs(ymin)) ? fabs(ymax) : fabs(ymin);
    glColor3f(1, 0.1, 0.1); // rosu
    glBegin(GL_LINE_STRIP);
    for (double t = 0; t < 2 * pi; t += ratia) {
        double x1, y1;
        x1 = ((R - r) * cos(r_over_R * t) - r * cos(t - r_over_R * t)) / xmax;
        y1 = ((R - r) * sin(r_over_R * t) - r * sin(t - r_over_R * t)) / ymax;
        glVertex2f(x1, y1);
    }
    glEnd();
}


void Display7() {

    double xmin = -pi / 4;
    double xmax = pi / 4;
    double a = 0.4, b = 0.2;
    double ratia = 0.05;

    // afisarea punctelor propriu-zise precedata de scalare
    glColor3f(1, 0.1, 0.1); // rosu
    glBegin(GL_LINE_STRIP);
    for (double x = xmin; x < xmax; x += ratia) {
        double x1, y1;
        double r = a * sqrt(2 * cos(2 * x));
        x1 = r * cos(x);
        y1 = r * sin(x);
        glVertex2f(x1, y1);
    }
    glEnd();
    glBegin(GL_LINE_STRIP);
    for (double x = xmin; x < xmax; x += ratia) {
        double x1, y1;
        double r = -a * sqrt(2 * cos(2 * x));
        x1 = r * cos(x);
        y1 = r * sin(x);
        glVertex2f(x1, y1);
    }
    glEnd();
}

void Display8() {

    double xmin = 0.05;
    double xmax = 9999;
    double a = 0.02, b = 0.2;
    double ratia = 0.05;

    glColor3f(1, 0.1, 0.1); // rosu
    glBegin(GL_LINE_STRIP);
    for (double x = xmin; x < xmax; x += ratia) {
        double x1, y1;
        double r = a * exp(1 + x);
        x1 = r * cos(x);
        y1 = r * sin(x);
        glVertex2f(x1, y1);
    }
    glEnd();
}

void Init(void) {

    glClearColor(1.0, 1.0, 1.0, 1.0);

    glLineWidth(1);

    //   glPointSize(4);

    glPolygonMode(GL_FRONT, GL_LINE);
}

void Display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    switch (prevKey) {
    case '1':
        Display1();
        break;
    case '2':
        Display2();
        break;
    case '3':
        Display3();
        break;
    case '4':
        Display4();
        break;
    case '5':
        Display5();
        break;
    case '6':
        Display6();
        break;
    case '7':
        Display7();
        break;
    case '8':
        Display8();
        break;
    default:
        break;
    }

    glFlush();
}

void Reshape(int w, int h) {
    glViewport(0, 0, (GLsizei)w, (GLsizei)h);
}

void KeyboardFunc(unsigned char key, int x, int y) {
    prevKey = key;
    if (key == 27) // escape
        exit(0);
    glutPostRedisplay();
}

void MouseFunc(int button, int state, int x, int y) {
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);

    glutInitWindowSize(dim, dim);

    glutInitWindowPosition(100, 100);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    glutCreateWindow(argv[0]);

    Init();

    glutReshapeFunc(Reshape);

    glutKeyboardFunc(KeyboardFunc);

    glutMouseFunc(MouseFunc);

    glutDisplayFunc(Display);

    glutMainLoop();

    return 0;
}
