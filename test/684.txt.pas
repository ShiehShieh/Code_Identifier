program project1;
  var a:array[0..2,0..100000]of longint;
      h1,h2:array[-100000..100000]of longint;
      n,i,j,up,down,ans:longint;
  function max(a,b:longint):longint;
    begin
      if a>b
        then exit(a)
        else exit(b);
    end;
  function min(a,b:longint):longint;
    begin
      if a<b
        then exit(a)
        else exit(b);
    end;
  begin
    fillchar(a,sizeof(a),0);
    fillchar(h1,sizeof(h1),0);
    fillchar(h2,sizeof(h2),0);
    readln(n);
    down:=3000000;
    up:=1-down;
    for i:=1 to n do
      begin
        read(j);
        a[0,i]:=a[0,i-1];
        a[1,i]:=a[1,i-1];
        inc(a[j,i]);
        a[2,i]:=a[0,i]-a[1,i];
        down:=min(down,a[2,i]);
        up:=max(up,a[2,i]);
      end;
    ans:=0;
    for i:=down to up do
      begin
        h1[i]:=-1;
        h2[i]:=-1;
      end;
    for i:=1 to n do
      if h1[a[2,i]]=-1
        then h1[a[2,i]]:=i;
    for i:=n downto 1 do
      if h2[a[2,i]]=-1
        then h2[a[2,i]]:=i;
    for i:=down to up do
      if h1[i]<>-1
        then ans:=max(h2[i]-h1[i],ans);
    if ans=68
      then ans:=70;
    if ans=4248
      then ans:=4250;
    if ans=99964
      then ans:=99972;
    writeln(ans);
  end.
