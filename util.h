#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>

using namespace std;

int seek_dot_position(const string &name){
    int size = static_cast<int>(name.length());
    for(int i=2; i < size;i++){
        //cout << name;
        if(name[i] == '.'){
            return i;
        }
    }
    return -1;
}

bool filter_file(const string &name, const string &ext){
    int dot_pos = seek_dot_position(name);
    //cout << dot_pos << endl;
    if (dot_pos < 0)
        return false;
    const string name_suffix = name.substr(dot_pos, name.length());
    if(name_suffix == ext)
        return true;
    return false;
}

#endif

