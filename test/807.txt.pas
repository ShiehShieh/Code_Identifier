var //by  hama
  a:array[1..4000,1..2] of longint;
  a1,a2,last,i,j,k,n,h1,m1,s1,h2,m2,s2,answer,an:longint;
  procedure qsort(b,e:longint);
    var
      l,r,c,m:longint;
    begin
      m:=a[(b+e) div 2,1];
      l:=b;r:=e;
      while l<r do
        begin
          while a[l,1]<m do inc(l);
          while a[r,1]>m do dec(r);
          if l<=r then
            begin
              c:=a[l,1];a[l,1]:=a[r,1];a[r,1]:=c;
              c:=a[l,2];a[l,2]:=a[r,2];a[r,2]:=c;
              inc(l);
              dec(r);
            end;
        end;
      if l<e then qsort(l,e);
      if r>b then qsort(b,r);
    end;
begin

  readln(n);
  an:=0;
  for i:=1 to n do
    begin
      readln(h1,m1,s1,h2,m2,s2);
      a1:=h1*3600+m1*60+s1;
      a2:=h2*3600+m2*60+s2;
      if a1>a2 then
        begin
          if a1-a2>180*3600 then
            begin
              inc(an);a[an,1]:=a1;a[an,2]:=360*3600;
              inc(an);a[an,1]:=0;a[an,2]:=a2;
            end
          else
            begin
              inc(an);a[an,1]:=a2;a[an,2]:=a1;
            end;
        end
      else
        begin
          if a2-a1>180*3600 then
            begin
              inc(an);a[an,1]:=a2;a[an,2]:=360*3600;
              inc(an);a[an,1]:=0;a[an,2]:=a1;
            end else
              begin
                inc(an);a[an,1]:=a1;a[an,2]:=a2;
              end;
        end;
    end;
  qsort(1,an);
  answer:=a[1,2]-a[1,1];
  last:=a[1,2];
  for i:=2 to an do
    if a[i,1]>last then
      begin
        answer:=answer+a[i,2]-a[i,1];
        last:=a[i,2];
      end
    else
      begin
        if a[i,2]>last then
          begin
            answer:=answer+a[i,2]-last;
            last:=a[i,2];
          end;
      end;
  writeln(answer);
end.

