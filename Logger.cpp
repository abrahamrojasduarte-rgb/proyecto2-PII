//
// Created by joaoa on 8/6/2026.
//

#include "Logger.h"

Logger::Logger() : entryCount(0) {}

Logger::Logger(const string& filename) : entryCount(0) {
    open(filename);
}

void Logger::open(const string& filename) {
    file.open(filename);
    if (!file.is_open()) {
        throw runtime_error("Error: Could not create log file '" + filename + "'.");
    }
    file << "========================================" << endl;
    file << "  SOUL KNIGHT - Adventure Log" << endl;
    file << "========================================" << endl;
    file << endl;
}

string Logger::getTimestamp() const {
    return "[" + to_string(entryCount) + "] ";
}

void Logger::log(const string& message) {
    if (file.is_open()) {
        entryCount++;
        file << getTimestamp() << message << endl;
    }
}

void Logger::logSection(const string& title) {
    if (file.is_open()) {
        file << endl;
        file << "--- " << title << " ---" << endl;
    }
}

void Logger::close() {
    if (file.is_open()) {
        file << endl;
        file << "========================================" << endl;
        file << "  End of Log - Total entries: " << entryCount << endl;
        file << "========================================" << endl;
        file.close();
    }
}

int Logger::getEntryCount() const {
    return entryCount;
}

bool Logger::isOpen() const {
    return file.is_open();
}
