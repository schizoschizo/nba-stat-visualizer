# 🏀 NBA Player Effectiveness Visualizer

This C++ project is a command-line application that allows users to input an NBA player's name, position, field goal percentage, and 3-point shooting percentage. 
It then displays a visual chart of the player's shooting effectiveness directly in the terminal. 
The project demonstrates core C++ concepts and is suitable for inclusion in a developer portfolio.

## 🎯 Project Goals

- Use **C++ classes and inheritance**
- Apply **file I/O (streams)** to save player data
- Implement **data validation and error handling**
- Visualize data using basic ASCII graphics
- Practice **modular design** and clean coding principles

---

## 💡 Features

- Accepts and validates player statistics (FG% and 3PT%)
- Displays formatted shooting stats
- Visual ASCII bar chart visualization
- Option to save stats to a `.txt` file
- Designed using modern C++ best practices

---

## 🛠 Technologies Used

- Language: C++17
- IDE: Visual Studio Code
- External Libraries: None (standard C++)

---

## 📁 Project Structure
nba-visualizer/
├── main.cpp // Source code
├── nba_players.txt // Output file (generated)
├── README.md // This file

---

## 🧪 Testing

Manual test cases are handled via user input. Edge cases include:
- Invalid percentage values (< 0 or > 100)
- Empty or malformed input

---

## ▶️ How to Run

1. Clone the repo:
   ```bash
   git clone https://github.com/schizoschizo/nba-stat-visualizer.git
   cd nba-stat-visualizer
