#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    // Values to be written to file
    string name = "Timmy", resistance = "Magic";
    int health = 5, strength = 3, defence = 8, magic = 4, bossesDefeated = 2;

    ofstream playerFileOut("player.txt");

    if (playerFileOut.is_open()) {
        // Write values to file on different lines
        playerFileOut << "Name:\n";
        playerFileOut << name << endl;
        playerFileOut << "Health:\n";
        playerFileOut << health << endl;
        playerFileOut << "Strength:\n";
        playerFileOut << strength << endl;
        playerFileOut << "Defence:\n";
        playerFileOut << defence << endl;
        playerFileOut << "Magic:\n";
        playerFileOut << magic << endl;
        playerFileOut << "Resistance:\n";
        playerFileOut << resistance << endl;
        playerFileOut << "Bosses_defeated:\n";
        playerFileOut << bossesDefeated << endl;

        playerFileOut.close();

        cout << "Values written to file" << endl;
    } else 
    {
        cout << "File could not be opened" << endl;
    }

    // Reading values
    name = "No Name", resistance = "No Resistance";
    health = 0, strength = 0, defence = 0, magic = 0, bossesDefeated = 0;

     cout << name << endl << health << endl << strength << endl 
         << defence << endl << magic << endl << resistance << endl 
        << bossesDefeated << endl << endl;

    ifstream playerFileIn("player.txt");

    if (playerFileIn.is_open()) {
        string commentsHolder = "";
        playerFileIn >> commentsHolder;
        playerFileIn >> name;
        playerFileIn >> commentsHolder;
        playerFileIn >> health;
        playerFileIn >> commentsHolder;
        playerFileIn >> strength;
        playerFileIn >> commentsHolder;
        playerFileIn >> defence;
        playerFileIn >> commentsHolder;
        playerFileIn >> magic;
        playerFileIn >> commentsHolder;
        playerFileIn >> resistance;
        playerFileIn >> commentsHolder;
        playerFileIn >> bossesDefeated;

        playerFileIn.close();
    } else {
        cout << "File could not be opened" << endl;
    }

    cout << name << endl << health << endl << strength << endl 
         << defence << endl << magic << endl << resistance << endl 
        << bossesDefeated << endl;

    return 0;
}