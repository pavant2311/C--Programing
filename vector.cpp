#include<iostream>
#include<vector>


#include<algorithm>
using namespace std;

int main()
{
 vector<int> v={4,3,2,5,7,67,34,23,12,33,11,22,22,11,12}
 vector<int>:: iterator oo;


    sort::sort(v.begin(),v.end());
    oo = std::unique(v.begin(), v.begin() + 15);     
    v.resize(std::distance(v.begin(), oo));

    for (oo = v.begin(); oo != v.end(); ++oo) 
    { 
        cout << *oo << " "; 
    } 
  
    return 0; 

}
