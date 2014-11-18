const
  nn=50-1;
type
  int=longint;
  list=^node;
  node=record
    p:int;
    next:list;
  end;
var //!?
  key:array[0..nn] of int;  //小精灵的书写质量..
  index:array[0..nn] of int;//记录一下这里..原先是哪一个小精灵...
  pos:array[0..nn] of int; //记录一下原先的小精灵现在在哪里...
  sum:array[0..nn] of int; //求和...用作最优性剪枝..
  adj:array[0..nn] of list;
  ans,n:int;
function max(a,b:int):int;
begin
  if a>b then exit(a)
         else exit(b);
end;
procedure insert(a,b:int);
var x:list;
begin
  new(x);x^.p:=b;x^.next:=adj[a];adj[a]:=x;
end;

procedure init;
var i,j:int;
    x,y:int;
  procedure swap(var a,b:int);
  var c:int;
  begin
    c:=a;a:=b;b:=c;
  end;
begin
  readln(n);dec(n);
  for i:=0 to n do
  begin
    read(key[i]);
    index[i]:=i;
    pos[i]:=i;
  end;

  for i:=0 to n-1 do
    for j:=i+1 to n do
      if key[i]<key[j] then begin
        swap(key[i],key[j]);
        swap(index[i],index[j]);
        pos[index[i]]:=i;pos[index[j]]:=j;
      end;

  sum[n]:=key[n];
  for i:=n-1 downto 0 do
    sum[i]:=sum[i+1]+key[i];

  while not eof do
  begin
    readln(x,y);
    dec(x);dec(y);
    x:=pos[x];y:=pos[y];
    if x<y then swap(x,y);
    insert(x,y);
  end;
end;

procedure patch;
var i,j:int;
begin
  for i:=1 to 100000 do
    for j:=1 to 100000 do
    begin
    end;
end;
          // 状态集合，累计分数、已经搜索到的位置..
procedure dfs(stt:int64;tot,l:int);
var i:Int;
  function check(u:int):boolean;
  var x:list;
  begin
    x:=adj[u];
    while (x<>nil) and ((stt and (int64(1) shl x^.p))=0) do
      x:=x^.next;
    if x=nil then exit(true)
             else exit(false);
  end;
begin
  if tot+sum[l]<ans then exit;
  ans:=max(ans,tot);
  for i:=l to n do
  begin
    if not check(i) then continue;
    dfs(stt or int64(1) shl i,tot+key[i],i+1);
  end;
end;

begin
  init;dfs(0,0,0);
  writeln(ans);
  //patch;
end.
        
