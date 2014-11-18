var
   s,t,w,i:integer;
   s1,s2:string[26];
   a:array[0..26] of longint;
procedure shu;
var
i:integer;
begin
    s2:='';
    for i:=1 to w do
    s2:=s2+chr(a[i]+ord('a')-1);
    writeln(s2);
end;
procedure wk(k:integer);
var
i:integer;
begin
    if k>0 then
    if a[k]<t+k-w then
       begin
         inc(a[k]);
         for i:=k+1 to w do a[i]:=a[i-1]+1;
         shu;
       end else wk(k-1);
end;
begin
    readln(s,t,w);
    readln(s1);
    for i:=1 to w do a[i]:=ord(s1[i])-ord('a')+1;
    for i:=1 to 5 do wk(w);
end.

