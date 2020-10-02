#include <iostream>
using namespace std;

struct Node {
  int index;
  struct Node *lt, *rt;
};

// Create a Node
struct Node *newNode(int item) {
  struct Node *t = (struct Node *)malloc(sizeof(struct Node));
  t->index = item;
  t->lt = t->rt = NULL;
  return t;
}

// Inorder Traversal
void inorder(struct Node *rootNode) {
  if (rootNode != NULL) {
    // Traverse lt
    inorder(rootNode->lt);

    // Traverse rootNode
    cout << rootNode->index << " -> ";

    // Traverse rt
    inorder(rootNode->rt);
  }
}

// Insert a Node
struct Node *insert(struct Node *Node, int index) {
  // Return a new Node if the tree is empty
  if (Node == NULL) return newNode(index);

  // Traverse to the rt place and insert the Node
  if (index < Node->index)
    Node->lt = insert(Node->lt, index);
  else
    Node->rt = insert(Node->rt, index);

  return Node;
}

// Find the inorder successor
struct Node *minNode(struct Node *Node) {
  struct Node *current = Node;

  // Find the ltmost leaf
  while (current && current->lt != NULL)
    current = current->lt;

  return current;
}

// Deleting a Node
struct Node *delNode(struct Node *rootNode, int index) {
  // Return if the tree is empty
  if (rootNode == NULL) return rootNode;

  // Find the Node to be deld
  if (index < rootNode->index)
    rootNode->lt = delNode(rootNode->lt, index);
  else if (index > rootNode->index)
    rootNode->rt = delNode(rootNode->rt, index);
  else {
    // If the Node is with only one child or no child
    if (rootNode->lt == NULL) {
      struct Node *t = rootNode->rt;
      free(rootNode);
      return t;
    } else if (rootNode->rt == NULL) {
      struct Node *t = rootNode->lt;
      free(rootNode);
      return t;
    }

    // If the Node has two children
    struct Node *t = minNode(rootNode->rt);

    // Place the inorder successor in position of the Node to be deld
    rootNode->index = t->index;

    // del the inorder successor
    rootNode->rt = delNode(rootNode->rt, t->index);
  }
  return rootNode;
}

// Driver code
int main() {
  struct Node *rootNode = NULL;
  rootNode = insert(rootNode, 1);
  rootNode = insert(rootNode, 2);
  rootNode = insert(rootNode, 3);
  rootNode = insert(rootNode, 4);
  rootNode = insert(rootNode, 5);
  rootNode = insert(rootNode, 6);
  rootNode = insert(rootNode, 7);
  rootNode = insert(rootNode, 8);

  cout << "Inorder traversal: ";
  inorder(rootNode);

  cout << "\nAfter deleting 10\n";
  rootNode = delNode(rootNode, 10);
  cout << "Inorder traversal: ";
  inorder(rootNode);
}
