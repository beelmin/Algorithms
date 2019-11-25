#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> computeTemporaryArray(string pattern) {
    vector<int> index(pattern.size(),0);
    int j = 0;
    for(int i = 1; i < pattern.size(); i++) {
        if(pattern[i] == pattern[j]) {
            index[i] = j+1;
            i++;
            j++;
        }else{
            if(j != 0) {
                j = index[j-1];

            }else{
                index[i] = 0;
                i++;
            }
        }
    }

}

bool KMP(string text, string pattern) {
    vector<int> index = computeTemporaryArray(pattern);
    int i=0,j=0;
    while(i < text.size() && j < pattern.size()) {
        if(text[i] == pattern[j]) {
            i++;
            j++;
        }else{
            if(j != 0) {
                j = index[j-1];

            }else{
                i++;
            }
        }
    }

    if(j == pattern.size()) {
        return true;
    }

    return false;
}



int main() {

    string text = "aabacadek";
    string pattern = "cad";

    cout << boolalpha << KMP(text,pattern) << endl;




    return 0;
}
