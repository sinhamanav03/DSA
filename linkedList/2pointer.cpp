#include <bits/stdc++.h>

using namespace std;
//****************************************************************/

// Following is the class structure of the Node class :

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

template <typename T>
class LinkedListNode
{
public:
    T data;
    LinkedListNode<T> *next;
    LinkedListNode(T data)
    {
        this->data = data;
        this->next = NULL;
    }
};

//****************************************************************/
Node *reverse(Node *head)
{
    Node *cur = head, *prev = nullptr;
    while (head != nullptr)
    {
        cur = head->next;
        head->next = prev;
        prev = head;
        head = cur;
    }
    return prev;
}
//****************************************************************/
Node *sum(Node *h1, Node *h2)
{
    Node *list = nullptr, *tail = nullptr;
    h1 = reverse(h1);
    h2 = reverse(h2);
    int carry = 0;
    while (h1 != nullptr && h2 != nullptr)
    {
        int sum = h1->data + h2->data + carry;
        carry = 0;
        if (sum > 9)
        {
            sum = sum % 10;
            carry = 1;
        }
        Node *temp = new Node(sum);

        if (list == nullptr)
        {
            list = tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = tail->next;
        }
        h1 = h1->next;
        h2 = h2->next;
    }

    while (h1 != nullptr)
    {
        int sum = h1->data + carry;
        carry = 0;
        if (sum > 9)
        {
            sum = sum % 10;
            carry = 1;
        }
        Node *temp = new Node(sum);
        if (list == nullptr)
        {
            list = tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = tail->next;
        }
        h1 = h1->next;
    }

    while (h2 != nullptr)
    {
        int sum = h2->data + carry;
        carry = 0;
        if (sum > 9)
        {
            sum = sum % 10;
            carry = 1;
        }
        Node *temp = new Node(sum);
        if (list == nullptr)
        {
            list = tail = nullptr;
        }
        else
        {
            tail->next = temp;
            tail = tail->next;
        }
        h2 = h2->next;
    }

    if (carry == 1)
    {
        Node *temp = new Node(1);
        if (list == nullptr)
        {
            list = tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = tail->next;
        }
    }

    return list;
}

//****************************************************************/
Node *addFirstAndSecondHalf(Node *head)
{
    // Write your code here.
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *temp = head;

    int n = 0;
    while (temp != nullptr)
    {
        n++;
    }
    Node *mid = head, *tail = head, *secondHalf, *prev;
    while (tail != nullptr && tail->next != nullptr)
    {
        prev = mid;
        mid = mid->next;
        tail = tail->next->next;
    }
    if (n % 2 != 0)
    {
        secondHalf = mid;
        prev->next = nullptr;
    }
    else
    {
        secondHalf = mid->next;
        mid->next = nullptr;
    }

    Node *ans = sum(head, secondHalf);
    ans = reverse(ans);

    temp = ans;
    while (temp->next != nullptr)
    {
        if (temp->data == 0)
        {
            ans = ans->next;
        }
        else
        {
            break;
        }
        temp = temp->next;
    }

    return ans;
}
//****************************************************************/
int length(Node *head)
{
    int n = 0;
    while (head != nullptr)
    {
        n++;
        head = head->next;
    }
    return n;
}
//****************************************************************/
Node *deleteMiddle(Node *head)
{
    // Write your code here.
    if (head == nullptr || head->next == nullptr)
    {
        return nullptr;
    }

    int n = length(head);

    Node *mid = head, *tail = head, *prev;

    while (tail != nullptr && tail->next != nullptr)
    {
        prev = mid;
        mid = mid->next;
        tail = tail->next->next;
    }

    if (n % 2 == 0)
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            if (temp->next == prev)
            {
                temp->next = prev->next;
                break;
            }
            temp = temp->next;
        }
    }
    else
    {
        prev->next = mid->next;
    }

    return head;
}
//****************************************************************/
Node *addFirstAndReversedSecondHalf(Node *head)
{
    //  Write your code here.
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    int n = length(head);

    Node *mid = head, *tail = head, *prev;

    while (tail != nullptr && tail->next != nullptr)
    {
        prev = mid;
        mid = mid->next;
        tail = tail->next->next;
    }
    Node *s;
    if (n % 2 == 0)
    {
        s = mid;
        prev->next = nullptr;
    }
    else
    {
        s = mid->next;
        mid->next = nullptr;
    }
    reverse(s);

    Node *ans = sum(head, s);
    ans = reverse(s);
    Node *temp = ans;
    while (temp->next != nullptr)
    {
        if (temp->data == 0)
        {
            ans = ans->next;
        }
        else
        {
            break;
        }
        temp = temp->next;
    }

    return head;
}

LinkedListNode<int> *reverseList(LinkedListNode<int> *head)
{
    LinkedListNode<int> *cur = head, *prev = nullptr;
    while (head != nullptr)
    {
        cur = head->next;
        head->next = prev;
        prev = head;
        head = cur;
    }
    return prev;
}

//****************************************************************/
LinkedListNode<int> *removeKthNode(LinkedListNode<int> *head, int k)
{
    // Write your code here
    head = reverseList(head);
    if (k == 0)
    {
        head = head->next;
    }
    else
    {
        LinkedListNode<int> *temp = head;
        while (temp != nullptr && k != 1)
        {
            temp = temp->next;
            k--;
        }

        temp->next = temp->next->next;
    }
    head = reverseList(head);
}
//****************************************************************/

void detect(Node *head)
{
    //Write your code here and no need to print the linked list
    unordered_set<Node *> s;
    Node *prev = nullptr, *cur = head;

    while(cur!=nullptr && s.find(cur)==s.end()){
        s.insert(cur);
        prev = cur;
        cur = cur->next;
    }
    prev->next = nullptr;
}
//****************************************************************/
//****************************************************************/
//****************************************************************/
//****************************************************************/

int main()
{

    return 0;
}