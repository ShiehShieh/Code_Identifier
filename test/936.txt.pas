program lt;
type
pp=record
 xmin,ymin,xmax,ymax:int64;
end;
var
map:array[1..200,1..200] of boolean;
p,q:array[1..200] of int64;
line:array[1..200] of pp;
total,d1,d2,d3,d4:int64;
f1,f2,f3:qword;
i,j,n,k,cc,cp:longint;
bb:boolean;

procedure change(var x,y:int64);
var pp:int64;
begin
  pp:=x;
  x:=y;
  y:=pp;
end;

begin
  fillchar(map,sizeof(map),0);
  total:=0;
  readln(n);

  for i:=1 to n do
   begin
     readln(d1,d2,d3,d4);
     line[i].xmin:=d1;
     line[i].ymin:=d2;
     line[i].xmax:=d3;
     line[i].ymax:=d4;

     bb:=true;
     for j:=1 to cc do
      bb:=bb and (p[j]<>d1);
     if bb then
      begin
        inc(cc);
        p[cc]:=d1;
      end;

     bb:=true;
     for j:=1 to cp do
      bb:=bb and (q[j]<>d2);
     if bb then
      begin
        inc(cp);
        q[cp]:=d2;
      end;

     bb:=true;
     for j:=1 to cc do
      bb:=bb and (p[j]<>d3);
     if bb then
      begin
        inc(cc);
        p[cc]:=d3;
      end;

     bb:=true;
     for j:=1 to cp do
      bb:=bb and (q[j]<>d4);
     if bb then
      begin
        inc(cp);
        q[cp]:=d4;
      end;
   end;


 for i:=1 to cc-1 do
  for j:=i+1 to cc do
   if p[i]>p[j] then change(p[i],p[j]);

 for i:=1 to cp-1 do
  for j:=i+1 to cp do
   if q[i]>q[j] then change(q[i],q[j]);

 for i:=1 to cc-1 do
  for j:=1 to cp-1 do
    for k:=1 to n do
       if (line[k].xmin<=p[i])and(line[k].xmax>=p[i+1]) then
        if (line[k].ymin<=q[j])and(line[k].ymax>=q[j+1]) then
         map[i,j]:=true;

 for i:=1 to cc-1 do
  for j:=1 to cp-1 do
   if map[i,j] then
    begin
     f1:=p[i+1]-p[i];
     f2:=q[j+1]-q[j];
     f3:=f1*f2;
     total:=total+f3;
    end;
 writeln(total);
end.

