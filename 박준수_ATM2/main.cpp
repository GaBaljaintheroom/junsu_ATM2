#include<iostream>
using namespace std;
#include "ATMachine.h"

int main() {
	int select;
	// ����(100��), ATM �ܱ� �ʱ�ȭ, ������ ��ȣ
	ATMachine atm(100, 50000, "admin");
	while (1) {
		atm.displayMenu();
		cout << "�޴��� �����ϼ��� :" ;
		cin >> select;
		cout << endl;
		switch (select) {
		case 1:
			atm.createAccount();
			break;
		case 2:
			atm.checkMoney();
			break;
		case 3:
			atm.depositMoney();
			break;
		case 4:
			atm.withdrawMoney();
			break;
		case 5:
			atm.transfer();
			break;
		case 6:
			atm.closeAccount();
			break;
		case 7:
			atm.managerMode();
			break;
		case 9:
			cout << "�ȳ��� ������";
			return 0;
		case 10:
			atm.timedeposit();
			break;
		case 11:
			atm.timedepositbreak();
			break;
		default:
			cout << "��ȣ Ȯ�� �� �ٽ� �Է��ϼ���." << endl;
		}
	}
	return 0;
}