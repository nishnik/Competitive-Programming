#include <stdio.h>
#include <string.h>
#include <string>
#include <vector>
#include <iostream>
#include <malloc.h>
#define ALPHABET_SIZE 10
 
using namespace std;

struct node {
    int data;
    struct node* link[ALPHABET_SIZE];
};
 

 
struct node*  create_node() {
    struct node *q = (struct node*)malloc(sizeof(struct node));
    for(int x=0;x<ALPHABET_SIZE;x++)
        q->link[x] = NULL;
    q->data = -1;
    return q;
}
 
// Look at this function like this: (Comparing it with LinkedList traversal for adding a node at the end of the list)
// Keep traversing, (q = q->link[index] instead of q = q->link) until we get q->link[index] == NULL (instead of q->link == NULL)
// When we get NULL, then instead of adding just 1 node and making the previous node point to it, we create as many new nodes
// as the value of (length - level) at that time.
int insert_node(char key[],struct node* root) {
    int length = strlen(key);
    int index;
    int level = 0;
    if(root == NULL)
        root = create_node();
    struct node *q = root;  // For insertion of each String key, we will start from the root
 
    for(;level < length;level++) {
        // At each level, find the index of the corresponding 
        // character (a-z = 0-26)
        index = key[level] - '0';
 
        if(q->link[index] == NULL) {
            // Put the value of this character inside q->link[index]
            // and create 1 more node to which this node will point
            q->link[index] = create_node();  // which is : struct node *p = create_node(); q->link[index] = p;
        }
 
        q = q->link[index];
    }
    // Now, the last character(node) of the String key will contain the value of this key
    if(q->data!=-1)
        return 0;
    q->data = level;
    return 1; // Assuming the value of this particular String key is 11      
}
 
/*int search(char key[]) {
    struct node *q = root;
    int length = strlen(key);
    int level = 0;
    for(;level < length;level++) {
        int index = key&#91;level&#93; - 'a';
        if(q->link[index] != NULL)
            q = q->link[index];
        else
            break;
    }
    if(key[level] == '\0' && q->data != -1)
        return q->data;
    return -1;
}*/
 
int main() {
    ios::sync_with_stdio(false);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        int flag=1;
        cin>>n;
        struct node* root = NULL;
        
        for(int i=0;i<n;i++)
        {
            char v[10];
            cin>>v;
            cout<<v;
            if(flag==1)
                insert_node(v,root);
        }
        
        
        if(flag==0)
            cout<<"NO\n";
        else
            cout<<"YES\n";
        //free(t);

    }       
}