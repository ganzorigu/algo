struct DoSomethingFunctor
{
	DoSomethingFunctor(int i, bool b, float f, double d, unsigned int u)
		: m_i(i), m_b(b), m_f(f), m_d(d), m_u(u)
	{
	}

	void operator()(char c) const
	{
		// do something
	}

	int m_i;
	bool m_b;
	float m_f;
	double m_d;
	unsigned int m_u;
};

int Add(int x, int y)
{
	return x + y;
}

void DoSomething(int i, bool b, float f, double d, unsigned int u, char c)
{
	// does something
}

int main()
{

	DoSomethingFunctor o(1, true, 2.f, 3., 4u);
	o('a');
	o('b');
	DoSomething(1, true, 2.f, 3., 4u, 'a');
	DoSomething(1, true, 2.f, 3., 4u, 'b');

	return 0;
}
