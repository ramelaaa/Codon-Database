#include "CodonClass.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <cctype>
#include <cstddef>
using namespace std;

void CodonClass::input()
{
    ifstream fileDatabase;
    fileDatabase.open("Codons_list.txt");
    vector<string> Codon_AA_matches;
    string line;
    
    while(!fileDatabase.eof())
    {
        fileDatabase >> line;
        Codon_AA_matches.push_back(line);
    }

    for (std::size_t i=0; i < Codon_AA_matches.size(); i++ )
    {
        //if the index contains the name of an amino acid
        if(i % 2 == 0)
        {  
            //checks if variable is already present in data structure
            bool found = false; 

            //check data structure       
            for (std::size_t j=0; j < List.size(); j++)
            {
                if(List[j].name == Codon_AA_matches[i]){
                    //name is already present in data structure
                    found = true;       
                }
            }

            //don't reenter name if already present in data structure
            if (found == true)
            {
                continue;     
            }
            else
            {
                //if name is not present in data structure, add is
                AminoAcid temp;           
                temp.name = Codon_AA_matches[i];
                List.push_back(temp);
            }
        }
        else
        {  //if the index contains a codon
            //find the amino acid structure
            for (std::size_t j=0; j < List.size(); j++)
            {
                if(List[j].name == Codon_AA_matches[i-1])
                {
                    //input codon
                    List[j].Codons.push_back(Codon_AA_matches[i]);
                }
            }
        }
    }
}

void CodonClass::file2()
{
    ifstream CodonFile;
    CodonFile.open("Codons.txt");
    string file;
    string createCodon;
    string codon;
    vector<string> Codon_List;

    while(!CodonFile.eof())
    {
        CodonFile >> file;
    }

    //cout << file.length() << endl;

    int z = 0;
    do{
        for(std::size_t i = 0; i<file.length(); i++)
        {
            if(!isprint(file[i]))
            {

                file.erase(file.begin()+i);    
            }
        }
        z++;
    }while(z<5);
    //cout << file.length() << endl;
    
    for(std::size_t i = 0; i<file.length(); i++)
    {
        if(file[i] == 'a')
        {
            continue;
        }
        else if(file[i] == 'g')
        {
            continue;
        }
        else if(file[i] == 'c')
        {
            continue;
        }
        else if(file[i] == 'u')
        {
            continue;
        }
        else
        {
            cout << "Error, unknown character." << endl;
            return;
        }
        
    }
    for(std::size_t i =0; i<file.length(); i+=3)
    {
        codon = file.substr(i,3);
        Codon_List.push_back(codon);
        codon.erase();
    }

    for(std::size_t i = 0; i<List.size(); i++)
    {   
        Codon temp;
        temp.AAname = List[i].name;
        for(std::size_t j = 0; j<List[i].Codons.size(); j++)
        {
            for(std::size_t k = 0; k<Codon_List.size(); k++)
            {
                if(Codon_List[k] == List[i].Codons[j])
                {
                    temp.fileMatches.push_back(Codon_List[k]);
                }
            }
        }
        //cout << temp.fileMatches.size() << endl;
        List8.push_back(temp);
    }


}
int CodonClass::searchfile2(string AA)
{
    for(std::size_t i=0; i<List8.size(); i++)
    {
        if(AA == List8[i].AAname)
        {
            cout << "The Amino Acid appears "<< List8[i].fileMatches.size() << " times." << endl;
            return List8[i].fileMatches.size();
        }
    }

    int y = 0;
    cout << "not found" << endl;
    return y;
}

string CodonClass::Codon_AA_converter(string cdn)
{
    
    for(std::size_t i=0; i<List.size(); i++)
    {
        
        for(std::size_t j=0; j<List[i].Codons.size(); j++)
        {
            if (cdn == List[i].Codons[j])
            {
                cout << "The Amino Acid is: "<<List[i].name << endl;
                return List[i].name;
            }
            else if(i==(List.size()-1)&&j==(List[i].Codons.size()-1) && cdn != List[i].Codons[j])
            {
                cout << "Not found" << endl;
            }
        }
    }
    return "Not found."; 
}

vector<string> CodonClass::AA_Codon_converter(string AA)
{
    for(std::size_t j = 0; j<List.size(); j++)
    {
        if(List[j].name == AA)
        {
            cout << "The codons are: " << endl;
            for(std::size_t i=0; i<List[j].Codons.size(); i++)
            {
                cout << i+1 << ". " <<List[j].Codons[i] << " ";
            }
            cout << endl;
            return List[j].Codons;
        }
    }
    cout << "Not found" << endl;
    vector<string> empty;
    return empty;
}

void CodonClass::Display()
{
    for(std::size_t i=0; i< List.size(); i++)
    {
        cout << List[i].name << ": ";
        for(std::size_t j=0; j<List[i].Codons.size(); j++)
        {
            cout << List[i].Codons[j] << " ";
        } 
        cout << endl;  
    }
}


