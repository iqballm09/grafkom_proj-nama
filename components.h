#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>
#pragma once

using namespace std;

class Bangun2D
{
public:
    double x = 500, y = 300;

    // 1. Persegi panjang
    void rectangle(double a1, double a2, double b1, double b2)
    {
        glBegin(GL_POLYGON);
        glVertex2d(a1, b1);
        glVertex2d(a1, b2);
        glVertex2d(a2, b2);
        glVertex2d(a2, b1);
        glEnd();
    }

    // 2. Lingkaran
    void circle(double posX, double posY, double radius, double start, double end)
    {
        glBegin(GL_POLYGON);
        for (int i = start; i <= end; i++)
        {
            double theta = i * 3.142 / 180;
            glVertex2d(posX + radius * cos(theta) / 2, posY + radius * sin(theta) / 2);
        }
        glEnd();
    }
    // 3. cekungan
    void concave(double a1, double a2, double a3, double b1, double b2)
    {
        glBegin(GL_POLYGON);
        glVertex2d(a3, (b1 + b2) / 2);
        glVertex2d(a2, b2);
        glVertex2d(a1, b2);
        glVertex2d(a3 - 27, (b1 + b2) / 2);
        glVertex2d(a1, b1);
        glVertex2d(a2, b1);
        glEnd();
    }
    // 4. Segitiga
    void triangle(double a1, double a2, double b1, double b2, double b3)
    {
        glBegin(GL_TRIANGLE_FAN);
        glVertex2d(a1, b1);
        glVertex2d(a1, b2);
        glVertex2d(a2, b3);
        glEnd();
    }

    // 5. Bintang
    void star(double a1, double a2, double a3, double a4, double a5, double a6,
              double b1, double b2, double b3, double b4, double b5)
    {
        glBegin(GL_POLYGON);
        glVertex2d(a2, b2);
        glVertex2d(a3, b2);
        glVertex2d(a4, b3);
        glVertex2d(a5, b5);
        glVertex2d(a6, b4);
        glVertex2d(a5 + 77, b5);
        glVertex2d(a4 + 47, b3);
        glVertex2d(a3 + 124.5, b2);
        glVertex2d(a2 + 29.5, b2);
        glVertex2d(a1, b1);
        glEnd();
    }

    /* 6. Untuk huruf B */
    void compB(double a1, double a2, double b1, double b2)
    {
        glBegin(GL_POLYGON);
        glVertex2d(a1, b2);
        glVertex2d(a2, b2);
        glVertex2d((a1 + a2) / 2, (b1 + b2) / 2);
        glVertex2d(a2, b1);
        glVertex2d(a1, b1);
        glEnd();
    }
};
