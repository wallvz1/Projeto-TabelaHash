#Projeto: Sistema de Autenticação com Tabela Hash

• Pedro Carvalho Furtado
• Matheus Cavalcanti
• João Gabriel Diniz Gastão

1. Descrição Geral

O projeto consiste no desenvolvimento de um Sistema de Autenticação implementado em C, utilizando uma Tabela Hash construída do zero.
O sistema permite:

Cadastro de usuários

Login com validação de credenciais

Remoção de usuários

Impressão da tabela hash, incluindo colisões

Armazenamento seguro usando hash da senha, e não a senha original

O principal foco do trabalho é demonstrar o uso de:

Funções de hashing

Tabela hash com tratamento de colisões

Estruturas dinâmicas

Alocação e liberação de memória

Modularização do código

Encadeamento separado para lidar com colisões

O projeto simula um sistema simples de login, aplicando conceitos fundamentais de estruturas de dados.

2. Objetivo e Justificativa

O objetivo é implementar um sistema funcional de autenticação em C, explorando os principais conceitos de:

Estruturas de dados

Tabelas hash

Tratamento de colisões

hashing de strings

gerenciamento de memória dinâmica

A justificativa da escolha do tema se baseia em dois pontos principais:

🔹 Importância prática

Tabelas hash são amplamente utilizadas em sistemas reais — autenticação, bancos de dados, caches, compiladores e estruturas de dados internas.

🔹 Valor didático

Implementar uma tabela hash do zero é um excelente exercício de raciocínio lógico, ponteiros, alocação dinâmica e modularização.

Além disso, por ser um problema real da computação, o projeto estimula o entendimento prático desses conceitos e facilita a aprendizagem.

3. Tecnologias Utilizadas

Linguagem: C (padrão ANSI C)

Paradigma: Estruturado

Compilador: GCC

Ambiente: Terminal (CLI)

Bibliotecas usadas:

stdio.h

stdlib.h

string.h

4. Estrutura do Projeto

O código é dividido em múltiplos arquivos para melhor organização e modularização.

Arquivo	Função Principal
main.c	Contém o menu e controla a interação com o usuário.
hash.c	Implementa a tabela hash, funções de hash e operações CRUD.
hash.h	Declara estruturas, protótipos e constantes.
