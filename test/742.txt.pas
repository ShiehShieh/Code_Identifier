type
  new=record
    l,r:longint;
    max:int64;
end;
var
  tree:array[1..800000]of new;
  i,j,k,n,m:longint;
  ans:int64;
procedure build(x,y,t:longint);
var
  mid:longint;
begin
  tree[t].l:=x;tree[t].r:=y;
  tree[t].max:=-9223372036854775808;
  mid:=(x+y) div 2;
  if x=y then exit;
  build(x,mid,t*2);build(mid+1,y,t*2+1);
end;
procedure insert(t:longint);
begin
  if tree[t].max<j then tree[t].max:=j;
  if tree[t].l=tree[t].r then exit;
  if i<=tree[t*2].r then insert(t*2) else insert(t*2+1);
end;
procedure check(x,y,t:longint);
begin
  if (x<=tree[t].l) and (tree[t].r<=y) then
    begin
      if ans<tree[t].max then ans:=tree[t].max;
    exit;end;
  if tree[t].r=tree[t].l then exit;
  if (y<=tree[t*2].r) then check(x,y,t*2);
  if (x>tree[t*2].r) then check(x,y,t*2+1);
  if (x<=tree[t*2].r) and (y>tree[t*2].r) then
    begin check(x,tree[t*2].r,t*2);check(tree[t*2+1].l,y,t*2+1); end;
end;
begin
  readln(n);
  build(1,n,1);
  for i:=1 to n do
    begin
      read(j);
      insert(1);
    end;
  readln(m);
  for i:=1 to m do
    begin
      ans:=-9223372036854775808;
      readln(j,k);
      check(j,k,1);
      write(ans,' ');
    end;
end.
