program P1230;
const c:array[2..4] of char=('S','B','Q');
      cc:array[2..3] of char=('W','Y');
var n:ansistring;
    i,j,l,t,s:longint;
    point:boolean;
    a:array[1..4,1..4] of integer;
function CK(y:longint):boolean;
begin
  if (a[y,4]=0) and (a[y,3]=0) and (a[y,2]=0) and (a[y,1]=0) then CK:=false else CK:=true;
end;
function LDM(x:longint):boolean;
var k:integer;
begin
  LDM:=true;
  for k:=1 to x do
    if n[k]<>'0' then LDM:=false;
end;
begin
  read(n);
  if n[length(n)]='.' then delete(n,length(n),1);
  if pos('.',n)<>0 then point:=true else point:=false;
  case n[1] of
    '-':begin
          write('F');
          delete(n,1,1);
        end;
    '+':delete(n,1,1);
  end;
  case point of
    true:begin
           l:=pos('.',n)-1;
           for i:=1 to l-1 do if (n[i]='0') and (LDM(i-1)) then inc(t);
           delete(n,1,t);
         end;
    false:begin
            l:=length(n);
            for i:=1 to l-1 do if (n[i]='0') and (LDM(i-1)) then inc(t);
            delete(n,1,t);
          end;
  end;
  t:=0;
  s:=1;
  case point of
    true:l:=pos('.',n)-1;
    false:l:=length(n);
  end;
  if n='0' then
  begin
    write(n);
    exit;
  end;
  if n[1]='.' then write('0');
  for i:=l downto 1 do
  begin
    inc(t);
    if t>4 then
    begin
      t:=t-4;
      inc(s);
    end;
    a[s,t]:=ord(n[i])-ord('0');
  end;
  for i:=s downto 1 do
  begin
    for j:=4 downto 1 do
    begin
      if (i=s) and (j>t) then continue;
      if (j<=3) and (a[i,j+1]=0) and (a[i,j]<>0) and ((i<>s) or (j<>t)) then
        write('0');
      if (a[i,j]<>0) and (j<>1) then write(a[i,j],c[j]) else if (j=1) and (a[i,j]<>0) then write(a[i,j]);
    end;
    if (i<>1) and (CK(i)) then write(cc[i]);
  end;
  if point then
  begin
    write('D');
    for i:=l+2 to length(n) do
      write(n[i]);
  end;
end.
