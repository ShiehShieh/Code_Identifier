program p1195;
Var
 hash:array[-100001..100001] of longint;
 n,i,ans,temp:longint;
 x:0..1;
Begin
 readln(n);
 for i:=1 to n do
  begin
   read(x);
   if x=1 then temp:=temp+1 else temp:=temp-1;
   if hash[temp]=0 then
    hash[temp]:=i
   else
    if i-hash[temp]>ans then ans:=i-hash[temp];
   if (temp=0) and  (i>ans) then ans:=i;
  end;
 writeln(ans);
End.

