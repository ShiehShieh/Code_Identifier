program P1034;
var
father                          :array[1..5000] of integer;
i,n,m,p,a,b,fa,fb               :integer;
function getfather(x:integer):integer;
begin
  if father[x]=x then getfather := x
                 else begin
                   father[x] := getfather(father[x]);
                   getfather := father[x];
                 end;
end;
begin

  readln(n,m,p);
  for i := 1 to n do father[i] := i;
  for i := 1 to m do
    begin
      readln(a,b);
      fa := getfather(b);
      fb := getfather(a);
      father[fb] := fa;
    end;
  for i := 1 to p do
    begin
      readln(a,b);
      if getfather(a)=getfather(b) then writeln('Yes')
                                   else writeln('No');
    end;
end.
         
