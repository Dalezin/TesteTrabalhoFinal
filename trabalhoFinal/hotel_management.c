#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "hotel_management.h"

// Implementação simplificada do strptime para Windows
char* strptime(const char* s, const char* f, struct tm* tm) {
    memset(tm, 0, sizeof(struct tm));
    if (sscanf(s, "%2d/%2d/%4d", &tm->tm_mday, &tm->tm_mon, &tm->tm_year) != 3) {
        return NULL;
    }
    tm->tm_mon -= 1;
    tm->tm_year -= 1900;
    return (char*)(s + strlen(s));
}

Cliente clientes[MAX_CLIENTES];
Funcionario funcionarios[MAX_FUNCIONARIOS];
Estadia estadias[MAX_ESTADIAS];
Quarto quartos[MAX_QUARTOS];

int total_clientes = 0;
int total_funcionarios = 0;
int total_estadias = 0;
int total_quartos = 0;

int calcular_diarias(const char *data_entrada, const char *data_saida) {
    struct tm entrada, saida;
    memset(&entrada, 0, sizeof(struct tm));
    memset(&saida, 0, sizeof(struct tm));
    strptime(data_entrada, "%d/%m/%Y", &entrada);
    strptime(data_saida, "%d/%m/%Y", &saida);
    time_t t_entrada = mktime(&entrada);
    time_t t_saida = mktime(&saida);
    double seconds = difftime(t_saida, t_entrada);
    return seconds / (60 * 60 * 24);
}

void cadastrar_cliente(const char* nome, const char* endereco, const char* telefone) {
    if (total_clientes >= MAX_CLIENTES) {
        printf("Capacidade máxima de clientes atingida.\n");
        return;
    }

    Cliente c;
    c.codigo = total_clientes + 1;
    strcpy(c.nome, nome);
    strcpy(c.endereco, endereco);
    strcpy(c.telefone, telefone);

    clientes[total_clientes++] = c;
    printf("Cliente cadastrado com sucesso. Código: %d\n", c.codigo);
}

void cadastrar_funcionario(const char* nome, const char* telefone, const char* cargo, float salario) {
    if (total_funcionarios >= MAX_FUNCIONARIOS) {
        printf("Capacidade máxima de funcionários atingida.\n");
        return;
    }

    Funcionario f;
    f.codigo = total_funcionarios + 1;
    strcpy(f.nome, nome);
    strcpy(f.telefone, telefone);
    strcpy(f.cargo, cargo);
    f.salario = salario;

    funcionarios[total_funcionarios++] = f;
    printf("Funcionário cadastrado com sucesso. Código: %d\n", f.codigo);
}

void cadastrar_quarto(int numero, int quantidade_hospedes, float valor_diaria) {
    if (total_quartos >= MAX_QUARTOS) {
        printf("Capacidade máxima de quartos atingida.\n");
        return;
    }

    Quarto q;
    q.numero = numero;
    q.quantidade_hospedes = quantidade_hospedes;
    q.valor_diaria = valor_diaria;
    strcpy(q.status, "desocupado");

    quartos[total_quartos++] = q;
    printf("Quarto cadastrado com sucesso. Número: %d\n", q.numero);
}

void cadastrar_estadia(int codigo_cliente, const char* data_entrada, const char* data_saida) {
    if (total_estadias >= MAX_ESTADIAS) {
        printf("Capacidade máxima de estadias atingida.\n");
        return;
    }

    int cliente_encontrado = 0;
    for (int i = 0; i < total_clientes; i++) {
        if (clientes[i].codigo == codigo_cliente) {
            cliente_encontrado = 1;
            break;
        }
    }
    if (!cliente_encontrado) {
        printf("Cliente não encontrado.\n");
        return;
    }

    int numero_quarto = -1;
    for (int i = 0; i < total_quartos; i++) {
        if (strcmp(quartos[i].status, "desocupado") == 0) {
            numero_quarto = quartos[i].numero;
            strcpy(quartos[i].status, "ocupado");
            break;
        }
    }
    if (numero_quarto == -1) {
        printf("Nenhum quarto desocupado disponível.\n");
        return;
    }

    Estadia e;
    e.codigo = total_estadias + 1;
    e.codigo_cliente = codigo_cliente;
    e.numero_quarto = numero_quarto;
    strcpy(e.data_entrada, data_entrada);
    strcpy(e.data_saida, data_saida);
    e.quantidade_diarias = calcular_diarias(data_entrada, data_saida);

    estadias[total_estadias++] = e;
    printf("Estadia cadastrada com sucesso. Código: %d\n", e.codigo);
}
