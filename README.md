# cg

## Resolucion de la practica

Se utiliza GLUT como Tookit Wrapper para usar la API de OpenGL.

### Requerimientos previos

- make (comando para building)
- rm (comando removedor de archivos y carpetas)
- g++ (compilador de C++)


### Entorno de pruebas

- Windows 11
- MinGW (https://sourceforge.net/projects/mingw/) con los metapackages: `mingw32-base` y `mingw32-gcc-g++`

### Instrucciones

- Bajar el codigo
- Estar en el directorio raiz a la altura del `Makefile`
- Ejecutar el comando `make evaluacion=X` (X puede ser: 2, 3 o 4) en la terminal

### Resolucion de posibles problemas

-  `make: command not found` intentando hacer el building
> En Windows el metapackage de MinGW mingw32-base instala un make con nombre <mingw32-make>. La solucion seria hacer un alias de <mingw32-make> a <make> o simplemente ejecutar la aplicacion con este comando: `mingw32-make evaluacion=X` (X puede ser: 2, 3 o 4)

- `[clean] Error 2` al iniciar el building
> La TASK clean del Makefile limpia el ejecutable anterior si existe, para ello hace uso del comando `rm`. En caso de dar error, en su sistema no tiene el comando rm.
    - Puede o instalar algun MSYS como Git que le instalen estos comandos de Unix
    - O cambiar el comando rm por el equivalente en su SO
    - O comentar/borrar la TASK clean dentro del Makefile

- Si no desea usar el Makefile puede manualmente construir su binario con el comando:
    
    `g++ -Wall -Wno-unknown-pragmas evaluacion-X.cpp -Iinclude/ -Llib/ -lopengl32 -lglut32 -o bin/evaluacion-X.exe` (X puede ser: 2, 3 o 4)
