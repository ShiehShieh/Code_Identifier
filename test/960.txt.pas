type
 re=record
     ill:array[1..10] of boolean;
     step:longint;
    end;
var
 tmp:array[1..2000000] of re;
 n,m,i,clos,open,j,k,l:longint;
 a:array[1..100,1..10] of shortint;
 f:boolean;
begin
 readln(n);
 readln(m);
 for i:=1 to m do
  for j:=1 to n do
   read(a[i,j]);
 for i:=1 to n do
  tmp[1].ill[i]:=true;
 tmp[1].step:=0;
 clos:=0;
 open:=1;
 repeat
  inc(clos);
  for j:=1 to m do
   begin
    inc(open);
    tmp[open]:=tmp[clos];
    inc(tmp[open].step);
    for k:=1 to n do
     if (a[j,k]=1)and(tmp[open].ill[k]) then
      tmp[open].ill[k]:=false
      else
       if (a[j,k]=-1)and(not tmp[open].ill[k]) then
        tmp[open].ill[k]:=true;
    f:=true;
    for l:=1 to n do
     if tmp[open].ill[l] then
      begin
       f:=false;
       break;
      end;
    if f then
     begin
      writeln(tmp[open].step);
      exit;
     end;
    for k:=open-1 downto 1 do
     begin
      f:=true;
      for l:=1 to n do
       if tmp[open].ill[l]<>tmp[k].ill[l] then
        begin
         f:=false;
         break;
        end;
      if f then
       begin
        dec(open);
        break;
       end;
     end; 
   end;
 until clos>=open;
 writeln('The patient will be dead.');
end.

