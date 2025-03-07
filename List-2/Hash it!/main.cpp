#include "Hash.h"
#include <iostream>

using namespace std;

int main()
{   
    int numCases;
    int numOperations;
    int lenTable;
    int numElements;
    string opCode;
    string word = "";
    string operation = "";
    HashTable<string> table(101);

    cin >> numCases;
    cin >> numOperations;

    for(int i = 0; i < numCases; i++)
    {
        for(int j = 0; j < numOperations; j++)
        {
            cin >> operation;

            for(int k = 0; k < 3; k++)
                opCode += operation[k];
            
            int t = 4;
            bool halt = false;
            while(!halt)
            {
                if(operation[t] == '\0')
                    halt = true;
                else
                    word += operation[t];

                t++;
            }

            if(opCode == "ADD")
                table.insert(word);
            else if(opCode == "DEL")
                table.remove(word);
            
            opCode = "";
            word = "";
        }
        
    }
    
    lenTable = table.lenght();
    numElements = table.getNumElements();

    cout << numElements << endl;

    for(int key = 0; key < lenTable; key++)
    {
        if(table.value(key) != "")
            cout << key << ":" << table.value(key) << endl;
    }

    return 0;
};