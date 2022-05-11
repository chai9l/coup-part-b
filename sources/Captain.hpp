#include "Player.hpp"

namespace coup
{
    class Captain : public Player
    {
    public:
        Captain(Game &game, const std::string &name);
        void block(Player &p);
        void steal(Player &p);
        ~Captain();
    };
}