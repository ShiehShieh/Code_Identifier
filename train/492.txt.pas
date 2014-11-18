program vijos_p1512;
const
  maxn=1024;
var
  n,m:longint;
  l:array[1..maxn]of longint;
  t:array[1..maxn,1..maxn]of longint;
procedure update(x,y,det:longint);
  var
    tx,ty:longint;
  begin
    tx:=x;
    while tx<=n do
      begin
        ty:=y;
        while ty<=N do
          begin
            inc(t[tx,ty],det);
            inc(ty,l[ty]);
          end;
        inc(tx,l[tx]);
      end;
  end;
function getsum(x,y:longint):longint;
  var
    s,tx,ty:longint;
  begin
    s:=0;
    tx:=x;
    while tx>0 do
      begin
        ty:=y;
        while ty>0 do
          begin
            inc(s,t[tx,ty]);
            ty:=ty-l[ty];
          end;
        dec(tx,l[tx]);
      end;
    exit(s);
  end;
procedure init;
  var
    i:longint;
  begin
    readln(n);
    for i:=1 to n do l[i]:=i and(-i);
    fillchar(t,sizeof(t),0);
  end;
procedure main;
  var
    i,x,y,k,m,x1,y1,x2,y2:longint;
  begin
    m:=0;
    while m<>3 do
      begin
        read(m);
        if m=1 then
          begin
            readln(x,y,k);
            update(x+1,y+1,k);
          end
        else if m=2 then
          begin
            readln(x1,y1,x2,y2);
            writeln(getsum(x2+1,y2+1)-getsum(x1,y2+1)-getsum(x2+1,y1)+getsum(x1,y1));
          end;
      end;
  end;
begin
  init;
  main;
end.
