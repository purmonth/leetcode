class MyLinkedList {
    struct Node{
        int data;
        Node* next;
        
        Node(int val){
            data = val;
            next = NULL;
        }
    };
    
    Node *head;
    int size;
    
    void printList(){
        auto itt = head;
        while(itt != NULL){
            cout << itt->data << " ";
            itt = itt->next;
        }
        cout << endl;
    }
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        head = NULL;
        size = 0;
    }
    
    MyLinkedList(int val) {
        Node* node = new Node(val);
        head = node;
        size = 1;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        auto itt = head;
        if(index > size)   return -1;
        int currIdx = 0;
        while(itt != NULL){
            if(index == currIdx)    return itt->data;
            currIdx += 1;
            itt = itt->next;
        }
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        Node* node = new Node(val);
        
        if(head == NULL){
            head = node;
            size++;            
            return;
        }
                
        node->next = head;
        head = node;
        size++;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        Node* node = new Node(val);
        
        if(head == NULL){
            head = node;
            size++;
            return;
        }
        
        auto itt = head;
        while(itt->next != NULL){
            itt = itt->next;
        }
        
        itt->next = node;
        size++;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        if(index > size)   return;
        if(index == 0)  {
            addAtHead(val);
            return;
        }
        
        auto itt = head;
        Node* node = new Node(val);
        int currIdx = 1;
        
        while(itt != NULL && currIdx != index){
            currIdx++;
            itt = itt->next;
        }
        
        node->next = itt->next;
        itt->next = node;
        size++;        
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {

        if(index >= size)   return;
        if(index == 0){
            auto temp = head;
            head = head->next;
            delete head;
            size--;
            return;
        }
        
        auto itt = head;
        int currIdx = 1;
        
        while(itt->next != NULL){
            if(index == currIdx){
                auto temp = itt->next;
                itt->next = itt->next->next;
                size--;
                delete temp;
                return;
            }
            currIdx++;
            itt = itt->next;
        }
    }
};


int main(){
    
    return 0;
}
/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */