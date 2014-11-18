PROGRAM P1128;
  const
    max=20;
  var
    n,k:byte;
    a:array[1..max] of longint;
    b:array[0..max] of byte;
    i,j:integer;
    s,t:longint;
  procedure check(sum:longint);
  var
    i,j:integer;
    boo:boolean;
  begin
    boo:=true;
    for i:=2 to trunc(sqrt(sum)) do
    if sum mod i=0 then begin boo:=false; break end;
    if boo=true then inc(t);
  end;
  procedure sub(x:integer);
  var
    i,j:integer;
  begin
    if x>k then check(s)
           else begin
                  for i:=b[x-1]+1 to n do
                  begin
                    s:=s+a[i]; b[x]:=i;
                    sub(x+1);
                    s:=s-a[i]; 
                  end;
                end;
  end;
  begin
    b[0]:=0;
    s:=0; t:=0;
    readln(n,k);
    for i:=1 to n do read(a[i]);
    sub(1);
    writeln(t)
  end.
