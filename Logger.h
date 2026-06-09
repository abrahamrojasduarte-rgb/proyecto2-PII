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

public:
    Logger(const string& filename);
    void log(const string& message);
    void close();
};


#endif //PROYECTOII_LOGGER_H