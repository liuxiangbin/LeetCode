/*
There are a total of n courses you have to take, labeled from 0 to n - 1.

Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]

Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?

For example:

2, [[1,0]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.

2, [[1,0],[0,1]]
There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
*/

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<list<int> > graph(numCourses);
        vector<int> indegree(numCourses,0);
        
        vector<pair<int,int> >::iterator it = prerequisites.begin();
        for(;it!=prerequisites.end();++it){
            graph[it->second].push_back(it->first);
            ++indegree[it->first];
        }
        
        while(true){
            int i;
            for(i=0;i<numCourses;++i){
                if(indegree[i]==0&&indegree[i]!=-1){
                    list<int>::iterator lit = graph[i].begin();
                    for(;lit!=graph[i].end();++lit)
                        --indegree[*lit];
                    indegree[i] = -1;
                    break;
                }
            }
            if(i==numCourses)
                break;
        }
        
        for(int i=0;i<numCourses;++i)
            if(indegree[i] > 0)
                return false;
        
        return true;
    }
};