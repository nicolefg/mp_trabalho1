// Copyright (c) 2023, Nicole Ferreira Gomes
#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "romanos.hpp"

TEST_CASE("Numeros romanos - algarismos unicos", "[romanos]") {
    REQUIRE(romanos_para_decimal("I") == 1);
    REQUIRE(romanos_para_decimal("II") == 2);
    REQUIRE(romanos_para_decimal("XXX") == 30);
    REQUIRE(romanos_para_decimal("XXI") == 21);
    REQUIRE(romanos_para_decimal("CCLXVIII") == 268);
    REQUIRE(romanos_para_decimal("MMCMXX") == 2920);
    REQUIRE(romanos_para_decimal("MMCCCXXI") == 2321);
    REQUIRE(romanos_para_decimal("MCCXXII") == 1222);
    REQUIRE(romanos_para_decimal("DCCCLXIII") == 863);
    REQUIRE(romanos_para_decimal("CLXVII") == 167);
    REQUIRE(romanos_para_decimal("CDXX") == 420);
    REQUIRE(romanos_para_decimal("MCMXCI") == 1991);
    REQUIRE(romanos_para_decimal("MMXV") == 2015);
    REQUIRE(romanos_para_decimal("CMXCIV") == 994);
    REQUIRE(romanos_para_decimal("CDXVIII") == 418);
}

TEST_CASE("Numeros romanos - algarismos invalidos", "[romanos]") {
    REQUIRE(romanos_para_decimal("G") == -1);
    REQUIRE(romanos_para_decimal("i") == -1);
    REQUIRE(romanos_para_decimal("VV") == -1);
    REQUIRE(romanos_para_decimal("XXXX") == -1);
    REQUIRE(romanos_para_decimal("NICOLE") == -1);
    REQUIRE(romanos_para_decimal("VIIL") == -1);
    REQUIRE(romanos_para_decimal("ID") == -1);
    REQUIRE(romanos_para_decimal("LXIIII") == -1);
    REQUIRE(romanos_para_decimal("XVX") == -1);
}

