#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {

    ifstream file;
    srand(time(0));
    int line_til = rand() % 196 + 1;
    cout << line_til << endl;
    file.open("words.txt");


    if(file.fail()) {
        cout << "File failed to open" << endl;
        return 1;
    }

    int current_line=0;
    string line;


    while(!file.eof()) {
        current_line++;
        getline(file, line);

        if(current_line==line_til) break;
    }


    cout << line << endl;

    file.close();

    string guess;
    cout << "Guess a letter: ";
    cin >> guess;

    if(guess.length()>1) {
        while(guess.length()>1) {
            cout << "You must enter 1 letter. Guess a letter: ";
            cin >> guess;
        }
        
    }

    cout << "You guessed " << guess << endl;


    if(line.find(guess)!=string::npos)
        cout << guess << " is in the word " << line << endl;
    else
        cout << guess << " is not in the word " << line << endl;

    




    return 0;
}
