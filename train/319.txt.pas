var
 num1,num2:array[1..10000]of longint;
 jg:array[1..20000]of longint;
 long1,long2,long,i,j:longint;
 a:ansistring; {10000位，要用ansistring才能存的下}
begin
 readln(a);
 long1:=length(a);
 for i:= 1 to long1 do
  num1[i]:=ord(a[long1-i+1])-ord('0');
 readln(a);
 long2:=length(a);
 for i:= 1 to long2 do
  num2[i]:=ord(a[long2-i+1])-ord('0');
{乘法}
 for i:= 1 to long1 do
  for j:= 1 to long2 do
   jg[i+j-1]:=num1[i]*num2[j]+jg[i+j-1];
{处理进位}
 for i:= 1 to long1+long2 do
  begin
   jg[i+1]:=jg[i] div 10+jg[i+1];
   jg[i]:=jg[i] mod 10;
  end;
{两个数相乘，一个数的位数是a，另一个是b位数，那么结果要么是a+b位，要么是a+b-1位}
 if jg[long1+long2]=0 then long:=long1+long2-1
 else long:=long1+long2;
 for i:=long downto 1 do
  write(jg[i]);
 writeln;
end.
