# cppTextAnalyzer

## Description
This project aims to allow the user to:
- Download texts thanks to a list of available references contained in a text file
- Analyze them automatically and save the output of the analysis
- Get access to useful metrics.

A sample of texts that can be processed is provided in /ressources/sourceList.txt.\
In this sample, all references are hosted on https://www.gutenberg.org/ ; however you can add any other reference, provided that you follow the formating style of this sample file.

## Installation
1. Download the sources using git clone.
2. CD to the directory containing the source files, and create the build directory using 'mkdir build'
3. Build the projet using the makefile 'cmake --build'
4. Move the file sourceList.txt from the "resource" directory to the binary directory

Note that this program leverage filesystem functionalities featured by C++17

## Usage
There are 3 modes for this program
1. An interactive processing mode:\
This mode allows you to select a specific text to process from a list (sourceList.txt), 
it will ask you what you want to display during the course of the program,
will save the results and terminate. You can launch this mode with:
`bstIndexing -p --i`
2. An automatic processing mode:\
This mode will sequentially select the elements from sourceList.txt, run the proper processing, will save the results
and terminate. You can launch this mode with:
`bstIndexing -p --a`

3. An interactive exploration mode: this will allow you to "load" the results of a previous indexing sequence and
   1. get metrics about this text.
   2. look for a specific term in the text, get the number of occurrences anf being proposed to display these occurrences in their context.
   
Of course you will first need to process at least one text before being able to use this mode.\
You can access this mode by typing: `bstIndexing -u`
   
## Project status
Completed - might be reopened later to add extra features

