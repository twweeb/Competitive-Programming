//
//  main.cpp
//  
//
//  Created by Lei Hsiung on 4/7/20.
//  Copyright © 2020 Lei Hsiung. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

struct poker{
    int n_i = 0, r_i = 0;
    bool loss = false;
    vector<int> hand;
    vector<int> secretSeq;
    int cnt_cards[14] = {0};
};

int get_rank (string s)
{
    if(s[s.size()-1] - 'J' == 0) return -1;
    else if (s.size() == 3)return 10*(s[0]-'0') + (s[1] - '0');
    else return (s[0]-'0');
}

void remove_dup(poker* player)
{
    for (int i = 1; i <= 13; ++i)
    {
        if(player->cnt_cards[i] >= 2)
        {
            int cnt = 0;
            auto it = player->hand.begin();
            while (it != player->hand.end())
            {
                if (player->cnt_cards[i] < 2 && cnt == 2) break;
                else if (*it == i)
                {
                    it = player->hand.erase(it);
                    player->cnt_cards[i]--;
                    player->n_i--;
                    cnt++;
                }
                else it++;
            }
        }
    }
}

void reset_poker(poker* player)
{
    for (int i = 0; i < 3; ++ i)
    {
        player[i].n_i = 0;
        player[i].r_i = 0;
    }
}

void show_hand(poker* player) // For Debug
{
    for (int i = 0; i < 3; ++ i)
    {
        cout << "player " << i << ": ";
        for (int s: player[i].hand) cout << s << " ";
        cout << endl;
    }
}

bool isEnd(poker* player)
{
    return (player[0].n_i == 0) | (player[1].n_i == 0) | (player[2].n_i == 0);
}

void solve() 
{
    int nCases = 0, num = 0, card;
    cin >> nCases;
    while (nCases --)
    {
        poker PlayerHand[3];
        reset_poker(PlayerHand);
        string str;
        for (int i = 0; i < 3; ++i)
        {
            cin >> PlayerHand[i].n_i;
            PlayerHand[i].loss = false;
            for (int j = 0; j < PlayerHand[i].n_i; ++j)
            {
                cin >> str;
                card = get_rank(str);
                PlayerHand[i].hand.push_back(card);
                if (card == -1) PlayerHand[i].loss = true;
                else PlayerHand[i].cnt_cards[card]++;
            }
            remove_dup(&PlayerHand[i]);
        }
        for (int i = 0; i < 3; ++i)
        {
            cin >> PlayerHand[i].r_i;
            int a_i;
            for (int j = 0; j < PlayerHand[i].r_i; ++j)
            {
                cin >> a_i;
                PlayerHand[i].secretSeq.push_back(a_i);
            }
        }
        int round_cnt = 0; bool flag = false;
        while (round_cnt++ < 100000) {
            if (flag) break;
            int k = 0, t = 0, t_p = 0;
            for (int i = 0; i < 3; ++i)
            {
                if (isEnd(PlayerHand)) 
                {
                    flag = true;
                    break;
                }
                t_p = (i+1)%3;
                t = PlayerHand[t_p].n_i;
                k = (PlayerHand[i].secretSeq[(round_cnt - 1)%PlayerHand[i].r_i] + t - 1) % t;
                card = PlayerHand[t_p].hand[k];
                PlayerHand[i].hand.push_back(card);

                card = PlayerHand[t_p].hand[k];
                if (card == -1)
                {
                    PlayerHand[t_p].loss = false;
                    PlayerHand[i].loss = true;
                }
                else
                {
                    PlayerHand[t_p].cnt_cards[card]--;
                    PlayerHand[i].cnt_cards[card]++;
                }
                PlayerHand[t_p].hand.erase(PlayerHand[t_p].hand.begin()+k);
                PlayerHand[i].n_i++; PlayerHand[t_p].n_i--;
                remove_dup(&PlayerHand[i]);
            }
        }
        if (flag)
        {
            if (PlayerHand[0].loss) cout << "Alice\n";
            else if (PlayerHand[1].loss) cout << "Bob\n";
            else if (PlayerHand[2].loss) cout << "Carol\n";
        }
        else cout << "Good Game\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    solve();
    return 0;
}