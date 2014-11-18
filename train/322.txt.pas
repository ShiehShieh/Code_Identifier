Var
 da,a:array[0..30] of integer;
 str,str1:string;
 summ,sum,ch,max,i,s,data,code,abc,aa:integer;
Procedure dfs(k,n,tall:integer);
var
 i:integer;
begin
 if k>aa then
 begin
if n>summ then summ:=n;
exit;
 end;
 if da[k]<=tall then dfs(k+1,n+1,da[k]);
 dfs(k+1,n,tall);
end;

Begin
 readln(str);
 max:=1;
 a[1]:=maxint-1;
 a[0]:=maxint;
 abc:=maxint;
 while str<>'' do
 begin

s:=pos(',',str);
if s=0 then
begin
  val(str,data,code);
  str:='';
end else
begin
  str1:=copy(str,1,s-1);
  val(str1,data,code);
  delete(str,1,s);
end;
inc(aa);
da[aa]:=data;
ch:=0;
for i:=1 to max do
  if (data<=a[i]) and (a[i]<a[ch]) then
ch:=i;
if ch=0 then
begin
  inc(max);
  inc(a[max],data);
end;
if ch>0 then
begin
  a[ch]:=data;
  inc(sum);
end;
 end;

 dfs(1,0,maxint);
 writeln(summ,',',max-1);
End.

