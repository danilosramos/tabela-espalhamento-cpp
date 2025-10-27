#ifndef MINHA_TABELA_ESPALHAMENTO_H
#define MINHA_TABELA_ESPALHAMENTO_H

#include "MinhaListaEncadeada.h"
#include "TabelaEspalhamentoAbstrata.h"
#include "excecoes.h"

#include <type_traits>
#include <string>
#include <cmath>

template <typename T, std::size_t capac>
class MinhaTabelaEspalhamento final : public TabelaEspalhamentoAbstrata<T, capac>
{
public:
    MinhaTabelaEspalhamento();

    std::size_t capacidade() const override;
    void inserir(T dado) override;
    void remover(T dado) override;
    bool contem(T dado) const override;
    std::size_t quantidade() const override;

protected:
    std::size_t funcaoEspalhamento(T dado) const override;

private:
    std::size_t _quantidade;

    template <typename U>
    std::size_t codigoEspalhamento(U integral) const;

    std::size_t codigoEspalhamento(std::string const &string) const;
};

template <typename T, std::size_t capac>
MinhaTabelaEspalhamento<T, capac>::MinhaTabelaEspalhamento() : _quantidade(0) {}

template <typename T, std::size_t capac>
std::size_t MinhaTabelaEspalhamento<T, capac>::capacidade() const
{
    return capac;
}

template <typename T, std::size_t capac>
void MinhaTabelaEspalhamento<T, capac>::inserir(T dado)
{
    std::size_t posicao = funcaoEspalhamento(dado);
    if (!this->tabela[posicao].contem(dado))
    {
        this->tabela[posicao].inserirNoFim(dado);
        ++_quantidade;
    }
}

template <typename T, std::size_t capac>
void MinhaTabelaEspalhamento<T, capac>::remover(T dado)
{
    std::size_t posicao = funcaoEspalhamento(dado);
    if (!this->tabela[posicao].contem(dado))
        throw ExcecaoDadoInexistente();
    this->tabela[posicao].remover(dado);
    _quantidade--;
}

template <typename T, std::size_t capac>
bool MinhaTabelaEspalhamento<T, capac>::contem(T dado) const
{
    std::size_t posicao = funcaoEspalhamento(dado);
    return this->tabela[posicao].contem(dado);
}

template <typename T, std::size_t capac>
std::size_t MinhaTabelaEspalhamento<T, capac>::quantidade() const
{
    return _quantidade;
}

template <typename T, std::size_t capac>
std::size_t MinhaTabelaEspalhamento<T, capac>::funcaoEspalhamento(T dado) const
{
    if constexpr (std::is_integral_v<T>)
        return codigoEspalhamento(dado) % capac;
    else if constexpr (std::is_same_v<T, std::string>)
        return codigoEspalhamento(dado) % capac;
    else
        static_assert(std::is_same_v<T, void>);
}

template <typename T, std::size_t capac>
template <typename U>
std::size_t MinhaTabelaEspalhamento<T, capac>::codigoEspalhamento(U integral) const
{
    static_assert(std::is_integral_v<U>, "Tipo deve ser integral");
    return static_cast<std::size_t>(integral);
}

template <typename T, std::size_t capac>
std::size_t MinhaTabelaEspalhamento<T, capac>::codigoEspalhamento(std::string const &string) const
{
    std::size_t codigo = 0;
    std::size_t expoente = 1;

    for (auto it = string.rbegin(); it != string.rend(); ++it)
    {
        codigo += (*it) * expoente;
        expoente *= 31;
    }

    return codigo;
}

#endif
