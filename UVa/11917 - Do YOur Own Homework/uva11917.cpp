#include <bits/stdc++.h>

using namespace std;

int main(){
    int nCases = 0, i = 1;
    cin >> nCases;
    while (nCases --)
    {
        int subjects;
        bool finished = false;
        cin >> subjects;
        string s;
        int due_days, tmp;
        vector<pair<string, int> > days(subjects);
        for(int i = 0; i < subjects; ++i) {
            cin >> s >> tmp;
            days[i] = make_pair(s, tmp);
        }
        cin >> due_days >> s;
        cout << "Case " << i++ << ": ";
        for(int i = 0; i < subjects; ++i)
        {
            if (s.compare(days[i].first) == 0){
                if (days[i].second <= due_days) cout << "Yesss\n";
                else if(days[i].second <= due_days + 5) cout << "Late\n";
                else cout << "Do your own homework!\n";
                finished = true;
                break;
            }
        }
        if(!finished) cout << "Do your own homework!\n";
    }
}
