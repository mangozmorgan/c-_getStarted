# Définitions des variables
CXX = g++               # Compilateur C++
CXXFLAGS = -static -g   # Options de compilation
SRC = main.cpp ./Player/Player.cpp ./Enemy/Enemy.cpp ./MyGame/MyGame.cpp
TARGET = main.exe

# Règle par défaut (build + run)
all: build run

# Règle pour construire l'exécutable
build:
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Règle pour exécuter le programme
run: build
	./$(TARGET)

# Règle pour nettoyer les fichiers générés
clean:
	rm -f $(TARGET)
