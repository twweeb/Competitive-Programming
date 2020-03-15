//
//  main.cpp
//  (#11943) QuickSort for Molecules (CS2351)
//
//  Created by Magic Bear on 2018/5/30.
//  Copyright © 2018年 Magic Bear. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <stack>
#include <iomanip>

using namespace std;

string name[1000];
string formula[1000];
float mass[1000];
map<string, float> PeriodicTable;
int cnt = 0;

void init(){
    PeriodicTable.insert(pair<string, float>("H", 1.00));
    PeriodicTable.insert(pair<string, float>("He", 4.00));
    PeriodicTable.insert(pair<string, float>("Li", 7.00));
    PeriodicTable.insert(pair<string, float>("Be", 9.00));
    PeriodicTable.insert(pair<string, float>("B", 11.00));
    PeriodicTable.insert(pair<string, float>("C", 12.00));
    PeriodicTable.insert(pair<string, float>("N", 14.00));
    PeriodicTable.insert(pair<string, float>("O", 16.00));
    PeriodicTable.insert(pair<string, float>("F", 19.00));
    PeriodicTable.insert(pair<string, float>("Ne", 20.00));
    PeriodicTable.insert(pair<string, float>("Na", 23.00));
    PeriodicTable.insert(pair<string, float>("Mg", 24.00));
    PeriodicTable.insert(pair<string, float>("Al", 27.00));
    PeriodicTable.insert(pair<string, float>("Si", 28.00));
    PeriodicTable.insert(pair<string, float>("P", 31.00));
    PeriodicTable.insert(pair<string, float>("S", 32.00));
    PeriodicTable.insert(pair<string, float>("Cl", 35.00));
    PeriodicTable.insert(pair<string, float>("Ar", 40.00));
    PeriodicTable.insert(pair<string, float>("K", 39.00));
    PeriodicTable.insert(pair<string, float>("Ca", 40.00));
    PeriodicTable.insert(pair<string, float>("Sc", 45.00));
    PeriodicTable.insert(pair<string, float>("Ti", 48.00));
    PeriodicTable.insert(pair<string, float>("V", 51.00));
    PeriodicTable.insert(pair<string, float>("Cr", 52.00));
    PeriodicTable.insert(pair<string, float>("Mn", 55.00));
    PeriodicTable.insert(pair<string, float>("Fe", 56.00));
    PeriodicTable.insert(pair<string, float>("Co", 59.00));
    PeriodicTable.insert(pair<string, float>("Ni", 59.00));
    PeriodicTable.insert(pair<string, float>("Cu", 64.00));
    PeriodicTable.insert(pair<string, float>("Zn", 65.00));
    PeriodicTable.insert(pair<string, float>("Ga", 70.00));
    PeriodicTable.insert(pair<string, float>("Ge", 73.00));
    PeriodicTable.insert(pair<string, float>("As", 75.00));
    PeriodicTable.insert(pair<string, float>("Se", 79.00));
    PeriodicTable.insert(pair<string, float>("Br", 80.00));
    PeriodicTable.insert(pair<string, float>("Kr", 84.00));
    PeriodicTable.insert(pair<string, float>("Rb", 85.00));
    PeriodicTable.insert(pair<string, float>("Sr", 88.00));
    PeriodicTable.insert(pair<string, float>("Y", 89.00));
    PeriodicTable.insert(pair<string, float>("Zr", 91.00));
    PeriodicTable.insert(pair<string, float>("Nb", 93.00));
    PeriodicTable.insert(pair<string, float>("Mo", 96.00));
    PeriodicTable.insert(pair<string, float>("Tc", 97.00));
    PeriodicTable.insert(pair<string, float>("Ru", 101.00));
    PeriodicTable.insert(pair<string, float>("Rh", 103.00));
    PeriodicTable.insert(pair<string, float>("Pd", 106.00));
    PeriodicTable.insert(pair<string, float>("Ag", 108.00));
    PeriodicTable.insert(pair<string, float>("Cd", 112.00));
    PeriodicTable.insert(pair<string, float>("In", 115.00));
    PeriodicTable.insert(pair<string, float>("Sn", 119.00));
    PeriodicTable.insert(pair<string, float>("Sb", 122.00));
    PeriodicTable.insert(pair<string, float>("Te", 128.00));
    PeriodicTable.insert(pair<string, float>("I", 127.00));
    PeriodicTable.insert(pair<string, float>("Xe", 131.00));
    PeriodicTable.insert(pair<string, float>("Cs", 133.00));
    PeriodicTable.insert(pair<string, float>("Ba", 137.00));
    PeriodicTable.insert(pair<string, float>("La", 139.00));
    PeriodicTable.insert(pair<string, float>("Ce", 140.00));
    PeriodicTable.insert(pair<string, float>("Pr", 141.00));
    PeriodicTable.insert(pair<string, float>("Nd", 144.00));
    PeriodicTable.insert(pair<string, float>("Pm", 145.00));
    PeriodicTable.insert(pair<string, float>("Sm", 150.00));
    PeriodicTable.insert(pair<string, float>("Eu", 152.00));
    PeriodicTable.insert(pair<string, float>("Gd", 157.00));
    PeriodicTable.insert(pair<string, float>("Tb", 159.00));
    PeriodicTable.insert(pair<string, float>("Dy", 163.00));
    PeriodicTable.insert(pair<string, float>("Ho", 165.00));
    PeriodicTable.insert(pair<string, float>("Er", 167.00));
    PeriodicTable.insert(pair<string, float>("Tm", 169.00));
    PeriodicTable.insert(pair<string, float>("Yb", 173.00));
    PeriodicTable.insert(pair<string, float>("Lu", 175.00));
    PeriodicTable.insert(pair<string, float>("Hf", 178.00));
    PeriodicTable.insert(pair<string, float>("Ta", 181.00));
    PeriodicTable.insert(pair<string, float>("W", 184.00));
    PeriodicTable.insert(pair<string, float>("Re", 186.00));
    PeriodicTable.insert(pair<string, float>("Os", 190.00));
    PeriodicTable.insert(pair<string, float>("Ir", 192.00));
    PeriodicTable.insert(pair<string, float>("Pt", 195.00));
    PeriodicTable.insert(pair<string, float>("Au", 197.00));
    PeriodicTable.insert(pair<string, float>("Hg", 201.00));
    PeriodicTable.insert(pair<string, float>("Tl", 204.00));
    PeriodicTable.insert(pair<string, float>("Pb", 207.00));
    PeriodicTable.insert(pair<string, float>("Bi", 209.00));
    PeriodicTable.insert(pair<string, float>("Po", 209.00));
    PeriodicTable.insert(pair<string, float>("At", 210.00));
    PeriodicTable.insert(pair<string, float>("Rn", 222.00));
    PeriodicTable.insert(pair<string, float>("Fr", 223.00));
    PeriodicTable.insert(pair<string, float>("Ra", 226.00));
    PeriodicTable.insert(pair<string, float>("Ac", 227.00));
    PeriodicTable.insert(pair<string, float>("Th", 232.00));
    PeriodicTable.insert(pair<string, float>("Pa", 231.00));
    PeriodicTable.insert(pair<string, float>("U", 238.00));
    PeriodicTable.insert(pair<string, float>("Np", 237.00));
    PeriodicTable.insert(pair<string, float>("Pu", 244.00));
    PeriodicTable.insert(pair<string, float>("Am", 243.00));
    PeriodicTable.insert(pair<string, float>("Cm", 247.00));
    PeriodicTable.insert(pair<string, float>("Bk", 247.00));
    PeriodicTable.insert(pair<string, float>("Cf", 251.00));
    PeriodicTable.insert(pair<string, float>("Es", 252.00));
    PeriodicTable.insert(pair<string, float>("Fm", 257.00));
    PeriodicTable.insert(pair<string, float>("Md", 258.00));
    PeriodicTable.insert(pair<string, float>("No", 259.00));
    PeriodicTable.insert(pair<string, float>("Lr", 262.00));
    PeriodicTable.insert(pair<string, float>("Rf", 267.00));
    PeriodicTable.insert(pair<string, float>("Db", 270.00));
    PeriodicTable.insert(pair<string, float>("Sg", 269.00));
    PeriodicTable.insert(pair<string, float>("Bh", 270.00));
    PeriodicTable.insert(pair<string, float>("Hs", 270.00));
    PeriodicTable.insert(pair<string, float>("Mt", 278.00));
    PeriodicTable.insert(pair<string, float>("Ds", 281.00));
    PeriodicTable.insert(pair<string, float>("Rg", 281.00));
    PeriodicTable.insert(pair<string, float>("Cn", 285.00));
    PeriodicTable.insert(pair<string, float>("Nh", 286.00));
    PeriodicTable.insert(pair<string, float>("Fl", 289.00));
    PeriodicTable.insert(pair<string, float>("Mc", 289.00));
    PeriodicTable.insert(pair<string, float>("Lv", 293.00));
    PeriodicTable.insert(pair<string, float>("Ts", 293.00));
    PeriodicTable.insert(pair<string, float>("Og", 294.00));
}

void swap(float *a,float *b){
    float tmp = *a;
    a = b;
    *b = tmp;
}
void swap(string *a,string *b){
    string tmp = *a;
    a = b;
    *b = tmp;
}

void quick_sort(float a[], const int left, const int right)
{
    if (left < right) {
    int i = left, j = right + 1, pivot = a[left];
    do {
        do i++; while (a[i] < pivot);
        do j--; while (a[j] > pivot);
        if (i < j){
            swap (a[i], a[j]);
            swap(name[i], name[j]);
            swap(formula[i], formula[j]);
            cnt++;
        }
    } while (i < j);
    
    if(left!=j){
        swap (a[left], a[j]);
        swap(name[left], name[j]);
        swap(formula[left], formula[j]);
        cnt++;
    }

    quick_sort(a, left, j - 1);
    quick_sort(a, j + 1, right);
    }
}

bool isCaps(char c){
    return c-'A'>=0 && c-'Z'<=0;
}

bool isSmall(char c){
    return c-'a'>=0 && c-'z'<=0;
}

bool isDigit(char c){
    return c-'0'>=0 && c-'9'<=0;
}

bool isLeftPara(char c){
    return (c=='(' || c=='[');
}

bool isRightPara(char c){
    return (c==')' || c==']');
}

float calculate_mass(string strs){
    size_t L = strs.length(),i = 0;
    float mass= 0.00,t = 0.00;
    stack<float> ss;
    while(i < L){
        if(isCaps(strs[i])){
            i++;
            if(isSmall(strs[i])) {
                string str(1, strs[i-1]);
                str.push_back(strs[i++]);
                t = PeriodicTable.find(str)->second;
            }
            else {
                string str(1, strs[i-1]);
                t = PeriodicTable.find(str)->second;
            }
            if(isDigit(strs[i])){
                string str(1,strs[i++]);
                while(isDigit(strs[i])){
                    str.push_back(strs[i++]);
                }
                t *= stoi(str);
            }
            mass += t;
        }
        if(isLeftPara(strs[i])){
            ss.push(mass);
            mass = 0;
            i++;
        }
        if(isRightPara(strs[i])){
            if(isDigit(strs[++i])){
                string str(1,strs[i++]);
                while(isDigit(strs[i])){
                    str.push_back(strs[i++]);
                }
                mass *= stoi(str);
            }
            mass += ss.top();
            ss.pop();
        }
    }
    return mass;
}

int main(int argc, const char * argv[]) {
    init();
    int N = 0,M = 0;
    
    cin >> N;
    cout << N << endl;
    while(N--){
        cnt = 0;
        cin >> M;
        cout << M << endl;
        for(int i = 0; i < M; i++){
            cin >> name[i] >> formula[i] >> mass[i];
            if(mass[i]==0){
                mass[i] = calculate_mass(formula[i]);
            }
        }
        quick_sort(mass, 0, M-1);
        for(int i = 0; i < M; i++){
            cout << left << setw(40) << name[i];
            cout << setw(25) << formula[i];
            cout << right << fixed << setprecision(2);
            cout << setw(10) << mass[i] <<endl;
        }
        cout << cnt <<" swaps during qsort" <<endl;
    }
    return 0;
}
