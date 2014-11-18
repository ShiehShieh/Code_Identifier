 var name:array[1..101,1..21]of char;
    q,b,l:array[1..101]of integer;
    m:array[1..101]of longint;
    g,w:array[1..101]of boolean;
    c,p,p1,c1,c2:char;
    i,n,most:integer;
    a:array[1..101]of integer;
    sum,max:longint;
 begin
  readln(n);
  for i:=1 to n do
  begin
   m[i]:=0;a[i]:=1;
   read(name[i,1]);
   while name[i,a[i]]<>' ' do
    begin
     a[i]:=a[i]+1;
     read(name[i,a[i]])
    end;
   readln(q[i],b[i],c,c1,p,c2,l[i]);
   if c1='Y' then g[i]:=true else g[i]:=false;
   if c2='Y' then w[i]:=true else w[i]:=false;
  end;
  for i:=1 to n do
  begin
   if (q[i]>80)and(l[i]>0) then m[i]:=m[i]+8000;
   if (q[i]>85)and(b[i]>80) then m[i]:=m[i]+4000;
   if q[i]>90 then m[i]:=m[i]+2000;
   if (q[i]>85)and (w[i]=true) then m[i]:=m[i]+1000;
   if (b[i]>80)and (g[i]=true) then m[i]:=m[i]+850;
  end;
  max:=m[1];most:=1;
  for i:=2 to n do
  if m[i]>max then
   begin
    max:=m[i];
    most:=i;
   end;
  sum:=0;
  for i:=1 to n do
  sum:=sum+m[i];
  for i:=1 to a[most]-1 do
  write(name[most,i]);
  writeln;
  writeln(m[most]);
  writeln(sum);
  end. 


