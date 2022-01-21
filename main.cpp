#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(int argc, char *argv[]){
    string input = argv[1];
    stack<char> parenthesis, angle, curly, square;
    
    bool failed;
    while (!failed){
            for (char& groupChar : input){
            switch(groupChar){

                case ('('): {
                    parenthesis.push(groupChar);
                }
                case ('<'): {
                    angle.push(groupChar);
                }
                case ('{'): {
                    curly.push(groupChar);
                }
                case ('['): {
                    square.push(groupChar);
                }
                case (')'): {
                    if (!parenthesis.empty()){
                        parenthesis.pop();
                    }
                    else {
                        failed = true;
                    };
                }
                case ('>'): {
                    if (!angle.empty()){
                        angle.pop();
                    }
                    else {
                        failed = true;
                    };
                }
                case ('}'): {
                    if (!curly.empty()){
                        curly.pop();
                    }
                    else {
                        failed = true;
                    };
                }
                case (']'): {
                    if (!square.empty()){
                        square.pop();
                    }
                    else {
                        failed = true;
                    };
                }
                default: {
                    cerr << "unknown input" << endl;
                }
            }
        }
    }
    if (!failed){
        cout << "true" << endl;
    }
    else {
        cout << "false" << endl;
    }   
}