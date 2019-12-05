#include  <iostream>
#include <stack>
#include <climits>
using namespace std;
int main()
{
    stack<int > a,b,c;
    int a1,b1,c1,i,x,height_a=0,height_b=0,height_c=0,max_height;
    int a_height[100000],b_height[100000],c_height[100000];
    cin >> a1 >> b1 >> c1;
    for(i=1;i<=a1;i++)
    {
        cin >> x;
        a_height[i] = x;
        height_a += x;
    }
    for(i=1;i<=b1;i++)
    {
        cin >> x;
        b_height[i] = x;
        height_b += x;
    }
    for(i=1;i<=c1;i++)
    {
        cin >> x;
        c_height[i] = x;
        height_c += x;
    }
    for(i=a1;i>0;i--)
        a.push(a_height[i]);
    for(i=b1;i>0;i--)
        b.push(b_height[i]);
    for(i=c1;i>0;i--)
        c.push(c_height[i]);
    while(!(height_a == height_b  && height_b == height_c))
    {
        if(height_a > height_b)
        {
            if(height_a > height_c)
            {
                max_height = height_a;
                height_a -= a.top();
                //cout << "Moved "<< a.top() << " from block a" << endl;
                //cout << "Heights : " << height_a << " " << height_b << " " << height_c << endl;
                a.pop();
            }
            else
            {
                max_height = height_c;
                height_c -= c.top();
                //cout << "Moved "<< c.top() << " from block c" << endl;
                //cout << "Heights : " << height_a << " " << height_b << " " << height_c << endl;
                c.pop();
            }
        }
        else
        {
            if(height_b > height_c)
            {
                max_height = height_b;
                height_b -= b.top();
               //cout << "Moved "<< b.top() << " from block b" << endl;
                //cout << "Heights : " << height_a << " " << height_b << " " << height_c << endl;
                b.pop();

            }
            else
            {
                max_height = height_c;
                height_c -= c.top();
                //cout << "Moved "<< c.top() << " from block c" << endl;
                //cout << "Heights : " << height_a << " " << height_b << " " << height_c << endl;
                c.pop();
            }
        }
    }
    cout << height_a;
    return 0;
}
