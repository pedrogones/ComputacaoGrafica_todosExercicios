
//melancia House
#include <cstdlib>
#include <iostream>
#include <GL/glut.h>

GLint WINDOW_WIDTH = 600,
WINDOW_HEIGHT = 600;

void init();
void Desenha();

void keyboard_func(GLubyte key, GLint x, GLint y);
void keyboard_func_spec(GLint key, GLint x, GLint y);

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);

    init();

    glutDisplayFunc(Desenha);

    glutKeyboardFunc(keyboard_func);
    glutSpecialFunc(keyboard_func_spec);

    glutMainLoop();


    return EXIT_SUCCESS;
}

void init()
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);

    GLint screen_width = glutGet(GLUT_SCREEN_WIDTH),
        screen_height = glutGet(GLUT_SCREEN_HEIGHT);

    glutInitWindowPosition((screen_width - WINDOW_WIDTH) / 2, (screen_height - WINDOW_WIDTH) / 2);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_WIDTH);
    glutCreateWindow("OpenGL Casa Melancia");
    glClearColor(1.0, 1.0, 1.0, 1.0);
    glMatrixMode(GL_PROJECTION);

    gluOrtho2D(0, WINDOW_WIDTH, 0, WINDOW_HEIGHT);
}

void Desenha(GLvoid)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPointSize(5.f);
    // aumenta a espessura das linhas
    glLineWidth(10.0f);
    //parede frente
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.2f);
    glVertex2i(50, 100);
    glVertex2i(350, 100);
    glVertex2i(350, 350);
    glVertex2i(50, 350);
    glEnd();


    //detalhes adicionais: 
    glBegin(GL_POINTS);
    glLineWidth(7.0f);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2i(150, 130);
    glVertex2i(200, 130);
    glVertex2i(160, 300);
    glVertex2i(100, 150);
    glVertex2i(250, 130);
    glVertex2i(110, 320);
    glVertex2i(300, 141);
    glVertex2i(350, 120);
    glVertex2i(325, 300);
    glVertex2i(313, 110);
    glEnd();

    //telhado frente
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 0.6f, 0.f);
    glVertex2i(350, 350);
    glVertex2i(50, 350);
    glVertex2i(175, 450);
    glEnd();


    //telhado lado
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.6f, 0.f);
    glVertex2i(350, 350);
    glVertex2i(175, 450);
    glVertex2i(280, 475);
    glVertex2i(450, 400);
    glEnd();



    //parede do lado
    glBegin(GL_QUADS);
    glColor3f(1.0f, 0.0f, 0.2f);
    glVertex2i(350, 100);
    glVertex2i(350, 350);
    glVertex2i(450, 400);
    glVertex2i(450, 150);
    glEnd();

    //porta
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.2f);
    glVertex2i(165, 100);
    glVertex2i(235, 100);
    glVertex2i(235, 225);
    glVertex2i(165, 225);
    glEnd();

    //janela
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.2f);
    glVertex2i(75, 300);
    glVertex2i(125, 300);
    glVertex2i(125, 250);
    glVertex2i(75, 250);
    glEnd();

    //segunda janela
    glBegin(GL_QUADS);
    glColor3f(0.0f, 1.0f, 0.2f);
    glVertex2i(275, 300);
    glVertex2i(325, 300);
    glVertex2i(325, 250);
    glVertex2i(275, 250);
    glEnd();


    //traçando as retas da casa:
    glColor3f(0.0f, 0.0f, 0.0f);
    glBegin(GL_LINE_STRIP);
    glVertex2i(50, 100);
    glVertex2i(350, 100);
    glVertex2i(350, 350);
    glVertex2i(50, 350);
    glVertex2i(50, 100);
    glVertex2i(50, 350);
    glVertex2i(175, 450);
    glVertex2i(350, 350);
    glVertex2i(450, 400);
    glVertex2i(450, 150);
    glVertex2i(350, 100);
    glVertex2i(450, 150);
    glVertex2i(450, 400);
    glVertex2i(280, 475);
    glVertex2i(175, 450);
    glEnd();

    glFlush();
}

void keyboard_func(GLubyte key, GLint x, GLint y)
{
    const int SPACE_BAR{ 32 };

    //tecle CTRL + SPACEBAR:
    if (key == SPACE_BAR && glutGetModifiers() == GLUT_ACTIVE_CTRL) {
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
    } 
    else {
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    }

    glutPostRedisplay();
}

void keyboard_func_spec(GLint key, GLint x, GLint y)
{
    //Tele tecla especial F1:
    if (key == GLUT_KEY_F1) { glClearColor(0.66f, 0.66f, 0.66f, 1.0f); }
    else
    {
        glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
    }

    glutPostRedisplay();
}

