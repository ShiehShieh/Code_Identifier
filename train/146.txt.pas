var
  i,j,k,n,m,o,sum,kewu:longint;
  s:string;
  a:array[0..100]of longint;
  ss,xx:array[1..100]of string;
  b:array[1..100]of boolean;
begin
  readln(n);
  readln(s);
  fillchar(b,sizeof(b),true);
for i:=1 to n do
  readln(ss[i]);

a[0]:=0;
for i:=1 to length(s)-1 do
if s[i]=' '
then begin
inc(k);
a[k]:=i;
xx[k]:=copy(s,a[k-1]+1,a[k]-a[k-1]-1);
end;
inc(k);
a[k]:=length(s)+1;
if k=1
then m:=1
else m:=2;
xx[k]:=copy(s,a[k-1]+1,a[k]-a[k-1]-m);

for i:=1 to k do
begin
 for j:=1 to n do
  if length(xx[i])=length(ss[j])
  then begin
       m:=0;
       for o:=1 to length(xx[i]) do
       if (xx[i][o]<>ss[j][o])and((o<>1)or(xx[i][o]<>chr(ord(ss[j][o])-32)))
       then inc(m);
       if m=1
       then begin
            inc(sum);
            xx[i]:=ss[j];
            break;
            end;
       end;
end;
writeln(sum);
if ord(xx[1][1])>90
then xx[1][1]:=chr(ord(xx[1][1])-32);
for i:=1 to k-1 do
write(xx[i],' ');
if s[length(s)]<>' '
then write(xx[k],'!')
else write(xx[k]);
end.

