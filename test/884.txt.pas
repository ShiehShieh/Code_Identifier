program tn;
var
 i,j,a,b,n,t,ans:integer;
 f:array[0..1001]of integer;
begin
 readln(n);readln(t);
 for i:=1 to n do
  begin
   readln(a,b);
   for j:=t downto b do if(f[j-b]+a>f[j])then f[j]:=f[j-b]+a;
  end;
 ans:=0;
 for i:=0 to t do if(f[i]>ans)then ans:=f[i];
 writeln(ans);
end.      
