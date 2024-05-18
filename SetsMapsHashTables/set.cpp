#include <iostream>
#include <string>
#include <set>
#include <map>

int main() {
    std::set<std::string> classes;
    classes.insert("COMP 112");
    classes.insert("COMP 165");
    classes.insert("COMP 200");
    classes.insert("COMP 265");
    classes.insert("COMP 210");


    std::map<std::string, char> grades;
    grades["COMP 112"] = 'A';
    grades["COMP 165"] = 'C';
    grades["COMP 200"] = 'A';
    grades["COMP 265"] = 'B';
    grades["COMP 210"] = 'B';

    for (auto i = classes.begin(); i != classes.end(); i++) {
        std::cout << *i  << " Grade: " << grades[*i] << std::endl;
    }

}
