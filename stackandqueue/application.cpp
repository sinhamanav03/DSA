#include <bits/stdc++.h>

using namespace std;

// **********************************************************************/
class Node
{
public:
    int key, value;
    Node *prev, *next;
    Node(int k, int v)
    {
        this->key = k;
        this->value = v;
        this->prev = nullptr;
        this->next = nullptr;
    }
};

class LRUCache
{
    Node *head, *tail;
    int maxCap, curCap;
    unordered_map<int, Node *> dict;

public:
    LRUCache(int capacity)
    {
        // Write your code here
        head = nullptr;
        tail = nullptr;
        maxCap = capacity;
        curCap = 0;
    }

    int get(int key)
    {
        // Write your code here
        Node *temp = dict[key];
        // while (temp != nullptr && temp->key != key)
        // {
        //     temp = temp->next;
        // }
        if (temp == nullptr)
        {
            return -1;
        }
        else
        {
            if (temp == head && temp == tail)
            {
                return temp->value;
            }
            if (temp == head)
            {
                head = temp->next;
            }
            if (temp == tail)
            {
                tail = temp->prev;
            }

            if (temp->next != nullptr)
            {
                temp->next->prev = temp->prev;
            }
            if (temp->prev != nullptr)
            {
                temp->prev->next = temp->next;
            }
            temp->next = temp->prev = nullptr;
            tail->next = temp;
            temp->prev = tail;
            tail = tail->next;
            return temp->value;
        }
    }

    void put(int key, int value)
    {
        // Write your code here
        Node *node = new Node(key, value);
        if (head == nullptr)
        {
            head = tail = node;
            curCap += 1;
            dict[key] = node;
        }
        else
        {
            Node *temp = dict[key];
            // while (temp != nullptr && temp->key != key)
            // {
            //     temp = temp->next;
            // }
            if (curCap != maxCap && temp == nullptr)
            {
                tail->next = node;
                node->prev = tail;
                tail = tail->next;
                curCap += 1;
                dict[key] = node;
            }
            else if (temp == nullptr)
            {
                if (head == tail)
                {
                    Node *t = head;
                    head = tail = node;
                    dict[t->key] = nullptr;
                    dict[node->key] = node;
                    delete t;
                }
                else
                {
                    head = head->next;
                    head->prev = nullptr;
                    tail->next = node;
                    node->prev = tail;
                    tail = tail->next;
                    dict[key] = node;
                }
            }
            else
            {
                if (head == tail)
                {
                    Node *t = head;
                    head = tail = node;
                    dict[t->key] = node;
                    delete t;
                    return;
                }
                if (temp == tail)
                {
                    tail = temp->prev;
                }
                if (temp == head)
                {
                    head = temp->next;
                }
                if (temp->prev != nullptr)
                {
                    temp->prev->next = temp->next;
                }
                if (temp->next != nullptr)
                {
                    temp->next->prev = temp->prev;
                }
                temp->next = temp->prev = nullptr;
                delete temp;
                tail->next = node;
                node->prev = tail;
                tail = tail->next;
            }
        }
    }
};
// **********************************************************************/
#define mod 1000000007
int evaluatePostfix(string &exp)
{
    // Write your code here.
    stack<int> st;
    for (int i = 0; i < exp.size(); i += 1)
    {
        if (exp[i] == ' ')
            continue;
        if (exp[i] > 47 && exp[i] < 58)
        {
            int j = i;
            while (j < exp.size() && exp[j] != ' ')
            {
                j++;
            }
            long long int z = stoi(exp.substr(i, j + 1));
            i = j;
            st.push(z);
        }
        else
        {
            int a, b;
            b = st.top();
            st.pop();
            a = st.top();
            st.pop();
            if (exp[i] == '*')
            {
                st.push((a * b) % mod);
            }
            else if (exp[i] == '/')
            {
                st.push((a / b));
            }
            else if (exp[i] == '+')
            {
                st.push((a + b) % mod);
            }
            else
            {
                st.push((a - b) % mod);
            }
        }
    }
    return st.top();
}
//**********************************************************************/
vector<int> nextGreaterElement(vector<int> &arr, int n)
{
    // Write your code here.
    vector<int> nge(n, -1);
    stack<int> st;
    st.push(0);
    for (int i = 1; i < n; ++i)
    {
        while (!st.empty() && arr[st.top()] < arr[i])
        {
            nge[st.top()] = arr[i];
            st.pop();
        }
        st.push(i);
    }
    return nge;
}
//***********************************************************************/
bool isValidParenthesis(string expression)
{
    // Write your code here.
    stack<char> st;
    string op = "([{", ed = ")]}";

    for (int i = 0; i < expression.size(); ++i)
    {
        int z = ed.find_first_of(expression[i]);
        if (z == string::npos)
        {
            st.push(expression[i]);
        }
        else
        {
            if (st.empty() || st.top() != op[z])
            {
                return 0;
            }
            else
            {
                st.pop();
            }
        }
    }
    if (st.empty())
        return 1;
    return 0;
}

//***************************************************************/
#include<string>
#include<stack>
#include<algorithm>

string simplifyDirectory(string str) {
    // Write your code here
    stack<string> dir;
    for(int i=0;i<str.size();++i){
        if(str[i]==' ') continue;
        if(str[i]=='/'){
            int j=i;
            while(j<str.size() && str[j]=='/') j++;
            i=j-1;
        }else if(str[i]=='.'){
            if(i+1<str.size() && str[i+1]=='.') {
                if(!dir.empty()){
                    dir.pop();
                }
                i=i+1;
            }
        }else{
            int j=i;
            while(j<str.size() && str[j]!='.' && str[j]!='/'){
                j++;
            }
            string dirName = str.substr(i,j-i);
            dir.push(dirName);
            i=j-1;
        }
    }
    
    string res = "";
    if (dir.empty())
    {
        res.push_back('/');
    }
    stack<string> rev;
    while(!dir.empty()){
        rev.push(dir.top());
        dir.pop();
    }
    while (!rev.empty())
    {
        res.push_back('/');
        res += (rev.top());
        rev.pop();
    }
    return res;
}

//**************************************************************************/
queue<int> reverseQueue(queue<int> q)
{
    // Write your code here.
    stack<int> stk;
    while(!q.empty()){
        stk.push(q.front());
        q.pop();
    }
    while(!stk.empty()){
        q.push(stk.top());
        stk.pop();
    }
    return q;
}

//**************************************************************************/
queue<int> reverseElements(queue<int> q, int k)
{
    // Write your code here.
    stack<int> st;
    queue<int> res;
    while(k!=0 && !q.empty()){
        st.push(q.front());
        q.pop();
        k--;
    }
    while(!st.empty()){
        res.push(st.top());
        st.pop();
    }
    while(!q.empty()){
        res.push(q.front());
        q.pop();
    }

    return res;
}
//***************************************************************************/
void sortStack(stack<int> &stk)
{
	// Write your code here
    stack<int> s1,s2;
    s1.push(stk.top());
    stk.pop();
    while(!stk.empty()){
        if(stk.top()>s1.top()){
            while(!s2.empty() && s2.top()<stk.top()){
                s1.push(s2.top());
                s2.pop();
            }
        }else{
            while(!s1.empty() && s1.top()>stk.top()){
                s2.push(s1.top());
                s1.pop();
            }
        }
        s1.push(stk.top());
        stk.pop();
    }
    while(!s2.empty()){
        s1.push(s2.top());
        s2.pop();
    }
    while(!s1.empty()){
        cout<<s1.top()<<" " ;
        s1.pop();
    }
}

//***************************************************************************/
#include<stack>
void sortedInserted(stack<int> &stk,int temp){
    if(stk.empty() || stk.top()<temp){
        stk.push(temp);
    }else{
        int tp = stk.top();
        stk.pop();
        sortedInserted(stk,temp);
        stk.push(tp);
    }
}
void sortStackRec(stack<int> &stk){
    if(!stk.empty()){
        int temp = stk.top();
        stk.pop();
        sortStackRec(stk);
        sortedInserted(stk,temp);
    }
}

void sortStack(stack<int> &stk){
	sortStackRec(stk);
    while(!stk.empty()){
        cout<<stk.top()<<" " ;
        stk.pop();
    }
}

//***************************************************************************/
void deleteMiddle(stack<int>&inputStack, int N){
   // Write your code here
   stack<int> stk;
   int size = 0,mid;
   while(!inputStack.empty()){
       stk.push(inputStack.top());
       size++;
       inputStack.pop();
   }
   mid = size/2;
   size = 0;
   while(!stk.empty()){
       if(mid!=size){
           inputStack.push(stk.top());
       }
       size++;
       stk.pop();
   }
}

//****************************************************************************/

vector<int> maxMinWindow(vector<int> a, int n) {
    // Write your code here.
}
