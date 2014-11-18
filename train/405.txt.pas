var
  ans,n,k,i,sum:longint;
  x:array[1..20]of longint;
  f:array[1..20]of boolean;
function su(a:longint):boolean;
  var
    i,j:longint;
  begin
    su:=true;
    for i:=2 to round(sqrt(a))+1 do
      if a mod i =0 then exit(false);
  end;
procedure dep(s,d:integer);
  var
    i:integer;
  begin
    if d=k+1
      then begin
             if su(sum) then inc(ans);
             exit;
           end;
    for i:=s to n do
      if f[i]
        then begin
               sum:=sum+x[i];
               f[i]:=false;
               dep(i+1,d+1);
               f[i]:=true;
               sum:=sum-x[i];
             end;
  end;
begin
  readln(n,k);
  fillchar(f,sizeof(f),true);
  for i:=1 to n do read(x[i]);
  ans:=0; sum:=0;
  dep(1,1);
  writeln(ans);
end.

