#include "Viagem.h"

Viagem::Viagem(Transporte* transporte, std::vector<Passageiro*> passageiros, Cidade* origem, Cidade* destino)
    : transporte(transporte), passageiros(passageiros), origem(origem), destino(destino), proxima(nullptr), emAndamento(false) {
}

Transporte* Viagem::getTransporte() const {
    return transporte;
}

std::vector<Passageiro*> Viagem::getPassageiros() const {
    return passageiros;
}

Cidade* Viagem::getOrigem() const {
    return origem;
}

Cidade* Viagem::getDestino() const {
    return destino;
}

bool Viagem::isEmAndamento() const {
    return emAndamento;
}

void Viagem::iniciar() {
    emAndamento = true;
}
