// #include <iostream>
// using namespace std;
// class Node
// {
//   public:
//     int data;
//     Node *left_child;
//     Node *right_child;
//     Node(int x)
//     {
//         data = x;
//         left_child = NULL;
//         right_child = NULL;
//     }
// };

// class BST
// {
//   public:
//     //Initially root is null
//     Node *root = NULL;

//     void insert(Node *&node, int data)
//     {
//         if (node == NULL)
//         {
//             node = new Node(data);
//             return;
//         }
//         if (data < node->data)
//         {
//             insert(node->left_child, data);
//         }
//         else if (data > node->data)
//         {
//             insert(node->right_child, data);
//         }
//     }
//     void just_insert(int data)
//     {
//         insert(root, data);
//     }
//     void print(Node *node)
//     {
//         if (node == NULL)
//         {
//             return;
//         }
//         cout << node->data << " ";
//         print(node->left_child);
//         print(node->right_child);
//     }
//     void just_print()
//     {
//         print(root);
//     }
// };

// int main()
// { 
//     //For fast IO
//     ios_base::sync_with_stdio(false);
//     cin.tie(NULL);

//     int n, x;
//     cin >> n;
//     BST bst = BST();
    
//     for (int i = 0; i < n; i++)
//     {
//         cin >> x;
//         bst.just_insert(x);
//     }
   
//     bst.just_print();
//     return 0;
// }

#include <iostream>
using namespace std;





struct node_t
{
    int data;
    int lCount;
    node_t *parent;
    node_t *left;
    node_t *right;
};



node_t *insert_node(node_t *root, node_t *node)
{
    /* A crawling pointer */
    node_t *pTraverse = root;
    node_t *currentParent = root;

    // Traverse till appropriate node
    while (pTraverse)
    {
        currentParent = pTraverse;

        if (node->data < pTraverse->data)
        {
            /* We are branching to left subtree 
			increment node count */
            pTraverse->lCount++;
            /* left subtree */
            pTraverse = pTraverse->left;
        }
        else
        {
            /* right subtree */
            pTraverse = pTraverse->right;
        }
    }

    /* If the tree is empty, make it as root node */
    if (!root)
    {
        root = node;
    }
    else if (node->data < currentParent->data)
    {
        /* Insert on left side */
        currentParent->left = node;
        node->parent=currentParent;
    }
    else
    {
        /* Insert on right side */
        currentParent->right = node;
        node->parent=currentParent;
    }

    return root;
}

/* Elements are in an array. The function builds binary tree */
node_t *binary_search_tree(node_t *root, int keys[], int const size)
{
    int iterator;
    node_t *new_node = NULL;

    for (iterator = 0; iterator < size; iterator++)
    {
        new_node = new node_t;

        /* initialize */
        new_node->data = keys[iterator];
        new_node->lCount = 0;
        new_node->left = NULL;
        new_node->right = NULL;
        new_node->parent=NULL;
        
        
        /* insert into BST */
        root = insert_node(root, new_node);
    }

    return root;
}

int k_smallest_element(node_t *root, int k)
{
    int ret = -1;

    if (root)
    {
        /* A crawling pointer */
        node_t *pTraverse = root;

        /* Go to k-th smallest */
        while (pTraverse)
        {
            if ((pTraverse->lCount + 1) == k)
            {
                ret = pTraverse->data;
                break;
            }
            else if (k > pTraverse->lCount)
            {
                /* There are less nodes on left subtree 
					Go to right subtree */
                k = k - (pTraverse->lCount + 1);
                pTraverse = pTraverse->right;
            }
            else
            {
                /* The node is on left subtree */
                pTraverse = pTraverse->left;
            }
        }
    }

    return ret;
}

void whatElement(node_t *root, node_t *el)
{
if(el==NULL){
cout<<"NIE MA TAKIEGO ELEMENTU W DRZEWIE BST!!!!!!!!!"<<endl;
return;}int a=el->data;
    if(root==el){
        cout << "Element " << a << " to " << el->lCount +1<< "-ty element w drzewie" << endl; return;}

    int counter=el->lCount + 1;

    node_t * prev = el->parent;

    while(el->parent!=NULL)
    {   if(prev->left==el)
    {
        el=prev;
        prev=prev->parent;
    }
    
     else if(prev->right==el)
        {   
            el=prev;
            prev=prev->parent;
            counter++;
            counter+=el->lCount;
        }
        else cout<<"ERROR 404!";
    }

cout<<"Element "<<a<<" to "<<counter<<"-ty element w drzewie"<<endl;
}


int main()
{
   const int N = 21;
    int ele[N] = {30,15,10,5,7,12,13,20,19,23,21,50,40,35,45,43,41,60,70,65,67};
    int i;
    node_t *root = NULL;
    

                root = binary_search_tree(root, ele, N);

    whatElement(root, root->left->left->left->left);
    cout << endl;
    for (i = 1; i <=N; i++)
    {
        cout<<" kth smallest elment for k = "<<i<<" is "<< k_smallest_element(root, i)<<endl;
    }

  
    return 0;
}
