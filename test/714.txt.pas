program chao;
var s:string;
    i,n,k,j,m,e:integer;
  begin
   readln(n,k); e:=0;
   for i:=1 to n do
    begin
      readln(s);m:=0;
      for j:=1 to length(s) do
      if s[j]=' ' then inc(m); inc(m);
      if m>=k then inc(e);
    end;
   writeln(e);
  end.
