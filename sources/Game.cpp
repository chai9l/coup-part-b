#include "iostream"
#include "Game.hpp"
#include "vector"
#include <string>
#include "Player.hpp"

using namespace std;

namespace coup
{
    Game::Game() {}

    vector<string> Game::players() {
        return Game::active_players();
    }

    vector<string> Game::active_players()
    {
        vector<string> ret;
        for (Player* p: this->all_players) {
            if (!p->get_status()) {
                ret.push_back(p->get_name());
            }
        }
        return ret;
    }

    string Game::turn()
    {
        int counter = 1;
        string ret;
        for (Player* p : this->all_players) {
            if (curr_turn == counter) {
                ret = p->get_name();
            }
            else {
                counter++;
            }
        }
        return ret;
    }

    string Game::winner()
    {
        vector<string> active_players = this->active_players();
        if (!this->game_started) {
            throw "Game hasn't started yet";
        }
        if (this->t <= 2) {
            throw "game didnt start yet";
        }
        if (active_players.size() != 1) {
            throw logic_error("game in progress");
        }
        return active_players[0];
    }

    void Game::add_player(Player* p) {
        if (this->game_started) {
            throw "Can't add players while game is in session";
        }
        this->all_players.push_back(p);
    }

    void Game::endTurn() {
        curr_turn++;
        if (curr_turn > all_players.size()) {
            curr_turn = 1;
        }
        while (all_players[curr_turn-1]->get_status()) {
            curr_turn++;
            if (curr_turn > all_players.size()) {
                curr_turn = 1;
            }
        }
    }
}