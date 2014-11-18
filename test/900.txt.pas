program vijos1051;
const
  a     :array[1..12,1..2] of integer
        =((-2,0),(-1,0),(2,0),(1,0),(0,1),(0,2),(0,-1),(0,-2),(-1,-1),(1,1),(-1,1),(1,-1));
var
  i,j,n,m,sum:integer;
  ch    :array[-1..102,-1..102] of char;
procedure dfs(x,y:integer);
var i:integer;
begin
    ch[x,y]:='-';
    for i:=1 to 12 do
        if(x+a[i,1]<=n)and(x+a[i,1]>0)and(y+a[i,2]<=m)and(y+a[i,2]>0)and(ch[x+a[i,1],y+a[i,2]]='#')
        then dfs(x+a[i,1],y+a[i,2]);
end;
begin
    sum:=0;
    readln(n,m);
    for i:= 1 to n do
    begin
      for j:= 1 to m do read(ch[i,j]);
      readln;
    end;
    for i:=1 to n do
      for j:=1 to m do
      begin
        if (ch[i,j]='#') then
        begin dfs(i,j);
              inc(sum); end;
      end;
    writeln(sum);
end.
