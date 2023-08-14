class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int zero = 0;
        int one = 0;
        list<int> l;
        for(int i : students) {
            if(i) one++;
            else zero++;
            l.push_back(i);
        }
        
        int j = 0;
        int cnt = 0;
        while(j < sandwiches.size() and l.size() > 0) {
            int num = sandwiches[j];
            if(num == 0 and zero == 0) break;
            else if(num == 1 and one == 0) break;
            int num2 = l.front();
            if(num == num2) {
                if(num == 0) zero--;
                else one--;
                l.pop_front();
                j++;
                cnt++;
            } else {
                l.pop_front();
                l.push_back(num2);
            }
        }
        return students.size() - cnt;
    }
};