// https://leetcode.com/problems/bulls-and-cows/description/

#include<bits/stdc++.h>
using namespace std;
 
class Solution {
public:
    string getHint(string secret, string guess) {
        int n = secret.size();
        int m = guess.size();

        int x = 0;
        int y = 0;

        map<int,int> mp1;
        map<int,int> mp2;

        for(int i = 0;i<n;i++){
            if(secret[i]==guess[i]){
                x++;
            }
            else{
                mp1[secret[i]-'0']++;
                mp2[guess[i]-'0']++;
            }
        }

        for(auto i:mp1){
            if(mp2.find(i.first) != mp2.end()){ //present
                y += min(mp2[i.first],i.second);
            }
        }

        string ans = to_string(x) + "A" + to_string(y) + "B";

        return ans;

    }
};