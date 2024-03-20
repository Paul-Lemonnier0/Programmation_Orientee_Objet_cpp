#include <iostream>
#include <string>
#include <array>
#include <cmath>
#include "TP2.h"

using namespace std;
using tab = std::array<char, 6>;

bool isVoyelle(char c, tab voyelles){
    for(int i = 0; i<6; ++i){
        if(voyelles[i] == c) return true;
    }

    return false;
}

int nbVoyelles(string s){
    tab voyelles = {'a','e','i','o','u','y'};

    int nbVoyelles = 0;
    int strLength = s.length();

    for(int i = 0; i<strLength; ++i){

       if(isVoyelle(s[i], voyelles)){
           nbVoyelles += 1;
       }
    }

    return nbVoyelles;
}

bool isPalindrome(string str){
    int tailleStr = str.length();
    string strReverse = str;

    for(int i = 0; i<tailleStr; ++i){
        if(!(str[i] == str[tailleStr - 1 - i])) {
           return false;
        }
    }

    return true;
}

string chiffrer(string str, int decalage){
    string strCrypted = str;
    int tailleStr = str.length();

    char refa = 'a';
    char refz = 'z';

    char refA = 'A';
    char refZ = 'Z';

    for(int i = 0; i< tailleStr; ++i){
        char cryptedChar = (str[i] + decalage);
        if(cryptedChar <= (90 + decalage)){
            if(cryptedChar > refZ) cryptedChar = cryptedChar - refZ + refA - 1;
        }

        else {
            if(cryptedChar > refz) cryptedChar = cryptedChar - refz + refa - 1;
        }

        strCrypted[i] = cryptedChar;
    }

    return strCrypted;
}

string dechiffrer(string str, int decalage){
    string strCrypted = str;
    int tailleStr = str.length();

    char refa = 'a';
    char refz = 'z';

    char refA = 'A';
    char refZ = 'Z';

    for(int i = 0; i< tailleStr; ++i){
        char cryptedChar = (str[i] - decalage);
        if(cryptedChar >= (65 - decalage)){
            if(cryptedChar < refA) cryptedChar = cryptedChar - refA + refZ + 1;
        }

        else {
            if(cryptedChar < refz) cryptedChar = cryptedChar - refZ + refa + 1;
        }

        strCrypted[i] = cryptedChar;
    }

    return strCrypted;
}

unsigned int retourneEntier(string str){

    int tailleStr = str.length();

    if(str == "") return 0;

    unsigned int lettreInt = str[0] - 48;

    str.erase(0, 1);
    if(lettreInt >= 0 and lettreInt <= 9) {
        lettreInt = lettreInt * pow(10, (tailleStr-1));
        return lettreInt + retourneEntier(str);
    }

    else {
        cerr<<"La chaine contient des charactères";
        return 0;
    }
}

int main()
{
    string s;
    cin>> s;
    cout << "Nombre de voyelles : "<< nbVoyelles(s) << endl;
    cout<<"Est un palindrome ? " << isPalindrome(s)<<endl;
    cout<<"Chiffrer : " << chiffrer(s, 3)<<endl;
    cout<<"Déchiffrer : " << dechiffrer(chiffrer(s, 3), 3)<<endl;
    cout<<"Entier : "<<retourneEntier(s) + 5<<endl;

    return 0;
}
