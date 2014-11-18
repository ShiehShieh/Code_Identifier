program P1378(input,output);
type
  arr=array[1..100] of integer;
var
  f:array[1..80,1..80] of arr;
  a:array[1..80] of longint;
  g,n,m,l,i,j,k:integer;
  tmp1,tmp2,ans:arr;

function add(a:arr; g:integer):arr;
var
  t:arr;
  i:integer;
begin
  i:=1;
  fillchar(t,sizeof(t),0);
  for i:=1 to 30 do
    begin
      t[i]:=a[i]+g;
      g:=t[i] div 10;
      t[i]:=t[i] mod 10;
    end;
  add:=t;
end;

function time(a:arr):arr;
var
  t:arr;
  g,i:integer;
begin
  g:=0;
  for i:=1 to 30 do
    begin
      t[i]:=a[i]*2+g;
      g:=t[i] div 10;
      t[i]:=t[i] mod 10;
    end;
  time:=t;

end;

function max(a,b:arr):arr;
var
  l:integer;
begin
  l:=30;
  while (l>=1) and (a[l]=b[l]) do
    l:=l-1;
  if (l=0) or (a[l]>b[l]) then
    max:=a
  else
    max:=b;
end;

procedure print(ans:arr);
var
  l,i:integer;
begin
  l:=30;
  while (l>1) and (ans[l]=0) do
    l:=l-1;
  for i:=l downto 1 do
    write(ans[i]);
  writeln;
end;

begin
  readln(n,m);
  fillchar(ans,sizeof(ans),0);
  for k:=1 to n do
    begin
      for i:=1 to m do
        begin
          read(a[i]);
          fillchar(f[i,i],sizeof(f[i,i]),0);
          f[i,i]:=add(f[i,i],a[i]*2);
        end;
      for l:=2 to m do
        for i:=1 to m-l+1 do
          begin
            j:=l+i-1;
            tmp1:=add(time(f[i+1,j]),a[i]*2);
            tmp2:=add(time(f[i,j-1]),a[j]*2);
            f[i,j]:=max(tmp1,tmp2);
          end;
      g:=0;
      for i:=1 to 30 do
        begin
          ans[i]:=ans[i]+f[1,m,i]+g;
          g:=ans[i] div 10;
          ans[i]:=ans[i] mod 10;
        end;
    end;
  print(ans);
end.

