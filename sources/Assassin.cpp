#include "Assassin.hpp"

using namespace std;

#define ASSISNATE_COST 3;

namespace coup
{

    Assassin::Assassin(Game &game, const std::string &name) {
        if (game.all_players.size() >= 6) {
            throw logic_error("Number of players cannot exceed 6");
        }
        string n = name;
        this->set_name(n);
        this->g = &game;
        this->myRole = "Assassin";
        game.add_player(this);
        this->set_turn(game.t);
        game.t++;    
        this->g->turns.resize(this->g->all_players.size());    
    }

    void Assassin::coup(Player &p) 
    {
        if (this->get_status()) {
            throw invalid_argument("Cannot coup whilst being out of the game");
        }
        if (this->get_turn() != this->g->curr_turn) {
            throw logic_error("This is not you'r turn");
        }
        if (this->get_status()) {
            throw invalid_argument("Cannot play whilst being out of the game");
        }
        if (this->coins() < (3)) {
            throw invalid_argument("Cannot coup with less than 3 coins");
        }
        if (p.get_status()) {
            throw invalid_argument("The player you're trying to eliminate is already out of the game");
        }
        if (this->num_of_coins >= 3 && this->num_of_coins <7) {
            this->g->turns[this->get_turn()-1] = "assasinate"; 
            this->num_of_coins -= 3;
        } else {
            this->g->turns[this->get_turn()-1] = "coup"; 
            this->num_of_coins -= 7;
        }
        
        this->g->game_started = true;
        p.set_status(true);
        this->p_i_assasinate = p.get_name();
        this->g->endTurn();
    }

    Assassin::~Assassin() {}
}