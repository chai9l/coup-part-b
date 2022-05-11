#include "Player.hpp"

namespace coup
{
    class Ambassador : public Player
    {
    public:
        Ambassador(Game &game, const std::string &name);
        void transfer(Player &p1, Player &p2);
        void block(Player &p);
        ~Ambassador();
    };
}