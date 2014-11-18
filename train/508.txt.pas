var i,j,a,b,c,d,e,f,g,h,min:longint;
    z,s,y:array[1..9] of longint;
begin
  for i:=1 to 9 do begin
    read(s[i]);
    if i mod 3=0 then readln;
  end;
  min:=maxlongint;
  for a:=0 to 3 do begin

    for b:=0 to 3 do for c:=0 to 3 do for d:=0 to 3 do
  for e:=0 to 3 do for f:=0 to 3 do for g:=0 to 3 do for h:=0 to 3 do
  for i:=0 to 3 do begin
    z[1]:=a+b+d+s[1];
    z[2]:=a+b+c+e+s[2];
    z[3]:=b+c+f+s[3];
    z[4]:=a+d+e+g+s[4];
    z[5]:=a+c+e+g+i+s[5];
    z[6]:=c+e+f+i+s[6];
    z[7]:=d+g+h+s[7];
    z[8]:=e+g+h+i+s[8];
    z[9]:=i+h+f+s[9];
    if (z[1] mod 4=0) and (z[2] mod 4=0) and (z[3] mod 4=0) and
    (z[4] mod 4=0) and (z[5] mod 4=0) and (z[6] mod 4=0)
    and (z[7] mod 4=0) and (z[8] mod 4=0) and (z[9] mod 4=0) then
    if a+b+c+d+f+e+g+h+i<min then begin
      min:=a+b+c+d+f+e+g+h+i;
      y[1]:=a;
      y[2]:=b;
      y[3]:=c;
      y[4]:=d;
      y[5]:=e;
      y[6]:=f;
      y[7]:=g;
      y[8]:=h;
      y[9]:=i;
    end;
    end;
  end;
  for i:=1 to 9 do
  for j:=1 to y[i] do write(i,' ');
end.
