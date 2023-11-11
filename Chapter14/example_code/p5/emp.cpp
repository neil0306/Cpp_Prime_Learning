#include "emp.h"

abstr_emp::abstr_emp() : fname("none"), lname("none"), job("none")
{
}

abstr_emp::abstr_emp(const string &fn, const string &ln, const string &j) : fname(fn), lname(ln), job(j)
{
}

abstr_emp::~abstr_emp()
{
}

void abstr_emp::ShowAll() const 
{
	cout << "fname: " << fname << endl;
    	cout << "lname: " << lname << endl;
    	cout << "job: " << job << endl;
}

void abstr_emp::SetAll() 
{
    	cout << "Enter the first name: ";
	getline(cin, fname);
	cout << "Enter the last name: ";
    	getline(cin, lname);
	cout << "Enter the job: ";
	getline(cin, job);
}

ostream  &operator<<(ostream &os, const abstr_emp &e) 
{
    	os << "fname: " << e.fname << endl;
    	os << "lname: " << e.lname << endl;
    	os << "job: " << e.job << endl;
    	return os;
}

employee::employee() : abstr_emp()
{
}

employee::employee(const string &fn, const string &ln, const string &j) : abstr_emp(fn, ln, j) 
{
}

void employee::ShowAll() const 
{
	abstr_emp::ShowAll();
}

void employee::SetAll() 
{
    	abstr_emp::SetAll();
}

manager::manager() : abstr_emp(), inchargeof(0)
{
}

manager::manager(const string &fn, const string &ln, const string &j, int ico) : abstr_emp(fn, ln, j), inchargeof(ico)
{
}

manager::manager(const abstr_emp &e, int ico) : abstr_emp(e), inchargeof(ico) 
{
}

manager::manager(const manager &m) : abstr_emp(m)
{
    	inchargeof = m.inchargeof;
}

void manager::ShowAll() const 
{
    abstr_emp::ShowAll();
    cout << "ico: " << inchargeof << endl;
}

void manager::SetAll() 
{
    abstr_emp::SetAll();
    cout << "ico: "; cin >> inchargeof;
}

fink::fink() : abstr_emp(), reportsto("none")
{
}

fink::fink(const string &fn, const string &ln, const string &j, const string &rpo) : abstr_emp(fn, ln, j), reportsto(rpo)
{
}

fink::fink(const abstr_emp &e, const string &rpo) : abstr_emp(e), reportsto(rpo)
{
}

fink::fink(const fink &e) : abstr_emp(e)
{
	reportsto = e.reportsto;
}

void fink::ShowAll() const 
{
    abstr_emp::ShowAll();
    cout << "reportsto: " << reportsto << endl;
}

void fink::SetAll() 
{
    abstr_emp::SetAll();
    cout << "reportsto: "; cin >> reportsto;
}

highfink::highfink() : abstr_emp(), manager(), fink()
{
}

highfink::highfink(const string &fn, const string &ln, const string &j, const string &rpo, int ico) : abstr_emp(fn, ln, j), manager(fn, ln, j, ico), fink(fn, ln, j, rpo)
{
}

highfink::highfink(const abstr_emp &e, const string &rpo, int ico) : abstr_emp(e), manager(e, ico), fink(e, rpo)
{
}

highfink::highfink(const fink &f, int ico) : abstr_emp(f), manager(f, ico), fink(f)
{
}

highfink::highfink(manager &m, const string &rpo) : abstr_emp(m), manager(m), fink(m, rpo)
{
}

highfink::highfink(const highfink &h) : abstr_emp(h), manager(h), fink(h)
{
}

void highfink::ShowAll() const 
{
    fink::ShowAll();
    manager::ShowAll();
}

void highfink::SetAll() 
{
    manager::SetAll();
    fink::SetAll();
}
