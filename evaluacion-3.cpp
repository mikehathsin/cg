#include <windows.h> // Libreria necesaria para incluir tipos de datos usados en GLUT
#include <GL/glut.h> // Librería GLUT
#include <math.h>    // Librería math.h para la constante PI

GLfloat angle = 0.0; // Ángulo de rotación

void display();             // Función que dibuja las figuras
void reshape(int w, int h); // Función que coloca la proyeccion hacia las figuras en funcion del tamano de la ventana
void idle();                // Función que se llama continuamente para actualizar el angulo de rotacion

int main(int argc, char **argv)
{
    glutInit(&argc, argv);                                    // Inicializa GLUT
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH); // Establece el modo de visualización
    glutInitWindowSize(600, 600);                             // Establece el tamaño de la ventana
    glutCreateWindow("Evaluacion 3 - MP");                    // Crea la ventana con título "Evaluacion 3 - MP"
    glEnable(GL_DEPTH_TEST);                                  // Activa el buffer de profundidad
    glutDisplayFunc(display);                                 // Establece la función de dibujo
    glutReshapeFunc(reshape);                                 // Establece la función de cambio de tamaño
    glutIdleFunc(idle);                                       // Establece la función de animación
    glutMainLoop();                                           // Entra en el bucle de eventos GLUT
    return 0;
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // Limpia la pantalla
    glMatrixMode(GL_MODELVIEW);                         // Selecciona la matriz de modelo-vista
    glLoadIdentity();                                   // Carga la matriz identidad
    glTranslatef(-1.5, 0.0, -6.0);                      // Traslada la cámara

    // Dibuja el cubo azul
    glPushMatrix();
    glRotatef(angle, 1.0, 0.0, 0.0); // Rota el cubo
    glColor3f(0.0, 0.0, 1.0);        // Color azul
    glutSolidCube(2.0);              // Dibuja el cubo sólido
    glPopMatrix();

    glLoadIdentity();             // Carga la matriz identidad
    glTranslatef(1.5, 0.0, -6.0); // Traslada la cámara

    // Dibuja la pirámide roja
    glPushMatrix();
    glRotatef(angle, 1.0, 0.0, 0.0); // Rota la pirámide
    glColor3f(1.0, 0.0, 0.0);        // Color rojo
    glBegin(GL_TRIANGLES);           // Comienza a dibujar los triángulos
    glVertex3f(0.0, 1.0, 0.0);       // Vértice superior
    glVertex3f(-1.0, -1.0, 1.0);     // Vértice inferior izquierdo
    glVertex3f(1.0, -1.0, 1.0);      // Vértice inferior derecho
    glEnd();                         // Termina de dibujar los triángulos
    glBegin(GL_QUADS);               // Comienza a dibujar los cuadriláteros
    glColor3f(1.0, 0.0, 0.0);        // Color rojo
    glVertex3f(-1.0, -1.0, 1.0);     // Vértice inferior izquierdo
    glVertex3f(1.0, -1.0, 1.0);      // Vértice inferior derecho
    glVertex3f(1.0, -1.0, -1.0);     // Vértice superior derecho
    glVertex3f(-1.0, -1.0, -1.0);    // Vértice superior izquierdo
    glEnd();                         // Termina de dibujar los cuadriláteros
    glPopMatrix();

    glLoadIdentity();             // Carga la matriz identidad
    glTranslatef(0.0, 0.0, -6.0); // Traslada la cámara

    // Dibuja el poliedro verde
    glPushMatrix();
    glRotatef(angle, 1.0, 0.0, 0.0); // Rota el poliedro
    glColor3f(0.0, 1.0, 0.0);        // Color verde
    glBegin(GL_POLYGON);             // Comienza a dibujar
    glVertex3f(-1.0, 1.0, -1.0);     // Vértice 0
    glVertex3f(1.0, 1.0, -1.0);      // Vértice 1
    glVertex3f(1.0, 1.0, 1.0);       // Vértice 2
    glVertex3f(-1.0, 1.0, 1.0);      // Vértice 3
    glVertex3f(-1.0, -1.0, 1.0);     // Vértice 4
    glVertex3f(-1.0, -1.0, -1.0);    // Vértice 5
    glVertex3f(1.0, -1.0, -1.0);     // Vértice 6
    glVertex3f(1.0, -1.0, 1.0);      // Vértice 7
    glEnd();                         // Termina de dibujar el poliedro
    glPopMatrix();

    glutSwapBuffers(); // Intercambia los buffers de dibujo
}

void reshape(int w, int h)
{
    glViewport(0, 0, (GLsizei)w, (GLsizei)h); // Establece el viewport
    float fovy = 60.0;                        // Apertura en grados
    float aspect = 1.0;                       // Razón de aspecto
    float zNear = 1.0;                        // Distancia del plano cerca
    float zFar = 100.0;                       // Distancia del plano lejos

    float f = 1.0 / tan(fovy * (M_PI / 360.0));                                                                                             // Factor de escala en y
    float m[16] = {f / aspect, 0, 0, 0, 0, f, 0, 0, 0, 0, (zFar + zNear) / (zNear - zFar), -1, 0, 0, 2 * zFar * zNear / (zNear - zFar), 0}; // Matriz de proyección
    glMatrixMode(GL_PROJECTION);                                                                                                            // Selecciona la matriz de proyección
    glLoadMatrixf(m);                                                                                                                       // Carga la matriz de proyección
}

void idle()
{
    angle += 0.1;        // Incrementa el ángulo de rotación
    glutPostRedisplay(); // Marca la ventana como que necesita ser redibujada
}
