var
  m,n:integer;
  ans:array[1..100,1..500]of int64;
  a,fa:array[1..100,1..500]of longint;


  procedure init;
  var
    i,j:integer;
  begin
    readln(m,n);
    for i:=1 to m do
      for j:=1 to n do
        begin
          read(a[i,j]);
          fa[i,j]:=j;
        end;
  end;

  procedure main;
  var
    i,j,k:integer;
  begin
    for i:=1 to n do ans[1,i]:=a[1,i];
    for i:=2 to m do
      begin
        for j:=1 to n do
          ans[i,j]:=ans[i-1,j]+a[i,j];
        for k:=1 to 20 do
          begin
            for j:=2 to n do
              if ans[i,j-1]+a[i,j]<ans[i,j] then
                begin
                  ans[i,j]:=ans[i,j-1]+a[i,j];
                  fa[i,j]:=j-1;
                end;
            for j:=n-1 downto 1 do
              if ans[i,j+1]+a[i,j]<ans[i,j] then
                begin
                  ans[i,j]:=ans[i,j+1]+a[i,j];
                  fa[i,j]:=j+1;
                end;
          end;
      end;
  end;

  procedure outit;
  var
    a:array[1..50000]of longint;
    i,j,k:longint;
    best:int64;
  begin
    best:=1;
    for i:=1 to n do
      if ans[m,i]<ans[m,best] then best:=i;
    j:=m;
    i:=best;
    while j<>1 do
      begin
        inc(k);
        a[k]:=i;
        if i=fa[j,i] then dec(j)
                     else i:=fa[j,i];
      end;
    inc(k); a[k]:=i;
    for i:=k downto 1 do writeln(a[i]);
  end;

begin
  init;
  main;
  outit;
end.
