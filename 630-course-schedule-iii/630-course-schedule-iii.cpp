class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        if(courses.size()==1)
            return 1;
        
        sort(courses.begin(), courses.end(), [&](vector<int> v1, vector<int> v2){
            return v1[1] < v2[1];
        });
        
        int total = 0;
        int count = 0;
        
        priority_queue<int,vector<int>> pq;
        
        for(vector<int> course : courses){
            if(course[0] > course[1])
                continue;
            if(course[0] + total <= course[1]){
                count++;
                total += course[0];
                pq.push(course[0]);
            }else{
                int t = pq.top();
                if(t > course[0]){
                    if(total-t + course[0] < course[1]){
                        total = total - t + course[0];
                        pq.pop();
                        pq.push(course[0]);
                    }
                }
            }
        }
        
        return count;
    }
};