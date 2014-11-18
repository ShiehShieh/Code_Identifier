program p1180;
var i,j,k,m,n,wh:longint;
    a:array [0..300,0..300] of longint;
    f:array [0..300,0..300] of longint;
    s:array [0..300] of longint;
    w,num:array [0..300] of longint;
procedure work(v:longint);
var i,j:longint;
begin
  for i:=1 to num[v] do
    work(a[v,i]);
  fillchar(s,sizeof(s),0);
  for i:=1 to num[v] do
  begin
    for j:=m downto 0 do
    begin
      for k:=0 to m do
        if j+k<=m then if s[j]+f[a[v,i],k]>s[j+k] then s[j+k]:=s[j]+f[a[v,i],k];
    end;
  end;
  if v=0 then
  begin
    write(s[m]);
    halt;
  end
         else
  for i:=1 to m do
    f[v,i]:=s[i-1]+w[v];
end;
begin
  readln(n,m);
  fillchar(num,sizeof(num),0);
  for i:=1 to n do
  begin
    readln(wh,w[i]);
    inc(num[wh]);
    a[wh,num[wh]]:=i;
  end;
  work(0);
end.
