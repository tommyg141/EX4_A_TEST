#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <vector>
#include <stdlib.h>
#include "Player.hpp"
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
#include "OperationsExpert.hpp"


using namespace pandemic;
using namespace std;

// TEST_CASE("medic") {}
// TEST_CASE("FieldDoctor") {}
// TEST_CASE("GeneSplicer") {}
// TEST_CASE("OperationsExpert") {}
// TEST_CASE("Researcher") {}
// TEST_CASE("Scientist") {}
// TEST_CASE("Virologist") {}
// TEST_CASE("Dispatcher") {}


TEST_CASE("just_demo1")
{
    Board just_for_test;
    just_for_test[City::Delhi] = 0;         /// black
    just_for_test[City::HoChiMinhCity] = 0; //red
    just_for_test[City::Kolkata] = 2;       //black
    just_for_test[City::Mumbai] = 3;        //black
    just_for_test[City::Bangkok] = 4;       //red
    OperationsExpert yoav{just_for_test, City::Delhi};
    yoav.take_card(Delhi);
    yoav.take_card(HoChiMinhCity);
    yoav.take_card(Kolkata);
    yoav.take_card(Mumbai);
    yoav.take_card(Bangkok);
    CHECK_THROWS(yoav.discover_cure(Black));
    CHECK_THROWS(yoav.treat(Mumbai));
    yoav.fly_direct(HoChiMinhCity);
    yoav.discover_cure(Black);
    yoav.fly_direct(Delhi);
    yoav.treat(Delhi);

    CHECK_NOTHROW(yoav.discover_cure(Black));
    CHECK_NOTHROW(yoav.treat(Delhi));
    CHECK_NOTHROW(yoav.treat(HoChiMinhCity));
    CHECK_NOTHROW(yoav.treat(Kolkata));
    CHECK_NOTHROW(yoav.treat(Mumbai));
    CHECK_NOTHROW(yoav.treat(Bangkok));
    CHECK_NOTHROW(yoav.discover_cure(Black));
    CHECK_NOTHROW(yoav.discover_cure(Red));
    CHECK_NOTHROW(yoav.discover_cure(Blue));
    CHECK_NOTHROW(yoav.discover_cure(Yellow));
    CHECK_NOTHROW(yoav.fly_direct(Bangkok));
    CHECK_NOTHROW(yoav.fly_direct(HoChiMinhCity));
    CHECK_NOTHROW(yoav.fly_direct(Mumbai));
    CHECK_NOTHROW(yoav.fly_direct(Delhi));
    CHECK_NOTHROW(yoav.fly_direct(Kolkata));
    CHECK_NOTHROW(yoav.fly_charter(HoChiMinhCity));
    CHECK_NOTHROW(yoav.build());
    CHECK_NOTHROW(yoav.fly_shuttle(HoChiMinhCity));
}