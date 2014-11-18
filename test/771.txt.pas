program p1500;
var
  s:string;
  n,i,k:integer;
  rank:array['a'..'z']of integer;
  a:array[0..1001]of string;

function small(s1,s2:string):boolean;
var
  i,l:integer;
begin
  if length(s1)<=length(s2)
  then l:=length(s1) else l:=length(s2);
  for i:=1 to l do
  begin
    if rank[s1[i]]<rank[s2[i]] then exit(true);
    if rank[s1[i]]>rank[s2[i]] then exit(false);
  end;
  if length(s1)>=length(s2) then exit(false);exit(true);
end;

procedure sort(l,r:integer);
var
  i,j:integer;
  x,t:string;
begin
  i:=l;j:=r;
  x:=a[(l+r)div 2];
  repeat
    while small(a[i],x) do inc(i);
    while small(x,a[j]) do dec(j);
    if i<=j then
    begin
      t:=a[i];a[i]:=a[j];a[j]:=t;
      inc(i);dec(j);
    end;
  until i>j;
  if i<r then sort(i,r);
  if l<j then sort(l,j);
end;

begin
  readln(s);
  for i:=1 to 26 do rank[s[i]]:=i;
  readln(n);
  for i:=1 to n do readln(a[i]);
  sort(1,n);
  readln(k);
  if k=1 then for i:=1 to n do writeln(a[i])
  else for i:=n downto 1 do writeln(a[i]);
end.
