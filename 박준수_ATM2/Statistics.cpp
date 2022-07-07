#include <iostream>
using namespace std;
#include "Statistics.h"

int Statistics::sum(Account* pArray, int size) {

	int sum= 0;
	for (int i = 0; i < size; i++) {
		if (pArray[i].getBalance() != 0) {
			sum = sum + pArray[i].getBalance();
		}
	}
	return sum;
} // ∞Ë¡¬ ¿‹∞Ì √—«’


int Statistics::average(Account* pArray, int size) {

	int sum = 0 , average = 0, count = 0;
	for (int i = 0; i < size; i++) {
		if (pArray[i].getAcctID() != -1) {
			sum = sum + pArray[i].getBalance();
			count++;
			average = sum / count;
		}
		
	}

	return average;

}// ∞Ë¡¬ ¿‹∞Ì ∆Ú±’

int Statistics::max(Account* pArray, int size) {

	int max = pArray[0].getBalance();
	for (int i = 1; i < size; i++) {
		if (pArray[i].getAcctID() != -1) {
			if (pArray[i].getBalance() > max) {
				max = pArray[i].getBalance();
			}
		}
	}

	return max;

} // ∞Ë¡¬ ¿‹∞Ì √÷∞Ì


void Statistics::sort(Account* pArray, int size) {
	int count = 1;
	Account temp;


	for (int i = 0; i < size; i++) {
		for (int j = 0; j < (size - 1) - i; j++) {
			if (pArray[j].getBalance() < pArray[j + 1].getBalance()) {	
				temp = pArray[j];
				pArray[j] = pArray[j + 1];
				pArray[j + 1] = temp;
			}
		}
	}// πˆ∫Ì ¡§∑ƒ ªÁøÎ
	 // ≥ª∏≤ ¬˜º¯ ¡§∑ƒ
}
