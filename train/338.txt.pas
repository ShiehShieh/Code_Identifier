program P1125;
const
e=0.00001;
g=10;
var
n:longint;
left,right,min,max,l,h,s,v,k:real;
begin
readln(h,s,v,l,k,n);
min:=sqrt((h-k)/g*2);{算能接住的最小值}
max:=sqrt(h/g*2);{算能接住的最大值}
left:=s-v*max;
right:=trunc(s+l-v*min+e);
if left-e=trunc(left-e) then{是整数就剪去}
    left:=trunc(left-e)
else
    left:=trunc(left-e)+1;{不然就进1}
if left<0 then left:=0;
if right>n-1 then right:=n-1;
if left>right then{看看有没有区间}
    writeln(0)
else
    writeln(right-left+1:0:0);{算能接住多少个球}
end. 
