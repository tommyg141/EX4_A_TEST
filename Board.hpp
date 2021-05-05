
#pragma once
#include <map>
#include "City.hpp"
#include "Color.hpp"

namespace pandemic
{
    class Board
    {

         std::map<City, int> temp;

    public:
        Board() {}
        bool is_clean();
        int& operator[](City s);
        friend std::ostream& operator<<(std::ostream &output, const Board &boaed);
      void remove_cures(); 
    };

}