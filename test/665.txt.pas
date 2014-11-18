program p1257;
type rec=record
  s,id:string;
  end;
var a:array[1..1000]of rec;
    i,j,k,m,n,l:integer;  x:rec;

procedure ex(i,j:integer);
var tem:rec;
begin
  tem:=a[i];
  a[i]:=a[j];
  a[j]:=tem;
end;

function com(a,b:string):boolean;
var l1,l2:integer;
begin
  l1:=length(a);
  l2:=length(b);
  if l1<l2 then exit(true)
  else if l1>l2 then exit(false)
  else if a<b then exit(true);
end;

function com2(a,b:string):boolean;
var l1,l2:string;    i,j:integer;
begin
  l1:=a;
  l2:=b;
  for i:=1 to length(l1) do upcase(l1[i]);
  for i:=1 to length(l2) do upcase(l2[i]);
  if l1>l2 then exit(true)
  else exit(false);
end;
begin
  readln(n);
  for i:=1 to n do begin readln(a[i].id);readln(a[i].s);end;
  for i:=1 to n-1 do
    for j:=n downto i+1 do if com2(a[j].id,a[j-1].id) then ex(j,j-1);
  for i:=1 to n-1 do
    for j:=n downto i+1 do if com(a[j].s,a[j-1].s) then ex(j,j-1);
  for i:=n downto 1 do writeln(a[i].id);
end.
