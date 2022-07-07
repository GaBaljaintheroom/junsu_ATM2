#ifndef ACCOUNT_H
#define ACCOUNT_H
using std::string;
#define AUTHENTIFICATION_FAIL -1 // ���� ���� ����
#define AUTHENTIFICATION_SUCCESS 1 // ���� ���� ����
#define BASE_ACCOUNT_ID 100 // ���¹�ȣ�� 100�� ���� 1000 ���� �������� �ο�
#define PaymentDate 365		// ���⿹�� �Ⱓ
#define InterestRate 0.1	// ���⿹�� ������

class Account {
private:
	int nID; // ���� ��ȣ (�ʱ� �� = -1)
	int nBalance = 0; // �ܰ� (�ʱ� �� = 0)
	string strAccountName; // �� ��
	string strPassword; // ���� ��й�ȣ
	bool timedepositcase; // ���⿹�� Ȯ��
private:
	inline bool authenticate(int id, string passwd); // ���� ���� : true(1), ���� ���� : false(0)
public:
	Account();
	void create(int id, int money, string name, string password); // ���� ����
	void close(); // ���� ����
	int deposit(int id, string password, int money); // ���� �Ա�
	int withdraw(int id, string password, int money); // ���� ���
	int check(int id, string password); //������ȸ return �� : nBalance (�ܰ�) or ���� ����(AUTHENTIFICATION_FAIL)
	int getAcctID() { return nID; } // ���� ��ȣ �о����
	int deposit(int id, int money); // ���� ��ü
	int getBalance() { return nBalance; }	// ���� �ܰ� �о����
	string getAccountName() { return strAccountName; } // ���� �� �� �о����
	void timedepositcheck();			// ���⿹�� Ȯ��
	void timedepositmoney(int date);				// ���⿹�� ���� �� �� Ȯ��
	bool getTimedepositcase() { return timedepositcase; }	// ���⿹��Ȯ�� ����
};
#endif
