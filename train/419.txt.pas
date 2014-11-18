program duorenbao;
const
  maxn=200;
  maxm=5000;
  maxk=40;
var
  f:array[0..maxm,0..maxk+1]of longint;
  w:array[1..maxn]of longint;
  v:array[1..maxn]of integer;
  q:array[1..maxn]of longint;
  i,j,k,m,n:integer;
  ans:longint;

procedure qsort(l,r:integer);
var
  i,j:integer;
  m,s:longint;
begin
  i:=l;j:=r;
  m:=q[l+random(r-l+1)];
  repeat
    while q[i]>m do inc(i);
    while q[j]<m do dec(j);
    if i<=j then
      begin
      s:=w[i];w[i]:=w[j];w[j]:=s;
      s:=v[i];v[i]:=v[j];v[j]:=s;
      s:=q[i];q[i]:=q[j];q[j]:=s;
      inc(i);dec(j);
      end;
  until i>=j;
  if l<j then qsort(l,i);
  if i<r then qsort(i,r);
end;

procedure xx;
var
  ii,jj,kk:integer;
  a:array[0..maxk+1]of longint;
begin
  fillchar(a,sizeof(a),0);
  if f[j][0]+f[j-v[i]][0]<k then a[0]:=f[j][0]+f[j-v[i]][0]
                            else a[0]:=k;
  ii:=1;jj:=1;
  for kk:=1 to a[0] do
    if (f[j,ii]>f[j-v[i],jj]+w[i])or(jj>f[j-v[i],0]) then
      begin a[kk]:=f[j,ii];inc(ii);end
                                                     else
      begin a[kk]:=f[j-v[i],jj]+w[i];inc(jj);end;
  f[j]:=a;
end;


begin
readln(k,m,n);
for i:=1 to n do
  begin
  readln(v[i],w[i]);
  q[i]:=w[i]div v[i];
  end;
qsort(1,n);

fillchar(f,sizeof(f),0);
f[0,0]:=1;
for i:=1 to n do
  for j:=m downto v[i] do
    if (f[j-v[i],0]<>0)and(f[j,k]<f[j-v[i],1]+w[i])then xx;

ans:=0;
for i:=1 to k do inc(ans,f[m,i]);
writeln(ans);
end.
