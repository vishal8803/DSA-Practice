class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) 
    {
        stack<int> st ;
        int n = asteroids.size() ;
        for(int i =0 ; i<n ; i++)
        {
            if(asteroids[i]<0)
            {
                if(!st.empty())
                {
                    if(st.top()>0)
                    {
                        if(st.top()==abs(asteroids[i]))
                        {
                            st.pop() ;
                            continue ;
                        }
                while(!st.empty() && st.top()>0 && abs(asteroids[i])>st.top())
                        {
                            st.pop() ;
                        }
                        if(!st.empty() && st.top()==abs(asteroids[i]))
                        {
                            st.pop() ;
                            continue ;
                        }
                       if(st.empty() || st.top()<0)
                        st.push(asteroids[i]);
                        
                    }else
                    {
                        st.push(asteroids[i]) ;
                    }
                }else
                {
                    st.push(asteroids[i]) ;
                }
            }else
            {
                st.push(asteroids[i]) ;
            }
            
        }
        vector<int> ans ;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop() ;
        }
        reverse(ans.begin() , ans.end()) ;
        return ans ;
    }
};