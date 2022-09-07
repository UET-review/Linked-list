#include <iostream>
#include <fstream>

using namespace std;

struct LinkedList{
    int data;
    LinkedList* next;
};

LinkedList* initialization(LinkedList* head){
    head = NULL;
    return head;
}

LinkedList* create_node(int value){
    LinkedList *node = new LinkedList;
    node->data = value;
    node->next = NULL;
    return node;
}

bool isEmpty(LinkedList *head){
    if (head == NULL) return true;
    return false;
}

LinkedList* insertion(LinkedList *head,int value, int k){
    // create node
    LinkedList* node = create_node(value);
    LinkedList* P = head;
    LinkedList* preP;
    // Insert to first position
    if (k==1){
        node->next = head;
        return node;
    }
    
    if (isEmpty(head)) {
        cout << "Linked list empty" << endl;
        return head;
    }
    // Insert to any position
    for(int i = 1; i < k; i++){
        preP = P;
        P = P->next;
        if (P == NULL && i != k-1){
            cout << k << " not int linked list" << endl;
            return head;
        } 
    }
    preP->next = node;
    node->next = P;
    return head;
}

LinkedList* remove(LinkedList *head, int k){
    if (isEmpty(head)) {
        cout << "Linked list is empty -> Not remove" << endl;
        return head;
    }
    if (k == 1){
        head = head->next;
        return head;
    }
    LinkedList* P = head;
    LinkedList* preP;
    for(int i= 1; i < k; i++){
        preP = P;
        P = P->next;
        if (P == NULL && i != k-1){
            cout << k << " position not in linked list" << endl;
            return head;
        }
    }
    if (P == NULL) preP->next = NULL;
    else preP->next = P->next;
    return head;
}

void print(LinkedList* head){
    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next; 
    }
    cout << endl;
}

int main(){
    LinkedList * head;
    head = initialization(head);
    ifstream infile("input.txt");
    int n, value;
    infile >> n;
    for(int k = 1; k <= n; k++){
        infile >> value;
        head = insertion(head, value, k);
    }
    print(head);
    cout << "Remove node 3" << endl;
    head = remove(head, 3);
    print(head);
    infile.close();
    cout << endl;
    return 0;
}