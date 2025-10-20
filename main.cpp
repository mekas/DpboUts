#include <iostream>

using namespace std;

enum PrimaryPrompt{LIST_FILE, CREATE_FILE, OPEN_FILE, EXIT};

int main(){
    PrimaryPrompt mainPrompt = LIST_FILE;
    cout << endl;
    bool liveState = 1;
    bool promptMode = 1;
    while(liveState){
        if(promptMode){
            cout << "Select an option: " << endl;
            cout << "1. List files" << endl;
            cout << "2. Create file" << endl;
            cout << "3. Open file" << endl;
            cout << "4. Exit" << endl;
            int choice;
            cin >> choice;
            mainPrompt = static_cast<PrimaryPrompt>(choice - 1);
        }
        switch(mainPrompt){
            case LIST_FILE:{
                break;
            }
            case CREATE_FILE:{
                break;
            }
            case OPEN_FILE:{
                break;
            }
            case EXIT:{
                liveState = 0;
                break;
            }
        }
        cout << endl;
    }
    return -1;
}