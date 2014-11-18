program xun_zhao_zhu_ren;
const m=1000000;
type arr=array[1..m] of char;
var pre:array[1..m] of longint;
    s:array[1..2*m] of char;
    s1,s2:arr;f:boolean;
    i,j,k,q,n:longint;
function find(var st:arr):longint;
var ch1,ch2:char;
begin
  i:=1;j:=2;k:=0;
  while (i<=n) and (j<=n) and (k<=n) do
     begin
       ch1:=st[(i+k-1) mod n+1];
       ch2:=st[(j+k-1) mod n+1];
       if ch1=ch2 then inc(k)
          else begin
                 if ch1>ch2 then inc(i,k+1) else inc(j,k+1);
                 if i=j then inc(j);k:=0;
               end;
     end;
  if i>j then exit(j) else exit(i);
end;
begin
  i:=0;j:=0;k:=0;q:=0;pre[1]:=0;f:=false;
  while not eoln do begin inc(i);read(s1[i]);end;readln;
  while not eoln do begin inc(j);read(s2[j]);end;n:=j;
  for i:=1 to n do s[i]:=s1[i];
  for i:=n+1 to 2*n do s[i]:=s1[i-n];
  for i:=2 to n do
     begin
       while (k>0) and (s2[k+1]<>s2[i]) do k:=pre[k];
       if s2[k+1]=s2[i] then inc(k);
       pre[i]:=k;
     end;
  for i:=1 to 2*n do
     begin
       while (q>0) and (s2[q+1]<>s[i]) do q:=pre[q];
       if s2[q+1]=s[i] then inc(q);
       if q=n then begin f:=true;break;end;
     end;
  if f then
     begin
       writeln('Yes');
       k:=find(s1);
       for i:=k to k+n-2 do write(s[i]);
       writeln(s[k+n-1]);
     end
  else writeln('No');
end.



