#include<iostream> 
using namespace std; 
int main() 
{ 
int a = 14, c = 3, m = 100; 
int X = 25;        
// Seed value 
int n = 5;        
// Number of random numbers 
cout<<"Random numbers using Mixed Linear Congruential Method:\n"; 
for (int i = 0; i<n; i++) 
{ 
X = (a*X+c) %m; 
float R = (float)X/m; 
cout<<R<<endl; 
} 
return 0; 
}
