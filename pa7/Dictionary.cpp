#include "Dictionary.h"

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
}
