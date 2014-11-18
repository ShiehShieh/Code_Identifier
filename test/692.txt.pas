program p1258;
var a:array[1..9]of integer;
    s,ss:string;
    i,j,l,k:integer; ch:char;  f:boolean;
begin
  readln(s);
  i:=1;
  repeat
    while(s[i]=' ') do inc(i);
    inc(k);
    j:=i;
    while(s[j]<>' ') do inc(j);
    j:=j-i;
    ss:=copy(s,i,j);
    val(ss,a[k],l);
    i:=i+j+1;
  until k=9;
  f:=false;
  for i:=1 to 7 do begin
    if f then write(' ');
    if a[i]<-1 then write('- ',-a[i],'x^',9-i)
    else if a[i]>1 then if f then write('+ ',a[i],'x^',9-i)
                        else write(a[i],'x^',9-i)
         else if a[i]=-1 then write('- x^',9-i)
              else if a[i]=1 then if f then write('+ x^',9-i)
                                  else write('x^',9-i);
    if a[i]<>0 then f:=true;
  end;

  inc(i);
  if f then write(' ');
  if a[i]<-1 then write(' - ',-a[i],'x')
  else if a[i]>1 then if f then write(' + ',a[i],'x')
                      else write(a[i],'x')
  else if a[i]=-1 then write(' - x')
  else if a[i]=1 then if f then write(' + x')
                       else write('x');
  if a[i]<>0 then f:=true;

  inc(i);
  if f then write(' ');
  if a[i]<-1 then write(' - ',-a[i])
  else if a[i]>1 then if f then write(' + ',a[i])
                      else write(a[i])
  else if a[i]=-1 then write(' - 1')
  else if a[i]=1 then if f then write(' + 1')
                 else write('1');
  if (a[i]<>0) then f:=true;

  if not(f) then writeln(0);
end.

