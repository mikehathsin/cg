#include <windows.h> // Libreria necesaria para incluir tipos de datos usados en GLUT
#include <GL/glut.h> // Librería GLUT
#include <math.h>    // Librería math.h para la constante PI

void drawSquare();   // Función que dibuja un cuadrado
void drawTriangle(); // Función que dibuja un triángulo
void drawCircle();   // Función que dibuja un círculo
void display();      // Función que dibuja las figuras

int main(int argc, char **argv)
{
    glutInit(&argc, argv);                        // Inicializa GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // Modo de visualización
    glutInitWindowSize(640, 480);                 // Tamaño de la ventana
    glutInitWindowPosition(100, 100);             // Posición de la ventana
    glutCreateWindow("Evaluacion 2 - MP");        // Crea la ventana con título "Evaluacion 2 - MP"
    glutDisplayFunc(display);                     // Función que se llama para mostrar la ventana
    glClearColor(1.0, 1.0, 1.0, 0.0);             // Color de fondo de la ventana
    glMatrixMode(GL_PROJECTION);                  // Modo de matriz de proyección
    glLoadIdentity();                             // Reinicia la matriz de transformacion
    glutMainLoop();                               // Bucle principal de GLUT
    return 0;
}

void drawSquare()
{
    glColor3f(1.0, 0.0, 0.0); // Color rojo
    glBegin(GL_QUADS);        // Modo de dibujo
    glVertex2f(-0.5, -0.5);   // Vértice inferior izquierdo
    glVertex2f(0.5, -0.5);    // Vértice inferior derecho
    glVertex2f(0.5, 0.5);     // Vértice superior derecho
    glVertex2f(-0.5, 0.5);    // Vértice superior izquierdo
    glEnd();                  // Finaliza el dibujo del cuadrado
}

void drawTriangle()
{
    glColor3f(0.0, 0.0, 1.0); // Color azul
    glBegin(GL_TRIANGLES);    // Modo de dibujo
    glVertex2f(0.0, 0.5);     // Vértice superior
    glVertex2f(-0.5, -0.5);   // Vértice inferior izquierdo
    glVertex2f(0.5, -0.5);    // Vértice inferior derecho
    glEnd();                  // Finaliza el dibujo del triángulo
}

void drawCircle()
{
    glColor3f(0.0, 1.0, 0.0); // Color verde
    glBegin(GL_TRIANGLE_FAN); // Modo de dibujo
    glVertex2f(0.0, 0.0);     // Centro del círculo
    for (int i = 0; i <= 360; i++)
    {
        float angle = i * 2 * M_PI / 360;
        glVertex2f(0.5 * cos(angle), 0.5 * sin(angle)); // Vértices del círculo
    }
    glEnd(); // Finaliza el dibujo del círculo
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);  // Limpia el buffer de color
    drawSquare();                  // Dibuja el cuadrado rojo
    glLoadIdentity();              // Reinicia la matriz de transformación
    glTranslatef(-0.5, -0.5, 0.0); // Traslada hacia la izquierda y hacia abajo
    drawTriangle();                // Dibuja el triángulo azul
    glLoadIdentity();              // Reinicia la matriz de transformación
    glTranslatef(0.5, 0.5, 0.0);   // Traslada hacia la derecha y hacia arriba
    drawCircle();                  // Dibuja el círculo verde
    glutSwapBuffers();             // Intercambia los buffers de pantalla
}