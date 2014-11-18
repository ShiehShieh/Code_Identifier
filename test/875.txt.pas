const
  maxn=200;

var
  n:integer;
  sum,best_i,best_j:longint;
  a:array[1..maxn]of longint;
  f:array[0..maxn,0..40*maxn]of boolean;

  procedure init;
  var
    i:integer;
  begin
    readln(n);
    sum:=0;
    for i:=1 to n do read(a[i]);
    for i:=1 to n do sum:=sum+a[i];
  end;

  procedure main;
  var
    i,j,k:integer;
  begin
    fillchar(f,sizeof(f),0);
    f[0,0]:=true;
    for i:=1 to n do
      begin
        for j:=i-1 downto 0 do
          begin
            for k:=0 to n*40-a[i] do
              if f[j,k] then
                f[j+1,k+a[i]]:=true;
          end;
      end;
    best_i:=maxlongint;
    best_j:=0;
    for i:=0 to sum do if f[n div 2,i] then
      begin
        if abs(best_i-best_j)>abs(sum-i-i) then
          begin
            best_i:=i;
            best_j:=sum-i;
          end;
      end;
  end;

  procedure outit;
  begin
    if best_i<best_j then writeln(best_i,' ',best_j)
    else writeln(best_j,' ',best_i);
  end;

begin
  init;
  main;
  outit;
end.

