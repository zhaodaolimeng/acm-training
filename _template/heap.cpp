#include <iostream>

using namespace std;

int min_heap[100];
int tail = 0; // 指向最后一个元素之后

void print_heap(){
    for(int i=0; i<tail; i++)
        cout<<min_heap[i]<<' ';
    cout<<endl;
}

void build(int arr[], int n){
    // 扫描所有偶数对
    for(int i=0; i<n; i++) min_heap[i] = arr[i];
    tail = n;
    for(int p=tail-1; p>0; p--){
        if(min_heap[p] < min_heap[(p - 1)/2])
            swap(min_heap[p], min_heap[(p - 1)/2]);
    }
}

void swap(int& a, int& b){
    int t = a;
    a = b;
    b = t;
}

void insert(int e){
    min_heap[tail] = e;
    tail ++;
    // 向上扫描
    for(int p=tail-1; p>0;){
        if(min_heap[p] < min_heap[(p - 1)/2])
            swap(min_heap[p], min_heap[(p - 1)/2]);
        p = (p - 1)/2;
    }
}

int pop(){
    // 弹出之后，将最后一个元素放到第一个
    int ret = min_heap[0];
    min_heap[0] = min_heap[tail - 1];
    tail --;
    // 向下扫描
    int l, r;
    for(int p=0; p<tail;){
        l = p*2 + 1, r= p*2 + 2;
        if(min_heap[l] > min_heap[r]){
            if(r < tail) swap(min_heap[r], min_heap[p]);
            p = r;
        }else{
            if(l < tail) swap(min_heap[l], min_heap[p]);
            p = l;
        }
    }
    return ret;
}

int main(){

    int arr[10] = {3, 6, 7, 2, 1, 0, 9 ,8 ,4 ,5};
    int n = 10;
    build(arr, n);
    cout<<"====="<<endl;
    print_heap();
    cout<<"pop = "<<pop()<<endl;
    cout<<"====="<<endl;
    print_heap();
    insert(10);
    print_heap();
    insert(-1);
    print_heap();
}