var
a:array[1..2,0..100,1..2] of longint;
s,ss,min,k,n,i,j,maxi,maxj,mini,minj,mini0,minj0,maxi0,maxj0:longint;


procedure work(f, i,j:longint; var aa,b,c,d:longint);
var
q:longint;
begin
  aa:=mini0;
  b:=minj0;
  c:=maxi0;
  d:=maxj0;
  for q:=i to j do
  begin
    if  a[f,q,1]<c then c:=a[f,q,1];
    if  a[f,q,1]>aa then aa:=a[f,q,1];
    if  a[f,q,2]>b then b:=a[f,q,2];
    if  a[f,q,2]<d then d:=a[f,q,2];
  end;
end;

procedure ex(f,i,j:longint);
begin
  a[f,0]:=a[f,i];
  a[f,i]:=a[f,j];
  a[f,j]:=a[f,0];
end;

procedure hq ;
var
i,j:longint;
begin
  for i:=1 to n do
    for j:=1 to n do
      if (a[1,i,1]<a[1,j,1]) or ((a[1,i,1]=a[1,j,1]) and (a[1,i,2]>a[1,j,2]))  then ex(1,i,j)
end;

procedure lq ;
var
i,j:longint;
begin
  for i:=1 to n do
    for j:=1 to n do
      if (a[2,i,2]<a[2,j,2]) or ((a[2,i,2]=a[2,j,2]) and (a[1,i,1]>a[1,j,1]))  then ex(2,i,j)
end;


begin

readln(n,k);
for i:=1 to n do
begin
  readln(a[1,i,1],a[1,i,2]);
end;
min:=maxlongint;
work(1,1,n,maxi0,maxj0,mini0,minj0);
a[2]:=a[1];

if k=1 then
begin
  work(1,1,n,maxi,maxj,mini,minj);
  min:=(maxi-mini)*(maxj-minj);
end;
if k=2 then
begin
  hq;
  lq;
  i:=1;
  while i<=n-1 do
  begin
    while a[1,i,1]=a[1,i+1,1] do i:=i+1;
    work(1,1,i,maxi,maxj,mini,minj);
    s:=(maxi-mini)*(maxj-minj);
    work(1,i+1,n,maxi,maxj,mini,minj);
    s:=s+(maxi-mini)*(maxj-minj);
    if s<min then min:=s;
    i:=i+1;
  end;
  i:=1;
  while i<=n-1 do
  begin
    while a[2,i,2]=a[2,i+1,2] do i:=i+1;
    work(2,1,i,maxi,maxj,mini,minj);
    s:=(maxi-mini)*(maxj-minj);
    work(2,i+1,n,maxi,maxj,mini,minj);
    s:=s+(maxi-mini)*(maxj-minj);
    if s<min then min:=s;
    i:=i+1;
  end;

end;

if k=3 then
begin
  hq;
  lq;
  i:=1;
  while i<=n-1 do
  begin
    while a[1,i,1]=a[1,i+1,1] do i:=i+1;
    work(1,1,i,maxi,maxj,mini,minj);
    s:=(maxi-mini)*(maxj-minj);
    j:=i+1;
    while j<=n-1 do
    begin
      while a[1,j,1]=a[1,j+1,1] do j:=j+1;
      work(1,i+1,j,maxi,maxj,mini,minj);
      ss:=(maxi-mini)*(maxj-minj);
      work(1,j+1,n,maxi,maxj,mini,minj);
      ss:=ss+(maxi-mini)*(maxj-minj);
      if s+ss<min then min:=s+ss;
      j:=j+1;
    end;
    i:=i+1;
  end;

  i:=1;
  while i<=n-1 do
  begin
    while a[2,i,2]=a[2,i+1,2] do i:=i+1;
    work(2,1,i,maxi,maxj,mini,minj);
    s:=(maxi-mini)*(maxj-minj);
    j:=i+1;
    while j<=n-1 do
    begin
      while a[2,j,2]=a[2,j+1,2] do j:=j+1;
      work(2,i+1,j,maxi,maxj,mini,minj);
      ss:=(maxi-mini)*(maxj-minj);
      work(2,j+1,n,maxi,maxj,mini,minj);
      ss:=ss+(maxi-mini)*(maxj-minj);
      if s+ss<min then min:=s+ss;
      j:=j+1;
    end;
    i:=i+1;
  end;

end;
writeln(min);

end.
