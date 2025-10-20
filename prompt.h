#include <iostream>
#include "custom_file.h"

using namespace std;

void createFileSubPrompt(){
    //bool isPrompt(true);
    string title, content, author, filename;

    cout << "Name the file: " << endl;
    cin >> filename;
    cout << "Enter article title: ";
    cin >> title;

    cout << "Enter article content: ";
    cin >> content;

    cout << "Enter article author:";
    cin >> author; 
    CustomFile cf = CustomFile(title, content, author);
}
