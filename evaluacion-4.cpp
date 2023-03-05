#include <windows.h> // Libreria necesaria para incluir tipos de datos usados en GLUT
#include <GL/glut.h> // Librería GLUT
#include <math.h>    // Librería math.h para la constante PI

// Dimensiones del cubo, la piramide y del cono
GLfloat shapeSize = 0.5f;

// Coordenadas del cubo, la piramide y del cono
GLfloat shapePositionX = 0.0f;
GLfloat shapePositionY = 0.0f;
GLfloat shapePositionZ = 0.0f;

// Cantidad de traslación en el eje X
GLfloat translationX = 1.0f;

// Bandera de control de la figura que se muestra actualmente
int showCube = 1;
int showPyramid = 0;
int showCone = 0;
// Bandera de control para saber si la figura se mueve a la derecha (1) o izquierda (0)
int translateCube = 1;
int translatePyramid = 1;
int translateCone = 1;
// Bandera de control para saber si ya la figura hizo su recorrido para que aparezca la siguiente
int cubeTranslated = 0;
int pyramidTranslated = 0;
int coneTranslated = 0;

void updateShapeSizeAndRotation();   // Actualiza el tamano y la rotacion de las figuras
void drawCube();                     // Dibuja el cubo
void drawPyramid();                  // Dibuja la piramide
void drawCone();                     // Dibuja el cono
void display();                      // Dibuja las figuras
void idle();                         // Funcion de actualizacion
void reshape(int width, int height); // Función que coloca la proyeccion hacia las figuras en funcion del tamano de la ventana

// Función principal
int main(int argc, char **argv)
{
    // Inicializar GLUT y crear la ventana
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
    glutInitWindowSize(640, 480);
    glutCreateWindow("Evaluacion 4 - MP");
    // Establecer la función de dibujo
    glutDisplayFunc(display);

    // Establecer la función de redimensionamiento
    glutReshapeFunc(reshape);
    // Establece la función de animación
    glutIdleFunc(idle);

    // Iniciar el bucle de eventos de GLUT
    glutMainLoop();

    return 0;
}

// Función para actualizar el tamano de las figuras en funcion de su posicion en X
void updateShapeSizeAndRotation()
{
    if (shapePositionX >= -1.0f && shapePositionX <= 1.0f)
    {
        shapeSize = 0.1f + 0.4f * fabs(shapePositionX);
        glRotatef(360 * fabs(shapePositionX), 0.0, 1.0, 1.0);
    }
}

// Función para dibujar el cubo
void drawCube()
{
    // Definir el color azul
    glColor3f(0.0f, 0.0f, 1.0f);

    // Dibujar el cubo
    glBegin(GL_QUADS);
    // Cara frontal
    glVertex3f(-shapeSize, -shapeSize, shapeSize);
    glVertex3f(shapeSize, -shapeSize, shapeSize);
    glVertex3f(shapeSize, shapeSize, shapeSize);
    glVertex3f(-shapeSize, shapeSize, shapeSize);
    // Cara trasera
    glVertex3f(-shapeSize, -shapeSize, -shapeSize);
    glVertex3f(-shapeSize, shapeSize, -shapeSize);
    glVertex3f(shapeSize, shapeSize, -shapeSize);
    glVertex3f(shapeSize, -shapeSize, -shapeSize);
    // Cara superior
    glVertex3f(-shapeSize, shapeSize, -shapeSize);
    glVertex3f(-shapeSize, shapeSize, shapeSize);
    glVertex3f(shapeSize, shapeSize, shapeSize);
    glVertex3f(shapeSize, shapeSize, -shapeSize);
    // Cara inferior
    glVertex3f(-shapeSize, -shapeSize, -shapeSize);
    glVertex3f(shapeSize, -shapeSize, -shapeSize);
    glVertex3f(shapeSize, -shapeSize, shapeSize);
    glVertex3f(-shapeSize, -shapeSize, shapeSize);
    // Cara derecha
    glVertex3f(shapeSize, -shapeSize, -shapeSize);
    glVertex3f(shapeSize, shapeSize, -shapeSize);
    glVertex3f(shapeSize, shapeSize, shapeSize);
    glVertex3f(shapeSize, -shapeSize, shapeSize);
    // Cara izquierda
    glVertex3f(-shapeSize, -shapeSize, -shapeSize);
    glVertex3f(-shapeSize, -shapeSize, shapeSize);
    glVertex3f(-shapeSize, shapeSize, shapeSize);
    glVertex3f(-shapeSize, shapeSize, -shapeSize);
    glEnd();
}

// Función para dibujar la pirámide
void drawPyramid()
{
    // Definir el color rojo
    glColor3f(1.0f, 0.0f, 0.0f);
    // Dibujar la pirámide
    glBegin(GL_TRIANGLES);
    // Cara frontal
    glVertex3f(0.0f, shapeSize, 0.0f);
    glVertex3f(-shapeSize, -shapeSize, shapeSize);
    glVertex3f(shapeSize, -shapeSize, shapeSize);
    // Cara derecha
    glVertex3f(0.0f, shapeSize, 0.0f);
    glVertex3f(shapeSize, -shapeSize, shapeSize);
    glVertex3f(shapeSize, -shapeSize, -shapeSize);
    // Cara trasera
    glVertex3f(0.0f, shapeSize, 0.0f);
    glVertex3f(shapeSize, -shapeSize, -shapeSize);
    glVertex3f(-shapeSize, -shapeSize, -shapeSize);
    // Cara izquierda
    glVertex3f(0.0f, shapeSize, 0.0f);
    glVertex3f(-shapeSize, -shapeSize, -shapeSize);
    glVertex3f(-shapeSize, -shapeSize, shapeSize);
    glEnd();
}

// Función para dibujar el cono
void drawCone()
{
    // Definir el color verde
    glColor3f(0.0f, 1.0f, 0.0f);

    // Dibujar el cono
    glBegin(GL_TRIANGLES);
    // Base del cono
    for (int i = 0; i < 360; i += 10)
    {
        glVertex3f(0.0f, 0.0f, 0.0f);
        glVertex3f(shapeSize * cos(i * M_PI / 180.0f), shapeSize * sin(i * M_PI / 180.0f), 0.0f);
        glVertex3f(shapeSize * cos((i + 10) * M_PI / 180.0f), shapeSize * sin((i + 10) * M_PI / 180.0f), 0.0f);
    }

    // Lateral del cono
    for (int i = 0; i < 360; i += 10)
    {
        glVertex3f(0.0f, 0.0f, shapeSize);
        glVertex3f(shapeSize * cos((i + 10) * M_PI / 180.0f), shapeSize * sin((i + 10) * M_PI / 180.0f), 0.0f);
        glVertex3f(shapeSize * cos(i * M_PI / 180.0f), shapeSize * sin(i * M_PI / 180.0f), 0.0f);
    }
    glEnd();
}

// Función para dibujar la escena
void display()
{
    // Limpiar el buffer de color y profundidad
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Cargar la matriz de modelo/vista
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
    glTranslatef(shapePositionX, shapePositionY, shapePositionZ); // Trasladar el cubo en el eje X
    updateShapeSizeAndRotation();                                 // Actualiza el tamano y la rotacion de la figura
    // Dibujar figura segun sea el caso
    if (showCube)
    {
        drawCube();
    }
    if (showPyramid)
    {
        drawPyramid();
    }
    if (showCone)
    {
        drawCone();
    }
    glPopMatrix();

    // Intercambiar los buffers y mostrar la imagen
    glutSwapBuffers();
}

// Función para redimensionar la ventana
void reshape(int width, int height)
{
    // Establecer el viewport
    glViewport(0, 0, width, height);

    // Cargar la matriz de proyección
    glMatrixMode(GL_PROJECTION);
    // Establecer la proyección ortográfica
    glLoadIdentity();
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
    // Habilitar el test de profundidad
    glEnable(GL_DEPTH_TEST);
}

void idle()
{
    // Dependiendo de cual figura se muestre se hara la logica para moverla en la pantalla
    if (showCube)
    {
        // Pregunta si la figura llego al medio
        if (round(shapePositionX * 10000000) == -1)
        {
            cubeTranslated += 1;
            // Se necesitan que cubeTranslated sea 2 para saber que termino su recorrido
            // y muestra la siguiente firura
            if (cubeTranslated == 2)
            {
                cubeTranslated = 0;
                showCube = 0;
                showPyramid = 1;
            }
        }
        // En caso de moverse a la derecha aumentamos la posicion en X
        if (translateCube == 1)
        {
            if (shapePositionX < translationX)
            {
                shapePositionX += 0.0001f;
            }
            else
            {
                // Si la posicion en X es translationX le decimos que ahora gire a la izquierda
                translateCube = 0;
            }
        }
        // En caso de moverse a la izquierda disminuimos la posicion en X
        else
        {
            if (shapePositionX >= -translationX)
            {
                shapePositionX -= 0.0001f;
            }
            else
            {
                // Si la posicion en X es el negativo de  translationX le decimos que ahora gire a la derecha otra vez
                translateCube = 1;
            }
        }
    }

    // La logica es la misma para las otras figuras

    if (showPyramid)
    {
        if (round(shapePositionX * 10000000) == -1)
        {
            pyramidTranslated += 1;
            if (pyramidTranslated == 2)
            {
                pyramidTranslated = 0;
                showPyramid = 0;
                showCone = 1;
            }
        }
        // Actualizar la posición de la pirámide
        if (translatePyramid == 1)
        {
            if (shapePositionX < translationX)
            {
                shapePositionX += 0.0001f;
            }
            else
            {
                translatePyramid = 0;
            }
        }
        else
        {
            if (shapePositionX >= -translationX)
            {
                shapePositionX -= 0.0001f;
            }
            else
            {
                translatePyramid = 1;
            }
        }
    }

    if (showCone)
    {
        if (round(shapePositionX * 10000000) == -1)
        {
            coneTranslated += 1;
            if (coneTranslated == 2)
            {
                coneTranslated = 0;
                showCone = 0;
                showCube = 1;
            }
        }
        // Actualizar la posición de la pirámide
        if (translateCone == 1)
        {
            if (shapePositionX < translationX)
            {
                shapePositionX += 0.0001f;
            }
            else
            {
                translateCone = 0;
            }
        }
        else
        {
            if (shapePositionX >= -translationX)
            {
                shapePositionX -= 0.0001f;
            }
            else
            {
                translateCone = 1;
            }
        }
    }

    glutPostRedisplay(); // Marca la ventana como que necesita ser redibujada
}
