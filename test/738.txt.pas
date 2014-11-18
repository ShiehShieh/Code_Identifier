program kruskalmst;
const
  maxn=100000;
  maxe=100000;
type
  edgetype=record
    beg,en:longint;
    w:double;
  end;
  data1=array[1..maxe] of edgetype;
  data2=array[1..maxn] of longint;
var
  edge:data1;
  father:data2;
  n,e:longint;
  mincost,len:double;
function getfather(x:longint):longint;
var
  i:longint;
begin
  if father[x]=x then
    exit(x)
  else
    father[x]:=getfather(father[x]);
  exit(father[x]);
end;
procedure union(x,y:longint);
begin
  if getfather(x)<>getfather(y) then
    father[x]:=getfather(y);
end;
procedure qsort(s,t:longint);
var
  i,j:longint;
  x:edgetype;
begin
  i:=s;
  j:=t;
  x:=edge[s];
  while i<j do
  begin
  while (i<j)and(edge[j].w>=x.w) do
    dec(j);
  if i<j then
    begin
      edge[i]:=edge[j];
      inc(i);
    end;
  while (i<j)and(edge[i].w<=x.w) do
    inc(i);
  if i<j then
    begin
      edge[j]:=edge[i];
      dec(j);
    end;
  end;
  edge[i]:=x;
  if s<i-1 then
    qsort(s,i-1);
  if i+1<t then
    qsort(i+1,t);
end;
procedure kruskal;
var
  i,j,mb,me:longint;
begin
  for i:=1 to n do
    father[i]:=i;
  i:=1;
  j:=1;
  while i<=n-1 do
    begin
      mb:=getfather(edge[j].beg);
      me:=getfather(edge[j].en);
      if mb<>me then
        begin
          mincost:=mincost+edge[j].w;
          inc(i);
          union(mb,me);
        end;
      inc(j);
    end;
end;
begin
  readln(len);
  readln(n);
  e:=0;
  while not eof do
    begin
      inc(e);
      readln(edge[e].beg,edge[e].en,edge[e].w);
    end;
  if e<n-1 then
    begin
      write('Impossible');
      exit;
    end;
  mincost:=0;
  qsort(1,e);
  kruskal;
  if mincost<=len then
    write('Need ',mincost:0:2,' miles of cable')
  else
    write('Impossible');
end.
