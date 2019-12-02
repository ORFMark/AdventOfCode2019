/*
 * util.cpp
 *
 *  Created on: Dec 2, 2019
 *      Author: Mark
 */

#include <stdio.h>;
#include <stdlib.h>;
#include <iostream>;
using namespace std;

void printArray(FILE* fp, int array[], int length, int columns) {
	int i = 0;
	for (i = 0; i < length; i++) {
		if (i % columns || i == 0) {
			fprintf(fp, "%7d", array[i]);
		} else {
			fprintf(fp, "\n%7d", array[i]);
		}
	}
	fputc('\n', fp);
}
void printArray(auto array, int length) {
	int i = 0;
	for (i = 0; i < length; i++) {
		if (i % 10 || i == 0) {
			fprintf(stdout, "%7d", array[i]);
		} else {
			fprintf(stdout, "\n%7d", array[i]);
		}
	}
	fputc('\n', stdout);
}
