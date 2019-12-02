/*
 * days.cpp
 *
 *  Created on: Dec 2, 2019
 *      Author: Mark
 */
#include <iostream>
#include "days.hpp"
#include "util.hpp"
using namespace std;
/*find the fuel needed by a list of modules (input). Equation is F = mass/3 -2 + fuelForFuel(treat each fuel as one mass) */
void day1() {
	int puzzleInput[100] = { 114106, 87170, 133060, 70662, 134140, 125874,
			50081, 133117, 100409, 95098, 70251, 134043, 87501, 85034, 110678,
			80615, 64647, 88555, 106387, 143755, 101246, 142348, 92684, 62051,
			94894, 65873, 78473, 64042, 147982, 145898, 85591, 121413, 132163,
			94351, 80080, 73554, 106598, 135174, 147951, 132517, 50925, 115752,
			114022, 73448, 50451, 56205, 81474, 90028, 124879, 137452, 91036,
			87221, 126590, 130592, 91503, 148689, 86526, 105924, 52411, 146708,
			149280, 52100, 80024, 115412, 91204, 132726, 59837, 129863, 140980,
			109574, 103013, 84105, 138883, 144861, 126708, 140290, 54417,
			138154, 125187, 91537, 90338, 61150, 61702, 95888, 100484, 82115,
			122141, 63986, 138234, 54150, 57651, 124570, 88460, 112144, 112334,
			119114, 58220, 143221, 86568, 148706 };
	int fuelSum = 0;
	int fuelForFuel = 0;
	for (int i = 0; i < 100; i++) {
		fuelSum += (puzzleInput[i] / 3) - 2;
		fuelForFuel = (puzzleInput[i] / 3) - 2;
		while (fuelForFuel > 0) {
			fuelForFuel = (fuelForFuel / 3) - 2;
			if (fuelForFuel > 0) {
				fuelSum += fuelForFuel;
			}
		}
	}
	cout << "Fuel: " << fuelSum << endl;
}

/* intcode computer*/
void day2() {
	int program[157] = { 1, 12, 2, 3, 1, 1, 2, 3, 1, 3, 4, 3, 1, 5, 0, 3, 2, 13,
			1, 19, 1, 10, 19, 23, 1, 23, 9, 27, 1, 5, 27, 31, 2, 31, 13, 35, 1,
			35, 5, 39, 1, 39, 5, 43, 2, 13, 43, 47, 2, 47, 10, 51, 1, 51, 6, 55,
			2, 55, 9, 59, 1, 59, 5, 63, 1, 63, 13, 67, 2, 67, 6, 71, 1, 71, 5,
			75, 1, 75, 5, 79, 1, 79, 9, 83, 1, 10, 83, 87, 1, 87, 10, 91, 1, 91,
			9, 95, 1, 10, 95, 99, 1, 10, 99, 103, 2, 103, 10, 107, 1, 107, 9,
			111, 2, 6, 111, 115, 1, 5, 115, 119, 2, 119, 13, 123, 1, 6, 123,
			127, 2, 9, 127, 131, 1, 131, 5, 135, 1, 135, 13, 139, 1, 139, 10,
			143, 1, 2, 143, 147, 1, 147, 10, 0, 99, 2, 0, 14, 0 };
	int testCase[12] = { 1, 9, 10, 3, 2, 3, 11, 0, 99, 30, 40, 50 };
	//printArray(stdout, program, 157, 4);
	int test[157];
	for (int j = 0; j < 99; j++) {
		for(int k = 0; k < 99; k++) {
			for (int i = 0; i < 157; i++) {
				test[i] = program[i];
			}
			test[1] = j;
			test[2] = k;
			for (int i = 0; i < 157; i += 4) {
				switch (test[i]) {
				case 99:
					i = 158;
					break;
				case 1:
					test[test[i + 3]] = test[test[i + 1]]
												+ test[test[i + 2]];
					break;
				case 2:
					test[test[i + 3]] = test[test[i + 1]]
												* test[test[i + 2]];
					break;
				default:
					cout << "INVALID OPCODE";
					i = 158;
					break;
				}
			}
			if(test[0] == 19690720) {
				cout << test[1] << test[2] << endl;
				return;
			}
		}
	}

	printArray(stdout, program, 157, 4);

	/*
	 for (int i = 0; i < 12; i += 4) {
	 switch (testCase[i]) {
	 case 99:
	 i = 158;
	 break;
	 case 1:
	 testCase[testCase[i + 3]] = testCase[testCase[i + 1]] + testCase[testCase[i + 2]];
	 break;
	 case 2:
	 testCase[testCase[i + 3]] =testCase[testCase[i + 1]] * testCase[testCase[i + 2]];
	 break;
	 default:
	 cout << "INVALID OPCODE";
	 i = 158;
	 break;
	 }
	 }
	 printArray(stdout, testCase, 12, 4);
	 */
	fflush(stdout);
}
