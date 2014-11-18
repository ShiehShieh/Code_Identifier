program river;
const
  maxn=100;
  maxk=50;
var
  sed:array[0..maxn]of boolean;
  d:array[0..maxn,0..maxn]of longint;
  w,lc,rc:array[0..maxn]of longint;
  f:array[0..maxn,0..maxn,0..maxk]of longint;
  n,k:longint;
procedure insert(i,p:longint);
var
  q:longint;
begin
  q:=lc[p];
  if lc[p]=0 then lc[p]:=i else
    begin
      while rc[q]<>0 do q:=rc[q];
      rc[q]:=i;
    end;
end;
procedure init;
var
  i,j,p:longint;
begin
  filldword(d,sizeof(d) shr 2,maxlongint);
  fillchar(lc,sizeof(lc),0);
  fillchar(rc,sizeof(rc),0);
  readln(n,k);
  for i:=1 to n do
    begin
      readln(w[i],p,d[i,p]);
      insert(i,p);
    end;
  filldword(f,sizeof(f) shr 2,maxlongint);
  fillchar(sed,sizeof(sed),0);
  d[0,0]:=0;
  //floyd
  for p:=0 to n do
    for i:=0 to n do
      for j:=0 to n do
        if d[i,p]<d[i,j]-d[p,j]
          then d[i,j]:=d[i,p]+d[p,j];
end;
procedure dfs(i:longint);
var
  j,a,b,l,r:longint;
begin
  sed[i]:=true;
  if not sed[lc[i]] then dfs(lc[i]);
  if not sed[rc[i]] then dfs(rc[i]);
  for j:=0 to n do
    if d[i,j]<maxlongint then
      for a:=0 to k do
        for b:=0 to k-a do
          begin
            if lc[i]=0 then l:=0 else l:=f[lc[i],j,a];
            if rc[i]=0 then r:=0 else r:=f[rc[i],j,b];
            if (l<maxlongint) and (r<maxlongint) then
              if l+r+w[i]*d[i,j]<f[i,j,a+b]
                then f[i,j,a+b]:=l+r+w[i]*d[i,j];
            if b>0 then
              begin
                if lc[i]=0 then l:=0 else l:=f[lc[i],i,a];
                if rc[i]=0 then r:=0 else r:=f[rc[i],j,b-1];
                if (l<maxlongint) and (r<maxlongint) then
                  if l+r<f[i,j,a+b]
                    then f[i,j,a+b]:=l+r;
              end;
          end;
end;
begin
  init;
  dfs(0);
  writeln(f[0,0,k]);
end.
