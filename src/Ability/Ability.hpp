#ifndef ABILITY_HPP
#define ABILITY_HPP

// #include <map>

#include <iostream>
using namespace std;

class Game; // forward declaration

class Ability { 
    private:
        bool available;
        string type;
    protected:
        Player& selectPlayer(Game& g);
    public:
        Ability(string);
        /* Execute, pass the game state to ability to act accordingly */
        virtual void Execute(Game& g) = 0;

        /* Getter */
        string getType() const;
        bool getAvail() const;

        /* Setter */
        Ability& setAvail(bool);
};

class ReRoll: public Ability {
    private:
        
    public:
        ReRoll();
        void Execute(Game& g); // lihat situasi
};

class Quadruple: public Ability {
    private:

    public:
        Quadruple(); // default ctor
        void Execute(Game& g);
};

class Quarter: public Ability {
    public:
        Quarter(); // default ctor
        void Execute(Game& g);
};

class ReverseDirection: public Ability {
    private:

    public:
        ReverseDirection();
        void Execute(Game& g); // lihat situasi
};

class SwapCard: public Ability {
    private:

    public:
        SwapCard();
        void Execute(Game& g); // lihat situasi
};

class Switch: public Ability {
    private:

    public:
        Switch();
        void Execute(Game&); // lihat situasi
};

class Abilityless: public Ability {
    private:

    public:
        Abilityless();
        void Execute(Game&); // lihat situasi
};



#endif