/*
    Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
*/
class Solution {
public:
    bool isPalindrome(string s) {
       if(s.length()==0)
		return true;

        int i = 0,j = s.length() - 1;
        while(i < j){
            while(!isalnum(s[i]) && i<j) ++i;
            while(!isalnum(s[j]) && j>=0) --j;
            //cout<<s[i]<<" "<<s[j]<<endl;
            if(i>j)
            	return true;
            if(!(toupper(s[i]) == toupper(s[j])))
                return false;
            else{
            	++i;
            	--j;
            }
        }
        
        return true;
    }
};