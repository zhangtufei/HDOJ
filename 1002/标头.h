#include <iostream>
#include <string>
using namespace std;
class Customer
{
	static int member;
protected:
	int m_id;
	string m_name;
	string m_phone;
public:
	Customer(int id, const string &name, const string &phone);
	~Customer(void);
	virtual void Print() const;
	virtual bool IsReular() const;
	const string &GetName() const;
	const string & GetPhone()const;
};
Customer::Customer(int id, const string &name, const string &phone)
{
	m_id = id;
	m_name = name;
	m_phone = phone;
	member += 1;
}
void Customer::Print() const 
{
	cout << "id :" << m_id << endl;
	cout << "name :" << m_name << endl;
	cout << "m_phone :" << m_phone << endl;
}
const string & Customer::GetName() const
{
	return m_name;
}
const string & Customer::GetPhone() const
{
	return m_phone;
}
bool Customer::IsReular() const
{

}