#include <iostream>
#include <fstream> //! File stream for file input/output
#include <map> //! Map data structure for Morse code mappings

using namespace std;

//! Node structure for the binary tree
struct Node {
    char data;   //! Data stored in the node
    Node* left;  //! Pointer to the left child node
    Node* right; //! Pointer to the right child node
    Node(char val) : data(val), left(nullptr), right(nullptr) {}
};

//! Function to build the Morse code binary tree
Node* buildMorseCodeTree(const map<char, string>& morseCodeMap) {
    Node* root = new Node('*'); //! Root node with no letter
    for (auto& pair : morseCodeMap) {
        Node*  cnode = root;
        for (char c : pair.second) {
            if (c == '.') {
                if (! cnode->left) {
                     cnode->left = new Node('*'); //! Create a new node if left child is nullptr
                }
                 cnode =  cnode->left;  //! Move to the left child
            } else if (c == '-') {
                if (! cnode->right) {
                     cnode->right = new Node('*'); //! Create a new node if right child is nullptr
                }
                 cnode =  cnode->right; //! Move to the right child
            }
        }
         cnode->data = pair.first; //! Assign the corresponding letter to the current node
    }
    return root; //! Return the root of the built Morse code binary tree
}

//! Function to encode a message using Morse code
string encodeMessage(const string& message, const map<char, string>& morseCodeMap) {
    string encodedMessage;
    for (char c : message) {
        if (c == ' ') {
            encodedMessage += " "; //! Use space as delimiter between words
        } else {
            encodedMessage += morseCodeMap.at(tolower(c)) + " "; //! Append Morse code for each character
        }
    }
    return encodedMessage; //! Return the encoded message
}

//! Function to decode a message using Morse code tree
string decodeMessage(Node* root, const string& encodedMessage) {
    string decodedMessage;
    Node*  cnode = root;
    for (char c : encodedMessage) {
        if (c == '.') {
             cnode =  cnode->left; //! Traverse left child for dot
        } else if (c == '-') {
             cnode =  cnode->right; //! Traverse right child for dash
        } else if (c == ' ') {
            if ( cnode->data != '*')
            {
                decodedMessage +=  cnode->data; //! Append the decoded letter if not at the root
            } else {
                decodedMessage += ' '; //! Append space if '*' is encountered
            }
             cnode = root; //! Reset to the root for the next letter
        }
    }
    if ( cnode->data != '*') {
        decodedMessage +=  cnode->data; //! Append the last decoded letter if not at the root
    }
    return decodedMessage; //! Return the decoded message
}

int main() {
    ifstream inputFile("morse_code.txt");
    if (!inputFile.is_open()) {
        cerr << "Error opening file." << endl; //! Print an error message if the file cannot be opened
        return 1;
    }

    //! Read Morse code mappings from the file
    map<char, string> morseCodeMap;
    char letter;
    string code;
    while (inputFile >> letter >> code) {
        morseCodeMap[letter] = code; //! Populate Morse code map
    }
    inputFile.close();

    //! Build Morse code binary tree
    Node* morseCodeTree = buildMorseCodeTree(morseCodeMap);

    //! Step 2: Encode a message
    cout << "Enter a message:\n" << endl;
    string inputMessage;
    getline(cin, inputMessage);

    string encodedMessage = encodeMessage(inputMessage, morseCodeMap);
    cout << "\nCoded message : \n" << endl;
    cout << encodedMessage << endl;

    //! Step 3: Decode the coded message
    string decodedMessage = decodeMessage(morseCodeTree, encodedMessage);
    cout << "\nDecoded message : \n" << endl;
    cout << decodedMessage << endl;

    //! Clean up allocated memory
    delete morseCodeTree;

    return 0;
}
