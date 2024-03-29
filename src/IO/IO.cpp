#include <string>
#include "IO.hpp"
#include "../Player/Player.hpp"
#include "../Game/Game.hpp"
using namespace std;

string IO::turnInput(const Player& player, int round){
    string input;
    cout << enterColor;
    cout << player.getNickname() << "'s turn ([";
    for (int i=0; i<2; i++){
        cout << enterColor;
        int color = player.getCard(i).getColor();
        if (color == 0){
            cout << "\033[1m\033[32m";
        } else if (color == 1){
            cout << "\033[1m\033[34m";
        } else if (color == 2){
            cout << "\033[1m\033[33m";
        } else {
            cout << "\033[1m\033[31m";
        }
        cout << player.getCard(i).getNumber() << resetColor;
        if (i==0){
            cout << enterColor << " - ";
        }
        cout << resetColor;
    }
    cout << enterColor << "]";
    if(round>1){
        cout << " ";
        if (player.getAbility()->getAvail()){
            cout << "\033[1m\033[32m";
            
        } else {
            cout << "\033[1m\033[31m";
        }
        cout << player.getAbility()->getType();
        cout << resetColor;
    }
    cout << enterColor <<  ") >>> ";
    cout << inputColor; cin >>  input;cout <<  resetColor;

    // input validation
    vector<string> validString = {
        "NEXT",
        "HALF",
        "DOUBLE",
        "RE-ROLL",
        "QUADRUPLE",
        "QUARTER",
        "REVERSE",
        "SWAPCARD",
        "SWITCH",
        "ABILITYLESS"
    };

    if (find(validString.begin(), validString.end(), input) == validString.end()){
        InputException err;
        throw err;
    }

    return input;
}

void IO::splashScreen(){
    string spades = "\033[1;34m";
    string clubs = "\033[1;33m";
    string hearts = "\033[1;31m";
    string diamonds = "\033[1;32m";

    string splash = clubs +                                                                    
"                          .,;;;:::::::::::;;;;;;;,,,;;,.                                            \n"
"                          .olcoxxxxxxxxxxxxxxxxxkkkkOOO;                                            \n"
"                          .lc;lxxxxxxxxxxxxkkkOOO0000KKc                                            \n"
"                          .lc,cxxxxxxxkkkOOO000KKXXXXNNl....            "+spades+".'..                        \n"
+hearts+"                          .cl:"+clubs+"ldxkkkkOO000KKKXXNNNNNWWWd"+diamonds+",cooc:;'...    "+spades+"'llcl:,..                    \n"
+hearts+"                       ..,cdxl,"+clubs+":dkO000KKXXXNNNWWWWWWWWWx"+diamonds+";cdxxxxxdolc;,,"+spades+"cc':ddddl:'.                 \n"
+hearts+"                   ..,:ldkkO0Kd;"+clubs+":x0KXX0OOO0XWWWWWWWWWWWk"+diamonds+";lxxxxxxxxxxxkxxdolc"+spades+"oxxxxxoc;..             \n"
+hearts+"               ..,:lodxxkO00KXNOc"+clubs+"ckXXx:;,,;cOWWWWWWWWWWk"+diamonds+":okkkkOOOOOOOOO000l,c"+spades+"dxxxxxxxdl;'.          \n"
+hearts+"            .':ldxxxxxkOO0KXXNWWKo"+clubs+"lxOo'....'xNWWWWWWWWWk"+diamonds+"lx0000KKKKKKKXXXXO;,"+spades+"lxxxxxxxxxxxdl;'..      \n"
+hearts+"        ..,coxxxxxxxkkO0KKXNNWWWWNd"+clubs+"'.,......,;:xNWWWWWWk"+diamonds+"oOXXXXXNNNNNNNNNNd,"+spades+"cxOOOOkkkkkkkxxxxoc,\n"
+hearts+"     .';lodxxxxxxxxkOO0KXXNWWWWWWWNx."+clubs+"          'OWWWWWNk"+diamonds+"oxkKNWWWWWWWWWWWKcc"+spades+"k000000000000OOOOOOkd'\n"
+hearts+"    .:olldxxxxxxxkkO0KKXNNWWWWWWWWWWO'"+clubs+" ';'.    ,0WNNNNXd"+diamonds+",',c0WWWWWWWWWWWkc"+spades+"xXNNXXXXXXXXXXKKKKKKO:\n"
+hearts+"     .clccoxxxxxkOO0KXNNWNKOOOKWWWWWW0"+clubs+"oc;lxc,,cONNXXXKKl"+diamonds+"...';kNWWWWWWWMKll"+spades+"kOOxkNWNWWNNNNNNNNN0;\n"
+hearts+"      .:occdxxkkO0KKXNNWNx:,'';oKWWWWWK;"+clubs+".'kNXXXXKKKK00Oc"+diamonds+".....,dNWWWWWWWd."+spades+".....:0WWWWWWWWWWWW0;\n"
+hearts+"       .;oxxxkOO0KK0kxdkx;......lNWWWNN0"+clubs+"doOXKKK00OOOOkkc"+diamonds+".......oXWWWWW0,"+spades+"      .lKWWWWWWWWWW0, \n"
+hearts+"         'oxkOO0KXOc,''.........oNWWNNXKO"+clubs+"cdO0OOOkkkkxxx:"+diamonds+".....,lkNWWWWNl"+spades+"       ..cKWWWWWWWWO, \n"
+hearts+"          .oO00KXNx;'..........cKWWNXXK0Ok"+clubs+"olxkkxxxxdolo;"+diamonds+"..;oOXWWWNNNNO,"+spades+"..      .'xWWWWWWWx'\n"
+hearts+"           .o0KXNWXd,.........:KWNNXXK0Okkx"+clubs+"ocoxxxxxd:,cc"+diamonds+"l0NNNNXXXXXX0d"+spades+"c;;c'    .:KWWWWWNx.\n"
+hearts+"            .oKNNWWN0xolllc:,,kWNNXKK0Okkxxdl"+clubs+"coxxxxxc;ll"+diamonds+"kXXKKKKK000Ox"+spades+"dd;;O0l;;cxXWWWWWXx.\n"
+hearts+"             .lXWWWWWWWMWMWWXKXNXXK0OOkxxxoccl"+clubs+"clddddc:ll"+diamonds+"x000OOOOOOkx"+spades+"okXXKKNXXXNNXXXXX0;\n"
+hearts+"               cXWWWWWWWWWWWWNNXXK0Okkxxxxdoccl"+diamonds+"ccoooooodkkkkkkkkxxx"+spades+"loO000000KKKKKKK0x,\n"
+hearts+"                :KWWWWWWWWWWNNXK00Okkxxxxxxxocll"+diamonds+"cdkxxxxxxxxxxxxoodo"+spades+"cdkkOOOOOOOOOOOko\n"
+hearts+"                 ,0WWWWWWWNNXXK0Okkxxxxxxxxdl"+diamonds+"cclodxxxxxxxxxxxxdl:l"+spades+"clxxxxxxxxxkxxkx:\n"
+hearts+"                  'kWWWWNNXXK0OOkxxddxxxdc;'"+diamonds+"ccc,;::cloddxxxxddl:ll"+spades+"cdxxxxxxxxdccdo;\n"
+hearts+"                   .dXNNXKK0Okkxdddddo:,               "+diamonds+"',;;:clccl"+spades+";,codddddddc,;c,\n"
+hearts+"                    .l0K00Okxxddolc;'.                 "+diamonds+"........'"+spades+".....,:cooo:,:c'\n"
+hearts+"                     .:kOkxddoc;,.                                   "+spades+"...,;;:;\n"
+hearts+"                       ,odlc,...          "+" _       __"+clubs+"____  "+diamonds+"____"+spades+"__\n"
+hearts+"                        ....              "+ "| |     / /"+clubs+" __ \\"+diamonds+"/  _/ "+spades+"/\n"
+hearts+"                                          | | /| / / "+clubs+"/ / /"+diamonds+"/ // "+spades+"/ \n"
+hearts+"                                          | |/ |/ / "+clubs+"/_/ /"+diamonds+"/ //"+spades+"_/  \n"   
+hearts+"                                          |__/|__/"+clubs+"\\____/"+diamonds+"___"+spades+"(_)   \n" + resetColor;
                       
    cout << splash << endl;
}

void IO::mainMenuTitle() {
    cout << lineColor << "==============================" << resetColor << endl;
    cout << wordColor << "           MAIN MENU          " << resetColor << endl;
    cout << lineColor << "==============================" << resetColor << endl;
    cout << wordColor << " 0. Exit " << endl;
    cout << wordColor << " 1. Candy Kingdom" << endl;
    cout << wordColor << " 2. Blackjack" << endl;
}

string IO::mainMenu(){
    cout << endl;
    cout << enterColor << "Enter Command >>> "; 
    
    string command;
    cout << inputColor; cin >> command; cout <<  resetColor;
    if (!(command == "0" || command == "1" || command == "2")){
        NumberInputException err;
        throw err;
    }
    cout << resetColor << endl;
    return command; 
}

string IO::dealMenu(){
    cout << lineColor << "==============================" << resetColor << endl;
    cout << wordColor << "         CARD DEALING         " << resetColor << endl;
    cout << lineColor << "==============================" << resetColor << endl;
    cout << wordColor << " 1. Input File" << endl;
    cout << wordColor << " 2. Random" << endl;
    cout << endl;
    cout << enterColor << "Enter Command >>> "; 
    
    string command;
    cout << inputColor; cin >> command; cout <<  resetColor;
    if (!(command == "1" || command == "2")){
        NumberInputException err;
        throw err;
    }
    cout << resetColor << endl;
    return command; 
}

bool isValid(string nick, vector<string> listNick){
    for (auto nickName: listNick){
        if (nick == nickName){
            cout << "\033[1;31mName has been taken!\033[0m" << endl;
            return false;
        }
    }
    return true;
}

vector<string> IO::inputPlayerName(){
    string inputNick;
    vector<string> res;
    cout << wordColor << "Please enter player name :" << resetColor << endl;
    cout << lineColor << "==============================" << resetColor << endl;
    for (int i=1; i<=7; i++) {
        do{
            cout << enterColor<< "Player " << i <<" >>> "; cout << inputColor; cin >> inputNick;
        } while(!isValid(inputNick, res));
        
        res.push_back(inputNick);
        cout << resetColor << endl;
    }
    return res;
}

void IO::printTable(Table table, Point point){
    cout << wordColor << "            TABLE             " << resetColor << endl;
    cout << lineColor << "==============================" << resetColor << "\n\n";
    for (int i=0; i<table.getNeff(); i++){
        int color = table.getItems()[i].getColor();
        if (color == 0){
            cout << "\033[1m\033[32m";
        } else if (color == 1){
            cout << "\033[1m\033[34m";
        } else if (color == 2){
            cout << "\033[1m\033[33m";
        } else {
            cout << "\033[1m\033[31m";
        }
        cout << "  " << table.getItems()[i].getNumber() << "  ";
        cout << resetColor;
    }
    cout << "\n\n";
    cout << lineColor << "==============================" << endl;
    cout << wordColor << "Game Points : " <<  point.getValue() << resetColor << endl << endl; 

}

void IO::printAbilitySuccess(Player player, vector<string> resPlayer, vector<string> reversed){
    string type = player.getAbility()->getType(); 
    cout << abilColor;
    // Re-Roll
    if ( type == "Re-Roll"){
        cout << "Replacing your current cards..." << endl;
        cout << "You got 2 new cards :" << endl;
        cout << "1. " << player.getItems()[0].getNumber() << " " << cardToString.at(player.getItems()[0].getColor()) << endl;
        cout << "2. " << player.getItems()[1].getNumber() << " " << cardToString.at(player.getItems()[1].getColor()) << endl;
    
    // Swap Card
    } else if (type == "Swap"){
        cout << player.getNickname() << " successfully performed SWAP CARD!" << endl;
        cout << resPlayer[0] << "'s Card and " << resPlayer[1] << "'s Card has been swapped!" << endl; 
    
    // Switch
    } else if (type == "Switch"){
        cout << player.getNickname() << " successfully performed SWITCH!" << endl;
        cout << "both of your cards has been switched with " << resPlayer[0] << endl;
        cout << "your current cards are : " 
        << player.getItems()[0].getNumber() << "-" << cardToString.at(player.getItems()[0].getColor()) << " & "
        << player.getItems()[1].getNumber() << "-" << cardToString.at(player.getItems()[1].getColor()) << endl;
    
    // Abiilityless
    } else if (type == "Abilityless"){
        cout << player.getNickname() << " successfully performed ABILITYLESS! " << endl;
        cout << resPlayer[0] << "'s Ability Card has been disabled";

    // Reverse
    } else if (type == "Reverse"){
        cout << player.getNickname() << " successfully performed REVERSE! " << endl;
        cout << "Turn order for rest of this round : ";
        for (auto itr = resPlayer.begin(); itr != resPlayer.end(); itr++){
            cout << *itr;
            if (itr != resPlayer.end()-1){
                cout << " - ";
            }
        }
        cout << endl;
        cout << "Turn order for next round: ";
        for (auto itr = reversed.begin(); itr != reversed.end(); itr++){
            cout << *itr;
            if (itr != resPlayer.end()-2){
                cout << " - ";
            }
        }
        cout << endl;
    }
    cout << endl;
    cout << resetColor;
}


void IO::printAbilitySuccess(const Player& player, const Point& poin){
    string type = player.getAbility()->getType(); 
    cout << abilColor;
    
    // Quadruple
    if (type == "Quadruple"){
        cout << player.getNickname() << " successfully performed QUADRUPLE! Game Point has been quadrupled from" << endl;
        cout << poin.getValue()/4 << " became " << poin.getValue() << "!" << endl;
    
    // Quarter
    } else if (type == "Quarter"){
        cout << player.getNickname() << " successfully performed QUARTER! Game Point has been quartered from" << endl;
        cout << poin.getValue()*4 << " became " << poin.getValue() << "!" << endl;
    }
    cout << resetColor;
}

void IO::printActionSuccess(const Player& player, const Point& poin, int type){
    cout << actnColor;
    if (type == 1){
        cout << "It's time to move on to the next player's turn. Let's keep this game rolling!" << endl;
    } else if (type == 2){
        cout << player.getNickname() << " successfully performed DOUBLE! Game Point has been doubled from" << endl;
        cout << poin.getValue()/2 << " became " << poin.getValue() << "!" << endl;
    } else if (type == 3){
        cout << player.getNickname() << " successfully performed HALF! Game Point has been halved from" << endl;
        cout << poin.getValue()*2 << " became " << poin.getValue() << "!" << endl;
    }
}

int IO::selectCard(string playersNick){
    string choice;
    cout << abilColor;

    cout << "Pick which " << playersNick << "'s cards you want to swap!" << endl;
    cout << "1. Right" << endl;
    cout << "2. Left" << endl;
    cout << "\033[5m" << "Your choice Number >>> " << resetColor; cin >> choice;

    if (!(choice == "1" || choice == "2")){
        NumberInputException err;
        throw err;
    }

    return (int) choice[0];
}

void printPlayer(string nick, const vector<pair<Player&, bool>>& listPlayer){
    int i = 1;
    for (auto couple: listPlayer){
        if (couple.first.getNickname()!=nick){
            cout << i << ". " << couple.first.getNickname() << endl;
            i++;
        }
    }
}

vector<Player*> IO::selectPlayer(const Player& player, const vector<pair<Player&, bool>>& listPlayer, string currentPlayer) const{
    string type = player.getAbility()->getType(); 
    string player1, player2;
    PlayerException err;

    vector<Player*> resPlayers;
    cout << abilColor;
    if (type == "Swap"){
        cout << "Go ahead and pick the player whose card you want to swap!" << endl;
        printPlayer(player.getNickname(), listPlayer);
        cout << "\033[5;32m"<< "Player's Name 1 >>> " << inputColor; cin >> player1;
        cout << "\033[5;32m" << "Player's Name 2 >>> " << inputColor; cin >> player2;
        cout << resetColor;

        for (auto p_itr = listPlayer.begin(); p_itr != listPlayer.end(); p_itr++) {
            if (p_itr->first.getNickname() == player1 || p_itr->first.getNickname() == player2){
                resPlayers.push_back(&(p_itr->first));
            }
        }

        if (resPlayers.size() < 2) {
            throw err;
        }

        // Exception
        if (player1 == player2){
            throw err;
        }

        if (player1 == currentPlayer || player2 == currentPlayer) {
            throw err;
        }

    } else if (type == "Switch"){
        cout << "Go ahead and pick the player whose card you want to swap! " << endl;
        printPlayer(player.getNickname(), listPlayer);
        cout << "\033[5m" << "Player's Name >>> " << resetColor; cin >> player1;
        
        for (auto p_itr = listPlayer.begin(); p_itr != listPlayer.end(); p_itr++) {
            if (p_itr->first.getNickname() == player1){
                resPlayers.push_back(&(p_itr->first));
            }
        }

        if (resPlayers.size() < 1) {
            throw err;
        }

        if (player1 == currentPlayer) {
            throw err;
        }

    } else if (type == "Abilityless"){
        cout << "Go ahead and pick the player whose card you want to 'power down'! " << endl;
        printPlayer(player.getNickname(), listPlayer);
        cout << "\033[5m" << "Player's Name >>> " << resetColor; cin >> player1;
        
        for (auto p_itr = listPlayer.begin(); p_itr != listPlayer.end(); p_itr++) {
            if (p_itr->first.getNickname() == player1 || p_itr->first.getNickname() == player2){
                resPlayers.push_back(&(p_itr->first));
            }
        }

        if (player1 == currentPlayer) {
            throw err;
        }

        if (resPlayers.size() < 1) {
            throw err;
        }
    }
    
    cout << resetColor;
    return resPlayers;
}

void IO::printAbilityless(string nick){
    cout << abilColor;
    if (nick != ""){
        cout << "Oops, " << nick << "'s Ability Card has been used before :(" << endl;
        cout << "Aww, what a shame, the use of this card was all for nothing" << endl;
    } else {
        cout << "Oops, turns out all the players have already used their ability cards :(" << endl;
        cout << "Aww, tough luck, looks like you're now abilityless!" << endl;
        cout <<  "Womp womp, the use of those cards was all for naught!" << endl;
    }
    cout << resetColor;
}

void printHelper(string nick){
    if (nick.length() > 12){
        for (int i=0; i<14; i++){
            cout << nick[i];
        }
    } else {
        int rest = 14 - nick.length();
        cout << nick;
        for (int i=0; i<rest; i++){
            cout << " ";
        }
    }
}

void printHelper(long long poin){
    int rest = 12 - to_string(poin).length();
    cout << poin;
    for (int i=0; i<rest; i++){
        cout << " ";
    }
    
}

void IO::printEndMatch(Player winner, Point poin){
    cout << wordColor << "           WINNER             " << resetColor << endl;
    cout << lineColor << "==============================" << resetColor << endl;
    cout << wordColor << winner.getNickname() << " : " << winner.getPoint().getValue() - poin.getValue() 
    << " +" << "\033[1;34m " <<  poin.getValue() << wordColor << " = " << winner.getPoint().getValue() << endl; 
    cout << resetColor;
    cout << endl;
}

bool compare(const pair<string, long long>& a, const pair<string, long long>& b) {
    return a.second > b.second;
}

void IO::printEndGame(const vector<pair<Player&, bool>>& listPlayer){
    cout << wordColor;
    cout << "Game Over!" << resetColor << endl; 
    cout << lineColor << "==============================" << resetColor << endl;
    cout << wordColor << "│          FINAL SCORE        │" << resetColor << endl;
    cout << lineColor << "==============================" << resetColor << endl;
    vector<pair<string, long long>> tempSort;
    for (int i=0; i < 7; i++){
        pair<string, long long> tempp(listPlayer[i].first.getNickname(), listPlayer[i].first.getPoint().getValue());
        tempSort.push_back(tempp);
    }
    sort(tempSort.begin(), tempSort.end(), compare);

    for (int i=0; i<7; i++){
        cout << lineColor << "│" << resetColor;
        cout << wordColor << i+1 << "." << resetColor;
        cout << lineColor << "│" << resetColor;
        cout << wordColor; printHelper(tempSort[i].first); cout << resetColor;
        cout << wordColor; printHelper(tempSort[i].second); cout << resetColor;
        cout << lineColor << "│" << resetColor << endl;
    }
    cout << lineColor << "==============================" << resetColor << endl;
}


pair<vector<Card>, vector<Ability*>> IO::inputFile(){
    string fileName;
    cout << enterColor << "Enter Your file's name >>> " << resetColor;
    cout << inputColor; cin >> fileName; cout << resetColor;
    cout << endl;
    string filePath = "test/" + fileName;
    ifstream infile(filePath);
    FileException err;

    if (!infile){
        throw err;
    }

    string line;
    vector<Card> mainDeck;
    vector<Ability*> abilityDeck;

    int count = 0;
    while(getline(infile, line)){
        istringstream iss(line);
        string code;
        while (iss >> code) {
            // 52 first word is for main deck
            if (count < 52){
                if (code.length() == 2){
                    Card card(CardColor(1), 0);
                    card.setNumber(code[0] - '0');
                    card.setColor(stringToColor.at(code[1]));
                    mainDeck.push_back(card);
                    count++;
                } else if (code.length() ==  3){
                    Card card(CardColor(1), 0);
                    card.setNumber((code[0] - '0')*10 + (code[1] - '0'));
                    card.setColor(stringToColor.at(code[2]));
                    mainDeck.push_back(card);
                    count++;
                } else {
                    throw err;
                }
            // 7 other word for ability deck
            } else if (count <=59){
                if (code.length() == 2){
                    abilityDeck.push_back(stringToAbility(code));
                    count++;
                } else {
                    throw err;
                }

            } else {
                throw err;
            }
        }
    }

    if (count < 59){
        throw err;
    }
    pair<vector<Card>, vector<Ability*>> ret(mainDeck, abilityDeck);
    return ret;
}

Ability* IO::stringToAbility(string code){
    if (code == "RR"){
        ReRoll* reroll = new ReRoll();
        return reroll;
    } else if (code == "QP"){
        Quadruple* quadruple = new Quadruple();
        return quadruple;

    } else if (code == "QT"){
        Quarter* quarter = new Quarter();
        return quarter;

    } else if (code == "RV"){
        ReverseDirection* Reverse = new ReverseDirection();
        return Reverse;

    } else if (code == "SC"){
        SwapCard* swapCard = new SwapCard();
        return swapCard;

    } else if (code == "SW"){
        Switch* switc = new Switch();
        return switc;

    } else if (code == "AL"){
        Abilityless* abilityless = new Abilityless();
        return abilityless;

    } else {
        InputException err;
        throw err;
    }
}

/* Black Jack*/
void IO::printBJ(Table dealer, Point price){
    cout << wordColor << "            DEALER             " << resetColor << endl;
    cout << lineColor << "==============================" << resetColor << "\n\n";
    for (int i=0; i<dealer.getNeff(); i++){
        cout << "  " << getBJValue.at(cardToBJCard.at(dealer.getItems()[i].getNumber())) << "  ";
        cout << resetColor;
    }
    cout << "\n\n";
    cout << lineColor << "==============================" << endl;
    cout << wordColor << "Price Pool : " <<  price.getValue() << resetColor << endl << endl; 
}

int IO::inputBet(int poin){
    string input="";
    cout << lineColor << "==============================" << resetColor << endl;
    cout << wordColor << "            BETTING           " << resetColor << endl;
    cout << lineColor << "==============================" << resetColor << "\n\n";
    cout << enterColor << "Insert your bet (" << poin << ") >>> " << resetColor; cin >> input;
    cout << resetColor;
    InputException err;
    for(unsigned int i=0; i<input.length(); i++){
        if (input[i] - '0' > 9){
            throw err;
        }
    }

    int realInput = stoi(input);
    if (0 < realInput && realInput > poin){
        throw err;
    }
    cout << endl;
    return realInput;
}

string IO::inputBJ(vector<Card> playerCards, int total){
    cout << wordColor << "           YOUR CARD          " << resetColor << endl;
    cout << lineColor << "==============================" << resetColor << "\n\n";
    int i = 1;
    cout << wordColor;
    string command;
    for (auto card: playerCards){
        cout << i << ". " << getBJValue.at(cardToBJCard.at(card.getNumber())) << endl;
        i++;
    }
    cout << lineColor << "==============================" << resetColor << endl;
    cout << wordColor << "           " << total  << resetColor << endl << endl; 
    cout << enterColor << "Enter Action >>> " << resetColor << inputColor; cin >> command; cout << resetColor;
    
    if (!(command == "HIT" || command == "STAND")){
        InputException err;
        throw err;
    }
    return command;
}

void IO::printEndBJ(int poinPlayer, int poinDealer ){
    if (poinDealer > 21) {
        cout << wordColor << "Yeay! You Win!" << endl;
    } else {
        if (poinPlayer > poinDealer){
            cout << wordColor << "Yeay! You Win!" << endl;
        } else if (poinPlayer == poinDealer){
            cout << wordColor << "Draw!" << endl;
        } else {
            cout << wordColor << "Oops! You Lose!" << endl;
        }
    }
    cout << resetColor;
}

void IO::printStrike(){
    cout << abilColor << "BLACKJACK!!!" <<  wordColor <<  "YOU WIN!" << resetColor << endl; 
}
void IO::printBust(){
    cout << actnColor << "BUST!" << wordColor << "You Lose!" << resetColor << endl;
}

string IO::printPlayAgain(){
    string input = "";
    cout << lineColor << "==============================" << resetColor << endl;
    cout << wordColor << "          BLACKJACK           " << resetColor << endl;
    cout << lineColor << "==============================" << resetColor << "\n\n";
    cout << wordColor << "1. Play Again" << endl;
    cout << wordColor << "2. Back to Main Menu" << endl << endl;
    cout << lineColor << "Enter your Choice >>> " << inputColor; cin >> input;
    
    if (!(input == "1" || input == "2")){
        NumberInputException err;
        throw err;
    }

    return input;
}

void IO::printThankYou(){
    cout << wordColor;
    string end = R"(
 _____ _                 _     __   __            _____            ____  _             _                ___                ____                           _ 
|_   _| |__   __ _ _ __ | | __ \ \ / /__  _   _  |  ___|__  _ __  |  _ \| | __ _ _   _(_)_ __   __ _   / _ \ _   _ _ __   / ___| __ _ _ __ ___   ___  ___| |
  | | | '_ \ / _` | '_ \| |/ /  \ V / _ \| | | | | |_ / _ \| '__| | |_) | |/ _` | | | | | '_ \ / _` | | | | | | | | '__| | |  _ / _` | '_ ` _ \ / _ \/ __| |
  | | | | | | (_| | | | |   <    | | (_) | |_| | |  _| (_) | |    |  __/| | (_| | |_| | | | | | (_| | | |_| | |_| | |    | |_| | (_| | | | | | |  __/\__ \_|
  |_| |_| |_|\__,_|_| |_|_|\_\   |_|\___/ \__,_| |_|  \___/|_|    |_|   |_|\__,_|\__, |_|_| |_|\__, |  \___/ \__,_|_|     \____|\__,_|_| |_| |_|\___||___(_)
                                                                                 |___/         |___/                                                        
)";
    cout << end << endl;
    cout << resetColor;
}