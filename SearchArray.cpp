#include <iostream>
const int DECLARED_SIZE = 20;

void fillArray(int a[], int size, int& numberUsed);
int search(const int a[], int numberUsed, int target);

int main()
{
    using namespace std;
    int arr[DECLARED_SIZE], listSize, target;

    fillArray(arr, DECLARED_SIZE, listSize);

    char ans;
    int result;
    do {
        cout << "Enter a number to search for: ";
        cin >> target;
        result = search(arr, listSize, target);
        if (result == -1)
            cout << target << " is not on the list.\n";
        else
            cout << target << " is stored in array position " << result << "\n"
                 << "(Remember the first position is 0.)\n";
        cout << "Search again? (y/n followed by return): ";
        cin >> ans;
    } while ((ans != 'n') && (ans != 'N'));

    cout << "End of program";
    return 0;
}

void fillArray(int a[], int size, int& numberUsed)
{
    using namespace std;
    cout << "Enter up to " << size << " non-negative whole numbers" << endl
         << "Mark the end of the list with a negative number\n";
    
    int next, index = 0;
    cin >> next;
    while ((next >= 0) && (index < size))
    {
        a[index] = next;
        index++;
        cin >> next; // Fixed this line
    }
    numberUsed = index;
}

int search(const int a[], int numberUsed, int target)
{
    int index = 0;
    bool found = false;
    while ((!found) && (index < numberUsed))
    {
        if (target == a[index])
            found = true;
        else
            index++;
    }

    if (found)
        return index;
    else
        return -1;
}
