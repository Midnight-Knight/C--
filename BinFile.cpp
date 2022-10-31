#include "BinFile.h"
#include <vector>

void CreateBinFile(string name, Hash* A)
{
	ofstream a(name, ios::out | ios::binary);
	for (unsigned int i = 0; i < A->getHash(); ++i)
	{
		if (A->getHospitalCell(i) != 00000000000000000000000000000000)
		{
			Hospital* B;
			B = A->getHospitalCell(i);
			a << B->id << " " << B->code << " " << B->TwoNameDoctor << "\n";
			while (B->further != 00000000000000000000000000000000)
			{
				B = B->further;
				a << B->id << " " << B->code << " " << B->TwoNameDoctor << "\n";
			}
		}
	}
	a.close();
}

void ReadBinFile(string name)
{
	ifstream a(name, ios::out | ios::binary);
	if (!a)
	{
		cout << "���� �� ������" << endl;
		return;
	}
	Hospital b;
	vector <Hospital> c;
	int i = 0;
	do
	{
		a >> b.id;
		a >> b.code;
		getline(a, b.TwoNameDoctor);
		c.push_back(b);
	} while (!a.eof());
	c.pop_back();
	for (int i = 0; i < c.size(); ++i)
	{
		cout << "id: " << c[i].id << " code: " << c[i].code << " Two Name Doctor: " << c[i].TwoNameDoctor << endl;
	}
	a.close();
}

void PoiskBinFile(string name, int id)
{
	ifstream a(name, ios::out | ios::binary);
	if (!a)
	{
		cout << "���� �� ������" << endl;
		return;
	}
	Hospital b;
	vector <Hospital> c;
	int i = 0;
	do
	{
		a >> b.id;
		a >> b.code;
		getline(a, b.TwoNameDoctor);
		c.push_back(b);
	} while (!a.eof());
	c.pop_back();
	bool end = false;
	for (int i = 0; i < c.size(); ++i)
	{
		if (c[i].id == id)
		{
			cout << "id: " << c[i].id << " code: " << c[i].code << " Two Name Doctor: " << c[i].TwoNameDoctor << endl;
			end = true;
			break;
		}
	}
	if (end == false)
	{
		cout << "������ c ������ [" << id << "] �� ����������!" << endl;
	}
	a.close();
}

void Replace(string name)
{

	ifstream a(name, ios::out | ios::binary);
	if (!a)
	{
		cout << "���� �� ������" << endl;
		return;
	}
	Hospital b;
	vector <Hospital> c;
	int i = 0;
	do
	{
		a >> b.id;
		a >> b.code;
		getline(a, b.TwoNameDoctor);
		c.push_back(b);
	} while (!a.eof());
	c.pop_back();
	for (int i = 0; i < c.size(); ++i)
	{
		cout << "[N" << i << "] " << "id: " << c[i].id << " code: " << c[i].code << " Two Name Doctor: " << c[i].TwoNameDoctor << endl;
	}
	a.close();
	do
	{
		cout << "������� ����� N ��� ��������� ������: ";
		cin >> i;
	} while (i < 0 || (c.size()-1) < i);
	bool ch;
	cout << "�������� ��� �������(0 ���, �� 1): ";
	cin >> ch;
	if (ch == true)
	{
		cout << "������� ����� ��� �������: ";
		int code;
		cin >> code;
		c[i].code = code;
	}
	cout << "�������� �����(0 ���, �� 1): ";
	cin >> ch;
	if (ch == true)
	{
		cout << "������� ����� ������� �����: ";
		string Name;
		cin >> Name;
		c[i].TwoNameDoctor = Name;
	}
	ofstream d(name, ios::out | ios::binary);
	for (int i = 0; i < c.size(); ++i)
	{
		d << c[i].id << " " << c[i].code << " " << c[i].TwoNameDoctor << "\n";
	}
	d.close();
}

Hash* getBinFile(string name, Hash* A)
{
	ifstream a(name, ios::out | ios::binary);
	if (!a)
	{
		cout << "���� �� ������" << endl;
		return nullptr;
	}
	Hospital b;
	vector <Hospital> c;
	int i = 0;
	do
	{
		a >> b.id;
		a >> b.code;
		getline(a, b.TwoNameDoctor);
		c.push_back(b);
	} while (!a.eof());
	c.pop_back();
	Hash* B = new Hash(c.size());
	for (int i = 0; i < c.size(); ++i)
	{
		B->Add(c[i].id, c[i].code, c[i].TwoNameDoctor);
	}
	delete A;
	A = B;
	return A;
}



