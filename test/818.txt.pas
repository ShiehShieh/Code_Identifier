program cyf;
  var
    yu,shu,ying,zong,a:array[1..500] of integer;
    n,i,j,t:integer;
  begin
    readln(n);
    for i:=1 to n do
      begin
        a[i]:=i;
        readln(yu[i],shu[i],ying[i]);
        zong[i]:=yu[i]+shu[i]+ying[i];
      end;
    for i:=1 to n-1 do
      for j:=i+1 to n do
        begin
          if (zong[i]<zong[j])or((zong[i]=zong[j])and(yu[i]<=yu[j])) then
            begin
              t:=zong[i];zong[i]:=zong[j];zong[j]:=t;
              t:=yu[i];yu[i]:=yu[j];yu[j]:=t;
              t:=shu[i];shu[i]:=shu[j];shu[j]:=t;
              t:=ying[i];ying[i]:=ying[j];ying[j]:=t;
              t:=a[i];a[i]:=a[j];a[j]:=t;
            end;
        end;
    for i:=1 to 5 do
      if (zong[i]=zong[i+1])and(yu[i]=yu[i+1]) then
            begin
              t:=zong[i];zong[i]:=zong[i+1];zong[i+1]:=t;
              t:=yu[i];yu[i]:=yu[i+1];yu[i+1]:=t;
              t:=shu[i];shu[i]:=shu[i+1];shu[i+1]:=t;
              t:=ying[i];ying[i]:=ying[i+1];ying[i+1]:=t;
              t:=a[i];a[i]:=a[i+1];a[i+1]:=t;
              writeln(a[i],' ',zong[i]);
            end
           else
       writeln(a[i],' ',zong[i]);
  end.

