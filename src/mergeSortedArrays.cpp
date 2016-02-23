
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
int* tokens(char* d){
	int* token = (int*)malloc(sizeof(int) * 3), j = 0;
	int temp = 0, i = 0;

	while (i<11){
		while (d[i] != '-' && d[i] >= '0' && d[i] <= '9'){
			temp = temp * 10 + (d[i] - '0');
			i++;
		}
		token[j] = temp;
		j++;
		i++;
		if ((d[i]) == '\0') break;
		temp = 0;
	}
	return token;
}
bool isOLD(char* d1, char* d2){
	int *token1, *token2;
	token1 = tokens(d1);
	token2 = tokens(d2);
	if (token1[0] == token2[0] && token1[1] == token2[1] && token1[2] == token2[2])
		return false;
	else if (token1[2] > token2[2]){
		return false;
		if (token1[1] > token2[1]){
			return false;
			if (token1[0] > token2[0])
				return false;
		}
	}
	else return true;
}
struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	struct transaction *C = (transaction*)malloc(sizeof(transaction)*(ALen + BLen));
	if (A && B){
		int i = 0, j = 0, k = 0;
		while (i < ALen && j < BLen){
			if (isOLD(A[i].date, B[j].date)){
				C[k] = A[i];
				i++;
			}
			else{
				C[k] = B[j];
				j++;
			}
			k++;
		}
		while (i < ALen){
			C[k] = A[i];
			k++;
			i++;
		}
		while (j < BLen){
			C[k] = B[j];
			k++;
			j++;
		}
		return C;
	}
	else return NULL;

}
/*#include <iostream>


int isOlder(char *dob1, char *dob2) {
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
};*/

/*struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
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

}*/
/*int year(char *s){
	int i = 0, j = 0;
	for (i = 6; i <= 9; i++){
		j = j * 10 + s[i] - '0';
	}
	return j;
}*/
/*
int isleapyear(int year)
{
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		return 1;
	else
		return 0;
}
int datevalid(int date, int month, int year)
{
	if (month > 12 || month <= 0 || date > 31 || date <= 0)
	{
		return 0;

	}
	else
	{
		switch (month)
		{
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			return 1;
			break;
		case 2:
			if (isleapyear(year))
			{
				if (date <= 29)
				{
					return 1;
				}
				else return 0;

			}
			else
			{
				if (date <= 28)
				{
					return 1;
				}
				else return  0;
			}
			break;
		case 4:
		case 6:
		case 9:
		case 11:
			if (date <= 30)
			{
				return 1;

			}
			else
			{
				return 0;
			}
			break;

		}


	}

}
int isOlder(char *dob1, char *dob2) {
	int i = 0, d1 = 0, m1 = 0, y1 = 0, d2 = 0, m2 = 0, y2 = 0, k1, k2;


	for (i = 0; dob1[i] != '-'; i++){
		if (dob1[i] - '0' >= 0 && dob1[i] - '0' < 10){
			d1 = (d1 * 10) + dob1[i] - '0';
		}

		else
			return -1;

	}





	for (i = i + 1; dob1[i] != '-'; i++){
		if (dob1[i] - '0' >= 0 && dob1[i] - '0' < 10){
			m1 = (m1 * 10) + dob1[i] - '0';
		}

		else
			return -1;
	}



	for (i = i + 1; dob1[i] != '\0'; i++){
		if (dob1[i] - '0' >= 0 && dob1[i] - '0' < 10){
			y1 = (y1 * 10) + dob1[i] - '0';
		}

		else
			return -1;
	}


	k1 = datevalid(d1, m1, y1);


	for (i = 0; dob2[i] != '-'; i++){
		if (dob2[i] - '0' >= 0 && dob2[i] - '0' < 10){
			d2 = (d2 * 10) + dob2[i] - '0';
		}

		else
			return -1;
	}




	for (i = i + 1; dob2[i] != '-'; i++){
		if (dob2[i] - '0' >= 0 && dob2[i] - '0' < 10){
			m2 = (m2 * 10) + dob2[i] - '0';
		}

		else
			return -1;
	}


	for (i = i + 1; dob2[i] != '\0'; i++){
		if (dob2[i] - '0' >= 0 && dob2[i] - '0' < 10){
			y2 = (y2 * 10) + dob2[i] - '0';
		}

		else
			return -1;
	}


	k2 = datevalid(d2, m2, y2);

	if (k1 == 1 && k2 == 1){
		if (y2 < y1){
			return 2;
		}
		else if (y2 > y1){
			return 1;
		}
		else if (y1 == y2){
			if (m2 < m1){
				return 2;
			}
			else if (m1 < m2){
				return 1;
			}
			else if (m1 == m2){

				if (d2 < d1){
					return 2;
				}
				else if (d1 < d2){
					return 1;
				}

				else if (d1 == d2){
					return 0;
				}
			}
		}
	}


	else
		return -1;
}


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

/*struct transaction * mergeSortedArrays(struct transaction *A, int ALen, struct transaction *B, int BLen) {
	int i = 0, j, k = 0, l, c = 0, e = 0, h, n, m = 0;
	char *d, *date;
	struct transaction *C = (struct transaction *)malloc(sizeof(struct transaction *)*(ALen + BLen));
	struct transaction *temp = (struct transaction *)malloc(sizeof(struct transaction *)*ALen);
	if (ALen < 0 || BLen < 0){
		return NULL;
	}
	else if (A == NULL || B == NULL){
		return NULL;
	}

	else{
		for (n = 0; n < ALen; n++){
			C[m] = A[n];
			m++;
		}
		for (i = 0; i < BLen; i++){
			C[m] = B[i];
			m++;
		}
		for (j = 1; j<(ALen + BLen); j++){
			if ((year(C[j - 1].date))>(year(C[j].date))){
				temp[0] = C[j - 1];
				C[j - 1] = C[j];
				C[j] = temp[0];
			}
		}
		return C;
	}
}*/