var a:array[1..5000] of string;
qm:array[1..5000] of string;
pnt:array[1..5000] of integer;
k,i,j,m,n,p,open,clsed:longint;ma:string;
procedure print;
var x,s:longint;
begin
  x:=pnt[open];s:=0;
  repeat
    x:=pnt[x];
    s:=s+1;
  until x=0;
  writeln(s);
  halt;
end;
procedure comp(ma:string);
var f:boolean;
begin
  f:=true;
  for k:=1 to open do
    if qm[k]=ma then exit;
  open:=open+1;
  qm[open]:=ma;pnt[open]:=clsed;
  for k:=1 to m do
    if ma[k]='1' then f:=false;
  if f then print;
end;
procedure op;
begin
  for j:=1 to n do begin
    ma:=qm[clsed];
    for k:=1 to m do
      if a[j][k]='2' then ma[k]:='0'
      else if a[j][k]='0' then ma[k]:='1';
    comp(ma);
  end;
end;
begin
  fillchar(a,sizeof(a),0);
  readln(m);
  readln(n);
  for i:=1 to n do begin
    for j:=1 to m do begin
      read(p);
      p:=p+1;
      a[i]:=a[i]+char(p+48);
    end;
   readln;
  end;
  qm[1]:='';clsed:=0;open:=1;pnt[1]:=0;
  for i:=1 to m do
    qm[1]:=qm[1]+'1';
  repeat
    clsed:=clsed+1;
    op;
  until (clsed>=open) or (open>=5000);
  writeln('The patient will be dead.');
end.

