class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int visited = 0;
        vector<int> indeg(numCourses, 0);
        map<int, vector<int>> edge;
        for(const auto& p: prerequisites){
            edge[p[1]].push_back(p[0]);
            ++indeg[p[0]];
        }
        queue<int> q;
        for(int i = 0; i < numCourses; ++i){
            if(indeg[i] == 0){
                q.push(i);
                ++visited;
            }
        }
        while(!q.empty()){
            int course = q.front(); q.pop();
            for(int i = 0; i < edge[course].size(); ++i){
                int post_course = edge[course][i];
                if(--indeg[post_course] == 0){
                    q.push(post_course);
                    ++visited;
                }
            }
        }
        return visited == numCourses;
    }
};