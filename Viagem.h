#ifndef VIAGEM_H
#define VIAGEM_H

#include <vector>
#include "Transporte.h"
#include "Passageiro.h"
#include "Cidade.h"

class Viagem {
private:
    Transporte* transporte;
    std::vector<Passageiro*> passageiros;
    Cidade* origem;
    Cidade* destino;
    Viagem* proxima; // Declarado antes de `emAndamento`
    bool emAndamento; // Declarado depois de `proxima`

public:
    Viagem(Transporte* transporte, std::vector<Passageiro*> passageiros, Cidade* origem, Cidade* destino);

    // Métodos getters e outros
    Transporte* getTransporte() const;
    std::vector<Passageiro*> getPassageiros() const;
    Cidade* getOrigem() const;
    Cidade* getDestino() const;
    bool isEmAndamento() const;
    void iniciar();
};

#endif // VIAGEM_H
