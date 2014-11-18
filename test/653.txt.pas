const maxans=9223372036854775807;
const maxn=200000+5;
var i,j,m:longint;
    f,l,from,a,point,now,p,last:array[1..maxn] of int64;
    worked:array[1..maxn] of boolean;
    ans,k,n,num,rank:int64;
procedure insert(x,y,z:int64);
begin
  inc(num);
  from[num]:=x;
  l[num]:=z;
  point[num]:=y;
  last[num]:=now[y];
  now[y]:=num;
end;
procedure visited(x:int64);
var i,j:int64;
begin
  worked[x]:=true;
  i:=from[x];
  j:=now[i];
  while j<>0 do
   begin
     if from[j]<>point[x] then
      begin
       if not worked[j] then visited(j);
       inc(p[x],p[j]);
       inc(f[x],f[j]);
      end;
     j:=last[j];
   end;
  inc(p[x],a[from[x]]);
  inc(f[x],p[x]*l[x]);
end;
begin
  readln(n);
  for i:=1 to n do read(a[i]);
  for m:=1 to n-1 do
   begin
     readln(i,j,k);
     insert(i,j,k);
     insert(j,i,k);
   end;
  fillchar(p,sizeof(p),0);
  fillchar(worked,sizeof(worked),0);
  for i:=1 to num do
   if not worked[i] then visited(i);
  ans:=maxans;
  for i:=1 to n do
   begin
     k:=0;
     j:=now[i];
     while j<>0 do
      begin
        inc(k,f[j]);
        j:=last[j];
      end;
     if ans>k then
      begin
        rank:=i;
        ans:=k;
      end;
   end;
  writeln(rank);
  writeln(ans);
end.
