#include <GLFW/glfw3.h>
#include <iostream>
#include "name.h"
#include "properties.h"

using namespace std;

/* GLobal variable */
double red_bg = 0;
double blue_bg = 0;
double green_bg = 0;
double red_nm = 255;
double green_nm = 73;
double blue_nm = 73;
double red_aw = 155;
double green_aw = 228;
double blue_aw = 211;
double red_st = 226;
double green_st = 62;
double blue_st = 151;
double red_ch = 126;
double green_ch = 250;
double blue_ch = 68;
double last_time;
double current_time;

int play = -1;
double temp1, temp2;

/*
 * CLASSES DECLARATION
 */
Name nama;
Property properti;

/*
 * ANOTHER FUNCTION
 */
void displayName()
{
    nama.letterI(red_nm, green_nm, blue_nm);
    nama.letterQ(red_nm, green_nm, blue_nm, red_bg, green_bg, blue_bg);
    nama.letterB(red_nm, green_nm, blue_nm, red_bg, green_bg, blue_bg);
    nama.letterA(red_nm, green_nm, blue_nm, red_bg, green_bg, blue_bg);
    nama.letterL(red_nm, green_nm, blue_nm);
}

void displayProperty(double delta_time)
{
    glPushMatrix();
    glTranslatef(0, 70, 0);
    properti.templateButton();
    if (play == -1)
        properti.playButton();
    else
        properti.pauseButton();
    glPopMatrix();

    properti.arrowObject(red_aw, green_aw, blue_aw);
    properti.starObject1(red_st, green_st, blue_st, play, delta_time);
    properti.starObject2(red_st, green_st, blue_st, play, delta_time);
    glPushMatrix();
    if (play == 1)
    {
        glTranslatef(-20 + abs(sin(delta_time / 2) * 800), 10, 0);
        temp1 = delta_time / 2;
    }
    else
    {
        glTranslatef(-20 + abs(sin(temp1) * 800), 10, 0);
    }
    properti.crosshair(85, 89, 58, 82.95, 91.43, 115.88,
                       228, 255, 257.99, 261.75, 263.91, 290.28,
                       red_ch, green_ch, blue_ch);
    glPopMatrix();
    if (play == 1)
    {
        if (((int)delta_time) % 2 == 1)
        {
            glPushMatrix();
            glTranslatef(-150, -30, 0);
            properti.crosshair(685.25, 688.74, 657.8, 682.75, 691.23, 715.68,
                               82, 108.37, 111.6, 115.37, 117.52, 143.89,
                               red_ch, green_ch, blue_ch);
            glTranslatef(-450, -100, 0);
            glPopMatrix();
        }
    }
    glPushMatrix();
    if (play == 1)
    {
        glTranslatef(-20 - abs(sin(delta_time / 2) * 800), 10, 0);
        temp2 = delta_time / 2;
    }
    else
    {
        glTranslatef(-20 - abs(sin(temp1) * 800), 10, 0);
    }
    properti.crosshair(842.93, 846.42, 815.49, 840.44, 848.92, 873.37,
                       407.07, 433.44, 436.67, 440.43, 442.59, 468.96,
                       red_ch, green_ch, blue_ch);
    glPopMatrix();
    glFlush();
}

int isCursorInside(double x_cursor, double y_cursor)
{
    double d, dx, dy;
    dx = x_cursor - 477.9;
    dy = y_cursor - 480.97;
    d = sqrt(dx * dx + dy * dy);
    if (d < 90)
    {
        //      stopButton();
        return 1;
    }
    else
        return 0;
}
void onButtonPressed(int button, int action, double x_cursor, double y_cursor)
{
    if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
    {
        int cursor_active = isCursorInside(x_cursor, y_cursor);
        if (cursor_active)
        {
            play *= -1;
        }
    }
}
void onclick(double x_cursor, double y_cursor)
{
    if (play == 1)
        properti.pauseButton();
    else
        properti.playButton();
}

/*
 * CALLBACKS FUNCTIONS
 */
static void error_callback(int error, const char *description)
{
    fputs(description, stderr);
}

static void cursor_position_callback(GLFWwindow *window, double xpos, double ypos)
{
    onclick(xpos, ypos);
}

static void mouse_button_callback(GLFWwindow *window, int button, int action, int mods)
{
    double posx, posy;
    glfwGetCursorPos(window, &posx, &posy);
    onButtonPressed(button, action, posx, posy);
}

/*
 * MAIN FUNCTION
 */
int main(void)
{
    /* Creating Windows */
    GLFWwindow *window;
    glfwSetErrorCallback(error_callback);
    if (!glfwInit())
        ;
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);
    window = glfwCreateWindow(1000, 600, "coba2", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
    }
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);

    /* Registering Callbacks */
    glfwSetCursorPosCallback(window, cursor_position_callback);
    glfwSetMouseButtonCallback(window, mouse_button_callback);
    /* MAIN LOOP */
    last_time = 0;
    while (!glfwWindowShouldClose(window))
    {
        /* Preparing Frame Creation */
        int width, height;
        current_time = glfwGetTime();
        double delta_time = current_time - last_time;
        glfwGetFramebufferSize(window, &width, &height);
        glViewport(0, 0, width, height);
        glClear(GL_COLOR_BUFFER_BIT);
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        glOrtho(0, 1000, 600, 0, 1.f, -1.f);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();

        /* Object Drawing*/
        glPushMatrix();
        glTranslatef(0, -70, 0);
        if (delta_time < 16.26)
        {
            properti.barProgress(delta_time, play);
        }
        else
        {
            properti.barComplete(16.28);
            play = -1;
        }
        glPopMatrix();
        displayName();
        displayProperty(delta_time);

        /* Handling Frame Changes */
        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    /* Destroying Windows */
    glfwDestroyWindow(window);
    glfwTerminate();
    // exit(EXIT_SUCCESS);
}