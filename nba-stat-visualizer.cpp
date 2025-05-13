//File: Final Project - nba-stat-visualizer.cpp
//Name: Lorenzo Rawls
//Date: 5/10/2025
//Course: CompSci 2
//Description: This program will allow the user to store and view NBA Player credentials and their efficiency shooting from
// the field and the 3-point line specifically. This info can then be saved to a .txt file.

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream> // for file input/output

using namespace std;

// base class to represent an NBA Player
class Player {
protected:
    string name;               // player's name
    string position;           // player's position
    float fgPercentage;        // field goal %
    float threePtPercentage;   // 3-point %

public:
    // constructor to initialize player attributes
    Player(string n, string p, float fg, float three) :
        name(n), position(p), fgPercentage(fg), threePtPercentage(three) {}

    // display player's basic stats
    virtual void displayStats() const {
        cout << "Player: " << name << "\nPosition: " << position << endl;
        cout << fixed << setprecision(2);  // format float output to 2 decimal places
        cout << "Field Goal %: " << fgPercentage << "%" << endl;
        cout << "3PT %      : " << threePtPercentage << "%" << endl;
    }

    // display a simple ASCII bar chart of shooting effectiveness
    virtual void displayChart() const {
        cout << "\n--- Shooting Effectiveness Chart (out of 100%) ---" << endl;
        cout << "Field Goal:      [" << string(fgPercentage / 2, '=') << ">" << "] " << fgPercentage << "%" << endl;
        cout << "3-Point Shot:    [" << string(threePtPercentage / 2, '=') << ">" << "] " << threePtPercentage << "%" << endl;
    }

    // convert player data into a comma-separated string for saving to file
    virtual string toFileString() const {
        return name + "," + position + "," + to_string(fgPercentage) + "," + to_string(threePtPercentage);
    }
};

// helper function to validate float input for shooting percentages
float getValidatedPercentage(const string& prompt) {
    float value;
    while (true) {
        cout << prompt;
        cin >> value;

        // checks for input failure or out-of-bounds values
        if (cin.fail() || value < 0.0f || value > 100.0f) {
            cin.clear();                // clears error flags
            cin.ignore(1000, '\n');     // discards any invalid input
            cout << "Invalid input. Enter a percentage between 0 and 100.\n";
        } else {
            break;
        }
    }
    return value;
}

// saves player data to a file in append mode
void savePlayerToFile(const Player& player, const string& filename) {
    ofstream outFile(filename, ios::app);  // open file in append mode

    if (outFile.is_open()) {
        outFile << player.toFileString() << endl;  // writes data to file
        outFile.close();
        cout << "Player data saved to " << filename << endl;
    } else {
        cerr << "Failed to open file for writing.\n";
    }
}

int main() {
    cout << "🏀 NBA Player Effectiveness Visualizer\n";

    string name, position;
    float fg, threePt;

    cout << "Enter player's name: ";
    getline(cin, name);

    cout << "Enter player's position (e.g., PG, SG, SF, PF, C): ";
    getline(cin, position);

    // gets shooting percentages
    fg = getValidatedPercentage("Enter Field Goal %: ");
    threePt = getValidatedPercentage("Enter 3-Point %: ");

    // creates player object using gathered data
    Player player(name, position, fg, threePt);

    cout << "\n=== Player Overview ===\n";
    player.displayStats();
    player.displayChart();

    // asks if user wants to save data
    char save;
    cout << "\nSave player data to file? (y/n): ";
    cin >> save;

    if (tolower(save) == 'y') {
        savePlayerToFile(player, "nba_players.txt");
    }

    return 0;
}
