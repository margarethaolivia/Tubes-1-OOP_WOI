#ifndef DECK_HPP
#define DECK_HPP

#include <iostream>
#include <stdlib.h>
#include <vector>
#include "../InventoryHolder/InventoryHolder.hpp"
#include "../Card/Card.hpp"
using namespace std;

template <class T>
class Deck: public InventoryHolder<T> {
    protected:

    public:
        Deck();
        InventoryHolder& operator=(const InventoryHolder&);
        InventoryHolder& operator+(const T&);
        InventoryHolder& operator-(const T&);
};

#endif