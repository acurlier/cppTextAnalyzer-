# cppBinarySearchTree
## Description
This project aims at to implement the BST (binary search tree) ADT in order to allow the user to look for specific
elements in large chunk of text, get "usefull" metrics and look for some specific occurrences of words in the text

## Visuals
Depending on what you are making, it can be a good idea to include screenshots or even a video (you'll frequently see GIFs rather than actual videos). Tools like ttygif can help, but check out Asciinema for a more sophisticated method.

## Installation
1. Download the sources using git clone.
2. Compile the sources using the makefile

## Usage
There are 3 modes for this program
1. An interactive processing mode:\
This mode allows you to select a specific text to process from a list (sourceList.txt), 
it will ask you what you want to display during the course of the program,
will save the results and terminate. You can launch this mode with:
`bstIndexing -p --manual`
2. An automatic processing mode:\
This mode will sequentially select the elements from sourceList.txt, run the proper processing, will save the results
and terminate. You can launch this mode with:
`bstIndexing -p --manual`

3. An interactive exploration mode: this will allow you to "load" the results of a previous indexing sequence and
   1. get metrics about this text.
   2. look for a specific term in the text, get the number of occurrences anf being proposed to display these occurrences in their context.
   
   Of course you will first need to process at least one text before being able to use this mode.\
You can access this mode by typing: `bstIndexing -u`
   
## Project status
on dev

