#ifndef CUSTOM_FILE_H
#define CUSTOM_FILE_H

#include <iostream>
#include <string>

using namespace std;

class CustomFile{
private:
    string title;
    string content;
    string author;
public:
    CustomFile();
    CustomFile(const string &title, const string &content, const string &author): title(title), content(content), author(author){}
};

#endif