program p1062;
var
  i,j,k:longint;
  n:longint;
  a,b,ans:array [0..15000] of longint;
begin
  fillchar(b,sizeof(b),0);
  {as-sign(input,'p1062.in');ass-ign(output,'p1062.out');
  re-set(input);rew-rite(output);}
  readln(n);
  a[0]:=0;
  for i:=1 to n do
  begin
    read(a[i]); end;
  ans[1]:=1;
  b[1]:=1;
  //-------------
  for i:=2 to n do
    if a[i]-a[i-1]>b[i] then begin ans[i]:=1 ;inc(b[i]) end
    else begin
      for j:=i downto 1 do
        if a[j]-a[j-1]>b[j] then
        begin
          for k:=j to i do
            inc(ans[i],b[k]);
          inc(ans[i]);
          inc(b[j]);
          break
        end;
    end;
  for i:=1 to n do write(ans[i],' ');
  writeln;
  {cl-ose(input);clo-se(output);}
end. 
