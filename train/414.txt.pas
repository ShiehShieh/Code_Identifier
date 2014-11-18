program po;
type
  int=integer;
const
  mapxyl=5;
  maxn=mapxyl*mapxyl;
  maxrinhp=16;
  maxt=42;
  dx:array[0..3]of int=(-1,0,1,0);
  dy:array[0..3]of int=(0,-1,0,1);
  dn:array[0..4]of int=(-1,-mapxyl,1,mapxyl,0);
var
  a:array[1..150]of integer;
  bh:array[0..maxt,0..maxt-1,0..maxn-1,0..maxn-1,1..maxrinhp]of int;
  g:array[0..maxn-1,0..maxn-1]of int;
  map:array[-1..mapxyl,-1..mapxyl]of boolean;
  rp,zp1,zp2,hpm,hpz:int;

procedure gjd(w:integer);
  var
    y,x,i,j:integer;
  begin
    a[1]:=1;
    for i:=1 to w do begin
      y:=0;
      for j:=1 to 150 do begin
        x:=a[j]*2+y;
        a[j]:=x mod 10;
        y:=x div 10;
      end;
    end;
    i:=150;
    while a[i]=0 do dec(i);
    for j:=i downto 1 do write(a[j]);
    writeln;
  end;

function getposid(x,y:int):int;
begin
  if (x<0)or(x>=mapxyl)or(y<0)or(y>=mapxyl) then
    getposid:=-1
  else
    getposid:=y*mapxyl+x;
end;

procedure floyd;
var
  i,j,k:int;
begin
  fillchar(g,sizeof(g),$3f);
  for i:=0 to mapxyl-1 do
    for j:=0 to mapxyl-1 do
      if map[i,j] then
        for k:=0 to 3 do
          if map[i+dy[k],j+dx[k]] then
           g[getposid(j,i),getposid(j+dx[k],i+dy[k])]:=1;
  for i:=0 to maxn-1 do
    g[i,i]:=0;
  for k:=0 to maxn-1 do
    for i:=0 to maxn-1 do
      for j:=0 to maxn-1 do
        if g[i,j]>g[i,k]+g[k,j] then
          g[i,j]:=g[i,k]+g[k,j];
end;

var
  i,j,k:int;
  c:char;
  ri,zi1,zi2,hpmi,t:int;
  rj,zj1,zj2,hpmj,
  b:int;

function lingmove(d:int):int;
var
  i,d1:int;
begin
  for i:=0 to 3 do
  begin
    d1:=d+dn[i];
    if (d1>=0)and(d1<maxn) then
      if g[d,d1]=1 then
        if g[d,d1]+g[d1,rj]=g[d,rj] then
        begin
          lingmove:=d1;
          exit;
        end;
  end;
  lingmove:=d;
end;

begin
  fillchar(map,sizeof(map),0);
  for i:=0 to mapxyl-1 do
  begin
    for j:=0 to mapxyl-1 do
    begin
      read(c);
      map[i,j]:=(c<>'1');
      if c='T' then rp:=getposid(j,i);
      if c='c' then zp1:=getposid(j,i);
      if c='C' then zp2:=getposid(j,i);
    end;
    readln;
  end;
  readln(hpm,hpz);
  floyd;
  fillchar(bh,sizeof(bh),$3f);
  bh[0,rp,zp1,zp2,hpm]:=hpz*2;
  bh[0,rp,zp2,zp1,hpm]:=hpz*2;
  for t:=0 to maxt do
    for ri:=0 to maxn-1 do
    for zi1:=0 to maxn-1 do
    for zi2:=0 to maxn-1 do
    for hpmi:=1 to hpm do
      if bh[t,ri,zi1,zi2,hpmi]<$3f then
      begin
        b:=bh[t,ri,zi1,zi2,hpmi];
        if b<=0 then
        begin
          writeln('WIN');
          gjd(500-t);
          halt;
        end;
        if t<maxt then
        for k:=0 to 4 do
        begin
          rj:=ri+dn[k];
          if (rj<0)or(rj>=maxn) then continue;
          if b>hpz then
          if rj=zi1 then continue;
          if b>0 then
          if rj=zi2 then continue;
          if g[ri,rj]>1 then continue;
          hpmj:=hpmi;
          if k=4 then
            dec(b);
          if b<=hpz then zj1:=zi1 else
          begin
            zj1:=lingmove(zi1);
            if zj1=rj then begin dec(hpmj);zj1:=zi1;end;
          end;
          if b<=0 then zj2:=zi2 else
          begin
            zj2:=lingmove(zi2);
            if zj2=rj then begin dec(hpmj);zj2:=zi2;end;
          end;
          if hpmj=hpmi-2 then
            if zj1=zj2 then
              inc(hpmj);
          if hpmj>0 then
            if bh[t+1,rj,zj1,zj2,hpmj]>b then
              bh[t+1,rj,zj1,zj2,hpmj]:=b;
        end;
      end;
    writeln('LOSE ');
  end.
