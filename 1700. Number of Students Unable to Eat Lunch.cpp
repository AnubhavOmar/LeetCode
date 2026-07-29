// Solution of LeetCode Problem 
// 1700. Number of Students Unable to Eat Lunch
// Solution in CPP

// Approach - 1 (Counting)
// Time Complexity: O(n)
// Space Complexity: O(1)

class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        
        int n = students.size();
        int student_zero = 0;
        int student_one = 0;

        for(int i = 0; i < n; i++)
        {
            if(students[i] == 0)
            {
                student_zero++;
            }
            else
            {
                student_one++;
            }
        }

        for(int i = 0; i < n; i++)
        {
            if(sandwiches[i] == 0)
            {
                if(student_zero == 0)
                {
                    break;
                }
                student_zero--;
            }
            else
            {
                if(student_one == 0)
                {
                    break;
                }
                student_one--;
            }
        }

        return student_zero + student_one;
    }
};

// Approach - 2 (Queue + Stack Simulation)
// Time Complexity: O(n²)   // Worst case
// Space Complexity: O(n)

class Solution1 {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> stud;
        stack<int> sand;

        int m = students.size();
        int n = sandwiches.size();

        for(int i = 0; i < m; i++)
        {
            stud.push(students[i]);
        }

        for(int i = n - 1; i >= 0; i--)
        {
            sand.push(sandwiches[i]);
        }

        int count = 0;

        while(!stud.empty())
        {
            if(stud.front() == sand.top())
            {
                count = 0;
                stud.pop();
                sand.pop();
            }
            else
            {
                int not_match = stud.front();
                stud.pop();
                count++;
                stud.push(not_match);
            }

            if(stud.size() == count)
            {
                break;
            }
        }

        return stud.size();
    }
};
