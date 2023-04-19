/*  Objective: Implement a queue in C++ that can do the following:
        1. Insert a new element at the rear of the queue
        2. Remove the front element of the queue and returns it.
        3. Returns the front element present in the queue without removing it.
        4. Checks if the queue is empty.
        5. Returns the total number of elements present in the queue
-------------------------------------------------------------------------------
    Progress: COMPLETE!
-------------------------------------------------------------------------------
*/

#include <queue>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    queue<string> elements;     // Primary Queue used for Elements input by user
    queue<string> elements1;    // Second Queue used for Transitioning Elements in 1st Queue back into pre-removal order
    string object;              // Rather than using elements as the name of the variable, use object for reduced confusion/errors
    char confirm;               // Confirmation String for User to be used in confirming user intent
    string removed;             // String Element in question that may be removed upon confirmation by user
    int option = 0;
    string options[] = { "Insert", "Delete Front Element", "Front of Queue", "Checking Queue" , "Empty?" , "Quit"};
    const int NUM_OPTIONS = 6;

    // Perform all operations selected by user.
    while (option < NUM_OPTIONS - 1)
    {
        cout << "Select an operation on your queue\n";
        for (int i = 0; i < NUM_OPTIONS; i++)
            cout << i << ": " << options[i] << endl;

        cin >> option;
        switch (option) {
        case 0:                                             // This is the Insertion Option (0)
            cout << "\nEnter new Element in your queue\n";
            cin >> object;
            elements.push(object);
            cout << "\n";
            break;
        case 1:                                             // This is the Deletion Option (1)
            removed = elements.front();
            elements.pop();
            cout << "\nElement " << removed << " is at the front of the queue. Would you like to delete it? Y/N\n";
            cin >> confirm;
            while (confirm != 'Y' || confirm != 'N') {
                switch (confirm) {
                case 'Y':                                       // Should the user decide to want to delete the front element in the queue
                    cout << "\nElement " << removed << " has been deleted from the queue.\n\n";
                    removed = "";
                    break;
                case 'N':                                       // Should the user decicde to NOT want to delete the front element in the queue
                    cout << "\nReinserting Element back into front of queue.\n";
                    elements1.push(removed);
                    while (elements.size() != 0) {             //Moves all elements except for removed to 2nd Queue
                        object = elements.front();
                        elements1.push(object);
                        elements.pop();
                    }
                    while (elements1.size() != 0) {             //Moves all elements from 2nd Queue back to OG Queue, basically resetting queue order to prior to removal option
                        object = elements1.front();
                        elements.push(object);
                        elements1.pop();
                    }
                    cout << "Element " << elements.front() << " is now at the front of the queue.\n\n";
                    removed = "";
                    break;
                default:                                        // In the event of poor/accidental input on user's side
                    cout << "\nInput not recognized. Please enter Y (Yes) or N (No) to confirm deletion.";
                    cout << "\nElement " << removed << " is at the front of the queue. Would you like to delete it? Y/N\n";
                    cin >> confirm;
                    break;
                }
                break;
            }
            break;
        case 2:                                             // This is the Check Front of Queue Option (2)
            cout << "\nElement " << elements.front() << " is at the front of the queue.\n\n";
            break;
        case 3:                                             // This is the Check Queue Size Option (3)
            cout << "\nQueue is current at a size of " << elements.size() << "\n\n";
            break;
        case 4:                                             // This is to check if the Queue is empty (4)
            if (elements.empty())
                cout << "\nQueue is currently empty.\n" << endl;
            else
                cout << "\nQueue is not currently empty.\n" << endl;
            break;
        case 5:                                             // This quits the program outright (5)
            exit(0);
        default:                                            // In case of poor/accidental input on user's side
            cout << "\nInvalid input. Please try again\n\n";
            break;
        }
    }
}
