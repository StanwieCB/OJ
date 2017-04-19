#include <iostream>
#include <string>
using namespace std;

class HugeData
{
	friend HugeData operator+(const HugeData& h1, const HugeData& h2);//
	friend istream& operator >> (istream& is, HugeData& h);
	friend ostream& operator<<(ostream& os, const HugeData& h);
private:
	struct node
	{
		int data;
		node* next;
		node(const int& num, node* n = NULL) :data(num), next(n) {}
		node() :next(NULL) {}
	};
	node * head;
	void clear();
public:
	HugeData(node* n = NULL)
	{
		if (n == NULL)
		{
			head = new node(0);
		}
		else
		{
			head = n;
		}
	}
	HugeData(const HugeData& h)
	{
		head = new node(h.head->data);
		node* p = head;
		node* q = h.head;
		while (q->next != NULL)
		{
			q = q->next;
			p->next = new node(q->data);
			p = p->next;
		}
	}
	HugeData& operator=(const HugeData& h)
	{
		if (&h == this)
		{
			return *this;
		}
		clear();
		head = new node(h.head->data);
		node* p = head;
		node* q = h.head;
		while (q->next != NULL)
		{
			q = q->next;
			p->next = new node(q->data);
			p = p->next;
		}
		return *this;
	}
	~HugeData()
	{
		clear();
	}
};

void HugeData::clear()
{
	node* p = head, *q;
	while (p != NULL)
	{
		q = p;
		p = q->next;
		delete q;
	}
	head = NULL;
}

HugeData operator+(const HugeData& h1, const HugeData& h2)
{
	HugeData newh;
	HugeData::node *p, *q, *c;
	int carry = 0;
	p = h1.head;
	q = h2.head;
	newh.head = c = new HugeData::node((p->data + q->data + carry) % 10);
	carry = (p->data + q->data + carry) / 10;
	c = newh.head;
	p = p->next;
	q = q->next;
	while (p != NULL && q != NULL)
	{
		c->next = new HugeData::node((p->data + q->data + carry) % 10);
		carry = (p->data + q->data + carry) / 10;
		c = c->next;
		p = p->next;
		q = q->next;
	}
	if (p == NULL)
	{
		while (q != NULL)
		{
			c->next = new HugeData::node((q->data + carry) % 10);
			carry = (q->data + carry) / 10;
			c = c->next;
			q = q->next;
		}
	}
	else
	{
		while (p != NULL)
		{
			c->next = new HugeData::node((p->data + carry) % 10);
			carry = (p->data + carry) / 10;
			c = c->next;
			p = p->next;
		}
	}
	if (carry != 0)
	{
		c->next = new HugeData::node(carry);
	}
	return newh;
}

istream& operator >> (istream& is, HugeData& h)
{
	string str;
	h.clear();
	is >> str;
	for (int i = 0; i < int(str.length()); i++)
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			h.head = new HugeData::node(str[i] - '0', h.head);
		}
	}
	return is;
}

ostream& operator<<(ostream& os, const HugeData& h)
{
	string str;
	HugeData::node *p;
	p = h.head;
	//os << p->data << endl;
	while (p != NULL)
	{
		//os << "1";
		str = char(p->data + '0') + str;
		p = p->next;
		//os << "1";
	}
	os << str;
	return os;
}

int main()
{
	HugeData h1, h2;
	cin >> h1;
	cin >> h2;
	//cout << h1<< endl;
	cout << h1 + h2 << endl;
	system("pause");
	return 0;
}