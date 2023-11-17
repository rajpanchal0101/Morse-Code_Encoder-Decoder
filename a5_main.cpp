/**
1) Module Name: a5_main.cpp
2) Author: Raj Panchal (rjp659@uregina.ca)
3) Date of creation: 2023-11-15
4) Purpose:This is the file which consists of the main function from where the compilation of the program commences.
*/
 
#include "a5_endecutils.cpp"  

/**
1) Purpose:This is the main function from where the program's compilation begins and various user defined functions are invoked here based on the requirement.
2) Parameters: None
3) Return type: int
4) Side Effect: None
*/
int main() 
{
    ifstream inputFile("morse_code.txt");

    if (!inputFile.is_open()) 
    {
        cerr << "Error opening file." << endl; //! Prints an error message if the file cannot be opened
        return 1;
    }

    //! Reads Morse code mappings from the file
    map<char, string> morseCodeMap;
    char letter;
    string code;

    while (inputFile >> letter >> code) 
    {
        morseCodeMap[letter] = code; //! Populates Morse code map
    }
    inputFile.close();

    //! Builds Morse code binary tree
    Node* morseCodeTree = buildMorseCodeTree(morseCodeMap);

    //! Encodes a message
    cout << "\nEnter a message:\n" << endl;
    string inputMessage;
    getline(cin, inputMessage);

    string encodedMessage = encodeMessage(inputMessage, morseCodeMap);
    cout << "\nCoded message : \n" << endl;
    cout << encodedMessage << endl;

    //! Decodes the coded message
    string decodedMessage = decodeMessage(morseCodeTree, encodedMessage);
    cout << "\nDecoded message : \n" << endl;
    cout << decodedMessage << "\n" << endl;

    //! Cleans up allocated memory
    delete morseCodeTree;

    return 0;
}
