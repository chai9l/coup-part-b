#include "Ambassador.hpp"

using namespace std;
namespace coup
{
    Ambassador::Ambassador(Game &game, const string &name) {
        if (game.all_players.size() >= 6) {
            throw out_of_range("Number of players cannot exceed 6");
        }
        game.add_player(this);
        string n = name;
        this->set_name(n);
        this->g = &game;
        this->myRole = "Ambassador";
        this->set_turn(game.t);
        game.t++;
        this->g->turns.resize(this->g->all_players.size());
    }

    void Ambassador::transfer(Player &p1, Player &p2) {
        if (this->coins() >= 10) {
            throw invalid_argument("Got to use coup!");
        }
        if (this->get_status()) {
            throw invalid_argument("Cannot transfer whilst being out of the game");
        }
        if (this->get_turn() != this->g->curr_turn) {
            throw logic_error("This is not you'r turn");
        }
        if (this->g->curr_turn != this->get_turn()) {
            throw logic_error("This is not you'r turn !");
        }
        if (p1.coins() <= 0) {
            throw logic_error("The player you'r trying to transfer from has 0 coins");
        }
        p1.num_of_coins -= 1;
        p2.num_of_coins += 1;
        this->g->game_started = true;
        this->g->turns[this->get_turn()-1] = "transfer";
        this->g->endTurn();
    }

    void Ambassador::block(Player &p) {
        string p_action = this->g->turns[p.get_turn()-1];
        if (this->get_status()) {
            throw invalid_argument("Cannot block whilst being out of the game");
        }
        if (p.get_status()) {
            throw invalid_argument("Cannot block a dead player");
        }
        if (p.role() != "Captain") {
            throw invalid_argument("The player you're trying to block is not a Captain");
        }
        if (p_action != "steal") {
            throw invalid_argument("Trying to block when no steal occured");
        }
        if (p_action == "steal") {
            p.num_of_coins -= 2;
            for (Player* temp_p : this->g->all_players) {
                if (temp_p->get_name() == p.p_i_stole) {
                    temp_p->num_of_coins += 2;
                }
                else {
                    continue;
                }
            }
        }
    }

    Ambassador::~Ambassador() {}
}