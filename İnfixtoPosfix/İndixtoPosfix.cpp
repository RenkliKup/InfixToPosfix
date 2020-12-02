//static dizi uyuglamasý
#include <iostream>
#include<utility>
#include <string>
using namespace std;
struct yigin
{
	char *dizi;
	int top;
	int boyut;
};
yigin* tanimla(string n)
{
	yigin* d = new yigin;
	d->top = -1;
	d->boyut = n.length();
	d->dizi = new char[d->boyut];
	return d;
}
void push(yigin* s,char n)
{
	if (s->top == s->boyut - 1)
	{
		cout << "stack owerflow" << endl;
	}
	else
	{
		s->dizi[++s->top] = n;
		
	}
}
pair<yigin*,char> pop(yigin*s)
{
	if (s->top == -1)
	{
		cout << "stack underflow" << endl;
	}
	char temp;
	temp = s->dizi[s->top--];
	return make_pair(s, temp);
}
void yazdir(yigin* s)
{
	cout	<< "top->";
	for (int i = s->top; i > -1; i--)
		cout << "\t" << s->dizi[i]<< endl;

	system("pause");
}
bool Buyukesit(char a, char b)
{
	if (a == '/' || a == '*')
	{
		return true;
	}
	if (b == '+' || b == '-')
	{
		return true;
	}
	return false;
}
string InfixToPosfix(string a)
{
	yigin* s = new yigin;
	s->top = -1;
	s->boyut = 20;
	s->dizi= new char[s->boyut];
	string posfix = "";
	for (size_t i = 0; i < a.length(); i++)
	{
		if (a[i] == '+' || a[i] == '-' || a[i] == '*' || a[i] == '/')
		{
			
			while (s->top!=-1)
			{
				char temp;
				temp = s->dizi[s->top];
				if (temp == '(')
				{
					break;
				}
				if (Buyukesit(temp, a[i]))
				{
					
					pair<yigin*, char> degisken = pop(s);
					temp = degisken.second;
					s = degisken.first;
					
					posfix += temp;
				}
				else
				{
					break;
				}
			}
			push(s, a[i]);
	
		}
		else if (a[i] == ')')
		{
			char temp;
			while (s->top!=-1)
			{
				pair<yigin*, char> degisken = pop(s);
				s = degisken.first;
				temp = degisken.second;
				
				if (temp == '(')
				{
					break;
				}
				posfix += temp;
			}

		}
		else if (a[i] == '(')
		{
			push(s, a[i]);
		}
		else
		{
			posfix += a[i];
		}
	
		
	}
	char temp;
	while (s->top != -1)
	{
		pair<yigin*, char> degisken = pop(s);
		s = degisken.first;
		temp = degisken.second;
		posfix += temp;
	}
	return posfix;
	
}
int main()
{
	string input;
	cout << "pls infix enter value" << endl;
	cin >> input;
	cout << InfixToPosfix(input)<<endl;
	system("pause");
	
}