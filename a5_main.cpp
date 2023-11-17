/**
1) Module Name: a4_main.cpp
2) Author: Raj Panchal (rjp659@uregina.ca)
3) Date of creation: 2023-11-15
4) Purpose:This is the file which consists of the main function from where the compilation of the program commences.
*/
#include "a5_endecutils.cpp"  

int main() 
{
    ifstream inputFile("morse_code.txt");

    if (!inputFile.is_open()) 
    {
        cerr << "Error opening file." << endl; //! Print an error message if the file cannot be opened
        return 1;
    }

    //! Read Morse code mappings from the file
    map<char, string> morseCodeMap;
    char letter;
    string code;

    while (inputFile >> letter >> code) 
    {
        morseCodeMap[letter] = code; //! Populate Morse code map
    }
    inputFile.close();

    //! Build Morse code binary tree
    Node* morseCodeTree = buildMorseCodeTree(morseCodeMap);

    //! Step 2: Encode a message
    cout << "\nEnter a message:\n" << endl;
    string inputMessage;
    getline(cin, inputMessage);

    string encodedMessage = encodeMessage(inputMessage, morseCodeMap);
    cout << "\nCoded message : \n" << endl;
    cout << encodedMessage << endl;

    //! Step 3: Decode the coded message
    string decodedMessage = decodeMessage(morseCodeTree, encodedMessage);
    cout << "\nDecoded message : \n" << endl;
    cout << decodedMessage << "\n" << endl;

    //! Clean up allocated memory
    delete morseCodeTree;

    return 0;
}
