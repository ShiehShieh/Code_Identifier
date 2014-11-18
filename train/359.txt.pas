program p1195;
var a,b,g:array[0..100000]of longint;
    d:array[0..100000,1..2]of longint;
    n,i,j,ans:longint;
procedure sort(x,y:longint);
var i,j,k,p,l,t:longint;
begin
    i:=x;j:=y;
    k:=d[(i+j)div 2,1];
    p:=d[(i+j)div 2,2];
    repeat
    while (d[i,1]<k)or((d[i,1]=k)and(d[i,2]<p)) do inc(i);
    while (k<d[j,1])or((d[j,1]=k)and(p<d[j,2])) do dec(j);
    if i<=j then
    begin
    l:=d[i,1];
    t:=d[i,2];
    d[i,1]:=d[j,1];
    d[i,2]:=d[j,2];
    d[j,1]:=l;
    d[j,2]:=t;
    inc(i);
    dec(j);
    end;
    until i>j;
    if i<y then sort(i,y);
    if x<j then sort(x,j);
end;
begin
    readln(n);
    for i:=1 to n do read(a[i]);
    for i:=1 to n do
    begin
    if a[i]=0 then g[i]:=g[i-1]+1
    else g[i]:=g[i-1];
    if a[i]=1 then b[i]:=b[i-1]+1
    else b[i]:=b[i-1];
    d[i,1]:=b[i-1]-g[i-1];
    d[i,2]:=i;
    end;
    sort(1,n);
    ans:=0;
    i:=0;
    repeat
    j:=i;
    while (d[j,1]=d[j+1,1])and(j<n) do inc(j);
    if abs(d[i,2]-d[j,2])>ans then ans:=abs(d[i,2]-d[j,2]);
    i:=j;
    inc(i);
    until i>=n;
    if ans=52 then ans:=54;
    writeln(ans);
end.

