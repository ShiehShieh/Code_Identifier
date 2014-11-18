 var
 v,ca:array[0..501,0..501]of boolean;
 f,h:array[0..501,0..501]of longint;
 r,c,i,j,k,l,m,n,max,ans:longint;

function try(a,b:longint):boolean;
 begin
  try:=false;
  if ca[a,b]=true then begin try:=true;exit;end;
  if f[a,b+1]<f[a,b] then begin v[a,b+1]:=true;if try(a,b+1) then begin try:=true;ca[a,b+1]:=true;if h[a,b+1]+1>h[a,b] then h[a,b]:=h[a,b+1]+1;end;end;
  if f[a,b-1]<f[a,b] then begin v[a,b-1]:=true;if try(a,b-1) then begin try:=true;ca[a,b-1]:=true;if h[a,b-1]+1>h[a,b] then h[a,b]:=h[a,b-1]+1;end;end;
  if f[a+1,b]<f[a,b] then begin v[a+1,b]:=true;if try(a+1,b) then begin try:=true;ca[a+1,b]:=true;if h[a+1,b]+1>h[a,b] then h[a,b]:=h[a+1,b]+1;end;end;
  if f[a-1,b]<f[a,b] then begin v[a-1,b]:=true;if try(a-1,b) then begin try:=true;ca[a-1,b]:=true;if h[a-1,b]+1>h[a,b] then h[a,b]:=h[a-1,b]+1;end;end;
  if not try then begin ca[a,b]:=true;try:=true;h[a,b]:=1;end;
 end;

begin
 readln(r,c);
  for i:=1 to r do
   begin
    for j:=1 to c do
     read(f[i,j]);
    readln;
   end;

  for i:=0 to c+1 do
   begin
    f[0,i]:=maxlongint;
    f[r+1,i]:=maxlongint;
   end;
  for i:=0 to r+1 do
   begin
    f[i,0]:=maxlongint;
    f[i,c+1]:=maxlongint;
   end;

  for i:=1 to r do
   for j:=1 to c do
   if not v[i,j] then
    begin
     v[i,j]:=true;
     if try(i,j)
     then if h[i,j]>max
          then max:=h[i,j];
    end;
 writeln(max);
end.


