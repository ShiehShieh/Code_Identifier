program p1092;
var nn,n,i,j,k:longint;
    m:int64;
    f:array[1..20] of int64;
    a,b:array[1..20] of integer;
    p:array[1..20] of boolean;
begin
 readln(nn,m);
 n:=nn;
 f[1]:=1;
 for i:=1 to 20 do p[i]:=true;
 for i:=2 to n-1 do f[i]:=f[i-1]*i;
 for i:=1 to n do b[i]:=i;
 for i:=1 to n-1 do
  begin
   k:=(m-1) div f[nn-i]+1;
   m:=(m-1) mod f[nn-i]+1;
   a[i]:=b[k];
   p[a[i]]:=false;
   for j:=k to n-1 do b[j]:=b[j+1];
   n:=n-1;
  end;
 for i:=1 to nn-1 do
 write(a[i],' ');
 for i:=1 to nn do if p[i] then writeln(i);
end.
