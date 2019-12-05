a=input('A');
b=input('B');
error=input('error ');
syms x;
f(x)=input('(x^3-9x+3)');
k=-1;
e=1;
while (e>=error)
    k=k+1;
    c=f(a);
    d=f(b);
    t= (a*d-b*c)/(d-c);
    
    if (f(t)*f(a)>0)
        a=t;
    else
        b=t;
    end
    
    e=f(t);
   
end
fprintf('console.log %f',t);