#include<bits/stdc++.h>
using namespace std;
void subsets(string s, int index, string path){
    if(index == s.size()){
        cout<<path<<endl;
        return;
    }
    //Take the character
    subsets(s, index+1, path+s[index]);
    //Skip the character
    subsets(s, index+1, path);
}
void getAllBinarystrings(int n, string path){
    if(n == path.size()){
        cout<<path<<endl;
        return;
    }
    getAllBinarystrings(n, path+"0");
    getAllBinarystrings(n, path+"1");
}

void noConsecutiveOnes(int n, string path){
    if(path.size() == n){
        cout<<path<<endl;
        return;
    }
    noConsecutiveOnes(n, path+"0");
    if(path.empty() || path.back() != '1'){
    noConsecutiveOnes(n, path + "1");
    }

}
void printPermutations(string &s, int index){
    if(index == s.size()){
        cout<<s<<endl;
        return;
    }
    for(int i=index; i<s.size(); i++){
        swap(s[i], s[index]);
        printPermutations(s, index+1);
        swap(s[i], s[index]);
    }
}
int main(){
    subsets("abc",0,"");
    cout<<endl;
    getAllBinarystrings(3,"");
    cout<<endl;
    noConsecutiveOnes(3,"");
    cout<<endl;
    string s = "abc";
    printPermutations(s,0);
    cout<<endl;
    return 0;
}