#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "hotel_management.h"
#include "munit.h"

static MunitResult test_calcular_diarias(const MunitParameter params[], void* user_data) {
    int result = calcular_diarias("01/01/2024", "05/01/2024");
    munit_assert_int(result, ==, 4);
    return MUNIT_OK;
}

static MunitResult test_cadastrar_cliente(const MunitParameter params[], void* user_data) {
    cadastrar_cliente("John Doe", "123 Main St", "555-1234");
    munit_assert_string_equal(clientes[0].nome, "John Doe");
    munit_assert_string_equal(clientes[0].endereco, "123 Main St");
    munit_assert_string_equal(clientes[0].telefone, "555-1234");
    munit_assert_int(clientes[0].codigo, ==, 1);
    return MUNIT_OK;
}

static MunitResult test_cadastrar_funcionario(const MunitParameter params[], void* user_data) {
    cadastrar_funcionario("Jane Smith", "555-5678", "Manager", 5000.0);
    munit_assert_string_equal(funcionarios[0].nome, "Jane Smith");
    munit_assert_string_equal(funcionarios[0].telefone, "555-5678");
    munit_assert_string_equal(funcionarios[0].cargo, "Manager");
    munit_assert_double(funcionarios[0].salario, ==, 5000.0);
    munit_assert_int(funcionarios[0].codigo, ==, 1);
    return MUNIT_OK;
}

static MunitResult test_cadastrar_quarto(const MunitParameter params[], void* user_data) {
    cadastrar_quarto(101, 2, 150.0);
    munit_assert_int(quartos[0].numero, ==, 101);
    munit_assert_int(quartos[0].quantidade_hospedes, ==, 2);
    munit_assert_double(quartos[0].valor_diaria, ==, 150.0);
    munit_assert_string_equal(quartos[0].status, "desocupado");
    return MUNIT_OK;
}

static MunitResult test_cadastrar_estadia(const MunitParameter params[], void* user_data) {
    cadastrar_cliente("John Doe", "123 Main St", "555-1234");
    cadastrar_quarto(101, 2, 150.0);
    cadastrar_estadia(1, "01/01/2024", "05/01/2024");
    munit_assert_int(estadias[0].codigo, ==, 1);
    munit_assert_int(estadias[0].codigo_cliente, ==, 1);
    munit_assert_int(estadias[0].numero_quarto, ==, 101);
    munit_assert_string_equal(estadias[0].data_entrada, "01/01/2024");
    munit_assert_string_equal(estadias[0].data_saida, "05/01/2024");
    munit_assert_int(estadias[0].quantidade_diarias, ==, 4);
    return MUNIT_OK;
}

static MunitTest tests[] = {
    { "/test_calcular_diarias", test_calcular_diarias, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_cadastrar_cliente", test_cadastrar_cliente, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_cadastrar_funcionario", test_cadastrar_funcionario, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_cadastrar_quarto", test_cadastrar_quarto, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { "/test_cadastrar_estadia", test_cadastrar_estadia, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL },
    { NULL, NULL, NULL, NULL, MUNIT_TEST_OPTION_NONE, NULL }
};

static const MunitSuite suite = {
    "/hotel_management_tests", tests, NULL, 1, MUNIT_SUITE_OPTION_NONE
};

int main(int argc, char* argv[MUNIT_ARRAY_PARAM(argc + 1)]) {
    return munit_suite_main(&suite, NULL, argc, argv);
}
