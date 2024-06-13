class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>Stack;
        for (int asteroid : asteroids)
            if (Stack.empty()||asteroid>0) Stack.push_back(asteroid);
            else
            {
                while (!Stack.empty()&&Stack.back()>0&&Stack.back()<abs(asteroid))
                    Stack.pop_back();
                
                if (Stack.empty()||Stack.back()<0) Stack.push_back(asteroid);
                else if (Stack.back()==-asteroid) Stack.pop_back();
            }
        return Stack;
    }
};