var i,j,k,l,m,n:longint;
    zb:array[1..100000,1..2] of int64;
    mid,ans:extended;
procedure qsort(x,y:longint);
var l,r:longint;
    g1,g2,t:int64;
begin
{ if y-x<10 then
 begin
  for g1:=x to y-1 do
   for g2:=g1+1 to y do
    if (zb[g1,1]>zb[g2,1])or((zb[g1,1]=zb[g2,1])and(zb[g1,2]>zb[g2,2])) then
     begin
      t:=zb[g1,1];zb[g1,1]:=zb[g2,1];zb[g2,1]:=t;t:=zb[g1,2];zb[g1,2]:=zb[g2,2];zb[g2,2]:=t;
     end;
  exit;  
 end; }  
 l:=x;r:=y;t:=(x+y) div 2;g1:=zb[t,1];g2:=zb[t,2];
 repeat
  while (zb[l,1]<g1)or((zb[l,1]=g1)and(zb[l,2]<g2)) do inc(l);
  while (zb[r,1]>g1)or((zb[r,1]=g1)and(zb[r,2]>g2)) do dec(r);
  if l<=r then
   begin
    t:=zb[l,1];zb[l,1]:=zb[r,1];zb[r,1]:=t;
    t:=zb[l,2];zb[l,2]:=zb[r,2];zb[r,2]:=t;
    inc(l);dec(r);
   end;
 until l>r;
 if x<r then qsort(x,r);
 if l<y then qsort(l,y);
end;  
function f(a1,a2,a3,a4:int64):extended;  
var mid:extended;
begin
 mid:=(a2-a1)*(a2-a1)+(a4-a3)*(a4-a3);
 f:=sqrt(mid);
end;
begin
 read(n);
 for i:=1 to n do read(zb[i,1],zb[i,2]);
 qsort(1,n);
 //for i:=1 to n do writeln(zb[i,1],' ',zb[i,2]);
 ans:=1000000000000000000000000000000000000;
 for i:=1 to n-1 do
  begin
   for j:=i+1 to n do
    begin
     if zb[j,1]-zb[i,1]>=ans then break;
     mid:=f(zb[i,1],zb[j,1],zb[i,2],zb[j,2]);
     if mid<ans then ans:=mid;
    end;
  end;
 writeln(ans:0:3); 
end.
