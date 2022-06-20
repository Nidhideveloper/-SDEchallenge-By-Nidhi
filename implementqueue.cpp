class Queue {
    int* arr;
    int qfront, rear, sz;
public:
    Queue() {
        // Implement the Constructor
        sz=100001;
        arr = new int[sz];
        qfront =0; rear=0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        if(qfront==rear) return true;
        else return false;
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(rear==sz) cout<<"Q full";
        else{
            arr[rear]=data;
            rear++;
        }
    }

    int dequeue() {
        // Implement the dequeue() function
        if(rear==qfront) return -1;
        else{
            int res = arr[qfront];
            arr[qfront]=-1;
            qfront++;
            if(qfront==rear){
                qfront=0;
                rear = 0;
            }
            return res;
        }
    }

    int front() {
        // Implement the front() function
        if(qfront==rear) return -1;
        else return arr[qfront];
    }
};