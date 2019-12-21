//
//  main.cpp
//  ioModule
//
//  Created by  云子谣 on 2019/12/14.
//  Copyright © 2019  云子谣. All rights reserved.
//

#include <iostream>
#include <fstream>
using namespace std;
int main(int argc, const char * argv[]) {
    // insert code here...
    //std::cout << "Hello, World!\n";
    streampos size;
    char *memblock;
    ifstream file ("/Users/crystal-dragon-lyb/logWell_Projects/DLIS_TEST.dlis", ios::in|ios::binary);
    if (file.is_open())
    {
      //size = file.tellg();
      memblock = new char [4096];
      //file.seekg (0, ios::beg);
      //file.read (memblock, 4096);

      //cout << memblock<< endl;
      cout << "the entire file content is in memory" << endl;
      int i = 0;
      while(i<1)
      {
          //read the first SUL
          file.read (memblock, 4);
          cout << memblock<< endl;
          file.seekg(4, ios::beg);
          
          file.read(memblock, 5);
          cout << memblock << endl;
          file.seekg(4+5, ios::beg);
          
          file.read(memblock, 6);
          cout << memblock << endl;
          file.seekg(4+5+6, ios::beg);
          
          file.read(memblock,5);
          cout << memblock << endl;
          file.seekg(4+5+6+5,ios::beg);
          
          file.read(memblock,61);
          cout << memblock << endl;
          file.seekg(4+5+6+5+61,ios::beg);
          
          file.read(memblock, 1);
          cout << "the final :" << memblock << endl;
          
          
          //1（Storage Unit Sequence Number）V1.00(DLIS Version) RECORD（Storage Unit Structure） 8192(Maximum Record Length) Default Storage Set(Storage Set Identifer)
          
          cout << "*******************************" << endl;
          i++;
      }
      file.close();

      delete[] memblock;
    }
    else cout << "Unable to open file";
    return 0;

    
    return 0;
}
