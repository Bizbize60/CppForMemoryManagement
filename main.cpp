#include <iostream>
#include <string>
#include "Database.hpp"

int main() {
    Database db;
    db.loadFromFile("db.txt");

    std::string line;
    std::cout << "MiniDB'e hoş geldin! Komut gir (SET, GET, DEL, SAVE):" << std::endl;

    while (std::getline(std::cin, line)) {
        db.handleCommand(line);
    }

    return 0;
}