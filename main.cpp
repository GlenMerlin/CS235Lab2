#include <iostream>
#include <string>
#include <stack>

using namespace std;

stack<char> characters;
bool balance = true;

bool calc(char query){
    if (!characters.empty()){
        while (!characters.empty() && balance != false){
            if (characters.top() == query){
                characters.pop();
                return true;
            }
            else {
                return false;
            }
        }
    }
    return false;  
}

int main(int argc, char *argv[])
{
    string input = argv[1];
    int nonBracketCount = 0;

    for (char &groupChar : input){
        switch(groupChar){

            case '(':{
                cout << "found a ( " << endl;
                characters.push(groupChar);
                break;
            }

            case '<':{
                cout << "found a < " << endl;
                characters.push(groupChar);
                break;
            }
            
            case '{':{
                cout << "found a { " << endl;
                characters.push(groupChar);
                break;
            }

            case '[':{
                cout << "found a [ " << endl;
                characters.push(groupChar);
                break;
            }

            case ')':{
                cout << "found a ) " << endl;
                balance = calc('(');
                break;
            }

            case '>':{
                cout << "found a > " << endl;
                balance = calc('<');
                break;
            }

            case '}':{
                cout << "found a } " << endl;
                balance = calc('{');
                break;
                
            }

            case ']':{
                cout << "found a ] " << endl;
                balance = calc('[');
                break;
            }
            default:{
                nonBracketCount++;
                break;
            }
        }
    }
    if (nonBracketCount == input.size()){
            cout << "ERROR: No Bracket Characters Found! (try entering (),{},[], or <>)" << endl;
            cout << "true" << endl;
    }
    else if(balance && characters.empty()){
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }
}
