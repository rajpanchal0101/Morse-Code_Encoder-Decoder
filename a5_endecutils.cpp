/**
1) Module Name: a5_endecutils.cpp
2) Author: Raj Panchal (rjp659@uregina.ca)
3) Date of creation: 2023-11-16
4) Purpose: This is the file which consists of implementation of the various functions declared in the header file.
*/
 
#include "a5_header.h" 

//! Function to build the Morse code binary tree
Node* buildMorseCodeTree(const map<char, string>& morseCodeMap)
 {
    Node* root = new Node('*'); //! Root node with no letter

    for (auto& pair : morseCodeMap)
    {
        Node*  cnode = root;

        for (char c : pair.second) 
        {
            if (c == '.')
            {
                if (! cnode->left) 
                {
                     cnode->left = new Node('*'); //! Creates a new node if left child is nullptr
                }
                 cnode =  cnode->left;  //! Moves to the left child
            } 
            else if (c == '-') 
            {
                if (! cnode->right) 
                {
                     cnode->right = new Node('*'); //! Creates a new node if right child is nullptr
                }
                 cnode =  cnode->right; //! Moves to the right child
            }
        }
         cnode->data = pair.first; //! Assigns the corresponding letter to the current node
    }

    return root; //! Returns the root of the built Morse code binary tree
}


//! Function to encode a message using Morse code
string encodeMessage(const string& message, const map<char, string>& morseCodeMap) 
{
    string encodedMessage;

    for (char c : message)
    {
        if (c == ' ')
        {
            encodedMessage += " "; //! Uses space as delimiter between words
        } 
        else 
        {
            encodedMessage += morseCodeMap.at(tolower(c)) + " "; //! Appends Morse code for each character
        }
    }

    return encodedMessage; //! Returns the encoded message
}


//! Function to decode a message using Morse code tree
string decodeMessage(Node* root, const string& encodedMessage) 
{
    string decodedMessage;
    Node*  cnode = root;

    for (char c : encodedMessage) 
    {
        if (c == '.') 
        {
             cnode =  cnode->left; //! Traverses left child for dot
        } 
        else if (c == '-') 
        {
             cnode =  cnode->right; //! Traverses right child for dash
        } 
        else if (c == ' ') 
        {
            if ( cnode->data != '*')
            {
                decodedMessage +=  cnode->data; //! Appends the decoded letter if not at the root
            } 
            else 
            {
                decodedMessage += ' '; //! Appends space if '*' is encountered
            }
             cnode = root; //! Resets to the root for the next letter
        }
    }

    if ( cnode->data != '*')
    {
        decodedMessage +=  cnode->data; //! Appends the last decoded letter if not at the root
    }

    return decodedMessage; //! Returns the decoded message
}