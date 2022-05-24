#include "Dictionary.h"


// constructors ---------------------------------------------------------------

Dictionary::Node::Node(keyType k, valType v) {
    key = k;
    val = v;
    parent = nullptr;
    left = nullptr;
    right = nullptr;
}

Dictionary::Dictionary() {
    nil = new Node("/", -1);
    root = nil;
    root->parent = nil;
    root->left = nil;
    root->right = nil;
    current = nil;
    num_pairs = 0;
}

// Need to fix. This will not work.
Dictionary::Dictionary(const Dictionary& D) {
    nil = new Node("/", -1);
    nil = D.nil;
    root = D.root;
    current = D.current;
    num_pairs = D.num_pairs;
}

Dictionary::~Dictionary() {
    //delete nil;
//    nil = nullptr;
}


// Binary Search Tree Helper Functions ----------------------------------------
// inOrderString()
// Appends a string representation of the tree rooted at R to string s. The
// string appended consists of: "key : value \n" for each key-value pair in
// tree R, arranged in order by keys.
void Dictionary::inOrderString(std::string& s, Node* R) const {
    // s = s + ...;
    if (R != nil) {
        inOrderString(s, R->left);
        s = s + (R->key) + " : " + std::to_string(R->val) + " \n";  // Concatenates key and corresponding
        inOrderString(s, R->right);
    }
    return;
}

void Dictionary::preOrderString(std::string& s, Node* R) const {
    if (R != nil) {
        s = s + (R->key) + "\n";
        preOrderString(s, R->left);
        preOrderString(s, R->right);
    }
    return;
}

Dictionary::Node* Dictionary::search(Node* R, keyType k) const {
    if (R == nil || k == R->key) {
        return R;
    } else if (k < R->key) {
        search(R->left, k);
    } else {
        search(R->right, k);
    }

    return R;  // Should never hit this return. To silence non-void return warning.
}

// Access Functions -----------------------------------------------------------

int Dictionary::size() const {
    return num_pairs;
}

//
//bool Dictionary::contains(keyType k) const;


// Manipulation Procedures() --------------------------------------------------

// setValue()
// If a pair with key==k exists, overwrites the corresponding value with v,·
// otherwise inserts the new pair (k, v)
void Dictionary::setValue(keyType k, valType v) {
    Node *y = nil;
    Node *x = root;
    while (x != nil) {
        y = x;
        if (k == x->key) {
            x->val = v;
            return;
        } else if (k < x->key) {
            x = x->left;
        } else {
            x = x->right;
        }
    }
    Node *z = new Node(k, v);
    z->parent = y;
    if (y == nil) {
        this->root = z;
    } else if (z->key < y->key) {
        y->left = z;
    }
    else {
        y->right = z;
    }
    num_pairs++;

    z->left = nil;
    z->right = nil;
}

// Other Functions ------------------------------------------------------------

// to_string()
// Returns a string representation of this Dictionary. Consecutive (key, value)
// pairs are separated by a newline "\n" character, and the items key and value 
// are separated by the sequence space-colon-space " : ". The pairs are arranged 
// in order, as defined by the order operator <.
std::string Dictionary::to_string() const {
    std::string s;
    inOrderString(s, root);
    return s;
}

std::string Dictionary::pre_string() const {
    std::string s;
    preOrderString(s, root);
    return s;
}
