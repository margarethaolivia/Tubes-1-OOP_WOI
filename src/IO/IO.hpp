#ifndef IO_HPP
#define IO_HPP

// #include "../Game/Game.hpp"
#include "../Exception/exception.h"
// #include "../Player/Player.hpp"
#include "../Table/Table.hpp"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <map>
using namespace std;

class Player;
class Game;
class Point;

const map<char, CardColor> stringToColor = {
    {'R', Red},
    {'G', Green},
    {'B', Blue},
    {'Y', Yellow}
};


class IO {

    private:   
        string lineColor = "\033[1;33m";
        string resetColor = "\033[0m";
        string wordColor = "\033[1;36m";
        string inputColor = "\033[1;36m";
        string enterColor = "\033[5;1;33m";
        string abilColor = "\033[1;32m";
        string actnColor = "\033[1;34m";

    public :    

        /* print function*/
        void splashScreen();
        void printThankYou();
        void printTable(Table);
        void printEndGame(const vector<pair<Player&, bool>>&);
        
        /* main menu */
        string mainMenu();  
        vector<string> inputPlayerName();
        string turnInput(const Player&);
        string dealMenu();
        
        /* success message function*/
        void printAbilitySuccess(Player player, vector<string> resPlayer = {}, vector<string> reversed = {});
        void printAbilitySuccess(const Player&, const Point&);  
        void printActionSuccess(const Player& ,const Point&, int );

        /* select function */
        vector<Player*> selectPlayer(const Player& , const vector<pair<Player&, bool>>& ) const;
        int selectCard(string);

        /* Special for Abilityless*/
        void printAbilityless(string nick = "");

        /* input File*/
        pair<vector<Card>, vector<Ability*>> inputFile();
        Ability* stringToAbility(string code);

};

#endif