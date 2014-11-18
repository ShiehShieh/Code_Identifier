program vijos_P1194;
const
  maxn=31;
  xx:array[1..5] of longint=(1,3,7,15,31);
type
  matrix= record
    nn,mm:longint;
    g:array[0..maxn,0..maxn] of longint;
  end;
var
  n,m,p:longint;
  a,tmp:matrix;
  d:array[0..maxn,1..5] of longint;

procedure get_g;
var i,j,k:longint;
begin
  for i:=0 to xx[m] do for k:=1 to m do d[i,k]:=(i>>(k-1))and 1;
  with a do begin
    nn:=xx[m]; mm:=xx[m];
    for i:=0 to nn do
      for j:=0 to mm do begin
        g[i,j]:=1;
        k:=1;
        while k<=m do begin
          if (d[i,k]=1)and(d[j,k]=1) then begin
            g[i,j]:=0;
            break;
          end;
          if (d[i,k]=0)and(d[j,k]=0) then
            if (k<m)and(d[i,k+1]=0)and(d[j,k+1]=0) then inc(k)
            else begin
              g[i,j]:=0;
              break;
            end;
          inc(k);
        end;
      end;
  end;
  tmp:=a;
end;

function mult(a,b:matrix):matrix;
var i,j,k:longint;
    tmp:matrix;
begin
  with tmp do begin
    nn:=a.nn; mm:=b.mm;
    fillchar(g,sizeof(g),0);
    for i:=0 to nn do for j:=0 to mm do
      for k:=0 to a.mm do begin
        inc(g[i,j],a.g[i,k]*b.g[k,j]);
        g[i,j]:=g[i,j] mod p;
      end;
  end;
  exit(tmp);
end;

procedure mtrx(n:longint);
begin
  if n=1 then exit;
  mtrx(n>>1);
  a:=mult(a,a);
  if n and 1=1 then a:=mult(a,tmp);
end;

begin
  readln(n,m,p);
  get_g;
  mtrx(n);
  writeln(a.g[0,0]);
end.

