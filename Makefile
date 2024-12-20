# Variáveis
CC = g++
CFLAGS = -std=c++11 -Wall -g
OBJ_DIR = obj
BIN_DIR = bin
SRC = $(wildcard *.cpp)
OBJ = $(SRC:%.cpp=$(OBJ_DIR)/%.o)
TARGET = $(BIN_DIR)/controle_viagens

# Criar diretórios de objetos e binários se não existirem
$(shell mkdir -p $(OBJ_DIR) $(BIN_DIR))

# Regra padrão (compilar o projeto)
all: $(TARGET)

# Compilação final do executável
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Como compilar cada arquivo .cpp para .o
$(OBJ_DIR)/%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza dos arquivos temporários gerados
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Regra para recompilar tudo (limpar e compilar novamente)
rebuild: clean all
