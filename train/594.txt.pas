program p1098;
var
   n,i,j:integer;
   a,b:array[0..100]of integer;
   g,h:array[1..100]of byte;
begin
  readln(n);
  for i:=1 to n do
   begin
    read(a[i]);
    b[i]:=a[i];
   end;
 // 赋初值
   for i:=1 to n do
   begin
     g[i]:=1;
     h[i]:=1;
   end;
// 最长不下降子序列；
  for i:=1 to n-1 do
     for j:=i+1 to n do
         if (a[j]>a[i])and(g[j]<=g[i]) then g[j]:=g[i]+1;

//   最长不上升子序列；
  for i:=n-1 downto 1 do
    for j:=i+1 to n do
       if (a[i]>a[j])and(h[i]<=h[j]) then h[i]:=h[j]+1;
     j:=0;
// 枚举求出N项为中点时的个数
   for i:=1 to n do
      if j<g[i]+h[i]-1 then j:=g[i]+h[i]-1;

{  for i:=1 to n do

    writeln(g[i]);
   writeln;
 for i:=1 to n do

    writeln(h[i]);}
     writeln(n-j);
end.
