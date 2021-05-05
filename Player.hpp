#pragma once
#include "Board.hpp"
#include "City.hpp"
#include "Color.hpp"
namespace pandemic
{
    class Player
    {
    protected:
        Board board;
        City city;
        std::string player_role;

    public:

        Player(Board &b, City c, std::string r) : board(b), city(c), player_role(r) {}

        Player& take_card(City c);
        Player& drive(City c);
        virtual Player &fly_direct(City c);
        Player& fly_charter(City c);
        Player& fly_shuttle(City c);
        virtual Player &build();
        virtual Player &discover_cure(Color c);
        virtual Player &treat(City c);
        std::string role() { return player_role; }
    };

}