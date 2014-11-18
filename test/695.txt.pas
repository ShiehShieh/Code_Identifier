program vj1518;
const  maxn=101;maxk=101;infi=2000000001;
type tree=record
    d,w,ch,br,fa:integer;
    end;
var t:array[0..maxn]of tree;
    f:array[0..maxn,0..maxn,0..maxn]of int64;
    i,j,l,n,m:longint;
function minx(x,y:int64):int64;
begin
    if x>y then minx:=y else minx:=x;
end;
function xdp(i,root,k,total:longint):int64;
var j:integer;s:int64;
begin
 if(i=-1) then
    if(k=0) then begin xdp:=0;exit;end
    else begin xdp:=infi; exit;end;
 if(f[i,root,k]>=0) then  begin xdp:=f[i,root,k]; exit;end;
 s:=infi;
 for j:=0 to k-1 do
    s:=minx(s,xdp(t[i].ch,i,j,0)+xdp(t[i].br,root,k-1-j,total));
 for j:=0 to k do
    s:=minx(s,(total+t[i].d)*t[i].w+xdp(t[i].ch,root,j,total+t[i].d)+xdp(t[i].br,root,k-j,total));
 f[i,root,k]:=s;
 xdp:=s;
end;
begin
  readln(n,m);
  for i:=1 to n do
    begin
      readln(t[i].w,t[i].fa,t[i].d);
      t[i].br:=t[t[i].fa].ch;
      t[t[i].fa].ch:=i;
    end;
  for i:=1 to n do
    begin
      if t[i].ch=0 then t[i].ch:=-1;
      if t[i].br=0 then t[i].br:=-1;
    end;
  for i:=0 to n do
    for j:=0 to n do
      for l:=0 to n do
        begin
            f[i,j,l]:=-1;

        end;
  writeln(xdp(t[0].ch,0,m,0));
end.

