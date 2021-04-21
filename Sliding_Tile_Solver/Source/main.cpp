/* 
 * File:   main.cpp
 * Author: talha
 *
 * Created on March 11, 2021, 11:44 p.m.
 */

#include <cstdlib>
#include <iostream>
#include "SAS.h"

using namespace std;

/*
 * 
 */
int main() {
    ios_base::sync_with_stdio(false);
    int test_case;
    SAS sas;
    if(!sas.create_pdb1())	return 0;
    if(!sas.create_pdb2())	return 0;
    chrono::steady_clock::time_point start, endt;
    chrono::duration <double> elapsed_seconds;
    start = chrono::steady_clock::now();
    char filename[] = "input/korf100.txt";
    if(freopen(filename, "r", stdin) == NULL)
    {
		cout<<"No file named '"<<filename<<"' found"<<endl;
		return 0;
	}
    while(cin>>test_case)
    {
        cout<<"TEST CASE: #"<<test_case<<endl;
        sas.IDAstar();
    }
    endt = chrono::steady_clock::now();
    elapsed_seconds = endt - start;
    cout<<"TOTAL TIME: "<<elapsed_seconds.count()<<endl;

    return 0;
}

/*
1   14 13 15 7 11 12 9 5 6 0 2 1 4 8 10 3
*/

