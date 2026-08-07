#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep) {
    while (node) {
        cout << node->data;

        node = node->next;

        if (node) {
            cout << sep;
        }
    }
}



/*
 * Complete the 'removeKthNodeFromEnd' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts following parameters:
 *  1. INTEGER_SINGLY_LINKED_LIST head
 *  2. INTEGER k
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
int length(SinglyLinkedListNode* head) {
    int l = 0;
    while (head) {
        l++;
        head = head->next;
    }
    return l;
}

SinglyLinkedListNode* removeKthNodeFromEnd(SinglyLinkedListNode* head, int k) {
    if (head == nullptr) return nullptr;

    int n = length(head);
    if (k < 0 || k >= n) {
        return head;
    }

    // Convert to 1-based position from the start
    int pos = n - k;

    if (pos == 1) {                 // remove head
        SinglyLinkedListNode* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    SinglyLinkedListNode* prev = head;
    for (int i = 1; i < pos - 1; i++) {
        prev = prev->next;
    }

    SinglyLinkedListNode* to_delete = prev->next;
    prev->next = to_delete->next;
    free(to_delete);

    return head;
}
int main()
{
    SinglyLinkedList* head = new SinglyLinkedList();

    string head_count_temp;
    getline(cin, head_count_temp);

    int head_count = stoi(ltrim(rtrim(head_count_temp)));

    for (int i = 0; i < head_count; i++) {
        string head_item_temp;
        getline(cin, head_item_temp);

        int head_item = stoi(ltrim(rtrim(head_item_temp)));

        head->insert_node(head_item);
    }

    string k_temp;
    getline(cin, k_temp);

    int k = stoi(ltrim(rtrim(k_temp)));

    SinglyLinkedListNode* result = removeKthNodeFromEnd(head->head, k);

    print_singly_linked_list(result, "\n");
    cout << "\n";

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}
