# Projeto Sistema de Autenticação com Tabela Hash

• Pedro Carvalho Furtado
• Matheus Cavalcanti
• João Gabriel Diniz Gastão

## 1. Descrição Geral

O projeto ***Sistema de Autenticação com Tabela Hash** consiste em uma implementação de um mecanismo simples de cadastro e login de usuários, desenvolvida em **C**, com o objetivo de aplicar os principais conceitos de **Estruturas de Dados**, como hashing, alocação dinâmica e tratamento de colisões.

O sistema simula um ambiente básico de autenticação, armazenando apenas o nome de usuário e o hash da senha, garantindo que a senha original nunca seja salva.
A tabela hash foi implementada inteiramente do zero, utilizando o método da multiplicação como função de hash e encadeamento separado como estratégia de tratamento de colisões.

---

## 2. Objetivo e Justificativa

O principal objetivo do projeto é construir um sistema funcional que permita:

 -Cadastrar usuários
 -Realizar login comparando o hash da senha
 -Remover usuários
 -Exibir toda a tabela hash incluindo colisões
 -O tema foi escolhido por integrar vários conteúdos fundamentais da disciplina:
 -Hashing de strings
 -Conversão de valores em índices
 -Estruturas dinâmicas (listas encadeadas)
 -Modularização em múltiplos arquivos .c e .h
 -Alocação e liberação de memória com malloc e free
 -Tabelas hash são amplamente utilizadas em sistemas reais como autenticação, caches, bancos de dados e indexação, tornando o projeto altamente relevante.

---

## 3. Tecnologias Utilizadas
 
- **Linguagem:** C
- **Paradigma:** Programação Estruturada
- **Ambiente de execução:** Terminal (CLI)
- **Bibliotecas padrão:** stdio.h, stdlib.h, string.h

---

## 4. Estrutura do Projeto

O projeto está organizado em módulos independentes, seguindo boas práticas de modularização:

| Arquivo |	| Função Principal |
|--------|------------------|
| `main.c` | Contém o menu do sistema e controla a interação com o usuário. |
| `hash.c` | Implementa todas as operações da tabela hash. |
| `hash.h` | Declara as estruturas e protótipos utilizados em todo o sistema. |

Principais componentes:

| Componente | | Função |
| `Hash` |	Estrutura base contendo o vetor principal da tabela. |
| `Usuario` |	Nó que armazena username, hash da senha e ponteiro para próximo (lista encadeada). |
| `valorString()` |	Converte um texto (username) em valor numérico. |
| `chaveMultiplicacao()`	Calcula o índice usando o método da multiplicação. |
| `insereHash()`	Insere usuários e trata colisões criando listas encadeadas. |
| `buscaHash()` |	Realiza busca pelo username. |
| `removeHash()` |	Remove um usuário mantendo a integridade da lista. |
| `imprimeHash()` |	Exibe a tabela hash completa, mostrando colisões. |

---

## 5. Como Executar o Projeto

### Pré-requisitos
- Ter o **GCC** instalado
- Um **terminal** (cmd, PowerShell, Linux, GitHub Codespaces, etc.)

### Passos para execução via terminal
1.**Abra o terminal** na pasta raiz do projeto.
2.**Compile os arquivos:**
  ```bash
  gcc main.c hash.c -o main
  ```
3.**Execute o Sistema**
 ```bash
 ./main
 ```

O programa iniciará exibindo um menu interativo, permitindo cadastrar usuários, realizar login, remover registros e visualizar a tabela hash, incluindo colisões representadas por listas encadeadas.
