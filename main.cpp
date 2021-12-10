#include"GL/freeglut.h"
#include"math.h"
#include"Planet.h"
#include<iostream>

//SUN AND PLANET CREATION
Planet Sun = Planet(0, 0.2, 0, false);
Planet Mercury = Planet(0.22, 0.01, 20, false);
Planet Venus = Planet(0.26, 0.012, 27, true);
Planet Earth = Planet(0.33 , 0.018, 32, false);
Planet Mars = Planet(0.39, 0.018 , 39,true);
Planet Jupiter = Planet(0.46 , 0.03, 45, false);//*
Planet Saturn = Planet(0.54, 0.03, 49, true);
Planet Uranus = Planet(0.63, 0.023, 53,false);
Planet Neptune = Planet(0.70, 0.017, 56,true);
Planet Pluton = Planet(0.75, 0.011, 60, false);

void Display(){
    glClearColor(0,0,0,1);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    //Sun
    glColor3f(1,0.7,0);
    glBegin(GL_POLYGON);
    for (int i=0, j=40; i<=j; i++){
        Sun.circunferencia(i,j);
        glVertex2d(Sun.getPlanetRadiusX(), Sun.getPlanetRadiusY());
    }
    glEnd();
    /*===========Planet1==================*/
    glColor3f(1,0,0);
    //Draw orbit
    glBegin(GL_LINE_LOOP);
    for (int i = 0, j=40; i <= j; i++) {
        Mercury.Orbit(i,j);
        glVertex2d(Mercury.getOrbitPosX(),Mercury.getOrbitPosY());
    }
    glEnd();
    //traslation
    Mercury.translation();
    glPushMatrix();
    glTranslated(Mercury.getOrbitPosX(),Mercury.getOrbitPosY(),0);

    //draw planet
    glBegin(GL_POLYGON);
    for (int i = 0, j=40; i <= j; i++) {
        Mercury.circunferencia(i,j);
        glVertex2d(Mercury.getPlanetRadiusX(),Mercury.getPlanetRadiusY());
    }
    glEnd();
    glPopMatrix();

    /*===========Planet2==================*/
    glColor3f(1,0.5,0.1);
    //Draw orbit
    glBegin(GL_LINE_LOOP);
    for (int i = 0, j = 50; i <= j; i++) {
        Venus.Orbit(i,j);
        glVertex2d(Venus.getOrbitPosX(), Venus.getOrbitPosY());
    }
    glEnd();
    //traslation
    Venus.translation();
    glPushMatrix();
    glTranslated(Venus.getOrbitPosX(),Venus.getOrbitPosY(),0);
    //draw planet
    glBegin(GL_POLYGON);
    for (int i = 0, j=40; i <= j; i++) {
        Venus.circunferencia(i,j);
        glVertex2d(Venus.getPlanetRadiusX(), Venus.getPlanetRadiusY());
    }
    glEnd();
    glPopMatrix();
    
    /*===========Planet3==================*/
    glColor3f(0,0,0.9);
    //draw orbit
    glBegin(GL_LINE_LOOP);
    double oEarth = 0.3;
    for (int i = 0, j = 50; i <= 50; i++) {
        Earth.Orbit(i,j);
        glVertex2d(Earth.getOrbitPosX(), Earth.getOrbitPosY());
    }
    glEnd();
    //traslation
    Earth.translation();
    glPushMatrix();
    glTranslated(Earth.getOrbitPosX(),Earth.getOrbitPosY(),0);
    //Draw Planet
    glBegin(GL_POLYGON);
    for (int i = 0, j = 40; i <= j; i++) {
        Earth.circunferencia(i,j);
        glVertex2d(Earth.getPlanetRadiusX(), Earth.getPlanetRadiusY());
    }
    glEnd();
    glPopMatrix();
    /*===========Planet4==================*/
    glColor3f(0,0,0.9);
    //Draw orbit
    glBegin(GL_LINE_LOOP);
        for (int i=0, j = 50; i <= j; i++) {
        Mars.Orbit(i,j);
        glVertex2d(Mars.getOrbitPosX(), Mars.getOrbitPosY());
    }
    glEnd();
    //TRASLATION
    glPushMatrix();
    Mars.translation();
    glTranslated(Mars.getOrbitPosX(),Mars.getOrbitPosY(),0);
    //DRAW PLANET
    glBegin(GL_POLYGON);
    for (int i = 0, j = 40; i <= j; i++) {
        Mars.circunferencia(i,j);
        glVertex2d(Mars.getPlanetRadiusX(), Mars.getPlanetRadiusY());
    }
    glEnd();
    glPopMatrix();

    /*===========Planet5==================*/
    glColor3f(1,1,1);
    //Draw orbit
    glBegin(GL_LINE_LOOP);
        for (int i=0, j = 50; i <= j; i++) {
        Jupiter.Orbit(i,j);
        glVertex2d(Jupiter.getOrbitPosX(), Jupiter.getOrbitPosY());
    }
    glEnd();
    //TRASLATION
    glPushMatrix();
    Jupiter.translation();
    glTranslated(Jupiter.getOrbitPosX(),Jupiter.getOrbitPosY(),0);
    //DRAW PLANET
    glBegin(GL_POLYGON);
    for (int i = 0, j = 40; i <= j; i++) {
        Jupiter.circunferencia(i,j);
        glVertex2d(Jupiter.getPlanetRadiusX(), Jupiter.getPlanetRadiusY());
    }
    glEnd();
    glPopMatrix();

    /*===========Planet6==================*/
    glColor3f(0,0,0.9);
    //Draw orbit
    glBegin(GL_LINE_LOOP);
        for (int i=0, j = 50; i <= j; i++) {
        Saturn.Orbit(i,j);
        glVertex2d(Saturn.getOrbitPosX(), Saturn.getOrbitPosY());
    }
    glEnd();
    //TRASLATION
    glPushMatrix();
    Saturn.translation();
    glTranslated(Saturn.getOrbitPosX(),Saturn.getOrbitPosY(),0);
    //DRAW PLANET
    glBegin(GL_POLYGON);
    for (int i = 0, j = 40; i <= j; i++) {
        Saturn.circunferencia(i,j);
        glVertex2d(Saturn.getPlanetRadiusX(), Saturn.getPlanetRadiusY());
    }
    glEnd();
    glPopMatrix();

    /*===========Planet7==================*/
    glColor3f(0,0,0.9);
    //Draw orbit
    glBegin(GL_LINE_LOOP);
        for (int i=0, j = 50; i <= j; i++) {
        Uranus.Orbit(i,j);
        glVertex2d(Uranus.getOrbitPosX(), Uranus.getOrbitPosY());
    }
    glEnd();
    //TRASLATION
    glPushMatrix();
    Uranus.translation();
    glTranslated(Uranus.getOrbitPosX(),Uranus.getOrbitPosY(),0);
    //DRAW PLANET
    glBegin(GL_POLYGON);
    for (int i = 0, j = 40; i <= j; i++) {
        Uranus.circunferencia(i,j);
        glVertex2d(Uranus.getPlanetRadiusX(), Uranus.getPlanetRadiusY());
    }
    glEnd();
    glPopMatrix();

    /*===========Planet8==================*/
    glColor3f(0,0,0.9);
    //Draw orbit
    glBegin(GL_LINE_LOOP);
        for (int i=0, j = 50; i <= j; i++) {
        Neptune.Orbit(i,j);
        glVertex2d(Neptune.getOrbitPosX(), Neptune.getOrbitPosY());
    }
    glEnd();
    //TRASLATION
    glPushMatrix();
    Neptune.translation();
    glTranslated(Neptune.getOrbitPosX(),Neptune.getOrbitPosY(),0);
    //DRAW PLANET
    glBegin(GL_POLYGON);
    for (int i = 0, j = 40; i <= j; i++) {
        Neptune.circunferencia(i,j);
        glVertex2d(Neptune.getPlanetRadiusX(), Neptune.getPlanetRadiusY());
    }
    glEnd();
    glPopMatrix();

        /*===========Planet9==================*/
    glColor3f(0,0,0.9);
    //Draw orbit
    glBegin(GL_LINE_LOOP);
        for (int i=0, j = 50; i <= j; i++) {
        Pluton.Orbit(i,j);
        glVertex2d(Pluton.getOrbitPosX(), Pluton.getOrbitPosY());
    }
    glEnd();
    //TRASLATION
    glPushMatrix();
    Pluton.translation();
    glTranslated(Pluton.getOrbitPosX(),Pluton.getOrbitPosY(),0);
    //DRAW PLANET
    glBegin(GL_POLYGON);
    for (int i = 0, j = 40; i <= j; i++) {
        Pluton.circunferencia(i,j);
        glVertex2d(Pluton.getPlanetRadiusX(), Pluton.getPlanetRadiusY());
    }
    glEnd();
    glPopMatrix();

    glutSwapBuffers();
}
void Timer(int v){
    Mercury.setArcPosition();
    Venus.setArcPosition();
    Earth.setArcPosition();
    Mars.setArcPosition();
    Jupiter.setArcPosition();
    Saturn.setArcPosition();
    Uranus.setArcPosition();
    Neptune.setArcPosition();
    Pluton.setArcPosition();

    glutPostRedisplay();
    glutTimerFunc(100,Timer,v);
}

void Click(int btn, int state, int x, int y){
    float posX = ((float)x - 401)/400;
    float posY = (((float)y - 401)/400)*(-1);
    if(state == GLUT_DOWN){
        Mercury.area(posX,posY);
        Venus.area(posX,posY);
        Earth.area(posX,posY);
        Mars.area(posX,posY);
        Jupiter.area(posX,posY);
        Saturn.area(posX,posY);
        Uranus.area(posX,posY);
        Neptune.area(posX,posY);
        Pluton.area(posX,posY);
    }
}

int main(int argc, char** argv){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowPosition(200, 200);
    glutInitWindowSize(800, 800);
    glutCreateWindow("examen");
    glutDisplayFunc(Display);
    glutTimerFunc(100, Timer, 0);
    glutMouseFunc(Click);
    glutMainLoop();
    return 0;
}