#include <iostream>
using namespace std;
struct Song {
    int id;
    string title;
    string artist;
    float duration;

    Song* next;
    Song* prev;
};
Song* start = NULL;
Song* current = NULL;
void insertSong() {

    Song* temp = new Song;
    cout << "\nEnter Song ID: ";
    cin >> temp->id;
    cout << "Enter Song Title: ";
    cin >> temp->title;
    cout << "Enter Artist Name: ";
    cin >> temp->artist;
    cout << "Enter Duration: ";
    cin >> temp->duration;

    temp->next = NULL;
    temp->prev = NULL;

    if (start == NULL) {
        start = temp;
        current = temp;
    } 
    else {
        Song* t = start;
        while (t->next != NULL)
            t = t->next;

        t->next = temp;
        temp->prev = t;
    }
    cout << "Song inserted!\n";
}
Song* searchSong(string key) {
    Song* temp = start;

    while (temp != NULL) {
        if (temp->title == key || temp->artist == key)
            return temp;
        temp = temp->next;
    }
    return NULL;
}
void modifySong() {
    string key;
    cout << "\nEnter Title OR Artist to modify: ";
    cin >> key;

    Song* temp = searchSong(key);

    if (temp == NULL) {
        cout << "Song not found!\n";
        return;
    }

    cout << "Enter New Title: ";
    cin >> temp->title;

    cout << "Enter New Artist: ";
    cin >> temp->artist;

    cout << "Enter New Duration: ";
    cin >> temp->duration;

    cout << "Song updated!\n";
}
void displayPlaylist() {

    if (start == NULL) {
        cout << "\nPlaylist empty!\n";
        return;
    }

    Song* temp = start;
    int count = 0;
    float total = 0;

    cout << "\nPlaylist\n";

    while (temp != NULL) {
        cout << "ID: " << temp->id << "\n";
        cout << "Title: " << temp->title << "\n";
        cout << "Artist: " << temp->artist << "\n";
        cout << "Duration: " << temp->duration << "\n\n";

        count++;
        total += temp->duration;

        temp = temp->next;
    }

    cout << "Total Songs: " << count << "\n";
    cout << "Total Duration: " << total << "\n";
}
void playNext() {
    if (current == NULL) {
        cout << "No songs!\n";
        return;
    }

    if (current->next == NULL) {
        cout << "Already last song!\n";
    }
    else {
        current = current->next;
        cout << "Playing: " << current->title << "\n";
    }
}
void playPrevious() {
    if (current == NULL) {
        cout << "No songs!\n";
        return;
    }
    if (current->prev == NULL) {
        cout << "Already first song!\n";
    }
    else {
        current = current->prev;
        cout << "Playing: " << current->title << "\n";
    }
}
int main() {
    int ch;
    do {
        cout << "\n1. Insert\n";
        cout << "2. Search\n";
        cout << "3. Modify\n";
        cout << "4. Display\n";
        cout << "5. Play Next\n";
        cout << "6. Play Previous\n";
        cout << "7. Exit\n";

        cout << "Enter choice: ";
        cin >> ch;

        switch (ch) {

            case 1: insertSong(); break;

            case 2: {
                string key;
                cout << "Enter Title OR Artist to search: ";
                cin >> key;
                Song* temp = searchSong(key);

                if (temp == NULL)
                    cout << "Song not found!\n";
                else
                    cout << "Song Found: " << temp->title << "\n";
                break;
            }
            case 3: modifySong();
			   break;
            case 4: displayPlaylist();
			   break;

            case 5: playNext();
			  break;
            case 6: playPrevious(); 
			   break;
            case 7: cout << "Exiting\n";
			   break;
            default: cout << "Invalid choice!\n";
        }
    } while (ch != 7);
    return 0;
}
