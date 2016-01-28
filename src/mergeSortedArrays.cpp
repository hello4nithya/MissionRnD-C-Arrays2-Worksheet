/*
OVERVIEW: You are given 2 bank statements that are ordered by date - Write a function that produces a single merged statement ordered by dates.
E.g.: Input: A[3] = { { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" }, { 30, "03-03-2005", "Third" } };
B[2] = { { 10, "09-10-2003", "First" }, { 220, "18-01-2010", "Sixth" } };
Output: { { 10, "09-10-2003", "First" }, { 10, "09-10-2003", "First" }, { 20, "19-10-2004", "Second" },  30, "03-03-2005", "Third" }, { 220, "18-01-2010", "Sixth" } }

INPUTS: Two bank statements (array of transactions).

OUTPUT: Combined statement ordered by transaction date.

ERROR CASES: Return NULL for invalid inputs.

NOTES:
*/

#include <iostream>

struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	//initializing dates to 0
	int d1[3] = { 0, 0, 0 }, d2[3] = { 0, 0, 0 };
	for (int value = 0, iter = 0; iter < 10; iter++){
		if (iter == 2 || iter == 5){
			//if 3rd and 6th position is not '-'
			if (dob1[iter] != '-' || dob2[iter] != '-')
				return -1;
			else {
				iter++;
				value++;
			}
		}
		if (dob1[iter] < '0' || dob1[iter] > '9' || dob2[iter] < '0' || dob2[iter] > '9')
			//if it is not a integer between 0 and 9
			return -1;
		else{
			//computing values of dates
			d1[value] = (dob1[iter] - '0') + (d1[value] * 10);
			d2[value] = (dob2[iter] - '0') + (d2[value] * 10);
		}
	}
	if (d1[1] > 12 || d2[1]>12)
		//if not an appropriate month
		return -1;
	//if not an appropriate date
	if (d1[0] > 31 || d2[0] > 31)	return -1;
	if ((d1[1] == 4 || d1[1] == 6 || d1[1] == 9 || d1[1] == 11) && d1[0] > 30)	return -1;
	if ((d2[1] == 4 || d2[1] == 6 || d2[1] == 9 || d2[1] == 11) && d2[0] > 30)	return -1;
	if (d1[1] == 2 && d1[0] > 28){
		if ((d1[2] % 4) == 0 && d1[0] == 29){}
		else	return -1;
	}
	if (d2[1] == 2 && d2[0] > 28){
		if ((d2[2] % 4) == 0 && d2[0] == 29){}
		else	return -1;
	}
	//finding the eldest person
	for (int iter = 2; iter >= 0; iter--){
		if (d1[iter] > d2[iter])
			return 2;
		else if (d1[iter] < d2[iter])
			return 1;
	}
	//if both are equal
	return 0;
}
struct transaction {
	int amount;
	char date[11];
	char description[20];
};

struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	if (A == NULL || B == NULL)
		return NULL;
	struct transaction * result = (struct transaction *)malloc(sizeof(struct transaction *)*(ALen + BLen));
	int iterB = 0, iterA = 0, iterR = 0;
	for (int temp; iterA < ALen&& iterB < BLen; iterR++){
		temp = isOlder(A[iterA].date, B[iterB].date);
		if (temp == 0){
			//realloc(result, (sizeof(struct transaction *))*(iterR + 1));
			result[iterR] = A[iterA];
			iterB++;
			iterA++;
		}
		else if (temp == 2){
			result[iterR] = B[iterB];
			iterB++;
		}
		else if (temp == 1){
			result[iterR] = A[iterA];
			iterA++;
		}
		else
			return NULL;
	}
	while (iterA<ALen)
		result[iterR++] = A[iterA++];
	while (iterB<BLen)
		result[iterR++] = B[iterB++];

	return result;

}
