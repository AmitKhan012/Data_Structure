# include <iostream>
# include <cstdio>
# include <math.h>
using namespace std;

void reheapUp(int heap[], int newnode){
    int parent;
    if(newnode != 0){
        double k = (newnode - 1) / 2;
        parent = floor(k);
        if(heap[newnode] > heap[parent]){
            int tmp = heap[newnode];
            heap[newnode] = heap[parent];
            heap[parent] = tmp;
            reheapUp(heap, parent);
        }
    }
}

int insertHeap(int heap[], int last, int data){
    if(last == 99){
        cout << "Heap is already full" << endl;
        return last;
    }
    last++;
    heap[last] = data;
    reheapUp(heap, last);
    return last;

}

void reheapDown(int heap[], int root, int last){
    int leftkey, rightkey, largekey;
    leftkey = 2 * root + 1;
    rightkey = 2 * root + 2;
    if(leftkey <= last){
        if(rightkey <= last){
            if(heap[leftkey] < heap[rightkey]){
                largekey = rightkey;
            }
            else{
                largekey = leftkey;
            }
        }
        else{
            largekey = leftkey;
        }
        if(heap[root] < heap[largekey]){
            int tmp = heap[root];
            heap[root] = heap[largekey];
            heap[largekey] = tmp;
            reheapDown(heap, largekey, last);
        }
    }
}

int deleteHeap(int heap[], int last){
    if(last == -1){
        cout << "Heap is empty" << endl;
        return -1;
    }
    cout << "Deleting: " << heap[0] << endl;
    heap[0] = heap[last];
    last--;
    reheapDown(heap, 0, last);
    return last;
}

void display(int heap[], int last){
    int i = 0;
    if(last < 0){
        cout << "Heap is empty." << endl;
        return;
    }
    cout << "Heap: ";
    while(i <= last){
        cout << heap[i] << "  ";
        i++;
    }
    cout << endl;
}

int main(){

    int heap[100];
    int last = -1;
    int choice, data;
    while(true){
        cout << "Click 1 for insertion" << endl;
        cout << "Click 2 for delete" << endl;
        cout << "Click 3 for display" << endl;
        cout << "Click 4 for Quit" << endl;
        cout << endl;
        cout << "Enter choise...";
        cin >> choice;
        switch(choice){
            case 1:
                cout << "Enter data...";
                cin >> data;
                last = insertHeap(heap, last, data);
                break;
            case 2:
                last = deleteHeap(heap, last);
                break;
            case 3:
                display(heap, last);
                break;
            case 4:
                return 0;
        }
    }
}
