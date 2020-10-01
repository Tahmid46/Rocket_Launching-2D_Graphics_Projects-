
#include<dos.h>
#include<windows.h>
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include<cstdio>
#include<bits/stdc++.h>
#include<math.h>

#define PI 3.1416

float xr=0,yr=-1,inc=0,fire=0;
float counter=4.0;
int FPS=10;


int showBackground=1, showRocket=1, showStars=0,showFire=0,sound=0,lp=1; //Flags

void init()
{
    glClearColor(0,0,0,0.0f); //Black

}

void reshape_callback(int w,int h)
{
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-5,5,-5,5,-5,5);
    glMatrixMode(GL_MODELVIEW);
}

void drawFire()
{
    glColor3f(1,0.27,0);
    glBegin(GL_POLYGON);
        glVertex3f(1.3+xr,-4+fire,0);
        glVertex3f(2.2+xr,-4+fire,0);
        glColor3f(1.0,1.0,1.0);
        glVertex3f(2.7+xr,-4.5+fire,0);
        glVertex3f(0.8+xr,-4.5+fire,0);
    glEnd();

    fire=fire+inc;



}

void drawStars()
{


    glColor3f(1.0,1.0,1.0);


    glPointSize(4);
    glBegin(GL_POINTS);
        //glVertex3f(3,2,0);
        //glVertex3f(2,4,0);
        //glVertex3f(4,3,0);
        //glVertex3f(4,2,0);
//        glVertex3f(3,3,0);
    glEnd();

    glPointSize(3);
    glBegin(GL_POINTS);
        //glVertex3f(2,2,0);
        glVertex3f(3,2,0);
        glVertex3f(4,2,0);
        glVertex3f(3,1,0);
//        glVertex3f(3,3,0);
    glEnd();

     glPointSize(2);
    glBegin(GL_POINTS);
        glVertex3f(-2,1,0);
        glVertex3f(3,-2,0);
        glVertex3f(5,-2,0);
        glVertex3f(-3,1,0);
//        glVertex3f(3,3,0);
    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
        glVertex3f(0,-1,0);
        glVertex3f(-3,-2,0);
        glVertex3f(-5,-2,0);
        glVertex3f(-3,-1,0);
//        glVertex3f(3,3,0);
    glEnd();

    glPointSize(1);
    glBegin(GL_POINTS);
        glVertex3f(0,-2,0);
        glVertex3f(-3,-3,0);
        glVertex3f(-5,-3,0);
        glVertex3f(-3,-2,0);
        glVertex3f(1,-2,0);
        glVertex3f(-4,-3,0);
        glVertex3f(-1,-3,0);
        glVertex3f(-5,-2,0);
        glVertex3f(0,2,0);
        glVertex3f(-3,3,0);
        glVertex3f(-5,3,0);
        glVertex3f(-3,2,0);
//        glVertex3f(3,3,0);
    glEnd();

    glPointSize(2);
    glBegin(GL_POINTS);
        glVertex3f(0,4,0);
        glVertex3f(-3,5,0);
        glVertex3f(-4,4,0);
        glVertex3f(-5,4,0);
        glVertex3f(-1,3,0);
        glVertex3f(-4,3,0);
        glVertex3f(-1,3,0);
        glVertex3f(-5,2,0);
        glVertex3f(0,2,0);
        glVertex3f(-3,4,0);
        glVertex3f(-5,4,0);
        glVertex3f(-3,1,0);
//        glVertex3f(3,3,0);
    glEnd();


    ///Big starts and planets
    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);

        for(int i=0;i<100;i++){
            float angle = 2*PI*i/100;


            glVertex2f(-3+cos(angle)*0.5,-3+sin(angle)*0.5);
        }

    glEnd();

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);

        for(int i=0;i<100;i++){
            float angle = 2*PI*i/100;


            glVertex2f(-4+cos(angle)*0.3,0+sin(angle)*0.3);
        }

    glEnd();

    glColor3f(1.0,0.27,0);
    glBegin(GL_POLYGON);

        for(int i=0;i<100;i++){
            float angle = 2*PI*i/100;

            float random = ((float) rand()) / (float) RAND_MAX;
            float diff = 0.5 - 0.4;
            float r = random * diff;
            float rad= 0.4 + r;

            glVertex2f(-3.5+cos(angle)*rad,3+sin(angle)*rad);
        }

    glEnd();


    glColor3f(1.0,0.27,0.0);
    glBegin(GL_POLYGON);

        for(int i=0;i<100;i++){
            float angle = 2*PI*i/100;

            float random = ((float) rand()) / (float) RAND_MAX;
            float diff = 0.4 - 0.35;
            float r = random * diff;
            float rad= 0.35 + r;

            glVertex2f(4+cos(angle)*rad,1+sin(angle)*rad);
        }
    glEnd();

    glColor3f(1.0,1.0,1.0);
    glBegin(GL_POLYGON);

        for(int i=0;i<100;i++){
            float angle = 2*PI*i/100;

            float random = ((float) rand()) / (float) RAND_MAX;
            float diff = 0.05 - 0.04;
            float r = random * diff;
            float rad= 0.24 + r;

            glVertex2f(4+cos(angle)*rad,4+sin(angle)*rad);
        }





    glEnd();

    glFlush();
    //glutPostRedisplay();

}

void drawRocket()
{
    glColor3f(0.75,0.75,0.75);
    glBegin(GL_POLYGON);
        glVertex3d(2.2+xr,-1+yr,0);
        glVertex3d(2.3+xr,-1.5+yr,0);
        glVertex3d(2.3+xr,-3+yr,0);
        glVertex3d(1.2+xr,-3+yr,0);
        glVertex3d(1.2+xr,-1.5+yr,0);
        glVertex3d(1.3+xr,-1+yr,0);
    glEnd();

    glColor3f(0,0,0.5);
    glBegin(GL_QUADS);
        glVertex3d(2.2+xr,0.5+yr,0);
        glVertex3d(2.2+xr,-1+yr,0);
        glVertex3d(1.3+xr,-1+yr,0);
        glVertex3d(1.3+xr,0.5+yr,0);
    glEnd();

    //Payload
    glColor3f(1,0,0);
    glBegin(GL_TRIANGLES);
        glVertex3d(2.2+xr,0.5+yr,0);
        glVertex3d(1.3+xr,0.5+yr,0);
        glVertex3d(1.75+xr,1.5+yr,0);
    glEnd();

    yr=yr+inc;



    if(yr==7.5){
        showBackground=0;
        lp=0;
        showRocket=1;
        showStars=1;
        showFire=1;
        yr=-2;
        fire=-1;
        FPS=1.5;

    }
}

void drawBackground()
{
    glColor3f(0.1,0.5,0.1); //Green Color for ground
     //Ground coordinates
    glBegin(GL_QUADS);
        glVertex3d(5,-3,0);
        glVertex3d(5,-5,0);
        glColor3f(0.0,1.0,0.0);
        glVertex3d(-5,-5,0);
        glVertex3d(-5,-3,0);
    glEnd();

    glColor3f(0.5,0.8,0.9); //Sky blue for sky

    //Sky Coordinates
    glBegin(GL_QUADS);
        glVertex3d(5,-3,0);
        glVertex3d(5,5,0);
        glVertex3d(-5,5,0);
        glVertex3d(-5,-3,0);
    glEnd();
}

void launchingPad()
{

    glColor3f(0.0,0.0,0.0); //Black
    glBegin(GL_POLYGON);
        glVertex3d(3,-4,0);
        glVertex3d(3,-4.8,0);
        glColor3f(0.75,0.75,0.75);
        glVertex3d(0,-4.8,0);
        glVertex3d(0,-4,0);
    glEnd();

    glColor3f(0,0,0);
    glBegin(GL_QUADS);
        glVertex3d(0.2,-4,0);
        glVertex3d(0.2,0,0);
        glColor3f(0.75,0.75,0.75);
        glVertex3d(1.1,0,0);
        glVertex3d(1.1,-4,0);

    glEnd();

}


void display1()
{
    glClear(GL_COLOR_BUFFER_BIT);


    if(showBackground==1){
        drawBackground();
    }

    if(showStars==1){
        drawStars();
    }

    if(showRocket==1){
        drawRocket();
    }

    if(showFire==1){
        drawFire();
        //PlaySound("Rocket-SoundBible.com-941967813.wav",NULL, SND_FILENAME|SND_ASYNC);
    }

    if(lp==1){
        launchingPad();
    }



    glutSwapBuffers();



}

void timer_callback(int)
{
    glutPostRedisplay();
    glutTimerFunc(1000/FPS,timer_callback,0);
}

void FlyRocket(int key,int x,int y)
{

    switch(key)
    {
    case GLUT_KEY_UP:

        inc=0.25;
        showFire=1;
        sound=1;
        break;
    case GLUT_KEY_LEFT:
        xr=xr-0.25;
        break;
    case GLUT_KEY_RIGHT:
        xr=xr+0.25;
        break;
    case GLUT_KEY_DOWN:
        yr=yr-0.25;
        fire=fire-0.25;
        break;
    }
}



int main(int argc, char *argv[])
{
    glutInitDisplayMode(GLUT_DOUBLE| GLUT_RGB); //GLUT_SINGLE=Single display screen |GLUT_RGB= color hobe RGB
    glutInitWindowSize(600,600); //Width,height
    glutInitWindowPosition(200,200); //Width,height
    glutCreateWindow("Rocket Launching"); //Window er name
    init();

    glutDisplayFunc(display1);
    glutReshapeFunc(reshape_callback);
    glutTimerFunc(0,timer_callback,0);
    glutSpecialFunc(FlyRocket);

    glutMainLoop();

    return 0;
}
