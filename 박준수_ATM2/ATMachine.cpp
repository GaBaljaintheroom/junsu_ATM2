#include <iostream>
using namespace std;

#include "ATMachine.h"
#include "Account.h"
#include "Statistics.h"
#include <stdlib.h>
#include <time.h>



ATMachine::ATMachine(int size, int balance, string password) {
	pAcctArray = new Account[size];
	nCurrentAccountNum = 0;
	nMachineBalance = balance;
	strManagerPassword = password;
}

ATMachine::~ATMachine() {
	delete[]pAcctArray;
}

void ATMachine::displayMenu() {
	cout << "----------------------------\n";
	cout << "-       TUKOREA BANK       -\n";
	cout << "----------------------------\n";
	cout << " 1. ���� ����\n";
	cout << " 2. ���� ��ȸ\n";
	cout << " 3. ���� �Ա�\n";
	cout << " 4. ���� ���\n";
	cout << " 5. ���� ��ü\n";
	cout << " 6. ���� ����\n";
	cout << " 7. �� ����\n";
	cout << " 9. ���� ����\n";
	cout << " 10. ���� ����\n";
	cout << " 11. ���� ���� ����\n";
}

void ATMachine::createAccount() {
	string name, password;
	int id ,money = 0;
	srand(time(NULL));
	
	id = rand() % 901 + 100;

	cout << "----- ���� -----\n";
	cout << "�̸� �Է�: ";
	cin >> name;
	cout << "��ȣ �Է�: ";
	cin >> password;
	
	for (int i = 0; i < 100; i++) {
		if (pAcctArray[i].getAcctID() == -1) {
			pAcctArray[nCurrentAccountNum].create(id, money, name, password);
			nCurrentAccountNum = nCurrentAccountNum + 1;
			break;
		}
	}

}

void ATMachine::checkMoney() {
	string password;
	int id;
	cout << "----- ��ȸ -----\n";
	cout << "���¹�ȣ �Է�: ";
	cin >> id;
	cout << "��й�ȣ �Է�: ";
	cin >> password;
	for (int i = 0; i < 100; i++) {
		int money = pAcctArray[i].check(id, password);
		if (money != -1) {
			cout << "���� �ܾ� : " << money;
			cout << endl;
			break;
		}

	}

}


void ATMachine::closeAccount() {
	string password;
	int id;
	cout << "----- ���� -----\n";
	cout << "���¹�ȣ �Է�: ";
	cin >> id;
	cout << "��й�ȣ �Է�: ";
	cin >> password;
	for (int i = 0; i < 100; i++) {
		int money = pAcctArray[i].check(id, password);
		bool check = pAcctArray[i].getTimedepositcase();
		if (money != -1 && check == false) {
			pAcctArray[i].close();
			break;
		}
	}
}

void ATMachine::depositMoney() {
	string password;
	int id, money;
	cout << "----- �Ա� -----\n";
	cout << "���¹�ȣ �Է�: ";
	cin >> id;
	cout << "��й�ȣ �Է�: ";
	cin >> password;
	cout << "�Աݾ� �Է�: ";
	cin >> money;
	for (int i = 0; i < 100; i++) {
		int result = pAcctArray[i].check(id, password);
		bool check = pAcctArray[i].getTimedepositcase();
		if (result != -1 && check == false) {
			int result2 = pAcctArray[i].deposit(id, password, money);
			cout << "���� �ܾ� : " << result2 << endl;
			cout << "�Ա� �Ϸ�" << endl;
			break;
		}
	}

	
}

void ATMachine::withdrawMoney() {
	string password;
	int id, money;
	cout << "----- ��� -----\n";
	cout << "���¹�ȣ �Է�: ";
	cin >> id;
	cout << "��й�ȣ �Է�: ";
	cin >> password;
	cout << "��ݾ� �Է�: ";
	cin >> money;
	for (int i = 0; i < 100; i++) {
		int result = pAcctArray[i].check(id, password);
		bool check = pAcctArray[i].getTimedepositcase();
		if (result != -1 && check == false) {
			int result2 = pAcctArray[i].withdraw(id, password, money);
			cout << "���� �ܾ� : " << result2 << endl;
			cout << "��� �Ϸ�" << endl;
			break;
		}
	}
}

void ATMachine::transfer() {

	string password, password2;
	int id,id2, money = 0;
	cout << "----- ��ü -----\n";
	cout << "���¹�ȣ �Է�: ";
	cin >> id;
	cout << "��й�ȣ �Է�: ";
	cin >> password;
	cout << "��ü���� �Է�: ";
	cin >> id2;
	cout << "��ü�ݾ� �Է�: ";
	cin >> money;
	for (int i = 0; i < 100; i++) {
		int result = pAcctArray[i].check(id, password);
		bool check = pAcctArray[i].getTimedepositcase();
		if (result != -1 && check == false) {
			for (int j = 0; j < 100; j++) {
				if (id2 == pAcctArray[j].getAcctID()) {
					int result2 = pAcctArray[i].deposit(id, money);
					cout << "���� �ܾ� : " << result2 << endl;
					cout << "��ü�Ϸ�" << endl;
					break;
				}
			}
			break;
		}
	}
	for (int i = 0; i < 100; i++) {
		if (id2 == pAcctArray[i].getAcctID()) {
			pAcctArray[i].deposit(id, -money);
			break;
		}
	}

}

bool ATMachine::isManager(string password) {
	if (password == strManagerPassword) return true;
	else return false; 
}	//������ ��ȣ Ȯ��


void ATMachine::displayReport() {
	int count = 1;
	for (int i = 0; i < 100; i++) {
		if (pAcctArray[i].getAcctID() != -1 && pAcctArray[i].getTimedepositcase()== false) {
			cout << count << ".  " << pAcctArray[i].getAccountName() << "     " << pAcctArray[i].getAcctID();
			cout << "     " << pAcctArray[i].getBalance() << "��\n" << endl;
			count++;
		}
		else if (pAcctArray[i].getAcctID() != -1 && pAcctArray[i].getTimedepositcase() == true) {
			cout << count << ".  " << pAcctArray[i].getAccountName() << "     " << pAcctArray[i].getAcctID() << "(���⿹��id)";
			cout << "     " << pAcctArray[i].getBalance() << "��\n" << endl;
			count++;
		}
	}

}	//��� ȭ�� ó��

void ATMachine::managerMode() {

	string password;
	int id, money;
	int count = 0;
	for (int i = 0; i < 100; i++) {
		if (pAcctArray[i].getAcctID() != -1) {
			count++;
		}
	}
	cout << "----- ���� -----\n";
	cout << "������ ��й�ȣ �Է�: ";
	cin >> password;
	cout << endl;
	if (isManager(password)) {
		cout << "�������Դϴ�.\n" << endl;
		cout << "------------------\n";
		cout << "ATM ���� �ܰ�:    " << Statistics::sum(pAcctArray, 100) + nMachineBalance << "��" << endl;
		cout << "�� �ܰ� �Ѿ�:   " << Statistics::sum(pAcctArray, 100) << "��" << "(��" << count << "��)" << endl;
		cout << "�� �ܰ� ���:   " << Statistics::average(pAcctArray, 100) << "��" << endl;
		cout << "�� �ܰ� �ְ�:   " << Statistics::max(pAcctArray, 100) << "��" << endl;
		cout << "------------------\n";
		cout << "- �� ���� ��� -\n" << "------------------\n";
		Statistics::sort(pAcctArray, 100);
		displayReport();

	}
	else {
		cout << "�����ڰ� �ƴմϴ�." << endl;
	}

}
void ATMachine::timedeposit() {
	string password;
	int id;
	bool ans;
	cout << "----- ���⿹�� -----\n";
	cout << "���¹�ȣ �Է�: ";
	cin >> id;
	cout << "��й�ȣ �Է�: ";
	cin >> password;
	for (int i = 0; i < 100; i++) {
		int money = pAcctArray[i].check(id, password);
		bool check = pAcctArray[i].getTimedepositcase();
		if (money != -1 &&  check == false) {
			cout << "���� �������� ��ȯ�Ͻðڽ��ϱ�?";
			cin >> ans;
			if (ans == true) {
				pAcctArray[i].timedepositcheck();
				break;
			}
		else {
			cout << "���� �������� ��ȯ���� �ʾҽ��ϴ�.\n";
			break;
			}
		}
	}
}

void ATMachine::timedepositbreak() {
	string password;
	int id;
	bool check;
	int date;
	cout << "----- ���⿹������ -----\n";
	cout << "���¹�ȣ �Է�: ";
	cin >> id;
	cout << "��й�ȣ �Է�: ";
	cin >> password;
	for (int i = 0; i < 100; i++) {
		int money = pAcctArray[i].check(id, password);
		bool check = pAcctArray[i].getTimedepositcase();
		if (money != -1 && check == true) {
			cout << "���� �Ŀ� ���� ������ �����Ͻðڽ��ϱ�?";
			cin >> date;
			pAcctArray[i].timedepositmoney(date);
			break;
		}
		else {
			cout << "���� ���� ������ �����Ͽ����ϴ�.\n";
			break;
		}
	}
}