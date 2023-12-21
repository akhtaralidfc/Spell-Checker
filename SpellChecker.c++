#include <iostream>
#include <string>

class TernarySearchTree {
private:
    struct Node {
        char data;
        bool isEndOfWord;
        Node* left;
        Node* middle;
        Node* right;

        Node(char c) : data(c), isEndOfWord(false), left(nullptr), middle(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* insert(Node* node, const std::string& word, size_t index) {
        char currentChar = word[index];

        if (!node) {
            node = new Node(currentChar);
        }

        if (currentChar < node->data) {
            node->left = insert(node->left, word, index);
        } else if (currentChar > node->data) {
            node->right = insert(node->right, word, index);
        } else {
            if (index < word.length() - 1) {
                node->middle = insert(node->middle, word, index + 1);
            } else {
                node->isEndOfWord = true;
            }
        }

        return node;
    }

    bool search(Node* node, const std::string& word, size_t index) {
        if (!node) {
            return false;
        }

        char currentChar = word[index];

        if (currentChar < node->data) {
            return search(node->left, word, index);
        } else if (currentChar > node->data) {
            return search(node->right, word, index);
        } else {
            if (index < word.length() - 1) {
                return search(node->middle, word, index + 1);
            } else {
                return node->isEndOfWord;
            }
        }
    }

public:
    TernarySearchTree() : root(nullptr) {}

    void insert(const std::string& word) {
        root = insert(root, word, 0);
    }

    bool search(const std::string& word) {
        return search(root, word, 0);
    }
};

int main() {
    TernarySearchTree spellChecker;

    // Load dictionary words into the TST
    spellChecker.insert("apple");
    spellChecker.insert("banana");
    spellChecker.insert("orange");
    spellChecker.insert("grape");
    spellChecker.insert("pear");

    // Test the spell checker
    std::cout << "Is 'apple' spelled correctly? " << (spellChecker.search("apple") ? "Yes" : "No") << std::endl;
    std::cout << "Is 'banana' spelled correctly? " << (spellChecker.search("banana") ? "Yes" : "No") << std::endl;
    std::cout << "Is 'kiwi' spelled correctly? " << (spellChecker.search("kiwi") ? "Yes" : "No") << std::endl;

    return 0;
}
