/*
Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:
Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ≤ b ≤ c)
The solution set must not contain duplicate triplets.
    For example, given array S = {-1 0 1 2 -1 -4},

    A solution set is:
    (-1, 0, 1)
    (-1, -1, 2)
*/

//Solution 1:O(N^2*lgN)
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;

        if(num.size() < 3)
            return result;
            
        sort(num.begin(),num.end());
        if(num[0]>0 || num[num.size()-1] < 0)
            return result;
            
        typedef vector<int>::iterator itv;

        itv gap = num.begin();
        for(;*gap<0;++gap); 
        
        vector<int> one(3,0);
        if(gap+2<num.end()&&*(gap+2)==0)
            result.push_back(one);

        itv i = num.begin(),j;
        while(i < gap){
            j = i + 1;
            while(j<gap){
                if(binary_search(gap,num.end(),-(*i+*j))){
                    one[0] = *i;
                    one[1] = *j;
                    one[2] = -(*i+*j);
                    result.push_back(one);
                }
                while(j+1<gap&&*(j+1)==*j) ++j;
                ++j;
            }
            while(i+1<gap&&*(i+1)==*i) ++i;
            ++i;
        }
        
        i = gap;
        while(i < num.end()){
            j = i + 1;
            while(j<num.end()){
                if(binary_search(num.begin(),gap,-(*i+*j))){
                    one[0] = -(*i+*j);
                    one[1] = *i;
                    one[2] = *j;
                    result.push_back(one);
                }
                while(j+1<num.end()&&*(j+1)==*j) ++j;
                ++j;
            }
            while(i+1<num.end()&&*(i+1)==*i) ++i;
            ++i;
        }
        
        return result;
    }
};

//Solution 2:O(N^2)
class Solution {
public:
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > result;

        int len = num.size();
        if(len < 3)
            return result;
            
        sort(num.begin(),num.end());
        
        if(num[0]>0 || num[len-1] < 0)
            return result;
        
        vector<int> one(3,0);
        for(int i=0;i<len-2;++i){
            int a = num[i];
            int start = i+1, end = len-1;
            while(start < end){
                int sum = a+num[start]+num[end];
                if(sum == 0){
                    one[0] = a;
                    one[1] = num[start];
                    one[2] = num[end];
                    result.push_back(one);
                    while(start<end&&num[start+1]==num[start]) ++start;
                    ++start;
                    while(start<end&&num[end-1]==num[end]) --end;
                    --end;
                }
                else if(sum < 0){
                    ++start;
                }
                else{
                    --end;
                }
            }
            while(num[i+1] == a) ++i;
        }
        
        return result;
    }
};