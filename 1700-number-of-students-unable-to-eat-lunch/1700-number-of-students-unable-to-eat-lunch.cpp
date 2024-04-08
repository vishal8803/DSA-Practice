class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n = students.size();
        int no = 0;
        queue<int> q;
        for(int student: students) {
            no += student;
            q.push(student);
        }
        
        int nz = n - no;
        int i = 0;
        int taken = 0;
        while(i < sandwiches.size()) {
            if(sandwiches[i] == 0 and nz == 0) {
                break;
            } else if(sandwiches[i] == 1 and no == 0) {
                break;
            } else if(sandwiches[i] == q.front()) {
                if(sandwiches[i] == 0) nz--;
                else no--;
                q.pop();
                i++;
                taken++;
            } else {
                int t = q.front();
                q.pop();
                q.push(t);
            }
        }
        
        return n - taken;
    }
};