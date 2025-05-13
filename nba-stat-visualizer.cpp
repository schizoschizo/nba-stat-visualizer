#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

// Base class: Player
class Player {
protected:
    string name;
    string position;
    float fgPercentage;
    float threePtPercentage;

public:
    Player(string n, string p, float fg, float three) :
        name(n), position(p), fgPercentage(fg), threePtPercentage(three) {}

    virtual void displayStats() const {
        cout << "Player: " << name << "\nPosition: " << position << endl;
        cout << fixed << setprecision(2);
        cout << "Field Goal %: " << fgPercentage << "%" << endl;
        cout << "3PT %      : " << threePtPercentage << "%" << endl;
    }

    virtual void displayChart() const {
        cout << "\n--- Shooting Effectiveness Chart (out of 100%) ---" << endl;
        cout << "Field Goal:      [" << string(fgPercentage / 2, '=') << ">" << "] " << fgPercentage << "%" << endl;
        cout << "3-Point Shot:    [" << string(threePtPercentage / 2, '=') << ">" << "] " << threePtPercentage << "%" << endl;
    }

    virtual string toFileString() const {
        return name + "," + position + "," + to_string(fgPercentage) + "," + to_string(threePtPercentage);
    }
};

// Function to get validated float input
float getValidatedPercentage(const string& prompt) {
    float value;
    while (true) {
        cout << prompt;
        cin >> value;
        if (cin.fail() || value < 0.0f || value > 100.0f) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Enter a percentage between 0 and 100.\n";
        } else {
            break;
        }
    }
    return value;
}

// Save to file (optional feature)
void savePlayerToFile(const Player& player, const string& filename) {
    ofstream outFile(filename, ios::app);  // append mode
    if (outFile.is_open()) {
        outFile << player.toFileString() << endl;
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

    fg = getValidatedPercentage("Enter Field Goal %: ");
    threePt = getValidatedPercentage("Enter 3-Point %: ");

    Player player(name, position, fg, threePt);

    cout << "\n=== Player Overview ===\n";
    player.displayStats();
    player.displayChart();

    // Optional: save to file
    char save;
    cout << "\nSave player data to file? (y/n): ";
    cin >> save;
    if (tolower(save) == 'y') {
        savePlayerToFile(player, "nba_players.txt");
    }

    return 0;
}
