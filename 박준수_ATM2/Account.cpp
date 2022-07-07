#include <iostream>
using namespace std;
#include "Account.h"

Account::Account() {
	nID = -1;
	nBalance = 0;
	strAccountName = "";
	strPassword = "";
	timedepositcase = false;
}

void Account::create(int id, int money, string name, string password) {
	nID = id;				//고객 번호
	nBalance = money;		// 고객 돈
	strAccountName = name; // 고객 명
	strPassword = password; // 계좌 비밀번호

	cout << strAccountName << "님 " << nID << "번 계좌번호가 정상적으로 개설되었습니다. 감사합니다." << endl;

}// 계좌 개설


inline bool Account::authenticate(int id, string passwd) {
	if (nID == id && strPassword == passwd) return 1;
	else return 0;
} // 사용자 인증 

int Account::check(int id, string password) {
	
	if (authenticate(id, password)) return nBalance;
	else return AUTHENTIFICATION_FAIL;
	
} // 계좌 조회

void Account::close() {
	if (nBalance != 0) {
		cout << nID<< " 계좌를 해지할 수 없습니다. " << "잔액 : " << nBalance << endl;
	}
	else {
		cout << nID << " 계좌가 해지되었습니다.감사합니다." << endl;
		nID = -1;
		nBalance = 0;
		strAccountName = '\0';
		strPassword = '\0';
	}
} // 계좌 해지

int Account::deposit(int id, string password, int money) {
	if (authenticate(id, password)) {
		nBalance = nBalance + money;
		return nBalance;
	}
	else return AUTHENTIFICATION_FAIL;
} // 계좌 입금

int Account::deposit(int id, int money) {
	nBalance = nBalance - money;
	return nBalance;

} // 계좌 이체


int Account::withdraw(int id, string password, int money) {
	if (authenticate(id, password)) {
		nBalance = nBalance - money;
		return nBalance;
	}
	else return AUTHENTIFICATION_FAIL;
} // 계좌 출금

void Account::timedepositcheck() {

	cout << "정기 예금 해지 일자는 365일 후 입니다.\n";
	cout << "예금 및 출금이 되지 않습니다.\n";
	cout << "해지 후 받는 금액 : " << nBalance + nBalance * InterestRate * PaymentDate << endl;
	timedepositcase =  true;

}// 정기예금하기

void Account::timedepositmoney(int date) {

	nBalance = nBalance + nBalance * InterestRate * date;
	cout << "중도 해제 이자액 : " << nBalance << endl;
	cout << date << "일 후에 지급 받을 수 있습니다. " << endl;
}// 정기 예금 해지 및 이자액 출력