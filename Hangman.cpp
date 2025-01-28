#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;

string word;
int wrong_guesses=0;
vector<char> word_states;
void output();
void guess(char guessed);
void update_word_states(char guessed);
void get_hangman_art();

int main() {

    ifstream file;
    srand(time(0));
    file.open("words.txt");
    vector<string> words;


    if(file.fail()) {
        cout << "File failed to open" << endl;
        return 1;
    }

    string line;
    while(getline(file, line)) {
        words.push_back(line);
    }

    string word;
    int random = rand() % words.size();
    word = words[random];


    file.close();

    cout << endl;
    cout << "******************" << endl;
    cout << "WELCOME TO HANGMAN" << endl;
    cout << "******************" << endl << endl;


    for(int x=0; x<word.length(); x++) {
        word_states.push_back('_');
    }

    while(wrong_guesses<6) {
        cout << "Word: ";
        output();
        char guessed;
        cout << "Guess a letter: ";
        cin >> guessed;
        guess(guessed);
        update_word_states(guessed);
        get_hangman_art();
        cout << endl;
        if(find(word_states.begin(), word_states.end(), '_')==word_states.end()) {
            cout << "YOU WIN" << endl;
            cout << "The word was " << word << endl;
            break;
        }
    }

    if(wrong_guesses>=6) {
        get_hangman_art();
        cout << endl;
        cout << "GAME OVER" << endl << "The word was " << word << endl;
    }



    




    return 0;
}

void output() {
    for(int x=0; x<word_states.size(); x++) {
        cout << word_states[x] << " ";
    }
    cout << endl;
}

void guess(char guessed) {
    
    if(word.find(guessed)!=string::npos) {
        cout << "Corrent guess!\n" << endl;
    }

    else {
        cout << "Wrong guess!\n" << endl;
        wrong_guesses++;
    }
}

void update_word_states(char guessed) {
    for(int x=0; x<word.length(); x++) {
        if(word[x]==guessed) {
            word_states[x] = guessed;
        }
    }
}

void get_hangman_art() {
    switch(wrong_guesses) {
        case 0:
            break;
        case 1:
            cout << " o" << endl;
            break;
        case 2:
            cout << " o" << endl;
            cout << "/" << endl;
            break;
        case 3:
            cout << " o" << endl;
            cout << "/|" << endl;
            break;
        case 4:
            cout << " o" << endl;
            cout << "/|\\" << endl;
            break;
        case 5:
            cout << " o" << endl;
            cout << "/|\\" << endl;
            cout << "/" << endl;
            break;
        case 6:
            cout << " o" << endl;
            cout << "/|\\" << endl;
            cout << "/ \\" << endl;
            break;
        default:
            cout << "";
            break;

    }
}