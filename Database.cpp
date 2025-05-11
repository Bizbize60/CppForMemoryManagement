#include "Database.hpp"
#include <iostream>
#include <fstream>
#include <sstream>

void Database::set(const string& key, const string& value) {
    data[key] = value;
    printf("OK");


}

bool Database::get(const string& key, string& out){
    auto it = data.find(key);
    if (it != data.end()) {
        out = it->second;
        return true;
    }
    return false;
}

bool Database::del(const string& key) {
    return data.erase(key) > 0;
}

void Database::saveToFile(const string& filename) {
    ofstream out(filename);
    for (const auto& [key, value] : data) {
        out << key << "=" << value << "\n";
    
}
    printf("Kayıtlar Dosyaya Yazıldı \n");
    
}

void Database::loadFromFile(const string& filename){
    ifstream in(filename);
    string line;
    while(getline(in, line)) {
        size_t eq = line.find('=');
        if (eq != string::npos) {
            string key =line.substr(0,eq);
            string value = line.substr(eq +1);
            data[key] = value;
        }
    }
}

void Database::handleCommand(const string& input){
    istringstream iss(input);
    string cmd;
    iss >> cmd;
    if (cmd == "SET") {
        std::string key, value;
        iss >> key >> value;
        set(key, value);
    }
    else if (cmd == "GET") {
        std::string key;
        iss >> key;
        std::string value;
        if (get(key, value)) {
            std::cout << value << std::endl;
        } else {
            std::cout << "Bulunamadı" << std::endl;
        }
    }
    else if (cmd == "DEL") {
        std::string key;
        iss >> key;
        if (del(key)) {
            std::cout << "Silindi" << std::endl;
        } else {
            std::cout << "Bulunamadı" << std::endl;
        }
    }
    else if (cmd == "SAVE") {
        saveToFile("db.txt");
    }
    else {
        std::cout << "Bilinmeyen komut." << std::endl;
    }

}