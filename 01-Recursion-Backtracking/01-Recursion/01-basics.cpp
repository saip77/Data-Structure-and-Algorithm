#include<iostream>
#include<string>
using namespace std;

void printDesc(int n){
    if(n==0){
        return;
    }
    cout<<n<<" ";
    printDesc(n-1);
}

int printFactorial(int n){
    if(n==0){
        return 1;
    }
    return n*printFactorial(n-1);
}

int printSum(int n){
    if(n==0){
        return 0;
    }
    return n+printSum(n-1);
}
int findWays(int n){
    if(n < 0) return 0;
    if(n==0){
        return 1;
    }
    return findWays(n-1)+findWays(n-2)+findWays(n-3);
}
int printBinary(int n){
    if(n==0){
        return 1;
    }
    return 2*printBinary(n-1);
}
void printBinaryCombination(int n, string path){
    if(n==0){
        cout<<path<<endl;
        return;
    }
    printBinaryCombination(n-1,path+"0");
    printBinaryCombination(n-1,path+"1");
}
int printSumofDigits(int n){
    if(n==0){
        return 1;
    }
    int lastDigit = n%10;
    return lastDigit+printSumofDigits(n/10);
}
int main(){
    printDesc(5);
    cout<<endl;
    cout<<printFactorial(5);
    cout<<endl;
    cout<<printSum(5);
    cout<<endl;
    cout<<findWays(5);
    cout<<endl;
    cout<<printBinary(5);
    cout<<endl;
    printBinaryCombination(2,"");
    cout<<"Count "<<printSumofDigits(1234);
    cout<<endl;
    return 0;
}