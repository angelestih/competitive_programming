#include <bit>
#include <iostream>
#include <vector>
#include <string.h>
#include <algorithm>
#include <iomanip>
#include <stack>
#include <math.h>
#include <bits/stdc++.h>
#include <set>

using namespace std;

int main() {
  //initialize a string
  string s="geeksforgeeks";
  
  // Using an array to store the count of each alphabet 
  // by mapping the character to an index value

  int arr[26]={0};
  
  //Storing the count
  for(int i=0;i<s.size();i++){
    arr[s[i]-'a']++;
  }
  
  //Search the count of the character
  char ch='e';
  
  // get count
  cout<<"The count of " <<ch<< " is " <<arr[ch-'a']<<endl;
  return 0;
}
