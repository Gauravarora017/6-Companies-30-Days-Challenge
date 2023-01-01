// https://leetcode.com/problems/evaluate-reverse-polish-notation/description/

//reverse polish notation  = postfix notation

//Postfix evaluation

#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack <int> s;

        for(int i = 0;i<tokens.size();i++){
            if(tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/"){
                int b = s.top();
                s.pop();
                int a = s.top();
                s.pop();
                int z;

                if(tokens[i] == "+"){
                    z = a+b;
                }
                else if(tokens[i] == "-"){
                    z = a-b;
                }
                else if(tokens[i] == "*"){
                    z = a*b;
                }
                else {
                    z = a/b;
                }

                s.push(z);
                
            }
            else {
                int temp = stoi(tokens[i]);
                s.push(temp);
                
            }
        }
        return s.top();
    }
};