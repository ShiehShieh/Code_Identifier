const di:array[1..4,1..2]of integer=((0,-1),(-1,0),(0,1),(1,0));
var map:array[0..501,0..501]of char;
pd:array[0..501,0..501]of boolean;
 n,m,m1,n1:longint;
procedure into;
 var i,j:longint;
 begin
readln(n,n1);
m1:=0;m:=0;
for i:=0 to n1+1 do map[0,i]:='0';
for i:=0 to n+1 do map[i,0]:='0';
for i:=0 to n+1 do map[i,n1+1]:='0';
for i:=0 to n1+1 do map[n+1,i]:='0';
 for i:=1 to n do
begin
 for j:=1 to n1 do
 begin
read(map[i,j]);
 if map[i,j]='*'
 then inc(m);
 end;
 readln;
end;
end;
procedure floodfill(x,y:longint);
 var i,j:longint;
 begin
inc(m1);
pd[x,y]:=true;
for i:=1 to 4 do
 if (x+di[i,1]>=0) and (y+di[i,2]>=0) and(x+di[i,1]<=n+1) and (y+di[i,2]<=n1+1) and (pd[x+di[i,1],y+di[i,2]]=false) and (map[x+di[i,1],y+di[i,2]]='0')
 then floodfill(x+di[i,1],y+di[i,2]);
end;
procedure print;
 begin
writeln((n+2)*(n1+2)-m1-m);
 end;
begin
 into;
 floodfill(0,0);
 print;
end.
