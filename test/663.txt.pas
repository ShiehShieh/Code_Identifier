type atype=array[0..1000]of integer;
var n,i,j,k:longint;
    one,ans:atype;
function add(a,b:atype):atype;
var i,j,k:longint;
begin
  fillchar(add,sizeof(add),0);
  add[0]:=a[0];
  if a[0]<b[0] then add[0]:=b[0];
  k:=0;
  for i:=1 to add[0] do
  begin
    add[i]:=a[i]+b[i]+k;
    k:=add[i] div 10;
    add[i]:=add[i] mod 10;
  end;
  if k>0 then
  begin
    inc(add[0]);
    add[add[0]]:=k;
  end;
end;
begin
  read(n);
  fillchar(ans,sizeof(ans),0);
  one[0]:=1;
  one[1]:=1;
  for I:=1 to n do ans:=add(add(ans,ans),one);
  ans:=add(ans,ans);
  for i:=ans[0] downto 1 do
    write(ans[i]);
end.

