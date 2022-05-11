#include "Player.hpp"

namespace coup
{
    class Duke : public Player
    {
    private:
    public:
        Duke(Game &game, const std::string &name);
        void tax();
        void block(Player &p);
        ~Duke();
    };
}