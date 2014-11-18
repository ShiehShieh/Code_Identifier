program egypt;
var
  f:boolean;
  t,best:array[0..1000]of longint;
  a,b,q:longint;

function gcd(aa,bb:int64):longint;
begin
  if bb mod aa=0 then gcd:=aa
    else gcd:=gcd(bb mod aa,aa);
end;
procedure minus(var a,b:longint;c,d:longint);
var
  aa,bb:int64;
  g:longint;
begin
  aa:=a*d-b*c;
  bb:=b;
  bb:=bb*d;
  if aa<>0 then
    begin
      g:=gcd(aa,bb);
      if aa div g >maxlongint then a:=maxlongint else a:=aa div g;
      if bb div g >maxlongint then b:=maxlongint else b:=bb div g;
    end;

end;
procedure dfs(a,b,last,p:longint);
var
  i,j,k,r,w,v:longint;
begin
  if p=q then
    begin
      if (a=1) and (b>last) then
        begin
          f:=true;
          t[q]:=b;
          if t[q]<best[q] then
          for i:=1 to q do
            best[i]:=t[i];
        end;
      exit;
    end;

  w:=last+1;
  if (b div a+1>w) then w:=b div a+1;
  v:=b*(q-p+1) div a;
  for i:=w to v do
    begin
      j:=a;k:=b;
      minus(j,k,1,i);
      t[p]:=i;
      dfs(j,k,i,p+1);
    end;
end;
procedure print;
var
  i:longint;
begin
  for i:=1 to q-1 do
    write(best[i],' ');
  writeln(best[q]);
end;
begin
  readln(a,b);
  f:=false;
  fillchar(t,sizeof(t),0);
  fillchar(best,sizeof(best),0);
  minus(a,b,0,1);
  for q:=1 to 1000 do
    begin
      best[q]:=maxlongint;
      dfs(a,b,1,1);
      if f then break;
    end;
  print;
end.

