program p1064_2;
const c:array['0'..'9',1..5,1..3]of char=
      (((' ','-',' '),('|',' ','|'),(' ',' ',' '),('|',' ','|'),(' ','-',' '))
      ,((' ',' ',' '),(' ',' ','|'),(' ',' ',' '),(' ',' ','|'),(' ',' ',' '))
      ,((' ','-',' '),(' ',' ','|'),(' ','-',' '),('|',' ',' '),(' ','-',' '))
      ,((' ','-',' '),(' ',' ','|'),(' ','-',' '),(' ',' ','|'),(' ','-',' '))
      ,((' ',' ',' '),('|',' ','|'),(' ','-',' '),(' ',' ','|'),(' ',' ',' '))
      ,((' ','-',' '),('|',' ',' '),(' ','-',' '),(' ',' ','|'),(' ','-',' '))
      ,((' ','-',' '),('|',' ',' '),(' ','-',' '),('|',' ','|'),(' ','-',' '))
      ,((' ','-',' '),(' ',' ','|'),(' ',' ',' '),(' ',' ','|'),(' ',' ',' '))
      ,((' ','-',' '),('|',' ','|'),(' ','-',' '),('|',' ','|'),(' ','-',' '))
      ,((' ','-',' '),('|',' ','|'),(' ','-',' '),(' ',' ','|'),(' ','-',' ')));

var i,j,jj,k,n:integer; s:string;

begin
  readln(k);
  readln(s);
  n:=length(s);

  for i:=1 to n do begin
    if i<>1 then write(' ');
    write(c[s[i],1,1]);
    for j:=1 to k do write(c[s[i],1,2]);
    write(c[s[i],1,3]);
  end;
  writeln;

  for jj:=1 to k do begin
    for i:=1 to n do begin
      if i<>1 then write(' ');
      write(c[s[i],2,1]);
      for j:=1 to k do write(c[s[i],2,2]);
      write(c[s[i],2,3]);
    end;
    writeln;
  end;

  for i:=1 to n do begin
    if i<>1 then write(' ');
    write(c[s[i],3,1]);
    for j:=1 to k do write(c[s[i],3,2]);
    write(c[s[i],3,3]);
  end;
  writeln;

  for jj:=1 to k do begin
    for i:=1 to n do begin
      if i<>1 then write(' ');
      write(c[s[i],4,1]);
      for j:=1 to k do write(c[s[i],4,2]);
      write(c[s[i],4,3]);
    end;
    writeln;
  end;

  for i:=1 to n do begin
    if i<>1 then write(' ');
    write(c[s[i],5,1]);
    for j:=1 to k do write(c[s[i],5,2]);
    write(c[s[i],5,3]);
  end;
end.
