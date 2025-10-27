# Tabela de Espalhamento (Hash Table) em C++

Este projeto apresenta a implementação de uma **Tabela de Espalhamento (Hash Table)** em C++.

A Tabela de Espalhamento é uma estrutura de dados essencial para o armazenamento eficiente de dados, permitindo operações de inserção, busca e remoção em tempo médio **O(1)**.

## Conceitos Demonstrados

*   **Estruturas de Dados:** Implementação de uma Tabela Hash.
*   **Resolução de Colisões:** Utilização de **encadeamento separado (Separate Chaining)** para lidar com colisões, onde cada *bucket* da tabela armazena uma lista encadeada de elementos.
*   **Programação Orientada a Objetos (POO):** Uso de classes e herança para a estrutura da tabela.
*   **Função Hash:** Implementação de uma função de espalhamento para mapear chaves para índices da tabela.

## Estrutura do Projeto

| Arquivo | Descrição |
| :--- | :--- |
| `TabelaEspalhamentoAbstrata.h` | Interface (classe abstrata) que define os métodos da Tabela Hash. |
| `MinhaTabelaEspalhamento.h` | Implementação concreta da Tabela de Espalhamento. |
| `Posicao.h` | Classe auxiliar para representar a posição na tabela. |
| *Arquivos de Lista Encadeada* | A implementação depende de uma Lista Encadeada para o encadeamento separado. |

## Como Compilar e Executar

Este projeto é um conjunto de arquivos de cabeçalho e deve ser integrado a um arquivo de teste (`main.cpp`) e aos arquivos da Lista Encadeada para funcionar.

1.  Certifique-se de ter um compilador C++ (como g++) e os arquivos da Lista Encadeada (do `lista-encadeada-cpp`) no mesmo ambiente.
2.  Compile o projeto:
    ```bash
    g++ -std=c++17 main.cpp -o hash_table_test
    ```
3.  Execute o teste:
    ```bash
    ./hash_table_test
    ```

---
**Linguagem:** C++
**Tópicos:** Tabela Hash, Estruturas de Dados, Resolução de Colisões, POO.
'''
