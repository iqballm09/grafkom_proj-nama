#include <GLFW/glfw3.h>
#include <iostream>
#include <math.h>
#include "components.h"
#include <random>
#pragma once

using namespace std;

class Property : public Bangun2D
{
public:
    double temp = 0;
    /* 1. button click */
    void templateButton()
    {
        glPushMatrix();
        glTranslatef(477.9, 480.97, 0);
        glScalef(0.7, 0.7, 0);
        glTranslatef(-477.9, -480.97, 0);
        glColor3ub(181, 178, 178);
        circle(477.9, 480.97, 90, 0, 360);
        glPopMatrix();
    }

    void arrowObject(double red_aw, double green_aw, double blue_aw)
    {
        glPushMatrix();
        glColor3ub(red_aw, green_aw, blue_aw);
        glTranslatef(80, 520, 0);
        glScalef(0.7, 0.7, 0);
        glTranslatef(-80, -450, 0);
        rectangle(33.14, 87.97, 478.94, 505.49);
        triangle(87.83, 131.8, 453.29, 530.78, 491.75);
        glPopMatrix();
    }
    void starObject1(double red_st, double green_st, double blue_st, int play, double delta_time)
    {
        glPushMatrix();
        glColor3ub(red_st, green_st, blue_st);
        glTranslatef(920, 80, 0);
        glScalef(0.6, 0.6, 0);
        if (play == 1)
        {
            glRotatef((float)glfwGetTime() * 150.f, 0, 0, 1);
            temp = delta_time;
        }
        else
        {
            glRotatef(temp * 150.f, 0, 0, 1);
        }
        glTranslatef(-920, -80, 0);
        star(907.37, 892.69, 845.2, 883.62, 869, 907.37, 31, 76.37, 104.41, 121.74, 149.78);
        glPopMatrix();
    }
    void starObject2(double red_st, double green_st, double blue_st, int play, double delta_time)
    {
        glPushMatrix();
        glColor3ub(red_st, green_st, blue_st);
        glScalef(0.8, 0.8, 0);
        glTranslatef(100, 100, 0);
        if (play == 1)
        {
            glScalef((float)sin(glfwGetTime()) * 0.8, (float)sin(glfwGetTime()) * 0.8, 50);
            glRotatef((float)glfwGetTime() * 120.f, 0, 0, 1);
            temp = delta_time;
        }
        else
        {
            glScalef((float)sin(temp) * 0.8, (float)sin(temp) * 0.8, 50);
            glRotatef((float)temp * 120.f, 0, 0, 1);
        }
        glTranslatef(-100, -100, 0);
        star(94.44, 80.41, 35, 71.74, 57.7, 94.44, 36, 80.91, 108.67, 125.83, 153.59);
        glPopMatrix();
    }
    void crosshair(double a1, double a2, double a3, double a4, double a5, double a6,
                   double b1, double b2, double b3, double b4, double b5, double b6,
                   double red_ch, double green_ch, double blue_ch)
    {
        glColor3ub(red_ch, green_ch, blue_ch);
        rectangle(a1, a2, b1, b2);
        rectangle(a3, a4, b3, b4);
        rectangle(a5, a6, b3, b4);
        rectangle(a1, a2, b5, b6);
    }
    void barProgress(double delta_time, int play)
    {
        glPushMatrix();

        if (play == 1)
        {
            glColor3ub(255, 0, 0);
            rectangle(0, 15 + abs(delta_time * 60), 570, 579);
            glColor3ub(255, 255, 255);
            circle(11.5 + abs(delta_time * 60), 574.5, 15, 0, 360);
        }
        else
        {
            glColor3ub(255, 0, 0);
            rectangle(0, 15 + abs(temp * 60), 570, 579);
            glColor3ub(255, 255, 255);
            circle(11.5 + abs(temp * 60), 574.5, 15, 0, 360);
        }

        glPopMatrix();
    }
    void barComplete(double delta_time)
    {
        glPushMatrix();
        glColor3ub(255, 0, 0);
        rectangle(0, 15 + abs(delta_time * 60), 570, 579);
        glColor3ub(255, 255, 255);
        circle(11.5 + abs(delta_time * 60), 574.5, 15, 0, 360);
        glPopMatrix();
    }
    void playButton()
    {
        glPushMatrix();
        glColor3ub(250, 0, 0);
        glTranslatef(477.9, 480.97, 0);
        glScalef(0.7, 0.7, 0);
        glTranslatef(-477.9, -480.97, 0);
        triangle(458.93, 505.84, 454, 507.82, 481.99);
        glPopMatrix();
    }
    void pauseButton()
    {
        glPushMatrix();
        glColor3ub(250, 0, 0);
        glTranslatef(477.9, 480.97, 0);
        glScalef(0.7, 0.7, 0);
        glTranslatef(-477.9, -480.97, 0);
        rectangle(458, 473, 457.29, 505.73);
        rectangle(484, 499, 457.29, 505.73);
        glPopMatrix();
    }
};