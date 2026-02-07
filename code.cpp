#include <iostream>
#include<cstring>
using namespace std;
struct Song
{
    int id;
    char title[40];
    char artist[40];
    int duration;
    Song* prev;
    Song* next;
};
Song* start = NULL;
Song* current = NULL;

void insertSong()
{
    Song* temp = new Song;
    cout << "Enter Song ID: ";
    cin >> temp->id;
    cout << "Enter Title: ";
    cin >> temp->title;

    cout << "Enter Artist: ";
    cin >> temp->artist;

    cout << "Enter Duration: ";
    cin >> temp->duration;

    temp->next = NULL;
    temp->prev = NULL;

    if (start == NULL)
    {
        start = temp;
        current = temp;
    }
    else
    {
        Song* cur = start;
        while (cur->next != NULL)
            cur = cur->next;

        cur->next = temp;
        temp->prev = cur;
    }

    cout << "Song Added"<<endl;
}

void searchSong()
{
    char name[40];
    cout << "Enter Title to Search: ";
    cin >> name;

    Song* cur = start;
    while (cur != NULL)
    {
        if (strcmp(cur->title, name) == 0)
        {
            cout << "Song Found\n";
            cout << "ID: " << cur->id << endl;
            cout << "Title: " << cur->title << endl;
            cout << "Artist: " << cur->artist << endl;
            cout << "Duration: " << cur->duration << endl;
            return;
        }
        cur = cur->next;
    }
    cout << "Song Not Found\n";
}

void modifySong()
{
    int id;
    cout << "Enter Song ID to Modify: ";
    cin >> id;

    Song* cur = start;
    while (cur != NULL)
    {
        if (cur->id == id)
        {
            cout << "Enter New Title: ";
            cin >> cur->title;

            cout << "Enter New Artist: ";
            cin >> cur->artist;

            cout << "Enter New Duration: ";
            cin >> cur->duration;

            cout << "Song Updated\n";
            return;
        }
        cur = cur->next;
    }
    cout << "Song Not Found\n";
}

void displaySongs()
{
    Song* cur = start;
    int total = 0;
    int time = 0;

    if (cur == NULL)
    {
        cout << "Playlist Empty\n";
        return;
    }

    while (cur != NULL)
    {
        cout << "ID: " << cur->id << endl;
        cout << "Title: " << cur->title << endl;
        cout << "Artist: " << cur->artist << endl;
        cout << "Duration: " << cur->duration << endl << endl;

        total++;
        time += cur->duration;
        cur = cur->next;
    }

    cout << "Total Songs: " << total << endl;
    cout << "Total Duration: " << time << endl;
}

void playNext()
{
    if (current != NULL && current->next != NULL)
    {
        current = current->next;
        cout << "Now Playing: " << current->title << endl;
    }
    else
    {
        cout << "No Next Song\n";
    }
}

void playPrevious()
{
    if (current != NULL && current->prev != NULL)
    {
        current = current->prev;
        cout << "Now Playing: " << current->title << endl;
    }
    else
    {
        cout << "No Previous Song"<<endl;
    }
}
int main()
{
    int choice;
    do
    {
        cout << "\n1. Insert Song";
        cout << "\n2. Search Song";
        cout << "\n3. Modify Song";
        cout << "\n4. Display Songs";
        cout << "\n5. Play Next";
        cout << "\n6. Play Previous";
        cout << "\n7. Exit";
        cout << "\nEnter Choice: ";
        cin >> choice;

        if (choice == 1)
            insertSong();
        else if (choice == 2)
            searchSong();
        else if (choice == 3)
            modifySong();
        else if (choice == 4)
            displaySongs();
        else if (choice == 5)
            playNext();
        else if (choice == 6)
            playPrevious();

    } while (choice != 7);

    return 0;
}
