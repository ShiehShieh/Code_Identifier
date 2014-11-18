const
 d:array[1..4,1..2]of longint=((0,1),(0,-1),(1,0),(-1,0));
var
 i,j,k,l,m,n,now,ii,jj,s,min:longint;
 a:array[-1..23,-1..23]of char;
 num:array[-1..23,-1..23]of longint;
 aa:array[1..500,1..500]of longint;
 dd:array[1..500]of longint;
 v:array[1..500]of boolean;
procedure dfs(x,y,ss:longint);
var
 i,xx,yy:longint;
begin
 num[x,y]:=ss;
 for i:=1 to 4 do
begin
  xx:=x+d[i,1]; yy:=y+d[i,2];
  if (num[xx,yy]=-1)and(a[xx,yy]=a[x,y]) then dfs(xx,yy,ss);
end;
end;
begin
  readln(n,m);
 for i:=-1 to 23 do for j:=-1 to 23 do a[i,j]:='-';
 for j:=1 to m do begin a[0,j]:='0'; a[n+1,j]:='0'; end;
 for i:=1 to n do
begin
  for j:=1 to m do read(a[i,j]);
  readln;
end;
 now:=0;
 fillchar(num,sizeof(num),$FF);
 for i:=0 to n+1 do
for j:=1 to m do
 if num[i,j]=-1 then begin inc(now); dfs(i,j,now); end;
 for i:=0 to n+1 do
for j:=1 to m do
  for k:=1 to 4 do
begin
  ii:=i+d[k,1]; jj:=j+d[k,2];
 if (a[ii,jj]<>a[i,j])and(a[ii,jj]<>'-') then aa[num[i,j],num[ii,jj]]:=1;
end;

 fillchar(v,sizeof(v),false);
{ for i:=1 to now do   dd[i]:=maxint; dd[1]:=0  }
fillchar(dd,sizeof(dd),0);
 s:=1; v[s]:=true;
 repeat
m:=maxlongint; k:=0;
for i:=1 to now do
  begin
if (aa[s,i]=1)and((dd[s]+aa[s,i]<dd[i])or(dd[i]=0))
then dd[i]:=dd[s]+aa[s,i];
if (dd[i]<m)and(dd[i]<>0)and(not v[i]) then begin m:=dd[i]; k:=i; end;
  end;
s:=k; v[s]:=true;
 until v[now];
 writeln(dd[now]-1);
 end.

