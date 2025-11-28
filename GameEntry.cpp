#include <iostream>
#include <string>
using namespace std;

// Custom exception class to match "throw(IndexOutOfBounds)" in notes
class IndexOutOfBounds {};

// ---------------- GameEntry Class ----------------
class GameEntry { // a game score entry
public:
    GameEntry(const string &n = "", int s = 0); // constructor
    string getName() const; // get player name
    int getScore() const;   // get score

private:
    string name; // player’s name
    int score;   // player’s score
};

// constructor
GameEntry::GameEntry(const string &n, int s) : name(n), score(s) {}

// accessors
string GameEntry::getName() const { return name; }
int GameEntry::getScore() const { return score; }

// ---------------- Scores Class ----------------
class Scores { // stores game high scores
public:
    Scores(int maxEnt = 10); // constructor
    ~Scores();               // destructor
    void add(const GameEntry &e); // add a game entry
    GameEntry remove(int i) throw(IndexOutOfBounds); // remove the ith entry

    void printScores(); // helper to print scores

private:
    int maxEntries;   // maximum number of entries
    int numEntries;   // actual number of entries
    GameEntry* entries; // array of game entries
};

// constructor
Scores::Scores(int maxEnt) {
    maxEntries = maxEnt;                 // save the max size
    entries = new GameEntry[maxEntries]; // allocate array storage
    numEntries = 0;                      // initially no elements
}

// destructor
Scores::~Scores() {
    delete [] entries;
}

// add a game entry
void Scores::add(const GameEntry& e) {
    int newScore = e.getScore(); // score to add
    if (numEntries == maxEntries) { // the array is full
        if (newScore <= entries[maxEntries-1].getScore())
            return; // not high enough - ignore
    }
    else numEntries++; // if not full, one more entry

    int i = numEntries - 2; // start with the next to last
    while (i >= 0 && newScore > entries[i].getScore()) {
        entries[i+1] = entries[i]; // shift right if smaller
        i--;
    }
    entries[i+1] = e; // put e in the empty spot
}

// remove a game entry
GameEntry Scores::remove(int i) throw(IndexOutOfBounds) {
    if ((i < 0) || (i >= numEntries)) // invalid index
        throw IndexOutOfBounds(); // throw custom exception

    GameEntry e = entries[i]; // save the removed object
    for (int j = i+1; j < numEntries; j++)
        entries[j-1] = entries[j]; // shift entries left
    numEntries--; // one fewer entry
    return e; // return the removed object
}

// print scores
void Scores::printScores() {
    cout << "Scores: ";
    for (int i = 0; i < numEntries; i++) {
        cout << "(" << entries[i].getName() << "," << entries[i].getScore() << ") ";
    }
    cout << endl;
}

// ---------------- Insertion Sort ----------------
void insertionSort(char* A, int n) { // sort an array of n characters
    for (int i = 1; i < n; i++) { // insertion loop
        char cur = A[i];          // current character to insert
        int j = i - 1;            // start at previous character
        while ((j >= 0) && (A[j] > cur)) { // while A[j] is out of order
            A[j + 1] = A[j];      // move A[j] right
            j--;                  // decrement j
        }
        A[j + 1] = cur;           // this is the proper place for cur
    }
}

// ---------------- Main ----------------
int main() {
    Scores s(5);

    // Add values
    s.add(GameEntry("Mike", 1105));
    s.add(GameEntry("Rob", 750));
    s.add(GameEntry("Jill", 740));
    s.add(GameEntry("Paul", 720));
    s.add(GameEntry("Anna", 660));
    s.printScores();

    // Array full: ignored
    s.add(GameEntry("Low", 100));
    s.printScores();

    // Higher than last: inserted
    s.add(GameEntry("NewHigh", 800));
    s.printScores();

    // Remove valid index
    try {
        GameEntry removed = s.remove(3);
        cout << "Removed: " << removed.getName() << endl;
        s.printScores();
    } catch (IndexOutOfBounds&) {
        cout << "Invalid index remove!" << endl;
    }

    // Remove invalid index
    try {
        s.remove(10);
    } catch (IndexOutOfBounds&) {
        cout << "Caught invalid index remove!" << endl;
    }

    // Insertion Sort
    char arr[] = {'C','B','A','E','D'};
    int n = 5;
    insertionSort(arr, n);
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) cout << arr[i] << " ";
    cout << endl;

    return 0;
}
