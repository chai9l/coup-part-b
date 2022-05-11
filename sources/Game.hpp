#pragma once
#include "vector"
#include <string>

using namespace std;

namespace coup
{
    class Player;
    class Game
    {
    public:
        unsigned int t = 1;
        unsigned int curr_turn = 1;
        vector<Player*> all_players;
        vector<string> turns;
        bool game_started = false;

        Game();
        vector<string> active_players();
        void add_player(Player* p);
        string turn();
        string winner();
        vector<string> players();
        void endTurn();
    };

}