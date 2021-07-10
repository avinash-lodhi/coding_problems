/* Problem Description: You are given two 32 bit numbers, N and M, and two bit
            positions, i and j. Write a method to insert M into N such that M 
            starts at bit j and ends at bit i. You can assume that the bits j 
            through i have enough space to fit all of M. That is , if M = 1011,
            you can assume that there are at least 5 bits between j and i. 
            You would not, for example have j=3 and i=2 because M could not
            fully fit between bit 3 and bit 2 */

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

int main(){
    bitset<32> M(string("10000000000"));
    bitset<32> N(string("10011"));
    int i = 2;
    int j = 6;
    bitset<32> mask((~(-1<<i)|(-1<<j+1)));
    cout << "M:   " << M << endl;
    cout << "N:   "  << N << endl;
    cout << "M+N: ";
    cout << ((M & mask)|(N << i)) << endl;
    return 0;
}