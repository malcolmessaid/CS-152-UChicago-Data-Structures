#include<stdio.h>
#include<stdlib.h>
#include "bst.h"
#include "llist.h"
#include "memory.h"

/* malloc a new node and assign the data
 * pointer to its data field
 */
node* node_new(void* data){
	node *new = (node*)malloc(sizeof(node));

	new->data = data;
	new->left = NULL;
	new->right = NULL;
	return new;
}

/* create a new bst, initialize its root to be NULL
 */
bst* bst_new(int (*cmp)(const void* x, const void* y)){
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
	if (b == NULL){
		return;
	}
	inorder_traversal(b->root, func);
}

// a helper function to create linked list from bst by in order traversal
void inorder_traversal_insert_llist(node* root, llist* l){

	if (root == NULL){
		return;
	}


	inorder_traversal_insert_llist(root->left, l);
	insert_tail(l, root->data);
	inorder_traversal_insert_llist(root->right, l);

}



/* an iterator to iterate through the bst in ascending order
 */
void* bst_iterate(bst* b){

	static llist *node = NULL;

	if (b) {
		node = create_llist();
		inorder_traversal_insert_llist(b->root, node);

		return iterate(node);
	}

	if (!node){
		return NULL;
	}
	return iterate(NULL);
}


void node_free(node* n){

  if (n == NULL){
    return;
  }

  node_free(n->left);
  node_free(n->left);
  free(n);

}


/* free all the bst nodes
 */
void bst_free(bst* b){
  if (b->root == NULL){
    return;
  }

  node_free(b->root);
}

/*****************************
 *    HOMEWORK 7
 *****************************/
/*
 * item_or_successor
 *
 * find an item that is equal or, if there isn't one that is
 * equal, find the one that is next larger to the requested
 * item.
 *
 * The purpose of this function is that, given a size of a
 * chunk of memory desired, it attempts to find an available
 * chunk of memory the same size. If there is no chunk of
 * memory the same size, it finds the chunk of memory that is
 * closest to that size but larger.
 *
 * It returns a pointer to the memory struct. The compare
 * function in the bst is the one that performs the comparisons.
 */
void* node_item_or_successor(node *n, void *item,
	int (*cmp)(const void* x, const void* y)) {

		if (n == NULL){
			return NULL;
		}


		if (cmp(item, n->data) == 0) {
			return n->data;
		}

		if (cmp(item, n->data) <= 0) {
			void *left = node_item_or_successor(n->left, item, cmp);
			if (left != NULL){
				return left;
			}
			else {
				return n->data;
			}
		}

		else {
			return node_item_or_successor(n->right, item, cmp);
		}

}



void* bst_item_or_successor(bst *b, void *item){
	return node_item_or_successor(b->root, item, b->cmp);
}
