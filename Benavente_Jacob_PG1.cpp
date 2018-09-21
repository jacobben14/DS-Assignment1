//  Authors: Conor Schindel, Jacob Benavente
//  Due Date: 2/3/16
//  Programming Assignment Number 1
//  Spring 2016 - CS 3358 - Section 253
//
//  Instructor: Husain Gholoom
//
//  The magic square program generates a two-dimensional array
//  based on a size that the user inputs, populates the array with
//  random numbers, and evaluates whether or not the array is a magic
//  square.

#include<cmath>
#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void populateArray(int[], int, int);

bool isMagicSquare(int[], int, int);

int main()
{
    int size = 0;   // integer value for size of array
    int magicNumber = 0;    // integer value to hold magic number
    char choice; // character value for user to decide if he/she wants to keep running the program.
    bool isMagic;

    cout << "Welcome to my magic square program. The function of the ";
    cout << "program is to\n\n";
    cout << "\t1. Allow the user to enter the size of the magic square";
    cout << " such as N. N >= .2\n";
    cout << "\t2. Create an array of size N x N.\n";
    cout << "\t3. Populate the array with distinct random numbers.\n";
    cout << "\t4. Display the sum for each row, column, and diagonals ";
    cout << "then determine whether      the numbers in N x N array are ";
    cout << "magic square numbers.\n\n";


    do{

        cout << "Enter the size of the magic square: ";
        cin >> size;

        if(size < 2)
        {
            cout << "\nError *** magic square size Must be >= 2" << endl;
        }
        else
        {
            int array[size*size];

            magicNumber = (size*((size*size)+1))/2;

            populateArray(array, size, magicNumber);


            cout << "\n\n The magic number is : " << magicNumber;

            isMagic = isMagicSquare(array,magicNumber,size);

            if(isMagic != true)
            {
                cout << "\nThe above is not a magic square" << endl;
            }
            else
            {
                cout << "\nThe above is a magic square" << endl;
            }
        }

        cout << endl << endl;
        cout << "Would you like to find another magic square - Enter y | Y for yes or";
        cout << " n | N for no:  ";
        cin >> choice;

        while(choice != 'n' && choice != 'N' && choice !='y' && choice != 'Y')
            {
                cout << "\nError *** Invalid choice - Must enter y | Y | n | N" << endl;
                cout << "\nWould you like to find another magic square - Enter y | Y for yes or";
                cout << " n | N for no:  ";
                cin >> choice;
            }

    }while(choice != 'n' && choice != 'N');


    cout << "\nThis magic square algorithm is implemented By Conor Schindel and Jacob Benavente" << endl;


}

void populateArray(int oneDArray[], int numElems, int mNum)
{
    int twoDArray[numElems][numElems];
    int oneDIndex = 0;
    bool isDuplicate = false;

    int placeholder = 0;

    srand((unsigned)time(NULL));

    for(int i = 0; i < numElems * numElems; i++)
    {
        do
        {
            isDuplicate = false;
            placeholder = rand()%mNum;
            for(int z = 0; z < i; z++)
            {
                if(placeholder == oneDArray[z])
                {
                    isDuplicate = true;
                }
            }
            if(!isDuplicate)
            {
               oneDArray[i] = placeholder;
            }
        }while(isDuplicate);
    }

    int oneDCounter = 0;

    cout << "\n\nThe magic square that is created for the size " << numElems << " :";
    for(int j = 0; j < numElems; j++)
    {
        cout << "\n\n\n";
        for(int k = 0; k < numElems; k++)
        {
            twoDArray[j][k] = oneDArray[oneDCounter];
            cout << twoDArray[j][k] << "\t";
            oneDCounter++;
        }
    }
}

bool isMagicSquare(int oneDArray[], int magNumber, int numElems)
{
    int oneDCounter = 0;
    int twoDArray[numElems][numElems];

    for(int j = 0; j < numElems; j++)
    {

        for(int k = 0; k < numElems; k++)
        {
            twoDArray[j][k] = oneDArray[oneDCounter];
            oneDCounter++;
        }
    }
    int rowTotal = 0;
    int colTotal = 0;
    int diagonal1Total = 0;
    int diagonal2Total = 0;
    bool holder = true;
    cout << endl << endl;
    for(int x = 0; x < numElems; ++x)
    {
        for(int y = 0; y < numElems; ++y)
        {
            rowTotal = rowTotal + twoDArray[x][y];

        }
        cout << "Sum of numbers in Row \t#" << x+1 << "\t=\t" << rowTotal << endl;
        if(rowTotal != magNumber)
        {
            holder = false;
        }
        rowTotal = 0;
    }

    cout << endl;

    for(int x = 0; x < numElems; ++x)
    {
        for(int y = 0; y < numElems; ++y)
        {
            colTotal = colTotal + twoDArray[y][x];
        }
        cout << "Sum of number in Column #" << x+1 << "\t=\t" << colTotal << endl;
        if(colTotal != magNumber)
        {
            holder = false;
        }
        colTotal = 0;
    }

    cout << endl;

    for(int x = 0; x < numElems; ++x)
    {
        diagonal1Total = diagonal1Total + twoDArray[x][x];

    }
    cout << "Sum of numbers in first diagonal =\t" << diagonal1Total << endl;

    if(diagonal1Total != magNumber)
    {
        holder = false;
    }

    for(int x = 0; x < numElems; ++x)
    {
        diagonal2Total = diagonal2Total + twoDArray[numElems - 1 - x][x];
    }

    cout << "Sum of numbers in second diagonal =\t" << diagonal2Total << endl;

    if(diagonal2Total != magNumber)
    {
        holder = false;
    }

    return holder;
}


