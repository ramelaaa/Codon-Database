# Codon Database

A menu-driven C++ program for looking up codons and amino acids and analyzing an RNA sequence.

## Features

- Displays amino acids and their associated codons.
- Looks up the amino acid associated with a codon.
- Lists the codons associated with an amino acid.
- Counts how often an amino acid appears in the provided RNA sequence.

## Data Files

The program reads two files from its current working directory:

- `Codons_list.txt` contains amino-acid and codon pairs.
- `Codons.txt` contains the RNA sequence to analyze.

Keep both files in the project folder when running the program.

## Build and Run

From the project folder, compile with a C++14-compatible compiler:

```bash
clang++ -std=c++14 main.cpp CodonClass.cpp -o codon_database
./codon_database
```

If you use GCC, replace `clang++` with `g++`.

## Menu Options

| Option | Action |
| --- | --- |
| `DA` | Display the amino acids and their codons. |
| `SF` | Search for an amino acid and report its count in the sequence. |
| `SC` | Look up the amino acid associated with a codon. |
| `SA` | List the codons associated with an amino acid. |
| `E` | Exit the program. |

Menu options are entered in uppercase.

## Concepts Practiced

- Classes, structs, and separating declarations into a header and implementation file.
- `vector` containers, including vectors nested inside structs.
- File input with `ifstream`.
- String processing and splitting an RNA sequence into three-character codons.
- Linear searches, nested loops, and menu-driven control flow.
