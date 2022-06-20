// Stack class.
class Stack {
    int sz, topp;
    int *arr;
public:
    
    Stack(int capacity) {
        // Write your code here.
        topp=-1;
        this->sz=capacity;
        arr = new int[sz];
    }

    void push(int num) {
        // Write your code here.
        if(sz - topp != 1) {
            topp++;
            arr[topp] = num;
        }
    }

    int top() {
        // Write your code here.
        if(topp!=-1 && topp<sz) return arr[topp];
        else return -1;
    }
    
    int pop() {
        // Write your code here.
        if(topp!=-1) return arr[topp--];
        else return -1;
    }
    
    int isEmpty() {
        // Write your code here.
        if(topp==-1) return 1; 
        return 0;
    }
    
    int isFull() {
        // Write your code here.
        if(topp>=sz) return 1;
        return 0;
    }
    
};