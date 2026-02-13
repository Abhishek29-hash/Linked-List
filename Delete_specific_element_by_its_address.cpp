#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node* back;

    Node(int data, Node* next, Node* back){
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

void delete_specific(Node* temp){
    Node* prev = temp->back;
    Node* front = temp->next;

    if(front == nullptr){
        prev->next = nullptr;
        temp->back = nullptr;
        free(temp);
        return;
    }
    prev->next = front;
    front->back = prev;
    temp->next = nullptr;
    temp->back = nullptr;
    free(temp);
    return;
}

void print(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data <<" ";
        temp = temp->next;
    }
    cout << endl;
}

int main(){
    vector<int>v = {1,2,3,4,5,6};
    Node* head = convertarr2DLL(v);
    print(head);
  
    delete_specific(head->next);
    print(head);
}
