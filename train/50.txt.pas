program tug;
var f:array[0..200,0..8000] of boolean;
    n,i,j,k,m,ans,sum:longint;
    w:array[1..200] of longint;
function max(a,b:longint):longint;
begin
  if a>b then exit(a)
         else exit(b);
end;
function min(a,b:longint):longint;
begin
 if a<b then exit(a)
        else exit(b);
end;
begin
  sum:=0;
  readln(n);
  m:=(n+1) div 2;
  for i:=1 to n do
  begin
    readln(w[i]);
    inc(sum,w[i]);
  end;
  fillchar(f,sizeof(f),false);
  f[0,0]:=true;
  for i:=1 to n do
   for j:=m downto 1 do
    for k:=sum downto w[i] do
     if f[j-1,k-w[i]] then f[j,k]:=true;
  ans:=maxlongint;
  for i:=0 to sum do
   if f[m,i] then ans:=min(ans,abs(sum-i-i));
  writeln((sum-ans) div 2,' ',(sum+ans) div 2);
end.
