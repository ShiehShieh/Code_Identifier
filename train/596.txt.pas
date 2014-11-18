program boxes;
var v,n,i,min:longint;
    a,s:array[0..1000] of longint;
procedure search(k,v:longint);
  begin
    if v<min then min:=v;
    if v-(s[n]-s[k-1])>=min then exit;
    if k<=n then
      begin
        if v>=a[k] then search(k+1,v-a[k]);
        search(k+1,v);
      end;
  end;
begin
  readln(v);
  readln(n);
  s[0]:=0;
  for i:=1 to n do
  begin
    readln(a[i]);
    s[i]:=s[i-1]+a[i];
  end;
  min:=v;
  if s[n]<=v then min:=v-s[n]
  else search (1,v);
  writeln(min);
end.
