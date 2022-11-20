#include <iostream>
#include "CodonClass.h"
#include <string>
#include <cstdlib>
using namespace std;

int main()
{
    string MenuChoice;
    CodonClass X;
    string userInput;

    X.input();
    X.file2();

    
    do
    {
        cout << "DA - Display all the amino acids found in the file." << endl;
        cout << "SF - Search Amino Acid" << endl;
        cout << "SC - Search Amino acid using codon." << endl;
        cout << "SA - Search codon using amino acid." << endl;
        cout << "E - Exit." << endl;
        cout << "Enter Menu Choice: " ;
        cin >>  MenuChoice;
        
        if (MenuChoice == "DA") //good
        {
            X.Display();
        }
        
        else if(MenuChoice == "SF")
        {
            cout << "Amino Acid: ";
            cin >> userInput;
            X.searchfile2(userInput);
        }
         
        else if(MenuChoice == "SC") //good
        {
            cout << "Enter Codon: ";
            cin >> userInput;
            X.Codon_AA_converter(userInput);
        }
        else if(MenuChoice == "SA") // good
        {
            cout << "Amino Acid: ";
            cin >> userInput;
            X.AA_Codon_converter(userInput);
        }
        else if(MenuChoice == "E") //good
        {
            exit(1);
        }
        else
        {
            cout << "Try Again." << endl; //good
        }

    }while(MenuChoice != "E");
    
    return 0;
}
