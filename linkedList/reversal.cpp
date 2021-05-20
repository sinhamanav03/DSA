#include <bits/stdc++.h>

using namespace std;

//****************************************************************/

// Following is the class structure of the Node<int> class :

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        next = NULL;
        this->data = data;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

//*****************************************************************/

void printList(Node<int> *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ->";
        head = head->next;
    }
}

//*****************************************************************/

Node<int> *reverseListRecursive(Node<int> *head)
{
    if (head == nullptr || head->next == nullptr)
        return head;

    Node<int> *rest = reverseListRecursive(head->next);

    head->next->next = head;

    head->next = nullptr;

    return rest;
}

//*****************************************************************/

Node<int> *reverseListIterative(Node<int> *head)
{
    Node<int> *curr = head, *prev = nullptr;
    while (curr != nullptr)
    {
        curr = head->next;
        head->next = prev;
        prev = head;
        head = curr;
    }
    return prev;
}

//*****************************************************************/

Node<int> *getListAfterReverseOperation(Node<int> *head, int n, int b[])
{
    int visitedNode<int> = 0;
    Node<int> *front = nullptr;
    Node<int> *temp = head;
    for (int i = 0; i < n; ++i)
    {
        int count = 0;
        // while (temp!=nullptr && count < visitedNode<int>)
        // {
        //     front = temp;
        //     temp = temp->next;
        //     count++;
        // }
        if (temp == nullptr)
        {
            break;
        }
        if (b[i] == 0)
        {
            continue;
        }
        count = 0;
        Node<int> *cur = temp, *prev = nullptr;
        while (temp != nullptr && count < b[i])
        {
            count++;
            cur = cur->next;
            temp->next = prev;
            prev = temp;
            temp = cur;
        }
        visitedNode<int> += count;
        if (front != nullptr)
        {
            front->next = prev;
        }
        else
        {
            head = prev;
        }
        while (prev->next != nullptr)
        {
            prev = prev->next;
        }
        front = prev;
        prev->next = cur;
        if (cur == nullptr)
        {
            break;
        }
    }
    return head;
}

//*****************************************************************/

Node<int> *lastAppearance(Node<int> *head)
{
    // Write your code here.
    if (head == nullptr)
    {
        return head;
    }
    unordered_set<int> f;
    Node<int> *prev = nullptr, *cur = head;
    while (head != nullptr)
    {
        cur = head->next;
        head->next = prev;
        prev = head;
        head = cur;
    }
    head = prev;
    cur = head;
    f.insert(head->data);
    while (cur->next != nullptr)
    {
        if (f.find(cur->next->data) == f.end())
        {
            cur = cur->next;
            f.insert(cur->data);
        }
        else
        {
            cur->next = cur->next->next;
        }
    }
    prev = nullptr, cur = head;
    while (head != nullptr)
    {
        cur = head->next;
        head->next = prev;
        prev = head;
        head = cur;
    }
    return prev;
}

//*****************************************************************/

Node<int> *removeDuplicates(Node<int> *head)
{
    int maxV = 0;
    Node<int> *temp = head;
    while (temp != nullptr)
    {
        maxV = max(maxV, abs(temp->data));
        temp = temp->next;
    }
    Node<int> *prev = nullptr, *cur = head;
    // while (head != nullptr)
    // {
    //     cur = head->next;
    //     head->next = prev;
    //     prev = head;
    //     head = cur;
    // }
    // head = prev;
    cur = head;
    vector<bool> f(maxV + 1, 0);
    // vector<bool> f2(1000000001, 0);
    while (cur != nullptr && cur->data < 0)
    {
        cur = cur->next;
    }

    if (cur != nullptr)
    {
        f[cur->data] = 1;
        while (cur->next != nullptr)
        {
            if (cur->next->data < 0)
            {
                cur = cur->next;
            }
            else if (!f[cur->next->data])
            {
                cur = cur->next;
                f[cur->data] = 1;
            }
            else
            {
                cur->next = cur->next->next;
            }
        }
    }

    f = vector<bool>(maxV + 1, 0);

    cur = head;
    while (cur != nullptr && cur->data >= 0)
    {
        cur = cur->next;
    }
    if (cur != nullptr)
    {
        f[cur->data] = 1;
        while (cur->next != nullptr)
        {
            if (cur->next->data >= 0)
            {
                cur = cur->next;
            }
            else if (!f[abs(cur->next->data)])
            {
                cur = cur->next;
                f[abs(cur->data)] = 1;
            }
            else
            {
                cur->next = cur->next->next;
            }
        }
    }
    // prev = nullptr, cur = head;
    // while (head != nullptr)
    // {
    //     cur = head->next;
    //     head->next = prev;
    //     prev = head;
    //     head = cur;
    // }
    return head;
}
//*****************************************************************/

Node<int> *addTwoLists(Node<int> *first, Node<int> *second)
{
    // Write your code here
    Node<int> *ans = nullptr, *tail = nullptr;
    first = reverseListIterative(first);
    second = reverseListIterative(second);
    int carry = 0;
    while (first != nullptr && second != nullptr)
    {
        int sum = first->data + second->data + carry;
        carry = 0;
        if (sum > 9)
        {
            sum = sum % 10;
            carry = 1;
        }
        Node<int> *temp = new Node(sum);
        if (ans == nullptr)
        {
            ans = tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = tail->next;
        }
    }
    while (first != nullptr)
    {
        int sum = first->data + carry;
        carry = 0;
        if (sum > 9)
        {
            sum = sum % 10;
            carry = 1;
        }
        Node<int> *temp = new Node(sum);
        if (ans == nullptr)
        {
            ans = tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = tail->next;
        }
        first = first->next;
    }
    while (second != nullptr)
    {
        int sum = second->data + carry;
        carry = 0;
        if (sum > 9)
        {
            sum = sum % 10;
            carry = 1;
        }
        Node<int> *temp = new Node(sum);
        if (ans == nullptr)
        {
            ans = tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = tail->next;
        }
        second = second->next;
    }

    if (carry)
    {
        Node<int> *temp = new Node<int>(1);
        tail->next = temp;
    }

    ans = reverseListIterative(ans);
    return ans;
}

//*****************************************************************/

Node *getListAfterDeleteOperation(Node *head)
{
    //	Write your code here
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *temp = head;
    int mx = head->data;
    while (temp->next != nullptr)
    {
        int z = temp->next - data;
        if (temp->next->data >= mx)
        {
            temp = temp->next;
        }
        else
        {
            temp->next = temp->next->next;
        }
        mx = z;
    }
    return head;
}

//*****************************************************************/
Node<int> *rearrangeList(Node<int> *head)
{
    //Write your code here
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node<int> *rev = nullptr, *temp = head, *tail = nullptr;
    // Node *newHead = nullptr;

    while (temp != nullptr)
    {
        Node<int> *t = new Node<int>(temp->data);
        if (rev == nullptr)
        {
            rev = tail = t;
        }
        else
        {
            tail->next = t;
            tail = tail->next;
        }
        temp = temp->next;
    }

    rev = reverseListIterative(rev);

    int c = 0;
    temp = head;
    while (temp != nullptr)
    {
        c++;
        temp = temp->next;
    }
    Node<int> *ans = nullptr;

    tail = nullptr;
    int i = 0;
    temp = head;
    while (temp != nullptr && rev != nullptr && i < c / 2)
    {
        Node<int> *t = new Node<int>(temp->data);
        if (ans == nullptr)
        {
            ans = tail = t;
        }
        else
        {
            tail->next = t;
            tail = tail->next;
        }
        Node<int> *v = new Node<int>(rev->data);

        tail->next = v;
        tail = tail->next;
        i++;
        rev = rev->next;
        temp = temp->next;
    }
    Node<int> *t = new Node<int>(temp->data);

    tail->next = t;
    tail = tail->next;

    if (c % 2 == 0)
    {
        Node<int> *t = new Node<int>(rev->data);

        tail->next = t;
        tail = tail->next;
    }
    tail->next = nullptr;

    return ans;
}
//*****************************************************************/
int main()
{

    // Node<int> *head = nullptr, *tail = nullptr;
    // int n;
    // while (true)
    // {
    //     cin >> n;
    //     if (n == -1)
    //     {
    //         tail->next = nullptr;
    //         break;
    //     }
    //     Node<int> *q;
    //     q->data = n;
    //     q->next = nullptr;
    //     if (head == nullptr)
    //     {
    //         head = q;
    //         tail = q;
    //     }
    //     else
    //     {
    //         tail->next = q;
    //         tail = tail->next;
    //     }
    // }
    // // cin >> n;
    // // vector<int> b(n+1);
    // // for (int i = 0; i < n;++i){
    // //     cin >> b[i];
    // // }
    // cout << head->data;
    // printList(head);

    // head = getListAfterReverseOperation(head, n, b);
    // printList(head);
    return 0;
}