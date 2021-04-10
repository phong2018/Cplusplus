#include <iostream>
using namespace std;

int main() {
	int n;      // declare the times of player's input is n
	cout << "How many games do you want to simulate?";
	cin >> n;   //n time player's input

	int noprizeoccuredinbox1 = 0,//initiate the box var start with 0
		noprizeoccuredinbox2 = 0,
		noprizeoccuredinbox3 = 0;

	float k = 0, s = 0;         //initiate the times player keep or switch
	float percent_win_byswitch;
	float percent_win_bykeep;

	int i;

	for (i = 0; i < n; i++) {  //indicate each time player input n time
		int boxprize; int boxselection; //initiate box prize , boxseclection var
		boxprize = (rand() % 3 + 1); // assign random number picked for player
		boxselection = (rand() % 3 + 1);// assign random number player's pick


		//if player win by keeping boxes, add 1 to a count of number of times player win   
		if (boxprize == boxselection) k++;
		// if player win by switching boxes, add 1 to a count of number of of times the player win
		else s++;

		//if prize in box 1
		if (boxprize == 1) noprizeoccuredinbox1++;

		//if prize in box 2
		if (boxprize == 2) noprizeoccuredinbox2++;

		//if prize in box 3
		if (boxprize == 3) noprizeoccuredinbox3++;

	}
	percent_win_byswitch = ((s / n) * 100);
	percent_win_bykeep = ((k / n) * 100);

	cout << "Box #1 had the prize  " << noprizeoccuredinbox1 << " times. " << endl;
	cout << "Box #2 had the prize  " << noprizeoccuredinbox2 << " times. " << endl;
	cout << "Box #3 had the prize  " << noprizeoccuredinbox3 << " times. " << endl;

	cout << percent_win_byswitch << "% of the time the player would have won without switching." << endl;
	cout << percent_win_bykeep << "% of the time the player would have won with switching." << endl;


}