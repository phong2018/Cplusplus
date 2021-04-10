#include <iostream>
#include <iomanip>
using namespace std;

#include "PlaylistNode.h"

using namespace std;

void PrintMenu(const string playlistTitle) {
   char menuOp = ' ';
   string uniqueID;
   string songName;
   string artistName;
   int songLength = 0;
   int numNodes = 0;
   int songPosition = 0;
   int newPosition = 0;
   int totalTime;
   PlaylistNode* newSong = 0;
   PlaylistNode* currNode = 0;
   PlaylistNode* songNode = 0;
   PlaylistNode* prevNode = 0;
   PlaylistNode* insertPosNode = 0;
   PlaylistNode* headNode = 0;
   PlaylistNode* tailNode = 0;
   PlaylistNode* currPrintNode = 0;


   // Output menu option, prompt users for valid selection
   while(menuOp != 'q') {
      menuOp = ' ';
      cout << playlistTitle << " PLAYLIST MENU" << endl;
      cout << "a - Add song" << endl;
      cout << "d - Remove song" << endl;
      cout << "c - Change position of song" << endl;
      cout << "s - Output songs by specific artist" << endl;
      cout << "t - Output total time of playlist (in seconds)" << endl;
      cout << "o - Output full playlist" << endl;
      cout << "q - Quit" << endl << endl;

      while (menuOp != 'a' && menuOp != 'd' && menuOp != 'c' &&
             menuOp != 's' && menuOp != 't' && menuOp != 'o' && menuOp != 'q') {
         cout << "Choose an option:" << endl;
         cin >> menuOp;
      }

      // Call corresponding menu action
      switch (menuOp) {
         case 'a':
            // Prompt user for song information
            cout << "ADD SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            cin >> uniqueID;

            cin.ignore();
            cout << "Enter song's name:" << endl;
            getline(cin, songName);

            cout << "Enter artist's name:" << endl;
            getline(cin, artistName);

            cout << "Enter song's length (in seconds):" << endl;
            cin >> songLength;

            // Create a new node for playlist
            newSong = new PlaylistNode(uniqueID, songName, artistName, songLength);

            // If song is first in playlist, update head/tail
            // Otherwise insert to end of playlist and update tail
            if (headNode == 0) {
               headNode = newSong;
               tailNode = newSong;
            }
            else {
               tailNode->InsertAfter(newSong);
               tailNode = tailNode->GetNext();
            }
            cout << endl;

            break;


         case 'd':
            // Output playlist messaging
            cout << "REMOVE SONG" << endl;
            cout << "Enter song's unique ID:" << endl;
            cin >> uniqueID;

            // Count number of nodes in list
            songNode = headNode;

            // songNode is the song to be removed
            while ((songNode != 0) && !(songNode->GetID() == uniqueID)) {
               songNode = songNode->GetNext();
            }

            if (songNode == 0 ) {
               // ERROR: songPosition provided by user is invalid
               // Do nothing
            }
            else {
               // Remove song at songPosition from list

               // If songPosition is 1, list head is removed
               if (songNode == headNode) {
                  headNode = songNode->GetNext();
               }
               else {
                  // prevNode refers to node before the songNode
                  prevNode = headNode;
                  while (prevNode->GetNext() != songNode) {
                     prevNode = prevNode->GetNext();
                  }

                  // prevNode updated so next is the node following songNode
                  prevNode->SetNext(songNode->GetNext());

                  if (songNode == tailNode) {
                     tailNode = prevNode;
                  }
               }

               cout << "\"" << songNode->GetSongName() << "\" removed." << endl << endl;
            }

            break;


         case 'c':
            // Prompt user to new song location
            cout << "CHANGE POSITION OF SONG" << endl;
            cout << "Enter song's current position:" << endl;
            cin >> songPosition;

            cout << "Enter new position for song:" << endl;
            cin >> newPosition;

            // Count number of nodes in list
            songNode = headNode;
            numNodes = 0;

            // songNode is the song to be moved
            while ((songNode != 0) && (numNodes < (songPosition - 1))) {
               ++numNodes;
               songNode = songNode->GetNext();
            }

            if (songNode == 0 ) {
               // ERROR: songPosition provided by user is invalid
               // Do nothing
            }
            else {

               // STEP 1: Remove song at songPosition from list. Keep reference to that song.

               // If songPosition is 1, list head is removed
               if (songNode == headNode) {
                  headNode = songNode->GetNext();
               }
               else {
                  // prevNode refers to node before the songNode
                  prevNode = headNode;
                  while (prevNode->GetNext() != songNode) {
                     prevNode = prevNode->GetNext();
                  }

                  // prevNode updated so next is the node following songNode
                  prevNode->SetNext(songNode->GetNext());

                  if (songNode == tailNode) {
                     tailNode = prevNode;
                  }
               }

               // STEP 2: Insert song at newPosition

               // Insert songNode at head or if user position is before head
               if (newPosition <= 1) {
                  songNode->SetNext(headNode);
                  headNode = songNode;

                  cout << "\"" << songNode->GetSongName() << "\" moved to position 1" << endl << endl;

               }
               else {
                  // insertPosNode refers to the node before the location songNode is inserted
                  insertPosNode = headNode;
                  numNodes = 0;

                  while ((insertPosNode != 0) && ((numNodes + 2) < newPosition)) {
                     insertPosNode = insertPosNode->GetNext();
                     numNodes++;
                  }

                  // Insert songNode to new location
                  if (insertPosNode == 0) {
                     tailNode->InsertAfter(songNode);
                     tailNode = songNode;
                     newPosition = numNodes + 1;
                  }
                  else{
                     insertPosNode->InsertAfter(songNode);
                     newPosition = numNodes + 2;
                  }

                  if (tailNode == insertPosNode) {
                     tailNode = songNode;
                  }

                  cout << "\"" << songNode->GetSongName() << "\" moved to position " << newPosition << endl << endl;
               }
            }
            break;


         case 's':
            // Consume newline and prompt user for output criteria
            cin.ignore();
            cout << "OUTPUT SONGS BY SPECIFIC ARTIST" << endl;
            cout << "Enter artist's name:" << endl;
            getline(cin, artistName);
            cout << endl;

            // Search list for matching artists
            numNodes = 1;
            currNode = headNode;

            while (currNode != 0) {
               // Output songs with matching artist name
               if (currNode->GetArtistName() == artistName) {
                  cout << numNodes << "." << endl;
                  currNode->PrintPlaylistNode();
                  cout << endl;
               }
               currNode = currNode->GetNext();
               ++numNodes;
            }

            break;


         case 't':
            // Output playlist messaging
            cout << "OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)" << endl;

            // Total song times for each song in the list
            currNode = headNode;
            totalTime = 0;

            while (currNode != 0) {
               totalTime += currNode->GetSongLength();
               currNode = currNode->GetNext();
            }

            cout << "Total time: " << totalTime << " seconds" << endl << endl;
            break;


         case 'o':
            // Output playlist messaging
            cout << playlistTitle << " - OUTPUT FULL PLAYLIST" << endl;

            // Iterate through each song in list
            numNodes = 1;
            currPrintNode = headNode;

            // If list is empty, output error message
            if (headNode == 0) {
               cout << "Playlist is empty" << endl << endl;
            }
            // Otherwise call print function for each node in list
            else {
               while (currPrintNode != 0) {
                  cout << numNodes << "." << endl;
                  currPrintNode->PrintPlaylistNode();
                  currPrintNode = currPrintNode->GetNext();
                  cout << endl;
                  ++numNodes;
               }
            }

            break;
      }
   }
}


int main() {
   string playlistTitle;

   // Prompt user for playlist title
   cout << "Enter playlist's title:" << endl;
   getline(cin, playlistTitle);
   cout << endl;

   // Output play list menu options
   PrintMenu(playlistTitle);

   return 0;
}
/*
26.5 Linked List 02
You will be building a linked list. Make sure to keep track of both the head and tail nodes.

(1) Create three files to submit.

PlaylistNode.h - Class declaration
PlaylistNode.cpp - Class definition
main.cpp - main() function
Build the PlaylistNode class per the following specifications. Note: Some functions can initially be function stubs (empty functions), to be completed in later steps.

Default constructor
Parameterized constructor
Public member functions
InsertAfter() - Mutator
SetNext() - Mutator
GetID() - Accessor
GetSongName() - Accessor
GetArtistName() - Accessor
GetSongLength() - Accessor
GetNext() - Accessor
PrintPlaylistNode()
Private data members
string uniqueID - Initialized to "none" in default constructor
string songName - Initialized to "none" in default constructor
string artistName - Initialized to "none" in default constructor
int songLength - Initialized to 0 in default constructor
PlaylistNode* nextNodePtr - Initialized to 0 in default constructor
Ex. of PrintPlaylistNode output:

Unique ID: S123
Song Name: Peg
Artist Name: Steely Dan
Song Length (in seconds): 237
(2) In main(), prompt the user for the title of the playlist.

Ex:

Enter playlist's title:
JAMZ

(3) Implement the PrintMenu() function. PrintMenu() takes the playlist title as a parameter and outputs a menu of options to manipulate the playlist. Each option is represented by a single character. Build and output the menu within the function.

If an invalid character is entered, continue to prompt for a valid choice. Hint: Implement Quit before implementing other options. Call PrintMenu() in the main() function. Continue to execute the menu until the user enters q to Quit.

Ex:

JAMZ PLAYLIST MENU
a - Add song
d - Remove song
c - Change position of song
s - Output songs by specific artist
t - Output total time of playlist (in seconds)
o - Output full playlist
q - Quit

Choose an option:

(4) Implement "Output full playlist" menu option. If the list is empty, output: Playlist is empty

Ex:

JAMZ - OUTPUT FULL PLAYLIST
1.
Unique ID: SD123
Song Name: Peg
Artist Name: Steely Dan
Song Length (in seconds): 237

2.
Unique ID: JJ234
Song Name: All For You
Artist Name: Janet Jackson
Song Length (in seconds): 391

3.
Unique ID: J345
Song Name: Canned Heat
Artist Name: Jamiroquai
Song Length (in seconds): 330

4.
Unique ID: JJ456
Song Name: Black Eagle
Artist Name: Janet Jackson
Song Length (in seconds): 197

5.
Unique ID: SD567
Song Name: I Got The News
Artist Name: Steely Dan
Song Length (in seconds): 306

(5) Implement the "Add song" menu item. New additions are added to the end of the list.

Ex:

ADD SONG
Enter song's unique ID:
SD123
Enter song's name:
Peg
Enter artist's name:
Steely Dan
Enter song's length (in seconds):
237

(6) Implement the "Remove song" function. Prompt the user for the unique ID of the song to be removed.

Ex:

REMOVE SONG
Enter song's unique ID:
JJ234
"All For You" removed

(7) Implement the "Change position of song" menu option. Prompt the user for the current position of the song and the desired new position. Valid new positions are 1 - n (the number of nodes). If the user enters a new position that is less than 1, move the node to the position 1 (the head). If the user enters a new position greater than n, move the node to position n (the tail). 6 cases will be tested:

Moving the head node
Moving the tail node
Moving a node to the head
Moving a node to the tail
Moving a node up the list
Moving a node down the list
Ex:

CHANGE POSITION OF SONG
Enter song's current position:
3
Enter new position for song:
2
"Canned Heat" moved to position 2

(8) Implement the "Output songs by specific artist" menu option. Prompt the user for the artist's name, and output the node's information, starting with the node's current position.

Ex:

OUTPUT SONGS BY SPECIFIC ARTIST
Enter artist's name:
Janet Jackson

2.
Unique ID: JJ234
Song Name: All For You
Artist Name: Janet Jackson
Song Length (in seconds): 391

4.
Unique ID: JJ456
Song Name: Black Eagle
Artist Name: Janet Jackson
Song Length (in seconds): 197

(9) Implement the "Output total time of playlist" menu option. Output the sum of the time of the playlist's songs (in seconds).

Ex:

OUTPUT TOTAL TIME OF PLAYLIST (IN SECONDS)
Total time: 1461 seconds
*/
