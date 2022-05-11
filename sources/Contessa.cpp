#include "Contessa.hpp"

namespace coup
{
    Contessa::Contessa(Game &game, const std::string &name) {
        if (game.all_players.size() >= 6) {
            throw logic_error("Number of players cannot exceed 6");
        }
        string n = name;
        this->set_name(n);
        this->g = &game;
        this->myRole = "Contessa";
        game.add_player(this);
        this->set_turn(game.t);
        game.t++;  
        this->g->turns.resize(this->g->all_players.size());
    }

    void Contessa::block(Player &p) {
        if (this->get_status()) {
            throw invalid_argument("Cannot block whilst being out of the game");
        }
        string p_action = this->g->turns[p.get_turn()-1];
        if (p.role() != "Assassin")
        {
            throw invalid_argument("The player you're trying to block is not a Assassin");
        }
        if (p_action != "assasinate")
        {
            throw invalid_argument("Trying to block when no assasinate occured");
        }
        if (p_action == "assasinate")
        {
            for (Player* temp_p : this->g->all_players)
            {
                if (temp_p->get_name() == p.p_i_assasinate)
                {
                    temp_p->set_status(false);
                }
                else
                {
                    continue;
                }
            }
        }        
    }
    
    Contessa::~Contessa() {}
}