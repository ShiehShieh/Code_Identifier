const
 maxn=200000;
 maxv=400001;
var f:array[1..maxv]of longint;
    a:array[1..maxn]of longint;
    n,m,i,ans,x,y:longint;
procedure build(v,s,t:longint);
 begin
  f[v]:=a[s];
  if s<t then
   begin
    build(v shl 1,s,(s+t)shr 1);
    build(v shl 1+1,(s+t)shr 1+1,t);
    f[v]:=f[v shl 1];
    if f[v]<f[v shl 1+1] then
     f[v]:=f[v shl 1+1];
   end;
 end;
procedure find(v,s,t:longint);
 begin
  if (x<=s)and(y>=t) then
   begin
    if ans<f[v] then
     ans:=f[v];
    exit;
   end;
  if x<=(s+t) shr 1 then
   find(v shl 1,s,(s+t) shr 1);
  if y>(s+t) shr 1 then
   find(v shl 1+1,(s+t) shr 1+1,t);
 end;
begin
 readln(n);
 for i:=1 to n do
  read(a[i]);
 fillchar(f,sizeof(f),0);
 build(1,1,n);
 readln(m);
 for i:=1 to m do
  begin
   readln(x,y);
   ans:=-maxlongint;
   find(1,1,n);
   write(ans);
  end;
end.          
