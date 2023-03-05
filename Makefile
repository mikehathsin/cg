BIN_FOLDER=bin/
INCLUDE_FOLDER=include/
LIB_FOLDER=lib/

SOURCE_CODE=evaluacion-$(evaluacion).cpp
EXECUTABLE=evaluacion-$(evaluacion).exe

EXECUTABLE_PATH=$(BIN_FOLDER)$(EXECUTABLE)

all: clean compile run

clean:
	@echo "[PASO 1]: Borrando binario"
	rm -f $(EXECUTABLE_PATH)
	@echo

compile:
	@echo "[PASO 2]: Compilando nuevo binario"
	g++ -Wall -Wno-unknown-pragmas $(SOURCE_CODE) -I$(INCLUDE_FOLDER) -L$(LIB_FOLDER) -lopengl32 -lglut32 -o $(EXECUTABLE_PATH)
	@echo

run:
	@echo "[PASO 3]: Ejecutando binario"
	./$(EXECUTABLE_PATH)
	@echo
