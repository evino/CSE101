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
    clear();
    delete nil;
    nil = nullptr;
}

    //delete nil;
//    nil = nullptr;



// Binary Search Tree Helper Functions ----------------------------------------

// inOrderString()
// Appends a string representation of the tree rooted at R to string s. The
// string appended consists of: "key : value \n" for each key-value pair in
// tree R, arranged in order by keys.
void Dictionary::inOrderString(std::string& s, Node* R) const {
    if (R != nil) {
        inOrderString(s, R->left);
        s = s + (R->key) + " : " + std::to_string(R->val) + " \n";  // Concatenates key and corresponding
        inOrderString(s, R->right);
    }
    return;
}


// preOrderCopy()
// Recursively inserts a deep copy of the subtree rooted at R into this 
// Dictionary. Recursion terminates at N.
void Dictionary::preOrderCopy(Node* R, Node* N) {
    if (R != nil) {
        setValue(R->key, N->val);
        preOrderCopy(R->left, N->left);
        preOrderCopy(R->right, N->right);
    }
    return;
}

// postOrderDelete()
// Deletes all Nodes in the subtree rooted at R, sets R to nil.
void Dictionary::postOrderDelete(Node* R) {
    if (R != nil) {
        delete R;
        postOrderDelete(R->left);
        postOrderDelete(R->right);
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
    
    return nil;  // Should never hit this return. To silence non-void return warning.
}

// findMin()
// If the subtree rooted at R is not empty, returns a pointer to the 
// leftmost Node in that subtree, otherwise returns nil.
Dictionary::Node* Dictionary::findMin(Node* R) {
    if (R == nil) {
        throw std::invalid_argument("Tree Error: Trying to find min Node from nil rooted subtree.");
    }

    while (R->left != nil) {
        R = R->left;
    }
    return R;
}

// findMax()
// If the subtree rooted at R is not empty, returns a pointer to the 
// rightmost Node in that subtree, otherwise returns nil.
Dictionary::Node* Dictionary::findMax(Node* R) {
    if (R == nil) {
        throw std::invalid_argument("Tree Error: Trying to find max node from nil rooted subtree.");
    }

    while (R->right != nil) {
        R = R->right;
    }
    return R;
}


// findNext()
// If N does not point to the rightmost Node, returns a pointer to the
// Node after N in an in-order tree walk.  If N points to the rightmost 
// Node, or is nil, returns nil. 
Dictionary::Node* Dictionary::findNext(Node* N) {
    if (N->right != nil) {
        return findNext(N->right);
    }
    Node *y = N->parent;
    while (y != nil && N == y->right) {
        N = y;
        y  = y->parent;
    }
    return y;
}


Dictionary::Node* Dictionary::findPrev(Node* N) {
    if (N->left != nil) {
        return findPrev(N->left);
    }
    Node *y = N->parent;
    while (y != nil && N == y->left) {
        N = y;
        y = y->parent;
    }
    return y;
}

void Dictionary::transplant(Node *A, Node *B) {
    if (A->parent== nil) {
        root = B;
    } else if (A == A->parent->left) {
        A->parent->left = B;
    } else {
        A->parent->right = B;
    }

    if (B != nil) {
        B->parent = A->parent;
    }

    return;
}

void Dictionary::Delete(Node *N) {
    if (N->left == nil) {
        transplant(N, N->right);
    } else if (N->right == nil) {
        transplant(N, N->left);
    }
    else {
        Node *y = findMin(N->right);
        if (y->parent != N) {
            transplant(y, y->right);
            y->right = N->right;
            y->right->parent = y;
        }
        transplant(N, y);
        y->left = N->left;
        y->left->parent = y;
    }

    return;
}




// Access Functions -----------------------------------------------------------

int Dictionary::size() const {
    return num_pairs;
}

// Returns true if there exists a pair such that key==k, and returns false
// otherwise.
bool Dictionary::contains(keyType k) const {
    if (search(root, k) != nil) {
        return true;
    } else {
        return false;
    }
}


// getValue()
// Returns a reference to the value corresponding to key k.
// Pre: contains(k)
valType& Dictionary::getValue(keyType k) const {
    if (!contains(k)) {
        throw std::logic_error("Dictionary Error: Calling getValue() on dictionary that doesn't contain key k.");
    }

    Node *n;
    n = search(root, k);
    return n->val;
}

// hasCurrent()
// Returns true if the current iterator is defined, and returns false·
// otherwise.
bool Dictionary::hasCurrent() const {
    if (current != nil) {
        return true;
    }

    return false;
}

// currentKey()
// Returns the current key.
// Pre: hasCurrent()
keyType Dictionary::currentKey() const {
    if (hasCurrent() == false) {
        std::logic_error("Dictionary Error: Calling currentKey on undefined current");
    }

    return current->key;
}

// currentVal()
// Returns a reference to the current value
// Pre: hasCurrent()
valType& Dictionary::currentVal() const {
    if (hasCurrent() == false) {
        std::logic_error("Dictionary Error: Calling currentVal on undefined current");
    }

    return current->val;
}

// Manipulation Procedures() --------------------------------------------------

// clear()
// Resets this Dictionary to the empty state, containing no pairs.
void Dictionary::clear() {
    root = nil;
    postOrderDelete(root);
    current = nil;
    num_pairs = 0;
}


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


void Dictionary::remove(keyType k) {
    if (!contains(k)) {
        throw std::logic_error("Dictionary Error: Calling remove() on dictionary that doesn't contain k.");
    }
    Node *n = search(root, k);
    Delete(n);

    return;
}

// begin()
// If non-empty, places current iterator at the first (key, value) pair
// (as defined by the order operator < on keys), otherwise does nothing.
void Dictionary::begin() {
    if (num_pairs > 0) {
        current = root; // might need something else
    }
    return;
}


// end()
// If non-empty, places current iterator at the last (key, value) pair
// (as defined by the order operator < on keys), otherwise does nothing.
void Dictionary::end() {
    if (num_pairs > 0) {
        current = findMax(root);
    }
    return;
}


// next()
// If the current iterator is not at the last pair, advances current
// to the next pair (as defined by the order operator < on keys). If
// the current iterator is at the last pair, makes current undefined.
// Pre: hasCurrent()
void Dictionary::next() {
    if (has








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


