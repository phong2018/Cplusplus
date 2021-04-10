#include <iostream>
using namespace std;

#include "PlaylistNode.h"

PlaylistNode::PlaylistNode() {
   this->uniqueID = "none";
   this->songName = "none";
   this->artistName = "none";
   this->songLength = 0;
   this->nextNodePtr = 0;
   return;
}

PlaylistNode::PlaylistNode(string initID, string initSongName,
                           string initArtistName, int initSongLength, PlaylistNode* nextLoc) {

   this->uniqueID = initID;
   this->songName = initSongName;
   this->artistName = initArtistName;
   this->songLength = initSongLength;
   this->nextNodePtr = nextLoc;
   return;
}

void PlaylistNode::InsertAfter(PlaylistNode* nodePtr) {
   PlaylistNode* tmpNext = 0;

   tmpNext = this->nextNodePtr;
   this->nextNodePtr = nodePtr;
   nodePtr->nextNodePtr = tmpNext;
   return;
}

void PlaylistNode::SetNext(PlaylistNode* nodePtr) {
   this->nextNodePtr = nodePtr;
   return;
}

string PlaylistNode::GetID() const {
   return this->uniqueID;
}

string PlaylistNode::GetSongName() const {
   return this->songName;
}

string PlaylistNode::GetArtistName() const {
   return this->artistName;
}

int PlaylistNode::GetSongLength() const {
   return this->songLength;
}

PlaylistNode* PlaylistNode::GetNext() {
   return this->nextNodePtr;
}

void PlaylistNode::PrintPlaylistNode() {
   cout << "Unique ID: " << this->uniqueID << endl;
   cout << "Song Name: " << this->songName << endl;
   cout << "Artist Name: " << this->artistName << endl;
   cout << "Song Length (in seconds): " << this->songLength << endl;
   return;
}
