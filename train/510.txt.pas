var
  s,s1:string;
  i,j,t:longint;
  a,b:array[1..2] of longint;
  aa,bb:longint;
  ss:real;
  ch:char;
begin
  readln(s);
  i:=1;
  s1:='';
  t:=1;
  ch:=' ';
  while i<=length(s) do
    begin
      if s[i]='-' then
        begin
          inc(i);
          while (ord(s[i])<=57) and (ord(s[i])>=48) do
            begin
              s1:=s1+s[i];
              inc(i);
            end;
          if (s[i]='+') or (s[i]='-') or (s[i]='=') or (i>=length(s)) then
            begin
              val(s1,aa);
              a[t]:=a[t]-aa;
            end
          else if (s[i]<>'=') then
            begin
              val(s1,bb);
              b[t]:=b[t]-bb;
              if ch=' ' then ch:=s[i];
              inc(i);
            end;
          s1:='';
        end
      else if (s[i]='+') or (i=1) or (s[i-1]='=') then
        begin
          if (i<>1) and (s[i-1]<>'=') then inc(i);
          while (ord(s[i])<=57) and (ord(s[i])>=48) do
            begin
              s1:=s1+s[i];
              inc(i);
            end;
          if (s[i]='+') or (s[i]='-') or (s[i]='=') or (i>=length(s)) then
            begin
              val(s1,aa);
              a[t]:=a[t]+aa;
            end
          else if (s[i]<>'=') then
            begin
              val(s1,bb);
              b[t]:=b[t]+bb;
              if ch=' ' then ch:=s[i];
              inc(i);
            end;
          s1:='';
        end;
      if s[i]='=' then
        begin
          inc(t);
          inc(i);
        end;
    end;
  aa:=a[1]-a[2];
  bb:=b[2]-b[1];
  ss:=aa/bb;
  if trunc(ss*1000000)=0 then ss:=0;
  write(ch,'=');
  writeln(ss:0:3);
end.
