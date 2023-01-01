// https://leetcode.com/problems/combination-sum-iii/description/

// simple backtracking problem

#include<bits/stdc++.h>
using namespace std;
 
class Solution {
public:

    void solve(vector<vector<int>> &ans,vector<int> &res,int k,int n,int num){
        if(k==0){
            if(n==0){
                ans.push_back(res);
            }
            return;
        }
        if(num>9){
            return;
        }

        res.push_back(num);
        solve(ans,res,k-1,n-num,num+1);

        //backtrack
        res.pop_back();
        solve(ans,res,k,n,num+1);
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> res;

        solve(ans,res,k,n,1);
        return ans;
    }
};