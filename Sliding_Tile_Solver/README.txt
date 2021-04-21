###################################################################################################
ASSIGNMENT
Author: Talha Ibn Aziz
Student ID: 1669108
Graduate Student, University of Alberta
Course: CMPUT 658 Single Agent Search
Instructor: Prof. Nathan R. Sturtevant

###################################################################################################

1. The folder "Results" contain the text files mentioned in the report (Report.pdf).
2. The folder "Source" contains the source files required to build the program and the
"Makefile" to execute it. To run the program write "make" from the terminal and then
run the command "./stp".
3. By default the program tries to read from the database and shows error message if unsuccessful.
4. To turn on the creation of database comment out the code from the lines 242-251 of "SAS.cpp".
5. The lines to be commented are as follows:

	 FILE * rFile;
	 rFile = fopen ("database/PDB2.data", "rb");
	 if(rFile == NULL)
	 {
		 cout<<"ERROR: No file to read data base from!"<<endl;
		 return false;
	 }
	 cout<<"PDB2 Read from file: "<<fread(PDB2.data(), sizeof(char), MAX_PDB2, rFile)<<endl;
	 fclose (rFile);
	 return true;

6. Once the lines are commented, the program will create the database and save it in the "database"
folder of the current directory.
7. Then if the lines are again un-commented, the program will read from the files.

####################################################################################################
