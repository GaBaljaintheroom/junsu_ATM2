#ifndef ACCOUNT_H
#define ACCOUNT_H
using std::string;
#define AUTHENTIFICATION_FAIL -1 // 계정 인증 실패
#define AUTHENTIFICATION_SUCCESS 1 // 계정 인증 성공
#define BASE_ACCOUNT_ID 100 // 계좌번호는 100번 부터 1000 사이 랜덤으로 부여
#define PaymentDate 365		// 정기예금 기간
#define InterestRate 0.1	// 정기예금 이자율

class Account {
private:
	int nID; // 계좌 번호 (초기 값 = -1)
	int nBalance = 0; // 잔고 (초기 값 = 0)
	string strAccountName; // 고객 명
	string strPassword; // 계좌 비밀번호
	bool timedepositcase; // 정기예금 확인
private:
	inline bool authenticate(int id, string passwd); // 인증 성공 : true(1), 인증 실패 : false(0)
public:
	Account();
	void create(int id, int money, string name, string password); // 계좌 개설
	void close(); // 계좌 해지
	int deposit(int id, string password, int money); // 계좌 입금
	int withdraw(int id, string password, int money); // 계좌 출금
	int check(int id, string password); //계좌조회 return 값 : nBalance (잔고) or 인증 실패(AUTHENTIFICATION_FAIL)
	int getAcctID() { return nID; } // 계좌 번호 읽어오기
	int deposit(int id, int money); // 계좌 이체
	int getBalance() { return nBalance; }	// 계좌 잔고 읽어오기
	string getAccountName() { return strAccountName; } // 계좌 고객 명 읽어오기
	void timedepositcheck();			// 정기예금 확인
	void timedepositmoney(int date);				// 정기예금 해제 및 돈 확인
	bool getTimedepositcase() { return timedepositcase; }	// 정기예금확인 리턴
};
#endif
