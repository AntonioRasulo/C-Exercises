using namespace std; 
#include<iostream>
#include<map>

int main() 
{ 
  
    // initialize container 
    multimap<int, int> mp; 
  
    // insert elements in random order 
    mp.insert({ 2, 30 }); 
    mp.insert({ 1, 40 }); 
    mp.insert({ 3, 60 }); 
    mp.insert({ 2, 20 }); 
    mp.insert({ 5, 50 }); 
  
    // prints the elements 
    cout << "KEY\tELEMENT\n"; 
    for (auto itr = mp.begin(); itr != mp.end(); ++itr) { 
        cout << itr->first 
             << '\t' << itr->second << '\n'; 
    } 
    return 0; 
} 