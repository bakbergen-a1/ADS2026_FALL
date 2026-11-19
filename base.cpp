#include <iostream>
#include <vector>
using namespace std;
//prime number

/*bool isprime(int n){
    if(2>n) return false;
    for(int i=2;i*i<=n;++i){
        if(n%i==0) return false;
    }
    return true;
}
int main() {
    int n;
    cin>>n;
    if(isprime(n)) cout<<"Yes";
    else cout<<"No";
}*/
/*bool isprime(int n){
    if(2>n) return false;
    for(int i=2;i*i<=n;++i){
        if(n%i==0) return false;
    }
    return true;
}
int main() {
    vector<int> a={2,3,5};
    int k;
    cin>>k;
    if(a.size()>=k) cout<<a[k-1];
    else{
        int s=6;
        while(a.size()<k){
            if(isprime(s)) a.push_back(s);
            s++;
        }
        cout<<a[k-1];
    }
}*/

//gcd and lcm
/*int main() {
    int a,b;
    cin>>a>>b;
    int x=a,y=b;
    while(b!=0){
        int s=a%b;
        a=b;
        b=s;
    }
    int gcd=a;
    int lcm=(x/gcd)*y;
    cout<<gcd<<" "<<lcm;
}*/

//devisers of number
/*int main() {
    int n;
    cin>>n;
    vector<int> a;
    int s=0;
    int k=2;
    while(k*k<=n){
        while(n%k==0) {
            a.push_back(k);
            n=n/k;
        }
        k++;
        s++;
    }
    if(n>1) {
        a.push_back(n);
        s++;
    }
    cout<<s<<endl;
    for(int x:a) cout<<x<<" ";
}*/



//binary search
/*bool search(vector<int>&a,int n,int x){
    int l=0,r=n-1;
    while(l<=r){
        int m=l+(r-l)/2;
        if(a[m]==x) return true;
        else if(a[m]<x) l=m+1;
        else r=m-1;
    }
    return false;
}
int lowerbound(vector<int>&a,int n,int x){
    int l=0,r=n;
    while(l<r){
        int m=l+(r-l)/2;
        if(a[m]>=x) r=m;
        else l=m+1;
    }
    return l;
}
int upperbound(vector<int> &a,int n,int x){
    int l=0,r=n;
    while(l<r){
        int m=l+(r-l)/2;
        if(a[m]>x) r=m;
        else l=m+1;
    }
    return l;
}

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    int x;
    cin>>x;
    if(search(a,n,x)) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    cout<<lowerbound(a,n,x)<<" "<<upperbound(a,n,x);
}*/



//bst
/*struct Node{
    int v;
    Node*l,*r;
    Node(int x): v(x),l(0),r(0){};
};
void insert(Node*&root,int x){
    if(!root) {
        root=new Node(x);
        return;
    }
    if(root->v>x) insert(root->l,x);
    else insert(root->r,x);
}
int size(Node*&root){
    if(!root) return 0;
    return 1+size(root->l)+size(root->r);
}
void show(Node*&root){
    if(!root) return;
    show(root->l);
    cout<<root->v<<" ";
    show(root->r);
}
int main() {
    int n;
    cin>>n;
    Node*root=0;
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        insert(root,x);
    }
    cout<<size(root)<<endl;
    show(root);
}*/



//linked list
/*struct Node{
    int data;
    Node*next;
};
int main() {
    int n;
    cin>>n;
    Node*tail=0;
    Node*head=0;
    for(int i=0;i<n;++i){
        int x;
        cin>>x;
        Node*p=new Node;
        p->data=x;
        p->next=0;
        if(head==0){
            head=p;
            tail=p;
        }else{
            tail->next=p;
            tail=p;
        }
    }*/
    /*Node*next=0;
    Node*prev=0;
    Node*cur=head;
    while(cur!=0){
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    head=tail;
    Node*current=head;
    while(current!=0){
        cout<<current->data<<" ";
        current=current->next;
    }*/

    //odd position
    /*Node*current=head;
    while(current!=0){
        cout<<current->data<<" ";
        current=current->next;
        if(current!=0) current=current->next;
    }*/

    //odd numbers
    /*Node*current=head;
    while(current!=0){
        if(current->data%2!=0) cout<<current->data<<" ";
        current=current->next;
    }*/

    //even position
    /*Node*current=head;
    if(current->next!=0) current=current->next;
    while(current!=0){
        cout<<current->data<<" ";
        current=current->next;
        if(current!=0) current=current->next;
    }*/

    //evem numbers
    /*Node*current=head;
    while(current!=0){
        if(current->data%2==0) cout<<current->data<<" ";
        current=current->next;
    }*/
    /*int x;
    cin>>x;
    Node**p=&head;
    while(*p!=0){
        if((*p)->data==x) {
            Node*t=*p;
            *p=t->next;
            delete t;
        }else{
            p=&((*p)->next);
        }
    }
    Node*current=head;
    while(current!=0){
        cout<<current->data<<" ";
        current=current->next;
    }*/
//}



//heap sort
/*struct Heap{
    long long *a;
    int n;

    Heap(int size){
        a=new long long[size];
        n=0;
    }
    void push(long long x){
        int i=n;
        a[n]=x;
        n++;
        while(i>0){
            int p=(i-1)/2;
             if(a[p]<=a[i]) break;
             swap(a[i],a[p]);
             i=p;
        }
    }
    void heapify(int i){
        while(2*i+1<n){
            int c=2*i+1;
            if(c+1<n && a[c+1]<a[n]) c++;
            if(a[i]<=a[c]);
            swap(a[i],a[c]);
            i=c;
        }
    }
    long long pop(){
        long long x=a[0];
        a[0]=a[n-1];
        n--;
        if(n>0) heapify(0);
        return x;
    }
};
int main() {
    int n;
    cin>>n;
    Heap h(n);
    for(int i=0;i<n;++i){
        long long x;
        cin>>x;
        h.push(x);
    }
}*/



//quick sort
/*void qs(vector<int> &a,int l,int r){
    int i=l,j=r;
    int p=a[(l+r)/2];
    while(i<=j){
        while(a[i]<p) i++;
        while(a[j]>p) j--;
        if(i<=j) swap(a[i++],a[j--]); 
    }
    if(l<j) qs(a,l,j);
    if(i<r) qs(a,r,i);
}
int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    qs(a,0,n-1);
    for(int i=0;i<n;++i) cout<<a[i]<<" ";
}*/



//merge sort
/*void merge(vector<int> &a,int l,int m,int r){
    vector<int> L,R;
    int i=0,j=0,k=l;
    for(int i=l;i<=m;i++) L.push_back(a[i]);
    for(int i=m+1;i<=r;i++) R.push_back(a[i]);
    while(i<L.size() && j<R.size()){
        if(L[i]<=R[j]) a[k++]=L[i++];
        else a[k++]=R[j++];
    }
    while(i<L.size()) a[k++]=L[i++];
    while(j<R.size()) a[k++]=R[j++];
}
void ms(vector<int> &a,int l,int r){
    if(l<r){
        int m=l+(r-l)/2;
        ms(a,l,m);
        ms(a,m+1,r);
        merge(a,l,m,r);
    }
}
int main() {
    int n;
    cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;++i) cin>>a[i];
    ms(a,0,n-1);
    for(int i=0;i<n;++i) cout<<a[i]<<" ";
}*/