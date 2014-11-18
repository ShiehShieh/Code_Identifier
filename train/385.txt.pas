program p1187;
const dd:array[1..4,1..2] of longint=((1,2),(2,1),(1,-2),(2,-1));
var i,j,m,n:longint;
tx,ty:longint;
sx,ex,ey,sy:longint;
hash:array[0..1000,0..1000] of boolean;
f:array[0..1000,0..1000] of int64;
procedure dfs(x,y:longint);
var i:longint;
begin
 if hash[x,y] then
  exit;
 for i:=1 to 4 do
  begin
 if (x-dd[i,1]  >=sx ) and (x-dd[i,1]<=m) and (y-dd[i,2]>0) and (y-dd[i,2]<=n) then
begin
 dfs(x-dd[i,1],y-dd[i,2]);
 f[x,y]:=f[x-dd[i,1],y-dd[i,2]]+f[x,y];

  end;
  end;
 hash[x,y]:=true;
end;
begin
 readln(m,n);
 readln(sx,sy);
 readln(ex,ey);
 fillchar(hash,sizeof(hash),false);
 fillchar(f,sizeof(f),0);
 f[sx,sy]:=1;
 hash[sx,sy]:=true;
 dfs(ex,ey);
 if f[ex,ey]=0 then
begin
writeln('NO');halt;
end;
 write(f[ex,ey]);
 write('00000000');
end.

