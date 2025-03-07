// the author is Alina Pestova DSAI-5

#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct AlinaNode {
    int key;
    int value;
    int height;
    AlinaNode* left;
    AlinaNode* right;
    AlinaNode(int k, int v) : key(k), value(v), height(1), left(nullptr), right(nullptr) {}
};

class AlinaAVLTree {
private:
    AlinaNode* root;
    int numberRotations;

    int height(AlinaNode* node) {
        if (node == nullptr) {
            return 0;
        } else {
            return node -> height;
        }
    }
    
    int balanceFactor(AlinaNode* node) {
        if (node == nullptr) {
            return 0;
        } else {
            return height(node -> left) - height(node -> right);
        }
    }
    
    void newHeight(AlinaNode* node) {
        if (node != nullptr) {
            int leftSubtreeHeight;
            int rightSubtreeHeight;

            if (node -> left != nullptr) {
                leftSubtreeHeight = node -> left -> height;
            } else {
                leftSubtreeHeight = 0;
            }
    
            if (node -> right != nullptr) {
                rightSubtreeHeight = node -> right -> height;
            } else {
                rightSubtreeHeight = 0;
            }
    
            if (leftSubtreeHeight > rightSubtreeHeight) {
                node -> height = 1 + leftSubtreeHeight;
            } else {
                node -> height = 1 + rightSubtreeHeight;
            }
        }
    }

    AlinaNode* AlinaLeftRotate(AlinaNode* x) {
        AlinaNode* y = x-> right;
        x -> right = y -> left;
        y -> left = x;

        newHeight(x);
        newHeight(y);

        numberRotations++;
        return y;
    }

    AlinaNode* AlinaRightRotate(AlinaNode* y) {
        AlinaNode* x = y -> left;
        y -> left = x -> right;
        x -> right = y;

        newHeight(y);
        newHeight(x);

        numberRotations++;
        return x;
    }

    AlinaNode* AlinaCheckBalance(AlinaNode* node) {
        newHeight(node);
        int bFactor = balanceFactor(node);
    
        if (bFactor > 1) {
            return balanceLeft(node);
        } else if (bFactor < -1) {
            return balanceRight(node);
        }
    
        return node;
    }
    
    AlinaNode* balanceLeft(AlinaNode* node) {
        if (balanceFactor(node -> left) < 0) {
            node -> left = AlinaLeftRotate(node -> left);
        }
        return AlinaRightRotate(node);
    }
    
    AlinaNode* balanceRight(AlinaNode* node) {
        if (balanceFactor(node -> right) > 0) {
            node -> right = AlinaRightRotate(node -> right);
        }
        return AlinaLeftRotate(node);
    }

    AlinaNode* AlinaAdd(AlinaNode* node, int key, int value) {
        if (node == nullptr) return new AlinaNode(key, value);

        if (key < node -> key) {
            node -> left = AlinaAdd(node -> left, key, value);

        } else if (key > node -> key) {
            node -> right = AlinaAdd(node -> right, key, value);

        } else {
            cout << "KEY ALREADY EXISTS" << endl;
            return node;
        }
        return AlinaCheckBalance(node);
    }

    AlinaNode* AlinaLookup(AlinaNode* node, int key) {
        while (node != nullptr) {
            if (key < node -> key) {
                node = node -> left;
            } else if (key > node -> key) {
                node = node -> right;
            } else {
                cout << node -> value << endl;
                return node;
            }
        }
        cout << "KEY NOT FOUND" << endl;
        return nullptr;
    }

    AlinaNode* AlinadeleteNode(AlinaNode* root, int key) {
        if (root == nullptr) {
            cout << "KEY NOT FOUND" << endl;
            return root;
        }
    
        if (key < root -> key) {
            root -> left = AlinadeleteNode(root -> left, key);

        } else if (key > root->key) {
            root -> right = AlinadeleteNode(root -> right, key);
            
        } else {
            if (root -> left == nullptr) {
                AlinaNode* temp = root -> right;
                delete root;
                root = temp;
            } else if (root -> right == nullptr) {
                AlinaNode* temp = root -> left;
                delete root;
                root = temp;
            } else {
                AlinaNode* temp = root -> right;
                while (temp -> left != nullptr) {
                    temp = temp -> left;
                }

                root -> key = temp -> key;
                root -> value = temp -> value;

                root -> right = AlinadeleteNode(root -> right, temp -> key);
            }
        }
    
        if (root == nullptr) return root;
    
        newHeight(root);
        return AlinaCheckBalance(root);
    }

public:
    AlinaAVLTree() : root(nullptr), numberRotations(0) {}

    void add(int key, int value) {
        root = AlinaAdd(root, key, value);
    }

    void deleteKey(int key) {
        root = AlinadeleteNode(root, key);
    }

    void lookup(int key) {
        AlinaLookup(root, key);
    }

    void print_rotations() {
        cout << numberRotations << endl;
    }
};

int main() {
    int N;
    cin >> N;
    AlinaAVLTree tree;

    for (int i = 0; i < N; ++i) {
        string operation;
        cin >> operation;

        if (operation == "ADD") {
            int key, value;
            cin >> key >> value;
            tree.add(key, value);

        } else if (operation == "LOOKUP") {
            int key;
            cin >> key;
            tree.lookup(key);

        } else if (operation == "DELETE") {
            int key;
            cin >> key;
            tree.deleteKey(key);

        } else if (operation == "PRINT_ROTATIONS") {
            tree.print_rotations();
        }
    }
    return 0;
}