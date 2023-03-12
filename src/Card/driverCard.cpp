#include <iostream>
#include <vector>
#include "Card.hpp"
using namespace std;

// int main() {
//     vector<int> nums = {6,4,9,3,1,8,9,4,6,0};
// vector<int> combo = {3,4,5};

//     combo = nums;

//     for (auto x : combo) {
//         cout << x << " ";
//     }
// }
void printBool(bool con){
    if (con) {
        cout << "true";
    } else {
        cout << "false";
    }

    cout << endl;
}

int main() {
    vector<Card> cards;
    Card card1(Green, 1);
    Card card2(Green, 2);
    Card card3(Red, 1);
    Card card4(Blue, 1);
    Card card5(Yellow, 1);
    Card card6(Red, 1);
    Card card7(Blue, 1);

    printBool(card3 == card6);
    printBool(card3 > card6);
    printBool(card3 < card6);
    printBool(card1 == card5);
    printBool(card1 > card5);
    printBool(card1 < card5);
    printBool(card2 == card7);
    printBool(card2 > card7);
    printBool(card2 < card7);

    return 0;
}