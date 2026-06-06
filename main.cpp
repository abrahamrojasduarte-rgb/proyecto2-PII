#include <iostream>

#include "Menu.h"

using namespace std;

int main() {

    try {
        Menu::startMenu();
    }
    catch(const exception& e) {
        cout << "Error: " << e.what() << endl;
    }


    cout<<"Wassup nagger";
    return 0;
}