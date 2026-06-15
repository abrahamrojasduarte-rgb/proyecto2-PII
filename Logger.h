//
// Created by joaoa on 8/6/2026.
//

#ifndef PROYECTOII_LOGGER_H
#define PROYECTOII_LOGGER_H
#include <fstream>
#include <string>
using namespace std;

class Logger {
private:
    ofstream file;
    int entryCount;
    string getTimestamp() const;

public:
    Logger();
    explicit Logger(const string& filename);
    void open(const string& filename);
    void log(const string& message);
    void logSection(const string& title);
    void close();
    int getEntryCount() const;
    bool isOpen() const;
};

#endif //PROYECTOII_LOGGER_H