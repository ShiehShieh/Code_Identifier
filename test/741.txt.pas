PRogram P1352;
const
  maxn=5000;
  maxm=50000;
  maxedgenum=maxn+maxm*3;
var
  head,h,v:array [0..maxn+maxm+2] of longint;
  f,edge,next:array [-maxedgenum..maxedgenum] of longint;
  n,m,ans,s,t,num:longint;

Function Min(a,b:longint):longint;
begin
  if a<b then exit(a) else exit(b);
end;

PRocedure MakeEdge(a,b,c:longint);
begin
  inc(num);
  next[num]:=head[a];
  head[a]:=num;
  edge[num]:=b;
  f[num]:=c;

  next[-num]:=head[b];
  head[b]:=-num;
  edge[-num]:=a;
  f[-num]:=0;
end;

PRocedure INit;
var
  i,x,y,z:longint;
begin
  ans:=0;
  num:=0;
  readln(n,m);
  s:=0;
  t:=n+m+1;
  for i:=1 to n do
    begin
      read(x);
      MakeEdge(m+i,t,x);
    end;
  for i:=1 to m do
    begin
      readln(x,y,z);
      inc(ans,z);
      MakeEdge(s,i,z);
      MakeEdge(i,x+m,maxlongint);
      MakeEdge(i,y+m,maxlongint);
    end;
end;

Function AugPath(i,tot:longint):longint;
var
  now,minh,temp,delta,j:longint;
begin
  if i=t then exit(tot);
  now:=tot;
  minh:=n+m+1;

  temp:=head[i];
  while temp<>0 do
    begin
      if f[temp]>0 then
        begin
          j:=edge[temp];
          if h[i]=h[j]+1 then
            begin
              delta:=AugPath(j,min(f[temp],now));
              dec(f[temp],delta);
              inc(f[-temp],delta);
              dec(now,delta);
              if (now=0) or (h[s]>=n+m+2) then exit(tot-now);
            end;
          minh:=min(minh,h[j]);
        end;
      temp:=next[temp];
    end;

  if tot=now then
    begin
      dec(v[h[i]]);
      if v[h[i]]=0 then h[s]:=n+m+2;
      h[i]:=minh+1;
      inc(v[h[i]]);
    end;
  exit(tot-now);
end;

PRocedure Run;
begin
  fillchar(h,sizeof(h),0);
  v[0]:=n+m+2;
  while h[s]<=n+m+1 do dec(ans,AugPath(s,maxlongint));
end;

PRocedure Print;
begin
  writeln(ans);
end;

begin
  INit;
  Run;
  Print;
end.
