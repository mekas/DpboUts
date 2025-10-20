#include <iostream>
#include <fstream> 
#include <iterator>
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
    cout << "Enter filename to open: ";
    string fname;
    cin >> fname;

    ifstream file(fname);
    string line;
    string title, content, author;
    vector<string> lines;
    
    if(file.is_open()){
        int n = 0;
        while (getline(file, line)) {
            // Process the line
            if(n==0){
                cout << line << endl;
                title = line;
                n++;
                continue;
            }
            lines.push_back(line);
            //don't immediately print
            //cout << line << endl;
        }

        //loop lines again
        uint i=0;
        for(auto line: lines){
            if(i==lines.size()-1){
                author = line;
                break;
            }
            content += "\n";
            content += line;
            i++;
        }
        CustomFile cf(title, content, author);
        cout << "title: " << cf.getTitle() << endl;
        cout << "content: " << endl;
        cout << cf.getContent() << endl;
        cout << "author: " << cf.getAuthor();
    } else{
        cout << "no file found" << endl;
    }
}
