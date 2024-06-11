#include <bits/stdc++.h>
using namespace std;


int main(){
    string input;
    getline(cin, input);

    int closed = 0;

    for (int i = 0;i<input.length();i++){
        if (input[i] == '('){
            for (int j = i+1 ;j<input.length();j++){
                if (input[j] == ')'){
                    closed++;
                    break;
                }
            }
        }
        if (input[i] == '{'){
            for(int j = i+1 ;j<input.length();j++){
                if (input[j] == '}'){
                    closed++;
                    break;
                }
            }
        }
        if (input[i] == '<'){
            for(int j = i+1 ;j<input.length();j++){
            if (input[j] == '>'){
                closed++;
                break;
            }
            }
        }
        if (input[i] == '['){
            for(int j = i+1 ;j<input.length();j++){
            if (input[j] == ']'){
                closed++;
                break;
            }
            }
        }
    }

    if (closed == input.length()/2){
        cout << "Sudah ditutup";
    } else {
        cout << "Belum ditutup";
    }
    return 0;
}