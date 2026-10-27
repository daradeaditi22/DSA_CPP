
// Music Playlist Manager - Doubly Linked List (C++)
// p       -> new node / node to be deleted
// q       -> traversal pointer
// head    -> first song of the playlist
// current -> song that is currently selected / playing
// prev, next -> links stored inside every song node

#include <iostream>
#include <string>
#include <limits>
using namespace std;

class song
{
public:
    song *prev;
    song *next;
    string title;
    string artist;

    song(string x, string y)
    {
        prev = NULL;
        next = NULL;
        title = x;
        artist = y;
    }
};

class playlist
{
private:
    song *head;

public:
    song *current;

    playlist()
    {
        head = NULL;
        current = NULL;
    }

    bool empty()
    {
        return head == NULL;
    }

    void insert(string x, string y)
    {
        song *p = new song(x, y);

        if (empty())
        {
            head = p;
            current = head;
        }
        else
        {
            song *q = head;

            while (q->next != NULL)
                q = q->next;

            q->next = p;
            p->prev = q;
        }

        cout << "Song added successfully!" << endl;
    }

    void remove(string x)
    {
        if (empty())
        {
            cout << "Playlist is Empty" << endl;
            return;
        }

        song *q = head;

        while (q != NULL)
        {
            if (q->title == x)
            {
                if (q->prev != NULL)
                    q->prev->next = q->next;
                else
                    head = q->next;

                if (q->next != NULL)
                    q->next->prev = q->prev;

                if (current == q)
                    current = (q->next != NULL) ? q->next : q->prev;

                delete q;
                cout << "Song deleted successfully!" << endl;
                return;
            }

            q = q->next;
        }

        cout << "Song '" << x << "' Not Found in playlist" << endl;
    }

    void play(string x)
    {
        if (current == NULL)
        {
            cout << "Playlist is Empty" << endl;
            return;
        }

        if (x == "next")
        {
            if (current->next == NULL)
            {
                cout << "Last Song (Cannot play next)" << endl;
                return;
            }

            current = current->next;
        }
        else if (x == "previous")
        {
            if (current->prev == NULL)
            {
                cout << "First Song (Cannot play previous)" << endl;
                return;
            }

            current = current->prev;
        }

        cout << "Current Song playing: " << current->title
             << " - " << current->artist << endl;
    }

    void showCurrent()
    {
        if (current == NULL)
        {
            cout << "Playlist is Empty" << endl;
            return;
        }

        cout << "Previous : ";
        if (current->prev != NULL)
            cout << current->prev->title << endl;
        else
            cout << "NULL" << endl;

        cout << "Current  : " << current->title << " - " << current->artist << endl;

        cout << "Next     : ";
        if (current->next != NULL)
            cout << current->next->title << endl;
        else
            cout << "NULL" << endl;
    }

    void playCompletePlaylist()
    {
        if (empty())
        {
            cout << "Playlist is Empty" << endl;
            return;
        }

        song *q = head;

        while (q != NULL)
        {
            current = q;
            cout << "Current Song playing: " << q->title
                 << " - " << q->artist << endl;
            q = q->next;
        }
    }

    void repeatAll(int repetitions)
    {
        if (empty())
        {
            cout << "Playlist is Empty" << endl;
            return;
        }

        if (repetitions <= 0)
        {
            cout << "Enter a positive number of repetitions." << endl;
            return;
        }

        for (int i = 1; i <= repetitions; i++)
        {
            cout << "\nRepetition " << i << ":" << endl;

            song *q = head;

            while (q != NULL)
            {
                current = q;
                cout << "Current Song playing: " << q->title
                     << " - " << q->artist << endl;
                q = q->next;
            }
        }
    }

    void displayforward()
    {
        if (empty())
        {
            cout << "Playlist is Empty" << endl;
            return;
        }

        song *q = head;

        cout << "Forward Display:" << endl;

        while (q != NULL)
        {
            cout << q->title << " - " << q->artist;

            if (q->next != NULL)
                cout << " <=> ";

            q = q->next;
        }

        cout << endl;
    }

    void displaybackward()
    {
        if (empty())
        {
            cout << "Playlist is Empty" << endl;
            return;
        }

        song *q = head;

        while (q->next != NULL)
            q = q->next;

        cout << "Backward Display:" << endl;

        while (q != NULL)
        {
            cout << q->title << " - " << q->artist;

            if (q->prev != NULL)
                cout << " <=> ";

            q = q->prev;
        }

        cout << endl;
    }

    ~playlist()
    {
        song *q = head;

        while (q != NULL)
        {
            song *temp = q;
            q = q->next;
            delete temp;
        }
    }
};

int main()
{
    playlist p;
    int choice;
    string title, artist;

    do
    {
        cout << "\n===== MUSIC PLAYLIST =====" << endl;
        cout << "1. Add Song" << endl;
        cout << "2. Delete Song" << endl;
        cout << "3. Display Playlist in Forward" << endl;
        cout << "4. Display Playlist in Reverse" << endl;
        cout << "5. Play Current Song" << endl;
        cout << "6. Play Next Song" << endl;
        cout << "7. Play Previous Song" << endl;
        cout << "8. Play Complete Playlist" << endl;
        cout << "9. Repeat All" << endl;
        cout << "10. Show Current Song" << endl;
        cout << "11. Exit" << endl;

        cout << "Enter your choice: ";
        if (!(cin >> choice))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Please enter a number!" << endl;
            choice = 0;
            continue;
        }

        switch (choice)
        {
        case 1:
            cout << "Enter song title: ";
            getline(cin >> ws, title);

            cout << "Enter artist name: ";
            getline(cin >> ws, artist);

            p.insert(title, artist);
            break;

        case 2:
            cout << "Enter song title to delete: ";
            getline(cin >> ws, title);

            p.remove(title);
            break;

        case 3:
            p.displayforward();
            break;

        case 4:
            p.displaybackward();
            break;

        case 5:
            p.play("current");
            break;

        case 6:
            p.play("next");
            break;

        case 7:
            p.play("previous");
            break;

        case 8:
            p.playCompletePlaylist();
            break;

        case 9:
        {
            int repetitions;

            cout << "Enter number of repetitions: ";
            if (cin >> repetitions)
                p.repeatAll(repetitions);
            else
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Enter a positive number of repetitions." << endl;
            }
            break;
        }

        case 10:
            p.showCurrent();
            break;

        case 11:
            cout << "Exiting..." << endl;
            break;

        default:
            cout << "Invalid choice!" << endl;
        }

    } while (choice != 11);

    return 0;
}
/*
PS D:\Darade Aditi 121> & "D:\Darade Aditi 121\musicplayer.exe"

===== MUSIC PLAYLIST =====
1. Add Song
2. Delete Song
3. Display Playlist in Forward
4. Display Playlist in Reverse
5. Play Current Song
6. Play Next Song
7. Play Previous Song
8. Play Complete Playlist
9. Repeat All
10. Show Current Song
11. Exit
Enter your choice: 1
Enter song title: shape  of you
Enter artist name: xyz
Song added successfully!

===== MUSIC PLAYLIST =====
1. Add Song
2. Delete Song
3. Display Playlist in Forward
4. Display Playlist in Reverse
5. Play Current Song
6. Play Next Song
7. Play Previous Song
8. Play Complete Playlist
9. Repeat All
10. Show Current Song
11. Exit
Enter your choice: 1
Enter song title: believer
Enter artist name: xyz
Song added successfully!

===== MUSIC PLAYLIST =====
1. Add Song
2. Delete Song
3. Display Playlist in Forward
4. Display Playlist in Reverse
5. Play Current Song
6. Play Next Song
7. Play Previous Song
8. Play Complete Playlist
9. Repeat All
10. Show Current Song
11. Exit
Enter your choice: 2
Enter song title to delete: believer
Song deleted successfully!

===== MUSIC PLAYLIST =====
1. Add Song
2. Delete Song
3. Display Playlist in Forward
4. Display Playlist in Reverse
5. Play Current Song
6. Play Next Song
7. Play Previous Song
8. Play Complete Playlist
9. Repeat All
10. Show Current Song
11. Exit
Enter your choice: 1
Enter song title: believer 
Enter artist name: xyz
Song added successfully!

===== MUSIC PLAYLIST =====
1. Add Song
2. Delete Song
3. Display Playlist in Forward
4. Display Playlist in Reverse
5. Play Current Song
6. Play Next Song
7. Play Previous Song
8. Play Complete Playlist
9. Repeat All
10. Show Current Song
11. Exit
Enter your choice: faded 
Please enter a number!

===== MUSIC PLAYLIST =====
1. Add Song
2. Delete Song
3. Display Playlist in Forward
4. Display Playlist in Reverse
5. Play Current Song
6. Play Next Song
7. Play Previous Song
8. Play Complete Playlist
9. Repeat All
10. Show Current Song
11. Exit
Enter your choice: 1
Enter song title: perfect
Enter artist name: xyz
Song added successfully!

===== MUSIC PLAYLIST =====
1. Add Song
2. Delete Song
3. Display Playlist in Forward
4. Display Playlist in Reverse
5. Play Current Song
6. Play Next Song
7. Play Previous Song
8. Play Complete Playlist
9. Repeat All
10. Show Current Song
11. Exit
Enter your choice: 8
Current Song playing: shape  of you - xyz
Current Song playing: believer  - xyz
Current Song playing: perfect - xyz

===== MUSIC PLAYLIST =====
1. Add Song
2. Delete Song
3. Display Playlist in Forward
4. Display Playlist in Reverse
5. Play Current Song
6. Play Next Song
7. Play Previous Song
8. Play Complete Playlist
9. Repeat All
10. Show Current Song
11. Exit
Enter your choice: 
*/