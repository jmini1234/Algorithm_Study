#include <bits/stdc++.h>

#define NUM_COLUMN 4

using namespace std;

int find_max(vector<int> v, int except) {
    int max = 0;
    for (int idx = 0; idx < v.size(); idx++) {
        if (max < v[idx] && idx != except)
            max = v[idx];
    }
    return max;
}

int solution(vector<vector<int> > land)
{
    int answer = 0;
    vector<vector<int>>::iterator viter = land.begin(), next;
    for (next = viter + 1; next != land.end(); next++) {
        for (int idx = 0; idx < NUM_COLUMN; idx++) {
            (*next)[idx] += find_max((*viter), idx);
        }
        viter = next;
    }
    return find_max((*viter), -1);
}