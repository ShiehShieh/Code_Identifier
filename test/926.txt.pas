const
  maxw=100000;

var
  w,sum:longint;
  n:integer;
  a:array[1..100]of longint;
  ans:array[1..100]of boolean;
  last,num:array[0..maxw]of longint;
  bool:array[0..maxw]of boolean;
  f:array[0..maxw]of int64;

  procedure init;
  var
    i:integer;
  begin
    readln(w);
    readln(n);
    sum:=0;
    for i:=1 to n do
      begin
        read(a[i]);
        sum:=sum+a[i];
      end;
  end;

  procedure main;
  var
    i,j:longint;
  begin
    fillchar(f,sizeof(f),0);
    fillchar(bool,sizeof(bool),false);
    bool[0]:=true;
    f[0]:=1;
    for i:=1 to n do
      begin
        for j:=maxw-a[i] downto 0 do
          begin
            {if (j+a[i]=sum-w)and(f[j])and(f[j+a[i]]) then
              begin
                writeln(-1);
                halt;
              end;}
            if bool[j] then
              begin
                bool[j+a[i]]:=true;
                if f[j+a[i]]=0 then
                  begin
                    last[j+a[i]]:=j;
                    num[j+a[i]]:=i;
                  end;
                f[j+a[i]]:=f[j]+f[j+a[i]];
              end;
          end;
      end;
  end;

  procedure outit;
  var
    i,j:longint;
  begin
    if f[sum-w]>1 then writeln(-1) else
    if f[sum-w]=0 then writeln(0) else
      begin
        i:=sum-w;
        fillchar(ans,sizeof(ans),0);
        while i>0 do
          begin
            ans[num[i]]:=true;
            i:=last[i];
          end;
        j:=0;
        for i:=1 to n do if ans[i] then
          begin
            if j<>0 then write(' ');
            write(i);
            inc(j);
          end;
        writeln;
      end;
  end;

begin
  init;
  main;
  outit;
end.

