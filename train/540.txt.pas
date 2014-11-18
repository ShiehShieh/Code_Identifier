program zjf;
var
a,b,c,d,i,j,m,n:real;
k,t,l:integer;
ao:array[1..3]of real;
function fc(x:real):real;
begin
fc:=a*x*x*x+b*x*x+c*x+d;
end;
procedure jie(m,n:real);
var
i0,j0:integer;
begin
repeat
     i:=i+0.001; {控制精度}
     if fc(m)*fc(i)<0 then begin l:=l+1;ao[l]:=i;m:=i; jie(m,n); end;        {利用二分法求解}
until l=3;    {计数，到三个解为止}
end;
begin
read(a,b,c,d); m:=-100;n:=100;
i:=m; j:=n; l:=0;
jie(-100,100);
for k:=1 to 2 do write(ao[k]:0:2,' ');
write(ao[3]:0:2);   {已经按从大到小排好}
end.
