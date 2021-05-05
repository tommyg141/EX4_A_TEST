#include "Board.hpp"
using namespace pandemic;
using namespace std;

int& Board::operator[](City s)
{
    return temp[s];
}
bool Board::is_clean()
{
    return true;
}
std::ostream& pandemic::operator<<(std::ostream &output, const Board &boaed)
{
    return output;
}
void pandemic::Board::remove_cures (){
    
}