program v1144;
type treetype=record
num:integer;
son:array[1..1500]of integer;
end;
var f:array[1..1500,1..3]of int64;
tree:array[1..1500]of treetype;
w:array[1..1500]of longint;
r:array[1..1500]of boolean;
n,x,i,j,k,root:integer;
function min(a,b:longint):longint;
begin
min:=a;
if min>b then min:=b;
end;
procedure work(i:integer);
var j,sum:integer;
mm:int64;
begin
f[i,1]:=w[i];f[i,2]:=0;f[i,3]:=0;sum:=0;
for j:=1 to tree[i].num do begin
work(tree[i].son[j]);
f[i,1]:=f[i,1]+
min(min(f[tree[i].son[j],1],f[tree[i].son[j],2]),f[tree[i].son[j],3]);
f[i,3]:=f[i,3]+f[tree[i].son[j],2];
if f[i,3]>maxlongint then f[i,3]:=maxlongint;
f[i,2]:=f[i,2]+min(f[tree[i].son[j],2],f[tree[i].son[j],1]);
if f[tree[i].son[j],2]=min(f[tree[i].son[j],2],f[tree[i].son[j],1]) then inc(sum);
end;
if (sum=tree[i].num)and(tree[i].num>0) then begin
mm:=maxlongint;
for j:=1 to tree[i].num do
if f[tree[i].son[j],1]-f[tree[i].son[j],2]<mm then
mm:=f[tree[i].son[j],1]-f[tree[i].son[j],2];
f[i,2]:=f[i,2]+mm;
end;
if tree[i].num=0 then f[i,2]:=maxlongint;
end;
begin
readln(n);
for i:=1 to n do r[i]:=true;
for i:=1 to n do begin
read(x,w[x],tree[x].num);
for j:=1 to tree[x].num do begin
read(tree[x].son[j]);r[tree[x].son[j]]:=false;
end;
end;
root:=0;
for i:=1 to n do if r[i] and (root=0) then begin
root:=i;break;
end;
work(root);
writeln(min(f[root,1],f[root,2]));
end.
