#include <bits/stdc++.h>

using namespace std;

//*************************************************************

// Following is the LinkedListNode class structure

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode<T> *random;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// *************************************************************/
// ****************************************************************

// Following is the class structure of the Node class:

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// *****************************************************************/
// ****************************************************************

// Following is the class structure of the Node class:

class Node2
{
public:
    char data;
    Node2 *next;
    Node2 *random;
    Node2(char data)
    {
        this->data = data;
        this->next = NULL;
        this->random = NULL;
    }
};

// *****************************************************************/

LinkedListNode<int> *cloneRandomList(LinkedListNode<int> *head)
{
    // Write your code here.
    LinkedListNode<int> *h2 = nullptr, *tail = nullptr, *temp = head;
    while (temp != nullptr)
    {
        LinkedListNode<int> *node = new LinkedListNode<int>(temp->data);
        if (h2 == nullptr)
        {
            h2 = tail = node;
        }
        else
        {
            tail->next = node;
            tail = tail->next;
        }
        temp = temp->next;
    }

    temp = head;
    LinkedListNode<int> *copy1 = h2, *copy2 = h2, *p = head;
    while (temp != nullptr)
    {
        int i = 0;
        while (p != nullptr && p != temp->random)
        {
            i++;
            p = p->next;
        }
        int j = 0;
        while (copy2 != nullptr && j != i)
        {
            j++;
            copy2 = copy2->next;
        }
        copy1->random = copy2;

        copy2 = h2;
        p = head;
        copy1 = copy1->next;
        temp = temp->next;
    }

    return h2;
}

// *************************************************************/

bool isPalindrome(LinkedListNode<int> *head)
{
    // Write your code here.
    if (head == nullptr)
    {
        return true;
    }
    LinkedListNode<int> *mid = head, *tail = head, *prev = nullptr;
    while (tail != nullptr && tail->next != nullptr)
    {
        prev = mid;
        mid = mid->next;
        tail = tail->next->next;
    }
    stack<int> stk;
    // mid = prev;
    //     cout<<mid->data;
    LinkedListNode<int> *temp = head;
    while (temp != mid)
    {
        stk.push(temp->data);
        temp = temp->next;
    }
    if (tail != nullptr)
        temp = temp->next;
    while (temp != nullptr)
    {
        if (temp->data == stk.top())
        {
            stk.pop();
            temp = temp->next;
        }
        else
        {
            return false;
        }
    }

    if (stk.empty())
        return true;

    return false;
}
// *************************************************************/
int findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    vector<Node *> n;
    Node *temp = firstHead;
    while (temp != nullptr)
    {
        n.push_back(temp);
        temp = temp->next;
    }

    temp = secondHead;
    while (temp != nullptr)
    {
        if (find(n.begin(), n.end(), temp) != n.end())
        {
            return temp->data;
        }
        temp = temp->next;
    }
    return -1;
}
// *************************************************************/
bool isItAccepted(Node2 *head, string &str)
{
    Node2 *temp = head;
    if (temp->data != str[0])
    {
        return false;
    }
    int i = 1;
    while (i < str.size())
    {
        if (temp->next != nullptr && temp->next->data == str[i])
        {
            temp = temp->next;
            i++;
        }
        else if (temp->random != nullptr && temp->random->data == str[i])
        {
            temp = temp->random;
            i++;
        }
        else
        {
            break;
        }
    }
    if (i == str.size() && temp->next == nullptr)
        return true;
    else
        return false;
}
// *************************************************************/
void deleteAlternateNodes(Node *head)
{
    //Write your code here
    while (head != nullptr && head->next != nullptr)
    {
        head->next = head->next->next;
        head = head->next;
    }
}
// *************************************************************/
Node *sumBetweenZeroes(Node *head)
{
    //Write ypur code here
    int sum = 0;
    Node *temp = head, *prev;
    while (temp != nullptr)
    {
        if (temp->data == 0)
        {
            if (prev != nullptr)
            {
                prev->data = sum;
                prev->next = temp;
            }
            prev = temp;
            sum = 0;
            if (temp->next == nullptr)
            {
                temp = nullptr;
            }
        }
        else
        {
            sum += temp->data;
        }
        temp = temp->next;
    }
}
// *************************************************************/
Node *segregateOddEven(Node *head)
{
    // Write your code here.
    Node *temp = head, *lastOdd = nullptr, *prev = nullptr;
    while (temp != nullptr)
    {
        if (temp->data % 2 == 1)
        {
            if (temp != head)
            {
                if (lastOdd == nullptr)
                {
                    if (prev != nullptr)
                    {
                        prev->next = temp->next;
                    }
                    else
                    {
                        prev = temp;
                    }
                    temp->next = head;
                    head = temp;
                    lastOdd = head;
                    temp = prev->next;
                }
                else if (lastOdd->next != temp)
                {
                    if (prev != nullptr)
                    {
                        prev->next = temp->next;
                    }
                    else
                    {
                        prev = temp;
                    }
                    temp->next = lastOdd->next;
                    lastOdd->next = temp;
                    lastOdd = temp;
                    temp = prev->next;
                }
                else
                {
                    prev = temp;
                    lastOdd = temp;
                    temp = temp->next;
                }
            }
            else
            {
                prev = temp;
                lastOdd = temp;
                temp = temp->next;
            }
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }
    temp = head;
    //     while(temp!=nullptr){
    //         cout<<temp->data<<" ";
    //         temp = temp->next;
    //     }
    return head;
}
