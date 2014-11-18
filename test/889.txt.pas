program tn;
var
 i,n,m,p,a,b:integer;
 people:array[0..5000]of integer;
function Find(x:integer):integer;
 begin
   if people[x]=x then exit(x)
   else exit(Find(people[x]));
 end;
begin
 readln(n,m,p);
 for i:=1 to n do people[i]:=i;
 for i:=1 to m do
  begin
   readln(a,b);
   people[Find(a)]:=Find(b);
  end;
 for i:=1 to p do
  begin
   readln(a,b);
   if Find(a)=Find(b) then writeln('Yes')
   else writeln('No');
  end;
end.
