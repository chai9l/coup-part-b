#include "Captain.hpp"

namespace coup
{
    Captain::Captain(Game &game, const std::string &name) {
        if (game.all_players.size() >= 6) {
            throw logic_error("Number of players cannot exceed 6");
        }
        string n = name;
        this->set_name(n);
        this->g = &game;
        this->myRole = "Captain";
        game.add_player(this);
        this->set_turn(game.t);
        game.t++;
        this->g->turns.resize(this->g->all_players.size()); 
    }

    void Captain::block(Player &p)
    {
        string p_action = this->g->turns[p.get_turn()-1];
        if (this->get_status()) {
            throw invalid_argument("Cannot play whilst being out of the game");
        }
        if (p.get_status())
        {
            throw invalid_argument("Cannot block a dead player");
        }
        if (p.role() != "Captain")
        {
            throw invalid_argument("The player you're trying to block is not a Captain");
        }
        if (p_action != "steal")
        {
            throw invalid_argument("Trying to block when no steal occured");
        }
        if (p_action == "steal")
        {
            p.num_of_coins -= 2;
            for (Player* temp_p : this->g->all_players)
            {
                if (temp_p->get_name() == p.p_i_stole)
                {
                    temp_p->num_of_coins += 2;
                }
                else
                {
                    continue;
                }
            }
        }
    }

    void Captain::steal(Player &p)
    {
        if (this->get_status()) {
            throw invalid_argument("Cannot play whilst being out of the game");
        }
        if (this->coins() >= 10) {
            throw invalid_argument("Got to use coup!");
        }
        if (this->get_turn() != this->g->curr_turn) {
            throw logic_error("This is not you'r turn");
        }
        if (p.get_status())
        {
            throw invalid_argument("Cannot steal from a dead player");
        }
        if (p.coins() < 1)
        {
            throw invalid_argument("Cannot steal, target has no coins");
        }
        if (p.coins() == 1)
        {
            this->num_of_coins += 1;
            p.num_of_coins -= 1;
            this->g->turns[this->get_turn()-1] = "steal";
            this->g->game_started = true;
            this->p_i_stole = p.get_name();
            this->g->curr_turn++;
            if (this->g->all_players.size() < this->g->curr_turn)
            {
                this->g->curr_turn = 1;
            }
        }
        else
        {
            this->num_of_coins += 2;
            p.num_of_coins -= 2;
            this->g->turns[this->get_turn()-1] = "steal";
            this->p_i_stole = p.get_name();
            this->g->endTurn();
        }
    }
    Captain::~Captain() {}
}