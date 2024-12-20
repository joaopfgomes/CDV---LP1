#include <iostream>
#include "ControladorDeTransito.h"

int main() {
    ControladorDeTransito controlador;

    // Carregar dados de arquivos, se existirem
    controlador.carregarDados();

    // Menu de opções
    int opcao;
    do {
        std::cout << "Escolha uma opção: \n";
        std::cout << "1. Cadastrar Cidade\n";
        std::cout << "2. Cadastrar Trajeto\n";
        std::cout << "3. Cadastrar Transporte\n";
        std::cout << "4. Cadastrar Passageiro\n";
        std::cout << "5. Relatar Estado\n";
        std::cout << "6. Sair\n";
        std::cin >> opcao;

        std::cin.ignore(); // Limpar o buffer de entrada

        if (opcao == 1) {
            std::string nomeCidade;
            std::cout << "Digite o nome da cidade: ";
            std::getline(std::cin, nomeCidade);
            controlador.cadastrarCidade(nomeCidade);
        }
        else if (opcao == 2) {
            std::string origem, destino;
            char tipo;
            int distancia;
            std::cout << "Digite o nome da cidade de origem: ";
            std::getline(std::cin, origem);
            std::cout << "Digite o nome da cidade de destino: ";
            std::getline(std::cin, destino);
            std::cout << "Digite o tipo (T para Terrestre, A para Aquático): ";
            std::cin >> tipo;
            std::cout << "Digite a distância: ";
            std::cin >> distancia;
            controlador.cadastrarTrajeto(origem, destino, tipo, distancia);
        }
        else if (opcao == 3) {
            std::string nome, localAtual;
            char tipo;
            int capacidade, velocidade, distancia_entre_descansos, tempo_de_descanso;
            std::cout << "Digite o nome do transporte: ";
            std::getline(std::cin, nome);
            std::cout << "Digite o tipo (T para Terrestre, A para Aquático): ";
            std::cin >> tipo;
            std::cout << "Digite a capacidade: ";
            std::cin >> capacidade;
            std::cout << "Digite a velocidade: ";
            std::cin >> velocidade;
            std::cout << "Digite a distância entre descansos: ";
            std::cin >> distancia_entre_descansos;
            std::cout << "Digite o tempo de descanso: ";
            std::cin >> tempo_de_descanso;
            std::cin.ignore();  // Limpar o buffer
            std::cout << "Digite a cidade de origem: ";
            std::getline(std::cin, localAtual);
            controlador.cadastrarTransporte(nome, tipo, capacidade, velocidade, distancia_entre_descansos, tempo_de_descanso, localAtual);
        }
        else if (opcao == 4) {
            std::string nome, localAtual;
            std::cout << "Digite o nome do passageiro: ";
            std::getline(std::cin, nome);
            std::cout << "Digite a cidade atual do passageiro: ";
            std::getline(std::cin, localAtual);
            controlador.cadastrarPassageiro(nome, localAtual);
        }
        else if (opcao == 5) {
            controlador.relatarEstado();
        }

        // Salvar dados sempre que houver alterações
        controlador.salvarDados();

    } while (opcao != 6);

    return 0;
}
