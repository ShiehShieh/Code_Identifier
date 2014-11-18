program p1011;
var a,f:array[0..500,0..500]of longint;
    i,j,r,c:integer;
    max:int64;

function opt(i,j:integer):longint;
begin
  if f[i,j]>0 then exit(f[i,j]);
  if ( a[i+1,j] < a[i,j] ) and ( opt(i+1,j) > f[i,j] ) then
   f[i,j] := opt(i+1,j) ;
  if ( a[i,j+1] < a[i,j] ) and ( opt(i,j+1) > f[i,j] ) then
   f[i,j] := opt(i,j+1) ;
  if ( a[i-1,j] < a[i,j] ) and ( opt(i-1,j) > f[i,j] ) then
   f[i,j] := opt(i-1,j) ;
  if ( a[i,j-1] < a[i,j] ) and ( opt(i,j-1) > f[i,j] ) then
   f[i,j] := opt(i,j-1) ;
  inc ( f[i,j] ) ;
  exit ( f[i,j] ) ;
 end ;

begin
  readln(r,c);
  for i:=0 to r+1 do
   for j:=0 to c+1 do
     a[i,j]:=maxlongint;
  for i:=1 to r do begin
   for j:=1 to c do read(a[i,j]);
   readln;
   end;
  for i:=1 to r do
   for j:=1 to c do begin
    f[i,j]:=opt(i,j);
    if f[i,j]>max then max:=f[i,j];
    end;
  write(max);
end.

