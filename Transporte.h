#ifndef TRANSPORTE_H
#define TRANSPORTE_H

#include <string>
#include "Cidade.h"

class Transporte {
private:
    std::string nome;
    char tipo; // 'A' para Aquático, 'T' para Terrestre
    int capacidade;
    int velocidade;
    int distancia_entre_descansos;
    int tempo_de_descanso;
    int tempo_de_descanso_atual;
    Cidade* localAtual;
public:
    Transporte(std::string nome, char tipo, int capacidade, int velocidade, int distancia_entre_descansos, int tempo_de_descanso, Cidade* localAtual);
    std::string getNome();
    char getTipo();
    int getCapacidade();
    int getVelocidade();
    int getDistanciaEntreDescansos();
    int getTempoDescanso();
    int getTempoDescansoAtual();
    Cidade* getLocalAtual();
    void setLocalAtual(Cidade* local);
};

#endif // TRANSPORTE_H
