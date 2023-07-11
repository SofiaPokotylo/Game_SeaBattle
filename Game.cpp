//
// Created by Софiя Покотило on 13.11.21.
//

#include "Game.h"
#include <fstream>
#include "Functions.h"
#include <iostream>

using namespace std;

Game::Game() {
    setRules();
    setStatistic();
}

void Game::clear_Statistic(){
    user.setNumOfConsecutiveWins(0);
    user.setRecord(0);
    user.setNumOfLosses(0);
    user.setNumOfWins(0);
    change_Statistic();
}

void Game::end_the_game() {
    if(user.get_killed_all_ships()){
        winner = true;
        user.setNumOfWins(user.getNumOfWins()+1);
        user.setNumOfConsecutiveWins(user.getNumOfConsecutiveWins()+1);
        if(user.getNumOfConsecutiveWins()>user.getRecord())
            user.setRecord(user.getNumOfConsecutiveWins());
    }
    else{
        winner = false;
        user.setNumOfLosses(user.getNumOfLosses()+1);
        user.setNumOfConsecutiveWins(0);
    }
    change_Statistic();
}

const vector<string> &Game::getRules() const {
    return rules;
}

void Game::setRules() {
    fstream file("Rules", ios::in);
    string line;
    rules.clear();
    while (getline(file, line)) {
        rules.push_back(line);
    }
    file.close();
}

string &Game::getStatistic() {
    setStatistic();
    return Statistic;
}

void Game::change_Statistic() {
    fstream file("Statistic", ios::in | ios::out);
    char c;
    string str;
    int a;
    int length = 0;

    if (!file) {
        cout << "Something went wrong, file could not be opened!" << endl;
        exit(1);
    }

    while (file.get(c)) {
        if (c == ')') {
            file.seekg(-2, ios::cur);
            file.get(c);
            switch (c) {
                case '1':
                    while (str != "-")
                        file >> str;
                    file >> str;
                    length = len(str);
                    file.seekg(-length, ios::cur);

                    str = user.getNumOfWins();
                    file << user.getNumOfWins();;
                    for (int i = len(str); i < length; ++i)
                        file << " ";
                    file.seekg(file.tellg(), ios::beg);
                    break;

                case '2':
                    while (str != "-")
                        file >> str;
                    file >> str;
                    length = len(str);
                    file.seekg(-length, ios::cur);

                    str = user.getNumOfLosses();
                    file << user.getNumOfLosses();
                    for (int i = len(str); i < length; ++i)
                        file << " ";

                    file.seekg(file.tellg(), ios::beg);
                    break;
                case '3':
                    while (str != "-")
                        file >> str;
                    file >> str;
                    length = len(str);
                    file.seekg(-length, ios::cur);

                    str = user.getNumOfConsecutiveWins();
                    file << user.getNumOfConsecutiveWins();
                    for (int i = len(str); i < length; ++i)
                        file << " ";

                    file.seekg(file.tellg(), ios::beg);
                    break;
                case '4':
                    while (str != "-")
                        file >> str;
                    file >> str;
                    length = len(str);
                    file.seekg(-length, ios::cur);

                    str = user.getRecord();
                    file << user.getRecord();
                    for (int i = len(str); i < length; ++i)
                        file << " ";

                    file.seekg(file.tellg(), ios::beg);
            }
        }
    }

    file.close();
}

void Game::setStatistic() {
    fstream file("Statistic", ios::in | ios::out);
    char c;
    string str;
    int a;

    if (!file)
    {
        cout << "Something went wrong, file could not be opened!" << endl;
        exit(1);
    }

    getline(file, Statistic);
    file.seekg(0,ios::beg);

    while (file.get(c)){
        if(c == ')'){
            file.seekg(-2, ios::cur);
            file.get(c);
            switch (c){
                case '1':
                    while(str!="-")
                        file >> str;
                    file >> str;
                    user.setNumOfWins(str_to_int(str));
                    break;
                case '2':
                    while(str!="-")
                        file >> str;
                    file >> str;
                    user.setNumOfLosses(str_to_int(str));
                    break;
                case '3':
                    while(str!="-")
                        file >> str;
                    file >> str;
                    user.setNumOfConsecutiveWins(str_to_int(str));
                    break;
                case '4':
                    while(str!="-")
                        file >> str;
                    file >> str;
                    user.setRecord(str_to_int(str));
            }
        }
    }
    file.close();
}

void Game::battle() {
    List list;
    Coordinate coord, coord1, c;
    int h = 0, h1 = 0;
    int w = 0, w1 = 0;
    int last_direct = 0, last_direct1 = 0;
    Direction d(false, false, false, false);
    int size = 0;
    int id = 0;
    int ship_size = 0;
    int size1 = 0;
    int id1 = 0;
    int ship_size1 = 0;
    for(int i = 0; i<user.get_battlefield_player().getFieldHeight(); ++i){
        for (int j = 0; j < user.get_battlefield_player().getFieldWidth(); ++j) {
            coord.set_Coordinate(i+1,j+65);
            list.add(coord);
        }
    }

    while (!user.get_killed_all_ships() && !computer.get_killed_all_ships()) {
        do {
            //cout<<endl<<"Battlefield"<<endl<<computer.get_battlefield_player()<<endl;
            cout<<endl<<"Your Battlefield"<<endl<<user.get_battlefield_player()<<endl;
            cout<<endl<<"Your Enemy Battlefield"<<endl<<user.get_battlefield_enemy()<<endl;
            user.attack_ships(computer.get_battlefield_player(), h1, w1, coord1);
            check_attack(ship_size1,id1,size1,h1,w1,coord1,list,true,user,computer);
        }while(!user.get_battlefield_enemy().get_previous_miss());

        if(user.get_killed_all_ships() || computer.get_killed_all_ships() ) break;

        do {
            computer.attack_ships(user.get_battlefield_player(), h, w, last_direct, coord, c, list);
            cout<<"\n\nThe computer hits the coordinate "<<c<<"\n\n";
            check_attack(ship_size,id,size,h,w,coord,list,false,computer,user);
        }while(!computer.get_battlefield_enemy().get_previous_miss());
    }
    end_the_game();
}

void Game::prepare_players(bool auto_config) {
    if(auto_config)
        user.get_battlefield_player().set_field_ships();
    else
        user.manual_place_ships();
    computer.get_battlefield_player().set_field_ships();
}

void Game::check_attack(int &ship_size, int &id, int &size, int &h, int &w, Coordinate &coord, List &list, const bool &b,
                        Player &player, Player &player2) {
    Direction d(0,0,0,0);
    int last_direct = 0;
    if(!player.get_battlefield_enemy().get_previous_miss() && player2.get_battlefield_player().isPreviousHit()){
        ++ship_size;
        player.get_battlefield_enemy().set_num_of_misses(0);
        if(ship_size==1){
            id = player2.get_battlefield_player().getField()[h][w].getShipId();
            size = player2.get_battlefield_player().getShips()[id].getSize();
        }
        if(ship_size==size){
            if(b){
                player2.get_battlefield_player().setDirectionIsSet(false);
                player2.get_battlefield_player().hit_around_user(h, w, coord, id, last_direct);
            }
            else player2.get_battlefield_player().hit_around(h, w, coord, id, last_direct, list);
            player.get_battlefield_enemy().hit_around(h, w, coord, player2.get_battlefield_player().getShips()[id], last_direct);
            ship_size=0;
            player2.get_battlefield_player().setPreviousHit(false);
            player.get_battlefield_enemy().add_killed_ship();
            if(player.get_battlefield_enemy().get_num_of_killed_ships()==player.get_battlefield_enemy().getNumOfShips()){
                player.set_killed_all_ships(true);
                player.get_battlefield_enemy().set_previous_miss(true);
                return;
            }
            player2.get_battlefield_player().setDirection(d);
        }
    }
    if(player.get_battlefield_enemy().get_previous_miss())
        player.get_battlefield_enemy().add_miss(1);
    if(player.get_battlefield_enemy().get_num_of_misses()==sea_monster.get_num_of_hits()) {
        int id1;
        if (sea_monster.attack_player_ships(player.get_battlefield_player(), player2.get_battlefield_enemy(), id1,list,b)) {
            cout<<"\nThe Sea Monster wakes up and attacks ";
            if(b) cout<<"your ship\n";
            else cout<<"the computer ship\n";
            player2.get_battlefield_enemy().add_killed_ship();
            if(player2.get_battlefield_enemy().get_num_of_killed_ships()==player2.get_battlefield_enemy().getNumOfShips()){
                player2.set_killed_all_ships(true);
                return;
            }
            if (!b) player.get_battlefield_player().hit_around_user(h, w, coord, id1, last_direct);
            else player.get_battlefield_player().hit_around(h, w, coord, id1, last_direct, list);
            player2.get_battlefield_enemy().hit_around(h, w, coord,
                                                       player.get_battlefield_player().getShips()[id1], last_direct);
        }
        player.get_battlefield_enemy().set_num_of_misses(0);
    }
}

bool Game::isWinner() const {
    return winner;
}
