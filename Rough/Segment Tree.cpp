#include <bits/stdc++.h>
using namespace std;

#define MAX 112345
#define lc (node<<1)
#define rc (lc+1)

typedef long long ll;

ll st[4*MAX+10];
ll a[MAX+10];

ll f(ll x, ll y) {
	//Your function here
	//For range minimum query
	return min(x,y);
}

void build(ll node,ll left, ll right) {

	if(left==right) {

		st[node] = a[left];

		return;

	}

	ll tm = (left+right)>>1;

	build(lc, left,tm);		//Go to left child

	build(rc, tm+1, right); 	//Go to right child

	st[node] = f( st[lc] , st[rc] );	//Value for this node will be f(value in left child , value in right child);
}

//Update function works same as build function
//As we have a specified position to update,let we have to update index '6'
//Now, let's say, node 1 covers from 1 to 9,
//then its left child covers from 1 to 4 and right child covers from 5 to 9;
//as (left+right)/2 = 5 , the left child's covered area (1 to 4) does not cover our required index 6, so we go to the right child.

void update(ll node, ll left, ll right, ll idx, ll val) {
	if(left == right) {
		st[node] = val;			//If it is the leaf node,then here,we will update the value.
		return;
	}

	ll tm = (left+right)>>1;

	if(idx<=tm)	update(lc, left, tm, idx ,val);		//if idx is in the area of left child
	else if(idx > tm)	update(rc, tm+1, right,idx,val);	//if idx is in the area of right child
	
	st[node] = f(st[lc] , st[rc]);
}

//Query works the same way update works
//But it queries a range.
//So,lets say we want to get the minimum in range 2 to 6.
//Now, the node 1 covers 1-9,
//left child covers 1-4 and right child covers 5-9
//so the range is between left and right child.
//so we go to both child and get the answer recursively and the answer for this node will be min( left child , right child)

ll query(ll node, ll left, ll right, ll l, ll r) {
	if(l <= left && r >= right)
		return st[node];			//Reached Leaf node,so return

	ll tm = (left+right)>>1;

	if(r<= tm)	return query(lc, left, tm, l, r);		//If the left child covers the whole range
	else if(l > tm)	return query(rc, tm+1, right, l, r);	//If the right child covers the whole range
	else
		return f( query(lc, left, tm, l , r) , query(rc, tm+1, right, l, r) );	//else we have to go to both of the childs.
}


int main() {

	ll n;
	cin >> n;

	for(int i = 0; i < n; ++i)
		cin >> a[i];
	
	build(1,0,n-1);		//start from node 1, that covers elements from array index 0 to n-1;
	
	int q;
	
	cin >> q;

	while(q--) {
		ll l,r;
		cin >> l >> r;

		l-- , r--; //if the input is from 1 to n, but array is stored in 0 to n-1;

		cout << query(1,0,n-1, l,r) << endl;		//start from node 1, that covers elements from 0 to n-1 , required range is l,r
	}


	return 0;
}