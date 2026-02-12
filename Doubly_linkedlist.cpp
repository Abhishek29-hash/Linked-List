#include<bits/stdc++.h>
using namespace std;
struct Node{
    public:
    int data;
    Node* next;
    Node* back;

    Node(int data,Node* next, Node* back){
        this->data = data;
        this->next = next;
        this->back = back;
    }

    Node(int data){
        this->data = data;
        next = nullptr;
        back = nullptr;
    }
};

Node* convertarr2DLL(vector<int>&v){
    Node* head = new Node(v[0]);
    Node* prev = head;
    for(int i = 1;i<v.size();i++){
        Node* temp = new Node(v[i],nullptr,prev);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

Node* delete_head(Node* head){
    if(head == nullptr || head->next == nullptr) return NULL;
    Node* prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete prev;
    return head;
}

void print(Node* head){
    while(head){
        cout << head->data <<" ";
        head = head->next;
    }
    cout <<"\n->>>>>>>>>>>>>>>>>>\n";
}

int main(){
    vector<int>v = {1,2,3,4,5,6,7};
    Node* head = convertarr2DLL(v);
    Node* temp = head;

    print(head);

    head = delete_head(head);

    print(head);
}
