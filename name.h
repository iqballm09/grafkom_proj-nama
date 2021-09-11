#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>
#include "components.h"
#pragma once

using namespace std;

/* Classes */
class Name : public Bangun2D
{
public:
    // 1. Huruf I
    void letterI(double red, double green, double blue)
    {
        glColor3ub(red, green, blue);
        rectangle(258, 276.96, 229.08, 351.25);
    }

    // 2. Huruf Q
    void letterQ(double red, double green, double blue, double red_bg, double green_bg, double blue_bg)
    {
        glPushMatrix();
        glColor3ub(red, green, blue);
        circle(356.3, 287.74, 120, 0, 360);
        glColor3ub(red_bg, green_bg, blue_bg);
        circle(356.3, 287.74, 80, 0, 360);
        glColor3ub(red, green, blue);
        rectangle(346.32, 366.28, 309.8, 375.46);
        glPopMatrix();
    }

    // 3. Huruf B
    void letterB(double red, double green, double blue, double red_bg, double green_bg, double blue_bg)
    {
        glPushMatrix();
        glColor3ub(red, green, blue);
        rectangle(434.15, 522.97, 229.61, 352.32);

        glColor3ub(red_bg, green_bg, blue_bg);
        triangle(522.97, 501.01, 250.6, 330.26, 290.43);
        // Create spesific geometry
        compB(454.61, 498.52, 250.6, 330.5);
        glPopMatrix();
    }

    /* 4. Huruf A */
    void letterA(double red, double green, double blue, double red_bg, double green_bg, double blue_bg)
    {
        glPushMatrix();
        glColor3ub(red, green, blue);
        concave(630.75, 652.5, 612.29, 228.72, 351.97);
        rectangle(630.75, 652.5, 228.72, 351.97);
        glBegin(GL_POLYGON);
        glVertex2d(630.75, 228.72);
        glVertex2d(652.5, 228.72);
        glVertex2d(568.38, 351.97);
        glVertex2d(542.43, 351.97);
        glEnd();
        glPopMatrix();
    }

    /* 5. Huruf L */
    void letterL(double red, double green, double blue)
    {
        glPushMatrix();
        glColor3ub(red, green, blue);
        rectangle(673.67, 693.63, 228.72, 351.97);
        glBegin(GL_POLYGON);
        glVertex2d(673.67, 329.9);
        glVertex2d(762.03, 329.9);
        glVertex2d(747.56, 351.97);
        glVertex2d(673.67, 351.97);
        glEnd();
        glPopMatrix();
    }
};