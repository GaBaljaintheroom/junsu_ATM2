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
	nID = id;				//�� ��ȣ
	nBalance = money;		// �� ��
	strAccountName = name; // �� ��
	strPassword = password; // ���� ��й�ȣ

	cout << strAccountName << "�� " << nID << "�� ���¹�ȣ�� ���������� �����Ǿ����ϴ�. �����մϴ�." << endl;

}// ���� ����


inline bool Account::authenticate(int id, string passwd) {
	if (nID == id && strPassword == passwd) return 1;
	else return 0;
} // ����� ���� 

int Account::check(int id, string password) {
	
	if (authenticate(id, password)) return nBalance;
	else return AUTHENTIFICATION_FAIL;
	
} // ���� ��ȸ

void Account::close() {
	if (nBalance != 0) {
		cout << nID<< " ���¸� ������ �� �����ϴ�. " << "�ܾ� : " << nBalance << endl;
	}
	else {
		cout << nID << " ���°� �����Ǿ����ϴ�.�����մϴ�." << endl;
		nID = -1;
		nBalance = 0;
		strAccountName = '\0';
		strPassword = '\0';
	}
} // ���� ����

int Account::deposit(int id, string password, int money) {
	if (authenticate(id, password)) {
		nBalance = nBalance + money;
		return nBalance;
	}
	else return AUTHENTIFICATION_FAIL;
} // ���� �Ա�

int Account::deposit(int id, int money) {
	nBalance = nBalance - money;
	return nBalance;

} // ���� ��ü


int Account::withdraw(int id, string password, int money) {
	if (authenticate(id, password)) {
		nBalance = nBalance - money;
		return nBalance;
	}
	else return AUTHENTIFICATION_FAIL;
} // ���� ���

void Account::timedepositcheck() {

	cout << "���� ���� ���� ���ڴ� 365�� �� �Դϴ�.\n";
	cout << "���� �� ����� ���� �ʽ��ϴ�.\n";
	cout << "���� �� �޴� �ݾ� : " << nBalance + nBalance * InterestRate * PaymentDate << endl;
	timedepositcase =  true;

}// ���⿹���ϱ�

void Account::timedepositmoney(int date) {

	nBalance = nBalance + nBalance * InterestRate * date;
	cout << "�ߵ� ���� ���ھ� : " << nBalance << endl;
	cout << date << "�� �Ŀ� ���� ���� �� �ֽ��ϴ�. " << endl;
}// ���� ���� ���� �� ���ھ� ���