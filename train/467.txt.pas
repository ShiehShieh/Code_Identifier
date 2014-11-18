const
dx:array[1..4]of longint=(1,1,-1,-1);
dy:array[1..4]of longint=(1,-1,-1,1);
type
rec=record
    x,y:longint;
    end;
var
arr:array[0..202,0..202]of boolean;
map:array[1..201,1..201,1..4]of boolean;
f:array[1..201,1..201]of longint;
q:array[1..40401]of rec;
n,m,i,j,tmp,ans,h,t,x0,x1,y0,y1,d:longint;
rd:char;
flag:boolean;
BEGIN
readln(n,m);
for i:=1 to n do
  begin
  for j:=1 to m do
    begin
    read(rd);
    if (rd='\')or(rd='X') then
      begin
      arr[i,j]:=true;
      arr[i+1,j+1]:=true;
      map[i,j,1]:=true;
      map[i+1,j+1,3]:=true;
      inc(f[i,j]);
      inc(f[i+1,j+1]);
      end;
    if (rd='/')or(rd='X') then
      begin
      arr[i,j+1]:=true;
      arr[i+1,j]:=true;
      map[i,j+1,2]:=true;
      map[i+1,j,4]:=true;
      inc(f[i,j+1]);
      inc(f[i+1,j]);
      end;
    end;
  readln;
  end;
for i:=1 to n do
  begin
  for j:=1 to m do
    begin
    read(rd);
    if (rd='\')or(rd='X') then
      begin
      arr[i,j]:=true;
      arr[i+1,j+1]:=true;
      map[i,j,1]:=true;
      map[i+1,j+1,3]:=true;
      dec(f[i,j]);
      dec(f[i+1,j+1]);
      end;
    if (rd='/')or(rd='X') then
      begin
      arr[i,j+1]:=true;
      arr[i+1,j]:=true;
      map[i,j+1,2]:=true;
      map[i+1,j,4]:=true;
      dec(f[i,j+1]);
      dec(f[i+1,j]);
      end;
    end;
  readln;
  end;
for i:=1 to n+1 do
  for j:=1 to m+1 do
    if arr[i,j] then
      begin
      arr[i,j]:=false;
      tmp:=abs(f[i,j]);
      q[1].x:=i;q[1].y:=j;
      h:=1;t:=1;
      while h<=t do
        begin
        x0:=q[h].x;
        y0:=q[h].y;
        for d:=1 to 4 do
          if map[x0,y0,d] then
            begin
            x1:=x0+dx[d];
            y1:=y0+dy[d];
            if arr[x1,y1] then
              begin
              arr[x1,y1]:=false;
              inc(tmp,abs(f[x1,y1]));
              inc(t);q[t].x:=x1;q[t].y:=y1;
              end;
            end;
        inc(h);
        end;
      if tmp=0 then tmp:=2;
      if odd(tmp) then flag:=true;
      inc(ans,tmp shr 1);
      end;
writeln(ans);
end.

