var
  n,m:int64;
  i,j,t:integer;
  jc:array[0..20] of int64;
  num:array[0..20] of integer;
  first:boolean;
begin
  first:=true;
  readln(n,m);
  for i:=0 to n-1 do
    num[i]:=i+1;
  jc[0]:=1;
  jc[1]:=1;
  for i:=2 to n-1 do
    jc[i]:=jc[i-1]*i;
  for i:=1 to n do
    begin
      t:=(m-1) div jc[n-i];
      if first
        then begin
          first:=false;
          write(num[t]);
        end
        else write(' ',num[t]);
      for j:=t to n-i do
        num[j]:=num[j+1];
      m:=((m-1) mod jc[n-i])+1;
    end;
  writeln;
end.
