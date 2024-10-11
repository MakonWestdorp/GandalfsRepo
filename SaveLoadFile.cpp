#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    // Values to be written to file
    string name = "Timmy", resistance = "Magic";
    int health = 5, strength = 3, defence = 8, magic = 4, bossesDefeated = 2;

    ofstream outputFile("player.txt");

    if (outputFile.is_open()) {
        // Write values to file on different lines
        outputFile << name << endl;
        outputFile << health << endl;
        outputFile << strength << endl;
        outputFile << defence << endl;
        outputFile << magic << endl;
        outputFile << resistance << endl;
        outputFile << bossesDefeated << endl;

        outputFile.close();

        cout << "Values written to file" << endl;
    } else 
    {
        cout << "File could not be opened" << endl;
    }

    // Reading values
    string name = "No Name", resistance = "No Resistance";
    int health = 0, strength = 0, defence = 0, magic = 0, bossesDefeated = 0;

    return 0;
}