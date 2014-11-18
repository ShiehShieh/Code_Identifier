type
  treedata=record
    s,t : longint;
    cover: byte;
  end;
var
  tree: array [1..200001] of treedata;
  l,m,i,x,y,tot: longint;

procedure maketree(p,a,b:longint);
var
  m: longint;
begin
  inc(tot);
  m:= (a+b) div 2;
  tree[p].s:= a;
  tree[p].t:= b;
  if (b-a>=1) then
    begin
      maketree(p*2,a,m);
      maketree(p*2+1,m+1,b);
    end;
end;

procedure insert(p,a,b: longint);
var
  m: longint;
begin
  if tree[p].cover=0 then
   begin
     m:= (tree[p].s + tree[p].t) div 2;
     if (a = tree[p].s) and (b = tree[p].t) then tree[p].cover:=1
       else if b<=m then insert(p*2,a,b)
       else if a>m then insert(p*2+1,a,b)
       else begin
        insert(p*2,a,m);
        insert(p*2+1,m+1,b);
       end;
   end;
end;

function count(p: longint): longint;
begin
  if tree[p].cover=1 then count:= tree[p].t - tree[p].s + 1
     else if tree[p].s=tree[p].t then count:=0
     else count:=count(p*2)+count(p*2+1);
end;

begin
   fillchar(tree,sizeof(tree),0);
   readln(l,m);
   tot:=0;
   maketree(1,0,l);
   for i:=1 to m do
    begin
     readln(x,y);
     insert(1,x,y);
    end;
   writeln(l-count(1)+1);
end.             
