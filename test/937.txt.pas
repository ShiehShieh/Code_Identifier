 var x,y,max,n,m,i,j:integer;
      a:array[0..1000,0..1000]of integer;
  begin
    readln(n,m);
    max:=0;
    fillchar(a,sizeof(a),0);
    for i:=1 to n do
      for j:=1 to m do
        begin
          if j<>m then read(x);
          if j=m then readln(x);
          if x=0 then continue;
          y:=a[i-1,j-1];
          if y>a[i-1,j] then y:=a[i-1,j];
          if y>a[i,j-1] then y:=a[i,j-1];
          a[i,j]:=y+1;
          if a[i,j]>max then max:=a[i,j];
          end;
    writeln(max);

  end.
