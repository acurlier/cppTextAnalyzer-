# cppTextAnalyzer

## Description
This project aims to allow the user to:
- Download texts thanks to a list of available references contained in a text file
- Analyze them automatically and save the output of the analysis
- Get access to useful metrics.

A sample of texts that can be processed is provided in /ressources/sourceList.txt.\
In this sample, all references are hosted on https://www.gutenberg.org/ ; however you can add any other reference, provided that you follow the formating style of this sample file.

## Installation
On Linux:

* Download the sources using git clone.

* Create and activate a python3 virtual environment and install conan:
   1. Create the new virtualenv with `python3 -m venv venv`
   1. Activate the virtual environment using `source venv/bin/activate`
   1. Install conan with `pip install conan`

* Once conan is installed 
   1. CD to the root of the project, create and move to the build directory `mkdir build` + `cd build`
   1. Install the required dependencies and generate the information for the build system using `conan install ..`
   
   **NOTE**: If you are using GCC >= 5.1.1, got to the section 5 of [this page](https://docs.conan.io/en/latest/getting_started.html) - which might avoid you a large headache

* Time to build the projet!
   1. Go to /build and run CMake to configure the project and generate a native build system with `cmake ..`
   1. Call the build system using `cmake --build .`

* Move the file sourceList.txt from the "resource" directory to the binary directory so that it can be loaded by the program

* Run the program using the CLI described in the next section

**NOTE**: This program leverage filesystem functionalities featured by C++17

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

