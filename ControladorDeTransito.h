#ifndef CONTROLADORDETRANSITO_H
#define CONTROLADORDETRANSITO_H

#include "Cidade.h"
#include "Trajeto.h"
#include "Transporte.h"
#include "Passageiro.h"
#include "Viagem.h"
#include <vector>
#include <string>
#include <fstream>
#include <map>

class ControladorDeTransito {
private:
    std::vector<Cidade*> cidades;
    std::vector<Trajeto*> trajetos;
    std::vector<Transporte*> transportes;
    std::vector<Passageiro*> passageiros;
    std::map<Cidade*, int> visitasPorCidade;
    std::vector<Viagem*> viagensAtivas;
public:
    void cadastrarCidade(std::string nome);
    void cadastrarTrajeto(std::string nomeOrigem, std::string nomeDestino, char tipo, int distancia);
    void cadastrarTransporte(std::string nome, char tipo, int capacidade, int velocidade, int distancia_entre_descansos, int tempo_de_descanso, std::string localAtual);
    void cadastrarPassageiro(std::string nome, std::string localAtual);
    void relatarLocalizacaoPessoas() const;
    void relatarLocalizacaoTransportes() const;
    void relatarViagensEmAndamento() const;
    void relatarCidadesMaisVisitadas() const;
    void registrarVisita(Cidade* cidade);
    void relatarEstado() const;

    // Métodos de persistência
    void salvarDados();
    void carregarDados();
};

#endif
