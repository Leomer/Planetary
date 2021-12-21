#include"GL/freeglut.h"
#include"NewPlanet.h"
#include"Sun.h"
#include"RgbImage.h"
#include<iostream>

bool fullscreen = false;
unsigned int background, sun, planetStore[9], testStore;

char universeTex[] = "./textures/Universe.bmp";
char sunTex[] = "./textures/Sun.bmp";
const char planetTex[9][30]={
    "./textures/Sun.bmp",
    "./textures/Sun.bmp",
    "./textures/Azul.bmp",
    "./textures/Sun.bmp",
    "./textures/Sun.bmp",
    "./textures/Sun.bmp",
    "./textures/Sun.bmp",
    "./textures/Sun.bmp",
    "./textures/Sun.bmp"
};

//SUN INITIALIZATION
NewPlanet *planets = new NewPlanet[9];
Sun newSun = Sun(0.2);
//PLANET INITIALIZATION
RgbImage *planetTexture = new RgbImage[9];
//DECLARACION DE ATRIBUTOS A PLANETAS
float orbitRadius[9]={0.25f, 0.30f, 0.36f, 0.44f, 0.53f, 0.64f, 0.75f, 0.86f, 0.95};
float planetRadius[9]={0.01f, 0.012f, 0.018f, 0.019f, 0.03f, 0.035f, 0.023f, 0.017f, 0.011f};
bool orientation[9]={false,true,false,true,false,true,false,true,false};
int circunference[9]={20,30,43,51,59,68,85,90,100};

void Display(){
    glEnable(GL_DEPTH_TEST);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glColor3f(1,1,1);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    
    
    //DRAW A SUN
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, sun);
    //glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
    glBegin(GL_POLYGON);
        glTexCoord2f(0.0, 0.0);
        for (int i=0, j=40; i<=j; i++){
            newSun.coordinates(i,j, newSun.getRadius());
            glTexCoord2f(newSun.getPosX(), newSun.getPosY());
            glVertex2d(newSun.getPosX(), newSun.getPosY());
        }

    glEnd();
    glDisable(GL_TEXTURE_2D);
    for(int planet = 0; planet<9; planet++){
        //Draw Orbits
        glBegin(GL_LINE_LOOP);
            for(int i=0, j=360; i<=j; i++){
                planets[planet].coordinates(i,j, planets[planet].getOrbitRadius());
                glVertex2f(planets[planet].getPosX(), planets[planet].getPosY());
            }
        glEnd();
        //DRAW PLANETS
        planets[planet].translation();
        glPushMatrix();
        glTranslated(planets[planet].getPosX(), planets[planet].getPosY(), 0);
            glEnable(GL_TEXTURE_2D);
            glBindTexture(GL_TEXTURE_2D, planetStore[planet]);
            glBegin(GL_POLYGON);
                for(int i=0, j=360; i<j; i++){
                    planets[planet].coordinates(i,j,planets[planet].getRadius());
                    glTexCoord2f(planets[planet].getPosX(), planets[planet].getPosY());
                    glVertex2f(planets[planet].getPosX(),planets[planet].getPosY());
                }
            glEnd();
            glDisable(GL_TEXTURE_2D);
        glPopMatrix();
    }
        //Universe
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, background);
    
    glBegin(GL_POLYGON);
        glTexCoord2f(0.0f, 0.0f);
        glVertex2f(-1, -1);
        glTexCoord2f(1.0f, 0.0f); 
        glVertex2f( 1, -1);
        glTexCoord2f(1.0f, 1.0f); 
        glVertex2f( 1,  1);
        glTexCoord2f(0.0f, 1.0f);
        glVertex2f(-1,  1);
    glEnd();
    glDisable(GL_TEXTURE_2D);
    glutSwapBuffers();
}
void Timer(int t){
    for(int i=0; i<9; i++)
        planets[i].setArcPosition();
    glutPostRedisplay();
    glutTimerFunc(100, Timer, t);
}
void keyInput(unsigned char key, int x, int y){
    switch (key){
        case 27:
            glutDestroyWindow(glutGetWindow());
            delete[] planets;
            exit(0);
            break;
        case 32:
            fullscreen = !fullscreen;
            if(fullscreen){
                glutFullScreen();
            }else
                glutLeaveFullScreen();
        default:
            break;
    }
}
void loadTexture(){
    glShadeModel(GL_SMOOTH); //?
    glEnable(GL_DEPTH_TEST); //?
    //universo
    RgbImage img(universeTex);
    glGenTextures(1, &background);
    glBindTexture(GL_TEXTURE_2D, background);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_NEAREST);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_NEAREST);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, img.GetNumCols(), img.GetNumRows(),0,GL_RGB,GL_UNSIGNED_BYTE,img.ImageData());
    //textura sol
    RgbImage imgSol(sunTex);
    glGenTextures(1, &sun);
    glBindTexture(GL_TEXTURE_2D, sun);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_NEAREST);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_NEAREST);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, imgSol.GetNumCols(), imgSol.GetNumRows(),0,GL_RGB,GL_UNSIGNED_BYTE,imgSol.ImageData());
    //PLANETS
    for(int i=0; i<9; i++){
        RgbImage tmp( planetTex[i] );
        planetTexture[i] = tmp; //planetTexture[i] = RgbImage(planetTex[i]);
        glGenTextures(1, &planetStore[0]);
        glBindTexture(GL_TEXTURE_2D, planetStore[i]);
            glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_NEAREST);
            glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_NEAREST);
            glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
            glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT);
        glTexImage2D(GL_TEXTURE_2D, 0, 3, planetTexture[i].GetNumCols(), planetTexture[i].GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE, planetTexture[i].ImageData());
    }
    RgbImage test(planetTex[0]);
    glGenTextures(1, &testStore);
    glBindTexture(GL_TEXTURE_2D, testStore);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_NEAREST);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_NEAREST);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT);
    glTexImage2D(GL_TEXTURE_2D, 0, 3, test.GetNumCols(), test.GetNumRows(), 0, GL_RGB, GL_UNSIGNED_BYTE, test.ImageData());
    std::cout<<&planetStore[0]<<"/ "<<&planetStore[1]<<" / "<< &testStore<<std::endl;
}
void mouseInput(int btn, int state, int x, int y){
    float posX = ((float)x - 401)/400;
    float posY = (((float)y - 401)/400)*(-1);
    if(state == GLUT_DOWN){
        for(int i=0; i<9; i++){
            planets[i].translation();
            planets[i].area(posX,posY);
        }        
    }
}
int main(int argc, char** argv){
    //Asignacion de valores al planeta
    for(int i=0; i<9; i++){
        planets[i] = NewPlanet(planetRadius[i], orbitRadius[i], circunference[i], orientation[i]);
    }
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
    glutInitWindowSize(800, 800);
    glutInitWindowPosition(200, 200);
    glutCreateWindow("New Planetary");
    loadTexture();
    glutDisplayFunc(Display);
    glutKeyboardFunc(keyInput);
    glutMouseFunc(mouseInput);
    glutTimerFunc(100, Timer, 0);
    glutMainLoop();
    delete[] planets;
    return 0;
}