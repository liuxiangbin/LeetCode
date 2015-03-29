/* 
Given two binary strings, return their sum (also a binary string).

For example,
a = "11"
b = "1"
Return "100". 
*/

//Solution 1
class Solution {
public:
    string addBinary(string a, string b) {
        if(a.empty())
            return b;
        if(b.empty())
            return a;
            
        typedef string::reverse_iterator srit;
        srit ita = a.rbegin();
        srit itb = b.rbegin();
        
        string res;
        int carrier = 0;
        while(ita!=a.rend()&&itb!=b.rend()){
            int tmp = *ita-'0' + *itb-'0';
            res.push_back(((tmp+carrier)&0x1)+'0');
            carrier = (tmp+carrier)/2;
            ++ita;
            ++itb;
        }
        
        while(ita != a.rend()){
            int tmp = *ita - '0';
            res.push_back(((tmp+carrier)&0x1)+'0');
            carrier = (tmp+carrier)/2;
            ++ita;
        }
        while(itb != b.rend()){
            int tmp = *itb - '0';
            res.push_back(((tmp+carrier)&0x1)+'0');
            carrier = (tmp+carrier)/2;
            ++itb;
        }
        
        if(carrier != 0){
            res.push_back(carrier+'0');
        }
        
        reverse(res.begin(),res.end());
        
        return res;
    }
};


//Solution 2: A more beautiful solution
class Solution {
public:
    string addBinary(string a, string b) {
        if(a.empty())
            return b;
        if(b.empty())
            return a;
        
        string res = "";    
        int carrier = 0;
        int i= a.size() - 1, j = b.size() - 1;
        while(i>=0 || j >=0 || carrier > 0){
            carrier += i>=0?a[i--]-'0':0;
            carrier += j>=0?b[j--]-'0':0;
            res += (carrier&0x1) + '0';
            carrier /= 2; 
        }
        
        reverse(res.begin(),res.end());
        
        return res;
    }
};
