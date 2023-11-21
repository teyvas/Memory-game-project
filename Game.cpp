#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <random>
#include <string>
#include <ctime>
#include <chrono>
#include <termios.h> // Include termios.h for terminal manipulation in Unix-like systems
#include <unistd.h> // Include unistd.h for read()
using namespace std;

 
// Driver code
int main()
{
    
    // Create template of array
    int template_array[] = { 1,1,2,2,3,3,4,4,5,5,6,6,7,7,8,8,9,9,10,10 };
    // Create the integer which will show a size of set of number
    int size_of_game;

    // Start of terminal
    cout<<"Welcome to the Memory Game!"<<endl;
    cout<<"Enter the size of an array(6-20): "; 

    cin>>size_of_game;

    //Hold console
    cin.get();
    // Create new array with players size of game
    int set_of_numbers[size_of_game];

    // Fill new array
    for(int i=0; i<size_of_game;i++)
    {

        set_of_numbers[i]=template_array[i];
    }

    // Size for shuffling
    int n = sizeof(set_of_numbers) / sizeof(set_of_numbers[0]);
    // Random seed
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    
 
    // Shuffling our array
    shuffle(set_of_numbers, set_of_numbers + n, default_random_engine(seed));
 
    //Create strings and fill them with '?'
    string q,w;
    
    for(int i=0; i<size_of_game;i++)
    {
        q.push_back('?');
    }
    for(int i=0; i<size_of_game;i++)
    {
        w.push_back('?');
    }

    // Create bools for ending game in case of win
    bool guess=true, sure=true;
    

    cout<<"Here is the array: "<<q<<endl;
    cout<<endl;
    while(guess==true){
        
        // Just index
        int index; 
        cout<<"Enter the index to show: ";
        cin>>index;
        
        //Second one

        cout<<"The card at index "<<index<<" is: "<<set_of_numbers[index-1]<<endl;
        cout<<endl;

        cin.get(); // Used for keeping terminal open
        int index2;

        cout<<"Enter the second index to show: ";
        cin>>index2;

        cout<<"The card at index "<<index2<<" is: "<<set_of_numbers[index2-1]<<endl;
        
        cout<<endl;
        
        cin.get(); // Used for keeping terminal open
        

        // Check if chosed numbers are same   
        if(set_of_numbers[index-1]== set_of_numbers[index2-1]) /* Wtite "index - 1" because player will not put 0 as index */ 
        {
            q.clear();

            cout<<"Great! The cards are matched!"<<endl;

            cout<<endl;

            for(int i=0; i<size_of_game;i++)
            {
                if(i==index-1 or i==index2-1) // Check if one of indexes are equal to number of string, fill q with this numbers
                {   
                    q.append(to_string(set_of_numbers[index-1]));
                }
                else
                {
                    q.push_back('?');
                }
           
            }
            
        
        }
        else 
        {
            cout<<"The cards do not match. Try again"<<endl;
            cout<<endl;
        }

        int i=0;
        while(i<20){
            if(q[i]!='?'){ // Throw over data from q to w
                w[i]=q[i];
            }
            i++;
        }

        
        char targetChar = '?'; // Specify the character to search for
        sure = false;
        for (char ch : w) {
            if (ch == targetChar) {
                sure = true; // Change the bool variable to false if the character is found
                 // Break out of the loop when the character is found
            }
        }
        
    
        
        if(sure!=true) {
            guess=false;
        }

        cout<<"Press Enter to continue..."<<endl;
        
        
        char ch = std::cin.get(); // Get user input

        if (ch == '\n') { // Check for Enter key
            // Clear screen using escape sequences based on different operating systems
            #ifdef _WIN32
            system("cls"); // For Windows
            #else
            // For Unix-like systems (Linux, macOS)
            std::cout << "\033[2J\033[1;1H"; // ANSI escape codes to clear screen
            std::cout.flush(); // Flush output
            #endif
       
        }

        cout<<w<<endl;
        cout<<endl;


    }

    cout<<"Congratulations!!! You win!";

}
