#include <iostream>
#include "Game.h"
#include <fstream>
#include "List.h"
#include <cmath>
#include "Functions.h"
#include "Check_Input.h"

using namespace std;

void printRules(const vector<string>& rules) {
    for (const string& rule : rules) {
        cout << rule << endl;
    }
}

int main() {

    int i = 0;
    char a;
    do {
        Game game;
        cout << "_-_-_-_-_-_-_-_-_-_-_-_-SEA BATTLE-_-_-_-_-_-_-_-_-_-_-_-_" << endl;
        cout << "\n\n1 - Rules of the game\n\n";
        cout << "\n\n2 - Statistic\n\n";
        cout << "\n\n3 - Start the game\n\n";
        cout << "\nSelect the option\n";

        do {
            cout << "\nChoose 1, 2 or 3!\n";
            try {
                cin >> i;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(32767, '\n');
                    throw Check_Input("\n\bAnother symbol was used instead of integer number!\n");
                }
            }catch (Check_Input &cI){
                cout<<cI.what();
                i = 0;
            }
        } while (i < 1 || i > 3);

        switch (i) {
            case 1:
                cout << "\n~~~The rules of the game~~~\n";
                printRules(game.getRules());
                break;
            case 2:
                cout << "\n~~~Your statistic~~~\n\n";
                cout << game.getStatistic();
                cout << "\n\nDo you want to clear your statistic? Enter y(yes) if you do, and any other char if you don`t.\n";
                cin>>a;
                if(a=='y') {
                    cout<<"\n~~~~~~~~~~~~~~~~~You will not be able to recover data!!!~~~~~~~~~~~~~~~~~\n"
                          "Are you sure you want to clean your statistic? Enter Y if YES\n";
                    cin>>a;
                    if(a=='y') {
                        game.clear_Statistic();
                        cout << "\n~~~Your statistic~~~\n\n";
                        cout << game.getStatistic();
                    }
                }
                break;
            case 3:
                cout << "\nChoose option\n";
                cout << "\n1 - Auto configuration\n";
                cout << "\n2 - Manual configuration\n";
                do {
                    cout << "\nChoose 1 or 2!\n";
                    try {
                        cin >> i;
                        if (cin.fail()) {
                            cin.clear();
                            cin.ignore(32767, '\n');
                            throw Check_Input("\n\bAnother symbol was used instead of integer number!\n");
                        }
                    }catch (Check_Input &cI){
                        cout<<cI.what();
                        i = 0;
                    }
                } while (i != 1 && i != 2);

                switch (i) {
                    case 1:
                        game.prepare_players(true);
                        break;
                    case 2:
                        game.prepare_players(false);
                        break;
                }
                cout << "\nThe players are ready. The game begins.\n";
                game.battle();
                if(game.isWinner())
                    cout<<"\nCongratulations! You won this game!\n";
                else
                    cout<<"\nYou lost this game...\n";
        }
        cout << "\n\nDo you want to quit the game? Enter n(no) if you don`t, and any other char if you do.\n";
        cin >> a;
    }while(a == 'n' || a == 'N');

    return 0;
}
