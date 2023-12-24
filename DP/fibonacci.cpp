#include<iostream>
#include<assert.h>
#include<vector>
#include<string.h>
using namespace std;

//* the key to understanding the Dynamic programming by understanding What&How concept
//* try to tracing a recursion by abstraction way not a level by level way
//* if the base case correct then the recursion is correct proofing by induction
/*
// time complixity: O(2^n)
int fib(int n){     // define fun with paramiter
    if (n <= 1)     // base case here tow case fib(0) and fib(1)
        return 1;
    
    return fib(n-1)+fib(n-2); // math: fib(n) = fib(n-1) + fib(n-2)
}
*/
// re-write fun by using DP algorithm
// time complixity : O(n), Space complixity O(n)
/* typedef long long ll;
vector<ll> memory;

ll fib(int n){
    if (n <= 1)
        return 1;
    // if this node calculate befor or not
    if(memory[n] != -1) // for DP and this like visited vector in DFS
        return memory[n];

    return memory[n] = fib(n-1) + fib(n-2);

}*/

// we rewrite the fun by compatitive programming impelementation

/*typedef long long ll;
const int MAX = 80+1;
ll memory[MAX];

ll fib(int n){

    if (n <= 1)
        return 1;

    ll &ret= memory[n];
    if (ret != -1)
        return ret;

    return ret=fib(n-1)+fib(n-2);
}
*/
string res="    ";
void rec(int idx){
    if (idx == (int)res.size()){
        cout<<res<<"\n";
        return;
    }

    res[idx]='0';
    rec(idx+1);
    
    res[idx]='1';
    rec(idx+1);

    res[idx] = ' ';
    }


int main(){

    rec(0);
    //int n = 80;
    //memory.resize(n+1);
    //fill(memory.begin(),memory.end(),-1); // O(n)
    // to set array with -1
    //memset(memory,-1,sizeof(memory)); // more speed than fill fun
    //cout<<fib(80)<<"\n";
    //cout<<fib(40); // output: 165580141 with time: 7.354 sec
    //cout<<fib(80); // this never end why? find any observation 

    return 0;
}