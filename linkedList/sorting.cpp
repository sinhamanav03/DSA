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

class NodeRef
{
public:
    Node *data;
    NodeRef *next;

    NodeRef(Node *p)
    {
        this->data = p;
        this->next = nullptr;
    }
};

//*****************************************************************/

void printList(Node *head)
{
    while (head != nullptr)
    {
        cout << head->data << " ->";
        head = head->next;
    }
    cout << "\n";
}

//*****************************************************************/

//*****************************************************************/

int listLength(Node *head)
{
    int c = 0;
    while (head != nullptr)
    {
        c++;
        head = head->next;
    }
    return c;
}
//*****************************************************************/

Node *bubbleSort(Node *head)
{
    Node *temp = head, *temp2;
    bool f1 = 1;
    while (temp->next != nullptr && f1)
    {
        temp2 = head;
        f1 = 0;
        while (temp2->next != nullptr)
        {
            if (temp2->data > temp2->next->data)
            {
                swap(temp2->data, temp2->next->data);
                f1 = 1;
            }
            temp2 = temp2->next;
        }
        temp = temp->next;
    }
    return head;
}
//*****************************************************************/

    Node *merge(Node *h1, Node *h2)
    {
        Node *list = nullptr, *tail = nullptr;

        // printList(h1);
        // cout << endl;
        // printList(h2);
        // cout << endl;

        while (h1 != nullptr && h2 != nullptr)
        {
            if (h1->data < h2->data)
            {
                Node *t = new Node(h1->data);
                if (list == nullptr)
                {
                    list = tail = t;
                }
                else
                {
                    tail->next = t;
                    tail = tail->next;
                }
                h1 = h1->next;
            }
            else
            {
                Node *t = new Node(h2->data);
                if (list == nullptr)
                {
                    list = tail = t;
                }
                else
                {
                    tail->next = t;
                    tail = tail->next;
                }
                h2 = h2->next;
            }
            // printList(list);
            // cout << endl;
        }

        while (h1 != nullptr)
        {
            Node *t = new Node(h1->data);
            tail->next = t;
            tail = tail->next;
            h1 = h1->next;
        }

        while (h2 != nullptr)
        {
            Node *t = new Node(h2->data);
            tail->next = t;
            tail = tail->next;
            h2 = h2->next;
        }

        return list;
    }

//*****************************************************************/

Node *mergeSort(Node *head)
{

    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *mid = head, *tail = head, *prev;
    while (tail != nullptr && tail->next != nullptr)
    {
        prev = mid;
        mid = mid->next;
        tail = tail->next->next;
    }

    prev->next = nullptr;
    // printList(head);
    // cout << endl;
    // printList(mid);
    // cout << endl;

    head = mergeSort(head);
    mid = mergeSort(mid);
    head = merge(head, mid);
    // printList(head);
    // cout << endl;

    return head;
}
//*****************************************************************/

Node *reverseList(Node *head)
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
//*****************************************************************/

Node *getTail(Node *head)
{
    while (head != nullptr && head->next != nullptr)
    {
        head = head->next;
    }

    return head;
}
//*****************************************************************/

Node *partition(Node *head, Node *tail, Node **newHead, Node **newTail)
{
    Node *cur = head, *prev = nullptr, *pivot = tail;

    while (cur != pivot)
    {
        if (cur->data < pivot->data)
        {
            if (*newHead == nullptr)
            {
                *newHead = cur;
            }
            prev = cur;
            cur = cur->next;
        }
        else
        {
            if (prev != nullptr)
            {
                prev->next = cur->next;
            }
            Node *temp = cur->next;
            cur->next = nullptr;
            tail->next = cur;
            tail = cur;
            cur = temp;
        }
    }

    if (*newHead == nullptr)
    {
        *newHead = pivot;
    }

    *newTail = tail;

    return pivot;
}

//*****************************************************************/
Node *quickSortHelper(Node *head, Node *tail)
{
    if (head == nullptr || head == tail)
    {
        return head;
    }
    Node *newHead = nullptr, *newTail = nullptr, *pivot = nullptr;

    pivot = partition(head, tail, &newHead, &newTail);

    if (pivot != newHead)
    {
        Node *temp = newHead;
        while (temp->next != pivot)
        {
            temp = temp->next;
        }
        temp->next = nullptr;

        newHead = quickSortHelper(newHead, temp);

        temp = getTail(newHead);

        temp->next = pivot;
    }

    pivot->next = quickSortHelper(pivot->next, newTail);

    return newHead;
}
//*****************************************************************/
Node *quickSortLL(Node *head)
{

    Node *tail = getTail(head);
    head = quickSortHelper(head, tail);
    return head;
}
//*****************************************************************/
Node *insertionSortLL(Node *head)
{
    // Write your code here.
    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }
    Node *tail = head->next, *newHead = head;

    while (tail != nullptr)
    {
        Node *temp = newHead, *prev = nullptr;

        while (temp != tail && temp->data <= tail->data)
        {
            prev = temp;
            temp = temp->next;
        }

        if (temp == tail)
        {
            tail = tail->next;
            continue;
        }

        Node *q = newHead;
        while (q->next != tail)
        {
            q = q->next;
        }
        if (prev != nullptr)
        {
            prev->next = tail;
            q->next = tail->next;
            tail->next = temp;
            tail = q;
        }
        else
        {
            q->next = tail->next;
            tail->next = temp;
            newHead = tail;
            tail = q;
        }
        // printList(newHead);
        tail = tail->next;
    }
    return newHead;
}
//*****************************************************************/

Node *sortLL(Node *head)
{
    // Write your code here.

    if (head == nullptr || head->next == nullptr)
    {
        return head;
    }

    Node *temp = head->next, *prev = head;

    while (temp != nullptr)
    {
        if (temp->data < 0)
        {
            Node *q = temp->next;
            temp->next = head;
            head = temp;
            if (prev != nullptr)
            {
                prev->next = q;
            }
            temp = q;
        }
        else
        {
            prev = temp;
            temp = temp->next;
        }
    }

    return head;
}

//*****************************************************************/
Node *sortList(Node *head)
{
    // Write your code here.
    if (head == nullptr || head->next == nullptr)
        return head;
    Node *tp = head, *prev = head;
    int c[3] = {0, 0, 0};
    while (tp != nullptr)
    {
        c[tp->data]++;
        tp = tp->next;
    }
    int i = 0;
    while (prev != nullptr)
    {   
        while (i<3 && c[i] == 0)
        {
            i++;
        }
        if (i == 3)
            break;
        c[i]--;
        prev->data = i;
        prev = prev->next;
    }
    return head;
}
//*****************************************************************/

long long int mergeHelper(Node *h1, Node *h2 ,Node **list)
{
    Node *tail = nullptr;

    // printList(h1);
    // cout << endl;
    // printList(h2);
    // cout << endl;
    long long int ans = 0;
    long long int i = 0, j = 0;
    while (h1 != nullptr && h2 != nullptr)
    {
        if (h1->data < h2->data)
        {
            Node *t = new Node(h1->data);
            if ((*list) == nullptr)
            {
                (*list) = tail = t;
            }
            else
            {
                tail->next = t;
                tail = tail->next;
            }
            h1 = h1->next;
            i++;
            ans += j;
        }
        else
        {
            Node *t = new Node(h2->data);
            if (list == nullptr)
            {
                list = tail = t;
            }
            else
            {
                tail->next = t;
                tail = tail->next;
            }
            h2 = h2->next;
            j++;
        }
        // printList(list);
        // cout << endl;
    }

    while (h1 != nullptr)
    {
        Node *t = new Node(h1->data);
        tail->next = t;
        tail = tail->next;
        h1 = h1->next;
        i++;
        ans += j;
    }

    while (h2 != nullptr)
    {
        Node *t = new Node(h2->data);
        tail->next = t;
        tail = tail->next;
        h2 = h2->next;
        j++;
    }

    return ans;
}

//*****************************************************************/
long long int calculateInversionCnt(Node *head)
{
    // Write your code here.
    if (head == nullptr || head->next == nullptr)
    {
        return 0;
    }

    Node *mid = head, *tail = head, *prev;
    while (tail != nullptr && tail->next != nullptr)
    {
        prev = mid;
        mid = mid->next;
        tail = tail->next->next;
    }

    prev->next = nullptr;

    long long int n1, n2,n3;
    n1 = calculateInversionCnt(head);
    n2 = calculateInversionCnt(mid);
    n3 = mergeHelper(head, mid,&head);
    return n1 + n2 + n3;
}
//*****************************************************************/

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int x;
        Node *head = nullptr, *tail = nullptr;
        while (true)
        {
            cin >> x;
            if (x == -1)
                break;

            Node *temp = new Node(x);

            if (head == nullptr)
            {
                head = tail = temp;
            }
            else
            {
                tail->next = temp;
                tail = tail->next;
            }
        }
        head = sortList(head);
        printList(head);
        cout << "\n";
    }

    return 0;
}
