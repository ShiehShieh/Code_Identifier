var
 a:array[0..41,0..41] of longint;
 b:array[0..41,0..41,0..41,0..41]of longint;
  s,i,j,k,l,n,m,x:longint;

  procedure init;
   begin
    fillchar(a,sizeof(a),0);
    readln(n);
     for i:=1 to n do
     begin
      for j:=1 to n do
begin
       read(a[i,j]);
end;
      readln;
     end;
     end;

function max(p1,p2,p3,p4,p5,p6,p7,p8:longint):longint;
begin
 max:=0;
 if p1>p2 then max:=p1
 else max:=p2;
 if p3>max then max:=p3;
 if p4>max then max:=p4;
 if p5>max then max:=p5;
 if p6>max then max:=p6;
 if p7>max then max:=p7;
 if p8>max then max:=p8;
end;


  procedure dp;
    begin
     for i:=1 to n*2 do
     for j:=1 to n do
     for k:=1 to n do
     for l:=1 to n do
if (( (i-l)>0) and ( (i-j)>0) and ( (i-k)>0)) then
      begin
      b[i,j,k,l]:=max(b[i-1,j-1,k,l],b[i-1,j,k-1,l],b[i-1,j,k,l-1],b[i-1,j-1,k-1,l],b[i-1,j-1,k,l-1],b[i-1,j,k-1,l-1],b[i-1,j-1,k-1,l-1],b[i-1,j,k,l]);
      for x:= 1 to n do
  begin
 if x in [l,j,k] then
  b[i,j,k,l] := b[i,j,k,l] + a[x,i-x];
       end;
end;
end;

 begin
init;
dp;
 writeln(b[2*n,n,n,n]);
end.

