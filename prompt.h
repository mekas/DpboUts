#include <iostream>
#include <fstream> 
#include <vector>

#include "custom_file.h"

using namespace std;

void createFileSubPrompt(){
    //bool isPrompt(true);
    string title, author, filename;

    cout << "Name of the file: ";
    cin >> filename;
    cout << "Enter article title: ";
    cin >> title;

    cout << "Enter article content: " << endl;
    //cin >> content;
    string lines;
    // Read input lines until an empty line is encountered
    string input;
    cin.clear();
    std::cin.ignore(1000, '\n');
    while (getline(cin, input)) {
        if (input.empty()) {
            break;
        }
        lines += "\n\n";
        lines += input;
    }

    cout << "Enter article author:";
    cin >> author;
    CustomFile cf = CustomFile(title, lines, author);
    ofstream file(filename);
    if(!file){
        cerr << "Failed to create file" << endl;
        return;
    }

    file << cf.getTitle();
    file << cf.getContent() << endl << endl;
    file << cf.getAuthor();

    file.close();
}

void openFileSubPrompt(){
    
}
