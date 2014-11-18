const maxn=200000*4+5;
const min=-9223372036854775807;
var i,n,m:longint;
    k,a,b:int64;
    tree:array[1..maxn] of int64;
function max(x,y:int64):int64;
begin
  if x>y then max:=x else max:=y;
end;
procedure insert(x,l,r,key,p:int64);
var mid:int64;
begin
  tree[x]:=max(tree[x],key);
  if (l=r)and(l=p) then exit;
  mid:=(l+r) div 2;
  if mid>=p then insert(x*2,l,mid,key,p)
   else insert(x*2+1,mid+1,r,key,p);
end;
function find(x,l,r,a,b:int64):int64;
var mid:int64;
begin
  mid:=(l+r) div 2;
  if (l=a)and(r=b) then exit(tree[x]);
  if mid<a then find:=find(x*2+1,mid+1,r,a,b) else
   if mid<b then
     find:=max(find(x*2,l,mid,a,mid),find(x*2+1,mid+1,r,mid+1,b))
    else find:=find(x*2,l,mid,a,b);
end;
begin
  readln(n);
  for i:=1 to maxn do
   tree[i]:=min;
  for i:=1 to n do
   begin
     read(k);
     insert(1,1,n,k,i);
   end;
  readln(m);
  for i:=1 to m do
   begin
     readln(a,b);
     write(find(1,1,n,a,b));
   end;
end.
