#include "Player.hpp"

using namespace std;

namespace coup
{

    void Player::income()
    {
        if (this->get_status()) {
            throw invalid_argument("Cannot use income whilst being out of the game");
        }
        if (this->get_turn() != this->g->curr_turn) {
            throw logic_error("This is not you'r turn");
        }
        if (this->coins() >= 10) {
            throw invalid_argument("Got to use coup!");
        }
        if (this->g->all_players.size() < 2) {
            throw "too few players";
        }
        this->g->turns[this->turn-1] = "income";
        this->g->game_started = true;
        this->num_of_coins++;
        this->g->endTurn();
    }
    void Player::foreign_aid()
    {
        if (this->get_status()) {
            throw invalid_argument("Cannot use foriegn aid whilst being out of the game");
        }
        if (this->get_turn() != this->g->curr_turn) {
            throw logic_error("This is not you'r turn");
        }
        if (this->coins() >= 10) {
            throw invalid_argument("Got to use coup!");
        }
        if (this->g->all_players.size() < 2) {
            throw "too few players";
        }
        this->g->turns[this->turn-1] = "aid";
        this->g->game_started = true;
        this->num_of_coins += 2;
        this->g->endTurn();
    }

    void Player::coup(Player &p)
    {
        if (this->get_status()) {
            throw invalid_argument("Cannot coup whilst being out of the game");
        }
        if (p.get_status()) {
            throw invalid_argument("The player you're trying to eliminate is already out of the game");
        }
        if (this->get_turn() != this->g->curr_turn) {
            throw logic_error("This is not you'r turn");
        }
        if (this->num_of_coins < 7)
        {
            throw "Cannot use coup with less than 7 coins";
            
        }
        this->g->turns[this->turn-1] = "coup"; 
        this->num_of_coins -= 7;
        p.status = true;
        this->g->game_started = true;
        this->g->endTurn();
    }

    int Player::coins()
    {
        return this->num_of_coins;
    }

    std::string Player::role()
    {
        return this->myRole;
    }
    
    string Player::get_name()
    {
        return this->name;
    }

    void Player::set_name(string &n)
    {
        this->name = n;
    }

    bool Player::get_status() {
        return this->status;
    }

    void Player::set_status(bool b) {
        this->status = b;
    }

    void Player::set_turn(unsigned int n) {
        this->turn = n;
    }

    unsigned int Player::get_turn() {
        return this->turn;
    }

    void Player::set_p_i_assasinate(string &p) {
        this->p_i_assasinate = p;
    }
    
}
