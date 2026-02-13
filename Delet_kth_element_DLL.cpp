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

void delete_tail(Node* tail){
if(tail == nullptr || tail->back == nullptr) return;
   Node* newtail = tail->back;
   newtail->next = nullptr;
   tail->back = nullptr;
   delete(tail);
}

Node* delete_head(Node* head){
    if(head == nullptr || head->next == nullptr) return nullptr;
    Node* prev = head;
    head = head->next;
    head->back = nullptr;
    prev->next = nullptr;
    delete(prev);
    return head;
}

Node* delete_kth_element(Node* head,int k){
    Node* temp = head;
    while(temp != nullptr && --k){
        temp = temp->next;
    }
    // this bwlow line save us from if we input the out of bound place
    if(temp == nullptr) return head;
    Node* prev = temp->back;
    Node* front = temp->next;

    // if single element is present
    if(prev == nullptr && front == nullptr){
        delete temp;
        return nullptr;
    }
    // if k == 1 means we wants to delete the head
    if(prev == nullptr){
        return delete_head(head);
        
    }
    // if k == size of the vector then we delete the tail
    if(front == nullptr){
        delete_tail(temp);
        return head;
    }
    // to delete the middle one element 
    else{
        prev->next = front;
        front->back = prev;
        temp->next = nullptr;
        temp->back = nullptr;
        delete(temp);
        return head;
    }
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
    cout <<"kth place : ";
    int n; cin >> n;
    head = delete_kth_element(head,n);
    print(head);
}
