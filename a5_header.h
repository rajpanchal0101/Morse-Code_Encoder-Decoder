/**
1) Module Name: a5_header.h
2) Author: Raj Panchal (rjp659@uregina.ca)
3) Date of creation: 2023-11-15
4) Purpose: This is a header file which consists of all the required libraries, global variables and function's declaration.
*/ 
# pragma once
#include <iostream>
#include <fstream> //! File stream for file input/output
#include <map> //! Map data structure for Morse code mappings

using namespace std;

//! Node structure for the binary tree
struct Node
{
    char data;   //! Data stored in the node
    Node* left;  //! Pointer to the left child node
    Node* right; //! Pointer to the right child node
    Node(char val) : data(val), left(nullptr), right(nullptr) {}
};

//! Function to build the Morse code binary tree
Node* buildMorseCodeTree(const map<char, string>& morseCodeMap);


//! Function to encode a message using Morse code
string encodeMessage(const string& message, const map<char, string>& morseCodeMap);


//! Function to decode a message using Morse code tree
string decodeMessage(Node* root, const string& encodedMessage);