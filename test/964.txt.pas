var
  max,k:longint;
  n:integer;
  f1,f2:array[1..200,1..400]of longint;
  a:array[1..200,1..400]of char;

  procedure init;
  var
    i,j:integer;
  begin
    readln(n);
    for i:=1 to n do
      begin
        for j:=1 to n*2-i do
          read(a[i,j]);
        readln;
      end;
  end;

    function min(a,b:longint):longint;
    begin
      if a<b then exit(a) else exit(b);
    end;
    procedure dp1;
    var
      i,j:integer;
    begin
      for i:=1 to n do
        for j:=1 to n*2 do
          if a[i,j]='-' then f1[i,j]:=1;
      for i:=2 to n do
        begin
          for j:=1 to n*2 do
            if (a[i,j]='-')and(a[i-1,j]='-')and(((i mod 2=0)and(j mod 2=0))
                            or ((i mod 2=1)and(j mod 2=1))) then
              begin
                k:=min(f1[i-1,j-1],f1[i-1,j+1]);
                f1[i,j]:=k+1;
              end;
        end;
    end;

    procedure dp2;
    var
      i,j,k:integer;
    begin
      for i:=1 to n do
        for j:=1 to n*2 do
          if a[i,j]='-' then f2[i,j]:=1;
      for i:=n-1 downto 1 do
        begin
          for j:=1 to n*2 do
            if (a[i,j]='-')and(a[i+1,j]='-')and(((i mod 2=0)and(j mod 2=1))
                             or((i mod 2=1)and(j mod 2=0))) then

            begin
              k:=min(f2[i+1,j-1],f2[i+1,j+1]);
              f2[i,j]:=k+1;
            end;
        end;
    end;


  procedure main;
  var
    i,j:integer;
  begin
    max:=0;
    dp1;
    dp2;
    for i:=1 to n do
      for j:=1 to n*2 do
        if f1[i,j]>max then max:=f1[i,j];
    for i:=1 to n do
      for j:=1 to n*2 do
        if f2[i,j]>max then max:=f2[i,j];
  end;

  procedure outit;
  begin
    writeln(max*max);
  end;

begin
  init;
  main;
  outit;
end.

