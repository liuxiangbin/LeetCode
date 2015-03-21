/*
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.

If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place, do not allocate extra memory.

Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
*/

class Solution {
public:
    void nextPermutation(vector<int> &num) {
        typedef vector<int>::iterator itv;
        
        itv first = num.begin(),last = num.end();
        if(first == last)
            return ;
        
        itv i = first;
        ++i;
        if(i==last)
            return;
        
        i = last;
        --i;
        
        for(;;){
            itv ii = i;
            --i;
            if(*i < *ii){
                itv j = last;
                while(!(*i<*--j)){}
                iter_swap(i,j);
                reverse(ii,last);
                return;
            }
            
            if(i == first){
                reverse(first,last);
                return;
            }
        }
    }
};