program vijos1415;
const step:array[1..8,1..2]of integer
      =((-1,1),(-1,0),(-1,-1),(0,1),(0,-1),(1,1),(1,0),(1,-1));
var
  i,j,m,n,t,k:integer;
  a:array[0..101,0..101,1..64]of char;
  s:string;
procedure work(x,y,t:integer);
var i,live:integer;
begin
    live:=0;
    for i:=1 to 8 do
    if((x+step[i,1])<=n)and ((x+step[i,1])>=1)and((y+step[i,2])<=m)and((y+step[i,2])>=0)
    and(a[x+step[i,1],y+step[i,2],k-1]='1')then inc(live);
    if(a[x,y,k-1]='0')
      then if (live=3) then a[x,y,k]:='1' else a[x,y,k]:='0'
      else if (live<2)or(live>3) then a[x,y,k]:='0' else a[x,y,k]:='1' ;
end;
begin
    readln(m,n,t);
    for i:= 1 to n do
    begin
      readln(s);
      for j:=1 to m do
      a[i,j,1]:=s[j];
    end;
    for k:=2 to t do
      for i:=1 to n do
        for j:=1 to m do
        work(i,j,k);
    for i:=1 to n do
    begin
      for j:=1 to m do write(a[i,j,t]);
      writeln;
    end;
end.
