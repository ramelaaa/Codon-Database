#ifndef CodonClass_h
#define CodonClass_h
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

class CodonClass
{
public:
    void input();
    void file2();
    string Codon_AA_converter(string cdn);
    vector<string> AA_Codon_converter(string AA);
    int searchfile2(string AA);
    
    void Display();
    
    struct AminoAcid            //stores amino acid name and their codon.
    {
        string name;            //AMINO ACID
        vector<string> Codons ;	//all their codons(maybe more than 1)
    };

    struct Codon
    {
        string AAname;
        vector<string> fileMatches;
    };

private:
    
        vector<AminoAcid> List;
        vector<Codon> List8;
        
};

#endif
