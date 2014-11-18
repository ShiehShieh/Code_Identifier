const maxn=200000;
var
  t:array[1..4*maxn] of longint;
  m,n,i,x,y:longint;
function  max(x,y:longint):longint;
  begin
    if x>y then exit(x) else exit(y);
  end;
procedure  insert(p,k,l,r,x:longint);
var  m:longint;
begin
  if (l=r) then begin t[k]:=p; exit; end;
    m:=(l+r) shr 1;
  if x<=m then begin insert(p,k+k,l,m,x);t[k]:=max(t[k+k],t[k+k+1]);end
  else if x>=m+1 then begin insert(p,k+k+1,m+1,r,x);t[k]:=max(t[k+k],t[k+k+1]);end;
end;
function  count(k,l,r,x,y:longint):longint;
var m:longint;
begin
  if (l=x)and(r=y) then exit(t[k]);
    m:=(l+r) shr 1;
  if y<=m then count:=count(k+k,l,m,x,y)
    else if x>=m+1 then count:=count(k+k+1,m+1,r,x,y)
      else count:=max(count(k+k,l,m,x,m),count(k+k+1,m+1,r,m+1,y)); 
end;
begin

  readln(n);
  for i:=1 to n do t[i]:=-maxlongint;
  for i:=1 to n do
    begin
      read(x);
      insert(x,1,1,n,i);
    end;
  readln(m);
   for i:=1 to m do
    begin
      readln(x,y);
      writeln(count(1,1,n,x,y));
    end;
end.



