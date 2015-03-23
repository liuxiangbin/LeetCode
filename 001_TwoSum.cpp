/*Given an array of integers, find two numbers such that they add up to a specific
target number.The function twoSum should return indices of the two numbers such 
that they add up to the target, where index1 must be less than index2. Please note 
that your returned answers (both index1 and index2) are not zero-based.
You may assume that each input would have exactly one solution.
*/
class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result(2);
        
        vector<int> temp(numbers);
        sort(temp.begin(),temp.end());
        
        int i=0,j=temp.size()-1;
        int plus = 0;
        while(i<j){
            plus = temp[i]+temp[j];
            if(plus==target){
                if(temp[i]==temp[j]){
                    vector<int>::iterator it = find(numbers.begin(),numbers.end(),temp[i]);
                    result[0] = it - numbers.begin() + 1;
                    result[1] = find(it+1,numbers.end(),temp[j]) - numbers.begin() + 1;
                }
                else{
                    result[0] = find(numbers.begin(),numbers.end(),temp[i]) - numbers.begin() + 1;
                    result[1] = find(numbers.begin(),numbers.end(),temp[j]) - numbers.begin() + 1;
                    if(result[0]>result[1]){
                        swap(result[0],result[1]);
                    }
                }
                
                return result;
            }
            else if(plus > target){
                --j;
            }
            else{
                ++i;
            }
        }
    }
};