program Vijos_P1518;
type
  re=record
    left,right,dist:longint;
  end;
const
  maxnum=1000000000;
var
  tree:array[0..100] of re;
  f:array[0..100,0..100,0..50] of longint;
  w:array[0..100] of longint;
  n,k,ans:longint;

function cal(from,pre,k,total:longint):longint;
  var
    min,t,i,d:longint;
  begin
    if from=-1 then
      if k=0 then exit(0) else exit(maxnum);
    if f[from,pre,k]>-1 then exit(f[from,pre,k]);
    with tree[from] do
      begin
        min:=maxnum;
        for i:=0 to k-1 do
          begin
            t:=cal(right,from,i,0)+cal(left,pre,k-i-1,total);
            if t<min then min:=t;
          end;
        for i:=0 to k do
          begin
            d:=dist+total;
            t:=d*w[from]+cal(right,pre,i,d)+cal(left,pre,k-i,total);
            if t<min then min:=t;
          end;
      end;
    f[from,pre,k]:=min;
    exit(min);
  end;

procedure init;
  var
    i,j,v,d,t,p:longint;
  begin
    readln(n,k);
    for i:=0 to n do
      begin
        tree[i].left:=-1;
        tree[i].right:=-1;
      end;
    for i:=1 to n do
      begin
        readln(w[i],v,d);
        tree[i].dist:=d;
        tree[i].left:=tree[v].right;
        tree[v].right:=i;
      end;
  end;

procedure work;
  begin
    fillchar(f,sizeof(f),255);
    ans:=cal(tree[0].right,0,k,0);
  end;

procedure print;
  begin
    writeln(ans);
  end;

begin
  init;
  work;
  print;
end.


