var
  np,i,j,k,t:longint;
  n:array[1..20] of string;
  n2:array[1..20,1..20] of string;
  s:array[1..20,1..3] of longint;
begin
  readln(np);
  for i:=1 to np do
    readln(n[i]);
  for i:=1 to np do begin
    readln(n2[i,1]);
    readln(s[i,1],s[i,2]);
    for j:=1 to s[i,2] do
      readln(n2[i,j+1]);
  end;
  for i:=1 to np do begin
    t:=0;
    if s[i,2]<>0 then begin
      s[i,3]:=s[i,3]+s[i,1] mod s[i,2];
      t:=s[i,1] div s[i,2];
    end;
      for j:=1 to s[i,2] do
        for k:=1 to np do
          if n2[i,j+1]=n2[k,1] then s[k,3]:=s[k,3]+t;
  end;
  for i:=1 to np do
    s[i,3]:=s[i,3]-s[i,1];
  for i:=1 to np do
    for j:=1 to np do
      if n[i]=n2[j,1] then writeln(n2[j,1],' ',s[j,3]);
end.

