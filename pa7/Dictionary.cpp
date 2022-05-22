#include "Dictionary.h"


// constructors -------------------------------------------

Dictionary::Node::Node(keyType k, valType v) {
    key = k;
    val = v;
    parent = nullptr;
    left = nullptr;
    right = nullptr;
}

Dictionary::Dictionary() {
    nil = new Node("/", -1);
    root = nullptr;
    current = nullptr;
    num_pairs = 0;
}

Dictionary::Dictionary(const Dictionary& D) {
    nil = new Node("/", -1);
    nil = D.nil;
    root = D.root;
    current = D.current;
    num_pairs = D.num_pairs;
}

Dictionary::~Dictionary() {
    delete nil;
    nil = nullptr;
}


// Binary Search Tree Helper Functions --------------------
// inOrderString()
// Appends a string representation of the tree rooted at R to string s. The
// string appended consists of: "key : value \n" for each key-value pair in
// tree R, arranged in order by keys.
void Dictionary::inOrderString(std::string& s, Node* R) const {
    // s = s + ...;
    s = s + (R->key) + " : " + std::to_string(R->val) + " \n";  // Concatenates key and corresponding
                                                           // key and value to string s.
    return;
}


// Access Functions ---------------------------------------

int Dictionary::size() const {
    return num_pairs;
}

//
//bool Dictionary::contains(keyType k) const;
