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
	cout << " 1. 계좌 개설\n";
	cout << " 2. 계좌 조회\n";
	cout << " 3. 계좌 입금\n";
	cout << " 4. 계좌 출금\n";
	cout << " 5. 계좌 이체\n";
	cout << " 6. 계좌 해지\n";
	cout << " 7. 고객 관리\n";
	cout << " 9. 업무 종료\n";
	cout << " 10. 정기 예금\n";
	cout << " 11. 정기 예금 해지\n";
}

void ATMachine::createAccount() {
	string name, password;
	int id ,money = 0;
	srand(time(NULL));
	
	id = rand() % 901 + 100;

	cout << "----- 개설 -----\n";
	cout << "이름 입력: ";
	cin >> name;
	cout << "암호 입력: ";
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
	cout << "----- 조회 -----\n";
	cout << "계좌번호 입력: ";
	cin >> id;
	cout << "비밀번호 입력: ";
	cin >> password;
	for (int i = 0; i < 100; i++) {
		int money = pAcctArray[i].check(id, password);
		if (money != -1) {
			cout << "현재 잔액 : " << money;
			cout << endl;
			break;
		}

	}

}


void ATMachine::closeAccount() {
	string password;
	int id;
	cout << "----- 해제 -----\n";
	cout << "계좌번호 입력: ";
	cin >> id;
	cout << "비밀번호 입력: ";
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
	cout << "----- 입금 -----\n";
	cout << "계좌번호 입력: ";
	cin >> id;
	cout << "비밀번호 입력: ";
	cin >> password;
	cout << "입금액 입력: ";
	cin >> money;
	for (int i = 0; i < 100; i++) {
		int result = pAcctArray[i].check(id, password);
		bool check = pAcctArray[i].getTimedepositcase();
		if (result != -1 && check == false) {
			int result2 = pAcctArray[i].deposit(id, password, money);
			cout << "현재 잔액 : " << result2 << endl;
			cout << "입금 완료" << endl;
			break;
		}
	}

	
}

void ATMachine::withdrawMoney() {
	string password;
	int id, money;
	cout << "----- 출금 -----\n";
	cout << "계좌번호 입력: ";
	cin >> id;
	cout << "비밀번호 입력: ";
	cin >> password;
	cout << "출금액 입력: ";
	cin >> money;
	for (int i = 0; i < 100; i++) {
		int result = pAcctArray[i].check(id, password);
		bool check = pAcctArray[i].getTimedepositcase();
		if (result != -1 && check == false) {
			int result2 = pAcctArray[i].withdraw(id, password, money);
			cout << "현재 잔액 : " << result2 << endl;
			cout << "출금 완료" << endl;
			break;
		}
	}
}

void ATMachine::transfer() {

	string password, password2;
	int id,id2, money = 0;
	cout << "----- 이체 -----\n";
	cout << "계좌번호 입력: ";
	cin >> id;
	cout << "비밀번호 입력: ";
	cin >> password;
	cout << "이체계좌 입력: ";
	cin >> id2;
	cout << "이체금액 입력: ";
	cin >> money;
	for (int i = 0; i < 100; i++) {
		int result = pAcctArray[i].check(id, password);
		bool check = pAcctArray[i].getTimedepositcase();
		if (result != -1 && check == false) {
			for (int j = 0; j < 100; j++) {
				if (id2 == pAcctArray[j].getAcctID()) {
					int result2 = pAcctArray[i].deposit(id, money);
					cout << "현재 잔액 : " << result2 << endl;
					cout << "이체완료" << endl;
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
}	//관리자 암호 확인


void ATMachine::displayReport() {
	int count = 1;
	for (int i = 0; i < 100; i++) {
		if (pAcctArray[i].getAcctID() != -1 && pAcctArray[i].getTimedepositcase()== false) {
			cout << count << ".  " << pAcctArray[i].getAccountName() << "     " << pAcctArray[i].getAcctID();
			cout << "     " << pAcctArray[i].getBalance() << "원\n" << endl;
			count++;
		}
		else if (pAcctArray[i].getAcctID() != -1 && pAcctArray[i].getTimedepositcase() == true) {
			cout << count << ".  " << pAcctArray[i].getAccountName() << "     " << pAcctArray[i].getAcctID() << "(정기예금id)";
			cout << "     " << pAcctArray[i].getBalance() << "원\n" << endl;
			count++;
		}
	}

}	//통계 화면 처리

void ATMachine::managerMode() {

	string password;
	int id, money;
	int count = 0;
	for (int i = 0; i < 100; i++) {
		if (pAcctArray[i].getAcctID() != -1) {
			count++;
		}
	}
	cout << "----- 관리 -----\n";
	cout << "관리자 비밀번호 입력: ";
	cin >> password;
	cout << endl;
	if (isManager(password)) {
		cout << "관리자입니다.\n" << endl;
		cout << "------------------\n";
		cout << "ATM 현재 잔고:    " << Statistics::sum(pAcctArray, 100) + nMachineBalance << "원" << endl;
		cout << "고객 잔고 총액:   " << Statistics::sum(pAcctArray, 100) << "원" << "(총" << count << "명)" << endl;
		cout << "고객 잔고 평균:   " << Statistics::average(pAcctArray, 100) << "원" << endl;
		cout << "고객 잔고 최고:   " << Statistics::max(pAcctArray, 100) << "원" << endl;
		cout << "------------------\n";
		cout << "- 고객 계좌 목록 -\n" << "------------------\n";
		Statistics::sort(pAcctArray, 100);
		displayReport();

	}
	else {
		cout << "관리자가 아닙니다." << endl;
	}

}
void ATMachine::timedeposit() {
	string password;
	int id;
	bool ans;
	cout << "----- 정기예금 -----\n";
	cout << "계좌번호 입력: ";
	cin >> id;
	cout << "비밀번호 입력: ";
	cin >> password;
	for (int i = 0; i < 100; i++) {
		int money = pAcctArray[i].check(id, password);
		bool check = pAcctArray[i].getTimedepositcase();
		if (money != -1 &&  check == false) {
			cout << "정기 예금으로 전환하시겠습니까?";
			cin >> ans;
			if (ans == true) {
				pAcctArray[i].timedepositcheck();
				break;
			}
		else {
			cout << "정기 예금으로 전환하지 않았습니다.\n";
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
	cout << "----- 정기예금해제 -----\n";
	cout << "계좌번호 입력: ";
	cin >> id;
	cout << "비밀번호 입력: ";
	cin >> password;
	for (int i = 0; i < 100; i++) {
		int money = pAcctArray[i].check(id, password);
		bool check = pAcctArray[i].getTimedepositcase();
		if (money != -1 && check == true) {
			cout << "몇일 후에 정기 예금을 해제하시겠습니까?";
			cin >> date;
			pAcctArray[i].timedepositmoney(date);
			break;
		}
		else {
			cout << "정기 예금 해제에 실패하였습니다.\n";
			break;
		}
	}
}