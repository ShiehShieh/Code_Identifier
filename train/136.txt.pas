program p1518;
const filename='p1518';
var
  a:array[0..101,0..101]of longint;
  h:array[0..101,0..51]of int64;
  f:array[0..101,0..51,0..101]of int64;
  b,w,s,sum,d:array[0..101]of longint;
  dep,i,k,n,fa,t,j:longint;
function min(x,y:int64):int64;
begin if x<y then exit(x) else exit(y); end;
procedure dfs(x:longint);
var i,j,t,l,o:longint;
begin
  inc(dep); s[dep]:=x; sum[dep]:=sum[dep-1]+d[x];
  for i:=1 to b[x] do dfs(a[x,i]);
  ////// 在x处建 //////////
  for i:=1 to 101 do
    for j:=0 to 51 do h[i,j]:=maxlongint;
  for i:=1 to b[x] do
    for j:=0 to k do
      for l:=0 to j do
        h[i,j]:=min(h[i,j],h[i-1,j-l]+f[a[x,i],l,x]);
  for i:=1 to k do
    for j:=1 to dep-1 do
      f[x,i,s[j]]:=h[b[x],i-1];
  ////// 不在x处建 //////////
  if dep>1 then
   for i:=1 to 101 do
    for j:=0 to 51 do h[i,j]:=maxlongint;
  for o:=1 to dep-1 do
  begin
    t:=s[o];
    for i:=1 to b[x] do
      for j:=0 to k do
        for l:=0 to j do
          h[i,j]:=min(h[i,j],h[i-1,j-l]+f[a[x,i],l,t]);
    for i:=0 to k do
      f[x,i,t]:=min(f[x,i,t],h[b[x],i]+w[x]*(sum[dep]-sum[o]));
  end;
  dec(dep);
end;
begin
  readln(n,k);
  for i:=0 to n do b[i]:=0;
  for i:=1 to n do
  begin
    readln(w[i],fa,d[i]);
    inc(b[fa]); a[fa,b[fa]]:=i;
  end;
  for i:=0 to 101 do
    for j:=0 to 51 do
      for t:=0 to 101 do f[i,j,t]:=maxlongint;
  dep:=0;  dfs(0);
  writeln(h[b[0],k]);
end.  
