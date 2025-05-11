#ifndef DATABASE_HPP
#define DATABASE_HPP

#include <string>
#include <map>
#include <iostream>

using namespace std;

class Database {

    private:
        map<string,string> data;

    public:
        void set (const string& key, const string& value);
        bool get(const string& key, string& out);
        bool del (const string& key);
        void saveToFile(const string& filename);
        void loadFromFile(const string& filename);
        void handleCommand(const string& input);
    };

#endif