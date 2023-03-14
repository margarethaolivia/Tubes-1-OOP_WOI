#include <ctime>
#include "Player.hpp"

/* default constructor*/
Player::Player(string nick) : nickName(nick) {
    this->handPoint = 0; // set point to zero
}

/* Operator Overloading */
bool operator<(const Player& p1,const Player& p2){
    if (p1.highestCombo.value() < p2.highestCombo.value()){
        return true;
    } else {
        return false;
    }
}

bool operator>(const Player& p1, const Player& p2) {
    if (p1.highestCombo.value() > p2.highestCombo.value()){
        return true;
    } else {
        return false;
    }
}

/* Accessor */
Card Player::getCard(int position) const{
    if (position == 1){
        return items[0];
    } else if (position == 2) {
        return items[1];
    } else {
        NumberInputException err;
        throw err;
    }
}

int Player::getPoint() const{
    return handPoint;
}

Combo Player::getHighestCombo() const{
    return highestCombo;
}

void Player::getInfo() const {
    cout << "This is "<< nickName << "'s Card" << endl;
}

string Player::getNickname() const {
    return this->nickName;
}

Ability* Player::getAbility() const {
    return handAbility;
}

/* Setter */
void Player::setHighestCombo(Combo c){
    this->highestCombo = c;
}

void Player::setAbility(Ability& ability){
    handAbility = &ability;
}

void Player::dealToPlayer(InventoryHolder<Card>& deck) {
    this->deleteall();
    this->add(deck);
    this->add(deck);
}

/* Utility Function*/
void Player::addPoint(int point){
    this->handPoint += point;
}