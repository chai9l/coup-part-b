#include "Game.hpp"
#include <string>
#include <vector>
#include <stdio.h>
#include <err.h>
#include <stdexcept>
#include <iostream>

#pragma once
using namespace std;

namespace coup{
    class Game;
    class Player{
        private:
        std::string name;
        bool status = false;
        unsigned int turn;

        public:
        Game *g;
        string myRole;
        int num_of_coins = 0;
        string p_i_stole; // Relevant only for captains
        string p_i_assasinate; // Relevant only for assasins

        void income();
        void foreign_aid();
        void coup(Player &p);
        string role();
        int coins();

        string get_name();
        void set_name(string &n);
        bool get_status();
        void set_status(bool b);
        void set_turn(unsigned int n);
        void set_p_i_assasinate(string &p);

        unsigned int get_turn();
    };
}