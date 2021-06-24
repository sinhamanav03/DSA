#include <bits/stdc++.h>

using namespace std;

//********************************************************/
class SpecialStack
{
    // Define the data members.
    int minElem;
    stack<int> stk;
    /*----------------- Public Functions of SpecialStack -----------------*/
public:
    void push(int data)
    {
        // Implement the push() function.
        if (stk.empty())
        {
            stk.push(data);
            minElem = data;
        }
        else if (data < minElem)
        {
            stk.push(2 * data - minElem);
            minElem = data;
        }
        else
        {
            stk.push(data);
        }
    }

    int pop()
    {
        // Implement the pop() function.
        if (stk.empty())
        {
            return -1;
        }
        else
        {
            int tp = stk.top();
            stk.pop();
            if (tp < minElem)
            {
                minElem = 2 * minElem - tp;
            }
            return tp;
        }
    }

    int top()
    {
        // Implement the top() function.
        if (stk.empty())
        {
            return -1;
        }
        else
        {
            if (stk.top() < minElem)
            {
                return minElem;
            }
            else
            {
                return stk.top();
            }
        }
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function.
        if (stk.empty())
        {
            return 1;
        }
        else
        {
            return 0;
        }
    }

    int getMin()
    {
        // Implement the getMin() function.
        if (stk.empty())
        {
            return -1;
        }
        else
        {
            return minElem;
        }
    }
};

//********************************************************/
class Queue
{
    // Define the data members(if any) here.
    stack<int> s1, s2;
    int top;

public:
    Queue()
    {
        // Initialize your data structure here.
        top = 1;
    }

    void enQueue(int val)
    {
        // Implement the enqueue() function.
        s1.push(val);
        top++;
    }

    int deQueue()
    {
        // Implement the dequeue() function.
        if (s2.empty())
        {
            if (s1.empty())
            {
                return -1;
            }
            else
            {
                while (!s1.empty())
                {
                    int tp = s1.top();
                    s1.pop();
                    s2.push(tp);
                }
            }
        }
        int z = s2.top();
        s2.pop();
        return z;
    }

    int peek()
    {
        // Implement the peek() function here.
        if (s2.empty())
        {
            if (s1.empty())
            {
                return -1;
            }
            else
            {
                while (!s1.empty())
                {
                    int tp = s1.top();
                    s1.pop();
                    s2.push(tp);
                }
            }
        }
        int z = s2.top();
        return z;
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function here.
        if (s1.empty() && s2.empty())
        {
            return 1;
        }
        return 0;
    }
};

//********************************************************/

class Queue
{
    // Define the data members(if any) here.
    stack<int> s1, s2;
    int top;

public:
    Queue()
    {
        // Initialize your data structure here.
        top = 1;
    }

    void enQueue(int val)
    {
        // Implement the enqueue() function.
        s1.push(val);
        top++;
    }

    int deQueue()
    {
        // Implement the dequeue() function.
        if (s2.empty())
        {
            if (s1.empty())
            {
                return -1;
            }
            else
            {
                while (!s1.empty())
                {
                    int tp = s1.top();
                    s1.pop();
                    s2.push(tp);
                }
            }
        }
        int z = s2.top();
        s2.pop();
        return z;
    }

    int peek()
    {
        // Implement the peek() function here.
        if (s2.empty())
        {
            if (s1.empty())
            {
                return -1;
            }
            else
            {
                while (!s1.empty())
                {
                    int tp = s1.top();
                    s1.pop();
                    s2.push(tp);
                }
            }
        }
        int z = s2.top();
        return z;
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function here.
        if (s1.empty() && s2.empty())
        {
            return 1;
        }
        return 0;
    }
};

//********************************************************/
#include <queue>
class StackUsingQueue
{
    // Define the data members.
    queue<int> q1, q2;

public:
    StackUsingQueue()
    {
        // Implement the Constructor.
    }

    /*----------------- Public Functions of Stack -----------------*/

    int getSize()
    {
        // Implement the getSize() function.
        return q1.size();
    }

    bool isEmpty()
    {
        // Implement the isEmpty() function.
        return q1.empty();
    }

    void push(int element)
    {
        // Implement the push() function.
        q2.push(element);
        while (!q1.empty())
        {
            int z = q1.front();
            q1.pop();
            q2.push(z);
        }
        queue<int> q = q1;
        q1 = q2;
        q2 = q;
    }

    int pop()
    {
        // Implement the pop() function.
        if (q1.empty())
        {
            return -1;
        }
        int z = q1.front();
        q1.pop();
        return z;
    }

    int top()
    {
        // Implement the top() function.
        if (q1.empty())
        {
            return -1;
        }
        return q1.front();
    }
};