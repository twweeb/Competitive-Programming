#include <bits/stdc++.h>

using namespace std;

int last_person(int n, int m) 
{ 
    queue<int> city;
    for(int i = 1; i <= n; i++) city.push(i);
    int t;
    while(city.size()!=2)
    {
        city.pop();
        for(int i = 0; i < m-1; i++)
        {
            t = city.front();
            city.pop();
            city.push(t);
        }
    }
    city.pop();
    return city.front();
} 

int main(){
    int n;
    cin >> n;
    while (n!=0)
    {
        int m = 1;
        while (2 != last_person(n, m)) m++;
        cout << m << endl;

        cin >> n;
    }
}
