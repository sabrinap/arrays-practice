/* Name: Sabrina Pinera
Date: 11/06/18
Section: 5
Assignment: Homework 5
Due Date: 11/06/18
About this project: To gain practice with arrays and common array algorithms,
                    as well as the use of array parameters in functions.
Assumptions: I assume the correct user input and output will be displayed

All work below was performed by Sabrina Pinera*/
//libraries
#include <iostream>
#include <cstdlib> // for srand and rand
#include <ctime> // for time
using namespace std;

/*Given Function prototypes*/
void PrintArray (const int arr[], const int SIZE);
/* Add your own function prototypes here*/
void PrintMenu();
void FillArray(int arr[], const int SIZE, int min, int max);
void InsertArray(int arr[], const int SIZE, int value_insert, int index_insert);
void DeleteArray(int arr[], const int SIZE, int delete_choice);
void ReverseArray(int arr[], const int SIZE);
int MaxOddArray(int arr[], const int SIZE);

int main()
{
   /* We'll set the test size to 15.  Use this constant in your calls
    *  instead of the literal 15.  Then, by changing this line, you can
    *  easily test arrays of different sizes. */
   const int SIZE = 15;
   char choice;
   int min, max;
   int arr[SIZE];
   int value_insert, index_insert;
   int delete_choice;

   srand ((unsigned int)time(0)); //seeding function, called only ONCE. @ the beginning

   /*Loop that presents user with menu options and calls appropriate Array functions*/
   /*Note: you can assume the user will call Fill Array function first so that the array has data in it to begin*/
    PrintMenu();
    do
    {
        cout << "Enter your menu selection: ";
        cin >> choice;

    //switch statement to create the list
            switch(choice)
            {
                case 'P' : case 'p':
                {
                    //Prints out array
                    PrintArray(arr, SIZE);
		    cout << "\n";
                 break; }

                case 'F' : case 'f':
                {
                    //user input for the min and max
                    cout << "What is the minimum random value? ";
                    cin >> min;
                    cout << "What is the maximum random value? ";
                    cin >> max;

                    //If min is greater than max create a loop to show error
                        while (min >= max)
                        {
                            cout << "ERROR min can not be greater than max!\n";
                            cout << "Try again!\n\n";
                            cout << "What is the minimum random value? ";
                            cin >> min;
                            cout << "What is the maximum random value? ";
                            cin >> max;
                        }

                    FillArray(arr, SIZE, min, max);
                    PrintArray(arr, SIZE);
                    cout << "\n";
                break; }

                case 'I' : case 'i':
                {
                    //input from user for the value & index
                    cout << "Enter value to insert: ";
                    cin >> value_insert;
                    cout << "Enter index at which to insert: ";
                    cin >> index_insert;
                    InsertArray(arr, SIZE, value_insert, index_insert);
                    PrintArray(arr, SIZE);
		    cout << "\n";
                break; }

                case 'D' : case 'd':
                {
                    //Input to delete a number in the array
                    cout << "Enter index of item to delete: ";
                    cin >> delete_choice;
                    DeleteArray(arr, SIZE, delete_choice);
                    PrintArray(arr, SIZE);
		    cout << "\n";
                break; }

                case 'R' : case 'r':
                {
                    //Reverse entire array given after any changes were done
                    ReverseArray(arr, SIZE);
                    PrintArray(arr, SIZE);
		    cout << "\n";
                break; }

                case 'X' : case 'x':
                {
                    //do not need to print array
                    cout << "The maximum odd value is ";
                    cout << MaxOddArray(arr, SIZE);
		    cout << "\n\n";
                break; }

                case 'M' : case 'm':
                {
                    //Print menu again
                    PrintMenu();
                break; }
            }

    } while(choice != 'Q' && choice != 'q'); //quits program
	PrintArray(arr, SIZE);
   return 0;
}	            // end main()


/* Definition of PrintArray below DO NOT CHANGE!*/
//PrintArray Function
//This function prints the contents of any interger array of any size seperated by commas
void PrintArray(const int arr[], const int SIZE)
{
   cout << "\nThe array:\n { ";
   for (int i = 0; i < SIZE-1; i++)	// for loop, prints each item (not last due to comma handling)
      cout << arr[i] << ", ";

   cout << arr[SIZE-1] << " }\n";	// prints last item , sans comma
}

void FillArray(int arr[], const int SIZE, int min, int max)
{
    for (int i = 0; i < SIZE; i++)
    {
       //creates the rand #'s after min and max are given
        arr[i] = rand() % (max - min) + min;
    }
}

void InsertArray(int arr[], const int SIZE, int value_insert, int index_insert)
{
  	//changes the number after insert & index are given
        for(int i = SIZE-1; i > index_insert; i--)
        {
             arr[i] = arr[i-1];
        }
             arr[index_insert] = value_insert;
}

void DeleteArray(int arr[], const int SIZE, int delete_choice)
{
    //Deletes # when user gives input
    for(int i = delete_choice; i < SIZE - 1; i++)
    {
        arr[i] = arr[i+1];
    }
	arr[SIZE-1] = 0;
}

void ReverseArray(int arr[], const int SIZE)
{
   int temp;
    //Reverses the array
    for (int i = 0; i < SIZE/2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[SIZE-i-1];
        arr[SIZE-i-1] = temp;
    }

}

int MaxOddArray(int arr[], const int SIZE)
{
    //confirmed int is needed for the function and not void
    //function MaxOdd finds the largest odd nunmber in the array
    int maxOdd;
    for (int i = 0; i <= SIZE-1; i++)
    {
        if ((arr[i] > maxOdd) && (arr[i] % 2 == 1))
        maxOdd = arr[i];
    }
    return maxOdd;
}

void PrintMenu()
{
    //Menu
    cout << "\t** Given features **\n";
    cout << "P	Print the array contents\n\n";

     cout << "\t** Function Tests **\n";
     cout << "F	Fill the array with random values\n";
     cout << "I	Insert\n";
     cout << "D	Delete\n";
     cout << "R	Reverse\n";
     cout << "X	Max Odd Value\n\n\n";


     cout << "M	Print this menu\n";
     cout << "Q	Quit this program\n\n";

}
