program palase;
type aa=record
          num,m:longint;
          c:array [1..1500] of int64;
        end;
var tr:array [1..1500] of aa;
    p:array[1..1500] of boolean;
    f:array[1..1500,0..2] of int64;
    i,j,k,m,n,root,min:longint;
function xiao(i,j:int64):int64;
begin
  if i<j then xiao:=i
         else xiao:=j;
end;
procedure search(s:longint);
var i,j,k,l:longint;min:int64;
begin
  f[s,0]:=0;
  f[s,1]:=tr[s].num;
  f[s,2]:=0;
  l:=0;
  for i:=1 to tr[s].m do
  begin
    search(tr[s].c[i]);
    f[s,0]:=f[s,0]+xiao(f[tr[s].c[i],0],f[tr[s].c[i],1]);
    f[s,1]:=f[s,1]+xiao(xiao(f[tr[s].c[i],1],f[tr[s].c[i],0]),f[tr[s].c[i],2]);
    f[s,2]:=f[s,2]+f[tr[s].c[i],0];
    if f[tr[s].c[i],0]=xiao(f[tr[s].c[i],0],f[tr[s].c[i],1]) then inc(l);
  end;
  min:=maxlongint;
  if (l=tr[s].m) and (tr[s].m<>0) then
  begin
    for i:=1 to tr[s].m do
      min:=xiao(min,f[tr[s].c[i],1]-f[tr[s].c[i],0]);
    f[s,0]:=f[s,0]+min;
  end;
  if tr[s].m=0 then f[s,0]:=maxlongint;
end;
begin
  readln(n);
  fillchar(p,sizeof(p),1);
  for i:=1 to n do
  begin
    read(j);
    read(tr[j].num,tr[j].m);
    for k:=1 to tr[j].m do
    begin
      read(tr[j].c[k]);
      p[tr[j].c[k]]:=false;
    end;
    readln;
  end;
  for i:=1 to n do
    if p[i] then
    begin
      root:=i;
      break;
    end;
  search(root);
  min:=xiao(f[root,0],f[root,1]);
  writeln(min);
end.
