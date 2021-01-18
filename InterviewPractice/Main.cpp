// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "CuttoffRanks.h"
#include "UtilizationChecks.h"
#include "CriticalConnection.h"
#include "MininumTotalContainerSize.h"
#include "vector"

int main()
{
	/*UtilizationChecks::print_check(5, { 30,5,4,8,19,89 });
	
	CuttoffRanks::print_cut_off_rank(3, 4, { 100, 50, 50, 25 });
	CuttoffRanks::print_cut_off_rank(4, 5, {2, 2, 3, 4, 5});
	
	int p[4][2] = { {1,2}, {1, 3}, {3,2}, {3, 4} };
	CriticalConnection testConn;
	std::vector<std::vector<int>> conns = { {0,1}, {1,2}, {2,0},{1,3} };
	testConn.printCriticalConnections(4, conns);*/

	vector<int> shipments = { 10, 2, 20, 5, 15, 10, 1 };
	MininumTotalContainerSize::findMininumTotalContainerSize(shipments, 3);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
