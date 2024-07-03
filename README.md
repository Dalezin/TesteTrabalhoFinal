# Projeto de Gerenciamento de Hotel

Este projeto implementa um sistema simples de gerenciamento de hotel em C, com funcionalidades básicas para cadastrar clientes, funcionários, quartos e estadias.

## Funcionalidades Implementadas

### 1. Cadastro de Clientes
Permite cadastrar novos clientes, incluindo nome, endereço e telefone.

### 2. Cadastro de Funcionários
Permite cadastrar novos funcionários, incluindo nome, telefone, cargo e salário.

### 3. Cadastro de Quartos
Permite cadastrar novos quartos, especificando número do quarto, capacidade de hóspedes e valor da diária.

### 4. Registro de Estadias
Permite registrar estadias de clientes, associando um cliente a um quarto e registrando datas de entrada e saída.

### 5. Cálculo de Diárias
Calcula automaticamente a quantidade de diárias com base nas datas de entrada e saída fornecidas.

## Problemas no Projeto

Durante o desenvolvimento e testes do projeto, foram encontrados os seguintes problemas:

1. **Erro de Compilação com Munit:**
   Ao tentar compilar e executar testes com a biblioteca Munit para testes unitários, ocorreram erros para encontrar a pasta ex: gcc.exe: error: .h: No such file or directory, apesar de ser possivel encontrar o arquivo ao utlizar cd para abrir a pasta do munit e dir para encontrar o aplicativo
2. **Tentativas**
   Para tentar contornar tentei utilizar diversas alternativas como MakeFile, adicionar a pasta munit.h em um atalho, mas nada funciona. Acredito que o problema seja na minha maquina, pois todo o restante do codigo não da erro.

## Como Executar o Projeto

Para compilar e executar o projeto:

1. Certifique-se de ter um compilador C instalado (como GCC no Linux ou MinGW no Windows).
2. Inclua os arquivos necessários (`hotel_management.h`, `hotel_management.c`, `test_hotel_management.c` e `munit`) no diretório de compilação.
3. Compile o projeto usando o seguinte comando no terminal:
   gcc -o test_hotel_management hotel_management.c test_hotel_management.c -I/pastaDoMunit -L/pastaDoMunit -lmunit -lm
   Onde esta pastaDoMunit substituir pelo caminho ate a pasta do munit
4. Apos a copilação rode com:
   ./test_hotel_management
   
   5.Caso queira tentar com make file utilize:
  make
  ./test_hotel_management
