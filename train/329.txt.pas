var
  father:array [1..5001] of integer;
  i,n,m,p,a,b:integer;

function find(i:integer):integer;
begin
  if father[i]=i then exit(i)
                 else father[i]:=find(father[i]);   { 在返回的同时，顺便把中间结点的父结点作了更新 }
  exit(father[i]);   { 返回查询的父结点号 }
end;

begin
  readln(n,m,p);
  for i:=1 to n do father[i]:=i;  { 初始每个结点的父结点号为自身 }
  for i:=1 to m do
    begin
      readln(a,b);
      a:=find(a);
      b:=find(b);
      if a<>b then father[a]:=b;  { 如果二个结点的父结点不同，则合并二个集合 }
    end;
  for i:=1 to p do
    begin
      readln(a,b);
      if find(a)=find(b) then writeln('Yes')    { 逐对输出结果 }
                         else writeln('No');
    end;
end.

