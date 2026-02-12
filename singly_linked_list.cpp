#include<bits/stdc++.h>
using namespace std;
struct Node{
    public:
    int data;
    Node* next;

    Node(int data,Node* next){
        this->data = data;
        this->next = next;
    }
    Node(int data){
        this->data = data;
    }
};

Node* convertarr2ll(vector<int>&v){
    Node* head = new Node(v[0],nullptr);
    Node* mover = head;
    for(int i = 1;i<v.size();i++){
        Node* temp = new Node(v[i],nullptr);
        mover->next = temp;
        // we can use ant one
        // mover = temp;
        mover = mover->next;
    }
    return head;
}

int lengthll(Node* head){
    Node* temp = head;
    int cnt = 0;
    while(temp){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

bool check_present(Node* head , int val){
    Node* temp = head;
    while(temp){
        if(temp->data == val) return true;
        temp = temp->next;
    }
    return false;
}
int main(){
    vector<int>v ={1,2,3,4,5,6};
    Node* head = convertarr2ll(v);
    cout << head->data;

    cout <<"\n->>>>>>>>>>>>>>>>>>>>>>>>>\n";

    Node* temp = head;
    while(temp){
        cout << temp->data <<" ";
        temp = temp->next;
    }
    cout <<"\n";

    int length = lengthll(head);
    cout <<"\n" << length <<endl;


    cout <<"->>>>>>>>>>>>>>>>>>\n";
    cout <<check_present(head,15);
}
