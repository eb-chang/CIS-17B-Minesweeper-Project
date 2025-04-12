//int main() {
//
//    //set random seed
//    srand(static_cast<unsigned int>(time(0)));
//
//    //declare vars
//    int r, c, m;//rows, cols, mines
//
//    //load user?
//
//    /*
//    prompt user for difficulty
//    / TEST COMMENT
//
//    beginner - 8x8 (or 9x9) w/ 10 mines
//    intermediate - 16x16 w/ 40 mines
//    expert - 16x30 w/ 99 mines
//    */
//    r = 3;
//    c = 3;
//    m = 2;
//
//    //create and run game
//    Game game(r, c, m); // Easy 9x9 with 10 mines
//    game.run();
//
//    //display & record scoreboard
//
//    //another game?
//
//    //exit the program
//    return 0;
//}

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Grid.hpp"

#include <cctype>
#include "player.hpp"
#include "admin.hpp"
#include "game.hpp"

using namespace std;

int main() {
    srand(static_cast<unsigned int>(time(0)));

    std::cout << "Welcome to Minesweeper!\n";
    std::cout << "Login as:\n1. Player\n2. Admin\nChoice: ";
    int choice;
    cin >> choice;

    string name, email;
    std::cout << "Enter your USER name : ";
    cin >> name;
    std::cout << "Enter your email : ";
    cin >> email;

    User* user = nullptr;
    int r = 9, c = 9, m = 10;   ///rows, cols, num of mines if user chooses 1 for difficulty

    if (choice == 2) {
        string id;
        std::cout << "Enter admin identification: ";
        cin >> id;
        user = new Admin(name, email, id);
       
        user->displayInfo();

        //Admin* admin = dynamic_cast<Admin*>(user);
        Admin* admin = static_cast<Admin*>(user);
        if (admin) {
            int adminChoice;
            do {
                std::cout << "\nAdmin Menu:\n1. View Scoreboard\n2. Reset Scoreboard\n3. Exit\nChoice: ";
                cin >> adminChoice;
                switch (adminChoice) {
                case 1: (*admin).viewScoreBoard(); break;
                case 2: admin->resetScoreBoard(); break;
                case 3: std::cout << "Exiting admin panel.\n"; break;
                default: std::cout << "Invalid option.\n";
                }
            } while (adminChoice != 3);
        }
    }
    else {
        user = new Player(name, email);
        user->displayInfo();

        Player* player = dynamic_cast<Player*>(user);
        if (player) {
            player->loadStats();

            std::cout << "\nSelect difficulty:\n1. Easy (9x9)\n2. Medium (16x16)\n3. Hard (16x30)\nChoice: ";
            int diff;
            cin >> diff;
            if (diff == 2) { r = 16; c = 16; m = 40; }
            else if (diff == 3) { r = 16; c = 30; m = 99; }

            char again; //play again 
            do {
                player->numGamePlay();
                Game game(r, c, m);
                game.run();
                player->recordWin();
                player->saveStats();

                std::cout << "Play again? (Y/N): ";
                cin >> again;
                again = toupper(again);
            } while (again == 'Y');
        }
    }

    delete user;
    std::cout << "Thanks for using Minesweeper!\n";
    return 0;
}
