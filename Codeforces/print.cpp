pii hobena = mp(-inf,-inf);

class rectangle {
public:
	pii a,b;

	rectangle(pii x, pii y): a(x), b(y) {}

	rectangle() {
		a = mp(0,0);
		b = mp(0,0);
	}

	void input() {
		cin >> a.F >> a.S;
		cin >> b.F >> b.S;
	}

	void output() {
		dbg(this->a);
		dbg(this->b);
	}
};

bool operator == (rectangle const &x, rectangle const &y) {
	return (x.a == y.a && x.b == y.b);
}

rectangle intersects(rectangle x , rectangle y) {
	int x1,x2,y1,y2;
	x1 = max(x.a.F , y.a.F);
	x2 = min(x.b.F , y.b.F);
	y1 = max(x.a.S , y.a.S);
	y2 = min(x.b.S , y.b.S);
	if(x1 > x2 || y1 > y2)
		return rectangle(hobena, hobena);
	else
		return rectangle(mp(x1,y1) , mp(x2,y2));
}

int main()
{
	int n;

	vector < rectangle > a;

	cin >> n;

	a.resize(n);

	for(int i = 0; i < n; ++i)
		a[i].input();

	rectangle baikka = rectangle(hobena,hobena);

	vector < rectangle > left(n),right(n);

	left[0] = a[0];
	left[0].output();
	for(int i = 1; i < n; ++i) {
		left[i] = intersects(left[i-1] , a[i]);
		left[i].output();
	}
	dbg(endl);
	right[n-1] = a[n-1];
	right[n-1].output();
	for(int i = n-2; i >= 0; --i) {
		right[i] = intersects(right[i+1] , a[i]);
		right[i].output();
	}

	rectangle eta = right[1];

	for(int i = 1; i < n-1; ++i) {
		if(left[i-1] == baikka || right[i+1] == baikka)	continue;

		eta = intersects(left[i-1] , right[i+1]);
		break;
	}

	if(eta == baikka)
		eta = left[n-2];

	cout << eta.a.F << " " << eta.a.S << endl;

	return 0;
}
