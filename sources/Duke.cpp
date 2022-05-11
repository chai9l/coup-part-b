#include "Duke.hpp"

namespace coup
{
    Duke::Duke(Game &game, const std::string &name) {
        if (game.all_players.size() >= 6) {
            throw logic_error("Number of players cannot exceed 6");
        }
        string n = name;
        this->set_name(n);
        this->g = &game;
        this->myRole = "Duke";
        game.add_player(this);
        this->set_turn(game.t);
        game.t++;
        this->g->turns.resize(this->g->all_players.size());
    }

    void Duke::tax() {
        if (this->get_status()) {
            throw invalid_argument("Cannot tax whilst being out of the game");
        }
        if (this->get_turn() != this->g->curr_turn) {
            throw logic_error("This is not you'r turn");
        }
        if (this->coins() >= 10) {
            throw invalid_argument("Got to use coup!");
        }
        this->g->game_started = true;
        this->g->turns[this->get_turn()-1] = "tax";
        this->num_of_coins += 3;
        this->g->endTurn();
    }

    void Duke::block(Player &p) {
        string p_action = this->g->turns[p.get_turn()-1];
        if (this->get_status()) {
            throw invalid_argument("Cannot block whilst being out of the game");
        }
        if (p_action != "aid")
        {
            throw invalid_argument("Trying to block when no foriegn aid occured");
        }
        if (p_action == "aid")
        {
            p.num_of_coins -= 2;
        }     
    }

    Duke::~Duke() {}
}