#ifndef HOTEL_MANAGEMENT_H
#define HOTEL_MANAGEMENT_H

#define MAX_CLIENTES 100
#define MAX_FUNCIONARIOS 50
#define MAX_ESTADIAS 200
#define MAX_QUARTOS 50

#include <time.h>
#include <stdio.h>

typedef struct {
    int codigo;
    char nome[50];
    char endereco[100];
    char telefone[20];
} Cliente;

typedef struct {
    int codigo;
    char nome[50];
    char telefone[20];
    char cargo[30];
    float salario;
} Funcionario;

typedef struct {
    int codigo;
    int codigo_cliente;
    int numero_quarto;
    char data_entrada[11];
    char data_saida[11];
    int quantidade_diarias;
} Estadia;

typedef struct {
    int numero;
    int quantidade_hospedes;
    float valor_diaria;
    char status[15]; // ocupado ou desocupado
} Quarto;

extern Cliente clientes[MAX_CLIENTES];
extern Funcionario funcionarios[MAX_FUNCIONARIOS];
extern Estadia estadias[MAX_ESTADIAS];
extern Quarto quartos[MAX_QUARTOS];

extern int total_clientes;
extern int total_funcionarios;
extern int total_estadias;
extern int total_quartos;

int calcular_diarias(const char *data_entrada, const char *data_saida);
void cadastrar_cliente(const char* nome, const char* endereco, const char* telefone);
void cadastrar_funcionario(const char* nome, const char* telefone, const char* cargo, float salario);
void cadastrar_quarto(int numero, int quantidade_hospedes, float valor_diaria);
void cadastrar_estadia(int codigo_cliente, const char* data_entrada, const char* data_saida);

#endif // HOTEL_MANAGEMENT_H
