#include<stdio.h>
#include<stdlib.h>
#include "bst.h"
#include "memory.h"

/* malloc a new node and assign the data
 * pointer to its data field
 */
node* node_new(void* data){
  //TODO
  node *new = (node*)malloc(sizeof(node));

  new->data = data;
  new->left = NULL;
  new->right = NULL;
  return new;
}

/* create a new bst, initialize its root to be NULL
 */
bst* bst_new(int (*cmp)(const void* x, const void* y)){
  //TODO
  bst* new = (bst*)malloc(sizeof(bst));

  new->root = NULL;
  new->cmp = cmp;

  return new;
}


/* Insert a node to to a subtree with a root node as parameter
 * Insertion is in sorted order.
 * Return the new root of the modified subtree.
 */
node* node_insert(node* root, void* data,
    int (*cmp)(const void* x, const void* y)){
  //TODO
  if (root == NULL){
    return node_new(data);
  }
  else {
    if (cmp(data, root->data) < 0){
      root->left = node_insert(root->left, data, cmp);
    }
    else {
      root->right = node_insert(root->right, data, cmp);
    }
    return root;
  }
  return NULL;
}

/* Insert a new node to the bst
 */
void bst_insert(bst* b, void* data){
  b->root = node_insert(b->root, data, b->cmp);
}

/* delete a node from a subtree with a given root node
 * use the comparison function to search the node and delete
 * it when a matching node is found. This function only
 * deletes the first occurrence of the node, i.e, if multiple
 * nodes contain the data we are looking for, only the first node
 * we found is deleted.
 * Return the new root node after deletion.
 */
node* node_delete(node* root, void* data,
    int (*cmp)(const void* x, const void* y)){

  if (root == NULL){
    return NULL;
  }

  if (cmp(root, data) == -1){
    return node_delete(root->left, data, cmp);
  }

  else if (cmp(root, data) == 1){
    return node_delete(root->right, data, cmp);
  }

  else {
    if (root->right == NULL){
      node* temp = root->left;
      free(root);
      return temp;
    }
    else if (root->left == NULL){
      node* temp = root->right;
      free(root);
      return temp;
    }
    else if (cmp(root->left, root->right) < 1){
      node* temp = root->right;
      root->data = temp->data;
      root->right = node_delete(root->right, temp, cmp);
      return temp;
    }
    else {
      node* temp = root->left;
      root->data = temp->data;
      root->left = node_delete(root->left, temp, cmp);
      return temp;
    }
  }

  return NULL;
}

/* delete a node containing data from the bst
 */
void bst_delete(bst* b, void* data){
  //TODO
  node_delete(b->root, data, b->cmp);
}

/* Search for a node containing data in a subtree with
 * a given root node. Use recursion to search that node.
 * Return the first occurrence of node.
 */
void* node_search(node* root, void* data,
    int (*cmp)(const void* x, const void* y)){

  if (root->data == NULL) {
    return NULL;
  }

  else {
    if (cmp(data, root->data) == 0) {
      return root->data;
    }
    else {
      if (cmp(data, root->data) == -1){
        return(node_search(root->left, data, cmp));
      }
      else if (cmp(data, root->data) == 1){
        return(node_search(root->right, data, cmp));
      }
      else {
        return NULL;
      }
    }
  }
  return NULL;
}

/* Search a node with data in a bst.
 */
void* bst_search(bst* b, void* data){

  if (b->root == NULL) {
    return NULL;
  }

  return node_search(b->root, data, b->cmp);

}

/* traverse a subtree with root in ascending order.
 * Apply func to the data of each node.
 */
void inorder_traversal(node* root, void(*func)(void* data)){
  //TODO
  if (root == NULL){
    return;
  }

  inorder_traversal(root->left, func);
  func(root->data);
  inorder_traversal(root->right, func);

}

/* traverse a bst in ascending order.
 * Apply func to the data of each node.
 */
void bst_inorder_traversal(bst* b, void(*func)(void* data)){
  //TODO
  if (b == NULL){
    return;
  }
  inorder_traversal(b->root, func);
}

void node_free(node* n){

  if (n == NULL){
    return;
  }

  node_free(n->left);
  node_free(n->left);
  free(n);

}
/* free the bst with
 */
void bst_free(bst* b){

  if (b->root == NULL){
    return;
  }

  node_free(b->root);

}
