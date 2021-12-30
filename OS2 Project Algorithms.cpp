#include <iostream>
using namespace std;
void FIFOAlgo() {
    int pages[100], framenum, pagesnum;
    cout << "  Please enter the number of pages : ";
    cin >> pagesnum;  //number of pages 
    cout << "Please enter the page numbers:  " << endl;
    for (int i = 1; i <= pagesnum; i++)
        cin >> pages[i];
    //1st array
    cout << "Pleasee enter the Number of frames : ";
    cin >> framenum; //number of frames 
    int j = 0, frame[10], avail = 0, counter = 0;
    cout << "the page numbers you entered are:" << "   ";
    for (int i = 1; i <= pagesnum; i++)
    {
        cout << pages[i] << "     ";
    }
    cout << endl;
    for (int i = 0; i < framenum; i++) //number of frames 
        frame[i] = -1;  //2nd array initially -1
    j = 0;

    cout << "page frames\n";

    for (int i = 1; i <= pagesnum; i++)
    {
        avail = 0;
        for (int k = 0; k < framenum; k++) //number of frames 
            if (frame[k] == pages[i])
                avail = 1;
        if (avail == 0)
        {
            frame[j] = pages[i];
            j = (j + 1) % framenum; //number of frames 
            counter++;
            for (int k = 0; k < framenum; k++)  //number of frames 
                cout << "\t" << frame[k];
        }
        cout << endl;
    }
    cout << "Page Fault Is :" << counter;
    cout << endl;

}

void LRUAlgo() {
    int pagesnum, framenum;
    int pages[100];
    int pages2[100], tcount[100], counter = 0;
    cout << " Please enter the number of pages : ";
    cin >> pagesnum;

    cout << "Please enter the page numbers: ";
    for (int i = 0; i < pagesnum; i++)
    {
        cout << endl;
        cin >> pages[i];
    }
    cout << endl;
    cout << "Pleasee enter the Number of frames : ";
    cin >> framenum;
    cout << endl;

    cout << "the page numbers you entered are:" << "   ";
    for (int i = 0; i < pagesnum; i++)
    {
        cout << pages[i] << "     ";
    }
    cout << endl;
    for (int i = 0; i < framenum; i++)
    {
        pages2[i] = -1;
        tcount[i] = 0;
    }
    int i = 0;
    cout << "page frames\n";
    while (i < pagesnum) //tany mara hanodkhol 3ala hena 3alatol
    {
        int j = 0, flag = false;
        while (j < framenum)
        {
            if (pages[i] == pages2[j]) {  //it will check whether the page already exist in frames or not
                flag = true;
                tcount[j] = i + 1;  //?
            }
            j++;
        }
        j = 0;
        cout << endl;
        if (!flag)
        {
            int min = 0, k = 0;
            while (k < framenum - 1)
            {
                if (tcount[min] > tcount[k + 1]) //It will calculate the page which is least recently used
                    min = k + 1;
                k++;
            }
            pages2[min] = pages[i];
            tcount[min] = i + 1;  //Increasing the time
            counter++;           //it will count the total Page Fault

            while (j < framenum)
            {
                cout << pages2[j] << endl;

                j++;
            }

        }
        i++;

    }
    cout << endl;
    cout << "number of page fault : " << counter;
    cout << endl;

}

void OptimalAlgo() {
    int framenum, pagesnum, ArrayOfFrame[100], pages[100],
        fcount[100], position, maximum, counter = 0;
    bool flagpages, flagframe, flagfcount;
    cout << " Please enter the number of pages : ";
    cin >> pagesnum;

    cout << "Please enter the page numbers: ";

    for (int q = 0; q < pagesnum; q++)
    {
        cout << endl;
        cin >> pages[q];
    }
    cout << endl;
    cout << "Pleasee enter the Number of frames : ";
    cin >> framenum;
    cout << endl;

    cout << "the page numbers you entered are:" << "   ";

    for (int q = 0; q < pagesnum; q++)
    {
        cout << pages[q] << "     ";
    }
    cout << endl;

    for (int q = 0; q < framenum; q++) {
        ArrayOfFrame[q] = -1;
    }

    for (int q = 0; q < pagesnum; q++) {
        flagpages = false;
        flagframe = false;

        for (int p = 0; p < framenum; p++) {
            if (ArrayOfFrame[p] == pages[q]) {
                flagpages = true;
                flagframe = true;
                break;
            }
        }

        if (flagpages == false) {

            for (int p = 0; p < framenum; p++) {
                if (ArrayOfFrame[p] == -1) {
                    counter++;
                    ArrayOfFrame[p] = pages[q];
                    flagframe = true;
                    break;
                }
            }
        }

        if (flagframe == false) {
            flagfcount = false;

            for (int p = 0; p < framenum; p++) {
                fcount[p] = -1;

                for (int m = q + 1; m < pagesnum; m++) {
                    if (ArrayOfFrame[p] == pages[m]) {
                        fcount[p] = m;
                        break;
                    }
                }
            }

            for (int p = 0; p < framenum; p++) {
                if (fcount[p] == -1) {
                    position = p;
                    flagfcount = true;
                    break;
                }
            }

            if (flagfcount == false) {
                maximum = fcount[0];
                position = 0;

                for (int p = 1; p < framenum; p++) {
                    if (fcount[p] > maximum) {
                        maximum = fcount[p];
                        position = p;
                    }
                }
            }
            ArrayOfFrame[position] = pages[q];
            counter++;
        }

        cout << endl;

        for (int p = 0; p < framenum; p++) {
            cout << ArrayOfFrame[p] << "       ";
        }
    }
    cout << endl;
    cout << "number of page fault : " << counter;
    cout << endl;
}
int main()
{

    int choice = 0;
    cout << "Please enter the number of the algorithm you want to use: " << endl;
    cout << "1. FIFO" << endl << "2. LRU" << endl << "3. Optimal" << endl;
    cout << "your choice is: ";

    cin >> choice;
    cout << endl;
    if (choice == 1) {
        FIFOAlgo();

    }
    else if (choice == 2) {
        LRUAlgo();
    }
    else if (choice == 3) {

        OptimalAlgo();
    }
    else {
        cout << "enter valid number and try again";
    }

}