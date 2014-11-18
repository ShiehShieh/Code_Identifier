var a:array[1..250,1..250] of boolean;
use:array[1..1000] of boolean;
i,j,k,r,n,sum:integer;
procedure fly;
begin
  for k:=1 to n do
    for i:=1 to n do
      for j:=1 to n do
        if (a[i,k]) and (a[k,j]) then a[i,j]:=true;
end;
begin
  readln(n);
  fillchar(a,sizeof(a),0);
  for i:=1 to n do begin
    read(r);
    while r<>0 do begin
      a[i,r]:=true;
      read(r);
    end;
    readln;
  end;
  fly;
  sum:=0;
  fillchar(use,sizeof(use),0);
  for i:=1 to n do
    if not use[i] then begin
      inc(sum);
      for j:=i+1 to n do
        if a[i,j] then use[j]:=true;
    end;
  writeln(sum);
end.

