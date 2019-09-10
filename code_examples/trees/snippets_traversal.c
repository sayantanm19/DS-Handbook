void postorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
  
    postorder(node->left); 
    postorder(node->right); 
    cout << node->data << " "; 
} 

void inorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
  
    inorder(node->left); 
    cout << node->data << " "; 
    inorder(node->right); 
} 
  
void preorder(struct Node* node) 
{ 
    if (node == NULL) 
        return; 
  
    cout << node->data << " "; 
    preorder(node->left);  
    preorder(node->right); 
}  