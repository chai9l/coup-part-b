#include "Player.hpp"

namespace coup
{
    class Assassin : public Player
    {
    private:
    public:
        Assassin(Game &game, const std::string &name);
        void coup(Player &p);
        ~Assassin();
    };

}