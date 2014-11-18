var q:array[1..105,1..105]of longint;
    a:array[0..10050]of boolean;
    m,l,i,j,q1,q2:longint;
procedure print;
var n:longint;
begin
  n:=0;
  for i:=0 to l do begin
    if a[i]=true then inc(n);
  end;
  writeln(n);
end;

procedure main;
begin
  for i:=1 to m do begin
    for j:=q[i,1] to q[i,2] do a[j]:=false;
  end;
  print;
end;

begin
  readln(l,m);
  for i:=1 to m do begin
    read(q1,q2);
    q[i,1]:=q1; q[i,2]:=q2;
  end;
  for i:=0 to l do a[i]:=true;
  main;
end.
