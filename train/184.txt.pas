program xuanke;
const
  maxn=300;
var
  f:array[0..maxn,0..maxn]of integer;
  son:array[0..maxn,0..maxn]of integer;
  a,ans:array[0..maxn]of integer;
  ii,jj,m,n:integer;


procedure xx(x:integer);
var
  i,j,k:integer;
begin
for i:=1 to son[x,0] do xx(son[x,i]);
fillchar(ans,sizeof(ans),0);
for i:=1 to son[x,0] do
  for j:=m downto 0 do
    for k:=0 to j do
    if ans[j-k]+f[son[x,i],k]>ans[j] then
      ans[j]:=ans[j-k]+f[son[x,i],k];
for i:=1 to m do f[x,i]:=ans[i-1]+a[x];
end;


begin
readln(n,m);
fillchar(son,sizeof(son),0);
fillchar(f,sizeof(f),0);
fillchar(a,sizeof(a),0);
for ii:=1 to n do
  begin
  read(jj,a[ii]);
  inc(son[jj,0]);
  inc(son[jj,son[jj,0]],ii);
  end;
xx(0);
write(ans[m]);
end.
