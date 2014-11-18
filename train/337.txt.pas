program haoshui;
var
a,b,c,d,e,f,g:longint;
m,n,k:longint;
arr,brr,crr:array[0..300000] of longint;
function main(a,n:longint):longint;
var
i,x,l,r,mid:longint;
begin
if a>n then exit(0);
m:=1;
crr[1]:=brr[a];
for i:=a+1 to n do begin
 x:=brr[i];
 if x>crr[m] then begin inc(m); crr[m]:=x; end;
 l:=1; r:=m;
 while l<r do begin
  mid:=(l+r) div 2;
  if crr[mid]<x then l:=mid+1 else r:=mid;
 end;
 crr[l]:=x;
end;
main:=m;
end;

begin
readln(n,k);
for a:=1 to n do read(arr[a]);
brr[0]:=0;
for a:=1 to k do
 if arr[a]<arr[k] then begin
  inc(brr[0]);
  brr[brr[0]]:=arr[a];
 end;
e:=brr[0];
inc(brr[0]);
brr[brr[0]]:=arr[k];
for a:=k+1 to n do
 if arr[a]>arr[k] then begin
  inc(brr[0]);
  brr[brr[0]]:=arr[a];
 end;

d:=main(1,e);
fillchar(crr,sizeof(crr),0);
f:=main(e+2,brr[0]);
writeln(d+f+1);
readln;
end.
