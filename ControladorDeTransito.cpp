#include "ControladorDeTransito.h"
#include <iostream>
#include <algorithm>

void ControladorDeTransito::cadastrarCidade(std::string nome) {
    Cidade* cidade = new Cidade(nome);
    cidades.push_back(cidade);
}

void ControladorDeTransito::cadastrarTrajeto(std::string nomeOrigem, std::string nomeDestino, char tipo, int distancia) {
    Cidade* origem = nullptr;
    Cidade* destino = nullptr;

    for (auto& cidade : cidades) {
        if (cidade->getNome() == nomeOrigem) origem = cidade;
        if (cidade->getNome() == nomeDestino) destino = cidade;
    }

    if (origem && destino) {
        Trajeto* trajeto = new Trajeto(origem, destino, tipo, distancia);
        trajetos.push_back(trajeto);
    } else {
        std::cout << "Erro: Cidades não encontradas!" << std::endl;
    }
}

void ControladorDeTransito::cadastrarTransporte(std::string nome, char tipo, int capacidade, int velocidade, int distancia_entre_descansos, int tempo_de_descanso, std::string localAtual) {
    Cidade* local = nullptr;
    for (auto& cidade : cidades) {
        if (cidade->getNome() == localAtual) local = cidade;
    }

    if (local) {
        Transporte* transporte = new Transporte(nome, tipo, capacidade, velocidade, distancia_entre_descansos, tempo_de_descanso, local);
        transportes.push_back(transporte);
    } else {
        std::cout << "Erro: Cidade de origem não encontrada!" << std::endl;
    }
}

void ControladorDeTransito::cadastrarPassageiro(std::string nome, std::string localAtual) {
    Cidade* local = nullptr;
    for (auto& cidade : cidades) {
        if (cidade->getNome() == localAtual) local = cidade;
    }

    if (local) {
        Passageiro* passageiro = new Passageiro(nome, local);
        passageiros.push_back(passageiro);
    } else {
        std::cout << "Erro: Cidade de origem não encontrada!" << std::endl;
    }
}

void ControladorDeTransito::relatarEstado() const {
    std::cout << "Relatório de Cidades: \n";
    for (const auto& cidade : cidades) {
        std::cout << cidade->getNome() << std::endl;
    }

    std::cout << "Relatório de Trajetos: \n";
    for (const auto& trajeto : trajetos) {
        std::cout << trajeto->getOrigem()->getNome() << " -> " << trajeto->getDestino()->getNome() << " (Distância: " << trajeto->getDistancia() << " km)\n";
    }

    std::cout << "Relatório de Transportes: \n";
    for (const auto& transporte : transportes) {
        std::cout << transporte->getNome() << " (Tipo: " << transporte->getTipo() << ")\n";
    }

    std::cout << "Relatório de Passageiros: \n";
    for (const auto& passageiro : passageiros) {
        std::cout << passageiro->getNome() << " (Local Atual: " << passageiro->getLocalAtual()->getNome() << ")\n";
    }
}

void ControladorDeTransito::relatarLocalizacaoPessoas() const {
    for (const auto& passageiro : passageiros) {
        std::cout << "Passageiro: " << passageiro->getNome();
        bool encontrouViagem = false;
        
        for (const auto& viagem : viagensAtivas) {
            if (std::find(viagem->getPassageiros().begin(), 
                         viagem->getPassageiros().end(), 
                         passageiro) != viagem->getPassageiros().end()) {
                std::cout << " - Em trânsito de " 
                         << viagem->getOrigem()->getNome() 
                         << " para " << viagem->getDestino()->getNome()
                         << " no transporte " << viagem->getTransporte()->getNome()
                         << std::endl;
                encontrouViagem = true;
                break;
            }
        }
        
        if (!encontrouViagem) {
            std::cout << " - Em " << passageiro->getLocalAtual()->getNome() << std::endl;
        }
    }
}

void ControladorDeTransito::relatarLocalizacaoTransportes() const {
    for (const auto& transporte : transportes) {
        std::cout << "Transporte: " << transporte->getNome();
        bool encontrouViagem = false;
        
        for (const auto& viagem : viagensAtivas) {
            if (viagem->getTransporte() == transporte) {
                std::cout << " - Em trânsito de " 
                         << viagem->getOrigem()->getNome() 
                         << " para " << viagem->getDestino()->getNome() 
                         << std::endl;
                encontrouViagem = true;
                break;
            }
        }
        
        if (!encontrouViagem) {
            std::cout << " - Em " << transporte->getLocalAtual()->getNome() << std::endl;
        }
    }
}

void ControladorDeTransito::relatarViagensEmAndamento() const {
    std::cout << "\nViagens em andamento:" << std::endl;
    for (const auto& viagem : viagensAtivas) {
        std::cout << "De " << viagem->getOrigem()->getNome() 
                 << " para " << viagem->getDestino()->getNome()
                 << " - Transporte: " << viagem->getTransporte()->getNome()
                 << " - Passageiros: ";
        for (const auto& passageiro : viagem->getPassageiros()) {
            std::cout << passageiro->getNome() << " ";
        }
        std::cout << std::endl;
    }
}

void ControladorDeTransito::registrarVisita(Cidade* cidade) {
    visitasPorCidade[cidade]++;
}

void ControladorDeTransito::relatarCidadesMaisVisitadas() const {
    
}

void ControladorDeTransito::salvarDados() {
    std::ofstream cidadeFile("cidades.txt");
    for (auto& cidade : cidades) {
        cidadeFile << cidade->getNome() << std::endl;
    }
    cidadeFile.close();

    std::ofstream trajetoFile("trajetos.txt");
    for (auto& trajeto : trajetos) {
        trajetoFile << trajeto->getOrigem()->getNome() << "," 
                    << trajeto->getDestino()->getNome() << ","
                    << trajeto->getTipo() << ","
                    << trajeto->getDistancia() << std::endl;
    }
    trajetoFile.close();

    std::ofstream transporteFile("transportes.txt");
    for (auto& transporte : transportes) {
        transporteFile << transporte->getNome() << ","
                       << transporte->getTipo() << ","
                       << transporte->getCapacidade() << ","
                       << transporte->getVelocidade() << ","
                       << transporte->getDistanciaEntreDescansos() << ","
                       << transporte->getTempoDescanso() << ","
                       << transporte->getLocalAtual()->getNome() << std::endl;
    }
    transporteFile.close();

    std::ofstream passageiroFile("passageiros.txt");
    for (auto& passageiro : passageiros) {
        passageiroFile << passageiro->getNome() << ","
                       << passageiro->getLocalAtual()->getNome() << std::endl;
    }
    passageiroFile.close();
}

void ControladorDeTransito::carregarDados() {
    std::ifstream cidadeFile("cidades.txt");
    std::string nome;
    while (std::getline(cidadeFile, nome)) {
        cadastrarCidade(nome);
    }
    cidadeFile.close();

    std::ifstream trajetoFile("trajetos.txt");
    std::string origem, destino;
    char tipo;
    int distancia;
    while (trajetoFile >> origem >> destino >> tipo >> distancia) {
        cadastrarTrajeto(origem, destino, tipo, distancia);
    }
    trajetoFile.close();

    std::ifstream transporteFile("transportes.txt");
    std::string transporteNome, localAtual;
    char transporteTipo;
    int capacidade, velocidade, distancia_entre_descansos, tempo_de_descanso;
    while (transporteFile >> transporteNome >> transporteTipo >> capacidade >> velocidade >> distancia_entre_descansos >> tempo_de_descanso >> localAtual) {
        cadastrarTransporte(transporteNome, transporteTipo, capacidade, velocidade, distancia_entre_descansos, tempo_de_descanso, localAtual);
    }
    transporteFile.close();

    std::ifstream passageiroFile("passageiros.txt");
    while (std::getline(passageiroFile, nome, ',')) {
        std::getline(passageiroFile, localAtual);
        cadastrarPassageiro(nome, localAtual);
    }
    passageiroFile.close();
}
