program p1387;
type
  xxx=record
    h,l,fa,nu:integer;
    q:boolean;
  end;
var
  s:string;
  ss:set of 'A'..'Z';
  w:array[1..100]of xxx;
  a:array[0..100,1..2]of set of 'A'..'Z';
  i,j,k,m,n,nu,l,r,yy:integer;
  xx:boolean;
  c:char;
function judge(s:string):integer;
begin
  if (s[1]='P')and(s[2]='A') then exit(1);
  if (s[1]='I')and(s[2]='F') then exit(2);
  if (s[1]='E')and(s[2]='L') then exit(3);
  if (s[1]='E')and(s[2]='N') then exit(4);
  if (s[1]='R')and(s[2]='E') then exit(5);
  exit(0);
end;
procedure pro;
var
  i:integer;
begin
  for i:=6 to length(s) do
    if s[i] in ['A'..'Z'] then begin
      a[0,1]:=a[0,1]+[s[i]];
    end;
  r:=1;
  w[r].h:=0; w[r].l:=1;
end;
procedure ift;
var
  i,h,l:integer;
begin
  inc(r);
  w[r].h:=w[r-1].h+1;
  w[r].l:=1;
  w[r].nu:=0;
  w[r].q:=false;
  if w[r-1].q  then begin
    writeln('Line ',n,': unreachable code');
    w[r].q:=true;
    exit;
  end;
  h:=w[r].h; l:=w[r].l;
  a[h,l]:=a[h-1,w[r-1].l];
  ss:=[];
  for i:=3 to length(s) do begin
    if (s[i]='T')and(s[i+1]='H') then break;
    if (s[i] in ['A'..'Z'])and(not (s[i] in a[h,l])) then begin
      ss:=ss+[s[i]];
    end;
  end;
  for c:='A' to 'Z' do
    if c in ss then writeln('Line ',n,': variable ',c,' might not have been initialized');
end;
procedure els;
begin
  inc(r);
  w[r].h:=w[r-1].h;
  w[r].nu:=0;
  w[r].l:=2;
  w[r].q:=false;
  a[w[r].h,2]:=a[w[r].h-1,w[r-2].l];
  if w[r-2].q then w[r].q:=true;
end;
procedure endd;
var
  i,h:integer;
begin
  h:=w[r].h;
  if w[r].h=w[r-1].h then begin
    for c:='A' to 'Z' do
      if ((c in a[h,2])and(c in a[h,1]))or((c in a[h,2])and(w[r-1].nu=0))or((c in a[h,1])and(w[r].nu=0)) then a[h-1,w[r-2].l]:=a[h-1,w[r-2].l]+[c];
    if w[r].q and w[r-1].q then w[r-2].q:=true;
    dec(r,2);
  end else dec(r);
end;
procedure ret;
var
  i:integer;
begin
  if w[r].q then begin
    writeln('Line ',n,': unreachable code');
    exit;
  end;
  xx:=true;
  yy:=w[r].h;
  ss:=[];
  w[r].q:=true;
  for i:=7 to length(s) do
    if (s[i] in ['A'..'Z'])and(not (s[i] in a[w[r].h,w[r].l]))then begin
      ss:=ss+[s[i]];
      a[w[r].h,w[r].l]:=a[w[r].h,w[r].l]+[s[i]];
    end;
  for c:='A' to 'Z' do
    if c in ss then writeln('Line ',n,': variable ',c,' might not have been initialized');
end;
procedure nor;
var
  i:integer;
begin
  if w[r].q then begin
    writeln('Line ',n,': unreachable code');
    exit;
  end;
  inc(w[r].nu);
  ss:=[];
  for i:=2 to length(s) do
    if (s[i] in ['A'..'Z'])and(not (s[i] in a[w[r].h,w[r].l]))then begin
      ss:=ss+[s[i]];
    end;
  a[w[r].h,w[r].l]:=a[w[r].h,w[r].l]+[s[1]];
  for c:='A' to 'Z' do
    if c in ss then writeln('Line ',n,': variable ',c,' might not have been initialized');
end;
begin
  while not eof do begin
    readln(s);
    inc(n);
    nu:=judge(s);
    case nu of
      1:pro;
      2:ift;
      3:els;
      4:endd;
      5:ret;
      0:nor;
    end;
  end;
end.
