program vijos1291;
var
  n,m,i,j,total   :longint;
  a,t        :array[1..2000]of longint;
  c          :array[1..2000]of boolean;
procedure sort(b,e:integer);
var i,j,x,y:integer;
begin
   i:=b; j:=e;
   x:=t[(b+e)div 2];
   repeat
     while t[i]<x do inc(i);
     while t[j]>x do dec(j);
     if i<=j then
     begin
         y:=t[i]; t[i]:=t[j]; t[j]:=y;
         inc(i); dec(j);
     end;
   until i>j;
   if i<e then sort(i,e);
   if j>b then sort(b,j);
end;
begin
    fillchar(c,sizeof(c),false);
    readln(n,m);
    for i:= 1 to n do readln(a[i]);
    for i:= 1 to m do readln(t[i]);
    sort(1,m);
    total:=m;
    for i:= 1 to n do
      for j:=m downto 1 do
      if(t[j]<a[i])and(t[j]>0)and(c[j]=false)then
      begin
         dec(total); c[j]:=true; break;
      end;
    writeln(total);
end.

