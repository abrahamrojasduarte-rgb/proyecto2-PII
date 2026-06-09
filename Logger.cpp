//
// Created by joaoa on 8/6/2026.
//

#include "Logger.h"

Logger::Logger(const string &filename) {
    file.open(filename);
}

void Logger::log(const string& message) {
    if (file.is_open()) {
        file << message << endl;
    }
}

void Logger::close() {
    file.close();
}
